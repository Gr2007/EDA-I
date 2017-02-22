// E03_matriz
#include<stdio.h>
#include<stdlib.h>

double matrizGlobal[10][10];

void crearMatriz(int nl,int nc);

int  main(int argc, char *args[]) {
	int num,i,j,a=0,num2;
	
	printf("\nIngrese un numero entre 2 y 10: ");
	scanf("%d", &num);
	while (num<2 || num>10){
		printf("\n numero fuera del rango, ingrese un numero valido: ");
		scanf("%d", &num);
	}

	num2=num;
	num=num*num;
	 for(i=0;i<num2;i++){
		for(j=0;j<num2;j++){
	if(a<num){
		matrizGlobal[i][j]=a;
		a++;
	}
	}
   }


 	for(i=0;i<num2;i++){//abro ciclo que recorre renglones
		for(j=0;j<num2;j++){//abro ciclo que recorre columnas
		  printf("\t%g",matrizGlobal[i][j]);//imprimo matriz
		 }//cierro segundo for
	  printf("\t\n");//espacio para impresion
  	 }//cierro primer for


	printf("\nIngrese un numero entre 2 y 10: ");
	scanf("%d", &num);
	while (num<2 || num>10){
		printf("\n numero fuera del rango, ingrese un numero valido: ");
		scanf("%d", &num);
	}

	num2=num;
	crearMatriz(num,num);

//   6) Imprimir la matriz dentro de crearMatriz()
 	
	 /*for(i=0;i<num2;i++){//abro ciclo que recorre renglones
		for(j=0;j<num2;j++){//abro ciclo que recorre columnas
		  printf("\t%g",matrizGlobal[i][j]);//imprimo matriz
		 }//cierro segundo for
	  printf("\t\n");//espacio para impresion
  	 }//cierro segundo for*/
  	 
  	  	for(i=0;i<num2;i++){//abro ciclo que recorre renglones
		for(j=num2;j>=0;j--){//abro ciclo que recorre columnas
		if(j!=num2){
		  printf("\t%g",matrizGlobal[i][j]);//imprimo matriz
		}
		 }//cierro segundo for
	  printf("\t\n");//espacio para impresion
  	 }//cierro primer for
}

void crearMatriz(int dl,int dc){
     double matrizLocal[dl][dc];
     int num2,a,i,j;
	num2=dl;
	dl=dc*dc;
	a=dl-1;
	 for(i=0;i<num2;i++){//abro ciclo que recorre renglones
		for(j=0;j<num2;j++){//abro ciclo que recorre columnas
	if(a>=0){
		matrizGlobal[i][j]=a;
		a=a-1;
			}
		}
   }//cierro primer for
}
