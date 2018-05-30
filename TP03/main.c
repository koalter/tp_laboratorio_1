#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/** ESTRUCTURA GENERICA DE UN ABM:
*   ALTA: 1.PIDO DATOS(A); 2.VERIFICO PROCESO(B); 3.COPIO DATOS
*   BAJA: 1.PIDO INDICE(C); 2.VERIFICO PROCESO(B); 3.ELIMINO DATOS
*   MODI: 1.PIDO INDICE(C); 2.VERIFICO PROCESO(B); 3.PIDO DATOS(A); 4.VERIFICO PROCESO(B)
*/

/**< X agregar limitador de elementos al mostrar
*    X agregar verificadores datos al abm (IMPORTANTE LA DURACION)
     X baja: lograr que la estructura auxiliar pise a la estructura original
     aplicar reglas de estructura ESTRUCTURA GENERICA DE UN ABM
*/

int main()
{
    eMovie movie[100] = {};
    int opcion;
    int operacionExitosa;

    if(init(movie,100) == 0) // if(!init(movie))
    {
        printf("No se pudo encontrar el archivo pelicula.dat!\n\n");
    }
    do
    {
        printf("---TRABAJO PRACTICO 3---\n");
        printf("\n1. Agregar pelicula\n");
        printf("2. Borrar pelicula\n");
        printf("3. Modificar pelicula\n");
        printf("4. Generar pagina web\n");
        printf("9. Salir\n\n");

        mostrar(movie);

        printf("\n\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\nAGREGAR PELICULA.\n");
                //alta(movie);
                printf("\nel archivo pelicula.dat contiene %d entradas\n",alta(movie));
                break;
            case 2:
                printf("\nBORRAR PELICULA.\n");
                operacionExitosa = baja(movie);
                if(operacionExitosa)
                {
                    printf("\nEL PROCESO SE REALIZO CON EXITO!\n");
                }
                else
                {
                    printf("EL PROCESO NO PUDO SER COMPLETADO!\n\n");
                }
                break;
            case 3:
                printf("\nMODIFICAR PELICULA.\n");
                operacionExitosa = modificar(movie);
                if(operacionExitosa)
                {
                    printf("\nEL PROCESO SE REALIZO CON EXITO!\n");
                }
                else
                {
                    printf("EL PROCESO NO PUDO SER COMPLETADO!\n\n");
                }
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
