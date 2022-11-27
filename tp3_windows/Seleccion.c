#include "Seleccion.h"

Seleccion* selec_new()
{
	return(malloc(sizeof(Seleccion)));
}


Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* seleccionAux;

	seleccionAux=selec_new();

	if(idStr!=NULL && paisStr!=NULL && confederacionStr!=NULL && convocadosStr!=NULL)
	{

		selec_setId(seleccionAux, atoi(idStr));
		selec_setPais(seleccionAux, paisStr);
		selec_setConfederacion(seleccionAux, confederacionStr);
		selec_setConvocados(seleccionAux, atoi(convocadosStr));

	}
	else
	{
		printf("\nError select_newParam\n");

	}

	return seleccionAux;

}



void selec_delete(Seleccion* this)
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
int selec_getId(Seleccion* this,int* id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int selec_setId(Seleccion* this, int id)
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
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(pais, this->pais);
		retorno=1;
	}
	return retorno;
}

int selec_setPais(Seleccion* this, char* pais)
{
	int retorno=-1;
	if(this!=NULL && pais!=NULL)
	{
		strcpy(this->pais, pais);
		retorno=1;
	}

	return retorno;
}
//-------------------------------------------------------------------------------//
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;

		if(this!=NULL)
		{
			strcpy(confederacion, this->confederacion);
			retorno=1;
		}
		return retorno;
}

int selec_setConfederacion(Seleccion* this, char* confederacion)
{
	int retorno=-1;
	if(this!=NULL && confederacion!=NULL)
	{
		strcpy(this->confederacion, confederacion);
		retorno=1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------//
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->convocados=convocados;
		retorno=1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------//
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*convocados=this->convocados;
		retorno=1;
	}

	return retorno;
}

int selec_MostrarSeleccion(Seleccion* seleccionAux)
{
	int retorno=-1;

	int idAux;
	char paisAux[30];
	char confederacionAux[30];
	int convocadosAux;

	if(seleccionAux!=NULL)
	{
		selec_getId(seleccionAux, &idAux);
		selec_getPais(seleccionAux, paisAux);
		selec_getConfederacion(seleccionAux, confederacionAux);
		selec_getConvocados(seleccionAux, &convocadosAux);


		printf("  %2d    %20s     %10s                %3d\n",idAux, paisAux, confederacionAux, convocadosAux);
		retorno=1;
	}



	return retorno;
}

int selec_MostrarPaisDeNacionalidad(Seleccion* seleccionAux)
{
	int retorno=-1;

	int idAux;
	char paisAux[30];


	if(seleccionAux!=NULL)
	{
		selec_getId(seleccionAux, &idAux);
		selec_getPais(seleccionAux, paisAux);



		printf("   %d      %15s\n",idAux, paisAux);
		retorno=1;
	}



	return retorno;
}


int BuscarIdSeleccion(LinkedList* listaSeleccion, int id)
{
	int indice=-1;
	int size;
	int idSeleccion;

	Seleccion* seleccionAux=NULL;

	if(listaSeleccion!=NULL)
	{
		size=ll_len(listaSeleccion);

		for(int i=0; i<size; i++)
		{
			seleccionAux=ll_get(listaSeleccion,i);
			selec_getId(seleccionAux, &idSeleccion);

			if(idSeleccion == id)
			{
				indice=ll_indexOf(listaSeleccion, seleccionAux);//retorna el indice del jugador con el id que le paso
			}
		}
	}
//	else
//	{
//		printf("\n ERROR en buscar por id de seleccion\n");
//	}


	return indice;
}

//pido la confedracion
int GetConfederacionSeleccionada(int confederacionInt, char* confederacion)
{
	int retorno=-1;

	if(confederacion!=NULL)
	{
		switch(confederacionInt)
		{
		case 1:
			strcpy(confederacion,"AFC");
			break;

		case 2:
			strcpy(confederacion,"CAF");
			break;

		case 3:
			strcpy(confederacion,"CONCACAF");
			break;

		case 4:
			strcpy(confederacion,"CONMEBOL");
			break;

		case 5:
			strcpy(confederacion,"UEFA");
			break;
		}
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











