/*
 * menus.h
 *
 *  Created on: 13 nov. 2022
 *      Author: danil
 */

#ifndef MENUS_H_
#define MENUS_H_
#include <stdio.h>
#include <stdlib.h>

/// @brief Funcion que printea el menu principal.
///
void MenuPrincipal(void);


/// @brief Funcion que printea el menu de listados
///
void MenuListados(void);

/// @brief Funcion que printea las poosiciones de los jugadores a elegir.
///
void ElegirPosicion(void);

/// @brief Funcion que printea el menu de modificacion de un jugador.
///
void MenuModificacionJugador(void);

/// @brief Funcion que printea el menu para convocar y
/// eliminar de una seleccion a un jugador.
///
///
void MenuConvocados(void);

/// @brief Funcion que printea el menu para seleccionar
/// que ordenamientos realizar y mostrar
///
void MenuOrdenamientos(void);


/// @brief Funcion que printea una lista de las confederaciones
/// para elgir entre ellas.
void ElegirConfederacion(void);

#endif /* MENUS_H_ */
