#include "jugador.h"

Jugador* jug_new()
{
	return malloc(sizeof(Jugador));
}

//====================================================================================================//
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador;

	unJugador= jug_new();

	if(idStr!=NULL && nombreCompletoStr!=NULL && edadStr!=NULL && posicionStr!=NULL && nacionalidadStr!=NULL && idSelccionStr!=NULL)
	{
		jug_setId(unJugador, atoi(idStr));
		jug_setNombreCompleto(unJugador, nombreCompletoStr);
		jug_setEdad(unJugador, atoi(edadStr));
		jug_setPosicion(unJugador, posicionStr);
		jug_setNacionalidad(unJugador, nacionalidadStr);
		jug_setIdSeleccion(unJugador, atoi(idSelccionStr));
	}
	else
	{
		printf("\nError de jug_newParametros\n");
	}


	return unJugador;
}

//====================================================================================================//

void jug_delete(Jugador* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

//====================================================================================================//
//                                           SETTERS Y GETTERS                                        //
//====================================================================================================//
//====================================================================================================//
int jug_setId(Jugador* this,int id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->id = id;
		retorno=1;
	}

	return retorno;
}
//-------------------------------------------------------------------------------//
int jug_getId(Jugador* this,int* id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*id=this->id;
		retorno=1;
	}

	return retorno;
}
//-------------------------------------------------------------------------------//
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this!=NULL && nombreCompleto!=NULL)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno=1;
	}

	return retorno;
}
//-------------------------------------------------------------------------------//
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this!=NULL && nombreCompleto!=NULL)
	{
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno=1;
	}

	return retorno;
}
//terminar getters y setters e implementarlos en el jugador_newParam().
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;
	if(this!=NULL && posicion!=NULL)
	{
		strcpy(this->posicion, posicion);
		retorno=1;
	}

	return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;
	if(this!=NULL && posicion!=NULL)
	{
		strcpy(posicion, this->posicion);
		retorno=1;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL && nacionalidad!=NULL)
	{
		strcpy(this->nacionalidad, nacionalidad);
		retorno=1;
	}

	return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL && nacionalidad!=NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);
		retorno=1;
	}

	return retorno;
}

int jug_setEdad(Jugador* this, int edad)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->edad=edad;
		retorno=1;
	}

	return retorno;
}
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*edad=this->edad;
		retorno=1;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->idSeleccion=idSeleccion;
		retorno=1;
	}

	return retorno;
}
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*idSeleccion=this->idSeleccion;
		retorno=1;
	}

	return retorno;
}

int jug_MostrarJugador(Jugador* jugadorAux)
{
	int retorno=-1;

	int idAux;
	char nombreCompletoAux[100];
	int edadAux;
	char posicionAux[50];
	char nacionalidadAux[50];
	int idSelecAux;

	if(jugadorAux!=NULL)
	{
		jug_getId(jugadorAux, &idAux);
		jug_getNombreCompleto(jugadorAux, nombreCompletoAux);
		jug_getEdad(jugadorAux, &edadAux);
		jug_getPosicion(jugadorAux, posicionAux);
		jug_getNacionalidad(jugadorAux, nacionalidadAux);
		jug_getSIdSeleccion(jugadorAux, &idSelecAux);

		printf("%d %25s %d %15s %15s %d\n",idAux, nombreCompletoAux, edadAux, posicionAux,nacionalidadAux,idSelecAux);

		retorno=1;
	}



	return retorno;
}

