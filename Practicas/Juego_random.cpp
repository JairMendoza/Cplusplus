// Arturo Cueva Perez 
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>
#include<locale.h>
#include<time.h>

using namespace std;


void gotoxy(int,int);

int Dado1;
int Dado2;
int Total_da;
int Puntos;
int Dinero = 5000;
char Apuesta [6];
char Tirada;
char opcion;

int ban = 0;
int lon=0;
int aux=0;
int valor=-1;


int main ()
{

	int salir = 1;
	
	do
	{	setlocale(LC_CTYPE, "Spanish");
		system("cls");
		gotoxy(40,5); cout<<"----------------MENU----------------"<<endl;
		gotoxy(40,6); cout<<"[1].-Apostar entre $1 - $999        "<<endl;
		gotoxy(40,7); cout<<"[2].-Apostar entre $1000 - $4999    "<<endl;
		gotoxy(40,8); cout<<"[3].-Apostar entre $5000 - $10000   "<<endl;
		gotoxy(40,9); cout<<"[Esc] SALIR                         "<<endl;
		gotoxy(40,11);cout<<"INGRESE UNA OPCION:                 "<<endl;
		gotoxy(40,13);cout<<"Dinero disponible $" << Dinero;
		gotoxy(60,11);opcion=getch();
		
		switch(opcion)
		{
			case 49:
			
			do{ //1
			do
			{
			do
			{
				system("cls");          
				cout << "\nIntroduce la apuesta y tira el dado! (Rango de apuesta $1 - 999): ";
				memset(Apuesta,0,sizeof(Apuesta));  //Limpiar la cadena
				gets(Apuesta);                     //capturar la cadena
				lon=strlen(Apuesta);               //strlen  devuelve la longitud de la cadena capturada
				//COMPROBAR SI TODOS LOS CARACTERES INGRESDOS SON DIGITOS
				for(int i=0; i < lon; i++)
				{
					if(!isdigit(Apuesta[i]))
					{ 
						cout << "Solo digitos";
						ban=0;
						getch();
						break;	
					}	
				}		
				valor=atoi(Apuesta); //convierte la cadena en Entero
				if(valor >= 1000 )
				{	
					cout << "Valor fuera de Rango";
					ban=0;
					getch();
					break;
				}
				if(lon==0)
				{
					cout << "Cadena Vacia";
					ban=0;
					getch();
					break; //ACTIVA LA BANDERA DE ERROR
				}
				
				cout << "You Apuesta $" << Apuesta << ".";
				
				cin.get(Tirada);
				
				Dado1 = rand() % 6 + 1;
				Dado2 = rand() % 6 + 1;
				Total_da = Dado1 + Dado2;
				
				cout << "\nYou Tiradaed a " << Dado1 << " and a " << Dado2
				<< " for a total of " << Total_da << "."<<endl;
				
				if (Total_da == 7 )
				{
				cout << "HAS GANADO!!!";
				Dinero += valor;
				cout << "\nDinero disponible $" << Dinero;
				}
				
				else if (Total_da >= 8)
				{
				cout << "HAS PERDIDO!!!";
				ban=0;
				Dinero -= valor;
				cout << "\nDinero disponible $" << Dinero;
				}
				getch();
				} while (Total_da != Puntos || Total_da != 7);
				} while (Dinero > 0);
				
				cout << "/nLooks like you ran out of Dinero. " << "Thanks for playing!" << endl;
				getch();
			}while(ban!=0);
				
		    break;

		    case 50: //2
	
		    system("cls");
	
				
		    break;

		    case 51: //3
		    
		    // Consulta por carrera
		    system("cls");
		

			break;
			
			case 27: exit(-1);
		}
	}while(salir==1);
	exit(0);
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

				/*do{
		    	cout << "\nIntroduce la apuesta y tira el dado! (Rango de apuesta $1 - 999): ";               
				memset(Apuesta,0,sizeof(Apuesta)); 
				gets(Apuesta);          
				int aux=0;           
			
				lon=strlen(Apuesta);         
				
				for(int c=0; c<lon; c++)
				{
					
					aux=(isdigit(Apuesta[c]));
					if (aux==0)
					ban=1; 		
				}
				if(lon==0)
				{
					ban=2;
					valor=atoi(Apuesta);
				}
	
				if (ban!=0)
				{
					if(ban==1)
					{
						cout << "Solo digitos";
					}
					
					if(ban==2)
					{
						cout << "Cadena Vacia";
					}
					
					if(ban==3)
					{
						cout << "Valor fuera de Rango";
					}		
					cout << " ";
				}
				
			/*while (Apuesta > Dinero || Apuesta > 999)
			{
		
			if (Apuesta > Dinero)
			cout << "\nNo tienes esa cantidad!";
			if (Apuesta > 999)
			if (!isdigit(Apuesta)).,
			cout << "\nFuera de rango de apuesta!";
			cout << "\n\nIntroduce la apuesta y tira el dado! (Rango de apuesta $1 - 999): ";
			cin >> Apuesta;
			}
			
			cout << "Tu apuesta $" << Apuesta;
			
			cin.get(Tirada);
			
			Dado1 = rand() % 6 + 1;
			Dado2 = rand() % 6 + 1;
			Total_da = Dado1 + Dado2;
			
			cout << "\nTu tirada fue... Dado 1: " << Dado1 << " y Dado 2: " << Dado2 << " Para un total de " << Total_da <<endl;
			
			if (Total_da == 7 )
			{
			cout << "HAS GANADO!!!";
			Dinero += Apuesta;
			cout << "\nDinero disponible $" << Dinero;
			}
			
			else if (Total_da >= 8)
			{
			cout << "HAS PERDIDO!!!";
			Dinero -= Apuesta;
			cout << "\nDinero disponible $" << Dinero;
			}
			
			}while (Dinero > 0);

			cout << "\n\nLooks like you ran out of Dinero. " << "Thanks for playing!" << endl;
			return 0;
			system("pause");
			}while(ban!=0);
			
			return valor;
		    getch();*/

/*void Apu_1 ()
{
	cout << "\nIntroduce la apuesta y tira el dado! (Rango de apuesta $1 - 999): ";               
	gets(Apuesta);          
	int aux=0;           

	lon=strlen(Apuesta);         
	
	for(int i=0; i<lon; i++)
	{
		
		aux=(!isdigit(Apuesta[i]));
		if (aux==0)
		ban=1; 		
	}
	if(lon==0)
	{
		ban=2;
	
	}

	if (ban!=0)
	{
		if(ban==1)
		{
			cout << "Solo digitos";
		}
		
		if(ban==2)
		{
			cout << "Cadena Vacia";
		}
	}
	/*while (Apuesta < 1 || Apuesta > Dinero || Apuesta > 5000 || Apuesta < 1000)
	{
	if (Apuesta < 1)
	cout << "\nNo seas tacaño!";
	if (Apuesta > Dinero)
	cout << "\nNo tienes esa cantidad!";
	if (Apuesta > 5000)
	cout << "\nFuera de rango de apuesta!";
	if (Apuesta < 1000)
	cout << "\nFuera de rango de apuesta!";
	cout << "\n\nIntroduce la apuesta y tira el dado! (Rango de apuesta $1000 - 4999): ";
	cin >> Apuesta;
	}*/
	
	/*cout << "Tu apuesta $" << Apuesta;
	
	cin.get(Tirada);
	
	Dado1 = rand() % 6 + 1;
	Dado2 = rand() % 6 + 1;
	Total_da = Dado1 + Dado2;
	
	cout << "\nTu tirada fue... Dado 1: " << Dado1 << " y Dado 2: " << Dado2 << " Para un total de " << Total_da <<endl;
	
	if (Total_da == 7 )
	{
	cout << "HAS GANADO!!!";
	Dinero += Apuesta;
	Dinero=atoi(Apuesta);
	cout << "\nDinero disponible $" << Dinero;
	}
	
	else if (Total_da >= 8)
	{
	cout << "HAS PERDIDO!!!";
	Dinero -= Apuesta;
	Apuesta=atoi(Dinero);
	cout << "\nDinero disponible $" << Dinero;
	}
	/*
	}while (Dinero > 0);

	cout << "\n\nLooks like you ran out of Dinero. " << "Thanks for playing!" << endl;
	return 0;
	system("pause");								 
   
    getch();
}

void Apu_2 ()
{
	/*for (inTotal_da=0; inTotal_da<3; inTotal_da++)
	{
	cout << "____________________________" << endl;
 	cout << "Matricula: " << estudiante1[inTotal_da].matricula   << endl;
 	cout << "Nombre: "    << estudiante1[inTotal_da].nombre      << endl;
 	cout << "Domicilio: " << estudiante1[inTotal_da].domicilio   << endl;
 	cout << "Carrera: "   << estudiante1[inTotal_da].carrera     << endl;
 	cout << "Semestre: "  << estudiante1[inTotal_da].semetre     << endl;
 	cout << "Promedio: "  << estudiante1[inTotal_da].promedio    << endl;
	}
	system("pause");
}

void Apu_3 ()
{
	/*int carre;
	
	cout << "Ingresa la carrera a buscar: " << endl;
	cin >> carre;
		for (inTotal_da=0; inTotal_da<3; inTotal_da++)
		{
			if (estudiante1[inTotal_da].carrera==carre)
			{
			ban=1;
			cout << "Matricula: " << estudiante1[inTotal_da].matricula   << endl;
 			cout << "Nombre: "    << estudiante1[inTotal_da].nombre      << endl;
 			cout << "Semestre: "  << estudiante1[inTotal_da].semetre     << endl;
 			cout << "Promedio: "  << estudiante1[inTotal_da].promedio    << endl;
			}          
		}
		if (ban==0)
		{
			cout << "No hay carreras registradas con esa asignatura!",carre;
			
		}
		system("pause");
}*/

	    
   


			
		   
		    /*case 51:
			
			system("cls");
		    cout << "\nIntroduce la apuesta y tira el dado! (Rango de apuesta $5000 - 10000): ";
			cin >> Apuesta;
			
			while (Apuesta < 1 || Apuesta > Dinero || Apuesta < 5000 || Apuesta > 10000)
			{
			if (Apuesta < 1)
			cout << "\nNo seas tacaño!";
			if (Apuesta > Dinero)
			cout << "\nNo tienes esa cantidad!";
			if (Apuesta < 5000)
			cout << "\nFuera de rango de apuesta!";
			if (Apuesta > 10000)
			cout << "\nFuera de rango de apuesta!";
			cout << "\n\nIntroduce la apuesta y tira el dado! (Rango de apuesta $5000 - 10000): ";
			cin >> Apuesta;
			}
			
			cout << "Tu apuesta $" << Apuesta;
			
			cin.get(Tirada);
			
			Dado1 = rand() % 6 + 1;
			Dado2 = rand() % 6 + 1;
			Total_da = Dado1 + Dado2;
			
			cout << "\nTu tirada fue... Dado 1: " << Dado1 << " y Dado 2: " << Dado2 << " Para un total de " << Total_da <<endl;
			
			if (Total_da == 7 )
			{
			cout << "HAS GANADO!!!";
			Dinero += Apuesta;
			cout << "\nDinero disponible $" << Dinero;
			}
			
			else if (Total_da >= 8)
			{
			cout << "HAS PERDIDO!!!";
			Dinero -= Apuesta;
			cout << "\nDinero disponible $" << Dinero;
			}
	
			}while (Dinero > 0);

			cout << "\n\nLooks like you ran out of Dinero. " << "Thanks for playing!" << endl;
			return 0;
			system("pause");									 
		   
		    getch();									 
		    break;*/






