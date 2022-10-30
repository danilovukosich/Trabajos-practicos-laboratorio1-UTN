/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : danilo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "estructuraJugador.h"
#include "informes.h"


#define TAM_JUGADORES 3000
#define TAM_CONFEDERACIONES 6
#define TAM_HARDCODEO 10

int main(void) {
	setbuf(stdout, NULL);

	int respuestaMenu;
	int respuestaInformes;
	eJugador listaJugadores[TAM_JUGADORES];
	eConfederacion listaConfederaciones[TAM_CONFEDERACIONES];

	InicializarJugadores(listaJugadores,TAM_JUGADORES);//inicializa en 1

	HardcodearJugadores(listaJugadores, TAM_JUGADORES, TAM_HARDCODEO);

	HardcodearConfederaciones(listaConfederaciones, TAM_CONFEDERACIONES);



	do
	{
		MenuPrincipal();
		fflush(stdin);
		Utn_GetInt(&respuestaMenu, "Ingrese una opcion:\n", "Ingrese una opcion valida:\n", 1, 5, 1000);

		switch(respuestaMenu)
		{
		case 1:
			CargarListaJugadores(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
			break;
		case 2:
			BajaJugador(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
			break;
		case 3:
			ModificacionJugador(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
			break;
		case 4:

			do
			{
				MenuInformes();
				fflush(stdin);
				Utn_GetInt(&respuestaInformes, ">Ingrese una opcion: \n", "ERROR ingrese opcion VALIDA", 1, 7, 1000);

				switch(respuestaInformes)
				{
				case 1:
					OrdenarListaJugadores(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					MostrarListaJugadores(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					break;

				case 2:
					InformeConfederacionConmebol(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					InformeConfederacionUefa(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					InformeConfederacionAfc(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					InformeConfederacionCaf(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					InformeConfederacionConcacaf(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					InformeConfederacionOfc(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					break;

				case 3:
					InformeJugadoresSueldoPromedio(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					break;
				case 4:
					InformeConfederacionMayorCantidadAnios(listaJugadores, TAM_JUGADORES);
					break;
				case 5:
					InformePorcentajeJugadoresPorConfederacion(listaJugadores, TAM_JUGADORES);
					break;
				case 6:
					InformarRegionMasJugadores(listaJugadores, TAM_JUGADORES, listaConfederaciones, TAM_CONFEDERACIONES);
					break;


				}



			}while(respuestaInformes!=7);

			break;
		case 5:
			printf("\nUsted SALIO del programa...\n");
			break;

		}

	}while(respuestaMenu!=5);


	return EXIT_SUCCESS;
}
