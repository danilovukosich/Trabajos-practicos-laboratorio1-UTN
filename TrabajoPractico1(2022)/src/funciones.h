/*
 * funciones.h
 *
 *  Created on: 12 sep. 2022
 *      Author: danil
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>






/// @brief Funcion para pedir un Entero y validarlo.
///
/// @param numero
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @return retorno (para saber si tuvo un error o se ingreso correctamente).
int Utn_GetInt(int* numero, char mensaje[], char mensajeError[], int minimo, int maximo);



/// @brief Funcion para pedir un Flotante y validarlo.
///
/// @param numero
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @return retorno (para saber si tuvo un error o se ingreso correctamente).
int Utn_GetFloat(float* numero, char mensaje[], char mensajeError[], int minimo, int maximo);



/// @brief Funcion que valida el ingreso correcto de los numeros.
///
/// @param retorno
void ValidarRetorno(int retorno);



/// @brief Funcion que pide los datos de un jugador.
///
/// @param numeroCamiseta
/// @param confederacion
/// @return retorno (para validar el ingreso correcto de los datos).
int PedirJugador(int* numeroCamiseta, int* confederacion);



/// @brief Funcion para contar las confederaciones ingresadas y retornarlas por punteros.
///
/// @param confederacion
/// @param uefa
/// @param contadorUefa
/// @param conmebol
/// @param contadorConmebol
/// @param concaf
/// @param contadorConcaf
/// @param afc
/// @param contadorAfc
/// @param ofc
/// @param contadorOfc
/// @param caf
/// @param contadorCaf
void ContarConfederaciones(int confederacion, int* uefa,int contadorUefa, int* conmebol,int contadorConmebol, int* concaf,int contadorConcaf, int* afc, int contadorAfc, int* ofc, int contadorOfc, int* caf, int contadorCaf);



/// @brief Funcion que calcula promedios de jugadores y los devuelve con punteros.
///
/// @param contadorJugadores
/// @param contadorUefa
/// @param contadorConmebol
/// @param contadorConcaf
/// @param contadorAfc
/// @param contadorOfc
/// @param contadorCaf
/// @param promedioUefa
/// @param promedioConmebol
/// @param promedioConcaf
/// @param promedioAfc
/// @param promedioOfc
/// @param promedioCaf
/// @return retorno (Retorna un rentero para validar si se calculo bien).
int CalcularPromedioJugadores(int contadorJugadores, int contadorUefa, int contadorConmebol, int contadorConcaf, int contadorAfc, int contadorOfc, int contadorCaf,float* promedioUefa, float* promedioConmebol, float* promedioConcaf, float* promedioAfc, float* promedioOfc, float* promedioCaf);



/// @brief Funcion que calcula el costo total.
///
/// @param costo1
/// @param costo2
/// @param costo3
/// @return costoTotal (Retorna el costo total).
float CalcularCostos(float costo1, float costo2, float costo3);



/// @brief Funcion para calcular el costo final y el aumento.
///
/// @param costoTotal
/// @param porcentajeUefa
/// @param aumento
/// @param costoFinal
/// @return retorno (para validar el calculo).
int CalcularCostoFinal(float costoTotal, float porcentajeUefa, float* aumento, float* costoFinal);



#endif /* FUNCIONES_H_ */
