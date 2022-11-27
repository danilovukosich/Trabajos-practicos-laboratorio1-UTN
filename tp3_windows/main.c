
/*
 * DANILO VUKOSICH 1A TP3
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "menus.h"
#include "inputs.h"
#include "Seleccion.h"


int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int opcionListados=0;
    int returnController;
    int banderaCargaListas=0;
    int opcionConvocar=0;
    int opcionOrdenaListas=0;
    int banderaGuardado=0;
    int banderaConvocados=1;
    int opcionConfederacion=0;
    char confederacionElegida[50];
    int banderaAltaJugadoresConfederacion=0;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaJugadoresCofederacion = ll_newLinkedList();//lista para confederaciones.



    //puts("funciona ok");

    do{
    	MenuPrincipal();
    	Utn_GetInt(&option, "\n>Ingrese una opcion: ", "\n>Ingrese una opcion VALIDA!", 1, 11, 15);

        switch(option)
        {
            case 1://CARGA EN MEMORIA validar los controllers con if´s
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);
            	banderaCargaListas=1;//se cargaron los datos
                break;

            case 2://ALTA
            	if(banderaCargaListas==1)
            	{
            		returnController=controller_agregarJugador(listaJugadores, listaSelecciones);
					if(returnController==1)
					{
						printf("Se agrego el jugador correctamente!\n");
					}
					else
					{
						printf("ERROR al cargar jugador!\n");
					}
            	}
            	else
            	{
            		printf("\nREALIZAR LA CARGA ANTES!(Opcion 1)\n");
            	}
            	break;

            case 3://MODIFICACION
            	if(banderaCargaListas==1)
            	{
            		returnController=controller_editarJugador(listaJugadores, listaSelecciones);
            		if(returnController==1)
            		{
            			printf("Se modifico correctamente!\n");
            		}
            		else
            		{
            			printf("ERROR al modificar!\n");
            		}
            	}
            	else
				{
					printf("\nREALIZAR LA CARGA ANTES!(Opcion 1)\n");
				}
            	break;

            case 4://BAJA
            	if(banderaCargaListas==1)
            	{
            		returnController=controller_removerJugador(listaJugadores, listaSelecciones);
					if(returnController==1)
					{
						printf("Se elimino Correctamente!\n");
					}
					else
					{
						printf("ERROR al eliminar!\n");
					}
            	}
            	else
				{
					printf("\nREALIZAR LA CARGA ANTES!(Opcion 1)\n");
				}


				break;

            case 5://listados
            	if(banderaCargaListas==1)
            	{
            		do
					{
						MenuListados();
						Utn_GetInt(&opcionListados, "\n>Ingrese una opcion: ", "\nIngrese una opcion VALIDA! ", 1, 4, 15);

						switch(opcionListados)
						{
						case 1:
							controller_listarJugadores(listaJugadores);
							break;

						case 2:
							controller_listarSelecciones(listaSelecciones);
							break;

						case 3:
							if(banderaConvocados==1)
							{
								controller_listarJugadoresConvocados(listaJugadores);
							}
							else
							{
								printf("\nNo se convoco ningun jugador!\n");
							}

							break;
						}

					}while(opcionListados!=4);
            	}
            	else
				{
					printf("\nREALIZAR LA CARGA ANTES!(Opcion 1)\n");
				}

				break;

            case 6://CONVOCAR
            	if(banderaCargaListas==1)
            	{
            		do
					{
						MenuConvocados();
						Utn_GetInt(&opcionConvocar, "\n>Ingrese una opcion: ", "\nIngrese una opcion VALIDA!", 1, 3, 15);

						switch(opcionConvocar)
						{
						case 1:
							returnController=controller_convocarJugador(listaJugadores, listaSelecciones);
							if(returnController==1)
							{
								printf("Se Convoco Correctamente!\n");
								banderaConvocados=1;
							}
							else
							{
								printf("ERROR al convocar!\n");
							}
							break;
						case 2:
							if(banderaConvocados==1)
							{
								returnController=controller_removerDeSeleccion(listaJugadores, listaSelecciones);
								if(returnController==1)
								{
									printf("Se elimino Correctamente de la seleccion!\n");
								}
								else
								{
									printf("ERROR al eliminar de la seleccion!\n");
								}
							}
							else
							{
								printf("Convocar al menos un jugador antes!\n");
							}

							break;
						case 3:
							printf("Volvio al menu principal...\n");
							break;
						}

					}while(opcionConvocar!=3);
            	}
            	else
				{
					printf("\nREALIZAR LA CARGA ANTES!(Opcion 1)\n");
				}
				break;

            case 7://ORDENAR Y LISTAR
            	if(banderaCargaListas==1)
            	{
            		do
					{
						MenuOrdenamientos();
						Utn_GetInt(&opcionOrdenaListas, "\n>Ingrese una opcion: ", "\nIngrese una opcion VALIDA!", 1, 5, 15);
						controller_ordenarJugadores(listaJugadores, listaSelecciones, opcionOrdenaListas);

						switch(opcionOrdenaListas)
						{
						case 1:
							controller_listarJugadores(listaJugadores);
							break;
						case 2:
							controller_listarSelecciones(listaSelecciones);
							break;
						case 3:
							controller_listarJugadores(listaJugadores);
							 break;
						case 4:
							controller_listarJugadores(listaJugadores);
							break;
						}

					}while(opcionOrdenaListas!=5);
            	}
            	else
				{
					printf("\nREALIZAR LA CARGA ANTES!(Opcion 1)\n");
				}


				break;

            case 8:
            	//igualo la lista al filtro que me la devuelve y la cargo en el controller
            	if(banderaCargaListas==1)
            	{
            		if(banderaConvocados==1)
            		{
            			ElegirConfederacion();
						Utn_GetInt(&opcionConfederacion, ">Ingrese la confederacion: ", "ERROR canfedracion invalida!\n", 1, 5, 15);
						GetConfederacionSeleccionada(opcionConfederacion, confederacionElegida);

						returnController=controller_ListaPorConfederacion(listaJugadoresCofederacion, listaJugadores, listaSelecciones, confederacionElegida);
						if(returnController==1)
						{
							controller_guardarJugadoresModoBinario("listaJugadoresConvocados.bn", listaJugadoresCofederacion);
							banderaAltaJugadoresConfederacion=1;
						}
						else
						{
							printf("No se encontro jugador convocado en esa confederacion\n");
						}
            		}
            		else
            		{
            			printf("\nCONVOCAR AL MENOS UN JUGADOR ANTES!(Opcion 1)\n");
            		}

            	}
            	else
				{
					printf("\nREALIZAR LA CARGA ANTES!(Opcion 1)\n");
				}
				break;

            case 9://CARGAR ARCHIVO BINARIO DLE PUNTO 8
            	if(banderaAltaJugadoresConfederacion==1)
            	{
            		controller_cargarJugadoresDesdeBinario("listaJugadoresConvocados.bn", listaJugadoresCofederacion);
            		controller_listarJugadores(listaJugadoresCofederacion);
            	}
            	else
            	{
            		printf("\nREALIZAR LA CARGA ANTES!(Opcion 8)\n");
            	}
				break;

            case 10://GUARDAR ARCHIVO .CSV con todos los camibios de jugadoes y selecciones
            	if(banderaCargaListas==1)
            	{
            		returnController=controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
					if(returnController==1)
					{
						printf("Se guardo Correctamente la lista de jugadores!\n");
					}
					else
					{
						printf("ERROR al guardar jugadores!\n");
					}
					returnController=controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones);
					if(returnController==1)
					{
						printf("Se Guardo Correctamente la lista de selecciones!\n");
					}
					else
					{
						printf("ERROR al Guardar selecciones!\n");
					}
					banderaGuardado=1;
            	}
            	else
				{
					printf("\nREALIZAR LA CARGA ANTES!(Opcion 1)\n");
				}
            	break;

            case 11:
				if(banderaGuardado!=1)//BANDERA PARA PREGUNTAR SI DESEA SALIR SIN GUARDAR
				{
					int i=0;

						printf("Seguro que desea salir sin guardar?");
						Utn_GetInt(&i, "\n1)Si\n2)No\n>Ingrese una opcion:", "\nIngrese una opcion valida!", 1, 2, 15);
						switch(i)
						{
						case 1:
							printf("\n\nSALIO DEL PROGRAMA...\n");
							//elimnino las listas creadas
							controller_LiberarLista(listaJugadores);
							controller_LiberarLista(listaSelecciones);
							controller_LiberarLista(listaJugadoresCofederacion);
							option=12;
							break;
						case 2:
							printf("Volvio al menu principal...\n");
							break;
						}

				}
				else
				{
					printf("\n\nSALIO DEL PROGRAMA...\n");
					controller_LiberarLista(listaJugadores);
					controller_LiberarLista(listaSelecciones);
					controller_LiberarLista(listaJugadoresCofederacion);
					option=12;
				}
            	break;
        }//fin del switch

    }while(option != 12);

    return 0;
}

