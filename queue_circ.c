#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

typedef struct vuelo {
  char aerolinea[30];
  char num_vuelo[10];

  char destino[30];
  char hora_salida[6];
  char sala [4];
  char obs[20];
  char terminal[4];
}  vuelo_t;

typedef struct nodo
{
    vuelo_t *vuelo;
    struct nodo *sig;
} nodo_t;

typedef struct queue
{
    nodo_t *tail;
} queue_t;

void enqueue( queue_t *q , vuelo_t *v)
{
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));

    nuevo->vuelo = v;
     if(q->tail== NULL)
    {
	nuevo->sig=nuevo;
	q->tail = nuevo;
    }
    else
    {
        nuevo->sig   =q->tail->sig;
        q->tail->sig = nuevo;
        q->tail       = nuevo;
    }
}

vuelo_t *dequeue( queue_t *q  )
{
    vuelo_t *v_retorno = NULL;
    nodo_t *aux;

     if(q->tail != NULL )
    {
        v_retorno = (q->tail->sig)->vuelo;
        aux  = q->tail;

        if(q->tail->sig == q->tail)
        {
            q->tail = NULL;

        }
        else
        {
            q->tail->sig = aux->sig;
        }
        free(aux);
    }
    else
    {
        printf("Q vacia, error de  underflow \n");
    }

    return v_retorno;
}

void deleteQ(queue_t *q){
    nodo_t *aux = q->tail->sig;
    if (q->tail== NULL){
        printf( "No puede eliminar Nodos de una cola vacía." );
    }
    else{
        aux = aux->sig;
        q->tail->sig=aux;
    }


}
queue_t *crearQueue()
{
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->tail = NULL;
    return q;
}

void printQ(queue_t *q)
{
    if(q->tail!= NULL){
	nodo_t *aux = q->tail->sig;
    do
    {
        printf("%-30s",aux->vuelo->aerolinea);
        printf("%-10s",aux->vuelo->num_vuelo);
        printf("%-20s",aux->vuelo->destino);
        printf("%-6s",aux->vuelo->hora_salida);
        printf("%-4s",aux->vuelo->sala);
        printf("%-20s",aux->vuelo->obs);
        printf("%-4s",aux->vuelo->terminal);
        aux = aux->sig;
    }while(aux != q->tail->sig);}
}

void impVuelo(queue_t *q){
	nodo_t *aux=q->tail->sig;
	int i=0,a=0,x=0;
if(i==0){
	while(x<2){
		printf("\t\t SALIDAS AEROPUERTO INTERNACIONAL DE LA CDMX\n\n");
	for(a=0;a<5;a++){
        printf("%-30s",aux->vuelo->aerolinea);
        printf("%-10s",aux->vuelo->num_vuelo);
        printf("%-20s",aux->vuelo->destino);
        printf("%-6s",aux->vuelo->hora_salida);
        printf("%-4s",aux->vuelo->sala);
        printf("%-20s",aux->vuelo->obs);
        printf("%-4s",aux->vuelo->terminal);
	printf("\n");
	aux=aux->sig;
	  #ifdef _WIN32
        	Sleep(900);//para pausar
	  #else
        	usleep(900*1000);//para pausar
	  #endif
	}
  			#ifdef _WIN32
        		system("cls");
  			#else
  			system("clear");
  			#endif
		x++;
		}
	}
}

vuelo_t *leerInfo(){
	vuelo_t *v=(vuelo_t*)malloc(sizeof(vuelo_t));
	printf("Nombre de aerolinea: ");
	scanf("%s",v->aerolinea);
	printf("Numero de vuelo: ");
	scanf("%s",v->num_vuelo);
	printf("Destino: ");
	scanf("%s",v->destino);
	printf("Hora de salida: ");
	scanf("%s",v->hora_salida);
	printf("Sala: ");
	scanf("%s",v->sala);
	printf("Observaciones  On time | General Boarding |Final call: ");
	scanf("%s",v->obs);
	printf("Terminal: ");
	scanf("%s",v->terminal);
	return v;
}

vuelo_t *cargarDatos(  char aerolinea[],
  					   char num_vuelo[],
                       char destino[],
                       char hora_salida[],
                       char sala [],
                       char obs[],
                       char terminal[]){

	vuelo_t *v=(vuelo_t*)malloc(sizeof(vuelo_t));
	strcpy(v->aerolinea, aerolinea);
	strcpy(v->num_vuelo, num_vuelo);
	strcpy(v->destino, destino);
	strcpy(v->hora_salida, hora_salida);
	strcpy(v->sala, sala);
	strcpy(v->obs, obs);
	strcpy(v->terminal, terminal);
	return v;
}

int main()
{
    queue_t *q = crearQueue();
    enum opciones{ salir, insert, suprim, impTodos, continuar } opc;
	vuelo_t *v=(vuelo_t *)malloc(sizeof(vuelo_t));//funcion
    int eleccion,a=0;
	v=cargarDatos("AEROMEXICO","AM 2300","DF","08:00","30","On time","T1");
	enqueue(q,v);
	v=cargarDatos("DELTA","DEL 2300","MEXICALI","08:30","34","On time","T1");
	enqueue(q,v);
	v=cargarDatos("ALPHA","MS 2000","AUSTRALIA","08:05","31","General Boarding","T2");
	enqueue(q,v);
	v=cargarDatos("BETA","DOS 1111","ASTURIAS","08:25","67","Final call","T4");
	enqueue(q,v);
	v=cargarDatos("OMEGA","ARCH 2455","CANADA","09:00","50","On time","T1");
	enqueue(q,v);
	v=cargarDatos("GNOME","SHELL 326","DF","08:32","30","On time","T2");
	enqueue(q,v);
	v=cargarDatos("CINNAMON","STR 2008","TIJUANA","08:00","54","On time","T4");
	enqueue(q,v);
	v=cargarDatos("AMD","A8 2300","EUA","08:00","30","Final call","T1");
	enqueue(q,v);
	v=cargarDatos("STARK","GR 2007","MARTE","08:00","30","General Boarding","T7");
	enqueue(q,v);
	v=cargarDatos("DARK","GR 2070","NEPTUNO","08:00","30","General Boarding","T1");
	enqueue(q,v);
    impVuelo(q);
    impVuelo(q);
    	do{
		printf( "\n\n" );
		printf( "   1. Nuevo vuelo\n" );
		printf( "   2. Eliminar el primer vuelo\n" );
		printf( "   3. Muestra todos los vuelos\n" );
        printf( "   4. Continuar con la proyección\n" );
		printf( "   0. Salir del programa.\n" );
        do{
			scanf( "%i", &eleccion );
		} while( eleccion < 0  &&  eleccion > 12 );
		opc = (enum opciones)(eleccion);

		switch( opc )
		{
			case insert:
  			#ifdef _WIN32
        		system("cls");
  			#else
  			system("clear");
  			#endif
			v=leerInfo();
			enqueue( q, v );
			break;

			case suprim:
				deleteQ(q);
			break;

			case impTodos:
			#ifdef _WIN32
        		system("cls");
  			#else
  			system("clear");
  			#endif
				printQ( q );
			break;

            case continuar:
            #ifdef _WIN32
        		system("cls");
  			#else
  			system("clear");
  			#endif
				impVuelo(q);
				impVuelo(q);
			break;
			
			case salir:
				system("clear");
			break;
		}
	} while( opc != salir );

    return 0 ;
}
