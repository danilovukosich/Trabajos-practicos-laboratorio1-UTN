/*
 * informes.c
 *
 *  Created on: 29 oct. 2022
 *      Author: danil
 */

#ifndef INFORMES_C_
#define INFORMES_C_
#include "informes.h"


void InformeConfederacionConmebol(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		printf("\n|====================================================LISTA JUGADORES CONMEBOL==============================================|\n");
		printf("|  ID    |              NOMBRE           |    POSICION    | NRO. CAMISETA |     SUELDO    | CONFEDERACION | AÑOS DE CONTRATO |\n");
		printf("|============================================================================================================================|\n");

		for(int i=0;i<sizeJugadores;i++)
		{
			if(listaJugadores[i].isEmpty==0 && listaJugadores[i].idConfederacion==100)
			{
				MostrarJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
			}
		}
	}
}

void InformeConfederacionUefa(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		printf("\n|=====================================================LISTA JUGADORES UEFA=================================================|\n");
		printf("|  ID    |              NOMBRE           |    POSICION    | NRO. CAMISETA |     SUELDO    | CONFEDERACION | AÑOS DE CONTRATO |\n");
		printf("|============================================================================================================================|\n");

		for(int i=0;i<sizeJugadores;i++)
		{
			if(listaJugadores[i].isEmpty==0 && listaJugadores[i].idConfederacion==101)
			{
				MostrarJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
			}
		}
	}
}

void InformeConfederacionAfc(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		printf("\n|======================================================LISTA JUGADORES AFC=================================================|\n");
		printf("|  ID    |              NOMBRE           |    POSICION    | NRO. CAMISETA |     SUELDO    | CONFEDERACION | AÑOS DE CONTRATO |\n");
		printf("|============================================================================================================================|\n");

		for(int i=0;i<sizeJugadores;i++)
		{
			if(listaJugadores[i].isEmpty==0 && listaJugadores[i].idConfederacion==102)
			{
				MostrarJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
			}
		}
	}
}

void InformeConfederacionCaf(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		printf("\n|======================================================LISTA JUGADORES CAF=================================================|\n");
		printf("|  ID    |              NOMBRE           |    POSICION    | NRO. CAMISETA |     SUELDO    | CONFEDERACION | AÑOS DE CONTRATO |\n");
		printf("|============================================================================================================================|\n");

		for(int i=0;i<sizeJugadores;i++)
		{
			if(listaJugadores[i].isEmpty==0 && listaJugadores[i].idConfederacion==103)
			{
				MostrarJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
			}
		}
	}
}

void InformeConfederacionConcacaf(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		printf("\n|====================================================LISTA JUGADORES CONCACAF==============================================|\n");
		printf("|  ID    |              NOMBRE           |    POSICION    | NRO. CAMISETA |     SUELDO    | CONFEDERACION | AÑOS DE CONTRATO |\n");
		printf("|============================================================================================================================|\n");

		for(int i=0;i<sizeJugadores;i++)
		{
			if(listaJugadores[i].isEmpty==0 && listaJugadores[i].idConfederacion==104)
			{
				MostrarJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
			}
		}
	}
}

void InformeConfederacionOfc(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		printf("\n|=======================================================LISTA JUGADORES OFC================================================|\n");
		printf("|  ID    |              NOMBRE           |    POSICION    | NRO. CAMISETA |     SUELDO    | CONFEDERACION | AÑOS DE CONTRATO |\n");
		printf("|============================================================================================================================|\n");

		for(int i=0;i<sizeJugadores;i++)
		{
			if(listaJugadores[i].isEmpty==0 && listaJugadores[i].idConfederacion==105)
			{
				MostrarJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
			}
		}
	}
}


