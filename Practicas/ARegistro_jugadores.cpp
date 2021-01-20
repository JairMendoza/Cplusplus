// Arturo Cuevas Perez 
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>
#include<locale.h>

using namespace std;

///////////////////////////////////////////////
FILE *pf, *pa;
char carpeta_ori[300], carpeta_copy[300] = {"agenda_tmp.txt"};
///////////////////////////////////////////////
char nombre[25], apodo[25], nacionalidad[25], numeroj[3], posicion[9], club[30], goles[3];
///////////////////////////////////////////////
char caracter='\0';
char Union   [100], Union_1 [100], Union_2 [100], Union_3 [100], Union_4 [100], Union_5 [100], Union_6 [100];
///////////////////////////////////////////////
char respuesta;
int respuesta2;
int ban = 0, aux = 0, lon = 0, Rcreado = 0;
///////////////////////////////////////////////
void Crear ();
void Alta ();
void Mostrar ();
void Consultar ();
void Eliminar ();
void Editar ();
void gotoxy(int,int);
char Menu (void);
///////////////////////////////////////////////
int ema,num,nom,gol;

int main ()
{
	char opcion;
	
	do
	{
		opcion = Menu();
		
		switch(opcion)
		{
			char o;
			
			case 59: //F1
		    system("cls");
		    Crear ();
		    break;
		    
			case 60: //F2
			system("cls");
			Alta ();	
		    break;
		    
		    case 61: //F3
		    system("cls");
			Mostrar ();
		    break;
		    
		    case 62: //F4
		    system("cls");
			Consultar ();
		    break;
		    
		    case 63: //F5
		    system("cls");
			Editar ();
		    break;
		    
		    case 64: //F6
		    system("cls");
			Eliminar ();	
		    break;

			case 27: //ESC
			system("cls");
			gotoxy(50,11); cout<<"¡Hasta la proxima!";
		}
	}while(opcion!=27);
	return 0;
}

char Menu ()
{
	char opcion1;
	
	setlocale(LC_CTYPE, "Spanish");
	system("cls");
	gotoxy(45,7);  cout << "____________MENU____________";
	gotoxy(45,8);  cout << "[F1] Abrir o Crear fichero  ";
	gotoxy(45,9);  cout << "[F2] Registrar jugadores    ";
	gotoxy(45,10); cout << "[F3] Mostrar registros      ";
	gotoxy(45,11); cout << "[F4] Consultar              ";
	gotoxy(45,12); cout << "[F5] Editar jugadores       ";
	gotoxy(45,13); cout << "[F6] Eliminar jugadores     ";
	gotoxy(45,14); cout << "[Esc] SALIR                 ";
	gotoxy(45,16); cout << "INGRESE UNA OPCION: "; fflush(stdin);
	opcion1 = getch();
}

int NombreJugador (char nombre[25])
{	
	if (strlen(nombre) <= 25)
	{
		for (int i = 1; i < strlen(nombre); i++)
		{
			if(nombre[0] >= 'A' && nombre[0] <= 'Z' && nombre[i] >= 'a' && nombre[i] <= 'z' && !isdigit(nombre[i]))
				return 1;
			else
				return 0;
		}
		return 0;
	}
}

int ApodoJugador(char apodo[25])
{
	if (strlen(apodo) <= 25)
	for (int i = 0; i < strlen(apodo); i++)
		if (!isalpha(apodo[i]))
			return 0;
}

int NacionalidadJugador (char nacionalidad[25])
{
	if (strlen(nacionalidad) <= 25)
	{
		for (int i = 1; i < strlen(nacionalidad); i++)
		{
			if(nacionalidad[0] >= 'A' && nacionalidad[0] <= 'Z' && nacionalidad[i] >= 'a' && nacionalidad[i] <= 'z' && !isdigit(nacionalidad[i]) )
				return 1;
			else
				return 0;
		}
		return 0;
	}
}

int NumeroJugador(char numeroj[3])
{
	if (strlen(numeroj) <= 3)
	{
		num=atoi(numeroj);
		if(num>101)
		{
			cout << "¡Fuera de rango ingresa nuevamente el dato!\n";
			getch();
			return 0;
		}
		if (numeroj[0] == '0')
			return 0;
		for (int i = 0; i < strlen(numeroj); i++)
			if (!isdigit(numeroj[i]))
				return 0;
		return 1;
	}
	return 0;
}

