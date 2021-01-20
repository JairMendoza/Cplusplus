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
FILE *pd;

char caracter='\0';
char carpeta_dest[100];
char carpeta_ori[100];
int conta=0;

void Copia ();
void gotoxy(int,int);

int main ()
{
	int opcion;
	int salir = 1;
	
	do
	{
		system("cls");
		gotoxy(45,11); cout<<"____________MENU____________"<<endl;
		gotoxy(45,12); cout<<"[1] Copear archivo       	  "<<endl;
		gotoxy(45,13); cout<<"[Esc] SALIR                 "<<endl;
		gotoxy(45,15); cout<<"INGRESE UNA OPCION: ";fflush(stdin);
		gotoxy(65,15); opcion=getch();
		
		switch(opcion)
		{
			case 49: //1
		    
		    system("cls");
		    Copia ();
			
		    break;

			case 27: exit(-1);
		}
	}while(salir==1);
	return 0;
}
	
void Copia ()
{
	
	cout << "Que archivo desea copear?: " << endl;
	gets(carpeta_ori);
    pf = fopen(carpeta_ori, "r");
    cout << "A que directorio desea enviarlo?: " << endl;
    gets(carpeta_dest);
    pd = fopen(carpeta_dest, "w");
 
    if(pf == NULL || pd == NULL)
	{
          perror("El archivo de origen o la ruta de destino son erroneas");
          exit(0);
    }
    
    while(!feof(pf))
	{      
        caracter = getc(pf);
        fputc(toupper(caracter), pd);
        conta++;
    }
    cout << "son " << conta << " Caracteres del archivo!" << endl;
    cout << "Preciona una tecla para finalizar! \n" << endl;
    fclose(pf);
    fclose(pd);
    getch();
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


