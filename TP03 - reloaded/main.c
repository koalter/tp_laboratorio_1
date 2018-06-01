#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lib.h"
#define SIZE 10

int main()
{
    eMovie movie[SIZE] = {};
    int opcion;
    int operacionExitosa;
    Nocturno skin = {0,"Activar"};

    if(init(movie,SIZE) == 0)
    {
        printf("No se pudo encontrar el archivo pelicula.dat!\n\n");
    }
    do
    {
        printf("\n\t\t\t~~~TRABAJO PRACTICO 3~~~\n");
        printf("\n1. Agregar pelicula\n");
        printf("2. Borrar pelicula\n");
        printf("3. Modificar pelicula\n");
        printf("4. Generar pagina web\n");
        printf("5. %s modo Nocturno (BONUS HTML)\n", skin.mensaje);
        printf("\n9. Salir\n");

        //printf("\nnocturno == %d\n\n",skin.toggle);

        //mostrar(movie,SIZE);

        opcion = getInt("\nIngrese una opcion: ");

        switch(opcion)
        {
            case 1:
                printf("\nAGREGAR PELICULA.\n");
                operacionExitosa = alta(movie,SIZE);
                if(operacionExitosa)
                {
                    printf("\nEL PROCESO SE REALIZO CON EXITO!\n");
                }
                else
                {
                    printf("EL PROCESO NO PUDO SER COMPLETADO!\n\n");
                }
                /** BORRAR ESTO *//*printf("\nel archivo pelicula.dat contiene %d entradas\n",operacionExitosa);*/
                system("pause");
                break;
            case 2:
                printf("\nBORRAR PELICULA.\n");
                operacionExitosa = baja(movie,SIZE);
                if(operacionExitosa)
                {
                    printf("\nEL PROCESO SE REALIZO CON EXITO!\n");
                }
                else
                {
                    printf("EL PROCESO NO PUDO SER COMPLETADO!\n\n");
                }
                system("pause");
                break;
            case 3:
                printf("\nMODIFICAR PELICULA.\n");
                operacionExitosa = modificar(movie,SIZE);
                if(operacionExitosa)
                {
                    printf("\nEL PROCESO SE REALIZO CON EXITO!\n");
                }
                else
                {
                    printf("EL PROCESO NO PUDO SER COMPLETADO!\n\n");
                }
                system("pause");
                break;
            case 4:
                operacionExitosa = generarWeb(movie);
                if(operacionExitosa)
                {
                    printf("\nEL PROCESO SE REALIZO CON EXITO!\n");
                }
                else
                {
                    printf("EL PROCESO NO PUDO SER COMPLETADO!\n\n");
                }
                system("pause");
                break;
            case 5:
                modoNocturno(&skin);
                break;
            default:
                break;
        }

        system("cls");
    }while(opcion != 9);

    return 0;
}
