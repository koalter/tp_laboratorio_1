#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define LIBRE 1
#define OCUPADO 0
#define TAGS 3

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

void ePers_estructuraEjemplo(ePersona persona[])
{
    void load(char nombre[],int edad,int dni, int id)
    {
        strcpy(persona[id-1].nombre,nombre);
        persona[id-1].edad = edad;
        persona[id-1].dni = dni;
        persona[id-1].id = id;
        persona[id-1].estado = OCUPADO;
    }

    load("Lorenzo",23,38304953,1);
    load("Eliana",22,40653181,2);
    load("Miguel",17,45040283,3);
    load("Carmen",41,27391484,4);
    load("Raul",50,22147821,5);
    load("Enrique",28,32738292,6);
    load("Silvia",25,35901921,7);
     /*
    load("Juan",25,0,8);
    load("Juan",25,0,9);
    load("Juan",25,0,10);
    load("Juan",25,0,11);
    load("Cintia",16,0,12);
    load("Cintia",16,0,13);
    load("Cintia",16,0,14);
    load("Maria",40,0,15);
    load("Maria",40,0,16);
    load("Maria",40,0,17);
    load("Maria",40,0,18);
    load("Cintia",16,0,19);
    load("Cintia",16,0,20);
    */

    printf("\nDATOS CARGADOS\n");
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

void ePers_mostrarUno(ePersona parametro)
{
    printf("%10s %5d %10d \n",parametro.nombre,parametro.edad,parametro.dni);

}

int ePers_mostrarListado(ePersona listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        printf("\n    NOMBRE  EDAD\tDNI\n");
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

void ePers_ordenar(ePersona persona[] ,int longitud)
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

            retorno = 0;
            printf("\nALTA DE CONTACTO\n");
            listado[indice].id = id;
            strcpy(listado[indice].nombre,pedirNombre("Ingrese nombre: ", nombre) );

            listado[indice].edad = pedirEntero("Ingrese la edad: ");
            listado[indice].dni = pedirEntero("Ingrese numero de DNI: ");
            listado[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

void ePers_baja(ePersona persona[] ,int limite)
{
    int i;
    char respuesta;
    printf("\nBAJA DE CONTACTO\n");
    printf("Seleccione la posicion a dar de baja: ");
    scanf("%d", &i);
    while(i==0 || i>limite || persona[i-1].estado == LIBRE)
    {
        printf("ID incorrecto, ingrese otra posicion: ");
        scanf("%d", &i);
    }
    printf("\n    NOMBRE  EDAD\tDNI");
    printf("\n%10s %5d %10d\n", persona[i-1].nombre, persona[i-1].edad, persona[i-1].dni);
    printf("\nCUIDADO: ESTE PROCESO NO SE PUEDE REVERTIR\nINGRESE 'S' PARA CONFIRMAR LA BAJA: ");
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

int ePers_graficoVertical(ePersona listado[],int longitud)
{
    char tagNombre[TAGS][10] = {"<19","19-35",">35"};
    int* valor;
    int maximo;
    int i;
    int j;

    valor = contador(listado,longitud);
    maximo = valorMaximo(valor);

    for(i=maximo; i>0; i--)
    {
        for(j=0;j<TAGS;j++)
        {
            if(valor[j]>=i)
                printf("\t*");
            else
                printf("\t");
        }
        printf("\n");
    }

    printf("\t%s\t%s\t%s\n",tagNombre[0],tagNombre[1],tagNombre[2]);

    return 0;
}

int* contador(ePersona listado[], int limite)
{
    int i;
    static int auxiliar[TAGS];
    memset(auxiliar,0,sizeof auxiliar);

    for(i=0;i<limite;i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            if (listado[i].edad<19)
            {
                auxiliar[0]++;
            }
            else
            {
                if (listado[i].edad>35)
                {
                    auxiliar[2]++;
                }
                else
                {
                    auxiliar[1]++;
                }
            }
        }
    }
    return auxiliar;
}

int valorMaximo(int *aux)
{
    int i;
    int maximo;
    int flag = 0;
    for (i=0;i<sizeof(aux);i++)
    {
        if(flag==0 || aux[i]>maximo)
        {
            maximo = aux[i];
            flag = 1;
        }
    }
    return maximo;
}
