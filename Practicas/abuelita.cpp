#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

void menu();
void menuar();
void menuco();
void menuve();
void menua();
void menex();
void exple();
void expin();
int shar=0;

main()
{
	
	int cat=0,dog=0;
	char mopc='\0';
	do{
	do{	
		system("cls");
		menu();
		mopc=getch();
		if(mopc==59||mopc==60||mopc==61||mopc==62||mopc==13||mopc==27)
		{
			cat=1;
		}
		if(mopc==9)
		{
			shar++;
		}
		if(shar==4)
		{
			shar=0;
		}
	}while(cat!=1);
	if(shar==0&&mopc==13)
	{
		mopc=59;
	}
	if(shar==1&&mopc==13)
	{
		mopc=60;
	}
	if(shar==2&&mopc==13)
	{
		mopc=61;
	}
	if(shar==3&&mopc==13)
	{
		mopc=62;
	}
	///////////////////////////////////////////////INICIA SWITCH
	///////////////////////////////////////////////INICIA SWITCH
	///////////////////////////////////////////////INICIA SWITCH
	switch(mopc)
	{
		///////////////////////////////////////////////CASO F1
		///////////////////////////////////////////////CASO F1
		///////////////////////////////////////////////CASO F1
		case 59:
			cat=0;
			shar=0;
			do{
				system("cls");
				menuar();
				mopc=getch();
				if(mopc==59||mopc==60||mopc==13||mopc==27)
				{
					cat=1;
				}
				if(mopc==9)
				{
					shar++;
				}
				if(shar==3)
				{
					shar=0;
				}
			}while(cat!=1);
			if(shar==0&&mopc==13)
			{
				mopc=59;
			}
			if(shar==1&&mopc==13)
			{
				mopc=60;
			}
			if(mopc==59)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"Consola";/////////////////////////////BORRA ESTA LINEA
				///////////////////////////////////////////////AQUI VA LO DE LA CONSOLA PARA HACER UNO NUEVO
				///////////////////////////////////////////////AQUI VA LO DE LA CONSOLA PARA HACER UNO NUEVO
				///////////////////////////////////////////////AQUI VA LO DE LA CONSOLA PARA HACER UNO NUEVO
				///////////////////////////////////////////////AQUI VA LO DE LA CONSOLA PARA HACER UNO NUEVO
			}
			if(mopc==60)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"Texto";/////////////////////////////BORRA ESTA LINEA
				///////////////////////////////////////////////AQUI VA EL ARCHIVO YA CREADO DESDE TXT
				///////////////////////////////////////////////AQUI VA EL ARCHIVO YA CREADO DESDE TXT
				///////////////////////////////////////////////AQUI VA EL ARCHIVO YA CREADO DESDE TXT
				///////////////////////////////////////////////AQUI VA EL ARCHIVO YA CREADO DESDE TXT
			}
			shar=0;
			break;
		///////////////////////////////////////////////TERMINA CASO F1
		///////////////////////////////////////////////TERMINA CASO F1
		///////////////////////////////////////////////TERMINA CASO F1
		
		
		///////////////////////////////////////////////CASO F2
		///////////////////////////////////////////////CASO F2
		///////////////////////////////////////////////CASO F2
		case 60:
			cat=0;
			shar=0;
			do{
				system("cls");
				menuco();
				mopc=getch();
				if(mopc==59||mopc==60||mopc==13||mopc==27)
				{
					cat=1;
				}
				if(mopc==9)
				{
					shar++;
				}
				if(shar==3)
				{
					shar=0;
				}
			}while(cat!=1);
			if(shar==0&&mopc==13)
			{
				mopc=59;
			}
			if(shar==1&&mopc==13)
			{
				mopc=60;
			}
			if(mopc==59)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"analizis de archivo";/////////////////////////////BORRA ESTA LINEA
				///////////////////////////////////////////////AQUI VA EL ANALIZIS DEL ARCHIVO
				///////////////////////////////////////////////AQUI VA EL ANALIZIS DEL ARCHIVO
				///////////////////////////////////////////////AQUI VA EL ANALIZIS DEL ARCHIVO
				///////////////////////////////////////////////AQUI VA EL ANALIZIS DEL ARCHIVO
				mopc=getch();/////////////////////////////BORRA ESTA LINEA
			}
			if(mopc==60)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"analizis de consola";/////////////////////////////BORRA ESTA LINEA
				///////////////////////////////////////////////AQUI VA EL ANALIZIS DE CONSOLA
				///////////////////////////////////////////////AQUI VA EL ANALIZIS DE CONSOLA
				///////////////////////////////////////////////AQUI VA EL ANALIZIS DE CONSOLA
				///////////////////////////////////////////////AQUI VA EL ANALIZIS DE CONSOLA
				mopc=getch();/////////////////////////////BORRA ESTA LINEA
			}
			shar=0;
			break;
		///////////////////////////////////////////////TERMINA CASO F2
		///////////////////////////////////////////////TERMINA CASO F2
		///////////////////////////////////////////////TERMINA CASO F2
		
		
		///////////////////////////////////////////////CASO F3
		///////////////////////////////////////////////CASO F3
		///////////////////////////////////////////////CASO F3
		case 61:
			cat=0;
			shar=0;
			do{
				system("cls");
				menuve();
				mopc=getch();
				if(mopc==59||mopc==60||mopc==61||mopc==62||mopc==63||mopc==13||mopc==27)
				{
					cat=1;
				}
				if(mopc==9)
				{
					shar++;
				}
				if(shar==6)
				{
					shar=0;
				}
			}while(cat!=1);
			if(shar==0&&mopc==13)
			{
				mopc=59;
			}
			if(shar==1&&mopc==13)
			{
				mopc=60;
			}
			if(shar==2&&mopc==13)
			{
				mopc=61;
			}
			if(shar==3&&mopc==13)
			{
				mopc=62;
			}
			if(shar==4&&mopc==13)
			{
				mopc=63;
			}
			if(mopc==59)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"codigo fuente";/////////////////////////////BORRA ESTA 
				///////////////////////////////////////////////AQUI VA EL CODIGO FUENTE
				///////////////////////////////////////////////AQUI VA EL CODIGO FUENTE
				///////////////////////////////////////////////AQUI VA EL CODIGO FUENTE
				///////////////////////////////////////////////AQUI VA EL CODIGO FUENTE
				getch();/////////////////////////////BORRA ESTA LINEA
			}
			if(mopc==60)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"analizis_LN";/////////////////////////////BORRA ESTA LINEA
				///////////////////////////////////////////////AQUI VA ANALIZIS_LN
				///////////////////////////////////////////////AQUI VA ANALIZIS_LN
				///////////////////////////////////////////////AQUI VA ANALIZIS_LN
				///////////////////////////////////////////////AQUI VA ANALIZIS_LN
				getch();/////////////////////////////BORRA ESTA LINEA
			}
			if(mopc==61)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"errores";/////////////////////////////BORRA ESTA LINEA
				///////////////////////////////////////////////AQUI VA ERRORES
				///////////////////////////////////////////////AQUI VA ERRORES
				///////////////////////////////////////////////AQUI VA ERRORES
				///////////////////////////////////////////////AQUI VA ERRORES
				getch();/////////////////////////////BORRA ESTA LINEA
			}
			if(mopc==62)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"codigo intermedio";/////////////////////////////BORRA ESTA LINEA
				///////////////////////////////////////////////AQUI VA CODIGO INTERMEDIO
				///////////////////////////////////////////////AQUI VA CODIGO INTERMEDIO
				///////////////////////////////////////////////AQUI VA CODIGO INTERMEDIO
				///////////////////////////////////////////////AQUI VA CODIGO INTERMEDIO
				getch();/////////////////////////////BORRA ESTA LINEA
			}
			if(mopc==63)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"codigo objeto";/////////////////////////////BORRA ESTA LINEA
				///////////////////////////////////////////////AQUI VA CODIGO OBJETO
				///////////////////////////////////////////////AQUI VA CODIGO OBJETO
				///////////////////////////////////////////////AQUI VA CODIGO OBJETO
				///////////////////////////////////////////////AQUI VA CODIGO OBJETO
				getch();/////////////////////////////BORRA ESTA LINEA
			}
			shar=0;
			break;
		///////////////////////////////////////////////TERMINA CASO F3
		///////////////////////////////////////////////TERMINA CASO F3
		///////////////////////////////////////////////TERMINA CASO F3
		
		///////////////////////////////////////////////¡¡¡¡¡¡DE AQUI HACIA ABAJO YA NO LE MUEVAS NADA. SOLO LA DIRECCION DEL TEXTO BNF!!!!!!
		///////////////////////////////////////////////¡¡¡¡¡¡DE AQUI HACIA ABAJO YA NO LE MUEVAS NADA. SOLO LA DIRECCION DEL TEXTO BNF!!!!!!
		///////////////////////////////////////////////¡¡¡¡¡¡DE AQUI HACIA ABAJO YA NO LE MUEVAS NADA. SOLO LA DIRECCION DEL TEXTO BNF!!!!!!
		///////////////////////////////////////////////CASO F4
		///////////////////////////////////////////////CASO F4
		///////////////////////////////////////////////CASO F4
		case 62:
			cat=0;
			shar=0;
			int opa=0;
			do{
				system("cls");
				menua();
				mopc=getch();
				if(mopc==59||mopc==60||mopc==61||mopc==13||mopc==27)
				{
					cat=1;
				}
				if(mopc==9)
				{
					shar++;
				}
				if(shar==4)
				{
					shar=0;
				}
			}while(cat!=1);
			if(shar==0&&mopc==13)
			{
				mopc=59;
			}
			if(shar==1&&mopc==13)
			{
				mopc=60;
			}
			if(shar==2&&mopc==13)
			{
				mopc=61;
			}
			if(mopc==59)
			{
				cat=0;
				shar=0;
				do{
					system("cls");
					menex();
					mopc=getch();
					if(mopc==59||mopc==60||mopc==61||mopc==13||mopc==27)
					{
						cat=1;
					}
					if(mopc==9)
					{
						shar++;
					}
					if(shar==3)
					{
						shar=0;
					}
				}while(cat!=1);
				if(shar==0&&mopc==13)
				{
					mopc=59;
				}
				if(shar==1&&mopc==13)
				{
					mopc=60;
				}
				if(shar==2&&mopc==13)
				{
					mopc=61;
				}
				if(mopc==59)
				{
					exple();
					getch();
				}
				if(mopc==60)
				{
					expin();
					getch();
					opa=1;
				}
			}
			if(mopc==60&&opa==0)
			{
				system("cls");
				ifstream archivo;
				string texto;
				archivo.open("C:\\Users\\Deriam\\Desktop\\BNF.txt",ios::in);//////////////////////////////cambia la direccion de BNF.txt
				if(archivo.fail())
				{
					cout<<"no se pudo abrir archivo";
				}
				while(!archivo.eof())
				{
					getline(archivo,texto);
					cout<<texto<<endl;
				}
				archivo.close();
				getch();
			}
			if(mopc==61)
			{
				system("cls");
				cout<<"Hecho por:\n";
				cout<<"Jair Emanuelle Mendoza Reynoso\n";
				cout<<"Farid Josua Olmedo Lopez\n";
				cout<<"Deriam Abraham Lule Ramirez\n";
				cout<<"Oscar Ivan Sanchez Lopez";
				getch();
			}
			shar=0;
			break;
		///////////////////////////////////////////////TERMINA CASO F4
		///////////////////////////////////////////////TERMINA CASO F4
		///////////////////////////////////////////////TERMINA CASO F4
	}
	///////////////////////////////////////////////tERMINA SWITCH
	///////////////////////////////////////////////tERMINA SWITCH
	///////////////////////////////////////////////tERMINA SWITCH
	}while(dog!=1);
}

