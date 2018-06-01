#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lib.h"
#define SIZE 100

int settings(int*,int*);

int main()
{
    eMovie movie[100] = {};
    int opcion;
    int operacionExitosa;
    int consejos=1;
    int nocturno=0;

    if(init(movie,100) == 0)
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
        printf("5. (BONUS) Ajustes\n");
        printf("\n9. Salir\n\n");

        //printf("\nconsejos == %d \nnocturno == %d\n\n",consejos,nocturno);

        //mostrar(movie,SIZE);

        opcion = getInt("\n\nIngrese una opcion: ");

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
                system("cls");
                settings(&consejos,&nocturno);
                break;
            default:
                break;
        }

        system("cls");
    }while(opcion != 9);

    return 0;
}

int settings(int *consejos, int *nocturno)
{
    int opcion;
    char *toggleUno="Desactivar";
    char *toggleDos="Activar";

    if(*consejos)
        toggleUno = "Desactivar";
    else
        toggleUno = "Activar";

    if(*nocturno)
        toggleDos = "Desactivar";
    else
        toggleDos = "Activar";

    do
    {
        printf("\n1. %s consejos\n", toggleUno);
        printf("2. %s modo Nocturno (HTML)\n", toggleDos);
        printf("\n3. Volver al menu principal\n");

        opcion = getInt("\n\nIngrese una opcion: ");

        switch(opcion)
        {
            case 1:
                if(*consejos)
                {
                    *consejos = 0;
                    toggleUno = "Activar";
                }
                else
                {
                    *consejos = 1;
                    toggleUno = "Desactivar";
                }
                break;
            case 2:
                if(*nocturno)
                {
                    *nocturno = 0;
                    toggleDos = "Activar";
                }
                else
                {
                    *nocturno = 1;
                    toggleDos = "Desactivar";
                }
                break;
            default:
                break;
        }

        system("cls");
    }while(opcion != 3);

    return 0;
}