void InformeJugadoresSueldoPromedio(eJugador listajugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	float acumuladorSalarios=0;
	int contadorSalario=0;
	float promedioSalarios;


	if(listajugadores!=NULL && sizeJugadores>0 && listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		printf("======INFORME SALARIOS======\n");

		for(int i=0; i<sizeJugadores; i++)
		{
			if(listajugadores[i].isEmpty==0)
			{
				contadorSalario++;
				acumuladorSalarios+=listajugadores[i].salario;


			}
		}

		promedioSalarios=acumuladorSalarios/contadorSalario;

		printf("\nTotal Salarios $%.2f\n", acumuladorSalarios);
		printf("Promedio de salarios: $%.2f\n",promedioSalarios);


		printf("\n|==========================================LISTA JUGADORES POR ENCIMA DEL PROMEDIO===========================================|\n");
		printf("|  ID    |              NOMBRE           |    POSICION    | NRO. CAMISETA |     SUELDO    | CONFEDERACION | AÑOS DE CONTRATO |\n");
		printf("|============================================================================================================================|\n");
		for(int i=0; i<sizeJugadores; i++)
		{
			if(listajugadores[i].isEmpty==0 && listajugadores[i].salario>promedioSalarios)
			{

				MostrarJugador(listajugadores[i], listaConfederaciones, sizeConfederaciones);

			}
		}



	}
}


void InformeConfederacionMayorCantidadAnios(eJugador listajugadores[], int sizeJugadores)
{


	int acumuladorConmebol=0;
	int acumuladorUefa=0;
	int acumuladorAfc=0;
	int acumuladorCaf=0;
	int acumuladorConcaf=0;
	int acumuladorOfc=0;

	if(listajugadores!=NULL && sizeJugadores>0)
	{
		for(int i=0; i<sizeJugadores; i++)
		{
			if(listajugadores[i].isEmpty==0)
			{
				switch(listajugadores[i].idConfederacion)
				{
				case 100:
					acumuladorConmebol+=listajugadores[i].aniosContrato;
					break;
				case 101:
					acumuladorUefa+=listajugadores[i].aniosContrato;
					break;
				case 102:
					acumuladorAfc+=listajugadores[i].aniosContrato;
					break;
				case 103:
					acumuladorCaf+=listajugadores[i].aniosContrato;
					break;
				case 104:
					acumuladorConcaf+=listajugadores[i].aniosContrato;
					break;
				case 105:
					acumuladorOfc+=listajugadores[i].aniosContrato;
					break;
				}
			}

		}
		if(acumuladorConmebol>acumuladorUefa && acumuladorConmebol>acumuladorAfc && acumuladorConmebol>acumuladorCaf && acumuladorConmebol>acumuladorConcaf && acumuladorConmebol>acumuladorOfc)
		{
			printf("\nLa confederacion con mayor cantidad de anios es CONMEBOL con %d anios en total. \n", acumuladorConmebol);
		}
		else
		{
			if(acumuladorUefa>acumuladorConmebol && acumuladorUefa>acumuladorAfc && acumuladorUefa>acumuladorCaf && acumuladorUefa>acumuladorConcaf && acumuladorUefa>acumuladorOfc)
			{
				printf("\nLa confederacion con mayor cantidad de anios es UEFA con %d anios en total. \n", acumuladorUefa);
			}
			else
			{
				if(acumuladorAfc>acumuladorConmebol && acumuladorAfc>acumuladorUefa && acumuladorAfc>acumuladorCaf && acumuladorAfc>acumuladorConcaf && acumuladorAfc>acumuladorOfc)
				{
					printf("\nLa confederacion con mayor cantidad de anios es AFC con %d anios en total. \n", acumuladorAfc);
				}
				else
				{
					if(acumuladorCaf>acumuladorConmebol && acumuladorCaf>acumuladorUefa && acumuladorCaf>acumuladorAfc && acumuladorCaf>acumuladorConcaf && acumuladorCaf>acumuladorOfc)
					{
						printf("\nLa confederacion con mayor cantidad de anios es CAF con %d anios en total. \n", acumuladorCaf);
					}
					else
					{
						if(acumuladorConcaf>acumuladorConmebol && acumuladorConcaf>acumuladorUefa && acumuladorConcaf>acumuladorAfc && acumuladorConcaf>acumuladorCaf && acumuladorConcaf>acumuladorOfc)
						{
							printf("\nLa confederacion con mayor cantidad de anios es CONCACAF con %d anios en total. \n", acumuladorConcaf);
						}
						else
						{
							printf("\nLa confederacion con mayor cantidad de anios es OFC con %d anios en total. \n", acumuladorOfc);
						}
					}
				}
			}
		}

	}
}