void menu()
{
	if(shar==0)
	{
		cout<<"||-----------------||---------------||---------------||---------------||\n";
		cout<<"||>> F1. ARCHIVOS  ||  F2.COMPILAR  ||     F3.VER    ||   F4.AYUDA    ||\n";
		cout<<"||-----------------||---------------||---------------||---------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-----------------||---------------||---------------||---------------||\n";
		cout<<"||   F1. ARCHIVOS  ||>> F2.COMPILAR ||     F3.VER    ||   F4.AYUDA    ||\n";
		cout<<"||-----------------||---------------||---------------||---------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-----------------||---------------||---------------||---------------||\n";
		cout<<"||   F1. ARCHIVOS  ||   F2.COMPILAR ||    >>F3.VER   ||    F4.AYUDA   ||\n";
		cout<<"||-----------------||---------------||---------------||---------------||\n";
	}
	if(shar==3)
	{
		cout<<"||-----------------||---------------||---------------||---------------||\n";
		cout<<"||   F1. ARCHIVOS  ||   F2.COMPILAR ||      F3.VER   ||  >>F4.AYUDA   ||\n";
		cout<<"||-----------------||---------------||---------------||---------------||\n";
	}
}

void menuar()
{
	if(shar==0)
	{
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||>> F1. NUEVO CONSOLA  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   F2. ABRIR ARCHIVO  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   ESC. SALIR         ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   F1. NUEVO CONSOLA  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||>> F2. ABRIR ARCHIVO  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   ESC. SALIR         ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   F1. NUEVO CONSOLA  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   F2. ABRIR ARCHIVO  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||>> ESC. SALIR         ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
	}
}

