#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    int dni;
    int estado;
}ePersona;

#endif // FUNCIONES_H_INCLUDED

int ePers_cargarEjemploDeListado(ePersona persona[], int limite);

int ePers_init(ePersona[],int limite);
int ePers_buscarPorId(ePersona[] ,int limite, int id);
int ePers_siguienteId(ePersona[] ,int limite);
int ePers_buscarLugarLibre(ePersona listado[],int limite);

void ePers_mostrarUno(ePersona parametro);
int ePers_mostrarListado(ePersona[] ,int limite);
int ePers_mostrarListadoConBorrados(ePersona[] ,int limite);

int ePers_alta(ePersona[] ,int limite);
void ePers_baja(ePersona persona[] ,int limite);
int ePers_modificacion(ePersona[] ,int limite, int id);

int ePers_ordenar(ePersona[] ,int limite, int orden);
char* pedirNombre(char mensaje[], char cadena[]);
int pedirEntero(char mensaje[]);

void bubbleSort(ePersona[], int longitud);
