/*
 * informes.h
 *
 *  Created on: 29 oct. 2022
 *      Author: danil
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "estructuraJugador.h"

/// @brief Funcion que imprime un Informe de la confederacion CONMEBOL con sus respectivos jugadores.
///
/// @param listaJugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
void InformeConfederacionConmebol(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que imprime un Informe de la confederacion UEFA con sus respectivos jugadores.
///
/// @param listaJugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
void InformeConfederacionUefa(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que imprime un Informe de la confederacion AFC con sus respectivos jugadores.
///
/// @param listaJugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
void InformeConfederacionAfc(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que imprime un Informe de la confederacion CAF con sus respectivos jugadores.
///
/// @param listaJugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
void InformeConfederacionCaf(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que imprime un Informe de la confederacion CONCACAF con sus respectivos jugadores.
///
/// @param listaJugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
void InformeConfederacionConcacaf(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que imprime un Informe de la confederacion OFC con sus respectivos jugadores.
///
/// @param listaJugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
void InformeConfederacionOfc(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Funcion que imprime un Informe de el pormedio de los sueldo, los sueldos totales y los jugadores por encima del promedio.
///
/// @param listaJugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
void InformeJugadoresSueldoPromedio(eJugador listajugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief funcion que imprime la confederacion con mayor cantidad de años de contrato.
///
/// @param listajugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadorestamanio de la lista de jugadores.
void InformeConfederacionMayorCantidadAnios(eJugador listajugadores[], int sizeJugadores);

/// @brief funcion que imprime el porcentaje de jugadores por confederacion.
///
/// @param listajugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadores tamanio de la lista de jugadores.
void InformePorcentajeJugadoresPorConfederacion(eJugador listaJugadores[], int sizeJugadores);

/// @brief Funcion que imprime la region con mas jugadores.
///
/// @param listaJugadores lista de jugadores de las cuales de sacan los datos para el informe.
/// @param sizeJugadores tamanio de la lista de jugadores.
/// @param listaConfederaciones lista de confederaciones.
/// @param sizeConfederaciones tamanio de la lista de confederaciones.
void InformarRegionMasJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

#endif /* INFORMES_H_ */
