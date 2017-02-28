/*******************************************************************
EDA I														2017-2
Granados Villeda Johan Raciel
Grupo 13

Crear un bloque de memoria para un conjunto de datos y   mostrar en  pantalla el detalle dicho
bloque
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main (){
	int *arreglo,*arreglo_tmp, num=5, cont;
arreglo = (int *)malloc (sizeof(int)*num);
//arreglo = (int *)calloc (sizeof(int),num); //para calloc
arreglo_tmp = (int *)malloc (num * sizeof(int));//para la pregunta 3

	printf("Registro de Memoria\n");
for (cont=0 ; cont < num ; cont++){
	printf("%p: %d \n",arreglo+cont,*(arreglo+cont));
}

	printf("\n\nRegistro de Memoria\n");

num *= 3;
int *arreglo2 = (int *)realloc (arreglo,num*sizeof(int));
for (cont=0 ; cont < num ; cont++){
    *(arreglo2+cont)=0;
printf("%p: %d \n",arreglo2+cont,*(arreglo2+cont));
}

free(arreglo2);

getchar ();
return 0;
}
