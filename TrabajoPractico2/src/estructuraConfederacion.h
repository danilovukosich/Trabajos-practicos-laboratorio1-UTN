/*
 * estructuraConfederacion.h
 *
 *  Created on: 26 oct. 2022
 *      Author: danil
 */

#ifndef ESTRUCTURACONFEDERACION_H_
#define ESTRUCTURACONFEDERACION_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static unsigned int idAutoIncrementalConfe = 1000;

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;

}eConfederacion;

/// @brief Funcion que hardcodea una listad de confederaciones.
///
/// @param lista Confederaciones lista de confederaciones a hardcodear.
/// @param size tamanio de la lista de confederaciones a hardcodear.
/// @return retorna 0 si hubo un error y 1 si no hubo error.
int HardcodearConfederaciones(eConfederacion listaConfederaciones[], int size);

/// @brief Funcion que muestra las confederaciones.
///
/// @param listaConfederaciones lista de confederaciones a nostrar.
/// @param sizeConfederaciones tamanio de confederaciones.
void MostrarConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcio que carga el nombre de una confederacion mediante un id que ingresa como parametro.
///
/// @param listaCOnfederaciones lista de confederaciondes donde se busca el id.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
/// @param idConfederacion id con el que se compara para la busqueda.
/// @param nombreConfederacion puntero donde se guarda el valor del nombre de la confederacion.
/// @return
int CargarNombreConfederacion(eConfederacion listaCOnfederaciones[], int sizeConfederaciones, int idConfederacion, char nombreConfederacion[]);


//ALTA, BAJA Y MODIFICACION DE CONFEDERACION
/// @brief Funcion que genera un id de confederacion autoincremental
///
/// @return Retorna el id incramentado.
static int IdAutoIncrementalConfederacion(void);


/// @brief Funicon que inicializa la lista de confederacionnes en 1.
///
/// @param listaConfederaciones lsita de confederaciones a unicializar
/// @param size tamanio de la lista de confederaciones.
/// @return retorna 0 si hubo un erro y 1 si no hubo error.
int InicializarConfederaciones(eConfederacion listaConfederaciones[],int size);

/// @brief Funcion que busca un espacio libre en la lista d econfederaciones.
///
/// @param listaConfederaciones lista de confederaciones en la que se busca un espacio libre.
/// @param size tamanio de la lista de confederaciones
/// @return retorna -1 si hubo un erro y 1 si no hubo error.
int BuscarLibreConfederacion(eConfederacion listaConfederaciones[],int size);

/// @brief Funcion que carga una confederacion.
///
/// @param Confederacion puntero en el que se guardala confederacion
/// @return retorna -1 si hubo un erro y 1 si no hubo error.
int CargarConfederacion(eConfederacion Confederacion[]);

/// @brief Funcion que carga una lista de confederaciones.
///
/// @param listaConfederaciones lista de confedraciones en la que se cargara una confedracion.
/// @param sizeConfederaciones tamanio de confederaciones.
/// @return retorna -1 si hubo un erro y 1 si no hubo error.
int CargarListaConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que muestra una confederacion.
///
/// @param listaConfederaciones lista de confederaciones.
void MostrarConfederacion(eConfederacion listaConfederaciones);

/// @brief Funcion que muestra una lista de confederaciones.
///
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de lista de confederaciones.
void MostrarLitaConfederaciones(eConfederacion listaConfederaciones[],int sizeConfederaciones);

/// @brief Funcion que buca un id en la lista de confederaciones y devuelve un indice
///
/// @param listaConfederaciones lista de confederaciones en la que se busca el id.
/// @param sizeConfederaciones tamani de la lista de confederaciones
/// @param id id que se compara para realizar la busqueda.
/// @return retorna un indice y retorna -1 su hubo un error.
int VerificarIdConfederacion(eConfederacion listaConfederaciones[],int sizeConfederaciones, int id);

/// @brief Funcion que da de baja una confederacion.
///
/// @param listaConfederaciones lista de confederaciones de la cual se da la baja.
/// @param sizeConfederaciones tamanio de confederaciones.
/// @return retorna -1 si hubo un erro y 1 si no hubo error.
int BajaConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que modifica cualquier campo de una confedracion.
///
/// @param listaConfederaciones listad e confedraciones a modificar.
/// @param sizeConfederaciones tamanio de confederaciones.
/// @return retorna -1 si hubo un erro y 1 si no hubo error.
int ModificacionConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones);

#endif /* ESTRUCTURACONFEDERACION_H_ */
