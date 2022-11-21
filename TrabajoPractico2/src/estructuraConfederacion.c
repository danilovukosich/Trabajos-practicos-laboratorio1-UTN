/*
 * estructuraConfederacion.c
 *
 *  Created on: 26 oct. 2022
 *      Author: danil
 */

#ifndef ESTRUCTURACONFEDERACION_C_
#define ESTRUCTURACONFEDERACION_C_
#include "estructuraConfederacion.h"

int HardcodearConfederaciones(int* idSiguiente, eConfederacion listaConfederaciones[], int size)
{

    int retorno = 0;
    //
    eConfederacion auxConfederacion[10] ={{100, "CONMEBOL", "SUDAMERICA", 1916, 0},
										{101, "UEFA", "EUROPA", 1954, 0},
										{102, "AFC", "ASIA", 1954, 0},
										{103, "CAF", "AFRICA", 1957, 0},
										{104, "CONCAF", "NORTE Y CENTRO AMERICA", 1961, 0},
										{105, "OFC", "OCEANIA", 1966, 0}};

    if(listaConfederaciones != NULL && size > 0)
    {

        for(int i = 0 ; i < size ; i++)
        {
        	listaConfederaciones[i] = auxConfederacion[i];
        	*idSiguiente=*idSiguiente + 1;
        }
        retorno = 1;
    }
    return retorno;
}

void MostrarConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	if(listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		printf("------------------------CONFEDERACIONES------------------------\n");
		printf("|  ID  |  NOMBRE  |          REGION         |  ANIO CREACION  |\n");

		for(int i=0; i<sizeConfederaciones; i++)
		{
			printf("%d    %10s %25s       %4d\n", listaConfederaciones[i].id,
										  listaConfederaciones[i].nombre,
										  listaConfederaciones[i].region,
										  listaConfederaciones[i].anioCreacion);
		}
	}


}

int CargarNombreConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones, int idConfederacion, char nombreConfederacion[])
{
	int retorno=-1;
	if(listaConfederaciones!=NULL && sizeConfederaciones>0 && nombreConfederacion!=NULL)
	{
		for(int i=0;i<sizeConfederaciones;i++)
		{
			if(listaConfederaciones[i].id==idConfederacion)
			{
				strcpy(nombreConfederacion,listaConfederaciones[i].nombre);
				break;

			}
		}
		retorno=1;
	}
	return retorno;
}

int InicializarConfederaciones(eConfederacion listaConfederaciones[],int size)
{
	int retorno=0;
	if(listaConfederaciones !=NULL && size>0)
	{
		for(int i=0;i<size;i++)
		{
			listaConfederaciones[i].isEmpty=1;
		}
		retorno=1;
	}
	return retorno;
}

