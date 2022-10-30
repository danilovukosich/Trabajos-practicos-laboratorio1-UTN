/*
 * inputs.c
 *
 *  Created on: 26 oct. 2022
 *      Author: danil
 */

#ifndef INPUTS_C_
#define INPUTS_C_
#include "inputs.h"


int Utn_GetString(char string[], char mensaje[], char mensajeError[], int size)
{
	int retorno=0;
	char cadena[size];
	int x;

	if(string!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{

		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);
		x=strlen(cadena);
		strcpy(string,cadena);

		while(x>size)
		{

			printf("%s", mensajeError);
			fflush(stdin);
			gets(cadena);
			x=strlen(cadena);
			strcpy(string,cadena);
		}

		retorno=1;
	}

	return retorno;

}


int Utn_GetInt ( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(GetInt(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

int GetInt ( int * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (MyGets(buffer, sizeof (buffer))==0 && esNumericaInt(buffer) == 1)
		{
			*pResultado = atoi (buffer);
			retorno = 1;
		}
	}
	return retorno;

}

/////////////////////////////////////////////////////////////////
///
///
///

int Utn_GetShortInt ( short int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	short int aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(GetShortInt(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

int GetShortInt ( short int * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (MyGets(buffer, sizeof (buffer))==0 && esNumericaInt(buffer) == 1)
		{
			*pResultado = atoi (buffer);
			retorno = 1;
		}
	}
	return retorno;

}



int esNumericaInt ( char * cadena)
{
	int retorno;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = -1;
				break ;
			}
			i++;
		}

	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

int MyGets ( char * cadena, int longitud)
{
	if (cadena != NULL && longitud >0 && fgets (cadena,longitud,stdin)==cadena)
	{
		fflush (stdin);
		if (cadena[ strlen (cadena)-1] == '\n' )
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}
		return 0;
	}
	return -1;
}


int Utn_GetFloat( float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	float aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(GetFloat(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

float GetFloat ( float * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (MyGets(buffer, sizeof (buffer))==0 && EsNumericaFloat(buffer) == 1)
		{
			*pResultado = atof (buffer);
			retorno = 1;
		}
	}
	return retorno;

}

float EsNumericaFloat ( char * cadena)
{
	int retorno;
	int i=0;
	int contador=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '.' || cadena[i] > '9' || cadena[i] == '/' || contador>1)
			{
				retorno = -1;
				break ;
			}
			if(cadena[i] == '.')
			{
				contador++;
			}
			i++;

		}

	}
	else
	{
		retorno = -1;
	}
	return retorno;
}






#endif /* INPUTS_C_ */
