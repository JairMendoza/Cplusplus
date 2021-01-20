# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string.h>
# include <math.h>
# include <windows.h>
using namespace std;
void gotoxy(int,int);
void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
int main()
{
	int pri1=0,pri2=0,pri3=0,pri4=0,user1=0,user2=0,user3=0,prie1=0,prie2=0,error=0,x=7;
	do
	{
		system("cls");
		cout<<"Tenemos 4 servidores activos.\n";
		cout<<"Ingresa la prioridad de estos servidores.\n";
		cout<<"Prioridad 1: ";
		cin>>pri1;
		cout<<"\nPrioridad 2: ";
		cin>>pri2;
		cout<<"\nPrioridad 3: ";
		cin>>pri3;
		cout<<"\nPrioridad 4: ";
		cin>>pri4;
		cout<<"\nIngrese el numero de ususarios para la primera empresa.\n";
		cin>>user1;
		cout<<"\nIngrese el numero de ususarios para la segunda empresa.\n";
		cin>>user2;
		cout<<"\nIngrese el numero de ususarios para la tercera empresa.\n";
		cin>>user3;
		cout<<"Ingrese la prioridad de las empresas.\n";
		cout<<"Prioridad 1: ";
		cin>>prie1;
		cout<<"\nPrioridad 2: ";
		cin>>prie2;
		cout<<"\nPrioridad 3: ";
		cin>>prie3;
		
		system("cls");
		fflush (stdin);
		gotoxy(10,4); cout<<"Tiempo de respuesta: 3 min";
		gotoxy(10,5); cout<<"Servidor 1:";
		gotoxy(12,6); cout<<"9:00";
		gotoxy(10,4); cout<<"Tiempo de respuesta: 4 min";
		gotoxy(30,5); cout<<"Servidor 2:";
		gotoxy(32,6); cout<<"9:10";
		gotoxy(10,4); cout<<"Tiempo de respuesta: 6 min";
		gotoxy(50,5); cout<<"Servidor 3:";
		gotoxy(52,6); cout<<"9:30";
		gotoxy(10,4); cout<<"Tiempo de respuesta: 2 min";
		gotoxy(70,5); cout<<"Servidor 4:";
		gotoxy(72,6); cout<<"9:00";
		if(prie1>prie2&&prie1>prie3)
		{
			if(pri1==1)
			{
				gotoxy(10,x); cout<<"9:00-9:03 ";
				
			}
		}
		
	}while(error!=0);
}
