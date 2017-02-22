/*************************************************************************
Lee  una fecha en el formato dd-mm-año e imprimir su correspondiente valor
en formato largo (también es valido dd/mm/año)
EJ
Escribe una fecha: 01/01/2017
1 de enero de 2017
*************************************************************************/

#include <stdio.h>


int main(){
    int d,m,a;

    printf("\nIngrese la fecha en el formato dd/mm/aaaa: ");
    scanf("%d/%d/%d",&d,&m,&a);

    if(m==1){
    printf("\n Correspondiente valor en formato largo: %d de Enero de %d",d,a);
    }

    if(m==2){
    printf("\n Correspondiente valor en formato largo: %d de Febrero de %d",d,a);
    }

    if(m==3){
    printf("\n Correspondiente valor en formato largo: %d de Marzo de %d",d,a);
    }

    if(m==4){
    printf("\n Correspondiente valor en formato largo: %d de Abril de %d",d,a);
    }

    if(m==5){
    printf("\n Correspondiente valor en formato largo: %d de Mayo de %d",d,a);
    }

    if(m==6){
    printf("\n Correspondiente valor en formato largo: %d de Junio de %d",d,a);
    }

    if(m==7){
    printf("\n Correspondiente valor en formato largo: %d de Julio de %d",d,a);
    }

    if(m==8){
    printf("\n Correspondiente valor en formato largo: %d de Agosto de %d",d,a);
    }

    if(m==9){
    printf("\n Correspondiente valor en formato largo: %d de Septiembre de %d",d,a);
    }

    if(m==10){
    printf("\n Correspondiente valor en formato largo: %d de Octubre de %d",d,a);
    }

    if(m==11){
    printf("\n Correspondiente valor en formato largo: %d de Noviembre de %d",d,a);
    }

    if(m==12){
    printf("\n Correspondiente valor en formato largo: %d de Diciembre de %d",d,a);
    }
    getchar();
    getchar();
    return 0;

}
