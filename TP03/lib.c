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
/// PASO LOS DATOS A LA ESTRUCTURA LOCAL
    for(i=0;(movie+i)->id != 0;i++);
    (movie+i)->id = i+1;
    getString("\nIngrese titulo: ",(movie+i)->titulo);
    getString("Ingrese genero: ",(movie+i)->genero);
    (movie+i)->duracion = getInt("Ingrese duracion en minutos: ");
    getString("Ingrese sinopsis: ",(movie+i)->descripcion);
    (movie+i)->puntaje = getInt("Ingrese puntaje: ");
    getString("Ingrese link de imagen: ",(movie+i)->linkImagen);
/// COPIO LOS DATOS DEL ARRAY A UN ARCHIVO pelicula.dat
    fp = fopen("pelicula.dat","wb");
    if(fp == NULL)
    {
        printf("\nEl archivo no existe.\nCreando archivo...");
    }
    for(i=0;(movie+i)->id != 0;i++)
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
    eMovie auxiliar[100];
    int i;
    int j = 0;
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
        (movie+i)->id = -1;
    }
    else
    {
        return 0;
    }
/// 2. COPIO EL ARRAY LOCAL A UN ARRAY AUXILIAR OMITIENDO EL ELIMINADO
    for(i=0;(movie+i)->id != 0;i++)
    {
        if((movie+i)->id == -1)
        {
            continue;
        }
        auxiliar[j] = movie[i];
        auxiliar[j].id = j+1;
        j++;
    }
    movie = auxiliar;
/// 3. SOBREESCRIBO EL ARCHIVO pelicula.dat CON EL ARRAY AUXILIAR
    for(i=0;(auxiliar+i)->id != 0;i++)
    {
        fwrite(&auxiliar[i],sizeof(eMovie),1,fp);
    }
    fclose(fp);
    return 1;
}

int modificar(eMovie *movie)
{
    FILE *fp;
    eMovie auxiliar;
    int index;
    char respuesta;
    fp = fopen("pelicula.dat","wb");
    if(fp == NULL)
    {
        return 0;
    }
/// 1. LEO EL ARRAY LOCAL Y BUSCO EL INDICE QUE QUIERO MODIFICAR
    index = mostrarUno(movie);
/// 2. LE PASO LOS DATOS A UN ARRAY AUXILIAR (VERIFICO) Y LOS COPIO AL LOCAL
    auxiliar.id = index+1;
    getString("Ingrese titulo: ",auxiliar.titulo);
    getString("Ingrese genero: ",auxiliar.genero);
    auxiliar.duracion = getInt("Ingrese duracion en minutos: ");
    getString("Ingrese sinopsis: ",auxiliar.descripcion);
    auxiliar.puntaje = getInt("Ingrese puntaje: ");
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
    for(index=0;(movie+index)->id != 0;index++)
    {
        fwrite(&movie[index],sizeof(eMovie),1,fp);
    }
    fclose(fp);
    return 1;
}


/**< FUNCIONES DE DESARROLLO UNICAMENTE */
void mostrar(eMovie *movie)
{
    int i;
    for(i=0;(movie+i)->id == 0;i++)
    {
        //printf("%d--%s\n",(movie+i)->id,(movie+i)->titulo);
        printf("%d--%d\n",(movie+i)->id,i);
    }
}

int mostrarUno(eMovie *movie)
{
    int i;
    for(i=0;(movie+i)->id != 0;i++)
    {
        printf("%d--%s\n",(movie+i)->id,(movie+i)->titulo);
    }
    i = getInt("Ingrese numero de pelicula: ") - 1;
    /*while((movie+i)->id == 0)
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
