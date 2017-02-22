// E01_arreglos.c
#include<stdio.h>
#include<stdlib.h>

int  main(int argc, char *args[]) {

     char arreglo[10];
     int i=0;
     
     printf("\nIngrese la cadena: ");
     scanf ("%s",arreglo);
     
     printf("\n%s\n\n", arreglo);
		
		while(arreglo[i]!='\0')
		{
			printf ("%d		%c\n", arreglo[i], arreglo[i]);
			i++;
		}

     // 1) Lee una cadena desde el teclado  y asigna al arreglo
     //    incluyendo los espacios en blanco
     
     // 2) Imprime la cadena leida
     
     // 3) imprime letra por letra y su valor entero 
     //Ej: otoño
     //   (111) o
     //   (111) t
     //   (116) o
     
}