void menuco()
{
	if(shar==0)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F1. ANALIZAR ARCHIVO  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALIZAR CONSOLA  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. ANALIZAR ARCHIVO  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F2. ANALIZAR CONSOLA  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. ANALIZAR ARCHIVO  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALIZAR CONSOLA  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
}

void menuve()
{
	if(shar==0)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==3)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==4)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==5)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
}

void menua()
{
	if(shar==0)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F1. MANUAL DE USUARIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. BNF               ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ACERCA DE         ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. MANUAL DE USUARIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F2. BNF               ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ACERCA DE         ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. MANUAL DE USUARIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. BNF               ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F3. ACERCA DE         ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==3)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. MANUAL DE USUARIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. BNF               ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ACERCA DE         ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
}

void menex()
{
	if(shar==0)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F1. SOBRE LENGUAJE    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. SOBRE INTERFAZ    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. SOBRE LENGUAJE    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F2. SOBRE INTERFAZ    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. SOBRE LENGUAJE    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. SOBRE INTERFAZ    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
}


void exple()
{
	system("cls");
	cout<<"Este lenguaje fue creado en base para reconocer palabras\n";
	cout<<"simples. Ademas de reconocer tembien algunas palabras de\n";
	cout<<"estructuras de control y de ciclos.\n";
	cout<<"Como extra puede reconocer si se esta haciendo una operacion\n";
	cout<<"aritmetica o logica.\n\n";
	cout<<"Estas son las palabras que reconoce\n";
	cout<<"si, no, entonces, este, mientras, para, desde, ir, parar,\n";
	cout<<"cortar, saltar, contrario, todo, inicio, principal, funcion.\n\n";
	cout<<"La sintaxis para reconocer si es una operacion logica o \n";
	cout<<"una  operacion aritmetica es:\n";
	cout<<"un numero o iniciar con un punto, el nombre del operando\n";
	cout<<"y un guion medio al final seguido de el operador aritmetico\n";
	cout<<"(+, _, X, /) o el operador logico (MEN, MAY, IGU, DIF) al \n";
	cout<<"final un numero o iniciar con un punto, el nombre del operando\n";
	cout<<"y termina con un guion medio.\n\n";
	cout<<"Para mas informacion consulte el BNF";
}

void expin()
{
	system("cls");
	cout<<"La interfaz funciona de dos formas distintas\n";
	cout<<"se puede mover entre las opciones precionando\n";
	cout<<"la tecla Tabulador y presionando enter en la\n"; 
	cout<<"opcion deseada o bien puede precionar las opciones\n";
	cout<<"precionando cualquiera de las teclas señaladas.\n";
}
