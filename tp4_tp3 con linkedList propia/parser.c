#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=-1;

		Jugador* jugadorAux=NULL;

		char idAux[10];
		char nombreCompletoAux[100];
		char edadAux[10];
		char posicionAux[50];
		char nacionalidadAux[50];
		char idSelecAux[10];

		if(pFile!=NULL && pArrayListJugador!=NULL)
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,idSelecAux);//lectura fantasma

			while(!feof(pFile))
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,idSelecAux);

				jugadorAux=jug_newParametros(idAux, nombreCompletoAux, edadAux, posicionAux, nacionalidadAux, idSelecAux);

				if(jugadorAux!=NULL)
				{
					ll_add(pArrayListJugador, jugadorAux);
				}
			}
			retorno=1;
		}

		return retorno;
}


/// @brief Se encarga de escribir los datos de la lista de jugadores en jugadores.csv (modo texto).
///
/// @param pFile
/// @param pArrayListJugador
/// @return int
int parser_JugadorSaveAsText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int size=ll_len(pArrayListJugador);

	Jugador* jugadorAux;
	int idAux;
	char nombreCompletoAux[100];
	int edadAux;
	char posicionAux[30];
	char nacionalidadAux[30];
	int idSeleccionAux;

	if(pFile!=NULL && pArrayListJugador!=NULL)
	{
		fprintf(pFile, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");

		for(int i=0;i<size;i++)
		{
			jugadorAux=(Jugador*)ll_get(pArrayListJugador, i);

			if(jugadorAux!=NULL)
			{
				jug_getId(jugadorAux, &idAux);
				jug_getNombreCompleto(jugadorAux, nombreCompletoAux);
				jug_getEdad(jugadorAux, &edadAux);
				jug_getPosicion(jugadorAux, posicionAux);
				jug_getNacionalidad(jugadorAux, nacionalidadAux);
				jug_getSIdSeleccion(jugadorAux, &idSeleccionAux);

				fprintf(pFile, "%d,%s,%d,%s,%s,%d\n",idAux, nombreCompletoAux, edadAux, posicionAux, nacionalidadAux, idSeleccionAux);
				retorno=1;
			}
		}
	}



    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    int retorno=-1;
    int cantidad;
    Jugador* jugadorAux;

    if(pFile!=NULL && pArrayListJugador!=NULL)
    {

    	do
    	{
    		jugadorAux=jug_new();
    		cantidad=fread(jugadorAux,sizeof(Jugador),1,pFile);
    		//solucionpara que nome printee un jugador de mas.
    		if(cantidad<1)
    		{
    			break;
    		}

    		if(jugadorAux!=NULL && fread(jugadorAux,sizeof(Jugador),1,pFile)==1)
    		{
    			ll_add(pArrayListJugador, jugadorAux);
    		}

    	}while(!feof(pFile));
    }

    return retorno;
}

/// @brief Se encarga de escribir los datos de la lista de jugadores en jugadores.csv (modo binario).
///
/// @param pFile
/// @param pArrayListJugador
/// @return int
int parser_JugadorSaveAsBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int size=ll_len(pArrayListJugador);
	int sizeJugador=sizeof(Jugador);

	Jugador* jugadorAux;

	if(pFile!=NULL && pArrayListJugador!=NULL)
	{
		for(int i=0; i<size; i++)
		{
			jugadorAux=(Jugador*)ll_get(pArrayListJugador,i);

			if(jugadorAux!=NULL)
			{
				fwrite(jugadorAux, sizeJugador,1,pFile);
			}
		}
	}

	return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	Seleccion* seleccionAux=NULL;

	char idAux[10];
	char paisAux[30];
	char confederacionAux[30];
	char convocadosAux[10];

	if(pFile!=NULL && pArrayListSeleccion!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",idAux,paisAux,confederacionAux,convocadosAux);//lectura fantasma

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",idAux,paisAux,confederacionAux,convocadosAux);

			seleccionAux=selec_newParametros(idAux, paisAux, confederacionAux, convocadosAux);

			if(seleccionAux!=NULL)
			{
				ll_add(pArrayListSeleccion, seleccionAux);
			}
		}
		retorno=1;
	}

	return retorno;
}

/// @brief Se encarga de escribir los datos de la lista de selecciones en selecciones.csv (modo texto).
///
/// @param pFile
/// @param pArrayListSeleccion
/// @return int
int parser_SeleccionSaveAsText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int size=ll_len(pArrayListSeleccion);

	Seleccion* seleccionAux;
	int idAux;
	char paisAux[30];
	char confederacionAux[30];
	int convocadosAux;

	if(pFile!=NULL && pArrayListSeleccion!=NULL)
	{
		fprintf(pFile, "id,pais,confederacion,convocados\n");

		for(int i=0;i<size;i++)
		{
			seleccionAux=(Seleccion*)ll_get(pArrayListSeleccion, i);

			if(seleccionAux!=NULL)
			{

				selec_getId(seleccionAux, &idAux);
				selec_getPais(seleccionAux, paisAux);
				selec_getConfederacion(seleccionAux, confederacionAux);
				selec_getConvocados(seleccionAux, &convocadosAux);

				fprintf(pFile, "%d,%s,%s,%d\n",idAux, paisAux, confederacionAux,convocadosAux);
				retorno=1;
			}
		}
	}



	return retorno;
}

