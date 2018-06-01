#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "lib.h"

/** \brief CARGA LOS DATOS DE pelicula.dat AL ARRAY LOCAL
 *
 * \param movie eMovie* ESTRUCTURA DE LAS PELICULAS
 * \return int DEVUELVE 1 SI CARGO TODOS LOS DATOS, 0 SI EL ARCHIVO NO EXISTE, -1 SI HUBO UN ERROR EN LA CARGA DEL ARRAY
 *
 */
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

/** \brief AGREGA UNA PELICULA AL ARCHIVO pelicula.dat Y LO SINCRONIZA CON EL ARRAY LOCAL
 *
 * \param eMovie* ESTRUCTURA LOCAL
 * \return int NOS DEBE DEVOLVER LA CANTIDAD DE ESTRUCTURAS QUE SE COPIARON AL ARCHIVO
 *
 */
int alta(eMovie *movie, int length)
{
    FILE *fp;
    int i;
    int retorno = 0;
    int flag = 0;
/// PASO LOS DATOS A LA ESTRUCTURA LOCAL
    i = getIndex(movie, length);
    if(i < 0)
    {
        return 0;
    }

    getString("\nIngrese titulo: ",(movie+i)->titulo);
    while((movie+i)->titulo[0] == '\0')
    {
        if(flag == 1)
        {
            return 0;
        }
        getString("\nDebe ingresar un titulo para continuar: ",(movie+i)->titulo);
        flag++;
    }

    getString("Ingrese genero: ",(movie+i)->genero);

    (movie+i)->duracion = getInt("Ingrese duracion en minutos: ");
    while((movie+i)->duracion < 1)
    {
        (movie+i)->duracion = getInt("NUMERO INVALIDO: Ingrese duracion en minutos: ");
    }

    getString("Ingrese sinopsis: ",(movie+i)->descripcion);

    (movie+i)->puntaje = getInt("Ingrese puntaje (100 maximo): ");
    while((movie+i)->puntaje > 100)
    {
        (movie+i)->puntaje = getInt("NUMERO INVALIDO: Ingrese puntaje (100 maximo): ");
    }

    getString("Ingrese link de imagen: ",(movie+i)->linkImagen);
/// COPIO LOS DATOS DEL ARRAY A UN ARCHIVO pelicula.dat
    fp = fopen("pelicula.dat","wb");
    if(fp == NULL)
    {
        printf("\nEl archivo no existe.\nGenerando 'pelicula.dat'...!\n");
    }
    for(i=0;(movie+i)->duracion != 0;i++)
    {
        fwrite((movie+i),sizeof(eMovie),1,fp);
        retorno++;
    }
    fclose(fp);

    return retorno;
}

/** \brief BORRA UNA PELICULA AL ARRAY LOCAL Y SE SINCRONIZA CON EL ARCHIVO pelicula.dat
 *
 * \param eMovie* ESTRUCTURA LOCAL
 * \return int DEVUELVE 1 SI LA FUNCION SE EJECUTA CON EXITO, CASO CONTRARIO DEVUELVE 0
 *
 */
int baja(eMovie *movie, int length)
{
    FILE *fp;
    int i;
    int j;
    int acumulador = 0;
    char respuesta;

/// 1. LEO EL ARRAY LOCAL Y BUSCO EL INDICE QUE QUIERO ELIMINAR (CONFIRMAMOS)
    i = mostrarUno(movie, length);
    if (i < 0)
    {
        return 0;
    }
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
    fp = fopen("pelicula.dat","wb");
    if(fp == NULL)
    {
        return 0;
    }
    for(i=0;(movie+i)->duracion != 0;i++)
    {
        fwrite(&movie[i],sizeof(eMovie),1,fp);
    }
    fclose(fp);
    return 1;
}

/** \brief MODIFICA UNA PELICULA DEL ARRAY LOCAL Y LO SINCRONIZA AL ARCHIVO pelicula.dat
 *
 * \param eMovie* ESTRUCTURA LOCAL
 * \return int DEVUELVE 1 SI LA FUNCION SE EJECUTA CON EXITO, CASO CONTRARIO DEVUELVE 0
 *
 */
