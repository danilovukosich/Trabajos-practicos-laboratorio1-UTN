/*
 * funciones.c
 *
 *  Created on: 12 sep. 2022
 *      Author: danil
 */

#ifndef FUNCIONES_C_
#define FUNCIONES_C_

#include "funciones.h"







int Utn_GetInt(int* numero, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int NumEntero;
	int retorno;

	if(numero != NULL && minimo<=maximo)
	{
		printf("%s", mensaje);
		scanf("%d",&NumEntero);
		while(NumEntero<minimo || NumEntero>maximo)
		{
			printf("%s", mensajeError);
			scanf("%d",&NumEntero);
		}

		*numero=NumEntero;
		retorno=1;
	}
	else
	{
		retorno=-1;
	}

	return retorno;
}

int Utn_GetFloat(float* numero, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	float NumEntero;
	int retorno;
	if(numero != NULL && minimo<=maximo)
	{
		printf("%s", mensaje);
		scanf("%f",&NumEntero);
		while(NumEntero<minimo || NumEntero>maximo)
		{
			printf("%s", mensajeError);
			scanf("%f",&NumEntero);
		}

		*numero=NumEntero;
		retorno=1;
	}
	else
	{
		retorno=-1;
	}

	return retorno;
}

void ValidarRetorno(int retorno)
{
	if(retorno==1)
	{
		printf("Se ingreso correctamente.\n");
	}
	else
	{
		printf("ERROR.\n");
	}
}



int PedirJugador(int* numeroCamiseta, int* confederacion)
{
	int retorno=0;
	int camisetaJugador;
	int confederacionJugador;
	int rtnNum;


	if(numeroCamiseta!=NULL && confederacion!=NULL)
	{

		rtnNum=Utn_GetInt(&camisetaJugador, "\nIngrese numero de camisieta del 1 al 99: ", "Ingrese una camiseta valida: ", 1, 99);
		ValidarRetorno(rtnNum);
		*numeroCamiseta=camisetaJugador;

		rtnNum=Utn_GetInt(&confederacionJugador, "\nIngrese Confederacion: \n"
											"1)Uefa\n"
											"2)Conmebol\n"
											"3)Concaf\n"
											"4)AFC\n"
											"5)OFC\n"
											"6)CAF\n",
											"Ingrese una Confederacion valida: \n"
											"1)Uefa\n"
											"2)Conmebol\n"
											"3)Concaf\n"
											"4)AFC\n"
											"5)OFC\n"
											"6)CAF\n", 1, 6);
		ValidarRetorno(rtnNum);
		*confederacion=confederacionJugador;



		retorno=1;

	}

	return retorno;
}

void ContarConfederaciones(int confederacion, int* uefa,int contadorUefa, int* conmebol,int contadorConmebol, int* concaf,int contadorConcaf, int* afc, int contadorAfc, int* ofc, int contadorOfc, int* caf, int contadorCaf)
{

	if(uefa!=NULL && conmebol!=NULL && concaf!=NULL && afc!=NULL && ofc!=NULL && caf!=NULL)
	{
		switch(confederacion)
		{
		case 1:
			contadorUefa++;
			*uefa=contadorUefa;
			break;
		case 2:
			contadorConmebol++;
			*conmebol=contadorConmebol;
				break;
		case 3:
			contadorConcaf++;
			*concaf=contadorConcaf;
				break;
		case 4:
			contadorAfc++;
			*afc=contadorAfc;
				break;
		case 5:
			contadorOfc++;
			*ofc=contadorOfc;
			break;
		case 6:
			contadorCaf++;
			*caf=contadorCaf;
			break;
		}
	}



}

int CalcularPromedioJugadores(int contadorJugadores, int contadorUefa, int contadorConmebol, int contadorConcaf, int contadorAfc, int contadorOfc, int contadorCaf,float* promedioUefa, float* promedioConmebol, float* promedioConcaf, float* promedioAfc, float* promedioOfc, float* promedioCaf)
{
	int retorno=0;
	float promUefa;
	float promConmebol;
	float promConcaf;
	float promAfc;
	float promOfc;
	float promCaf;


	if(promedioUefa!=NULL && promedioConmebol!=NULL && promedioConcaf!=NULL && promedioAfc!=NULL && promedioOfc!=NULL && promedioCaf!=NULL)
	{
		promUefa=((float)contadorUefa/contadorJugadores)*100;
		*promedioUefa=promUefa;

		promConmebol=((float)contadorConmebol/contadorJugadores)*100;
		*promedioConmebol=promConmebol;

		promConcaf=((float)contadorConcaf/contadorJugadores)*100;
		*promedioConcaf=promConcaf;

		promAfc=((float)contadorAfc/contadorJugadores)*100;
		*promedioAfc=promAfc;

		promOfc=((float)contadorOfc/contadorJugadores)*100;
		*promedioOfc=promOfc;

		promCaf=((float)contadorCaf/contadorJugadores)*100;
		*promedioCaf=promCaf;

		retorno=1;
	}

	return retorno;
}



float CalcularCostos(float costo1, float costo2, float costo3)
{

	float costoTotal;

	costoTotal=costo1+costo2+costo3;


	return costoTotal;
}

int CalcularCostoFinal(float costoTotal, float porcentajeUefa, float* aumento, float* costoFinal)
{
	int retorno=0;
	float costAumento;
	float costFinal;

	if(aumento!=NULL && costoFinal!=NULL)
	{
		if(porcentajeUefa>50)
		{
			costAumento=costoTotal*0.35;
			*aumento=costAumento;

			costFinal=costoTotal+costAumento;
			*costoFinal=costFinal;

		}
		retorno=1;
	}

	return retorno;
}




#endif /* FUNCIONES_C_ */







