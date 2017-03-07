#include<stdio.h>
#include<stdlib.h>
#define DEBUG 0  // 1 con impresion , 0 no imprime nada

typedef struct nodo
{
    int valor;
    struct nodo *sig;
} nodo_t;

typedef struct queue
{
    nodo_t *head;
    nodo_t *tail;
} queue_t;

void enqueue( queue_t *q , int v);
int dequeue( queue_t *q );

queue_t *crearQueue()
{
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->head = NULL;
    q->tail = NULL;
    return q;
}


void debug(char *str)
{
    if(DEBUG){ //  Similar a  if( DEBUG == 1 )
        printf(str);
    }
}

void printQ(queue_t *q)
{
    nodo_t *aux = q->head;
    printf("\t HEAD <<< ");
    while(aux != NULL)
    {
        printf(" %d ",aux->valor);
        aux = aux->sig;
    }
    printf(" <<< TAIL  \n\n");
}

int main()
{

    // inicio del queue
    queue_t *q = crearQueue();

    printf("Inicio de q \n");
    printQ(q);

    printf("enqueue(q,5) \n");
    enqueue(q,5);
    printQ(q);

    printf("enqueue(q,8) \n");
    enqueue(q,8);
    printQ(q);

    printf("enqueue(q,11) \n");
    enqueue(q,11);
    printQ(q);

    printf("dequeue(q) Retorna: %d \n",dequeue(q));
    printQ(q);
    printf("dequeue(q) Retorna: %d \n",dequeue(q));
    printQ(q);
    printf("dequeue(q) Retorna: %d \n",dequeue(q));
    printQ(q);

    return 0 ;
}

void enqueue( queue_t *q , int v)
{
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));

    nuevo->valor = v;
    nuevo->sig   = NULL;

    if(q->head == NULL && q->tail== NULL)
    {
        //primer elemento de q
        debug("Primer elemento de la cola \n");
        q->head = nuevo;
        q->tail = nuevo;
    }
    else
    {
        debug("Nodo siguiente \n");
        q->tail->sig = nuevo;  // Enlazar el nuevo nodo
        q->tail       = nuevo;  // Recorre Tail al ultimo nodo
    }
}

int dequeue( queue_t *q  )
{
    int v_retorno = 0;
    nodo_t *aux;

    if(q->head != NULL && q->tail != NULL )
    {
        v_retorno = (q->head)->valor;
        aux  = q->head;

        if(q->head == q->tail)
        {
            debug("Desencolar ultimo nodo \n");
            // coloca los apuntadores a nulo
            // debido a que se trata del ultimo elemento
            q->head = NULL;
            q->tail = NULL;

        }
        else
        {
            debug("Desencolar nodo \n");
            // mover el apuntador head
            q->head = aux->sig;   // q->head = ( q->head )->sig;
        }
        free(aux);
    }
    else
    {
        printf("Q vacia, error de  underflow \n");
    }

    return v_retorno;
}
