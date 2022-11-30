#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(path!=NULL)
	{
		pArchivo=fopen(path,"r");

		if(pArchivo!=NULL)
		{
			parser_JugadorFromText(pArchivo, pArrayListJugador);
			printf("\n<Se cargaron exitosamente los jugadores>\n");
			retorno=1;
		}
		else
		{
			printf("\n<No se pudieron cargar los jugadores>\n");
		}

		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;

	FILE* pArchivo=NULL;

	if(pArrayListJugador!=NULL && path!=NULL)
	{
		pArchivo=fopen(path,"rb");

		if(pArchivo!=NULL)
		{
			parser_JugadorFromBinary(pArchivo, pArrayListJugador);
			printf("Se cargo correctamente!\n");
		}
		else
		{
			printf("Error en la carga de jugador a binario\n");
		}

		fclose(pArchivo);

		retorno=1;

	}

    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador, LinkedList* parraylistSeleccion)
{
	int retorno=-1;

	if(pArrayListJugador !=NULL)
	{
		AddNuevoJugador(pArrayListJugador, parraylistSeleccion);

		retorno=1;
	}
    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* listaSelecciones)
{
	int retorno=-1;
	int indice;
	int id;

	Jugador* jugadorAuxiliar=NULL;

	if(pArrayListJugador!=NULL)
	{
		controller_listarJugadores(pArrayListJugador);
		fflush(stdin);
		Utn_GetInt(&id, ">Ingrese id: \n", ">Ingrese un id valido\n", 1, 400, 15);
		indice=BuscarIdJugador(pArrayListJugador, id);
		retorno=0;//no encontro id
		if(indice!=-1)
		{
			jugadorAuxiliar=(Jugador*)ll_get(pArrayListJugador,indice);

			printf("|=========================================JUGADOR A MODIFICAR==========================================|\n");
			printf("|  ID    |        NOMBRE        |    EDAD    |    POSICION     |    NACIONALIDAD  |    ID SELECCION  |\n");
			jug_MostrarJugador(jugadorAuxiliar);
			ModificarJugador(jugadorAuxiliar, listaSelecciones);

			retorno=1;//se modifico
		}
		else
		{
			printf("ATENCION! No existe Jugador con ese ID...vuelva a intentar\n");
		}

	}

    return retorno;
}

/// @brief Funcion para convocar jugadores.
///
/// @param pArrayListJugador
/// @param listaSelecciones
/// @return int
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* listaSelecciones)
{
	int retorno=-1;
	int id;
	int indice;
	int idSeleccion;
	int indiceSeleccion;
	int cantConvocados;

	Jugador* jugadorAuxiliar=NULL;
	Seleccion* seleccionAuxiliar=NULL;

	//muestro los jugadorer y elijo por id
	controller_listarJugadores(pArrayListJugador);
	fflush(stdin);
	Utn_GetInt(&id, ">Ingrese id de jugador: \n", ">Ingrese un id valido\n", 1, 400, 15);
	indice=BuscarIdJugador(pArrayListJugador, id);

	if(indice!=-1)
	{
		//muestro las selecciones y la elijo por id
		controller_listarSelecciones(listaSelecciones);
		Utn_GetInt(&idSeleccion, ">Ingrese id de la seleccion: \n", ">Ingrese un id valido\n", 1, 400, 15);
		indiceSeleccion=BuscarIdSeleccion(listaSelecciones, idSeleccion);

		if(indiceSeleccion!=-1)
		{
			jugadorAuxiliar=(Jugador*)ll_get(pArrayListJugador,indice);
			seleccionAuxiliar=(Seleccion*)ll_get(listaSelecciones,indiceSeleccion);
			selec_getConvocados(seleccionAuxiliar, &cantConvocados);

			printf("|==========================================JUGADOR A CONVOCAR============================================|\n");
			printf("|  ID    |        NOMBRE        |    EDAD    |       POSICION      |   NACIONALIDAD   |  ID SELECCION  |\n");
			jug_MostrarJugador(jugadorAuxiliar);//printeo jugador elegido
			printf("\n|=======================================SELECCION ELEGIDA============================================|\n");
			selec_MostrarSeleccion(seleccionAuxiliar);//printeo seleccion elegida

			if(cantConvocados<22)
			{
				ConvocarJugador(jugadorAuxiliar, seleccionAuxiliar);
				retorno=1;//se concovo correctamente
			}
			else
			{
				printf("NO hay mas lugar en la seleccion!\n");
			}



		}
		else
		{
			printf("ATENCION! No existe Seleccion con ese ID...vuelva a intentar\n");
		}

	}
	else
	{
		printf("ATENCION! No existe Jugador con ese ID...vuelva a intentar\n");
	}

	return retorno;
}



