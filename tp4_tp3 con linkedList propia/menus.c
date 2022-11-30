/*
 * menus.c
 *
 *  Created on: 13 nov. 2022
 *      Author: danil
 */

#ifndef MENUS_C_
#define MENUS_C_
#include "menus.h"

void MenuPrincipal(void)
{
	printf("|====================================|\n");
	printf("|-----------MENU PRINCIPAL-----------|\n");
	printf("|====================================|\n");
	printf("|1)Carga de jugador.                 |\n"
		   "|2)ALTA jugador.                     |\n"
		   "|3)MODIFICACION jugador.             |\n"
		   "|4)BAJA jugador.                     |\n"
		   "|5)Listados.                         |\n"
		   "|6)Convocar jugadores.               |\n"
		   "|7)Ordenar y listar.                 |\n"
		   "|8)Generar archivo binario.          |\n"
		   "|9)Cargar archivo binario.           |\n"
		   "|10)Guardar archivos .CSV.           |\n"
	       "|11)SALIR                            |\n");
	printf("|====================================|\n");
}



void MenuListados(void)
{
	printf("|==============================================|\n");
	printf("|------------------MENU LISTADOS---------------|\n");
	printf("|==============================================|\n");
	printf("|1)Listado de Jugadores.                       |\n"
		   "|2)Listado selecciones.                        |\n"
		   "|3)Listado de jugadores convocados.            |\n"
		   "|4)Volver al Menu Principal                    |\n");
	printf("|==============================================|\n");
}



void ElegirPosicion(void)
{
	printf("|==============================================|\n");
	printf("|-------------------POSICIONES-----------------|\n");
	printf("|==============================================|\n");
	printf("|1)Portero.                                    |\n"
		   "|2)Defensa central.                            |\n"
		   "|3)Lateral izquierdo.                          |\n"
		   "|4)Lateral derecho.                            |\n"
		   "|5)Pivote.                                     |\n"
		   "|6)Mediocentro.                                |\n"
		   "|7)Mediocentro ofensivo.                       |\n"
		   "|8)Extremo izquierdo.                          |\n"
		   "|9)Extremo derecho.                            |\n"
		   "|10)Mediapunta.                                |\n"
		   "|11)Delantero centro.                          |\n");
	printf("|==============================================|\n");
}

void MenuModificacionJugador(void)
{
	printf("|========================================|\n");
	printf("|--------MENU MODIFICACION JUGADOR-------|\n");
	printf("|========================================|\n");
	printf("|1)Modificar Nombre.                     |\n"
		   "|2)Modificar Edad.                       |\n"
		   "|3)Modificar Posicion.                   |\n"
		   "|4)Modificar Nacionalidad.               |\n"
		   "|5)Volver al Menu Principal.             |\n");
	printf("|========================================|\n");
}

void MenuConvocados(void)
{
	printf("|========================================|\n");
	printf("|----------MENU CONVOCAR JUGADOR---------|\n");
	printf("|========================================|\n");
	printf("|1)Convocar Jugador.                     |\n"
		   "|2)Quitar jugador de seleccion.          |\n"
		   "|3)Volver al menu principal.             |\n");
	printf("|========================================|\n");
}


void ElegirConfederacion(void)
{
	printf("|========================================|\n");
	printf("|-------------CONFEDERACIONES------------|\n");
	printf("|========================================|\n");
	printf("|1)AFC.                                  |\n"
		   "|2)CAF.                                  |\n"
		   "|3)CONCACAF.                             |\n"
		   "|4)CONMEBOL.                             |\n"
		   "|5)UEFA.                                 |\n");
	printf("|========================================|\n");
}

void MenuOrdenamientos(void)
{
	printf("|========================================|\n");
	printf("|--------MENU MODIFICACION JUGADOR-------|\n");
	printf("|========================================|\n");
	printf("|1)Listar jugadores por nacionalidad.    |\n"
		   "|2)Listar selecciones por confedracion.  |\n"
		   "|3)Listar jugadores por edad.            |\n"
		   "|4)Listar jugadores por nombre.          |\n"
		   "|5)Volver al Menu Principal.             |\n");
	printf("|========================================|\n");
}


#endif /* MENUS_C_ */
