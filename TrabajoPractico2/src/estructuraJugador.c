/*
 * estructuraJugador.c
 *
 *  Created on: 17 oct. 2022
 *      Author: danil
 */

#ifndef ESTRUCTURAJUGADOR_C_
#define ESTRUCTURAJUGADOR_C_

#include "estructuraJugador.h"

static int IdAutoIncremental(void)
{
	return idAutoIncremental++;
}

int InicializarJugadores(eJugador listaJugadores[],int size)
{
	int retorno=0;
	if(listaJugadores !=NULL && size>0)
	{
		for(int i=0;i<size;i++)
		{
			listaJugadores[i].isEmpty=1;
		}
		retorno=1;
	}
	return retorno;
}

int BuscarLibre(eJugador listaJugadores[],int size)
{
	int indice=-1;

	if(listaJugadores !=NULL && size>0)
	{
		for(int i=0;i<size;i++)
		{
			if(listaJugadores[i].isEmpty==1)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}

int HardcodearJugadores(eJugador listaJugadors[], int size, int cantidad)
{

    int retorno = 0;
    //
    eJugador auxJugador[] ={{1, "Danilo", "Delantero", 9, 100, 10000000,3, 0},
							{2, "Nico", "Mediocampista", 10, 101, 11000444,3, 0},
							{3, "Luca", "Arquero", 1, 103, 12000555, 5,  0},
							{4, "Joaco", "Defensor", 8, 104, 13333444, 2, 0},
							{5, "Juani", "Mediocampista", 11, 101, 14000888, 1, 0},
							{6, "Juanma", "Delantero", 7, 105, 15555444, 5, 0},
							{7, "Milena", "Mediocampista", 5, 102, 1622200, 2, 0},
							{8, "Daniela", "Defensor", 4, 101, 1700000, 4,  0},
							{9, "Bianca", "Delantero", 14, 105, 18000000, 3,  0},
							{10, "Ailen", "Defensor", 3, 100, 19000000, 6, 0}};

    if(listaJugadors != NULL && size > 0 && cantidad <= size && cantidad <= 10)
    {

        for(int i = 0 ; i < cantidad ; i++)
        {
        	listaJugadors[i] = auxJugador[i];
        }
        retorno = 1;
    }
    return retorno;
}

int CargarJugador(eJugador unJugador[], eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int retorno=-1;
	char nombreAux[50];
	int posicionJugador;

	if(unJugador!=NULL && listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		Utn_GetString(nombreAux, "Ingrese Nombre del jugador: \n", "Ingrese un nombre VALIDO:\n", 50);
		strcpy(unJugador->nombre, nombreAux);

		Utn_GetInt(&posicionJugador, "---POSICIONES---\n1)Arquero.\n2)Defensor.\n3)Mediocampista.\n4)Delantero.\n>Ingrese una posicion: \n", " ERROR ingrese una posicion VALIDO! \n", 1, 4, 100);
		switch(posicionJugador)
		{
		case 1:
			strcpy(unJugador->posicion, "Arquero");
			break;
		case 2:
			strcpy(unJugador->posicion, "Defensor");
			break;
		case 3:
			strcpy(unJugador->posicion, "Mediocampista");
			break;
		case 4:
			strcpy(unJugador->posicion, "Delantero");
			break;
		}



		Utn_GetShortInt(&unJugador->numeroCamiseta, ">Ingrese numero de camiseta: \n", " ERROR Ingrese numero de camiseta VALIDO! \n", 1, 99, 100);

		MostrarConfederaciones(listaConfederaciones, sizeConfederaciones);
		fflush(stdin);
		Utn_GetInt(&unJugador->idConfederacion, "\n>Ingrese ID de confederacion: \n",  "ERROR ingrese ID de confederacion VALIDO! \n", 100, 105, 100);

		Utn_GetFloat(&unJugador->salario, ">Ingrese salario: \n", "ERROR Ingrese un salario VALIDO! \n", 100000, 1000000000, 1000);

		Utn_GetShortInt(&unJugador->aniosContrato, ">Ingrese anios de contrato: \n", "ERROR ingrese anios de contrato VALIDOS! \n", 1, 20, 100);

		unJugador->isEmpty=0;

		retorno=1;

	}

	return retorno;
}

int CargarListaJugadores(eJugador listaJugador[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int retorno=-1;
	int indice;
	eJugador auxJugador;

	if(listaJugador!=NULL && sizeJugadores>0 && listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		printf("-------Alta Jugadores------\n\n");
		indice=BuscarLibre(listaJugador, sizeJugadores);

		if(indice==-1)
		{
			printf("No hay lugar...\n");
		}
		else
		{
			CargarJugador(&auxJugador, listaConfederaciones, sizeConfederaciones);
			auxJugador.id=IdAutoIncremental();

			listaJugador[indice]=auxJugador;

			retorno=1;
		}
	}

	return retorno;

}
void MostrarJugador(eJugador jugador, eConfederacion listaConfederaciones[],int sizeConfederaciones)
{
	char nombreConfederacion[50];

	CargarNombreConfederacion(listaConfederaciones, sizeConfederaciones, jugador.idConfederacion, &nombreConfederacion);
	printf("  %4d  %25s        %15s         %hd           $%.2f   %10s           %hd \n",  jugador.id,
																					   jugador.nombre,
																					   jugador.posicion,
																					   jugador.numeroCamiseta,
																					   jugador.salario,
																					   nombreConfederacion,
																					   jugador.aniosContrato);

}

void MostrarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[],int sizeConfederaciones)
{
	printf("|=========================================================LISTA JUGADORES====================================================|\n");
	printf("|  ID    |              NOMBRE           |    POSICION    | NRO. CAMISETA |     SUELDO    | CONFEDERACION | AÑOS DE CONTRATO |\n");
	printf("|============================================================================================================================|\n");
	if(listaJugadores!=NULL && sizeJugadores>0 && listaConfederaciones!=NULL && sizeConfederaciones>0)
	{
		for(int i=0; i<sizeJugadores; i++)
		{
			if(listaJugadores[i].isEmpty==0)
			{
				MostrarJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
			}
		}
	}
}

//buscar por id
int VerificarId(eJugador listaJugadores[], int sizeJugadores, int id)
{
	int indice= -1;

	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		for(int i=0; i<sizeJugadores; i++)
		{
			if(listaJugadores[i].isEmpty==0 && listaJugadores[i].id==id)
			{
				indice=i;
				break;
			}
		}

	}

	return indice;
}

int BajaJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int id;
	int indice;
	int respuesta;
	int retorno=-1;

	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		printf("============BAJA JUGADOR============\n");
		MostrarListaJugadores(listaJugadores, sizeJugadores, listaConfederaciones, sizeConfederaciones);
		fflush(stdin);
		Utn_GetInt(&id, "Ingrese un ID: \n",  "Ingrese un ID valido: \n", 1, 3000);


		indice=VerificarId(listaJugadores, sizeJugadores, id);

		if(indice==-1)
		{
			printf("NO hay jugador con ese ID...\n");
		}
		else
		{
			Utn_GetInt(&respuesta, ">Confimar baja:\n1)SI\n2)NO\n", "ERROR\n>Confimar baja:\n1)SI\n2)NO\n", 1, 2);
			if(respuesta==1)
			{
				listaJugadores[indice].isEmpty=1;
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

int ModificacionJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int retorno=-1;
	int respuesta;
	int id;
	int indice;
	char nombreAux[50];
	int posicionJugador;

	if(listaJugadores!=NULL && sizeJugadores>0 && listaConfederaciones!=NULL && sizeConfederaciones>0)

	{
		MostrarListaJugadores(listaJugadores, sizeJugadores, listaConfederaciones, sizeConfederaciones);
		Utn_GetInt(&id, "Ingrese un ID: \n",  "Ingrese un ID valido: \n", 1, 3000);
		indice=VerificarId(listaJugadores, sizeJugadores, id);

		if(indice==-1)
		{
			printf("NO hay jugador con ese ID...\n");
		}
		else
		{
			do
			{
				MenuModificacion();
				fflush(stdin);
				Utn_GetInt(&respuesta, ">Ingrese una opcion: \n", "ERROR ingrese opcion VALIDA", 1, 7, 1000);

				switch(respuesta)
				{
				case 1:
					Utn_GetString(nombreAux, "Ingrese Nombre del jugador: \n", "Ingrese un nombre VALIDO:\n", 50);
					strcpy(listaJugadores[indice].nombre, nombreAux);
					break;

				case 2:
					Utn_GetInt(&posicionJugador, "---POSICIONES---\n1)Arquero.\n2)Defensor.\n3)Mediocampista.\n4)Delantero.\n>Ingrese una posicion: \n", " ERROR ingrese una posicion VALIDO! \n", 1, 4, 100);
					switch(posicionJugador)
					{
					case 1:
						strcpy(listaJugadores[indice].posicion, "Arquero");
						break;
					case 2:
						strcpy(listaJugadores[indice].posicion, "Defensor");
						break;
					case 3:
						strcpy(listaJugadores[indice].posicion, "Mediocampista");
						break;
					case 4:
						strcpy(listaJugadores[indice].posicion, "Delantero");
						break;
					}
					break;

				case 3:
					Utn_GetShortInt(&listaJugadores[indice].numeroCamiseta, ">Ingrese numero de camiseta del 1 al 99: \n", " ERROR Ingrese numero de camiseta VALIDO! \n", 1, 99, 100);
					break;

				case 4:
					MostrarConfederaciones(listaConfederaciones, sizeConfederaciones);
					fflush(stdin);
					Utn_GetInt(&listaJugadores[indice].idConfederacion, "\n>Ingrese ID de confederacion: \n",  "ERROR ingrese ID de confederacion VALIDO! \n", 100, 105, 100);
					break;

				case 5:
					Utn_GetFloat(&listaJugadores[indice].salario, ">Ingrese salario: \n", "ERROR Ingrese un salario VALIDO! \n", 100000, 1000000000, 100);
					break;

				case 6:
					Utn_GetShortInt(&listaJugadores[indice].aniosContrato, ">Ingrese anios de contrato: \n", "ERROR ingrese anios de contrato VALIDOS! \n", 1, 20, 100);
					break;
				case 7:
					printf("\n Volvio al Menu Principal\n");
					break;

				}

			}while(respuesta!=7);
			retorno=1;
		}

	}


	return retorno;
}


int OrdenarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	eJugador auxJugador;
	int retorno=0;
	char nombreConfedracion1[50];
	char nombreConfedracion2[50];



	if(listaJugadores!=NULL && sizeJugadores>0)
	{
		for(int i=0;i<sizeJugadores -1;i++)
		{
			for(int j=i+1;j<sizeJugadores;j++)
			{
				CargarNombreConfederacion(listaConfederaciones, sizeConfederaciones, listaJugadores[i].idConfederacion, nombreConfedracion1);

				CargarNombreConfederacion(listaConfederaciones, sizeConfederaciones, listaJugadores[j].idConfederacion, nombreConfedracion2);

				if(listaJugadores[i].isEmpty==0 &&( (strcmp(nombreConfedracion1,nombreConfedracion2)==0 && strcmp(listaJugadores[i].nombre,listaJugadores[j].nombre)>0)||(strcmp(nombreConfedracion1, nombreConfedracion2)>0)))
				{
					auxJugador=listaJugadores[i];
					listaJugadores[i]=listaJugadores[j];
					listaJugadores[j]=auxJugador;

				}

			}
		}
		retorno=1;
	}
	 return retorno;
}





#endif /* ESTRUCTURAJUGADOR_C_ */
