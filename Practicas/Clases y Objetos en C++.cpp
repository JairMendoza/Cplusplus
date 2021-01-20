/*El siguiente código del programa correspondiente a la aplicación de clases, objetos, métodos.
En donde deberás de crear o modificar los métodos para que realice la lectura desde consola
con la respectiva impresión de los datos leídos del libro (nombre, cantidad de páginas, código).
INTEGRANTES: GABRIEL ADÁN ESTRADA ORTIZ, JORGE RICARDO TORRES PADILLA, ARTURO CUEVAS PÉREZ.
FECHA DE ELABORACION: 08/03/2018 9:30 pm */

// Librerias Necesarias
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<windows.h>

using namespace std;

// Inicializacion de la Clase
class Libro {
	public:
		Libro();
		void imprime();
		void escribir();
		char Menu (void);
		int tit  (char Titulo[40]);
		int codi (int Codigo);
		int pagi (int Cantpaginas);
	private:
		char Titulo[40];
		int Codigo;
		int Cantpaginas;
};// Fin de la Clase

// Variables Globales Necesarias
void Gotoxy(int,int);
int  lon = 0;
int  aux = 0;
int  ban = 0;

char Menu ()
{
	char op;
	setlocale(LC_CTYPE, "Spanish"); // Funcion que Adimite Simbolos Especiiales Como el Tilde
	system("cls");
	Gotoxy(45,12); cout << "   __________MENU__________   ";
	Gotoxy(45,13); cout << "         [F1] Escribir        ";
	Gotoxy(45,14); cout << "         [F2] Mostrar         ";
	Gotoxy(45,15); cout << "         [ESQ] Salir          ";
	Gotoxy(45,17); cout << "    INGRESE UNA OPCION: "; fflush(stdin);
	op = getch();
} 

int main ()
{
	Libro Manual; // Creo el Objeto Manual de Tipo libro
	
	char opcion;
	
	do
	{
		opcion = Menu();
		
		switch(opcion)
		{	
			case 59: //F1
		    system("cls"); 
			Manual.escribir(); break; // Ya las Funciones Especificadas de la Clase
		    
			case 60: //F2
			system("cls"); 
			Manual.imprime(); getch(); break;  // Ya las Funciones Especificadas de la Clase

			case 27: //ESC
			
			system("cls");
			Gotoxy(50,11); cout<<"¡Hasta la proxima!";
		}
	}while(opcion!=27);  
	return 0;
}
// Incializacion de las Variables Principales en 0 o Nulos Asi no Arrojar Basura 
Libro::Libro()
{
	for(int i = 0; i < 40; i++)
	Titulo[i]='\0'; 
	Cantpaginas=0;
	Codigo=0;
}

// Funcion Mostrar Datos
void Libro::imprime()
{
	Gotoxy(45,12); cout<<"Titulo: "<<Titulo<<endl;
	Gotoxy(45,13); cout<<"Codigo: "<<Codigo<<endl;
	Gotoxy(45,14); cout<<"Cant pag: "<<Cantpaginas<<endl;
}

// Funcion Capturar Datos
void Libro::escribir()
{
	do
	{	
	    cout<<"\nTitulo: "; fflush(stdin);
		gets(Titulo);
		if (tit(Titulo))
		{
			ban=1;
		}
		else
		{
			cout << "¡Dato Incorrecto!" << endl;
			ban=0;
		}
	}while (ban==0);
	
	do
	{	
		char cod [5];
	
	    cout<<"\nCodigo: "; fflush(stdin);
 		cin  >> cod;
		Codigo=atoi(cod);
		if (codi(Codigo))
		{
			ban=1;
		}
		else
		{
			cout << "¡Dato Incorrecto!" << endl;
			ban=0;
		}
	}while (ban==0);
	
	do
	{	
		char pag [4];
	
	    cout<<"\nCant pag: "; fflush(stdin);
 		cin  >> pag;
		Cantpaginas=atoi(pag);
		if (pagi(Cantpaginas))
		{
			ban=1;
		}
		else
		{
			cout << "¡Dato Incorrecto!" << endl;
			ban=0;
		}
	}while (ban==0);
}

// Validacion Titulo
int Libro::tit (char Titulo[40])
{
	int Letras = 0;
	if (strlen(Titulo) <= 20)
		for (int i = 0; i < strlen(Titulo); i++)

			if (!isalpha(Titulo[i]))
				Letras = 0;
			else 
				Letras = 1;

			if (Letras == 1)
				return 1;
			else
				return 0;
}
// Validacion Codigo
int Libro::codi (int Codigo)
{
	char cod [5];
	int  num1;
	
	itoa(Codigo,cod,10);
	
	if (strlen(cod) <= 5)
	{
		num1 = atoi(cod);
		if(num1 > 10000)
		{
			cout << "¡Codigo Fuera de Rango!\n";
			getch();
			return 0;
		}
		if (cod[0] == '0')
			return 0;
		for (int i = 0; i < strlen(cod); i++)
			if (!isdigit(cod[i]))
				return 0;
		return 1;
	}
	return 0;
}
// Validacion Cant. Paginas
int Libro::pagi (int Cantpaginas)
{
	char pag [4];
	int  num2;
	
	itoa(Cantpaginas,pag,10);
	
	if (strlen(pag) <= 4)
	{
		num2 = atoi(pag);
		if(num2 > 9000)
		{
			cout << "¡Limite Maximo de Paginas!\n";
			getch();
			return 0;
		}
		if (pag[0] == '0')
			return 0;
		for (int i = 0; i < strlen(pag); i++)
			if (!isdigit(pag[i]))
				return 0;
		return 1;
	}
	return 0;
}
// Fin Validaciones y Funciones Miembro

// Funcion Para Posicionar la Escritura
void Gotoxy(int x,int y)
{  
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
}
