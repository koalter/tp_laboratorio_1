#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LIBRE 1
#define OCUPADO 0

int ePers_cargarEjemploDeListado(ePersona persona[], int limite)
{
    for(int i=0;i<limite;i++)
    {
        persona[i].id = i+1;
        strcpy(persona[i].nombre,"lorenzo");
        persona[i].edad = 25;
        persona[i].dni = 35921221+i;
        persona[i].estado = OCUPADO;
    }
    return printf("DATOS CARGADOS\n");
}

int ePers_init(ePersona listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            strcpy(listado[i].nombre,"zzz");
            listado[i].estado= LIBRE;
            listado[i].dni= 0;
        }
    }
    return retorno;
}

int ePers_buscarLugarLibre(ePersona listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePers_siguienteId(ePersona listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }

            }
        }
    }

    return retorno+1;
}

int ePers_buscarPorId(ePersona listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void ePers_mostrarUno(ePersona parametro)
{
    printf("%10s %5d %10d\n",parametro.nombre,parametro.edad,parametro.dni);

}

int ePers_mostrarListado(ePersona listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        printf("\n    NOMBRE  EDAD        DNI\n");
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                ePers_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}

int ePers_alta(ePersona listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = ePers_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = ePers_siguienteId(listado,limite);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                retorno = 0;
                listado[indice].id = id;
                strcpy(listado[indice].nombre,pedirNombre("Ingrese nombre: ", nombre) );

                listado[indice].edad = pedirEntero("Ingrese la edad: ");
                listado[indice].dni = pedirEntero("Ingrese numero de DNI: ");
                listado[indice].estado = OCUPADO;
            //}
        }
    }
    return retorno;
}

void ePers_baja(ePersona persona[] ,int limite)
{
    int i;
    char respuesta;
    printf("\nDAR DE BAJA\n");
    printf("Seleccione la posicion a dar de baja: ");
    scanf("%d", &i);
    while(i==0 || i-1>limite)
    {
        printf("ID incorrecto, ingrese otra posicion: ");
        scanf("%d", &i);
    }
    printf("\n%10s %5d %10d\n", persona[i-1].nombre, persona[i-1].edad, persona[i-1].dni);
    printf("CUIDADO: ESTE PROCESO NO SE PUEDE REVERTIR\nINGRESE 'S' PARA CONFIRMAR LA BAJA: ");
    fflush(stdin);
    scanf("%c", &respuesta);
    if(respuesta=='s')
    {
        persona[i-1].id = 0;
        strcpy(persona[i-1].nombre,"zzz");
        persona[i-1].edad = 0;
        persona[i-1].dni = 0;
        persona[i-1].estado = LIBRE;
    }
}

char* pedirNombre(char mensaje[], char cadena[])
{
    printf(mensaje);
    fflush(stdin);
    scanf("%s", cadena);
    return cadena;
}

int pedirEntero(char mensaje[])
{
    int numero;
    printf(mensaje);
    scanf("%d", &numero);
    return numero;
}

void bubbleSort(ePersona persona[], int longitud)
{
    int i;
    int j;
    char auxiliarStr[20];
    int auxInt;
    for(i=0;i<longitud-1;i++)
    {
        for(j=i+1;j<longitud;j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre) > 0)
            {
                strcpy(auxiliarStr, persona[i].nombre);
                strcpy(persona[i].nombre, persona[j].nombre);
                strcpy(persona[j].nombre, auxiliarStr);

                auxInt = persona[i].edad;
                persona[i].edad = persona[j].edad;
                persona[j].edad = auxInt;

                auxInt = persona[i].dni;
                persona[i].dni = persona[j].dni;
                persona[j].dni = auxInt;
            } //if(strcmp(persona[i].nombre, persona[j].nombre) > 0)
        } //for(j=i+1;j<longitud;j++)

    } //for(i=0;i<longitud-1;i++)

    ePers_mostrarListado(persona,longitud);
}
