#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int id;
    char titulo[30];
    char genero[30];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];
}eMovie;

typedef struct
{
    int toggle;
    char *mensaje;
}Nocturno;

#endif // LIB_H_INCLUDED


int init(eMovie *movie, int length);

int alta(eMovie*, int length);

int baja(eMovie*, int length);

int modificar(eMovie*, int length);

int generarWeb(eMovie*);

void mostrar(eMovie *movie, int length);
int mostrarUno(eMovie *movie, int length);

int getInt(char *mensaje);
char* getString(char *mensaje, char retorno[]);

int getIndex(eMovie *movie, int length);

void modoNocturno(Nocturno*);
