/*
* EDA I
* Arreola Salazar Belen 
* Granados Villeda Johan Raciel
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

char *password = "eda";
char *nom_examen ="examen.txt";
char *nom_examen2 = "examen2.txt";

typedef struct reactivo
{
    char pregunta[100];
    char opc1[100];
    char opc2[100];
    char opc3[100];
    char opCorrecta[4];
    char opUsuario[4];

} reactivo_t;

typedef struct  nodo
{
    reactivo_t  *reactivo;
    struct nodo *sig;
} nodo_t;

typedef struct list
{
    nodo_t *head;
    nodo_t *ptr;
    int total;
    int correctas;
} lista_t;

lista_t *crearLista()
{
    lista_t *lista = malloc(sizeof(lista_t));

    lista->head = NULL;
    lista->ptr  = NULL;
    lista->total =0;
    lista->correctas =0;
    return lista;
}

int isEmpty(lista_t *l)
{
    int regreso;
    if(l->head == NULL)
    {
        regreso = 1;
    }
    else
    {
        regreso = 0;
    }

    return regreso;
}

void freeList(lista_t *lista)
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
    }

}

void insertarAlFinal(lista_t *l, reactivo_t *v)
{

    nodo_t *n =(nodo_t*)malloc(sizeof(nodo_t));

    n->reactivo =v;
    n->sig = NULL;

    if( isEmpty(l) )
    {
        l->head = n;
    }
    else
    {
        l->ptr = l->head;
        while(l->ptr->sig != NULL)
        {
            l->ptr = l->ptr->sig;
        }
        l->ptr->sig = n;
    }
    l->total++;
}

void pausa(int pollingDelay)
{
//sleep:
#ifdef _WIN32
    Sleep(pollingDelay);
#else
    // unix/linux
    usleep(pollingDelay*1000);  /* sleep for 100 milliSeconds */
#endif
}

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    // unix/linux
    system("clear");
#endif
}

void esperaEnter()
{
    printf("Enter para continuar...\n");
    setbuf(stdin,NULL);
    getchar();
}


void printPregunta(int c, nodo_t *aux){
    printf("%d.- %s \n\n",c,aux->reactivo->pregunta);
    printf("1) %s \n",aux->reactivo->opc1);
    printf("2) %s \n",aux->reactivo->opc2);
    printf("3) %s \n",aux->reactivo->opc3);
    printf("\nRespuesta [1 ,2 ,3 ]: ");
}

void printLista(lista_t *l)
{
    if(!isEmpty(l))
    {
        int c=1;
        nodo_t *aux = l->head;
        while(aux != NULL)
        {
            printPregunta(c++, aux);
            aux = aux->sig;
        }
    }

}

float contestar(lista_t *l)
{
    float calificacion = 0;
    if(!isEmpty(l))
    {
        int c=1;
        char *a;
        nodo_t *aux = l->head;
        while(aux != NULL)
        {
            printf("\n");
            printPregunta(c++, aux);
            fflush(stdin);
            scanf("%s",aux->reactivo->opUsuario);
            printf("\n\n");
            if((aux->reactivo->opCorrecta[0]) == (aux->reactivo->opUsuario[0])){
                calificacion++;
            }
            aux = aux->sig;
        }
        l->correctas=calificacion;
        calificacion= ((l->correctas)*10)/(l->total);
    }
    return calificacion;
}

void printExamenResuelto(lista_t *l)
{
    float calificacion=0;
    int c=1;
    nodo_t *aux = l->head;
    while(aux != NULL)
        {
            printf("%d.- %s \n\n",c,aux->reactivo->pregunta);
            printf("1) %s \n",aux->reactivo->opc1);
            printf("2) %s \n",aux->reactivo->opc2);
            printf("3) %s \n",aux->reactivo->opc3);
            printf("\nTu respuesta fue : ");
            printf(" %s \n",aux->reactivo->opUsuario);
            printf("\n\n");
            aux = aux->sig;
            c++;
        }
        calificacion= ((l->correctas)*10)/(l->total);
    printf(" %.2f \n",calificacion);
}

