#include <stdio.h>
#include <stdlib.h>


int main ( int argc, char **argv ){

    FILE *archivo;
	char *palabras[1000],*aux;//declaro el arreglo palabaras que usare como indice
	//aux lo usare para recorrer mi arreglo master
    char caracter;//para abrir y recorrer el documento
    int saltoPrev=0,cont=0,i=0,a=0,x;
    /*
    Usare a cont como mi auxiliar para saber cuantos caracteres tiene mi texto y asi poder generar a master
    Usare a i para ciclos, a serÃ¡ un auxiliar contador, x es una variable
    */

    archivo = fopen ( "historiaC.txt", "r" );

    while( ( caracter = fgetc( archivo ) ) != EOF ){//ciclo para contar cuantos caracteres componen al archivo
		cont++;//contador para caracteres
	}
	char *master=(char *)malloc(sizeof(char)*cont);
	/*
	Genero a master para guardar los caracteres del texto,
	no desperdicio memoria por que el arreglo sera justo para los elementos del archivo
	*/
	   fclose( archivo);

    archivo = fopen ( "historiaC.txt", "r" );
    saltoPrev ='x';


    while (feof(archivo) == 0)
    {
        caracter = fgetc(archivo);

        if( caracter==' '||caracter=='.'||caracter==','||
            caracter==';'||caracter==':'||caracter=='"'||
            caracter=='('||caracter==')'||caracter=='['||
            caracter==']'||caracter=='/'||caracter=='\\'||
            caracter=='\n'||caracter=='\r'||caracter==EOF)
        {
            if(saltoPrev!=1)
            {
            	palabras[a]=&master[i];//aÃ±ado un indice donde acaba la palabra
                saltoPrev=1;
                a++;//recorro palabras en 1
                i++;//para recorrer el arreglo master
            }
        }
        else
        {
        	master[i]=caracter;//agrego el caracter al arreglo master
            saltoPrev=0;
            i++;//para recorrer el arreglo master
        }
    }
    aux=&master[0];//apunto aux a master para comparar direccion de memoria
    x=0;//los inicializo por que los usare como auxiliares
    a=0;


	for(i=0;i<cont;i++){//ciclo para imprimir en forma de matriz

        if(a<=4){//la condicional funciona para solo imprimir cuatro palabras en una linea
            if(aux==palabras[x]){
            /*
            Sirve para dar espacios, si la direccion a la que apunta aux es igual al indice,
            significa que ahi hay un espacio
            */
            x++;//recorro el indice
            a++;//cuantas palabras a escrito
                if(a==4){
                /*
                Si ya escribio las 4 palabras no necesita continuar
                el caracter que indica el indice, eso es hasta el salto de linea
                */
                printf("\t");
                }
                if(a<4){
                /*
                Como aun no ah escrito las 4 palabras debe continuar con el caracter que indica
                el indice, de lo contrario omite el caracter del indice
                */
                printf("\t%c",master[i]);
                }

            }
            else {//si no esta en un indice entonces no necesita dar saltos de linea
                printf("%c",master[i]);
                 }
            }//cierro la condicional de linea
        if(a==4){//condicional para salto de linea
                /*
                Cuando a es igual a 4 significa que ya escrio cuatro palabras, por lo tanto
                necesita dar un salto de linea y a su vez imprimir el caracter del indice
                */
                printf("\n%c",master[i]);
                a=0;//reinicio el contador de palabras
                }//cierro la condicional de salto d elinea
	*aux++;//recorro mi auxiliar que apunta a master
                    }//cierro ciclo for

    fclose ( archivo );//cierro el archivo

    return 0;//termino la ejecucion
}//cierro funcion principal