int modificar(eMovie *movie, int length)
{
    FILE *fp;
    eMovie auxiliar;
    int index;
    char respuesta;

/// 1. LEO EL ARRAY LOCAL Y BUSCO EL INDICE QUE QUIERO MODIFICAR
    index = mostrarUno(movie,length);
    if (index < 0)
    {
        return 0;
    }
/// 2. LE PASO LOS DATOS A UN ARRAY AUXILIAR (VERIFICO) Y LOS COPIO AL LOCAL
    getString("\nIngrese titulo: ",auxiliar.titulo);
    if(auxiliar.titulo[0] == '\0')
    {
        strcpy(auxiliar.titulo,(movie+index)->titulo);
    }

    getString("Ingrese genero: ",auxiliar.genero);
    if(auxiliar.genero[0] == '\0')
    {
        strcpy(auxiliar.genero,(movie+index)->genero);
    }

    auxiliar.duracion = getInt("Ingrese duracion en minutos: ");
    while(auxiliar.duracion < 1)
    {
        if(auxiliar.duracion == 0)
        {
            auxiliar.duracion = (movie+index)->duracion;
            break;
        }
        auxiliar.duracion = getInt("NUMERO INVALIDO: Ingrese duracion en minutos: ");
    }

    getString("Ingrese sinopsis: ",auxiliar.descripcion);
    if(auxiliar.descripcion[0] == '\0')
    {
        strcpy(auxiliar.descripcion,(movie+index)->descripcion);
    }

    auxiliar.puntaje = getInt("Ingrese puntaje: ");

    while(auxiliar.puntaje < 1 || auxiliar.puntaje > 100)
    {
        if(auxiliar.puntaje == 0)
        {
            auxiliar.puntaje = (movie+index)->puntaje;
            break;
        }
        auxiliar.puntaje = getInt("NUMERO INVALIDO: Ingrese puntaje del 1 al 100: ");
    }

    getString("Ingrese link de imagen: ",auxiliar.linkImagen);
    if(auxiliar.linkImagen[0] == '\0')
    {
        strcpy(auxiliar.linkImagen,(movie+index)->linkImagen);
    }

    printf("\nTITULO: %s \nGENERO: %s \nDURACION: %d minutos\nSINOPSIS: %s \nPUNTAJE: %d/100 \nIMAGEN: %s \n",
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
    fp = fopen("pelicula.dat","wb");
    if(fp == NULL)
    {
        return 0;
    }
    for(index=0;(movie+index)->duracion != 0;index++)
    {
        fwrite(&movie[index],sizeof(eMovie),1,fp);
    }
    fclose(fp);
    return 1;
}

/** \brief GENERA UN ARCHIVO HTML DONDE SE VUELCAN LOS DATOS DEL ARRAY ESTRUCTURA
 *
 * \param movie eMovie* ESTRUCTURA LOCAL
 * \return int DEVUELVE 1 SI SE EJECUTO CORRECTAMENTE, 0 SI NO SE COMPLETO EL PROCESO
 *
 */
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


/** \brief MUESTRA LOS TITULOS DE LAS PELICULAS INGRESADAS, EN ORDEN DE INGRESO
 *
 * \param movie eMovie* ESTRUCTURA LOCAL
 * \param length int LARGO DEL ARRAY ESTRUCTURA
 * \return void
 *
 */
void mostrar(eMovie *movie, int length)
{
    int i;
    for(i=0;(movie+i)->duracion != 0 && i < length;i++)
    {
        printf("%d--%s\n",i+1,(movie+i)->titulo);
    }
}

/** \brief PIDE EL # DE PELICULA INGRESADA Y LA MUESTRA POR CONSOLA
 *
 * \param movie eMovie* ESTRUCTURA LOCAL
 * \param length int LARGO DEL ARRAY ESTRUCTURA
 * \return int DEVUELVE EL INDICE DEL ARRAY ESTRUCTURA
 *
 */
int mostrarUno(eMovie *movie, int length)
{
    int i;
    int flag = 0;
    mostrar(movie,length);
    i = getInt("\nIngrese numero de pelicula: ") - 1;
    while((movie+i)->duracion == 0 || i > length || i == -1)
    {
        if(flag > 1)
        {
            return -1;
        }
        i = getInt("NUMERO INVALIDO:Ingrese numero de pelicula: ") - 1;
        flag++;
    }
    printf("\nTITULO: %s \nGENERO: %s \nPUNTAJE: %d \nDURACION: %d \nSINOPSIS: %s \nIMAGEN: %s \n",
           movie[i].titulo,movie[i].genero,movie[i].puntaje,movie[i].duracion,movie[i].descripcion,movie[i].linkImagen);

    return i;
}


/** \brief PIDE, VERIFICA Y DEVUELVE DATOS ENTEROS
 *
 * \param mensaje char* INFORMACION PARA EL USUARIO
 * \return int DEVUELVE UN VALOR NUMERICO ENTERO
 *
 */
int getInt(char *mensaje)
{
    int numero;
    char auxiliar[10];
    printf(mensaje);
    fflush(stdin);
    gets(auxiliar);
    numero = atoi(auxiliar);
    return numero;
}
/** \brief PERMITE INGRESAR UNA CADENA DE CARACTERES
 *
 * \param mensaje char* INFORMACION PARA EL USUARIO
 * \param retorno[] char VARIABLE DONDE SE GUARDARA EL STRING
 * \return char* DEVUELVE UN PUNTERO DE STRING
 *
 */
char* getString(char *mensaje, char retorno[])
{
    printf(mensaje);
    fflush(stdin);
    gets(retorno);
    return retorno;
}

/** \brief UBICA EL PRIMER INDICE LIBRE EN UN ARRAY
 *
 * \param movie eMovie* ESTRUCTURA LOCAL
 * \param length int LARGO DEL ARRAY ESTRUCTURA
 * \return int DEVUELVE EL INDICE, SI NO LOGRA UBICAR ALGUNO DEVUELVE UN NUMERO NEGATIVO
 *
 */
int getIndex(eMovie *movie, int length)
{
    int index;

    for(index=0;index < length && (movie+index)->duracion != 0;index++);

    if(index >= length)
    {
        return -1;
    }

    return index;
}