int PosicionJugador(char posicion[25])
{
	if (strlen(posicion) <= 25)
	for (int i = 0; i < strlen(posicion); i++)
		if (!isalpha(posicion[i]))
			return 0;
}

int ClubJugador (char club[25])
{
	if (strlen(club) <= 25)
	for (int i = 1; i < strlen(club); i++)
		if(club[0] >= 'A' && club[0] <= 'Z' && club[i] >= 'a' && club[i] <= 'z' && !isdigit(club[i]) )
			return 1;
		else
			return 0;
		return 0;
}

int GolesJugador(char goles[3])
{
	if (strlen(goles) <= 3)
	{
		gol=atoi(goles);
		if(gol>999)
		{
			cout << "¡Fuera de rango ingresa nuevamente el dato!\n";
			getch();
			return 0;
		}
		if (goles[0] == '0')
			return 0;
		for (int i = 0; i < strlen(goles); i++)
			if (!isdigit(goles[i]))
				return 0;
		return 1;
	}
	return 0;
}
	
void Crear ()
{
	system("color C");
	memset(carpeta_ori,0,sizeof(carpeta_ori));
	do
	{
		do
		{
			cout << "¿Que archivo desea abrir o crear?: " << endl; 
			gets(carpeta_ori);
			
			unsigned int i;
			lon=strlen(carpeta_ori);
			aux=0;
			for (int i = 0; i < lon; i++)
			{
				if(carpeta_ori[lon-1] == 't' && carpeta_ori[lon-2] == 'x' && carpeta_ori[lon-3] == 't' && carpeta_ori[lon-4] == '.')
				{
					ban = 0;
				}
				else
				{
					ban = 1;
				}
			}
			if(ban == 1)
			{
				cout << "¡Es necesario el punto y la extencion txt!" << endl;
			}
		}while(ban == 1);
		if (lon == 0)
		{
	    	aux=1;
	    	cout << "¡Campo vacio!" << endl;
		}
		if(isspace(lon))
		{
			aux=1;
			cout << "¡No se admiten espacios!" << endl;
		}
	}while(aux == 1);
			
			
    pf = fopen(carpeta_ori, "r");
	
	if(pf==NULL)
	{
		system("color A");
		pf = fopen(carpeta_ori, "w");
		cout << "¡El archivo no exite pero fue creado!" << endl;
		Rcreado=1;
		getch();
	}
	else 
	{
		system("color A");
		cout << "¡Apertura exitosa!" << endl;
		Rcreado=1;
		getch();
	}
	
	fclose(pf);
}