int AddNuevoJugador(LinkedList* this, LinkedList* listaSelecciones)
{
	int retorno=-1;

	char idAux[10];
	char nombreCompletoAux[100];
	char edadAux[10];
	char posicionAux[50];
	char nacionalidadAux[50];
	char idSeleccionAux[10];//es igual a 0 hasta quse convoque y ahi se modifica a 1==true.

	int NacionalidadAuxInt;
	int PosicionAuxInt;//se complementa con la funcion de JugadorPosicion
	int edadAuxInt;
	int idSeleccionAuxInt;



	int retornoNombre;
	int retornoEdad;
	int retornoPosicion;
	int retornoNacionalidad;

	Jugador* jugadorAux = NULL;

	//nombre
	retornoNombre=Utn_GetNombre(nombreCompletoAux, 100, ">Ingrese el nombre del Jugador:\n", ">Ingrese un nombre VALIDO:\n", 15);
	//edad
	retornoEdad=Utn_GetInt(&edadAuxInt, ">Ingrese edad:\n", ">Ingrese edad VALIDA:\n", 17, 45, 15);
	//posicion
	ElegirPosicion();//muestra las posiciones a elegir.
	retornoPosicion=Utn_GetInt(&PosicionAuxInt, ">Ingrese posicion: \n", ">Ingrese posicion VALIDA: \n", 1, 11, 15);
	//nacionalidad
	controller_listarNacionalidades(listaSelecciones);//muestra los paises a elegir
	retornoNacionalidad=Utn_GetInt(&NacionalidadAuxInt, "Ingrese ID del pais de nacionalidad:\n", "Ingrese ID de nacionalidad VALIDO:\n", 1, 30, 15);
	//id seleccion
	idSeleccionAuxInt = 0;

	if(retornoNombre==1 && retornoEdad==1 && retornoPosicion==1 && retornoNacionalidad==1)
	{
		IdAutoincremental(idAux);
		sprintf(edadAux, "%d", edadAuxInt);//pasa entero a una cadena.
		JugadorNacionalidad(NacionalidadAuxInt, nacionalidadAux);
		JugadorPosicion(PosicionAuxInt, posicionAux);
		sprintf(idSeleccionAux,"%d",idSeleccionAuxInt);

		jugadorAux=jug_newParametros(idAux, nombreCompletoAux, edadAux, posicionAux, nacionalidadAux, idSeleccionAux);

		if(jugadorAux!=NULL)
		{
			ll_add(this, jugadorAux);
		}
		//y ll_add()
	}

	return retorno;

}

void IdAutoincremental(char* auxId)
{
	FILE* pIdIncremental = NULL;
	char idchar[20];
	int id;

	pIdIncremental = fopen("IdIncremental.txt","r");

	if(pIdIncremental != NULL)
	{
		fscanf(pIdIncremental,"%[^\n]",idchar);
		strcpy(auxId,idchar);
		id = atoi(idchar);
		id++;
		fclose(pIdIncremental);

		pIdIncremental = fopen("IdIncremental.txt","w");
		fprintf(pIdIncremental,"%d\n",id);
		fclose(pIdIncremental);
	}
}

int JugadorNacionalidad(int idNacionalidad, char* nacionalidad)
{
	int retorno=-1;

	if(nacionalidad!=NULL)
	{
		switch(idNacionalidad)
		{
		case 1:
			strcpy(nacionalidad,"Aleman");
			break;
		case 2:
			strcpy(nacionalidad,"Arabe");
			break;
		case 3:
			strcpy(nacionalidad,"Argentino");
			break;
		case 4:
			strcpy(nacionalidad,"Australiano");
			break;
		case 5:
			strcpy(nacionalidad,"Belga");
			break;
		case 6:
			strcpy(nacionalidad,"Brasilero");
			break;
		case 7:
			strcpy(nacionalidad,"Camerunes");
			break;
		case 8:
			strcpy(nacionalidad,"Canadiense");
			break;
		case 9:
			strcpy(nacionalidad,"Coreano");
			break;
		case 10:
			strcpy(nacionalidad,"Costa Riquense");
			break;
		case 11:
			strcpy(nacionalidad,"Croata");
			break;
		case 12:
			strcpy(nacionalidad,"Dinamarques");
			break;
		case 13:
			strcpy(nacionalidad,"Ecuatoriano");
			break;
		case 14:
			strcpy(nacionalidad,"Espanol");
			break;
		case 15:
			strcpy(nacionalidad,"Estado unidense");
			break;
		case 16:
			strcpy(nacionalidad,"Frances");
			break;
		case 17:
			strcpy(nacionalidad,"Gales");
			break;
		case 18:
			strcpy(nacionalidad,"Ghana");
			break;
		case 19:
			strcpy(nacionalidad,"Holandes");
			break;
		case 20:
			strcpy(nacionalidad,"Ingles");
			break;
		case 21:
			strcpy(nacionalidad,"Iranqui");
			break;
		case 22:
			strcpy(nacionalidad,"Japones");
			break;
		case 23:
			strcpy(nacionalidad,"Marroqui");
			break;
		case 24:
			strcpy(nacionalidad,"Mexicano");
			break;
		case 25:
			strcpy(nacionalidad,"Polonia");
			break;
		case 26:
			strcpy(nacionalidad,"Portugues");
			break;
		case 27:
			strcpy(nacionalidad,"Qatari");
			break;
		case 28:
			strcpy(nacionalidad,"Senegales");
			break;
		case 29:
			strcpy(nacionalidad,"Serbio");
			break;
		case 30:
			strcpy(nacionalidad,"Suizo");
			break;
		case 31:
			strcpy(nacionalidad,"Tunez");
			break;
		case 32:
			strcpy(nacionalidad,"Uruguayo");
			break;
			//fin del switch gracias a dios
		}

		retorno=1;
	}

	return retorno;
}

