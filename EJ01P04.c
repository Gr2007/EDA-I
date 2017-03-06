// EJ01P04.c
// Memoria dinámica
#include<stdio.h>
#include<stdlib.h>
int *crearConjunto(int tam);
void asignarValores(int *conjunto, int tam);
void imprimeValores(int *conjunto, int tam);
long promediarValores(int *conjunto, int tam);

void liberar(int *conunto);

int main()
{
    int tam = 0;
    int *a = NULL;

    printf("Escribe la longitud del conjunto: ");
    scanf("%d", &tam);

    a = crearConjunto(tam);
    asignarValores(a,tam);
    imprimeValores(a,tam);

    printf("promedio= %ld \n", promediarValores(a,tam));

    return 0;
}

int *crearConjunto(int tam)
{
    int *espacio = (int*) malloc(tam*sizeof(int));//creo arreglo del tamaño solicitado
    return espacio;//regreso el arreglo
}

void asignarValores(int *conjunto, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        conjunto[i] = rand();
    }
}

void imprimeValores(int *conjunto, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        printf("%d \n", conjunto[i]);
    }
}

long promediarValores(int *conjunto, int tam)
{
    int i = 0;
    int total = 0;
    long promedio = 0;
    for(i = 0; i < tam; i++)
    {
        total += conjunto[i];
    }
    promedio = total / tam;
    return promedio;
}

void liberar(int *conjunto)
{
    free(conjunto);
}
