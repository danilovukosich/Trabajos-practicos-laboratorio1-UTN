/*
 ============================================================================
 Name        : TrabajoPractico1(2022).c
 Author      : Danilo vukosich 43034973    "1A"
 Description : Hello World in C, Ansi-style
 ============================================================================
 */




#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
#include "menus.h"

int main(void) {
	setbuf(stdout, NULL);

	int respuesta;
	int respuesta2;
	int respuesta3;
	float costoHospedaje=0;
	float costoComida=0;
	float costoTransporte=0;
	int retornoNum;

	int numeroCamiseta;
	int confederacion;

	int contadorJugadores=0;
	int contadorArqueros=0;
	int contadorDefensores=0;
	int contadorMediocampistas=0;
	int contadorDelateros=0;

	//contadores de confederaciones
	int contadorUefa=0;
	int contadorConmebol=0;
	int contadorConcaf=0;
	int contadorAfc=0;
	int contadorOfc=0;
	int contadorCaf=0;

	//promedios
	float promedioUefa;
	float promedioConmebol;
	float promedioConcaf;
	float promedioAfc;
	float promedioOfc;
	float promedioCaf;

	//resultado costos
	float costoMantenimientoTotal;
	float aumento=0;
	float costoMantenimientoFinal;

	//banderas
	int flagCosto1=0;
	int flagCosto2=0;
	int flagCosto3=0;
	int flagCalculos=0;





	do
	{

		MenuPrincipal(costoHospedaje, costoComida, costoTransporte, contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelateros);
		retornoNum=Utn_GetInt(&respuesta, "Ingrese una opcion: ", "Ingrese una opcion valida: ", 1, 5);

		switch(respuesta)
		{
		case 1:
			do
			{
				LimpiarConsola();
				SubMenuCostos(costoHospedaje, costoComida, costoTransporte);
				retornoNum=Utn_GetInt(&respuesta2, "Ingrese una opcion: ", "Ingrese una opcion valida: ", 1, 4);

				switch(respuesta2)
				{
				case 1:
					retornoNum=Utn_GetFloat(&costoHospedaje, "Ingrese el costo de Hospedaje: ", "Ingrese un costo VALIDO: ", 5000, 1000000);
					ValidarRetorno(retornoNum);
					flagCosto1=1;
					LimpiarConsola();
					break;

				case 2:
					retornoNum=Utn_GetFloat(&costoComida, "Ingrese el costo de la Comida: ", "Ingrese un costo VALIDO: ", 10000, 1000000);
					ValidarRetorno(retornoNum);
					flagCosto2=1;
					LimpiarConsola();
					break;

				case 3:
					retornoNum=Utn_GetFloat(&costoTransporte, "Ingrese el costo del Transporte: ", "Ingrese un costo VALIDO: ", 10000, 1000000);
					ValidarRetorno(retornoNum);
					flagCosto3=1;
					LimpiarConsola();
					break;

				case 4:
					LimpiarConsola();
					printf("Volvio al MENU PRINCIPAL...\n");
					break;

				}//fin del switch del subMenu1
			}while(respuesta2!=4);//fin subMenu1
			break;

		case 2:
			do
			{
				LimpiarConsola();
				SubMenuCargaJugadores(contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelateros);
				retornoNum=Utn_GetInt(&respuesta3, "Ingrese una opcion: ", "Ingrese una opcion valida: ", 1, 5);


				switch(respuesta3)
				{
				case 1:
					if(contadorArqueros<2)
					{
						retornoNum = PedirJugador(&numeroCamiseta, &confederacion);
						ValidarRetorno(retornoNum);
						ContarConfederaciones(confederacion, &contadorUefa, contadorUefa, &contadorConmebol, contadorConmebol, &contadorConcaf, contadorConcaf, &contadorAfc, contadorAfc, &contadorOfc, contadorOfc, &contadorCaf, contadorCaf);
						contadorArqueros++;
						contadorJugadores++;
						LimpiarConsola();
					}
					else
					{
						printf("No se pueden cargar mas arqueros!\n");
					}
					break;

				case 2:
					if(contadorDefensores<8)
					{
						retornoNum = PedirJugador(&numeroCamiseta, &confederacion);
						ValidarRetorno(retornoNum);
						ContarConfederaciones(confederacion, &contadorUefa, contadorUefa, &contadorConmebol, contadorConmebol, &contadorConcaf, contadorConcaf, &contadorAfc, contadorAfc, &contadorOfc, contadorOfc, &contadorCaf, contadorCaf);
						contadorDefensores++;
						contadorJugadores++;
						LimpiarConsola();
					}
					else
					{
						printf("No se pueden cargar mas Defensores!\n");
					}

					break;

				case 3:
					if(contadorMediocampistas<8)
					{
						retornoNum = PedirJugador(&numeroCamiseta, &confederacion);
						ValidarRetorno(retornoNum);
						ContarConfederaciones(confederacion, &contadorUefa, contadorUefa, &contadorConmebol, contadorConmebol, &contadorConcaf, contadorConcaf, &contadorAfc, contadorAfc, &contadorOfc, contadorOfc, &contadorCaf, contadorCaf);
						contadorMediocampistas++;
						contadorJugadores++;
						LimpiarConsola();
					}
					else
					{
						printf("No se pueden cargar mas Mediocampistas!\n");
					}

					break;

				case 4:
					if(contadorDelateros<4)
					{
						retornoNum = PedirJugador(&numeroCamiseta, &confederacion);
						ValidarRetorno(retornoNum);
						ContarConfederaciones(confederacion, &contadorUefa, contadorUefa, &contadorConmebol, contadorConmebol, &contadorConcaf, contadorConcaf, &contadorAfc, contadorAfc, &contadorOfc, contadorOfc, &contadorCaf, contadorCaf);
						contadorDelateros++;
						contadorJugadores++;
						LimpiarConsola();
					}
					else
					{
						printf("No se pueden cargar mas Delanteros!\n");
					}
					break;

				case 5:
					LimpiarConsola();
					printf("Volvio al MENU PRINCIPAL...\n");

					break;
				}

			}while(respuesta3!=5);

			break;

		case 3:
			if(flagCosto1==1 && flagCosto2==1 && flagCosto3==1  && contadorJugadores>0)
			{
				retornoNum=CalcularPromedioJugadores(contadorJugadores, contadorUefa, contadorConmebol, contadorConcaf, contadorAfc, contadorOfc, contadorCaf, &promedioUefa, &promedioConmebol, &promedioConcaf, &promedioAfc, &promedioOfc, &promedioCaf);
				ValidarRetorno(retornoNum);
				costoMantenimientoTotal=CalcularCostos(costoHospedaje, costoComida, costoTransporte);
				retornoNum=CalcularCostoFinal(costoMantenimientoTotal, promedioUefa, &aumento, &costoMantenimientoFinal);
				flagCalculos=1;
			}
			else
			{
				printf("Error...Ingrese los costos y al menos un jugador! \n");
			}
			break;

		case 4:
			if(flagCalculos==1)
			{
				LimpiarConsola();
				MostrarPromedio(promedioUefa, promedioConmebol, promedioConcaf, promedioAfc, promedioOfc, promedioCaf);
				MostrarCostos(costoMantenimientoTotal, aumento, costoMantenimientoFinal);
			}
			else
			{
				printf("Error...calcule los costos! \n");
			}


			break;

		case 5:
			printf("Usted SALIO del programa.");
		break;
		}//fin del switch principal.


	}while(respuesta!=5);


	return EXIT_SUCCESS;
}
