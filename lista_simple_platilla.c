/****************************************************************
EDyA I

Lista Ligada

head ->[ a ]->[ b ]->[ c ]->...->[Referencia a nulo]
inicio                            terminación de la lista
  
****************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct  nodo
{
    int v;
    struct nodo *sig;
} nodo_t;

typedef struct lista
{
	// Apuntador al inicio de la lista lista
    nodo_t *head;
	// Apuntador auxiliar util para recorrer toda la lista 
    nodo_t *ptr;
} lista_t;

lista_t *crearLista()
{
    lista_t *lista = malloc(sizeof(lista_t));

    lista->head = NULL;
    lista->ptr  = NULL;

    return lista;
}

// Devuelve 1 si la lista esta vacia, en caso contrario 0
int isEmpty(lista_t *l)
{
}

// Registra un nuevo nodo previo a head
void insertarAlInicio(lista_t *l, int v)
{


// Registra un nuevo nodo en la ultima posicion con una 
// referencia de siguiente en nulo 
void insertarAlFinal(lista_t *l, int v)
{
}

// Elimina la primera ocurrencia de v
void delete(lista_t *l, int v)
{
}
// Elimina toas ocurrencias de v
void deleteAll(lista_t *l, int v)
{
}
// Imprime los lementos de la lista desde head
void printList(lista_t *l)
{
}
// Devuelve el valor maximo de la lista, sin extraerlo o eliminarlo
int maximo(lista_t *l)
{
}

// Devuelve el valor minimo de la lista, sin extraerlo o eliminarlo
int minimo(lista_t *l)
{
}

// Elimina todos los elementos de la lista
void freeList(lista_t *l)
{
}

// Recorre todos los elementos de la lista hasta encontrar el
// primer elemento con valor igual a v, y regresa la referencia a ese nodo, 
// de no encontrar ningun elemento devuelve la referencia a nulo
nodo_t *search(lista_t *l,int v)
{
}

int main()
{
	iniciarAletorios();
	
	// Crear una lista de nombre "listaNums"

    // Prueba de la funcion eliminar al inicio 	
	
	// Prueba de la funcion eliminar al final
	
	// Uso de insertar al inicio los valores { 5, 1, 0, 2, 0, 3, 6 } con este orden
	
	// imprimir la lista
	
	// eliminar el primer numero

	// eliminar el ultimo numero
	
	// elimina todos los 0 con una sola instruccion
	
	// imprimir la lista
	
	// Vacia la lista
	
	// imprimir la lista
	
	// Uso de insertar al final los valores { 7, 8, 9, 10 } con este orden
	
	// imprimir la lista
	
	// eliminar el primer numero

	// eliminar el ultimo numero
	
	// imprimir la lista
	
	// Vacia la lista

    return 0;
}
