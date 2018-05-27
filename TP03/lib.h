#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int id;
    char titulo[30];
    char genero[30];
    int duracion;
    char descripcion[140];
    int puntaje;
    char linkImagen[100];
}eMovie;

#endif // LIB_H_INCLUDED

/** \brief CARGA LOS DATOS DE pelicula.dat AL ARRAY LOCAL
 *
 * \param movie eMovie* ESTRUCTURA DE LAS PELICULAS
 * \return int DEVUELVE 1 SI CARGO TODOS LOS DATOS, 0 SI EL ARCHIVO NO EXISTE
 *
 */
int init(eMovie *movie);

/** \brief AGREGA UNA PELICULA AL ARCHIVO pelicula.dat Y LO SINCRONIZA CON EL ARRAY LOCAL
 *
 * \param eMovie* ESTRUCTURA LOCAL
 * \return int DEVUELVE 1 SI LOGRO SINCRONIZARSE EL ARRAY LOCAL CON EL ARCHIVO
 *
 */
int alta(eMovie*);
void baja(eMovie*);
void modificacion(eMovie*);

int getInt(char *mensaje);
char* getString(char *mensaje, char *retorno);
