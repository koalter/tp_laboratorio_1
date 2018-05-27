#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    eMovie movie[100];
    int opcion;

    if(init(movie) == 0) // if(!init(movie))
    {
        printf("No se encontro el archivo pelicula.dat!\n\n");
    }
    do
    {
        printf("---TRABAJO PRACTICO 3---\n");
        printf("\n1. Agregar pelicula\n");
        printf("2. Borrar pelicula\n");
        printf("3.nombre_de_la_opcion\n");
        printf("4.nombre_de_la_opcion\n");
        printf("9.Salir\n");

        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\nAGREGAR PELICULA.\n");
                alta(movie);
                break;
            case 2:
                printf("\nBORRAR PELICULA.\n");
                baja(movie);
                break;
            case 3:

                break;
            case 4:
                break;
            default:
                opcion = 9;
                break;
        }

        system("pause");
        system("cls");
    }while(opcion != 9);

    return 0;
}

/*
while (fread(&myrecord,sizeof(struct person),1,fp) != NULL)

while (!feof(fp))
{
    fread(&myrecord,sizeof(struct person),1,fp)
}
*/
