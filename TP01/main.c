#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "operaciones.h"

int main()
{
    float numeroUno=0;
    float numeroDos=0;
    int opcion;

    do
    {
        printf("---CALCULADORA---\n\n");
        printf("1. Ingresar 1er operando (A=%.2f)\n", numeroUno);
        printf("2. Ingresar 2do operando (B=%.2f)\n", numeroDos);
        printf("3. Calcular la suma (A+B)\n");
        printf("4. Calcular la resta (A-B)\n");
        printf("5. Calcular la division (A/B)\n");
        printf("6. Calcular la multiplicacion (A*B)\n");
        printf("7. Calcular el factorial (A!)\n");
        printf("8. Calcular todas las operaciones\n");
        printf("9. Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\nIngrese el 1er operando: ");
                scanf("%f", &numeroUno);
                break;
            case 2:
                printf("\nIngrese el 2do operando: ");
                scanf("%f", &numeroDos);
                break;
            case 3:
                sumar(numeroUno, numeroDos);
                break;
            case 4:
                restar(numeroUno, numeroDos);
                break;
            case 5:
                dividir(numeroUno, numeroDos);
                break;
            case 6:
                multiplicar(numeroUno, numeroDos);
                break;
            case 7:
                if (numeroUno < 0)
                {
                    printf("ERROR: NO SE PUEDE SACAR EL FACTORIAL DE UN NUMERO NEGATIVO\n");
                    break;
                }
                printf("El factorial de %d es: %d\n", (int)numeroUno, sacarFactorial(numeroUno));
                break;
            case 8:
                sumar(numeroUno, numeroDos);
                restar(numeroUno, numeroDos);
                dividir(numeroUno, numeroDos);
                multiplicar(numeroUno, numeroDos);
                if (numeroUno < 0)
                {
                    printf("ERROR: NO SE PUEDE SACAR EL FACTORIAL DE UN NUMERO NEGATIVO\n");
                    break;
                }
                printf("El factorial de %d es: %d\n", (int)numeroUno, sacarFactorial(numeroUno));
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
