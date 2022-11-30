#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "inputs.h"
#include "menus.h"
#include "Controller.h"
#include "Seleccion.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

}Jugador;


/// @brief Crea un jugador en memoria dinamica
///
/// @return Jugador*
Jugador* jug_new();

/// @brief Recibe los datos en string y los setea en un nuevo jugador.
///
/// @param idStr
/// @param nombreCompletoStr
/// @param edadStr
/// @param posicionStr
/// @param nacionalidadStr
/// @param idSelccionStr
/// @return Jugador*
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

/// @brief Elimina un jugador de memoria.
///
/// @param this
void jug_delete(Jugador* this);


/// @brief setter del id del jugador.
///
/// @param this
/// @param id
/// @return int
int jug_setId(Jugador* this,int id);
/// @brief getter del id de jugador.
///
/// @param this
/// @param id
/// @return
int jug_getId(Jugador* this,int* id);


/// @brief Setter delnombre del jugador.
///
/// @param this
/// @param nombreCompleto
/// @return int
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
/// @brief getter del nombre completo del jugador.
///
/// @param this
/// @param nombreCompleto
/// @return int
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);


/// @brief Setter posicion del jugador.
///
/// @param this
/// @param posicion
/// @return int
int jug_setPosicion(Jugador* this,char* posicion);
/// @brief Getter posicion del jugador.
///
/// @param this
/// @param posicion
/// @return int
int jug_getPosicion(Jugador* this,char* posicion);


/// @brief setter  de la nacionalidad del jugador
///
/// @param this
/// @param nacionalidad
/// @return int
int jug_setNacionalidad(Jugador* this,char* nacionalidad);
/// @brief getter de la nacionalidad del jugador
///
/// @param this
/// @param nacionalidad
/// @return int
int jug_getNacionalidad(Jugador* this,char* nacionalidad);


/// @brief setter de la edad del jugdor.
///
/// @param this
/// @param edad
/// @return int
int jug_setEdad(Jugador* this,int edad);
/// @brief getter de la edad del jugador.
///
/// @param this
/// @param edad
/// @return int
int jug_getEdad(Jugador* this,int* edad);


/// @brief setter de la id de la seleccion del jugador
///
/// @param this
/// @param idSeleccion
/// @return int
int jug_setIdSeleccion(Jugador* this,int idSeleccion);
/// @brief getter id de la seleccion del jugador
///
/// @param this
/// @param idSeleccion
/// @return int
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

/// @brief Funcion que printea un jugador.
///
/// @param jugadorAux
/// @return int -1 si hubo error y 1 si salio con exito
int jug_MostrarJugador(Jugador* jugadorAux);//propia


/// @brief Funcion para añadir un nuevo jugador.
///
/// @param this
/// @param listaSelecciones
/// @return int -1 si hubo error y 1 si salio con exito.
int AddNuevoJugador(LinkedList* this, LinkedList* listaSelecciones);//propia


/// @brief Funcion que lee un archivo el cual tiene un id en el, lo devuelve como string y
/// lo aumenta +1 para el proximo.
///
/// @param auxId
void IdAutoincremental(char* auxId);


/// @brief Funcion que segun el id de la nacionalidad devuelve na nacionalidad por puntero.
///
/// @param idNacionalidad
/// @param nacionalidad
/// @return int -1 si hubo error y 1 si salio con exito
int JugadorNacionalidad(int idNacionalidad, char* nacionalidad);


/// @brief Funcion que segun el id de la posicion devuelve na posicion por puntero.
///
/// @param idPosicion
/// @param posicion
/// @return int -1 si hubo error y 1 si salio con exito.
int JugadorPosicion(int idPosicion, char* posicion);


/// @brief Funcion que segun el id de la seleccion que le paso devuleve la seleccion por puntero.
///
/// @param idSeleccion
/// @param seleccionJugador
/// @return int -1 si hubo error y 1 si salio con exito.
int JugadorSelecion(int idSeleccion, char* seleccionJugador);


/// @brief Funcion que segun el id que le paso me retorna el indice en donde se encuentra
/// el jugador con ese id.
///
/// @param this
/// @param id
/// @return int retorna -1 si hubo algun problema y retorna el indice del jugador si lo encuentra
int BuscarIdJugador(LinkedList* this, int id);


/// @brief Funcion para modificar un jugador seleccionado de la lista
///
/// @param jugador
/// @param listaSelecciones
/// @return int -1 si hubo error y 1 si salio con exito.
int ModificarJugador(Jugador* jugador, LinkedList* listaSelecciones);


/// @brief Funcion que convoca a un jugador seleccionado a una seleccion seleccionada
///
/// @param jugadorAux
/// @param seleccionAux
/// @return int -1 si hubo error y 1 si salio con exito.
int ConvocarJugador(Jugador* jugadorAux, Seleccion* seleccionAux);

/// @brief
///
/// @param jugadorAux
/// @param seleccionAux
/// @return int -1 si hubo error y 1 si salio con exito.
int QuitarJugadorDeSeleccion(Jugador* jugadorAux, Seleccion* seleccionAux);


/// @brief Funcion que printea un jugador solo si esta convocado
///
/// @param jugadorAux
/// @return int -1 si hubo error y 1 si salio con exito.
int jug_MostrarJugadorConvocado(Jugador* jugadorAux);


/// @brief Funcion que compara 2 jugadores segun su nacionalidad.
///
/// @param pJugador1
/// @param pJugador2
/// @return int segun lo que devueva su comparacion
int OrdenarJugadorNacionalidad(void* pJugador1, void* pJugador2);


/// @brief Funcion que compara 2 jugadores por edad.
///
/// @param pJugador1
/// @param pJugador2
/// @return int segun lo que devueva su comparacion
int OrdenarJugadorEdad(void* pJugador1, void* pJugador2);


/// @brief Funcion que compara 2 jugadores por su nombre.
///
/// @param pJugador1
/// @param pJugador2
/// @return int segun lo que devueva su comparacion
int OrdenarJugadorNombre(void* pJugador1, void* pJugador2);


//int jug_setIsEmpty(Jugador* this,int isEmpty);
//int jug_getIsEmpty(Jugador* this,int* isEmpty);


#endif // jug_H_INCLUDED
