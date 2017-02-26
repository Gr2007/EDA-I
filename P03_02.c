#include <stdio.h>
#include<string.h>

typedef struct asignatura {
	float b1,b2,b3,b4,b5,p;
}asignatura_t;

typedef struct alumno{
	unsigned char nombre[100], escuela[100];
	char grupo[100], turno[100], curp[100];
}alumno_t;

int main(){
    alumno_t alu1;
    asignatura_t e[6];

	strcpy(alu1.nombre,"Granados Johan");
	strcpy(alu1.escuela,"Enrique C. Rebsamen");
	strcpy(alu1.grupo,"6 'A'");
	strcpy(alu1.turno,"Matutino");
	strcpy(alu1.curp,"GGGGG5555c:");

	  e[0].b1=7;
	  e[1].b2=8;
	  e[2].b3=9;
	  e[3].b4=9;
	  e[4].b5=10;
	  e[6].p=(e[0].b1+e[1].b2+e[2].b3+e[3].b4+e[4].b5)/5;

	printf("DATOS DEL ALUMNO \n\tNombre: %s \n\tcurp: %s\n\nDATOS DE LA ESCUELA\n\tNombre de la escuela: %s\n\tGrupo: %s\tTurno: %s",alu1.nombre,alu1.curp,alu1.escuela,alu1.grupo,alu1.turno);
	printf("\n\n promedio: %2.f", e[6].p);
	getchar();
	return 0;
}
