/*******************************************************************
EDA I														2017-2
Granados Villeda Johan Raciel 
Grupo 13 
Escribir un programa que cree una matriz de caracteres de 16x16 , 
iniciar  la matriz con un n�mero del 0 al 255, despu�s imprime  esa 
matriz utilizando solo un apuntador y un s�lo ciclo de repetici�n, 
en el siguiente formato :
	<direcci�n>  : <valor num�rico>  <car�cter>  
*******************************************************************/
#include <stdio.h>
int main(){
	unsigned char m[16][16], *apu,i;
	int a;
    printf("Ingrese un numero del 0 al 255: \n");
    scanf("%d",&a);
    m[0][0]=a;
	apu= &m[0][0];
    for(i=0;i<256-a;i++){
    	*apu=a+i;
    	printf(" %p: %d  %c\n",(apu+i),*apu,*apu);
    	
    }
    getchar();
    getchar();
    return 0;
}
