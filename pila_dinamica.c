#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
   int    valor;
   struct nodo* sig;
}nodo_t;

typedef struct pila
{   // El apuntador tope es una referencia al ultimo nodo de la pila
    nodo_t* tope;
}pila_t;

pila_t *crearPila(){
  // La función crea una estructura pila en la memoria dinámica
  // y asigna la referencia del ultimo nodo a NULL indicando que la
  // pila esta vacia
  pila_t* pila = (pila_t*)malloc(sizeof(pila_t));
  pila->tope = NULL;

  return pila;
}

void push(pila_t *p, int v)
{
   // Crear una variable de tipo nodo en memoria dinámica
	nodo_t *nuevo=(nodo_t *)malloc(sizeof(nodo_t));
   // Validar que se tiene una dirección valida (diferente de nulo)
	if(nuevo==NULL){
	printf("Error overflow :v");	
	}else{
   // Asignar el numero v dentro del nodo
	nuevo->valor=v;
   // Enlazar el nodo al ultimo elemento de la pila
	nuevo->sig= p->tope;
   // Cambiar la referencia de la pila al nuevo nodo
	p->tope=nuevo;
	}

}

int pop(pila_t *p)
{	int v;
   // Validar que existe al menos un nodo, es decir, si se tiene una dirección valida (diferente de nulo
	if (p->tope==NULL){
		printf("Error Underflow");	
	}else{
   // Extraer el dato numerico fuera del ultimo nodo
	v=(p->tope)->valor;
   // Asignar un apuntador temporal al nodo a ser eliminado
	nodo_t *aux;
   // Actulizar la referencia de la pila del ulimo nodo al que es el penultimo
     aux=(p->tope)->sig;
   // Liberar la memoria del ultimo nodo
  free(aux);

   return v;
   }
}


int  main(int argc, char *args[]) {

  pila_t *pila = crearPila();

  push(pila, 1);
  push(pila, 2);

  int a = pop(pila_A);

  printf(" %d \n", a );
  printf(" %d \n", pop(pila_A) );
  /*  La salida debe ser
      2
      1
    */
return 0;
}