lista_t *leerArchivo(char *nom_archivo)
{
    FILE *archivo;

    char linea[500];
    char *separador = "|\n";
    // token es un apuntador a cadena que va a indicar el inicio de cada palabra encontrada
    // y se va a modificar conforme encuentre una nueva palabra.
    char *token;

    lista_t *lista = crearLista();

    archivo = fopen ( nom_archivo, "r" );

    reactivo_t *r;


    // Para cada linea leida del archivo
    while (feof(archivo) == 0)
    {
        // Leer una linea completa del archivo
        fgets(linea,sizeof(linea),archivo);
        linea[strlen(linea)-1]='\0';
        token = strtok(linea,separador);

        if(token != NULL)
        {
            r = (reactivo_t*)malloc(sizeof(reactivo_t));

            strcpy(r->pregunta,token);

            token = strtok(NULL, separador);
            strcpy(r->opc1,token);

            token = strtok(NULL, separador);
            strcpy(r->opc2,token);

            token = strtok(NULL, separador);
            strcpy(r->opc3,token);

            token = strtok(NULL, separador);
            strcpy(r->opCorrecta,token);

            insertarAlFinal(lista,r);
        }
    }

    fclose ( archivo );

    return lista;
}

void borrarPregunta(lista_t *l, int indx){
	FILE *archivo;
	int a=1;
	nodo_t *aux=l->head;
	archivo = fopen ( "examen2.txt", "wt" );
	while(a<indx)
	{
	fprintf(archivo,"%s|%s|%s|%s|%s\n",aux->reactivo->pregunta,aux->reactivo->opc1,aux->reactivo->opc2,aux->reactivo->opc3,aux->reactivo->opCorrecta);
	aux = aux->sig;
    a++;
    }
    aux=aux->sig;
    a++;
    if(aux!=NULL)
	{
    	while(aux != NULL)
		{
    		fprintf(archivo,"%s|%s|%s|%s|%s\n",aux->reactivo->pregunta,aux->reactivo->opc1,aux->reactivo->opc2,aux->reactivo->opc3,aux->reactivo->opCorrecta);
			aux = aux->sig;
    	}
	}
	fprintf(archivo,"\n");
    fclose(archivo);
    
	if(remove(nom_examen)==0) // Eliminamos el archivo
        printf("El archivo fue eliminado satisfactoriamente\n");
    else
        printf("No se pudo eliminar el archivo\n");
    if(rename(nom_examen2,nom_examen)==0)// Renombramos el archivo
        printf("El archivo se renombro satisfactoriamente\n");
    else
        printf("No se pudo renombrar el archivo\n");

}

void mostrarPreguntas(lista_t *l){
	int c=1;
	nodo_t *aux=l->head;
	while(aux!=NULL)
	{
	printf("%d.- %s \n\n",c,aux->reactivo->pregunta);
	 aux = aux->sig;
    c++;
    }
}

void mostrarExamenResps(lista_t *l)
{
    int c=1;
    nodo_t *aux = l->head;
    while(aux != NULL)
        {
            printf("%d.- %s \n\n",c,aux->reactivo->pregunta);
            printf("1) %s \n",aux->reactivo->opc1);
            printf("2) %s \n",aux->reactivo->opc2);
            printf("3) %s \n",aux->reactivo->opc3);
            printf("\nRespuesta correcta : ");
            printf(" %s \n",aux->reactivo->opCorrecta);
            printf("\n\n");
            aux = aux->sig;
            c++;
        }
}

