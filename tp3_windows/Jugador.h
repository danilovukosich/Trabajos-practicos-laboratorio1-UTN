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

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

int jug_MostrarJugador(Jugador* jugadorAux);//propia

int AddNuevoJugador(LinkedList* this, LinkedList* listaSelecciones);//propia

void IdAutoincremental(char* auxId);

int JugadorNacionalidad(int idNacionalidad, char* nacionalidad);

int JugadorPosicion(int idPosicion, char* posicion);

int BuscarIdJugador(LinkedList* this, int id);

int ModificarJugador(Jugador* jugador, LinkedList* listaSelecciones);



int ConvocarJugador(Jugador* jugadorAux, Seleccion* seleccionAux);

int QuitarJugadorDeSeleccion(Jugador* jugadorAux, Seleccion* seleccionAux);

int jug_MostrarJugadorConvocado(Jugador* jugadorAux);

int OrdenarJugadorNacionalidad(void* pJugador1, void* pJugador2);

int OrdenarSeleccionConfederacion(void* pSeleccion1, void* pSeleccion2);

int OrdenarJugadorEdad(void* pJugador1, void* pJugador2);

int OrdenarJugadorNombre(void* pJugador1, void* pJugador2);

//int JugadorDeDeterminadaConfederacion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);



//int jug_setIsEmpty(Jugador* this,int isEmpty);
//int jug_getIsEmpty(Jugador* this,int* isEmpty);


#endif // jug_H_INCLUDED
