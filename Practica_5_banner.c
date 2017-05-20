#include<stdio.h>
#include<stdlib.h>//para malloc
#include<string.h>//para strlen
//Trate de hacer que el codigo funcione tanto en linux como en windows
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

typedef struct nodo
{
    char valor;
    struct nodo *sig;
} nodo_t; //nodo

typedef struct queue
{
    nodo_t *head;
    nodo_t *tail;
} queue_t; //cola

void enqueue( queue_t *q , char v){
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));

    nuevo->valor = v;
    nuevo->sig   = NULL;

    if(q->head == NULL && q->tail== NULL)
    {
        //primer elemento de q
        //debug("Primer elemento de la cola \n");
        q->head = nuevo;
        q->tail = nuevo;
    }
    else
    {
        //debug("Nodo siguiente \n");
        q->tail->sig = nuevo;  // Enlazar el nuevo nodo
        q->tail       = nuevo;  // Recorre Tail al ultimo nodo
    }
}

char dequeue(queue_t *q){
//modifique la funcion originar para que regrese un caracter
   int v_retorno = 0;
    nodo_t *aux;

    if(q->head != NULL && q->tail != NULL )
    {
        v_retorno = (q->head)->valor;
        aux  = q->head;

        if(q->head == q->tail)
        {
            //debug("Desencolar ultimo nodo \n");
            // coloca los apuntadores a nulo
            // debido a que se trata del ultimo elemento
            q->head = NULL;
            q->tail = NULL;

        }
        else
        {
            //debug("Desencolar nodo \n");
            // mover el apuntador head
            q->head = aux->sig;   // q->head = ( q->head )->sig;
        }
        free(aux);
    }
    else
    {
        printf("Q vacia, error de  underflow \n");
    }

    return v_retorno;//regresa el caracter
}

queue_t *crearQueueVacia()
/*modifique la funcion original para que cree la cola "vacia" y evitar errores
de impresión*/
{int i;
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->head = NULL;
    q->tail = NULL;
	    for(i=0;i<10;i++){
        enqueue(q,' ');}
    //solo hasta 9 para que el banner no imprima caracteres aleatorios
    return q;
}

/**********************************************************************/
//Inicia main
//puse los asteriscos para ubicarla más rapido c: 
int main(){
    queue_t *q = crearQueueVacia();//creo cola vacia
    nodo_t *aux;//creo aux para recorrer la impresion
    char str[100],banner[10],Re;
    /*str es mi buffer para guardar el texto del banner, banner es la
	"la pantalla" donde imprimire, Re es para Recuperar caracter*/
    int i;;//para ciclo
    printf("Escribe un texto : ");
    fgets(str,100,stdin);

    for(i=0;i<(strlen(str));i++){//ciclo para mandar lo del buffer a la cola
        enqueue(q,str[i]);}

    do{
/*ciclo infinito
fuente: http://listas.conclase.net/pipermail/cconclase_listas.conclase.net/2010-November/008678.html*/
    	banner[10]='\0';//para que no imprima demas
  //para compatibilidad linux-windows
  #ifdef _WIN32
        system("cls");
  #else
  		system("clear");
  #endif
        aux = q->head;//posiciono a aux en el principio de la cola
        i=0;//inicio el ciclo
          while(i<10){//ciclo para añadir al banner con el stack
		    banner[i]= aux->valor;//se le asigna a un subindice de banner el valor del nodo
            aux=aux->sig;//recorro el nodo
            i++;//recorro el ciclo
          }
        Re = dequeue(q);//saco del stack
        enqueue(q, Re);//reingreso al stack el caracter
        printf("%s", banner);//imprimo la pantalla 

  #ifdef _WIN32
        Sleep(200);//para pausar
  #else
        usleep(20000);//para pausar
  #endif

    }while(TRUE);//cierro ciclo infinito

    //return 0; no necesito return 0 por que nunca termina la ejecucion
}
