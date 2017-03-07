#include<stdio.h>
#include<stdlib.h>

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
queue_t *crearQueue()
{
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue( queue_t *q, int v)
{
}

int dequeue( queue_t *q  )
{   int v_retorno;
    return v_retorno;
}



int main()
{
    queue_t *q = crearQueue();

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);

    printf("%d \n", dequeue(q));
    printf("%d \n", dequeue(q));
    printf("%d \n", dequeue(q));

    /* La salida debe ser
      1
      2
      3
    */

    return 0 ;
}

