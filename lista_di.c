/****************************************************************
EDyA I by gr2
Lista Doblemente Ligada
****************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *sig;
    struct nodo *pre;
} nodo_t;

typedef struct listaDoble
{
    nodo_t *head;
    nodo_t *tail;
    int size;
} listaDoble_t;

listaDoble_t *crearListaDoble()
{
    listaDoble_t *lista = (listaDoble_t *)malloc(sizeof(listaDoble_t));
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

nodo_t *crearNodo(int v)
{
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));
    nuevo->valor = v;
    nuevo->sig   = NULL;
    nuevo->pre   = NULL;
    return nuevo;
}

int isEmpty(listaDoble_t *lista)
{
    int result=1;

    if(lista==NULL)
    {
        result = 1;
    }
    else
    {
        if(lista->head == NULL && lista->tail == NULL)
            result = 1;
        else
            result = 0;
    }

    return result;
}


void insertarAlInicio(listaDoble_t *lista, int v)
{
    nodo_t *nuevo = crearNodo(v);

    if(lista->head == NULL && lista->tail == NULL )
    {
        //primer elemento de l
        lista->head = nuevo;
        lista->tail = nuevo;

    }
    else
    {
        lista->head->pre = nuevo ;   //
        nuevo->sig      = lista->head;  // Enlazar el nuevo nodo
        lista->head      = nuevo;  // Recorre Head al primer nodo
    }

    lista->size++;

}

void insertarAlFinal(listaDoble_t *lista, int v)
{
    nodo_t *nuevo = crearNodo(v);

    if(lista->head == NULL  && lista->tail == NULL)
    {
        //primer elemento de l
        lista->head = nuevo;
        lista->tail = nuevo;
    }
    else
    {
        lista->tail->sig = nuevo;   //
        nuevo->pre    = lista->tail;  // Enlazar el nuevo nodo
        lista->tail      = nuevo;     // Recorre Tail al ultimo nodo
    }

    lista->size++;

}
void printLista(listaDoble_t *lista)
{
    if(!isEmpty(lista))
    {
        nodo_t *aux = lista->head;

        while(aux != NULL)
        {
            printf(" %d ",aux->valor);
            aux = aux->sig;
        }
        printf("\n\n");
    }
}

void printListaReversa(listaDoble_t *lista)
{
    if(!isEmpty(lista))
    {
        nodo_t *aux = lista->tail;

        while(aux != NULL)
        {
            printf(" %d ",aux->valor);
            aux = aux->pre;
        }
        printf("\n\n");
    }

}

void delete(listaDoble_t *lista, int v)
{
    if(!isEmpty(lista))
    {
        nodo_t *aux = lista->head;

        if(lista->head  == lista->tail)
        {
            free(aux);
            lista->head = NULL;
            lista->tail = NULL;
            lista->size = 0;
        }
        else if(aux->valor == v)
        {
            lista->head = aux->sig;
            lista->head->pre = NULL;
            free(aux);
            lista->size--;
        }
        else
        {
            while( aux != NULL )
            {
                if(aux->sig != NULL)
                {
                    if(aux->sig->valor == v)
                    {

                        nodo_t *liberar     = aux->sig;
                        aux->sig            = liberar->sig;

                        if(liberar->sig == NULL)
                        {
                            lista->tail = aux;
                        }
                        else
                        {
                            (liberar->sig)->pre = aux;
                        }

                        free(liberar);
                        lista->size--;
                        aux = NULL;

                    }
                    else
                    {
                        aux = aux->sig;
                    }
                }
                else
                {
                    aux = aux->sig;
                }

            }
        }
    }
}

void deleteEnIndice(listaDoble_t *lista, int indx)
{

    nodo_t *aux = NULL;

    if( (0 <= indx)  && (indx < lista->size) )
    {

        if(lista->size == 1)
        {
            free(lista->head);
            lista->head = NULL;
            lista->tail = NULL;
            lista->size--;
        }
        else if(indx == 0)
        {
            // Borrar el primer elemento
            aux  = lista->head;
            lista->head = aux->sig;
            lista->head->pre = NULL;
            free(aux);
            lista->size--;
        }
        else if(indx == (lista->size-1))
        {
            // Borrar el ultimo elemento
            aux  = lista->tail;
            lista->tail = aux->pre;
            lista->tail->sig = NULL;
            free(aux);

            lista->size--;

        }
        else
        {
            // Borrar un elemento intermedio
            int i=0;
            aux = lista->head;

            while(i<indx-1)
            {
                aux = aux->sig;
                i++;
            }

            nodo_t *liberar     = aux->sig;
            aux->sig            = liberar->sig;
            (liberar->sig)->pre = aux;
            free(liberar);
            lista->size--;

        }
    }
    else
    {
        printf("error en deleteEnIndice() indice fuera de la lista\n");
    }
}

nodo_t *search(listaDoble_t *lista, int v)
{
    int continuar = 1;
    nodo_t *aux = NULL;

    if(!isEmpty(lista))
    {
        aux = lista->head;

        while( aux != NULL && continuar == 1)
        {
            if(aux->valor != v)
            {
                aux = aux->sig;
            }
            else
            {
                continuar = 0;
            }
        }
    }

    return aux ;
}

int searchIndex(listaDoble_t *lista, int v)
{
    int resultado = -1;
    int cont = -1;
    nodo_t *aux = NULL;

    if(!isEmpty(lista))
    {
        aux = lista->head;

        while( aux != NULL)
        {
            cont++;

            if(aux->valor == v)
            {
                resultado = cont;
                aux = NULL;
            }
            else
            {
                aux = aux->sig;
            }
        }
    }

    return resultado ;
}

void insertaEnIndice(listaDoble_t *lista, int v, int indx)
{

    nodo_t *aux = NULL;

    if(indx <= lista->size )
    {

        if(indx == 0)
        {
            insertarAlInicio(lista,v);
        }
        else if(indx == lista->size)
        {
            insertarAlFinal(lista,v);
        }
        else
        {

            int i=0;
            aux = lista->head;
            while(i<indx-1)
            {
                aux = aux->sig;
                i++;
            }

            nodo_t *nuevo = crearNodo(v);

            nuevo->sig = aux->sig;
            nuevo->pre = aux;
            aux->sig = nuevo;
            nuevo->sig->pre = nuevo;

            lista->size++;

        }

    }
}


int maximo(listaDoble_t *l)
{
    int v = 0;

    if(isEmpty(l))
    {
        printf("lista vacia \n ");
    }
    else
    {
        nodo_t *aux = l->head;
        v = aux->valor;
        while(aux != NULL)
        {
            if( v < aux->valor )
            {
                v = aux->valor;
            }

            aux = aux->sig;
        }
    }

    return v;
}

int minimo(listaDoble_t *l)
{
    int v = 0;

    if(isEmpty(l))
    {
        printf("lista vacia \n ");
    }
    else
    {
        nodo_t *aux = l->head;
        v = aux->valor;
        while(aux != NULL)
        {
            if( v > aux->valor )
            {
                v = aux->valor;
            }

            aux = aux->sig;
        }
    }

    return v;
}
void freeList(listaDoble_t *lista)
{
    nodo_t *aux = NULL;
    if(!isEmpty(lista))
    {
        aux = lista->head;

        while(lista->head != NULL)
        {
            aux = aux->sig;
            free(lista->head);
            lista->head = aux;
        }
        lista->tail = NULL;
        lista->size=0;
    }

}

int main()
{

    listaDoble_t *miLista = crearListaDoble();

    printf("isEmpty() : %d \n\n",isEmpty(miLista));
    insertarAlInicio(miLista,1);
    printf("isEmpty() : %d \n\n",isEmpty(miLista));

    insertarAlFinal(miLista,2);
    insertarAlInicio(miLista,3);
    insertarAlFinal(miLista,4);
    insertarAlInicio(miLista,5);
    insertarAlFinal(miLista,6);
    insertarAlInicio(miLista,7);
    insertarAlFinal(miLista,8);
    insertarAlFinal(miLista,1);
    insertarAlFinal(miLista,8);
    insertarAlFinal(miLista,2);
    insertarAlFinal(miLista,8);
    insertarAlFinal(miLista,3);
    insertarAlFinal(miLista,8);

    printLista(miLista);

    printListaReversa(miLista);

    nodo_t *ap = search(miLista,5);

    if(ap!=NULL)
        printf("Valor encontrado en : %p %d\n\n",ap,ap->valor);
    else
        printf("No se encontro el num.\n\n");

    int apIndx = searchIndex(miLista,5);

    if(apIndx!=-1)
        printf("Valor 5 encontrado en la posicion: %d\n\n",apIndx);
    else
        printf("No se encontro el num.\n\n");

    printf("Lista antes de delete().\n\n");
    printLista(miLista);

    printf("delete 8 \n");
    delete(miLista, 8);
    printf("delete 80 \n");
    delete(miLista, 80);

    printf("deleteEnIndice 0 \n");
    deleteEnIndice(miLista, 0 );

    printf("Lista despues de delete().\n\n");
    printLista(miLista);


    printf("freeList() \n\n");
    freeList(miLista);

    printLista(miLista);

    printf("miLista->size : %d \n\n",miLista->size);
    printf(" isEmpty() : %d \n\n",isEmpty(miLista));

    int i;
    for(i=10; i>0; i--)
    {
        insertaEnIndice(miLista, i, miLista->size);
        printLista(miLista);
    }

    printf("min : %d \n\n",minimo(miLista));
    printf("max : %d \n\n",maximo(miLista));

    while(!isEmpty(miLista))
    {
        printf("deleteEnIndice \n\n");
        deleteEnIndice(miLista, miLista->size-1);
        printLista(miLista);
    }

    return(EXIT_SUCCESS);
}