/// @brief Lista jugadores que han sido convocados.
///
/// @param pArrayListJugador
/// @return int
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int size=ll_len(pArrayListJugador);

	Jugador* jugadorAux;

	if(pArrayListJugador!=NULL )
	{
		printf("\n|=================================LISTA JUGADORES CONVOCADOS=====================================|\n");
		printf("|  ID    |        NOMBRE        |    EDAD    |    POSICION     |  NACIONALIDAD  |  ID SELECCION  |\n");
		printf("|================================================================================================|\n");


		for(int i=0;i<size;i++)
		{
			jugadorAux = ll_get(pArrayListJugador, i);
			jug_MostrarJugadorConvocado(jugadorAux);

		}
		retorno = 0;
		//printf("JUGADORES CARGADOS : %d\n",size);
	}
//	else
//	{
//		printf("ERROR al mostrar");
//	}

	return retorno;
}

/// @brief Modificacion del jugador
///
/// @param pArrayListJugador
/// @param listaSelecciones
/// @return int
int controller_removerDeSeleccion(LinkedList* pArrayListJugador, LinkedList* listaSelecciones)
{

	int retorno=-1;
	int id;
	int indice;
	int idSeleccion;
	int indiceSeleccion;

	Jugador* jugadorAuxiliar=NULL;
	Seleccion* seleccionAuxiliar=NULL;

	//muestro los jugadorer y elijo por id
	controller_listarJugadoresConvocados(pArrayListJugador);
	fflush(stdin);
	Utn_GetInt(&id, ">Ingrese id de jugador: \n", ">Ingrese un id valido\n", 1, 400, 15);
	indice=BuscarIdJugador(pArrayListJugador, id);

	if(indice!=-1)
	{
		jugadorAuxiliar=(Jugador*)ll_get(pArrayListJugador,indice);
		idSeleccion=jugadorAuxiliar->idSeleccion;
		indiceSeleccion=BuscarIdSeleccion(listaSelecciones, idSeleccion);

		if(indiceSeleccion!=-1)
		{
			seleccionAuxiliar=(Seleccion*)ll_get(listaSelecciones,indiceSeleccion);

			printf("|==================================JUGADOR A QUITAR DE SELECCION===================================|\n");
			printf("|  ID    |        NOMBRE        |    EDAD    |    POSICION     |  NACIONALIDAD  |  ID SELECCION  |\n");
			jug_MostrarJugador(jugadorAuxiliar);//printeo jugador elegido
			printf("\n|====================================SELECCION DEL JUGADOR=======================================|\n");
			selec_MostrarSeleccion(seleccionAuxiliar);


			QuitarJugadorDeSeleccion(jugadorAuxiliar, seleccionAuxiliar);
			retorno=1;//se quito de la selleccion
		}


	}
	else
	{
		printf("ATENCION! No se encontro Jugador convocado con ese ID...Intentar con un ID existente...\n\n");
	}


	return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArraylistSeleccion)
{
	int retorno=-1;//error
	int indice;
	int indiceSeleccion;
	int id;
	int jugadorSeleccionId;
	int convocados;

	Jugador* jugadorAuxiliar;
	Seleccion* seleccionAuxiliar;

	if(pArrayListJugador!=NULL)
	{

		controller_listarJugadores(pArrayListJugador);
		fflush(stdin);
		Utn_GetInt(&id, ">Ingrese id: \n", ">Ingrese un id valido\n", 1, 400, 15);
		indice=BuscarIdJugador(pArrayListJugador, id);

		retorno=0;//no encontro id

		if(indice!=-1)
		{
			jugadorAuxiliar=(Jugador*)ll_get(pArrayListJugador,indice);
			jug_getSIdSeleccion(jugadorAuxiliar, &jugadorSeleccionId);
			indiceSeleccion=BuscarIdSeleccion(pArraylistSeleccion, jugadorSeleccionId);
			seleccionAuxiliar=(Seleccion*)ll_get(pArraylistSeleccion, indiceSeleccion);
			selec_getConvocados(seleccionAuxiliar, &convocados);


			if(jugadorSeleccionId!=0)
			{
				printf("Este jugador esta convocado!\n");

				QuitarJugadorDeSeleccion(jugadorAuxiliar, seleccionAuxiliar);
				ll_remove(pArrayListJugador, indice);
				jug_delete(jugadorAuxiliar);
				retorno=1;//se elimino
			}
			else
			{
				ll_remove(pArrayListJugador, indice);
				jug_delete(jugadorAuxiliar);
				retorno=1;//se elimino
			}

		}
	}


    return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int size=ll_len(pArrayListJugador);

	Jugador* jugadorAux;

	if(pArrayListJugador!=NULL)
	{
		printf("\n|==========================================LISTA JUGADORES============================================|\n");
		printf("|  ID    |        NOMBRE        |    EDAD    |      POSICION      |   NACIONALIDAD   |  ID SELECCION  |\n");
		printf("|=====================================================================================================|\n");


		for(int i=0;i<size;i++)
		{
			jugadorAux = ll_get(pArrayListJugador, i);
			jug_MostrarJugador(jugadorAux);
		}
		retorno = 0;
		//printf("JUGADORES CARGADOS : %d\n",size);
	}
	else
	{
		printf("ERROR al mostrar");
	}

	return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int opcion)
{
	int retorno=-1;
	int ordenamiento;

	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
			switch(opcion)
			{
			case 1://jugadores nacionalidad
				ordenamiento=AscendenteDescendente();
				ll_sort(pArrayListJugador, OrdenarJugadorNacionalidad, ordenamiento);
				break;
			case 2://slecciones por confederacion
				ordenamiento=AscendenteDescendente();
				ll_sort(pArrayListSeleccion, OrdenarSeleccionConfederacion, ordenamiento);
				break;
			case 3://jugadores por edad
				ordenamiento=AscendenteDescendente();
				ll_sort(pArrayListJugador, OrdenarJugadorEdad, ordenamiento);//no funca //arreglado
				break;
			case 4: //jugadores por nombre
				ordenamiento=AscendenteDescendente();
				ll_sort(pArrayListJugador, OrdenarJugadorNombre, ordenamiento);
				break;
			}

		retorno=1;
	}

	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;

	FILE* pArchivo;

	if(path!=NULL && pArrayListJugador!=NULL)
	{
		pArchivo=fopen(path,"w");
		if(pArchivo!=NULL)
		{
			parser_JugadorSaveAsText(pArchivo, pArrayListJugador);
			retorno=1;//se guardo exitosamente.
		}

	}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;

	FILE* pArchivo;

	if(path!=NULL && pArrayListJugador!=NULL)
	{


		pArchivo=fopen(path,"wb");

		if(pArchivo!=NULL)
		{
			parser_JugadorSaveAsBinary(pArchivo, pArrayListJugador);
			fclose(pArchivo);
		}
		retorno=1;
	}

    return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(path!=NULL)
	{
		pArchivo=fopen(path,"r");

		if(pArchivo!=NULL)
		{
			parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
			printf("\n<Se cargaron exitosamente las Selecciones>\n");
			retorno=1;
		}
		else
		{
			printf("\n<No se pudieron cargar las selecciones>\n");
		}

		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Modificar datos de seleccion (no la utilizo en este programa por eso esta comnetada)
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
//int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
//{
//	int retorno=-1;
//	int indice;
//	int id;
//
//	Seleccion* seleccionAux=NULL;
//
//	if(pArrayListSeleccion!=NULL)
//	{
//		controller_listarSelecciones(pArrayListSeleccion);
//		fflush(stdin);
//		Utn_GetInt(&id, ">Ingrese id: \n", ">Ingrese un id valido\n", 1, 400, 15);
//		indice=BuscarIdSeleccion(pArrayListSeleccion, id);
//		retorno=0;//no encontro id
//		if(indice!=-1)
//		{
//			seleccionAux=(Seleccion*)ll_get(pArrayListSeleccion,indice);
//
//			printf("|=======================SELECCION A MODIFICAR======================|\n");
//			printf("|  ID    |        PAIS        |    CONFEDERACION  |    CONVOCADOS  |\n");
//			selec_MostrarSeleccion(seleccionAux);
//			//ModificarSeleccion(seleccionAux);
//
//			retorno=1;//se modifico
//		}
//		else
//		{
//			printf("ATENCION! No existe Jugador con ese ID...vuelva a intentar\n");
//		}
//
//	return retorno;
//}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int size=ll_len(pArrayListSeleccion);

	Seleccion* seleccionAux;

	if(pArrayListSeleccion!=NULL)
	{
		printf("\n|========================LISTA SELECCIONES=============================|\n");
		printf("|  ID    |        PAIS        |    CONFEDERAION    |    CONVOCADOS     |\n");
		printf("|======================================================================|\n");
		//printf("size: %d\n",size);

		for(int i=0;i<size;i++)
		{
			seleccionAux = ll_get(pArrayListSeleccion, i);
			selec_MostrarSeleccion(seleccionAux);
		}
		retorno = 0;

	}
	else
	{
		printf("ERROR al mostrar");
	}

    return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	if(pArrayListSeleccion!=NULL)
	{

		ll_sort(pArrayListSeleccion, OrdenarSeleccionConfederacion, 1);

		retorno=1;
	}

	return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	FILE* pArchivo;

	if(path!=NULL && pArrayListSeleccion!=NULL)
	{

		pArchivo=fopen(path,"w");
		if(pArchivo!=NULL)
		{
			parser_SeleccionSaveAsText(pArchivo, pArrayListSeleccion);
			retorno=1;//se guardo exitosamente.
		}

	}
	return retorno;
}