int JugadorPosicion(int idPosicion, char* posicion)
{
	int retorno=-1;

	if(posicion!=NULL)
	{
		switch(idPosicion)
		{
		case 1:
			strcpy(posicion, "Portero");
			break;
		case 2:
			strcpy(posicion, "Defensa central");
			break;
		case 3:
			strcpy(posicion, "Lateral izquierdo");
			break;
		case 4:
			strcpy(posicion, "Lateral derecho");
			break;
		case 5:
			strcpy(posicion, "Pivote");
			break;
		case 6:
			strcpy(posicion, "Mediocentro");
			break;
		case 7:
			strcpy(posicion, "Mediocentro ofensivo");
			break;
		case 8:
			strcpy(posicion, "Extremo izquierdo");
			break;
		case 9:
			strcpy(posicion, "Extremo derecho");
			break;
		case 10:
			strcpy(posicion, "Mediapunta");
			break;
		case 11:
			strcpy(posicion, "Delantero centro");
			break;

		}


		retorno=1;
	}

	return retorno;
}

int BuscarIdJugador(LinkedList* this, int id)
{
	int indice=-1;
	int size;

	Jugador* jugadorAux=NULL;

	if(this!=NULL)
	{
		size=ll_len(this);

		for(int i=0; i<size; i++)
		{
			jugadorAux=ll_get(this,i);

			if(jugadorAux->id == id)
			{
				indice=ll_indexOf(this, jugadorAux);//retorna el indice del jugador con el id que le paso
			}
		}

	}
//	else
//	{
//		printf("\n ERROR en buscar por id\n");
//	}


	return indice;
}

int ModificarJugador(Jugador* jugador, LinkedList* listaSelecciones)
{
	int retorno=-1;
	int opcion;
	char nombreCompletoAux[100];
	int edadAux;
	char posicionAux[50];
	int posicionInt;
	char nacionalidadAux[50];
	int nacionalidadAuxInt;


	if(jugador!=NULL)
	{

		do
		{
			MenuModificacionJugador();
			Utn_GetInt(&opcion, ">Ingrese una opcion: \n", ">Ingrese una opcion VALIDA: \n", 1, 7, 15);

			switch(opcion)
			{
			case 1:
				Utn_GetNombre(nombreCompletoAux, 100, ">Ingrese nombre: \n", ">Ingrese nombre valido: \n", 15);
				jug_setNombreCompleto(jugador, nombreCompletoAux);
				printf("Se modifico el NOMBRE del jugador!\n");
				break;

			case 2:
				Utn_GetInt(&edadAux, ">Ingrese una edad: \n", ">Ingrese una edad valida: \n", 17, 45, 15);
				jug_setEdad(jugador, edadAux);
				printf("Se modifico la EDAD del jugador!\n");
				break;

			case 3:
				ElegirPosicion();
				Utn_GetInt(&posicionInt, ">Ingrese posicion: \n", ">Ingrese posicion valida: \n", 1, 7, 15);
				JugadorPosicion(posicionInt, posicionAux);
				jug_setPosicion(jugador, posicionAux);
				printf("Se modifico la POSICION del jugador!\n");
				break;

			case 4:
				controller_listarNacionalidades(listaSelecciones);
				Utn_GetInt(&nacionalidadAuxInt, "Ingrese ID del pais de nacionalidad:\n", "Ingrese ID de nacionalidad VALIDO:\n", 1, 30, 15);
				JugadorNacionalidad(nacionalidadAuxInt, nacionalidadAux);
				jug_setNacionalidad(jugador, nacionalidadAux);
				printf("Se modifico la NACIONALIDAD del jugador!\n");
				break;

			case 5:
				printf("\nVolvio al menu principal...\n");
				break;

			}


		}while(opcion!=5);

	}


	return retorno;
}

int ConvocarJugador(Jugador* jugadorAux, Seleccion* seleccionAux)
{
	int retorno=-1;

	if(jugadorAux!=NULL && seleccionAux!=NULL)
	{
		jugadorAux->idSeleccion=seleccionAux->id;
		seleccionAux->convocados++;
		retorno=1;
	}



	return retorno;
}

int QuitarJugadorDeSeleccion(Jugador* jugadorAux, Seleccion* seleccionAux)
{
	int retorno=-1;

	if(jugadorAux!=NULL && seleccionAux!=NULL)
	{
		jugadorAux->idSeleccion=0;
		seleccionAux->convocados--;

		retorno=1;
	}


	return retorno;
}