void Alta ()
{		
	pf=fopen(carpeta_ori,"a");
	
	if(pf==NULL)
	{
		system("color C");
		cout << "¡No fue posible cargar el archivo para escribir!";
		exit(0);
		getch();
	}
	else
	{
		do
		{
			system("cls");
			memset(nombre,0,sizeof(nombre));
			memset(apodo,0,sizeof(apodo));
	        memset(nacionalidad,0,sizeof(nacionalidad));
	        memset(numeroj,0,sizeof(numeroj));
	        memset(posicion,0,sizeof(posicion));
	        memset(club,0,sizeof(club));
	        memset(goles,0,sizeof(goles));
		
///////////////////////////////////////////////////////////////////////////////////
			char Union [100];
			char ceros[3] = "00";
			char cero [3] =  "0";
			char Deli [20];
			int longitud = 0;
			
			memset(Deli,0,sizeof(Deli));
			
			do
			{	
			    cout << "Ingresa el nombre del jugador: "; fflush(stdin);
				gets(nombre);
				if (NombreJugador(nombre))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
			
			longitud=strlen(nombre);
			
			itoa(longitud,Deli,10);
			
			longitud=strlen(Deli);
			
			if(longitud == 1)
			{
				strcpy(Union,strcat(ceros,Deli));
			}
			if(longitud == 2)
			{
				strcpy(Union,strcat(cero,Deli));
			}
///////////////////////////////////////////////////////////////////////////////////
			char Union_1 [100];
			char ceros_1[3] = "00";
			char cero_1 [3] =  "0";
			char Deli_1 [20];
			int longitud_1 = 0;
			
			memset(Deli_1,0,sizeof(Deli_1));
			
			do
			{	
			    cout << "\nIngresa el apodo del jugador: "; fflush(stdin);
				gets(apodo);
				if (ApodoJugador(apodo))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
			
			longitud_1=strlen(apodo);
			
			itoa(longitud_1,Deli_1,10);
			
			longitud_1=strlen(Deli_1);
			
			if(longitud_1 == 1)
			{
				strcpy(Union_1,strcat(ceros_1,Deli_1));
			}
			if(longitud_1 == 2)
			{
				strcpy(Union_1,strcat(cero_1,Deli_1));
			}
			
//////////////////////////////////////////////////////////////////////////////////
			char Union_2 [100];
			char ceros_2[3] = "00";
			char cero_2 [3] =  "0";
			char Deli_2 [20];
			int longitud_2 = 0;
			
			memset(Deli_2,0,sizeof(Deli_2));
			
			do
			{	
			    cout << "\nIngresa la nacionalidad del jugador: "; fflush(stdin);
				gets(nacionalidad);
				if (NacionalidadJugador(nacionalidad))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
			
			longitud_2=strlen(nacionalidad);
			
			itoa(longitud_2,Deli_2,10);
			
			longitud_2=strlen(Deli_2);
			
			if(longitud_2 == 1)
			{
				strcpy(Union_2,strcat(ceros_2,Deli_2));
			}
			if(longitud_2 == 2)
			{
				strcpy(Union_2,strcat(cero_2,Deli_2));
			}
/////////////////////////////////////////////////////////////////////////////////
			char Union_3 [100];
			char ceros_3[3] = "00";
			char cero_3 [3] =  "0";
			char Deli_3 [20];
			int longitud_3 = 0;
			
			memset(Deli_3,0,sizeof(Deli_3));
			
        	do
			{	
			    cout << "\nIngresa el numero de jugador: "; fflush(stdin);
				gets(numeroj);
				if (NumeroJugador(numeroj))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
			
			longitud_3=strlen(numeroj);
			
			itoa(longitud_3,Deli_3,10);
			
			longitud_3=strlen(Deli_3);
			
			if(longitud_3 == 1)
			{
				strcpy(Union_3,strcat(ceros_3,Deli_3));
			}
			if(longitud_3 == 2)
			{
				strcpy(Union_3,strcat(cero_3,Deli_3));
			}
///////////////////////////////////////////////////////////////////////////////
			char Union_4 [100];
			char ceros_4[3] = "00";
			char cero_4 [3] =  "0";
			char Deli_4 [20];
			int longitud_4 = 0;
			
			memset(Deli_4,0,sizeof(Deli_4));
			do
			{	
			    cout << "\nIngresa la posicion del jugador: "; fflush(stdin);
				gets(posicion);
				if (PosicionJugador(posicion))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
			
			longitud_4=strlen(posicion);
			
			itoa(longitud_4,Deli_4,10);
			
			longitud_4=strlen(Deli_4);
			
			if(longitud_4 == 1)
			{
				strcpy(Union_4,strcat(ceros_4,Deli_4));
			}
			if(longitud_4 == 2)
			{
				strcpy(Union_4,strcat(cero_4,Deli_4));
			}
///////////////////////////////////////////////////////////////////////////////
			char Union_5 [100];
			char ceros_5[3] = "00";
			char cero_5 [3] =  "0";
			char Deli_5 [20];
			int longitud_5 = 0;
			
			memset(Deli_5,0,sizeof(Deli_5));
			do
			{	
			    cout << "\nIngresa el club del jugador: "; fflush(stdin);
				gets(club);
				if (ClubJugador(club))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
			
			longitud_5=strlen(club);
			
			itoa(longitud_5,Deli_5,10);
			
			longitud_5=strlen(Deli_5);
			
			if(longitud_5 == 1)
			{
				strcpy(Union_5,strcat(ceros_5,Deli_5));
			}
			if(longitud_5 == 2)
			{
				strcpy(Union_5,strcat(cero_5,Deli_5));
			}
///////////////////////////////////////////////////////////////////////////////
			char Union_6 [100];
			char ceros_6[3] = "00";
			char cero_6 [3] =  "0";
			char Deli_6 [20];
			int longitud_6 = 0;
			
			memset(Deli_6,0,sizeof(Deli_6));
			do
			{	
			    cout << "\nIngresa los goles anotados del jugador: "; fflush(stdin);
				gets(goles);
				if (GolesJugador(goles))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
			
			longitud_6=strlen(goles);
			
			itoa(longitud_6,Deli_6,10);
			
			longitud_6=strlen(Deli_6);
			
			if(longitud_6 == 1)
			{
				strcpy(Union_6,strcat(ceros_6,Deli_6));
			}
			if(longitud_6 == 2)
			{
				strcpy(Union_6,strcat(cero_6,Deli_6));
			}
///////////////////////////////////////////////////////////////////////////////
			
			fputs(Union,pf);
			fputs(nombre,pf);
				
			fputs(Union_1,pf);
			fputs(apodo,pf);
			
			fputs(Union_2,pf);
			fputs(nacionalidad,pf);
			
			fputs(Union_3,pf);
			fputs(numeroj,pf);
			
			fputs(Union_4,pf);
			fputs(posicion,pf);
			
			fputs(Union_5,pf);
			fputs(club,pf);
			
			fputs(Union_6,pf);
			fputs(goles,pf);
	
			do
			{	
				system("cls");
				cout << "¿Deseas agregar otro registro? S/N " << endl;
				respuesta=getch();
				
				if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
				{
					cout << "\n\nIntroduce una opcion: ";
					getch();
				}
			
			}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
		}while(respuesta=='s' || respuesta=='S');
	}
	fclose(pf);
}

void Mostrar ()
{
	char longitudChar[100];
	
 	pf = fopen(carpeta_ori,"r");
	if(pf==NULL)
	{
		system("color C");
		cout << "¡No se encontro el archivo para la lectura!";
		exit(0);
		getch();
	}
	else
	{
   		do
		{
			memset(nombre,0,sizeof(nombre));
			memset(apodo,0,sizeof(apodo));
	        memset(nacionalidad,0,sizeof(nacionalidad));
	        memset(numeroj,0,sizeof(numeroj));
	        memset(posicion,0,sizeof(posicion));
	        memset(club,0,sizeof(club));
	        memset(goles,0,sizeof(goles));
	   
	        Rcreado=0;
	        
	        for(int j=0; j < 7; j++)
			{
				for(int i=0; i < 3; i++)
				{
					caracter=fgetc(pf);
					longitudChar[i]=caracter;
				}
		
				Rcreado=atoi(longitudChar);
			
				if(j==0)
				{
					fgets(nombre,Rcreado+1,pf);
				}
				if(j==1)
				{
					fgets(apodo,Rcreado+1,pf);
				}
				if(j==2)
				{
					fgets(nacionalidad,Rcreado+1,pf);
				}
				if(j==3)
				{
					fgets(numeroj,Rcreado+1,pf);
				}
				if(j==4)
				{
					fgets(posicion,Rcreado+1,pf);
				}
				if(j==5)
				{
					fgets(club,Rcreado+1,pf);
				}
				if(j==6)
				{
					fgets(goles,Rcreado+1,pf);
				}
			}
			
			if(!feof(pf))
			{
				cout << "\n____________________________"  << endl;
				cout << "Nombre: " << nombre  		  	  << endl;
				cout << "Apodo : " << apodo				  << endl;
				cout << "Nacionalidad: " << nacionalidad  << endl;
				cout << "Numero jugador: " << numeroj 	  << endl;
				cout << "Posicion: " << posicion 		  << endl;
				cout << "Club: " << club 				  << endl;
				cout << "Goles: " << goles 				  << endl;
				cout << "____________________________" 	  << endl;
	        }
		}while(caracter!=EOF);
	}
	fclose(pf);
	getch();
}

void Consultar ()
{
	char longitudChar[100];
	char buscar[100];
	
 	pf = fopen(carpeta_ori,"r");
 	
	if(pf==NULL)
	{
		system("color C");
		cout << "¡No se encontro el archivo para la lectura!";
		exit(0);
		getch();
	}
	else
	{
		cout << "Introduce su Nombre: "; fflush(stdin);
		gets(buscar);
			
   		do
		{
			memset(nombre,0,sizeof(nombre));
			memset(apodo,0,sizeof(apodo));
	        memset(nacionalidad,0,sizeof(nacionalidad));
	        memset(numeroj,0,sizeof(numeroj));
	        memset(posicion,0,sizeof(posicion));
	        memset(club,0,sizeof(club));
	        memset(goles,0,sizeof(goles));
	   
	        Rcreado=0;
	        
	        for(int j=0; j < 7; j++)
			{
				for(int i=0; i < 3; i++)
				{
					caracter=fgetc(pf);
					longitudChar[i]=caracter;
				}
		
				Rcreado=atoi(longitudChar);
			
				if(j==0)
				{
					fgets(nombre,Rcreado+1,pf);
				}
				if(j==1)
				{
					fgets(apodo,Rcreado+1,pf);
				}
				if(j==2)
				{
					fgets(nacionalidad,Rcreado+1,pf);
				}
				if(j==3)
				{
					fgets(numeroj,Rcreado+1,pf);
				}
				if(j==4)
				{
					fgets(posicion,Rcreado+1,pf);
				}
				if(j==5)
				{
					fgets(club,Rcreado+1,pf);
				}
				if(j==6)
				{
					fgets(goles,Rcreado+1,pf);
				}
			}
			
			if(!strcmpi(buscar,nombre))
			{
				cout << "\n____________________________"  << endl;
				cout << "Nombre: " << nombre  		  	  << endl;
				cout << "Apodo : " << apodo				  << endl;
				cout << "Nacionalidad: " << nacionalidad  << endl;
				cout << "Numero jugador: " << numeroj 	  << endl;
				cout << "Posicion: " << posicion 		  << endl;
				cout << "Club: " << club 				  << endl;
				cout << "Goles: " << goles 				  << endl;
				cout << "____________________________" 	  << endl;
	        }
	        
		}while(caracter!=EOF);
	}
	fclose(pf);
	getch();
}

void Editar ()
{
	char longitudChar[100];
	char buscar[100];
	int respuesta2;
	
	do
	{
	 	pf = fopen(carpeta_ori,"r");
	 	pa = fopen(carpeta_copy, "w");
	 	
		if(pf==NULL)
		{
			system("color C");
			cout << "1¡No se encontro el archivo para la lectura!";
			exit(0);
			getch();
		}
		else
		{	
			system("cls");
			cout << "\nIntroduce un nombre para buscarlo y editarlo: "; fflush(stdin);
			gets(buscar);
				
			do
			{
				respuesta2 = 'n';
				memset(nombre,0,sizeof(nombre));
				memset(apodo,0,sizeof(apodo));
		        memset(nacionalidad,0,sizeof(nacionalidad));
		        memset(numeroj,0,sizeof(numeroj));
		        memset(posicion,0,sizeof(posicion));
		        memset(club,0,sizeof(club));
		        memset(goles,0,sizeof(goles));
		        Rcreado=0;
		        
		        for(int j=0; j < 7; j++)
				{
					for(int i=0; i < 3; i++)
					{
						caracter=fgetc(pf);
						longitudChar[i]=caracter;
					}
			
					Rcreado=atoi(longitudChar);
				
					if(j==0)
					{
						fgets(nombre,Rcreado+1,pf);
					}
					if(j==1)
					{
						fgets(apodo,Rcreado+1,pf);
					}
					if(j==2)
					{
						fgets(nacionalidad,Rcreado+1,pf);
					}
					if(j==3)
					{
						fgets(numeroj,Rcreado+1,pf);
					}
					if(j==4)
					{
						fgets(posicion,Rcreado+1,pf);
					}
					if(j==5)
					{
						fgets(club,Rcreado+1,pf);
					}
					if(j==6)
					{
						fgets(goles,Rcreado+1,pf);
					}
				}
		        
				if(caracter!=EOF)
				{
					if(!strcmpi(buscar,nombre))
					{
						cout << "\n____________________________"  << endl;
						cout << "Nombre: " << nombre  		  	  << endl;
						cout << "Apodo : " << apodo				  << endl;
						cout << "Nacionalidad: " << nacionalidad  << endl;
						cout << "Numero jugador: " << numeroj 	  << endl;
						cout << "Posicion: " << posicion 		  << endl;
						cout << "Club: " << club 				  << endl;
						cout << "Goles: " << goles 				  << endl;
						cout << "____________________________" 	  << endl;
						
						do
						{
							cout << "\n\n¿Este es el registro que quieres modificar? S/N ";
							respuesta=getch();
				
						if(respuesta == 's' || respuesta == 'S')
						{
							char Union [100];
							char ceros[3] = "00";
							char cero [3] =  "0";
							char Deli [20];
							int longitud = 0;
							
							memset(Deli,0,sizeof(Deli));
							
							do
							{	
							    cout << "\nIngresa el nombre del jugador: "; fflush(stdin);
								gets(nombre);
								if (NombreJugador(nombre))
								{
									ban=1;
								}
								else
								{
									cout << "¡Dato incorrecto!" << endl;
									ban=0;
								}
							}while (ban==0);
							
							longitud=strlen(nombre);
							
							itoa(longitud,Deli,10);
							
							longitud=strlen(Deli);
							
							if(longitud == 1)
							{
								strcpy(Union,strcat(ceros,Deli));
							}
							if(longitud == 2)
							{
								strcpy(Union,strcat(cero,Deli));
							}
							fputs(Union,pf);
							fputs(nombre,pf);
					///////////////////////////////////////////////////////////////////////////////////
							char Union_1 [100];
							char ceros_1[3] = "00";
							char cero_1 [3] =  "0";
							char Deli_1 [20];
							int longitud_1 = 0;
							
							memset(Deli_1,0,sizeof(Deli_1));
							
							do
							{	
							    cout << "\nIngresa el apodo del jugador: "; fflush(stdin);
								gets(apodo);
								if (ApodoJugador(apodo))
								{
									ban=1;
								}
								else
								{
									cout << "¡Dato incorrecto!" << endl;
									ban=0;
								}
							}while (ban==0);
							
							longitud_1=strlen(apodo);
							
							itoa(longitud_1,Deli_1,10);
							
							longitud_1=strlen(Deli_1);
							
							if(longitud_1 == 1)
							{
								strcpy(Union_1,strcat(ceros_1,Deli_1));
							}
							if(longitud_1 == 2)
							{
								strcpy(Union_1,strcat(cero_1,Deli_1));
							}
							fputs(Union_1,pf);
							fputs(apodo,pf);
							
					//////////////////////////////////////////////////////////////////////////////////
							char Union_2 [100];
							char ceros_2[3] = "00";
							char cero_2 [3] =  "0";
							char Deli_2 [20];
							int longitud_2 = 0;
							
							memset(Deli_2,0,sizeof(Deli_2));
							
							do
							{	
							    cout << "\nIngresa la nacionalidad del jugador: "; fflush(stdin);
								gets(nacionalidad);
								if (NacionalidadJugador(nacionalidad))
								{
									ban=1;
								}
								else
								{
									cout << "¡Dato incorrecto!" << endl;
									ban=0;
								}
							}while (ban==0);
							
							longitud_2=strlen(nacionalidad);
							
							itoa(longitud_2,Deli_2,10);
							
							longitud_2=strlen(Deli_2);
							
							if(longitud_2 == 1)
							{
								strcpy(Union_2,strcat(ceros_2,Deli_2));
							}
							if(longitud_2 == 2)
							{
								strcpy(Union_2,strcat(cero_2,Deli_2));
							}
							fputs(Union_2,pf);
							fputs(nacionalidad,pf);
					/////////////////////////////////////////////////////////////////////////////////
							char Union_3 [100];
							char ceros_3[3] = "00";
							char cero_3 [3] =  "0";
							char Deli_3 [20];
							int longitud_3 = 0;
							
							memset(Deli_3,0,sizeof(Deli_3));
							
					    	do
							{	
							    cout << "\nIngresa el numero de jugador: "; fflush(stdin);
								gets(numeroj);
								if (NumeroJugador(numeroj))
								{
									ban=1;
								}
								else
								{
									cout << "¡Dato incorrecto!" << endl;
									ban=0;
								}
							}while (ban==0);
							
							longitud_3=strlen(numeroj);
							
							itoa(longitud_3,Deli_3,10);
							
							longitud_3=strlen(Deli_3);
							
							if(longitud_3 == 1)
							{
								strcpy(Union_3,strcat(ceros_3,Deli_3));
							}
							if(longitud_3 == 2)
							{
								strcpy(Union_3,strcat(cero_3,Deli_3));
							}
							fputs(Union_3,pf);
							fputs(numeroj,pf);
					///////////////////////////////////////////////////////////////////////////////
							char Union_4 [100];
							char ceros_4[3] = "00";
							char cero_4 [3] =  "0";
							char Deli_4 [20];
							int longitud_4 = 0;
							
							memset(Deli_4,0,sizeof(Deli_4));
							do
							{	
							    cout << "\nIngresa la posicion del jugador: "; fflush(stdin);
								gets(posicion);
								if (PosicionJugador(posicion))
								{
									ban=1;
								}
								else
								{
									cout << "¡Dato incorrecto!" << endl;
									ban=0;
								}
							}while (ban==0);
							
							longitud_4=strlen(posicion);
							
							itoa(longitud_4,Deli_4,10);
							
							longitud_4=strlen(Deli_4);
							
							if(longitud_4 == 1)
							{
								strcpy(Union_4,strcat(ceros_4,Deli_4));
							}
							if(longitud_4 == 2)
							{
								strcpy(Union_4,strcat(cero_4,Deli_4));
							}
							fputs(Union_4,pf);
							fputs(posicion,pf);
					///////////////////////////////////////////////////////////////////////////////
							char Union_5 [100];
							char ceros_5[3] = "00";
							char cero_5 [3] =  "0";
							char Deli_5 [20];
							int longitud_5 = 0;
							
							memset(Deli_5,0,sizeof(Deli_5));
							do
							{	
							    cout << "\nIngresa el club del jugador: "; fflush(stdin);
								gets(club);
								if (ClubJugador(club))
								{
									ban=1;
								}
								else
								{
									cout << "¡Dato incorrecto!" << endl;
									ban=0;
								}
							}while (ban==0);
							
							longitud_5=strlen(club);
							
							itoa(longitud_5,Deli_5,10);
							
							longitud_5=strlen(Deli_5);
							
							if(longitud_5 == 1)
							{
								strcpy(Union_5,strcat(ceros_5,Deli_5));
							}
							if(longitud_5 == 2)
							{
								strcpy(Union_5,strcat(cero_5,Deli_5));
							}
							fputs(Union_5,pf);
							fputs(club,pf);
					///////////////////////////////////////////////////////////////////////////////
							char Union_6 [100];
							char ceros_6[3] = "00";
							char cero_6 [3] =  "0";
							char Deli_6 [20];
							int longitud_6 = 0;
							
							memset(Deli_6,0,sizeof(Deli_6));
							do
							{	
							    cout << "\nIngresa los goles anotados del jugador: "; fflush(stdin);
								gets(goles);
								if (GolesJugador(goles))
								{
									ban=1;
								}
								else
								{
									cout << "¡Dato incorrecto!" << endl;
									ban=0;
								}
							}while (ban==0);
							
							longitud_6=strlen(goles);
							
							itoa(longitud_6,Deli_6,10);
							
							longitud_6=strlen(Deli_6);
							
							if(longitud_6 == 1)
							{
								strcpy(Union_6,strcat(ceros_6,Deli_6));
							}
							if(longitud_6 == 2)
							{
								strcpy(Union_6,strcat(cero_6,Deli_6));
							}
							fputs(Union_6,pf);
							fputs(goles,pf);
					///////////////////////////////////////////////////////////////////////////////
							
									
									cout << "\n\n\n¡Registro modificado con exito!";
									getch();
						}
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								cout << "\n\nIntroduce una opcion: ";
								getch();
							}
						
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
					}
						fputs(Union,pf);
						fputs(nombre,pf);
							
						fputs(Union_1,pf);
						fputs(apodo,pf);
						
						fputs(Union_2,pf);
						fputs(nacionalidad,pf);
						
						fputs(Union_3,pf);
						fputs(numeroj,pf);
						
						fputs(Union_4,pf);
						fputs(posicion,pf);
						
						fputs(Union_5,pf);
						fputs(club,pf);
						
						fputs(Union_6,pf);
						fputs(goles,pf);
		    	}
			}while(caracter!=EOF);
		
			fclose(pf);
			fclose(pa);
					
			remove(carpeta_ori);        
			rename(carpeta_copy,carpeta_ori);
		
			do
			{
				cout << "\n\n¿Deseas seguir editando? S/N ";
				respuesta2=getch();
		
				if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
				{
					cout << "\n\nIntroduce una opcion: ";
					getch();
				}
			}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
		}
	
	}while(respuesta2 == 's' || respuesta2 == 'S');
}

void Eliminar ()
{
	char longitudChar[100];
	char buscar[100];
	
	do
	{
	 	pf = fopen(carpeta_ori,"r");
	 	pa = fopen(carpeta_copy, "w");
	 	
		if(pf==NULL)
		{
			system("color C");
			cout << "¡No se encontro el archivo para la lectura!";
			exit(0);
			getch();
		}
		else
		{	
			system("cls");
			cout << "Introduce un nombre para buscarlo y eliminarlo: "; fflush(stdin);
			gets(buscar);
				
			do
			{
				respuesta2 = 'n';
				memset(nombre,0,sizeof(nombre));
				memset(apodo,0,sizeof(apodo));
		        memset(nacionalidad,0,sizeof(nacionalidad));
		        memset(numeroj,0,sizeof(numeroj));
		        memset(posicion,0,sizeof(posicion));
		        memset(club,0,sizeof(club));
		        memset(goles,0,sizeof(goles));
		   
		        Rcreado=0;
		        
		        for(int j=0; j < 7; j++)
				{
					for(int i=0; i < 3; i++)
					{
						caracter=fgetc(pf);
						longitudChar[i]=caracter;
					}
			
					Rcreado=atoi(longitudChar);
				
					if(j==0)
					{
						fgets(nombre,Rcreado+1,pf);
					}
					if(j==1)
					{
						fgets(apodo,Rcreado+1,pf);
					}
					if(j==2)
					{
						fgets(nacionalidad,Rcreado+1,pf);
					}
					if(j==3)
					{
						fgets(numeroj,Rcreado+1,pf);
					}
					if(j==4)
					{
						fgets(posicion,Rcreado+1,pf);
					}
					if(j==5)
					{
						fgets(club,Rcreado+1,pf);
					}
					if(j==6)
					{
						fgets(goles,Rcreado+1,pf);
					}
				}
				
				if(!feof(pf))
				{
					if(!strcmpi(buscar,nombre))
					{      
						system("cls");
						cout << "\n____________________________"  << endl;
						cout << "Nombre: " << nombre  		  	  << endl;
						cout << "Apodo : " << apodo				  << endl;
						cout << "Nacionalidad: " << nacionalidad  << endl;
						cout << "Numero jugador: " << numeroj 	  << endl;
						cout << "Posicion: " << posicion 		  << endl;
						cout << "Club: " << club 				  << endl;
						cout << "Goles: " << goles 				  << endl;
						cout << "____________________________" 	  << endl;
						
						do
						{
							cout << "\n\n¿Este es el registro que quieres eliminar? S/N ";
							respuesta=getch();
							
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								cout << "\n\nIntroduce una opcion: ";
								getch();
							}
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
					}
					
						if(respuesta == 's' || respuesta == 'S')
						{	
							cout << "\n\n\n¡Registro eliminado con exito!";
							getch();
						}
						else 
						{
							fputs(Union,pf);
							fputs(nombre,pf);
								
							fputs(Union_1,pf);
							fputs(apodo,pf);
							
							fputs(Union_2,pf);
							fputs(nacionalidad,pf);
							
							fputs(Union_3,pf);
							fputs(numeroj,pf);
							
							fputs(Union_4,pf);
							fputs(posicion,pf);
							
							fputs(Union_5,pf);
							fputs(club,pf);
							
							fputs(Union_6,pf);
							fputs(goles,pf);
						}	
		    	}
		    	
			}while(caracter!=EOF);
			
			fclose(pf);
			fclose(pa);
			
			remove(carpeta_ori);        
			rename(carpeta_copy,carpeta_ori);
		
			do
			{
				cout << "\n\n¿Deseas seguir eliminando? S/N ";
				respuesta2=getch();
		
				if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
				{
					cout << "\n\nIntroduce una opcion: ";
					getch();
				}
			}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
		}
	
	}while(respuesta2 == 's' || respuesta2 == 'S');
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
