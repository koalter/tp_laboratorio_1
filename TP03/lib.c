#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int init(eMovie *movie)
{
    FILE *fp;
    int i = 0;

    fp = fopen("pelicula.dat","rb");
    if(fp == NULL)
    {
        return 0;
    }

    while(fread(&movie[i],sizeof(eMovie),1,fp) != NULL)
    {
        movie[i].id = i+1;
        movie[i+1].id = 0;
        i++;
    }
    fclose(fp);

    return 1;
}

int alta(eMovie *movie)
{
    FILE *fp;
    eMovie auxiliar;
    int retorno;
/// PASO LOS DATOS A UNA ESTRUCTURA AUXILIAR
    getString("Ingrese titulo: ",auxiliar.titulo);
    getString("Ingrese genero: ",auxiliar.genero);
    auxiliar.duracion = getInt("Ingrese duracion en minutos: ");
    getString("Ingrese sinopsis: ",auxiliar.descripcion);
    auxiliar.puntaje = getInt("Ingrese puntaje: ");
    getString("Ingrese link de imagen: ",auxiliar.linkImagen);
/// COPIO LOS DATOS AUXILIARES A UN ARCHIVO
    fp = fopen("pelicula.dat","wb");
    fwrite(&auxiliar,sizeof(eMovie),1,fp);
    fclose(fp);
/// SUBO LOS DATOS DEL ARCHIVO AL ARRAY ESTRUCTURA PRINCIPAL
    retorno = init(movie);
    return retorno;
    /*f = fopen("pelicula.dat","rb");
    while(fread(movie[i],sizeof(eMovie),1,fp) != NULL)
    {
        i++;
    }
    fclose(fp);*/
}

void baja(eMovie *movie)
{
    FILE *fp;
    eMovie *auxiliar;
    int i;
    int diferencia = 0;
/// 1. LEO EL ARRAY LOCAL Y BUSCO EL INDICE QUE QUIERO ELIMINAR
    for(i=0;(movie+i)->id == 0;i++)
    {
        printf("\n%d--%s",(movie+i)->id,(movie+i)->titulo);
    }
    i = getInt("Ingrese numero de pelicula: ") - 1;
    (movie+i)->id = -1;
/// 2. COPIO EL ARRAY LOCAL A UN ARRAY AUXILIAR OMITIENDO EL ELIMINADO
    for(i=0;(movie+i)->id == 0;i++)
    {
        if((movie+i)->id == -1)
        {
            diferencia++;
            continue;
        }
        auxiliar[i-diferencia] = movie[i];
        auxiliar[(i-diferencia)+1].id = 0;
    }
/// 3. SOBREESCRIBO EL ARCHIVO pelicula.dat CON EL ARRAY AUXILIAR
    fp = fopen("pelicula.dat","wb");
    for(i=0;(auxiliar+i)->id == 0;i++)
    {
        fwrite(&auxiliar[i],sizeof(eMovie),1,fp);
    }
    fclose(fp);
}

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
    fgets(retorno,140,stdin);
    return retorno;
}
