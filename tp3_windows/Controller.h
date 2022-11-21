int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador, LinkedList* parraylistSeleccion);//modificada
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* listaSelecciones);
int controller_removerJugador(LinkedList* pArrayListJugador);
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int opcion);//modificada
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_listarNacionalidades(LinkedList* pArrayListSeleccion);

int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* listaSelecciones);
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);
int controller_removerDeSeleccion(LinkedList* pArrayListJugador, LinkedList* listaSelecciones);

