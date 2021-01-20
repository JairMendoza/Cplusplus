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

// Declaro las funciones 
void dec_a_bin(long decimal, char *binario);
void impares_pares ();
void numeros_inferiores ();
void gotoxy(int,int);

// Variables globales para la funcion convertir entero a binario
long decimal; 
char binario[50]; 

int main ()
{

	int opcion;
	int salir = 1;
	
	do
	{
		system("cls");
		gotoxy(30,9);  cout<<"_____________________________MENU_____________________________  "<<endl;
		gotoxy(30,10); cout<<"[1] Convertir entero a binario     		   					  "<<endl;
		gotoxy(30,11); cout<<"[2] Encontrar cuantos son pares e impares    					  "<<endl;
		gotoxy(30,12); cout<<"[3] Imprimir los 10 primeros numeros enteros inferiores a N     "<<endl;
		gotoxy(30,13); cout<<"[Esc] SALIR                 									  "<<endl;
		gotoxy(30,15); cout<<"INGRESE UNA OPCION: "; fflush(stdin); // Funncion que limpia el bufer
		gotoxy(50,15); opcion=getch();
		
		switch(opcion) // llamamos las funciones en su respectivo case
		{
			case 49: //1
		    
		    system("cls");
		    cout << "Ingrese el numero a convertir: "; 
			cin >> decimal;
			
			dec_a_bin(decimal,binario);
			 
			cout << "\n\nEl numero Binario de: " << decimal << " es " << binario;  // datos de salida 
			getchar(); 
			getchar();	
			
		    break;
		    
			case 50: //2
		
			system("cls");
			impares_pares ();
			
		    break;

		    case 51: //3
		    
		    system("cls");
		    numeros_inferiores ();
				
		    break;

			case 27: exit(-1);
		}
	}while(salir==1);
	return 0;
}

void dec_a_bin(long decimal, char *binario) // inicio de la funcion
{
int x = 0, y = 0; // Declaramos variables que usaremos
int ban = 0; 
int aux; 
char temporal[80]; 

if (decimal < 0) // Validamos si el dato es menor o mayor para que pueda seguir la operacion
{ 
	decimal =- decimal; 
	ban = 1; 
} 
do 
{ 
	aux = decimal % 2;  // operaciones para hacer el cambio de decimal a binario
	decimal = decimal / 2;
	temporal[x++] = aux + '0'; 
}while (decimal > 0); 

while(x >= 0) 
binario[y++] = temporal[--x]; 
binario[y-1] = 0;
}


void impares_pares () // Inicio de la funcion
{
int cantida=5; // Rango permitido a introduccir
int aux[5]; // Auxiliar que me guarda temporalmete los numeros ingresados
int par=0,impar=0;

for (int i = 0; i < cantida; i++) // Comparamos y guardamos el numero en el auxiliar
{
	cout<<"ingresa un numero: ";
	cin>>aux[i];
}

for (int x = 0; x < cantida; x++) 
{
	if (aux[x]%2==0) // Operacion para dicidir sin son par o impares
	{
		par++;
	}
	else
	{	
		impar++;

	}
}
cout << "Los numeros pares son: " << par << endl; // Datos de salida
cout << "Los numeros impares son: " << impar << endl;

getch();
}


void numeros_inferiores ()
{
int numero,x,sumar; // Declaramos variables a usar 

cout << "Ingresa los numeros: ";
cin  >> numero;

for(x = numero; x >= numero-10; x--) // Rango maximo a imprimr y guadada en la variable x

cout << x << endl;
sumar = ((numero - 1) * 10) - 45; // Operacion para sumar todos los numeros desendiendo
cout << "El resultado de la suma es: " << sumar << endl; // Datos salida
getch();
}


void gotoxy(int x,int y) // Funcion para mover el menu
{  
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
}            

