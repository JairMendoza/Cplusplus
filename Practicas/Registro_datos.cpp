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

struct estudiante
{
	int matricula;
	char nombre [20];
	char domicilio [25];
	char carrera [20];
	int semetre;
	float promedio;
}estudiante1[10];

void gotoxy(int,int);

void insertar ();
void mostrar_g ();
void mostrar_c ();
void buscar_n ();

int indice;
int ban = 0;


int main ()
{
	int opcion;
	int salir = 1;
	
	do
	{	setlocale(LC_CTYPE, "Spanish");
		system("cls");
		gotoxy(40,5); cout<<"----------REGISTRO UTEG-----------\n"<<endl;
		gotoxy(40,6); cout<<"[1]  Añadir estudiante              "<<endl;
		gotoxy(40,7); cout<<"[2]  Consulta general               "<<endl;
		gotoxy(40,8); cout<<"[3]  Consulta por carrera           "<<endl;
		gotoxy(40,9); cout<<"[4]  Buscar estudiante           	 "<<endl;
		gotoxy(40,10);cout<<"[Esc] SALIR                         "<<endl;
		gotoxy(40,12);cout<<"INGRESE UNA OPCION: ";
		gotoxy(60,12);opcion=getch();
		
		switch(opcion)
		{
			case 49: //1
			
			//Añadir estudiante
			system("cls");
			insertar ();	
			
		    break;

		    case 50: //2
		    
		    // Consulta general
		    system("cls");
			mostrar_g ();
				
		    break;

		    case 51: //3
		    
		    // Consulta por carrera
		    system("cls");
			mostrar_c ();

			break;

			case 52: //4
			
			// Buscar estudiante
			
			system("cls");
			buscar_n ();

			break;
			
			case 27: exit(-1);
		}
	}while(salir==1);
	return 0;
}

void insertar ()
{
	for (indice=0; indice<10; indice++)
	{
    gotoxy(40,5);cout << "Introduce tu matricula: ",(indice+1); fflush(stdin);
	cin  >> estudiante1[indice].matricula;
	gotoxy(40,6);cout << "Introduce tu nombre: ",(indice+1); fflush(stdin);
	cin.getline(estudiante1[indice].nombre,20,'\n');
	gotoxy(40,7);cout << "Introduce tu domicilio: ",(indice+1); fflush(stdin);
	cin.getline(estudiante1[indice].domicilio,25,'\n');
	gotoxy(40,8);cout << "Introduce tu carrera: ",(indice+1); fflush(stdin);
	cin.getline(estudiante1[indice].carrera,20,'\n');
	gotoxy(40,9);cout << "Introduce el semestre: ",(indice+1); fflush(stdin);
	cin  >> estudiante1[indice].semetre;
	gotoxy(40,10);cout << "Introduce tu promedio: ",(indice+1); fflush(stdin);
	cin  >> estudiante1[indice].promedio;
	system("cls");
	do
	{
		gotoxy(40,8); cout << "Desea ingresar un nuevo registro?"; fflush(stdin);
		gotoxy(40,9); cout << " 1.- Si" << endl;
		gotoxy(40,10);cout << " 2.- No" << endl; 
	 	gotoxy(74,8);scanf("%d",&indice);
	 	system("cls");
    }while(indice<1||indice>2);
	if(indice==2)
	break;
	}
}

void mostrar_g ()
{
	for (indice=0; indice<3; indice++)
	{
	cout << "____________________________" << endl;
 	cout << "Matricula: " << estudiante1[indice].matricula   << endl;
 	cout << "Nombre: "    << estudiante1[indice].nombre      << endl;
 	cout << "Domicilio: " << estudiante1[indice].domicilio   << endl;
 	cout << "Carrera: "   << estudiante1[indice].carrera     << endl;
 	cout << "Semestre: "  << estudiante1[indice].semetre     << endl;
 	cout << "Promedio: "  << estudiante1[indice].promedio    << endl;
	}
	system("pause");
}

void mostrar_c ()
{
	/*int carre;
	
	cout << "Ingresa la carrera a buscar: " << endl;
	cin >> carre;
		for (indice=0; indice<3; indice++)
		{
			if (estudiante1[indice].carrera==carre)
			{
			ban=1;
			cout << "Matricula: " << estudiante1[indice].matricula   << endl;
 			cout << "Nombre: "    << estudiante1[indice].nombre      << endl;
 			cout << "Semestre: "  << estudiante1[indice].semetre     << endl;
 			cout << "Promedio: "  << estudiante1[indice].promedio    << endl;
			}          
		}
		if (ban==0)
		{
			cout << "No hay carreras registradas con esa asignatura!",carre;
			
		}
		system("pause");*/
}

void buscar_n ()                                                              
{
	/*int nombr;
	
	cout << "Ingresa el nombre del estudiante: " << endl;
	cin >> nombre;
		for (indice=0; indice<3; indice++)
		{
			if (estudiante1[indice].nombre==nombr)
			{
			ban=1;
			cout << "Matricula: " << estudiante1[indice].matricula   << endl;
			cout << "Nombre: "    << estudiante1[indice].nombre      << endl;
			cout << "Domicilio: " << estudiante1[indice].domicilio   << endl;
			cout << "Carrera: "   << estudiante1[indice].carrera     << endl;
			cout << "Semestre: "  << estudiante1[indice].semetre     << endl;
			cout << "Promedio: "  << estudiante1[indice].promedio    << endl;
			}          
		}
		if (ban==0)
		{
			cout << "No se encontro el estudiante!",nombr;
			
		}
		system("pause");*/                                 
         
}
	    
void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }                
