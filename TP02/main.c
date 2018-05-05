#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAMANIO 20

int main()
{
    ePersona persona[TAMANIO];
    ePers_init(persona,TAMANIO);
    int opcion;

    do
    {
        printf("---AGENDA ELECTRONICA---\n");
        printf("\n1. Agregar una persona\n");
        printf("2. Borrar una persona\n");
        printf("3. Imprimir lista ordenada por nombre\n");
        printf("4. Imprimir grafico de edades\n");
        printf("9. Salir\n");

        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                ePers_estructuraEjemplo(persona,5);
                //ePers_alta(persona,TAMANIO);
                break;
            case 2:
                ePers_baja(persona,TAMANIO);
                break;
            case 3:
                //ePers_mostrarListadoConBorrados(persona,TAMANIO);
                ePers_ordenar(persona,TAMANIO);
                break;
            case 4:
                ePers_grafico(persona,TAMANIO);
                //ePers_grafico(persona,TAMANIO,"<19","19-35",">35");
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
