#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    int dni;
    int estado;
}ePersona;

#endif // LIB_H_INCLUDED

/** \brief INICIALIZA UNA ESTRUCTURA
 *
 * \param ePersona[] NOMBRE DE LA ESTRUCTURA
 * \param limite int LONGITUD DEL PUNTERO DE LA ESTRUCTURA
 * \return int SI TODO FUNCIONA BIEN, DEVUELVE 0
 *
 */
int ePers_init(ePersona[],int limite);

/** \brief ASIGNA VALORES PREDEFINIDOS A LA ESTRUCTURA Y
 *         LOS DEJA ENLISTADOS
 * \param ePersona[] NOMBRE DE LA ESTRUCTURA
 * \param limite int LONGITUD
 * \return void AL FINAL SE IMPRIME UN MENSAJE DE QUE LOS DATOS FUERON CARGADOS
 *
 */
void ePers_estructuraEjemplo(ePersona[]);

/** \brief BUSCA UN LUGAR LIBRE EN EL ARRAY
 *
 * \param listado[] ePersona NOMBRE DE LA ESTRUCTURA
 * \param limite int LONGITUD
 * \return int DEVUELVE 0 SI SE EJECUTA CORRECTAMENTE
 *
 */
int ePers_buscarLugarLibre(ePersona listado[],int limite);

/** \brief BUSCA EL ULTIMO ID OCUPADO Y DEVUELVE EL SIGUIENTE
 *
 * \param ePersona[] NOMBRE DE LA ESTRUCTURA
 * \param limite int LONGITUD
 * \return int DEVUELVE EL SIGUIENTE ID AL ENCONTRADO
 *
 */
int ePers_siguienteId(ePersona[] ,int limite);

/** \brief MUESTRA LOS DATOS DE UN ELEMENTO DEL ARRAY
 *
 * \param parametro ePersona ES EL PARAMETRO DE LA ESTRUCTURA
 * \return void
 *
 */
void ePers_mostrarUno(ePersona parametro);

/** \brief LEE TODO EL ARRAY Y EJECUTA MOSTRARUNO PARA
 *         ENLISTAR TODOS LOS ELEMENTOS OCUPADOS
 * \param ePersona[] NOMBRE DE LA ESTRUCTURA
 * \param limite int LONGITUD
 * \return int DEVUELVE 0 SI TODO SE EJECUTO CORRECTAMENTE
 *
 */
int ePers_mostrarListado(ePersona[] ,int limite);

/** \brief ORDENA EL ARRAY POR METODO DE BURBUJEO
 *
 * \param ePersona[] NOMBRE DE LA ESTRUCTURA
 * \param longitud int LONGITUD
 * \return void
 *
 */
void ePers_ordenar(ePersona[] ,int longitud);

/** \brief DA DE ALTA UN ELEMENTO DE LA LISTA
 *
 * \param ePersona[] NOMBRE DE LA ESTRUCTURA
 * \param limite int LONGITUD
 * \return int
 *
 */
int ePers_alta(ePersona[] ,int limite);

/** \brief DA DE BAJA UN ELEMENTO DE LA LISTA
 *
 * \param persona[] ePersona NOMBRE DE LA ESTRUCTURA
 * \param limite int LONGITUD
 * \return void
 *
 */
void ePers_baja(ePersona persona[] ,int limite);

/** \brief FUNCION BASICA PARA PEDIR UN NOMBRE
 *
 * \param mensaje[] char
 * \param cadena[] char
 * \return char*
 *
 */
char* pedirNombre(char mensaje[], char cadena[]);

/** \brief FUNCION BASICA PARA PEDIR UN NUMERO ENTERO
 *
 * \param mensaje[] char
 * \return int
 *
 */
int pedirEntero(char mensaje[]);

/** \brief IMPRIME UN GRAFICO DE BARRAS QUE MUESTRA
 *         CUANTOS ELEMENTOS CORRESPONDEN CON X CRITERIO
 * \param listado[] ePersona NOMBRE DE LA ESTRUCTURA
 * \param longitud int LONGITUD
 * \return int
 *
 */
int ePers_graficoVertical(ePersona listado[],int longitud);

/** \brief SUBFUNCION DE GRAFICOVERTICAL
 *         MANTIENE UNA CUENTA DE CADA CONDICION
 * \param listado[] ePersona NOMBRE DE LA ESTRUCTURA
 * \param limite int LONGITUD
 * \return int* DEVUELVE UN ARRAY CON TODOS LOS CONTADORES
 *
 */
int* contador(ePersona listado[], int limite);

/** \brief SUBFUNCION DE GRAFICOVERTICAL
 *         TOMA COMO PARAMETRO EL CONTADOR Y DEVUELVE EL MAXIMO VALOR OBTENIDO
 * \param aux[] int AQUI SE INGRESA LA UBICACION DEL CONTADOR
 * \return int DEVUELVE EL MAXIMO VALOR OBTENIDO POR LOS CONTADORES
 *
 */
int valorMaximo(int aux[]);
