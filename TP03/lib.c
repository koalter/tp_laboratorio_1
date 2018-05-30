#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "lib.h"

int init(eMovie *movie, int length)
{
    FILE *fp;
    int i = 0;

    if (movie != NULL && length > 0)
    {
        fp = fopen("pelicula.dat","rb");
        if(fp == NULL)
        {
            return 0;
        }
        else
        {
            while(!feof(fp))
            {
                fread(&movie[i],sizeof(eMovie),1,fp);
                i++;
            }
            fclose(fp);
            return 1;
        }
    }//if (movie != NULL && length > 0)
    return -1;
}

int alta(eMovie *movie)
{
    FILE *fp;
    int i = 0;
    int retorno = 0;
    int flag;
/// PASO LOS DATOS A LA ESTRUCTURA LOCAL
    for(i=0;(movie+i)->duracion != 0;i++);
    getString("\nIngrese titulo: ",(movie+i)->titulo);
    getString("Ingrese genero: ",(movie+i)->genero);
    (movie+i)->duracion = getInt("Ingrese duracion en minutos: ");
    for(flag = 0;(movie+i)->duracion < 1 && flag < 2;flag++)
    {
        (movie+i)->duracion = getInt("NUMERO INVALIDO: Ingrese duracion en minutos: ");
    }
    if(flag > 2)
    {
        (movie+i)->duracion = 1;
    }
    getString("Ingrese sinopsis: ",(movie+i)->descripcion);
    (movie+i)->puntaje = getInt("Ingrese puntaje del 1 al 100: ");
    for(flag = 0;(movie+i)->puntaje < 1 || (movie+i)->puntaje > 100 && flag < 2;flag++)
    {
        (movie+i)->puntaje = getInt("NUMERO INVALIDO: Ingrese puntaje del 1 al 100: ");
    }
    if(flag > 2)
    {
        (movie+i)->puntaje = 1;
    }
    getString("Ingrese link de imagen: ",(movie+i)->linkImagen);
/// COPIO LOS DATOS DEL ARRAY A UN ARCHIVO pelicula.dat
    fp = fopen("pelicula.dat","wb");
    if(fp == NULL)
    {
        printf("\nEl archivo no existe.\nCreando archivo...");
    }
    for(i=0;(movie+i)->duracion != 0;i++)
    {
        fwrite((movie+i),sizeof(eMovie),1,fp);
        retorno++;
    }
    fclose(fp);
    return retorno;
}

int baja(eMovie *movie)
{
    FILE *fp;
    //eMovie auxiliar[100];
    int i;
    int j;
    int acumulador = 0;
    char respuesta;
    fp = fopen("pelicula.dat","wb");
    if(fp == NULL)
    {
        return 0;
    }
/// 1. LEO EL ARRAY LOCAL Y BUSCO EL INDICE QUE QUIERO ELIMINAR (CONFIRMAMOS)
    i = mostrarUno(movie);
    printf("\nESTE PROCESO NO PUEDE SER REVERTIDO! PRESIONE 'S' PARA CONFIRMAR LA SOLICITUD...");
    fflush(stdin);
    respuesta = getch();
    if(respuesta == 's' || respuesta == 'S')
    {
        (movie+i)->duracion = -1;
    }
    else
    {
        return 0;
    }
/// 2. COPIO EL ARRAY LOCAL A UN ARRAY AUXILIAR OMITIENDO EL ELIMINADO
    for(i=0;(movie+i)->duracion != 0;i++)
    {
        for(j=i+acumulador;(movie+j)->duracion == -1;j++)
        {
            acumulador++;
        }
        if(i!=j)
        {
            movie[i] = movie[j];
        }

    }
/// 3. SOBREESCRIBO EL ARCHIVO pelicula.dat CON EL ARRAY AUXILIAR
    for(i=0;(movie+i)->duracion != 0;i++)
    {
        fwrite(&movie[i],sizeof(eMovie),1,fp);
    }
    fclose(fp);
    return 1;
}

