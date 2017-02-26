/***********************************************************************
Diseñar un programa que utilice un Tipo de Dato Abstracto (TDA) para representar un punto de dos
coordenadas (x,y) en el Plano Euclídeo. Después generar una función para calcular la distancia euclidiana
entre dos puntos, a partir de la siguiente declaración de la función:
double distancia(punto_t a, punto_t b);
Generar la función que permita leer tres puntos para calcular el área y perímetro de un triángulo y
utilizando la función distancia(punto_t a, punto_t b).
double perimetro(punto_t a, punto_t b, punto_t c);
double area(punto_t a, punto_t b, punto_t c);
Nota: Puedes utilizar las funciones de math.h
double sqrt (double x)
double pow (double x, double y)
// raíz cuadrada.
// potencia. x^y
Utiliza typedef para definir un tipo de dato punto que contiene dos datos ‘x’ e ‘y’.
Utiliza la fórmula de Herón para el cálculo del área.
***********************************************************************/

#include <stdio.h>
#include <math.h>

typedef struct punto{
	double x,y;
} punto_t;

	double distancia(punto_t a, punto_t b);
	double perimetro(punto_t a, punto_t b, punto_t c);
	double area(punto_t a, punto_t b, punto_t c);

int main(){
	double d1,d2,d3,r;
	punto_t a,b,c;
        a.x=10;
        a.y=5;
        b.x=15;
        b.y=12;
        c.x=25;
        c.y=22;
	d1=distancia(a,b);
	d2=perimetro(a,b,c);
	d3=area(a,b,c);
	printf("la distancia entre puntos es %g \n",d1);
	printf("el perimetro del triangulo es %g \n",d2);
	printf("el area del triangulo es %g",d3);
	getchar ();
	return 0;
}

double distancia(punto_t a, punto_t b){
		double d;
	 	d= sqrt((pow(a.x-b.x,2))+ (pow(a.y-b.y,2)));
	return d;
}

double perimetro(punto_t a, punto_t b, punto_t c){
    double d1,d2,d3;
    	d1=distancia(a,b);
	d2=distancia(a,c);
	d3=distancia(c,b);
    d1=d1+d2+d3;
    return d1;
}

double area(punto_t a, punto_t b, punto_t c){
    double d1,d2,d3,r,s;
    	d1=distancia(a,b);
	d2=distancia(a,c);
	d3=distancia(c,b);
    r=((d1+d2+d3)/2);
    s= sqrt(r*(r-d1)*(r-d2)*(r-d3));
    return r;

}
