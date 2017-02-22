 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 struct direccion{//estructura direccion
	unsigned char calle[100];//para ASCII extendido
	int numOficina[15];//arreglo para numero
	unsigned char colonia[100];//para ASCII extendido
	int codigo[10];//arreglo para codigo
	unsigned char municipio[100];//para ASCII extendido
	unsigned char estado[100];//para ASCII extendido
};

 struct  profesional{/7estructura profesinal
	 char cargo[100];//no se necesitara de ASCII extendido
	 char departamento[100];//no se necesitara de ASCII extendido
	unsigned char correo[100];//para ASCII extendido
	unsigned char pagWeb[100];//para ASCII extendido
};


 struct familiar{//estructura familiar
	 char cumpleaños[20];//no se necesita ASCII extendido
	 char tipoSangre[4];//no se necesita ASCII extendido
};


 struct contacto{//estructura contacto
 		unsigned char nombre[100];//para ASCII extendido
		unsigned char alias[100];//para ASCII extendido
		int num[15];//arreglo para numero
		unsigned char correo[100];//para ASCII extendido
	struct direccion *particular; //apuntador a la estructura direccion
	struct direccion *oficina;//apuntador a la estructura direccion
	struct profesional *dat_pro;//apuntador a la estructura profesional
	struct familiar *dat_fam;//apuntador a la estructura familiar

};


int main() {//abro funcion principal

	struct contacto persona1; //creo una estructura contacto con el nombre persona1

	//asignacion de cadenas 
	//strcpy(persona1.nombre,"Johan");

	persona1.particular=NULL;//inicio el apuntador particular de la estructura persona de tipo 					 //contacto en NULL (no lo usare)
	persona1.oficina=(struct direccion *)malloc(sizeof(struct direccion));//creo el apuntador de 							//direccionde la estructura persona de tipo
						//contacto en NULL (no lo usare)
	strcpy(persona1.oficina->calle,"Av Universidad");

	printf("%s \n",persona1.oficina->calle);
	
	free(persona1.oficina);//libera memoria usada por la estructura oficina

/*
	persona1.dat_pro=NULL;
	persona1.dat_fam=NULL;
	struct contacto *punt;
	
	punt=&persona1;
	strcpy ( punt->nombre, "Johan" );
	strcpy ( punt->alias, "Gr2" );
	punt->num= '5545800469';
	strcpy ( punt->alias, "gvjohan99@gmail.com" );*/
	


	
	return 0; 
}

