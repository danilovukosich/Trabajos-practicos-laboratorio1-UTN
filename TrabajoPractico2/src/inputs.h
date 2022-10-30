/*
 * inputs.h
 *
 *  Created on: 26 oct. 2022
 *      Author: danil
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include "string.h"


/// @brief Funcion que pide un tipo de dato String.
///
/// @param string es el puntero donde se guardara el valor del string ingresado.
/// @param mensaje es el mensaje que se mostrara al pedir el string.
/// @param mensajeError es el mensaje que se mostrara al ingresar un string q no es valido.
/// @param size es el tamanio maxiomo del string con el que se validara el largo
/// @return retorna 0 si hubo algun error y retorna 1 si no tuvo errores
int Utn_GetString(char string[], char mensaje[], char mensajeError[], int size);

/// @brief Funcion que en conbinacion de 2 funciones pide un short int y lo valida.
///
/// @param pResultado es el puntero donde se guardara el valor del short int ingresado.
/// @param mensaje es el mensaje que se mostrara al pedir el short int.
/// @param mensajeError es el mensaje que se mostrara al ingresar un short int q no es valido.
/// @param minimo es el minimo que se validara al momento de pedir el short int.
/// @param maximo es el maximo que se validara al momento de pedir el short int.
/// @param reintentos
/// @return retorna -1 si hubo un error y 1 si no hubo error.
int Utn_GetShortInt ( short int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief Funcion que verifica que sea un short int.
///
/// @param pResultado es el puntero donde se guarda la variable.
/// @return retorna -1 si hubo un error y 1 si no hubo error
int GetShortInt ( short int * pResultado);

/// @brief Funcion que en conbinacion de 2 funciones pide un  int y lo valida.
///
/// @param pResultado es el puntero donde se guardara el valor del  int ingresado.
/// @param mensaje es el mensaje que se mostrara al pedir el  int.
/// @param mensajeError es el mensaje que se mostrara al ingresar un  int q no es valido.
/// @param minimo es el minimo que se validara al momento de pedir el  int.
/// @param maximo es el maximo que se validara al momento de pedir el  int.
/// @param reintentos
/// @return retorna -1 si hubo un error y 1 si no hubo error.
int Utn_GetInt ( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief Funcion que verifica que sea un  int.
///
/// @param pResultado es el puntero donde se guarda la variable.
/// @return retorna -1 si hubo un error y 1 si no hubo error
int GetInt ( int * pResultado);

/// @brief Funcion que valida que solo sean numeros.
///
/// @param cadena cadena a verificar.
/// @return  retorna -1 si hubo un error y 1 si no hubo error.
int esNumericaInt ( char * cadena);


/// @brief funcion que valida que no haya espacios y enters.
///
/// @param cadena la cadena a analizar
/// @param longitud el largo del buffer
/// @return retorna -1 si hubo algun error y 0 si no hubo error.
int MyGets ( char * cadena, int longitud);

/// @brief Funcion que en conbinacion de 2 funciones pide un  float y lo valida.
///
/// @param pResultado es el puntero donde se guardara el valor del  float ingresado.
/// @param mensaje es el mensaje que se mostrara al pedir el  int.
/// @param mensajeError es el mensaje que se mostrara al ingresar un  float q no es valido.
/// @param minimo es el minimo que se validara al momento de pedir el  float.
/// @param maximo es el maximo que se validara al momento de pedir el  float.
/// @param reintentos
/// @return retorna -1 si hubo un error y 1 si no hubo error.
int Utn_getFloat( float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/// @brief Funcion que verifica que sea un  float.
///
/// @param pResultado es el puntero donde se guarda la variable.
/// @return retorna -1 si hubo un error y 1 si no hubo error
float GetFloat ( float * pResultado);

/// @brief Funcion que valida que solo sean numeros flotantes.
///
/// @param cadena cadena a verificar.
/// @return  retorna -1 si hubo un error y 1 si no hubo error.
float EsNumericaFloat ( char * cadena);


#endif /* INPUTS_H_ */
