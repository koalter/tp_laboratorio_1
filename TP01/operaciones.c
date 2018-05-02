#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

/** \brief Funcion que permite hacer la operacion de suma
 *
 * \param numeroUno float Primer operando
 * \param numeroDos float Segundo operando
 * \return float Resultado final
 *
 */
float sumar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno + numeroDos;
    return printf("La suma da: %.2f\n", resultado);
}

/** \brief Funcion que permite hacer la operacion de la resta
 *
 * \param numeroUno float Minuendo
 * \param numeroDos float Sustraendo
 * \return float Resultado final
 *
 */
float restar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno - numeroDos;
    return printf("La resta da: %.2f\n", resultado);
}

/** \brief Funcion que permite hacer la operacion de la division,
 *  incluye la condicion de error al dividir por cero y la correccion de dividir al cero por un numero negativo
 * \param numeroUno float Dividendo
 * \param numeroDos float Divisor
 * \return float Resultado final
 *
 */
float dividir(float numeroUno, float numeroDos)
{
    float resultado;
    if (numeroDos == 0)
    {
        return printf("ERROR: NO SE PUEDE DIVIDIR POR CERO\n");
    }
    resultado = numeroUno / numeroDos;
    if (resultado == -0)
    {
        resultado = 0;
    }
    return printf("La division da: %.2f\n", resultado);
}

/** \brief Funcion que permite hacer la operacion de la multiplicacion,
 *  incluye la correccion al multiplicar un numero negativo por cero
 * \param numeroUno float Primer factor
 * \param numeroDos float Segundo factor
 * \return float Producto
 *
 */
float multiplicar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno * numeroDos;
    if (resultado == -0)
    {
        resultado = 0;
    }
    return printf("La multiplicacion da: %.2f\n", resultado);
}

/** \brief Funcion que permite obtener el factorial del primer operando, incluye error por numero negativo
 *   y resultado 1 del factorial del 0. Si el operando tiene decimales, opera unicamente la parte entera.
 * \param numeroUno int Numero a ser factorizado
 * \return int Factorial
 *
 */
int sacarFactorial(int numeroUno)
{
    int resultado=numeroUno;
    if (numeroUno <= 1)
    {
        return 1;
    }
    resultado = resultado * sacarFactorial(numeroUno - 1);
    return resultado;
}
