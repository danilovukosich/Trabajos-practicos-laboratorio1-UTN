/*
 * menus.h
 *
 *  Created on: 23 sep. 2022
 *      Author: danil
 */

#ifndef MENUS_H_
#define MENUS_H_

#include <stdio.h>
#include <stdlib.h>

/// @brief Funcion del Menu Principal.
///
/// @param costo1
/// @param costo2
/// @param costo3
/// @param contador1
/// @param contador2
/// @param contador3
/// @param contador4
void MenuPrincipal(float costo1, float costo2, float costo3, int contador1, int contador2, int contador3, int contador4);



/// @brief Funcion del Menu de costos.
///
/// @param costo1
/// @param costo2
/// @param costo3
void SubMenuCostos(float costo1, float costo2, float costo3);



/// @brief Funcion para limpiar consola
///
void LimpiarConsola(void);



/// @brief Funcion del Menu de carga de jugadores.
///
/// @param arqueros
/// @param defensores
/// @param mediocampistas
/// @param delanteros
void SubMenuCargaJugadores(int arqueros, int defensores, int mediocampistas, int delanteros);



/// @brief Funcion para mostrar los promedios.
///
/// @param promedioUefa
/// @param promedioConmebol
/// @param promedioConcaf
/// @param promedioAfc
/// @param promedioOfc
/// @param promedioCaf
void MostrarPromedio(float promedioUefa, float promedioConmebol, float promedioConcaf, float promedioAfc, float promedioOfc, float promedioCaf);



/// @brief Funcion para mostrar los costos.
///
/// @param costoTotal
/// @param aumento
/// @param costoFinal
void MostrarCostos(float costoTotal, float aumento, float costoFinal);


#endif /* MENUS_H_ */






