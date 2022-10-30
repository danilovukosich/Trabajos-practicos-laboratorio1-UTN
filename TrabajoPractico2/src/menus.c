/*
 * menus.c
 *
 *  Created on: 26 oct. 2022
 *      Author: danil
 */

#ifndef MENUS_C_
#define MENUS_C_
#include "menus.h"


//alta-baja jugador-modificacion jugador-informes-salir
void MenuPrincipal(void)
{
	printf("-----------MENU PRINCIPAL-----------\n");
	printf("1)Alta jugador.\n"
			"2)Baja jugador.\n"
			"3)Modificacion jugador.\n"
			"4)Informes.\n"
			"5)SALIR\n");
}

void MenuModificacion(void)
{
	printf("|============================================================================================|\n");
	printf("|----------------------------------------MENU INFORMES---------------------------------------|\n");
	printf("|============================================================================================|\n");
	printf("|1)Modificar Nombre.                                                                         |\n"
		   "|2)Modificar Posicion.                                                                       |\n"
		   "|3)Modificar Numero de camiseta.                                                             |\n"
		   "|4)Modificar Sueldo.                                                                         |\n"
		   "|5)Modificar Confederacion.                                                                  |\n"
		   "|6)Modificar Anios de contrato                                                               |\n"
		   "|7)Volver al Menu Principal                                                                  |\n");
	printf("|============================================================================================|\n");
}

void MenuInformes(void)
{
	printf("|============================================================================================|\n");
	printf("|----------------------------------------MENU INFORMES---------------------------------------|\n");
	printf("|============================================================================================|\n");
	printf("|1)Listado de Jugadores Ordenado.                                                            |\n"
		   "|2)Listado de confederaciones con sus jugadores.                                             |\n"
		   "|3)Total y promedio de todos los salarios y jugadores que cobran más del salario promedio.   |\n"
		   "|4)Informar la confederación con mayor cantidad de años de contratos total.                  |\n"
		   "|5)Informar porcentaje de jugadores por cada confederación.                                  |\n"
		   "|6)Informar cual es la región con más jugadores y el listado de los mismos.                  |\n"
		   "|7)Volver al Menu Principal                                                                  |\n");
	printf("|============================================================================================|\n");
}

void MenuModificacionConfederacion(void)
{
	printf("|============================================================================================|\n");
	printf("|----------------------------------------MENU INFORMES---------------------------------------|\n");
	printf("|============================================================================================|\n");
	printf("|1)Modificar Nombre.                                                                         |\n"
		   "|2)Modificar Region.                                                                         |\n"
		   "|3)Modificar Anio creacion.                                                                  |\n"
		   "|4)Volver al Menu Principal.                                                                 |\n");
	printf("|============================================================================================|\n");
}

#endif /* MENUS_C_ */