void InformePorcentajeJugadoresPorConfederacion(eJugador listaJugadores[], int sizeJugadores)
{
	float contadorJugadores=0;
	float contadorConmebol=0;
	float contadorUefa=0;
	float contadorAfc=0;
	float contadorCaf=0;
	float contadorConcaf=0;
	float contadorOfc=0;

	float porcentajeConmebol;
	float porcentajeUefa;
	float porcentajeAfc;
	float porcentajeCaf;
	float porcentajeConcaf;
	float porcentajeOfc;

	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		for(int i=0; i<sizeJugadores; i++)
		{
			if(listaJugadores[i].isEmpty==0)
			{
				switch(listaJugadores[i].idConfederacion)
				{
				case 100:
					contadorConmebol++;
					break;
				case 101:
					contadorUefa++;
					break;
				case 102:
					contadorAfc++;
					break;
				case 103:
					contadorCaf++;
					break;
				case 104:
					contadorConcaf++;
					break;
				case 105:
					contadorOfc++;
					break;
				}
				contadorJugadores++;
			}

		}

		porcentajeConmebol=(contadorConmebol/contadorJugadores)*100;
		porcentajeUefa=(contadorUefa/contadorJugadores)*100;
		porcentajeAfc=(contadorAfc/contadorJugadores)*100;
		porcentajeCaf=(contadorCaf/contadorJugadores)*100;
		porcentajeConcaf=(contadorConcaf/contadorJugadores)*100;
		porcentajeOfc=(contadorOfc/contadorJugadores)*100;

		printf("\n+++LISTA PROMEDIOS DE CONFEDERACIONES+++\n");
		printf("|  CONFEDERACION  |  PORCENTAJE  |\n");
		printf("|================================|\n");
		printf("|   CONMEBOL           %.2f      |\n", porcentajeConmebol);
		printf("|   UEFA               %.2f      |\n", porcentajeUefa);
		printf("|   AFC                %.2f      |\n", porcentajeAfc);
		printf("|   CAF                %.2f      |\n", porcentajeCaf);
		printf("|   CONCACAF           %.2f      |\n", porcentajeConcaf);
		printf("|   OFC                %.2f      |\n", porcentajeOfc);

	}


}

void InformarRegionMasJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{

	int sizeConf=sizeConfederaciones;
	int listaContadores[sizeConf];
	int RegionMasJugadores;

	if(listaJugadores!=NULL && sizeJugadores>0 && listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		printf("\nRegion mas jugadores:\n");

		for(int i=0; i<sizeConfederaciones;i++)
		{
			listaContadores[i]=0;
			for(int j=0; j<sizeJugadores; j++)
			{
				if(listaJugadores[j].isEmpty==0 && listaConfederaciones[i].id==listaJugadores[j].idConfederacion)
				{
					listaContadores[i]++;
				}
			}
		}

		for(int i=0; i<sizeConfederaciones; i++)
		{
			if(i==0 || listaContadores[i]>RegionMasJugadores)
			{
				RegionMasJugadores=listaContadores[i];
			}
		}

		for(int i=0; i<sizeConfederaciones; i++)
		{
			if(listaContadores[i]==RegionMasJugadores && listaContadores[i]>0)
			{

				printf("===== %s =====\n", listaConfederaciones[i].region);
				printf("Nombres de los jugadores: \n");
				for(int j=0; j<sizeJugadores; j++)
				{
					if(listaJugadores[j].isEmpty==0 && listaConfederaciones[i].id==listaJugadores[j].idConfederacion)
					{
						printf("\n> %s \n", listaJugadores[j].nombre);
					}
				}
			}
		}

	}

}














#endif /* INFORMES_C_ */
