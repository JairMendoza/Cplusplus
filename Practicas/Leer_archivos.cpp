// Arturo Cueva Perez 
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>
#include<locale.h>

using namespace std;

FILE *pf;

void escribir ();
void leer ();
void gotoxy(int,int);

char caracter='\0';

int main ()
{

	int opcion;
	int salir = 1;
	
	do
	{	setlocale(LC_CTYPE, "Spanish");
		system("cls");
		gotoxy(40,5); cout<<"--------------MENU-----------\n"<<endl;
		gotoxy(40,6); cout<<"[1]  Escribir              "<<endl;
		gotoxy(40,7); cout<<"[2]  Leer               "<<endl;
		gotoxy(40,8);cout<<"[Esc] SALIR                         "<<endl;
		gotoxy(40,10);cout<<"INGRESE UNA OPCION: ";
		gotoxy(60,10);opcion=getch();
		
		switch(opcion)
		{
			case 49: //1
		
			system("cls");
			escribir ();	
			
		    break;

		    case 50: //2
		    
		    system("cls");
			leer ();
				
		    break;

			case 27: exit(-1);
		}
	}while(salir==1);
	return 0;
}


void escribir ()
{
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
}

void leer ()
{
	pf=fopen ("C:\\Users\\Arturo\\Desktop\\Dev c++ programas\\Registro_datos.cpp","r");		//abrir archivo para lectura
	if(pf==NULL)	//comprobar la apertura correcta del archivo
	{
		perror("ERROR");	//mensaje de error al usuario
		exit(0);	//salir del programa
	}
	printf("Precione una tecla para iniciar la lectura...\n");	//pausa
	caracter=getch();
	do	//hacer
	{
		caracter=fgetc(pf);	//leer caracter desde el archivo
		printf("%c",caracter);	//imprimir en pantalla el caracter
	}while(caracter!=EOF);	//mientras (caracter diferente de fin del archivo)
	fclose(pf);		//cerrar fichero
	system("pause");
}// fin de main

void gotoxy(int x,int y)
{  
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
}            