int jug_MostrarJugadorConvocado(Jugador* jugadorAux)
{
	int retorno=-1;

	int idAux;
	char nombreCompletoAux[100];
	int edadAux;
	char posicionAux[50];
	char nacionalidadAux[50];
	int idSelecAux;

	if(jugadorAux!=NULL && jugadorAux->idSeleccion!=0)
	{
		jug_getId(jugadorAux, &idAux);
		jug_getNombreCompleto(jugadorAux, nombreCompletoAux);
		jug_getEdad(jugadorAux, &edadAux);
		jug_getPosicion(jugadorAux, posicionAux);
		jug_getNacionalidad(jugadorAux, nacionalidadAux);
		jug_getSIdSeleccion(jugadorAux, &idSelecAux);

		printf("%d %25s %d %15s %15s %d\n",idAux, nombreCompletoAux, edadAux, posicionAux,nacionalidadAux,idSelecAux);

		retorno=1;
	}



	return retorno;
}


int OrdenarJugadorNacionalidad(void* pJugador1, void* pJugador2)
{
	int retorno;
	char nacionalidadJugador1[50];
	char nacionalidadJugador2[50];

	Jugador* jugadorAux1=NULL;
	Jugador* jugadorAux2=NULL;

	if(pJugador1!=NULL && pJugador2!=NULL)
	{
		jugadorAux1=(Jugador*)pJugador1;
		jugadorAux2=(Jugador*)pJugador2;

		jug_getNacionalidad(jugadorAux1, nacionalidadJugador1);
		jug_getNacionalidad(jugadorAux2, nacionalidadJugador2);
		retorno=strcmp(nacionalidadJugador1,nacionalidadJugador2);
	}


	return retorno;
}

int OrdenarSeleccionConfederacion(void* pSeleccion1, void* pSeleccion2)
{
	int retorno;
	char confederacionSeleccion1[50];
	char confederacionSeleccion2[50];

	Seleccion* seleccionAux1=NULL;
	Seleccion* seleccionAux2=NULL;

	if(pSeleccion1!=NULL && pSeleccion2!=NULL)
	{
		seleccionAux1= (Seleccion*)pSeleccion1;
		seleccionAux2= (Seleccion*)pSeleccion2;

		selec_getConfederacion(seleccionAux1, confederacionSeleccion1);
		selec_getConfederacion(seleccionAux2, confederacionSeleccion2);
		retorno=strcmp(confederacionSeleccion1,confederacionSeleccion2);
	}


	return retorno;
}

int OrdenarJugadorEdad(void* pJugador1, void* pJugador2)
{
	int retorno=-1;
	int edadJugadorAux1;
	int edadJugadorAux2;

	Jugador* jugadorAux1=NULL;
	Jugador* jugadorAux2=NULL;

	if(pJugador1!=NULL && pJugador2!=NULL)
	{
		jugadorAux1=(Jugador*)pJugador1;
		jugadorAux2=(Jugador*)pJugador2;

		jug_getEdad(jugadorAux1, &edadJugadorAux1);
		jug_getEdad(jugadorAux2, &edadJugadorAux2);

		if(edadJugadorAux1>edadJugadorAux2)
		{
			retorno=1;
		}
		else
		{
			if(edadJugadorAux1==edadJugadorAux2)
			{
				retorno=0;
			}
		}
	}


	return retorno;

}

int OrdenarJugadorNombre(void* pJugador1, void* pJugador2)
{
	int retorno;
	char nombreJugador1[50];
	char nombreJugador2[50];

	Jugador* jugadorAux1=NULL;
	Jugador* jugadorAux2=NULL;

	if(pJugador1!=NULL && pJugador2!=NULL)
	{
		jugadorAux1=(Jugador*)pJugador1;
		jugadorAux2=(Jugador*)pJugador2;

		jug_getNombreCompleto(jugadorAux1, nombreJugador1);
		jug_getNombreCompleto(jugadorAux2, nombreJugador2);
		retorno=strcmp(nombreJugador1,nombreJugador2);
	}


	return retorno;
}

//int JugadorDeDeterminadaConfederacion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
//{
//	int retorno=-1;
//	int confederacion;
//
//	Jugador* jugadorAux=NULL;
//
//	ElegirConfederacion();
//	Utn_GetInt(&confederacion, ">Ingrese una confederacion: \n", "Ingrese una confederacion Valida!\n", 1, 5, 15);
//
//
//
//
//	return retorno;
//}
//int jug_setIsEmpty(Jugador* this,int isEmpty);
//int jug_getIsEmpty(Jugador* this,int* isEmpty);






















