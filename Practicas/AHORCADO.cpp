# include <iostream>
# include <windows.h>
# include <conio.h>
#include <string.h>
# include <locale.h>
# include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
struct categoria1
{
	char halo[5]="HALO";
	char fifa[5]="FIFA";
	char silent[12]="SILENT HILL";
	char evil[20]="RESIDENT EVIL";
	char final[20]="FINAL FANTASY";
	char street[20]="STREET FIGHTER";
	char mortal[20]="MORTAL KOMBAT";
	char killer[20]="KILLER INSTINCT";
	char pokemon[10]="POKEMON";
	char digimon[10]="DIGIMON";
}videojuegos;
struct categoria2aaaaa
{
	char padrino[20]="EL PADRINO";
	char django[20]="DJANGO";
	char iron[20]="IRON MAN";
	char pulp[20]="PULP FICTION";
	char the[20]="THE DARK NIGHT";
	char res[20]="EL RESPLANDOR";
	char toy[20]="TOY STORY";
	char avatar[20]="AVATAR";
	char tita[20]="TITANIC";
	char exo[20]="EL EXORCISTA";
}peliculas;
struct categoria3
{
	char len[20]="LENOVO";
	char sam[20]="SAMSUNG";
	char vans[20]="VANS";
	char nokia[20]="NOKIA";
	char her[20]="HERDES";
	char huwei[20]="HUAWEI";
	char coca[20]="COCA COLA";
	char apple[20]="APPLE";
	char intel[20]="INTEL";
	char nescafe[20]="NESCAFE";
}marcas;


//FUNCION GOTOXY ++++++++++++++++++++++++++++++++++++++++++++ 
void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 // fin de la funcion GOTOXY************************************************************


FILE *pf;
char user[10],palabra[20],letra[0],ye='\0',le='\0',punto[5],c='\0';
int ban=0,lon=0,puntos=0,opc=0,x=35,mal=5,no=0,let=3,acierto=0,espacio=0;
int main()
{
	
	
	
	time_t tiempo = time(NULL);//variables donde guardo el valor de la funcion time. 
    struct tm *tlocal = localtime(&tiempo); //estructura donde obtengo el tiempo 
     char date[11];
	strftime(date,11,"%d/%m/%Y",tlocal);//formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
    
	
	do
	{
		ban=0;
		system("cls");
		cout<<"Hola Bienvenid@ al juego de Ahorcado.\n";
		cout<<"Para empezar ingresa un nombre de usuario para registrar tu puntaje\n";
		gets(user);
		if(strlen(user)>10||strlen(user)==0)
		ban=1;
	}while(ban!=0);
	do
	{
		do
		{
			opc=0;
			system("cls");
			cout<<"Puntos: "<<puntos<<endl;
			cout<<"Seleccione una categoria"<<endl;
			cout<<"1.-Videojuegos. "<<endl;
			cout<<"2.-Peliculas. "<<endl;
			cout<<"3.-Marcas. "<<endl;
			cin>>opc;
		}while(opc>4||opc<0);
		srand(static_cast<unsigned>(time(NULL)));
	                int num = rand() % 9;
		switch(opc)
		{
			case 1: system("cls");
					gotoxy(0,0);cout<<"Puntos: "<<puntos;
					acierto=0;
					mal=5;
					acierto=0;
					espacio=0;
					x=35;
					let=3;
					
	                if(num==0)
	                strcpy(palabra,videojuegos.digimon);
	                if(num==1)
	                strcpy(palabra,videojuegos.evil);
	                if(num==2)
	                strcpy(palabra,videojuegos.fifa);
	                if(num==3)
	                strcpy(palabra,videojuegos.final);
	                if(num==4)
	                strcpy(palabra,videojuegos.halo);
	                if(num==5)
	                strcpy(palabra,videojuegos.killer);
	                if(num==6)
	                strcpy(palabra,videojuegos.mortal);
	                if(num==7)
	                strcpy(palabra,videojuegos.pokemon);
	                if(num==8)
	                strcpy(palabra,videojuegos.silent);
	                if(num==9)
	                strcpy(palabra,videojuegos.street);
	            }
	        }
	    }

