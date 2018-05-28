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
 * \return int DEVUELVE 1 SI CARGO TODOS LOS DATOS, 0 SI EL ARCHIVO NO EXISTE, -1 SI HUBO UN ERROR EN LA CARGA DEL ARRAY
 *
 */
int init(eMovie *movie, int length);

/** \brief AGREGA UNA PELICULA AL ARCHIVO pelicula.dat Y LO SINCRONIZA CON EL ARRAY LOCAL
 *
 * \param eMovie* ESTRUCTURA LOCAL
 * \return int NOS DEBE DEVOLVER LA CANTIDAD DE ESTRUCTURAS QUE SE COPIARON AL ARCHIVO
 *
 */
int alta(eMovie*);

/** \brief BORRA UNA PELICULA AL ARRAY LOCAL Y SE SINCRONIZA CON EL ARCHIVO pelicula.dat
 *
 * \param eMovie* ESTRUCTURA LOCAL
 * \return int DEVUELVE 1 SI LA FUNCION SE EJECUTA CON EXITO, CASO CONTRARIO DEVUELVE 0
 *
 */
int baja(eMovie*);

/** \brief MODIFICA UNA PELICULA DEL ARRAY LOCAL Y LO SINCRONIZA AL ARCHIVO pelicula.dat
 *
 * \param eMovie* ESTRUCTURA LOCAL
 * \return int DEVUELVE 1 SI LA FUNCION SE EJECUTA CON EXITO, CASO CONTRARIO DEVUELVE 0
 *
 */
int modificar(eMovie*);

void mostrar(eMovie *movie);
int mostrarUno(eMovie *movie);

int getInt(char *mensaje);
char* getString(char *mensaje, char *retorno);
