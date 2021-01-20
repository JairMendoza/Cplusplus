# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string.h>
# include <math.h>
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int menu=0,numero=0,numeror=0,puntos=10,atinar=0;
	char jugar,palabra[20];
	char rana[10]="rana",negro[10]="negro",sandia[10]="sandia",borracho[10]="borracho",sol[10]="sol",luna[10]="luna",nopal[10]="nopal",cantarito[10]="cantarito",venado[10]="venado",dama[10]="dama",diablo[10]="diablo",chalupa[10]="chalupa",bandera[10]="bandera",campana[10]="campana",jaraz[10]="jaraz",bota[10]="bota",pajarito[10]="pajarito",mundo[10]="mundo",cotorro[10]="cotorro",apache[10]="apache";
	do
	{
		system("cls");
		cout<<"                                                                         PUNTOS: "<<puntos<<"\n";
		cout<<"                                 Bienvenido al casino BS.\n";
		cout<<"                           Cada ves que adivines ganaras 5 puntos.\n                            Si pierdes solo perderas 1 punto.\n                          Para empezar te regalaremos 10 puntos.\n";
		cout<<"\n                                   Que modo deseas jugar?\n";
		cout<<"                            1.-Adivinar un numero del 1 al 1000.\n";
		cout<<"                            2.-Adivinar una palabra entre 20.";
		cin>>menu;		
	}while(menu<=0||menu>=3);
	switch(menu)
	{
		case 1: do
				{
					system("cls");
					cout<<"                                                                         PUNTOS: "<<puntos<<"\n";
					numeror=rand()%(1001-1);
					cout<<"                                                                         "<<numeror<<"\n";
					cout<<"Ingrese el numero elegido: ";
					
					cin>>numero;
					
					if(numero==numeror)
					{
						cout<<"Felicidades atienaste el numero!!!!\n";
						cout<<"Ganaste 5 puntos!\n";
						puntos+=5;
						cout<<"Tienes "<<puntos<<" Puntos.\n";
					}
					else
					{
						cout<<"Suerte para la proxima D':'\n";
						cout<<"Perdiste 1 punto!\n";
						puntos--;
						cout<<"Tienes "<<puntos<<" Puntos.\n";
					}
					do
					{
						cout<<"Seguir jugando?S/N\n";
						jugar=getch();
					}while(jugar!='n'&&jugar!='N'&&jugar!='s'&&jugar!='S');
				}while(jugar=='s'||jugar=='S');
				system("cls");
				cout<<"TU PUNTUACION FINAL ES: "<<puntos;
				cout<<"\nVisitanos pronto!";
				break;
		case 2: do
				{
					numeror=0;
					atinar=0;
					system("cls");
					cout<<"                                                                         PUNTOS: "<<puntos<<"\n";
					memset(&palabra,0,sizeof(palabra));
					numeror=rand()%(21-1);
					cout<<"PISTA: Son nombres de cartas de un juego de mesa.\n";
					cout<<"Ingresa una palabra para adivinar: \n";
					if(numeror==1)
					{
						cout<<"PISTA!: Es un animal verde.\n";
						cin>>palabra;
						if(!strstr(rana,palabra)==0)
						atinar=1;
					}
					if(numeror==2)
					{
						cout<<"PISTA!: Puedes ser racista con el.\n";
						cin>>palabra;
						if(!strstr(negro,palabra)==0)
						atinar=1;
					}
					if(numeror==3)
					{
						cout<<"PISTA!: Es una fruta verde.\n";
						cin>>palabra;
						if(!strstr(sandia,palabra)==0)
						atinar=1;
					}
					if(numeror==4)
					{
						cout<<"PISTA!: Tacos parece uno.\n";
						cin>>palabra;
						if(!strstr(borracho,palabra)==0)
						atinar=1;
					}
					if(numeror==5)
					{
						cout<<"PISTA!: Da mucha luz.\n";
						cin>>palabra;
						if(!strstr(sol,palabra)==0)
						atinar=1;
					}
					if(numeror==6)
					{
						cout<<"PISTA!: Sale de noche.\n";
						cin>>palabra;
						if(!strstr(luna,palabra)==0)
						atinar=1;
					}
					if(numeror==7)
					{
						cout<<"PISTA!: Tiene espinas y se come.\n";
						cin>>palabra;
						if(!strstr(nopal,palabra)==0)
						atinar=1;
					}
					if(numeror==8)
					{
						cout<<"PISTA!: Sirve para llevar agua.\n";
						cin>>palabra;
						if(!strstr(cantarito,palabra)==0)
						atinar=1;
					}
					if(numeror==9)
					{
						cout<<"PISTA!: Asi te dicen cuando tu novia no es fiel.\n";
						cin>>palabra;
						if(!strstr(venado,palabra)==0)
						atinar=1;
					}
					if(numeror==10)
					{
						cout<<"PISTA!: Tiene gorro rojo y vestido azul.\n";
						cin>>palabra;
						if(!strstr(dama,palabra)==0)
						atinar=1;
					}
					if(numeror==11)
					{
						cout<<"PISTA!: Nos da clases y tiene nombre algo femenino.\n";
						cin>>palabra;
						if(!strstr(diablo,palabra)==0)
						atinar=1;
					}
					if(numeror==12)
					{
						cout<<"PISTA!: Va en un rio muy sonriente(sinonimo de deriam).\n";
						cin>>palabra;
						if(!strstr(chalupa,palabra)==0)
						atinar=1;
					}
					if(numeror==13)
					{
						cout<<"PISTA!: Verde blanco y rojo.\n";
						cin>>palabra;
						if(!strstr(bandera,palabra)==0)
						atinar=1;
					}
					if(numeror==14)
					{
						cout<<"PISTA!: Hace sonido y esta en los templos.\n";
						cin>>palabra;
						if(!strstr(campana,palabra)==0)
						atinar=1;
					}
					if(numeror==15)
					{
						cout<<"PISTA!: Empieza con 'J' y termina con 'z'.\n";
						cin>>palabra;
						if(!strstr(jaraz,palabra)==0)
						atinar=1;
					}
					if(numeror==16)
					{
						cout<<"PISTA!: Lo que usan los baqueros en el pie.\n";
						cin>>palabra;
						if(!strstr(bota,palabra)==0)
						atinar=1;
					}
					if(numeror==17)
					{
						cout<<"PISTA!: Es lo que le quitaron a nuño.\n";
						cin>>palabra;
						if(!strstr(pajarito,palabra)==0)
						atinar=1;
					}
					if(numeror==18)
					{
						cout<<"PISTA!: Es donde vivimos todos.\n";
						cin>>palabra;
						if(!strstr(mundo,palabra)==0)
						atinar=1;
					}
					if(numeror==19)
					{
						cout<<"PISTA!: Es un animal verde y pica.\n";
						cin>>palabra;
						if(!strstr(cotorro,palabra)==0)
						atinar=1;
					}
					if(numeror==20)
					{
						cout<<"PISTA!: Es una marca que salia en Familia con chabelo.\n";
						cin>>palabra;
						if(!strstr(apache,palabra)==0)
						atinar=1;
					}
					if(atinar==0)
					{	
						cout<<"Suerte para la proxima D':'\n";
						cout<<"Perdiste 1 punto!\n";
						puntos--;
						cout<<"Tienes "<<puntos<<" Puntos.\n";
					} 
					if(atinar==1)
					{
						cout<<"Felicidades Atinaste una de las 20 palabras!!!!";	
						cout<<"Ganaste 5 puntos!\n";
						puntos+=5;
						cout<<"Tienes "<<puntos<<" Puntos.\n";
					}
					do
					{
						cout<<"Seguir jugando?S/N\n";
						jugar=getch();
					}while(jugar!='n'&&jugar!='N'&&jugar!='s'&&jugar!='S');
				}while(jugar=='s'||jugar=='S');
				system("cls");
				cout<<"TU PUNTUACION FINAL ES: "<<puntos;
				cout<<"\nVisitanos pronto!";
			break;
	}
	
}

