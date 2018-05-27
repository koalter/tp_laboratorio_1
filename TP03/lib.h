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

/** \brief BORRA UNA PELICULA AL ARRAY LOCAL Y SE SINCRONIZA CON EL ARCHIVO pelicula.dat
 *
 * \param eMovie* ESTRUCTURA LOCAL
 * \return int DEVUELVE 1 SI LOGRO OPERAR COMPLETAMENTE, 0 SI NO PUDO ABRIRSE pelicula.dat
 *
 */
int baja(eMovie*);

/** \brief MODIFICA UNA PELICULA DEL ARRAY LOCAL Y LO SINCRONIZA AL ARCHIVO pelicula.dat
 *
 * \param eMovie* ESTRUCTURA LOCAL
 * \return int DEVUELVE 1 SI LOGRO OPERAR COMPLETAMENTE, 0 SI NO PUDO ABRIRSE pelicula.dat
 *
 */
int modificar(eMovie*);

void mostrar(eMovie *movie);
void mostrarUno(eMovie *movie);

int getInt(char *mensaje);
char* getString(char *mensaje, char *retorno);