int modificar(eMovie *movie)
{
    FILE *fp;
    eMovie auxiliar;
    int index;
    int flag;
    char respuesta;
    fp = fopen("pelicula.dat","wb");
    if(fp == NULL)
    {
        return 0;
    }
/// 1. LEO EL ARRAY LOCAL Y BUSCO EL INDICE QUE QUIERO MODIFICAR
    index = mostrarUno(movie);
/// 2. LE PASO LOS DATOS A UN ARRAY AUXILIAR (VERIFICO) Y LOS COPIO AL LOCAL
    getString("Ingrese titulo: ",auxiliar.titulo);
    getString("Ingrese genero: ",auxiliar.genero);
    auxiliar.duracion = getInt("Ingrese duracion en minutos: ");
    for(flag = 0;auxiliar.duracion < 1 && flag < 2;flag++)
    {
        auxiliar.duracion = getInt("NUMERO INVALIDO: Ingrese duracion en minutos: ");
    }
    if(flag > 2)
    {
        auxiliar.duracion = 1;
    }
    getString("Ingrese sinopsis: ",auxiliar.descripcion);
    auxiliar.puntaje = getInt("Ingrese puntaje: ");
    for(flag = 0;auxiliar.puntaje < 1 || auxiliar.puntaje > 100 && flag < 2;flag++)
    {
        auxiliar.puntaje = getInt("NUMERO INVALIDO: Ingrese puntaje del 1 al 100: ");
    }
    if(flag > 2)
    {
        auxiliar.puntaje = 1;
    }
    getString("Ingrese link de imagen: ",auxiliar.linkImagen);

    printf("\nTITULO: %s \nGENERO: %s \nDURACION: %d \nSINOPSIS: %s \nPUNTAJE: %d \nIMAGEN: %s \n",
           auxiliar.titulo,auxiliar.genero,auxiliar.duracion,auxiliar.descripcion,auxiliar.puntaje,auxiliar.linkImagen);
    printf("\nSI ESTOS DATOS SON CORRECTOS PRESIONE 'S'...");
    fflush(stdin);
    respuesta = getch();
    if(respuesta == 's' || respuesta == 'S')
    {
        *(movie+index) = auxiliar;
    }
    else
    {
        return 0;
    }
/// 3. SOBREESCRIBO EL ARCHIVO pelicula.dat CON EL ARRAY LOCAL MODIFICADO
    for(index=0;(movie+index)->duracion != 0;index++)
    {
        fwrite(&movie[index],sizeof(eMovie),1,fp);
    }
    fclose(fp);
    return 1;
}

int generarWeb(eMovie *movie)
{
    FILE *html;
    int i;

    if(movie->duracion <= 0)
    {
        return 0;
    }
    html = fopen("listado\\index.html","w");

    fprintf(html,"<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n\t<meta charset='utf-8'>\n\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n\t<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n\t<title>Lista peliculas</title>\n\t<!-- Bootstrap Core CSS -->\n\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n\t<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n\t<link href='css/custom.css' rel='stylesheet'>\n\t<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n\t<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n\t<!--[if lt IE 9]>\n\t\t<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n\t\t<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n\t<![endif]-->\n</head>\n<body>\n\t<div class='container'>\n\t\t<div class='row'>");
    for(i=0;(movie+i)->duracion != 0;i++)
    {
        fprintf(html,"\n\t\t<article class='col-md-4 article-intro'>\n\t\t\t<a href='#'>\n\t\t\t\t<img class='img-responsive img-rounded' src='%s' alt=''>\n\t\t\t</a>\n\t\t\t<h3>\n\t\t\t\t<a href='#'>%s</a>\n\t\t\t</h3>\n\t\t\t<ul>\n\t\t\t\t<li>G&#233;nero:%s</li>\n\t\t\t\t<li>Puntaje:%d</li>\n\t\t\t\t<li>Duraci&#243;n:%d minutos</li>\n\t\t\t</ul>\n\t\t\t<p>%s</p>\n\t\t</article>",(movie+i)->linkImagen,(movie+i)->titulo,(movie+i)->genero,(movie+i)->puntaje,(movie+i)->duracion,(movie+i)->descripcion);
    }
    fprintf(html,"\n\t\t</div>\n\t\t<!-- /.row -->\n\t</div>\n\t<!-- /.container -->\n\t<!-- jQuery -->\n\t<script src='js/jquery-1.11.3.min.js'></script>\n\t<!-- Bootstrap Core JavaScript -->\n\t<script src='js/bootstrap.min.js'></script>\n\t<!-- IE10 viewport bug workaround -->\n\t<script src='js/ie10-viewport-bug-workaround.js'></script>\n\t<!-- Placeholder Images -->\n\t<script src='js/holder.min.js'></script>\n</body>\n</html>");
    fclose(html);

    return 1;
}

/**< FUNCIONES DE DESARROLLO UNICAMENTE */
void mostrar(eMovie *movie)
{
    int i;
    for(i=0;/*i<3*/(movie+i)->duracion != 0;i++)
    {
        printf("%d--%s\n",i+1,(movie+i)->titulo);
        //printf("%d--%d\n",(movie+i)->id,i);
    }
}

int mostrarUno(eMovie *movie)
{
    int i;
    /*for(i=0;(movie+i)->duracion != 0;i++)
    {
        printf("%d--%s\n",(movie+i)->id,(movie+i)->titulo);
    }*/
    mostrar(movie);
    i = getInt("Ingrese numero de pelicula: ") - 1;
    /*while((movie+i)->duracion == 0)
    {
        i = getInt("NUMERO INVALIDO:Ingrese numero de pelicula: ") - 1;
    }*/
    printf("\nTITULO: %s \nGENERO: %s \nPUNTAJE: %d \nDURACION: %d \nSINOPSIS: %s \nIMAGEN: %s \n",
           movie[i].titulo,movie[i].genero,movie[i].puntaje,movie[i].duracion,movie[i].descripcion,movie[i].linkImagen);

    return i;
}

/**< END_FUNCIONES DE DESARROLLO */

int getInt(char *mensaje)
{
    int numero;
    printf(mensaje);
    scanf("%d",&numero);
    return numero;
}
char* getString(char *mensaje, char *retorno)
{
    printf(mensaje);
    fflush(stdin);
    gets(retorno);
    return retorno;
}
