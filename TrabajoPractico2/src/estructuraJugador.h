/*
 * estructuraJugador.h
 *
 *  Created on: 17 oct. 2022
 *      Author: danil
 */

#ifndef ESTRUCTURAJUGADOR_H_
#define ESTRUCTURAJUGADOR_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "estructuraConfederacion.h"
#include "menus.h"

//id autoincremental
static unsigned int idAutoIncremental = 1;


typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short int numeroCamiseta;
	int idConfederacion;
	float salario;
	short int aniosContrato;
	short int isEmpty;

}eJugador;


/// @brief Funcion que genera un id de jugador autoincremental
///
/// @return Retorna el id incramentado.
static int IdAutoIncremental(void);


/// @brief Inicializa el isEmpty de la lista d ejugadores en 1.
///
/// @param listaJugadores la lista de jugadores a inicializar.
/// @param size el tamanio de la lista a inicializar.
/// @return retorna 0 si hubo un error y retorna 1 si no hubo error.
int InicializarJugadores(eJugador listaJugadores[],int size);

/// @brief funcion que busca un espacio libre en la lista de jugadores y cunado encuantra finaliza.
///
/// @param listaJugadres lista de jugadores en la que se buscara un espacio libre.
/// @param size es el tamanio de la lista en la que se buscara un espacio libre.
/// @return retorna -1 su hubo un error y 1 si no hubo error.
int BuscarLibre(eJugador listaJugadores[],int size);

/// @brief Funcion que carga un unico jugador en la lista.
///
/// @param unJugador puntero el el que se guardara un jugador.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista d econfederaciones.
/// @return retorna -1 su hubo un error y 1 si no hubo error.
int CargarJugador(eJugador unJugador[], eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que hardcodea una lista de jugadores
///
/// @param listaJugadors lista de jugadores a hardcodear.
/// @param size tamanio de la lista a hardcodear.
/// @param cantidad cantidad de jugadores hardcodeados.
/// @return retorna 0 su hubo un error y 1 si no hubo error.
int HardcodearJugadores(eJugador listaJugadors[], int size, int cantidad);

/// @brief Funcion que carga una un jugador a la lista de jugadores.
///
/// @param listaJugador lista de jugadores en la que se guardara un jugador
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones para utilizar en la funcion en conjunto de cargarJugador
/// @param sizeConfederaciones el tamanio de la lista de confederaciones
/// @return retorna -1 su hubo un error y 1 si no hubo error.
int CargarListaJugadores(eJugador listaJugador[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);


/// @brief Funcion que muestra un unico jugador.
///
/// @param jugador jugador a mostrar.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
void MostrarJugador(eJugador jugador, eConfederacion listaConfederaciones[],int sizeConfederaciones);

/// @brief Funcion que que mustra una lista de jugadores completa.
///
/// @param listaJugadores lista de jugadores a mostrar.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederacions.
/// @param sizeConfederaciones tamanio de lista de confederaciones.
void MostrarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[],int sizeConfederaciones);

/// @brief Funcion que recibe un id y devulve el indice del jugador con ese id.
///
/// @param listaJugadores lista de jugadores en la que sebuscara por id
/// @param sizeJugadores tamanio de la lista de jugadores
/// @param id id del jugador a bucar
/// @return retorna el indice del jugador y retorna -1 si no se encuentra id alguno.
int VerificarId(eJugador listaJugadores[], int sizeJugadores, int id);

/// @brief Funcion que busca por id y da de baja un jugador con el mismo.
///
/// @param listaJugadores lista de jugadores en la que se bucasra y se dara de baja si existe.
/// @param sizeJugadores tamanio de la  lista de jugadores
/// @param listaConfederaciones lista de confederaciones
/// @param sizeConfederaciones tamanio de la lista de confederaciones
/// @return retorna -1 su hubo un error y 1 si no hubo error.
int BajaJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funocion que modifica los campps a eleccion de un jugador.
///
/// @param listaJugadores lista en la que se ralizaran los cmabios.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones
/// @param sizeConfederaciones tamanio del la lista de confederaciones.
/// @return retorna -1 su hubo un error y 1 si no hubo error.
int ModificacionJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que ordena una lista de jugadores por doble criterio.
///
/// @param listaJugadores lista de jugadores a ordenar.
/// @param sizeJugadores tamanio del la lista de jugadores
/// @param listaConfederacioines lista de confederaciones.
/// @param sizeConfederaciones tamanio de confederaciones.
/// @return retorna 0 su hubo un error y 1 si no hubo error.
int OrdenarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederacioines[], int sizeConfederaciones);
#endif /* ESTRUCTURAJUGADOR_H_ */
