#include <stdio.h>
#include <stdlib.h>
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
	struct nodo *aux_ant;
	struct nodo *aux_sig;
}nodo_t;

typedef struct queue
{
	int nodos;
	nodo_t *head;
	nodo_t *tail;
} queue_t;

void crearQueue( queue_t **q ){
	queue_t *aux = (queue_t *) malloc(sizeof(queue_t));
	aux->head = NULL;
	aux->tail = NULL;
	(*q) = aux;}

void insertIzqQueue( queue_t **q, vuelo_t *dato ){
	nodo_t *aux = (nodo_t *) malloc(sizeof(nodo_t));
	if( (*q)->head == NULL ){
		aux->vuelo = dato;
		aux->aux_ant = NULL;
		aux->aux_sig = NULL;
		(*q)->head = aux;
		(*q)->tail = aux;}
	else{
		aux->vuelo = dato;
		aux->aux_ant = NULL;
		aux->aux_sig = (*q)->head;
		(*q)->head->aux_ant = aux;
		(*q)->head = aux;}
	(*q)->nodos += 1;
}

void insertDerQueue( queue_t **q, vuelo_t *dato ){
	nodo_t *aux = (nodo_t *) malloc(sizeof(nodo_t));
	if( (*q)->head == NULL ){
		aux->vuelo = dato;
		aux->aux_ant = NULL;
		aux->aux_sig = NULL;
		(*q)->head = aux;
		(*q)->tail = aux;}
	else{
		aux->vuelo  = dato;
		aux->aux_ant = (*q)->tail;
		aux->aux_sig = NULL;
		(*q)->tail->aux_sig = aux;
		(*q)->tail = aux;}
	(*q)->nodos += 1;
}

void deleteIzqQueue( queue_t **q ){
	nodo_t *aux;

	if( (*q)->head == NULL ){
		printf( "No puede eliminar vuelos de una cola vacía.\n" );}
	else if( (*q)->nodos == 1 ){
		free(*q);
		crearQueue(q);}
	else if( (*q)->nodos > 1 ){
		aux = (*q)->head;
		(*q)->head->aux_sig->aux_ant = NULL;
		(*q)->head = (*q)->head->aux_sig;
		free(aux);
		(*q)->nodos -= 1;}
}

void deleteDerQueue(queue_t **q){
	nodo_t *aux;
	if( (*q)->head == NULL ){
		printf( "No puede eliminar Nodos de una cola vacía." );}
	else if( (*q)->nodos == 1 ){
		free(*q);
		crearQueue(q);}
	else if( (*q)->nodos > 1 ){
		aux = (*q)->tail;
		(*q)->tail->aux_ant->aux_sig = NULL;
		(*q)->tail = (*q)->tail->aux_ant;
		free(aux);
		(*q)->nodos -= 1;}
}

void printQ( queue_t **q ){
	nodo_t *aux = (*q)->head;
	if(aux == NULL)
		printf( "La cola no contiene Nodos." );
	else{
		while( aux != NULL ){
	printf("%-30s",aux->vuelo->aerolinea);
        printf("%-10s",aux->vuelo->num_vuelo);
        printf("%-20s",aux->vuelo->destino);
        printf("%-6s",aux->vuelo->hora_salida);
        printf("%-4s",aux->vuelo->sala);
        printf("%-20s",aux->vuelo->obs);
        printf("%-4s",aux->vuelo->terminal);
	aux = aux->aux_sig;
	}
		printf( "\n\n" );
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
	printf("Observaciones On_time|General_Boarding|Final_call: ");
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

void impVuelo(queue_t *q){
	nodo_t *aux=q->head;
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
	aux=aux->aux_sig;
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

int main()
{

	enum opciones{ salir, insertIzq, insertDer, eliminaIzq, eliminaDer,impTodos, continuar } opc;
	queue_t *q;
	crearQueue( &q );
	int eleccion,a=0;
	vuelo_t *v=(vuelo_t *)malloc(sizeof(vuelo_t));//funcion

	v=cargarDatos("AEROMEXICO","AM 2300","DF","08:00","30","On time","T1");
	insertDerQueue(&q,v);
	v=cargarDatos("DELTA","DEL 2300","DF","08:00","30","On time","T1");
	insertDerQueue(&q,v);
	v=cargarDatos("ALPHA","MS 2000","AUSTRALIA","08:05","31","General Boarding","T2");
	insertDerQueue(&q,v);
	v=cargarDatos("BETA","DOS 1111","ASTURIAS","08:25","67","Final call","T4");
	insertDerQueue(&q,v);
	v=cargarDatos("OMEGA","ARCH 2455","CANADA","09:00","50","On time","T1");
	insertDerQueue(&q,v);
	v=cargarDatos("GNOME","SHELL 326","DF","08:32","30","On time","T2");
	insertDerQueue(&q,v);
	v=cargarDatos("CINNAMON","STR 2008","TIJUANA","08:00","54","On time","T4");
	insertDerQueue(&q,v);
	v=cargarDatos("AMD","A8 2300","EUA","08:00","30","Final call","T1");
	insertDerQueue(&q,v);
	v=cargarDatos("STARK","GR 2007","MARTE","08:00","30","General Boarding","T7");
	insertDerQueue(&q,v);
	v=cargarDatos("DARK","GR 2070","NEPTUNO","08:00","30","General Boarding","T1");
	insertDerQueue(&q,v);
	//printQ( &q );
	impVuelo(q);
	impVuelo(q);
	do{
		printf( "\n\n" );
		printf( "   1. Nuevo vuelo al principio\n" );
		printf( "   2. Nuevo vuelo al final\n" );
		printf( "   3. Eliminar el primer vuelo\n" );
		printf( "   4. Eliminar el ultimo vuelo\n" );
		printf( "   5. Muestra todos los vuelos\n" );
        	printf( "   6. Continuar con la proyección\n" );
		printf( "   0. Salir del programa.\n" );

		do{
			scanf( "%i", &eleccion );
		} while( eleccion < 0  &&  eleccion > 12 );
		opc = (enum opciones)(eleccion);

		switch( opc )
		{
			case insertIzq:
  			#ifdef _WIN32
        		system("cls");
  			#else
  			system("clear");
  			#endif
			v=leerInfo();
			insertIzqQueue( &q, v );
			break;

			case insertDer:
  			#ifdef _WIN32
        		system("cls");
  			#else
  			system("clear");
  			#endif
			v=leerInfo();
			insertDerQueue( &q, v);
			break;

			case eliminaIzq:
				deleteIzqQueue( &q );
			break;

			case eliminaDer:
				deleteDerQueue( &q );
			break;

			case impTodos:
			#ifdef _WIN32
        		system("cls");
  			#else
  			system("clear");
  			#endif
				printQ( &q );
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

}
