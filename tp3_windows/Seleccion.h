#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

}Seleccion;


/// @brief Crea una selecicon en memoria dinamica
///
/// @return Seleccion*
Seleccion* selec_new();


/// @brief Recibe los datos en string y los setea en una nueva seleccion
///
/// @param idStr
/// @param paisStr
/// @param confederacionStr
/// @param convocadosStr
/// @return Seleccion*
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);


/// @brief Elimina una seleccion de memoria.
///
void selec_delete();



/// @brief getter del id de la seleccion
///
/// @param this
/// @param id
/// @return int
int selec_getId(Seleccion* this,int* id);
/// @brief setter del id de la seleccion
///
/// @param this
/// @param id
/// @return int
int selec_setId(Seleccion* this, int id);


/// @brief getter de pais de la seleccion
///
/// @param this
/// @param pais
/// @return int
int selec_getPais(Seleccion* this,char* pais);
/// @brief setter del pais de la seleccion
///
/// @param this
/// @param pais
/// @return int
int selec_setPais(Seleccion* this, char* pais);


/// @brief getter de la confederacion de la seleccion
///
/// @param this
/// @param confederacion
/// @return int
int selec_getConfederacion(Seleccion* this,char* confederacion);
/// @brief setter de la confedederacion de la seleccion
///
/// @param this
/// @param confederacion
/// @return int
int selec_setConfederacion(Seleccion* this, char* confederacion);
//int selec_getIsEmpty(Seleccion* this,int* isEmpty);


/// @brief setter de los convocados de la seleccion
///
/// @param this
/// @param convocados
/// @return int
int selec_setConvocados(Seleccion* this,int convocados);
/// @brief getter de los convocados de la seleccion
///
/// @param this
/// @param convocados
/// @return int
int selec_getConvocados(Seleccion* this,int* convocados);


/// @brief Funcion que printea un jugador
///
/// @param seleccionAux
/// @return int -1 si hubo error y 1 si salio con exito
int selec_MostrarSeleccion(Seleccion* seleccionAux);


/// @brief Funcion que printea los paises
///
/// @param seleccionAux
/// @return int -1 si hubo error y 1 si salio con exito
int selec_MostrarPaisDeNacionalidad(Seleccion* seleccionAux);


/// @brief Funcion que segun el id que le paso me retorna el indice
/// en donde se encuentra la seleccion con ese id
///
/// @param listaSeleccion
/// @param id
/// @return int -1 si hubo error y 1 si salio con exito
int BuscarIdSeleccion(LinkedList* listaSeleccion, int id);


/// @brief Funcion que compara 2 selecciones por confederacion
///
/// @param pSeleccion1
/// @param pSeleccion2
/// @return int segun lo que devueva su comparacion
int OrdenarSeleccionConfederacion(void* pSeleccion1, void* pSeleccion2);



/// @brief Funcion que segun un numero que le paso me devuelve una confederacion en string
///
/// @param confederacionInt
/// @param confederacion
/// @return int -1 si hubo error y 1 si salio con exito
int GetConfederacionSeleccionada(int confederacionInt, char* confederacion);
#endif // selec_H_INCLUDED
