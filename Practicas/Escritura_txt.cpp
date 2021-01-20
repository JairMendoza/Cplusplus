#include<conio.h>
#include<iostream>

using namespace std;

FILE *pf;

int main(void){

	char caracter='\0';
	
	pf=fopen("Archivo1.txt","w");
	if(pf==NULL){
		perror("No fue posible crear el archivo para escribir");
		exit(0);
	}
	
	printf("Ingrese el texto a escribir en el archivo , presione ESC para terminar...\n");
	
	do{
		caracter=getche();
		
		if(caracter!=27&&caracter!=8){
		fputc(caracter,pf);
	}
	if(caracter==13){
		fprintf(pf,"/r/n");
		cout<<endl;
	}
}while(caracter!=27);
	fclose(pf);
	return 0;
}//fin del main