int BuscarLibreConfederacion(eConfederacion listaConfederaciones[],int size)
{
	int indice=-1;

	if(listaConfederaciones !=NULL && size>0)
	{
		for(int i=0;i<size;i++)
		{
			if(listaConfederaciones[i].isEmpty==1)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}

int CargarConfederacion(eConfederacion Confederacion[])
{
	int retorno=-1;
	char nombreAux[50];
	char regionAux[50];


	if(Confederacion!=NULL)
	{
		Utn_GetNombre(nombreAux, 50,"Ingrese Nombre de Confederacion: \n", "Ingrese un nombre VALIDO:\n", 50);
		strcpy(Confederacion->nombre, nombreAux);

		Utn_GetNombre(nombreAux, 50, "Ingrese Region: \n", "Ingrese una Region VALIDA:\n", 50);
		strcpy(Confederacion->region, regionAux);

		Utn_GetInt(&Confederacion->anioCreacion, "\n>Ingrese anio de creacion: \n",  "ERROR ingrese anio de creacion VALIDO! \n", 1700, 2022, 100);

		Confederacion->isEmpty=0;

		retorno=1;

	}

	return retorno;
}



int CargarListaConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones, int* idConfederacion)
{
	int retorno=-1;
	int indice;
	eConfederacion auxConfederacion;

	if(listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		printf("-------Alta Confedraciones------\n\n");
		indice=BuscarLibreConfederacion(listaConfederaciones, sizeConfederaciones);

		if(indice==-1)
		{
			printf("No hay lugar...\n");
		}
		else
		{
			CargarConfederacion(&auxConfederacion);
			auxConfederacion.id= *idConfederacion;
			(*idConfederacion)++;

			listaConfederaciones[indice]=auxConfederacion;

			retorno=1;
		}
	}

	return retorno;

}

void MostrarConfederacion(eConfederacion listaConfederaciones)
{


	printf("  %4d  %25s        %15s         %d\n", listaConfederaciones.id,
													listaConfederaciones.nombre,
													listaConfederaciones.region,
													listaConfederaciones.anioCreacion);
}

void MostrarLitaConfederaciones(eConfederacion listaConfederaciones[],int sizeConfederaciones)
{
	printf("|===================LISTA CONFEDERADCIONES=========================|\n");
	printf("|  ID    |        NOMBRE           |    REGION    | ANIO DE CRACION|\n");
	printf("|==================================================================|\n");
	if(listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		for(int i=0; i<sizeConfederaciones; i++)
		{
			if(listaConfederaciones[i].isEmpty==0)
			{
				MostrarConfederacion(listaConfederaciones[i]);
			}
		}
	}
}

int VerificarIdConfederacion(eConfederacion listaConfederaciones[],int sizeConfederaciones, int id)
{
	int indice= -1;

	if(listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		for(int i=0; i<sizeConfederaciones; i++)
		{
			if(listaConfederaciones[i].isEmpty==0 && listaConfederaciones[i].id==id)
			{
				indice=i;
				break;
			}
		}

	}

	return indice;
}

int BajaConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int id;
	int indice;
	int respuesta;
	int retorno=-1;

	if(listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		printf("============BAJA CONFEDERACION============\n");
		MostrarLitaConfederaciones(listaConfederaciones, sizeConfederaciones);
		fflush(stdin);
		Utn_GetInt(&id, "Ingrese un ID: \n",  "Ingrese un ID valido: \n", 1, 3000, 15);


		indice=VerificarIdConfederacion(listaConfederaciones, sizeConfederaciones, id);

		if(indice==-1)
		{
			printf("NO hay Confederacion con ese ID...\n");
		}
		else
		{
			Utn_GetInt(&respuesta, ">Confimar baja:\n1)SI\n2)NO\n", "ERROR\n>Confimar baja:\n1)SI\n2)NO\n", 1, 2, 15);
			if(respuesta==1)
			{
				listaConfederaciones[indice].isEmpty=1;
				printf("\nBAJA EXITOSA...\n");
				retorno = 1;
			}
			else
			{
				printf("\nBAJA CANCELADA...\n");
			}
		}

	}

	return retorno;

}

int ModificacionConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int retorno=-1;
	int respuesta;
	int id;
	int indice;
	char nombreAux[50];
	char regionAux[50];


	if(listaConfederaciones!=NULL && sizeConfederaciones>0)

	{
		MostrarLitaConfederaciones(listaConfederaciones, sizeConfederaciones);
		Utn_GetInt(&id, "Ingrese un ID: \n",  "Ingrese un ID valido: \n", 1, 3000, 15);
		indice=VerificarIdConfederacion(listaConfederaciones, sizeConfederaciones, id);

		if(indice==-1)
		{
			printf("NO hay confederacion con ese ID...\n");
		}
		else
		{
			do
			{
				MenuModificacionConfederacion();
				fflush(stdin);
				Utn_GetInt(&respuesta, ">Ingrese una opcion: \n", "ERROR ingrese opcion VALIDA", 1, 4, 1000);

				switch(respuesta)
				{
				case 1:
					Utn_GetNombre(nombreAux, 50, "Ingrese Nombre de Confederacion: \n", "Ingrese un nombre VALIDO:\n", 50);
					strcpy(listaConfederaciones[indice].nombre, nombreAux);
					break;

				case 2:
					Utn_GetNombre(regionAux, 50, "Ingrese Nombre de Confederacion: \n", "Ingrese un nombre VALIDO:\n", 50);
					strcpy(listaConfederaciones[indice].region, regionAux);
					break;

				case 3:
					Utn_GetInt(&listaConfederaciones[indice].anioCreacion, "\n>Ingrese anio de creacion: \n",  "ERROR ingrese anio de creacion VALIDO! \n", 1700, 2022, 100);
					break;

				case 4:
					printf("Volvio al menu Principal...\n");
					break;

				}

			}while(respuesta!=4);
			retorno=1;
		}

	}


	return retorno;
}


#endif /* ESTRUCTURACONFEDERACION_C_ */
