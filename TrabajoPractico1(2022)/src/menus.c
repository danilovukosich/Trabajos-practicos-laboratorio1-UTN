/*
 * menus.c
 *
 *  Created on: 23 sep. 2022
 *      Author: danil
 */

#ifndef MENUS_C_
#define MENUS_C_

#include "menus.h"

void MenuPrincipal(float costo1, float costo2, float costo3, int contador1, int contador2, int contador3, int contador4)
{
	printf("            >MENU PRINCIPAL<\n\n"
			"1)Ingreso de los constos de mantenimiento.\n"
			"Costo de Hospedaje -> $%.2f\n"
			"Costo de Comida -> $%.2f\n"
			"Costo de Transporte -> $%.2f\n\n"
			"2)Carga de jugadores.\n"
			"Arqueros -> %d\n"
			"Defensores -> %d\n"
			"Mediocampistas -> %d\n"
			"Delanteros -> %d\n\n"
			"3)Realizar todos los calculos.\n"
			"4)Informar todos los resultados.\n"
			"5)Salir.\n",costo1, costo2, costo3, contador1, contador2, contador3, contador4);
}


void SubMenuCostos(float costo1, float costo2, float costo3)
{
	printf("        <CARGA DE COSTOS>\n\n"
			"1)Costo de Hospedaje -> %.2f\n"
			"2)Costo de Comida -> %.2f\n"
			"3)Costo de Treansporte -> %.2f\n"
			"4)VOLVER ATRAS\n",costo1, costo2, costo3);
}



void LimpiarConsola(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


void SubMenuCargaJugadores(int arqueros, int defensores, int mediocampistas, int delanteros)
{
	printf("     >CARGA JUGADORES<      \n\n"
			"1)Arqueros -> %d\n"
			"2)Defensores -> %d\n"
			"3)Mediocampistas -> %d\n"
			"4)Delanteros -> %d\n"
			"5)Volver al MENU PRINCIPAL.\n", arqueros, defensores, mediocampistas, delanteros);
}


void MostrarPromedio(float promedioUefa, float promedioConmebol, float promedioConcaf, float promedioAfc, float promedioOfc, float promedioCaf)
{
	printf("         INFORME RESULTADOS\n\n"
			"Porcentaje UEFA: %.2f\n"
			"Porcentaje CONMEBOL: %.2f\n"
			"Porcentaje CONCAF: %.2f\n"
			"Porcentaje AFC: %.2f\n"
			"Porcentaje OFC: %.2f\n"
			"Porcentaje CAF: %.2f\n", promedioUefa, promedioConmebol, promedioConcaf, promedioAfc, promedioOfc, promedioCaf);
}


void MostrarCostos(float costoTotal, float aumento, float costoFinal)
{
	printf("\nEl costo de mantenimiento es de $%.2f y recibio un aumento de $%.2f, su nuevo valor es de $%.2f\n\n", costoTotal, aumento, costoFinal);
}



#endif /* MENUS_C_ */






