#include<stdio.h>

int  main() {
double *apFlotanteDoble;
double arreglo[4];
int i=0,a=0;

apFlotanteDoble=&arreglo[0];
		printf("Ingrese 4 numeros: \n");
	for(i=3;i>=0;i--){
		printf("\nIngrese el numero %d: ",a+1);
		scanf("%lf",&apFlotanteDoble[i]);
	a++;
	}
	printf("\n nuevo orden: \n");
	printf("%lf ",apFlotanteDoble[1]);
		printf("%lf ",apFlotanteDoble[3]);
			printf("%lf ",apFlotanteDoble[0]);
				printf("%lf ",apFlotanteDoble[2]);
	
	printf("\n\n Orden original en el que se registraro: \n");
	for(i=0;i<=4;i++){
		printf("%lf ",apFlotanteDoble[i]);
	}	
	
	i=sizeof(arreglo);
	printf ("\n\n Bytes utilizados para tener los datos registrados: %d",i);

	/*printf("\n Orden en el que se ingreso: \n");
	for(i=3;i>=0;i--){
		printf("%lf ",apFlotanteDoble[i]);
	}*/
// Diseña un programa que permita leer cuatro numeros de tipo double,
// adicional se require que esten registrados en el orden [3,2,1,0]
// y tambien en el orden [1,3,0,2]

// - No se permite dupiclar los números registrados
// - La asignación para apFlotanteDoble solo se puede hacer una sola vez

//  1) Lee los valores decimales por medio de 'apFlotanteDoble'
       

// 2) imprime los números en el nuevo orden
//    y después en el orden original en que se registraron

// 3) Cuenta cuantos bytes se utilizan para tener los datos registrados
//    es las dos lista ordenas.
getchar();
getchar();
return 0;
}
