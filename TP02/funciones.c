#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LIBRE 1
#define OCUPADO 0
#define TAGS 3

void ePers_estructuraEjemplo(ePersona persona[],int limite)
{
    int i;
    /*ePersona persona[] = {
        {1,"Lorenzo",23,38304953,0},
        {2,"Eliana",21,40011160,0},
        {3,"Miguel",17,45040283,0},
        {4,"Carmen",41,27391484,0},
        {5,"Raul",50,22147821,0}
        };*/
    void load(char nombre[],int edad,int dni)
    {
        strcpy(persona[i].nombre,nombre);
        persona[i].edad = edad;
        persona[i].dni = dni;
    }

    for(i=0;i<limite;i++)
    {

        switch(i)
        {
            case 0:
                load("Lorenzo",23,38304953);
                break;
            case 1:
                load("Eliana",21,40011160);
                break;
            case 2:
                load("Miguel",17,45040283);
                break;
            case 3:
                load("Carmen",41,27391484);
                break;
            case 4:
                load("Raul",50,22147821);
                /*strcpy(persona[i].nombre,"Lorenzo");
                persona[i].edad = 23;
                persona[i].dni = 38304953;*/
                break;
            case 5:
                load("Enrique",28,44738292);
                break;
            case 6:
                load("Silvia",25,23901921);
                break;
        }

        persona[i].id = i+1;
        persona[i].estado = OCUPADO;
    }
    printf("DATOS CARGADOS\n");
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

int ePers_mostrarListadoConBorrados(ePersona listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            ePers_mostrarUno(listado[i]);
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

int ePers_acumulador(ePersona listado[], int longitud)
{
    int valor[3] = {0};
    int valorMaximo;
    int indice=0;
    for(int i=0; i<longitud; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            /// acumulador
            if (listado[i].edad > 35)
            {
                valor[2]++;
                valorMaximo=valor[2];
                indice=3;
            }
            else
            {
                if (listado[i].edad < 18)
                {
                valor[0]++;
                if(valor[0]>valor[2])
                    valorMaximo=valor[0];
                    indice=1;
                }
                else
                {
                    valor[1]++;
                    if (valor[1]>valor[0] && valor[1]>valor[2])
                    {
                        valorMaximo=valor[1];
                        indice=2;
                    }

                }

            }
            /// end acumulador
             //if (listado[i].edad > 35)
        } //if(listado[i].estado==OCUPADO)
    }
    printf("Los menores de 19 son: %d\n", valor[0]);
    printf("Los que tienen entre 19 y 35 son: %d\n", valor[1]);
    printf("Los mayores de 35 son: %d\n", valor[2]);
    printf("El maximo valor es %d y corresponde al indice %d\n",valorMaximo,indice);
    return 0;
}

int ePers_graficoVertical(ePersona listado[],int longitud)
{
    char tagNombre[TAGS][10] = {"<19","19-35",">35"};
    int valor[TAGS] = {0};
    int valorMaximo;
    int i;
    int j;

    for(int i=0; i<longitud; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            /// acumulador
            if (listado[i].edad > 35)
            {
                valor[2]++;
                valorMaximo=valor[2];
            }
            else
            {
                if (listado[i].edad < 19)
                {
                valor[0]++;
                if(valor[0]>valor[2])
                    valorMaximo=valor[0];
                }
                else
                {
                    valor[1]++;
                    if (valor[1]>valor[0] && valor[1]>valor[2])
                    {
                        valorMaximo=valor[1];
                    }

                }

            }
            /// end acumulador
             //if (listado[i].edad > 35)
        } //if(listado[i].estado==OCUPADO)
    }


    for(i=valorMaximo; i>0; i--)
    {
        for(j=0;j<TAGS;j++)
        {
            if(valor[j]>=i)
                printf("\t*");
            else
                printf("\t");
        }
        putchar('\n');
    }

    printf("\t%s\t%s\t%s\n",tagNombre[0],tagNombre[1],tagNombre[2]);

    return 0;
}

int ePers_graficoHorizontal(ePersona listado[], int longitud)
{
    char tagNombre[3][10] = {"<19","19-35",">35"};
    int valor[3] = {0};
    int i;
    int j;

    /// acumulador
    for(i=0; i<longitud; i++)
    {
        if(listado[i].estado==OCUPADO)
        {

            if (listado[i].edad > 35)
                valor[2]++;
            else if (listado[i].edad < 19)
                valor[0]++;
            else
                valor[1]++;


        } //if(listado[i].estado==OCUPADO)
    } //for(int i=0; i<longitud; i++)
    printf("\nLos menores de 19 son: %d\n", valor[0]);
    printf("Los que tienen entre 19 y 35 son: %d\n", valor[1]);
    printf("Los mayores de 35 son: %d\n", valor[2]);
    /// end acumulador

    /// graficador
    for(j=0;j<3;j++)
    {
        printf("%s \t", tagNombre[j]);
        for(i=0; i<valor[j]; i++)
        {

            putchar('*');

        } //for(int i=0; i<longitud; i++)
        putchar('\n');
    } //for(int j=0;j<3;j++)
    /// end graficador


    return 0;
}
