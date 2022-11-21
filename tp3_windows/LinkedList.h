/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
//crea una lista en memoria dinamica.
LinkedList* ll_newLinkedList(void);

//permite saber cuatos elementos hay en la lista.
int ll_len(LinkedList* this);


Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//agrega un elemento al final de la lista si hay espacio en memoria.
int ll_add(LinkedList* this, void* pElement);

//devuelve el elementod del idex que le paso.
void* ll_get(LinkedList* this, int index);

//reemplaza a un jugador en la lista.
int ll_set(LinkedList* this, int index,void* pElement);

//remueve el elemento del index que le paso.
int ll_remove(LinkedList* this,int index);

//vacia la lista y esta sigue existiendo
int ll_clear(LinkedList* this);

//elimina la lista creada por completo
int ll_deleteLinkedList(LinkedList* this);

//le paso la lista y un elemnto y me devuelce en que index se encuentra, sino devuelve -1
int ll_indexOf(LinkedList* this, void* pElement);

//me devuelve si la lista esta llena o no(sirve como bandera)
int ll_isEmpty(LinkedList* this);

//agrega un jugador en el medio de la lista.
int ll_push(LinkedList* this, int index, void* pElement);

//hace lo mismo que el remove pero devuelve el elemento que elimina de la lista.
void* ll_pop(LinkedList* this,int index);

//parecido al ll_indexoff que me dice si el elemnto esta contenido en la lista.(PROBABLEMENTE NO SE USEN)
int ll_contains(LinkedList* this, void* pElement);

//mem dice si los elementos de una lista estan contenidos en otra.(PROBABLEMENTA NO SE USEN)
int ll_containsAll(LinkedList* this,LinkedList* this2);

//me devuelve un pedazo de la lista desde una posicion hasta otra.
LinkedList* ll_subList(LinkedList* this,int from,int to);

//me devuelve una copia exacta de la lista.(la usamos para hacer ordenamientos ordenando la copia para no tocar el listado original)
LinkedList* ll_clone(LinkedList* this);

//nos permite ordenar la lista.
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