reactivo_t *leerInfo(){
	reactivo_t *r=(reactivo_t*)malloc(sizeof(reactivo_t));
	printf("\n Ingrese la pregunta: ");
	scanf( " %[^\n]",r->pregunta);
	printf("Ingrese reactivo 1: ");
	scanf( " %[^\n]",r->opc1);
	printf("Ingrese reactivo 2: ");
	scanf( " %[^\n]",r->opc2);
	printf("Ingrese reactivo 3: ");
	scanf( " %[^\n]",r->opc3);
	printf("Ingrese opcion correcta: ");
	scanf( " %[^\n]",r->opCorrecta);
	return r;
}

void guardarArchivo(reactivo_t *r){
    FILE *archivo;
    archivo = fopen ( nom_examen, "a" );
    fprintf(archivo,"%s|%s|%s|%s|%s\n\n",r->pregunta,r->opc1,r->opc2,r->opc3,r->opCorrecta);
    fclose(archivo);
}

void registrarPregunta(lista_t *l)
{
	limpiarPantalla();
	printf("\n MENU PARA REGISTRAR PREGUNTA");
    reactivo_t *n;
    getchar();
    n=leerInfo();
    guardarArchivo(n);
    freeList(l);
	l=leerArchivo(nom_examen);
    mostrarExamenResps(l);
    esperaEnter();
}

void eliminarPregunta(lista_t *l)
{
	limpiarPantalla();
	printf("\n MENU PARA ELIMINAR PREGUNTA");
	int a;
    mostrarPreguntas(l);
    printf("Ingrese el numero de pregunta a eliminar: \n");
    scanf("%d",&a);
    borrarPregunta(l,a);
    freeList(l);
    l=leerArchivo(nom_examen);
    mostrarExamenResps(l);
    esperaEnter();
}

int menuAlumno()
{
    int opc;
    limpiarPantalla();
    printf("\n\n\tMenu del Alumno\n\n");
    printf("1) Contestar examen\n");
    printf("2) Mostrar la revision\n");
    printf("3) Menu para el profesor\n");
    printf("4) Salir\n");
    fflush(stdin);
    scanf("%d",&opc);
    return opc;
}
int menuProfesor()
{
    int opc;
    limpiarPantalla();
    printf("\n\n\tMenu del profesor\n\n");
    printf("1) Agregar pregunta al examen\n");
    printf("2) Eliminar pregunta al examen\n");
    printf("3) Mostar examen, incluidas la respuestas\n");
    printf("4) Salir\n");
    fflush(stdin);
    scanf("%d",&opc);
    return opc;
}

void subMenuProfesor(lista_t *l)
{

    int opc, continuar=1;
    char clave[20];
    printf("Clave del submenu [%s]:",password);
    scanf("%s",clave);

    if(strcmp(password,clave)!=0)
    {
        continuar =0;
        printf("Clave incorrecta\n");
        pausa(600);
    }

    while(continuar)
    {
        opc = menuProfesor();
        switch(opc)
        {
        case 1:
        	l = leerArchivo(nom_examen);
            registrarPregunta(l);
            break;
        case 2:
        	l = leerArchivo(nom_examen);
            eliminarPregunta(l);
            break;
        case 3:
        	l = leerArchivo(nom_examen);
            mostrarExamenResps(l);
            esperaEnter();
            break;
        case 4:
            continuar =0;
            break;
        default:
            printf("Opcion no valida\n");
            pausa(300);
        }
    }

}

int main()
{
    int opc, continuar=1;

    lista_t *examen= leerArchivo(nom_examen);

    while(continuar)
    {
        opc = menuAlumno();
        switch(opc)
        {
        case 1:
        	examen = leerArchivo(nom_examen);
            printf("\n\tCalificacion %.2f \n", contestar(examen) );
            esperaEnter();
            break;
        case 2:
        	//examen = leerArchivo(nom_examen);
            printExamenResuelto(examen);
            esperaEnter();
            break;
        case 3:
            subMenuProfesor(examen);
            break;
        case 4:
            continuar =0;
            break;
        default:
            printf("Opcion no valida\n");
            pausa(300);
        }
    }
    return 0;
}