/// @brief Listar nacionalidades
///
/// @param pArrayListSeleccion
/// @return int
int controller_listarNacionalidades(LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int size=ll_len(pArrayListSeleccion);

	Seleccion* seleccionAux;

	if(pArrayListSeleccion!=NULL)
	{
		printf("\n|====LISTA NACIONALIDADES====|\n");
		printf("|  ID    |        PAIS       |\n");
		printf("|============================|\n");
		//printf("size: %d\n",size);

		for(int i=0;i<size;i++)
		{
			seleccionAux = ll_get(pArrayListSeleccion, i);
			selec_MostrarPaisDeNacionalidad(seleccionAux);
		}
		retorno = 0;

	}
	else
	{
		printf("ERROR al mostrar");
	}

    return retorno;
}

/// @brief Filtra jugadores de la linked list de jugadores por una confedracion seleccionada por
/// 		el usuario y los agrega en otra lista.
///
/// @param pListaJugadoresConf
/// @param pListaJugadores
/// @param pListaSelecciones
/// @param confederacion
/// @return int
int controller_ListaPorConfederacion(LinkedList* pListaJugadoresConf, LinkedList* pListaJugadores, LinkedList* pListaSelecciones, char* confederacion)
{
	int retorno=-1;
	int sizeJugador;
	int sizeSeleccion;

	int idSeleccionJugadorAux;
	int idSeleccionAux;
	char confederacionSeleccionAux[50];

	Jugador* jugadorAux=NULL;
	Seleccion* seleccionAux=NULL;

	if(pListaJugadores!=NULL && pListaSelecciones!=NULL && confederacion!=NULL)
	{
		sizeJugador=ll_len(pListaJugadores);
		sizeSeleccion=ll_len(pListaSelecciones);

		for(int i=0; i<sizeJugador; i++)
		{
			jugadorAux=ll_get(pListaJugadores, i);
			jug_getSIdSeleccion(jugadorAux, &idSeleccionJugadorAux);
			//printf("jugador id seleccion: %d \n", idSeleccionJugadorAux);

			for(int j=0; j<sizeSeleccion; j++)
			{
				seleccionAux=ll_get(pListaSelecciones, j);
				selec_getConfederacion(seleccionAux, confederacionSeleccionAux);
				selec_getId(seleccionAux, &idSeleccionAux);
				//printf("seleccion id: %d \n", idSeleccionAux);
				//printf("seleccion confederacion: %s \n", confederacionSeleccionAux);

				//usar getters
				if(idSeleccionJugadorAux>0 && strcmp(confederacionSeleccionAux, confederacion)==0 && idSeleccionJugadorAux==idSeleccionAux)
				{
					ll_add(pListaJugadoresConf, jugadorAux);
					//printf("%s\n", confederacion);
					//printf("%s\n", confederacionSeleccionAux);
					retorno=1;
				}
//				else
//				{
//					printf("ERROR en crear la lista!!\n");
//					printf("%s\n", confederacion);
//				}
			}
		}

		//retorno=1;

	}

	return retorno;
}

int controller_LiberarLista(LinkedList* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		ll_deleteLinkedList(this);
		retorno=1;
	}
	return retorno;
}



