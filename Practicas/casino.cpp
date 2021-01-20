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

char volver;

int main()
{
	int dado1;
	int dado2; 
	int dinero=5000;
	int ganancia;
	int girar=0;
	int res;
	int ban; 
	int edad; 
	int can1;
	
	char opcion='\0', can[10];
	do
	{
	    system("cls");
		gotoxy(40,5); cout<<"----------------MENU----------------"<<endl;
		gotoxy(40,6); cout<<"[1].-Apostar entre $1 - $999        "<<endl;
		gotoxy(40,7); cout<<"[2].-Apostar entre $1000 - $4999    "<<endl;
		gotoxy(40,8); cout<<"[3].-Apostar entre $5000 - $10000   "<<endl;
		gotoxy(40,9); cout<<"[Esc] SALIR                         "<<endl;
		gotoxy(40,11);cout<<"INGRESE UNA OPCION:                 "<<endl;
		gotoxy(40,13);cout<<"Dinero disponible $" << dinero;
		gotoxy(60,11);opcion=getch();
	    switch(opcion)
		{
		    case 49: 
			do
			{
		        system("cls");
                srand(time(NULL));
		        cout<<"Cuanto deseas apostar? (Rango de apuesta $1 a $999) "<<endl;
		        cout<<"Saldo actual: "<<dinero<<endl;
		        memset(can,0,sizeof(can));
	            gets(can);
	            int lon=strlen(can);
	            int te=0;
	            for(int i=0;i<lon;i++)
	            {
		            te=isdigit(can[i]);
		            if(te==0)
		            ban=1;
                }
                if(lon==0)
	            ban=2;
	            edad=atoi(can);
	            if(ban==1)
	            {
                  	printf("Ingresaste letras en vez de numeros.\n");
                  	getch();
                  	break;
                }
	          
                if(edad>dinero)
                {
                	cout<<"Usted ya no tiene los fondos necesarios. "<<endl;
                	getch();
                	break;
				}
                if(edad<1||edad>999)
                {
                	cout<<"Solo puede apostar entre 1 a 999. "<<endl;
                	getch();
                	break;
				}

                 	if(dinero<0)
				{
					cout<<"Ya no tiene fondos. "<<endl;
					exit(0);
				}
                
                cout<<"Oprima cualquier tecla para tirar los dados. "<<endl;
                getch();
               	dado1 = rand() % 6 + 1;
				dado2 = rand() % 6 + 1;
                girar=dado1+dado2;
                cout<<"Dado 1: "<<endl<<dado1<<endl<<"Dado 2: "<<endl<<dado2<<endl<<"La suma de sus dados da: "<<endl<<girar<<endl;
                if(girar==7)
                {
                	cout<<"HAS GANADO!!!"<<endl;
                	dinero=dinero+edad;
                	cout<<"\t\tSus dolares actuales: "<<dinero<<" Sus dolares con el premio "<<edad<<endl;
				}
				else
				{
					cout<<endl<<"HAS PERDIDO!!!"<<endl<<"Perdiste la cantidad de: "<<edad<<endl;
					dinero=dinero-edad;
					cout<<"Su monto es actual es: "<<dinero<<endl<<endl;
					
				}
				cout<<"\t\t\t\tSi quieres volver a intentar oprima **S**. "<<endl;
				cout<<"\t\t\t\tSi usted quiere volver al menu oprima otra tecla. "<<endl;
				cin>>volver;
						
		    }while(volver=='S'||volver=='s');
		        break;
		        
			case 50: 
			do           
			{
				system("cls");
                srand(time(NULL));
		        cout<<"Cuanto deseas apostar? (Rango de apuesta $1000 a $4999) "<<endl;
		        cout<<"Saldo actual: "<<dinero<<endl;
		         memset(can,0,sizeof(can));
	            gets(can);
	            int lon=strlen(can);
	            int te=0;
	            for(int i=0;i<lon;i++)
	            {
		            te=isdigit(can[i]);
		            if(te==0)
		            ban=1;
                }
                if(lon==0)
	            ban=2;
	            edad=atoi(can);
	            if(ban==1)
	            {
                  	printf("Ingresaste letras en vez de numeros.\n");
                  	getch();
                  	break;
                }
                if(edad>dinero)
                {
                	cout<<"Usted ya no puede apostar, le sugerimos ir a otra categoria. "<<endl;
                	getch();
                	break;
				}
                if(edad<1000||edad>4999)
                {
                	cout<<"Solo puede apostar entre 1000 a 4999. "<<endl;
                	getch();
                	break;
				}

		        
					if(dinero<0)
				{
					cout<<"Usted ya no tiene fondos. "<<endl;
					getch();
					exit(0);
				}
				cout<<"Oprima cualquier tecla para tirar los dados. "<<endl;
                getch();
                dado1=1+rand()%6;
                dado2=1+rand()%6;
                girar=dado1+dado2;
                cout<<"Dado 1: "<<endl<<dado1<<endl<<"Dado 2: "<<endl<<dado2<<endl<<"La suma de sus dados da: "<<endl<<girar<<endl;
                if(girar==7)
                {
                	cout<<"HAS GANADO!!!"<<endl;
                	dinero=dinero+edad*2;
                	cout<<"\t\tSus dolares actuales: "<<dinero<<" Sus dolares con el premio "<<can<<endl;
				}
				else
				{
					cout<<endl<<"HAS PERDIDO!!!"<<endl<<"Perdiste la cantidad de: "<<edad*2<<endl;
					dinero=dinero-edad*2;
					cout<<"Su monto es actual es: "<<dinero<<endl<<endl;
					
				}
				cout<<"\t\t\t\tSi quieres volver a intentar oprima **S**. "<<endl;
				cout<<"\t\t\t\tSi usted quiere volver al menu oprima otra tecla. "<<endl;
				cin>>volver;
				
		    }while(volver=='S'||volver=='s');   
				break;         
		       
		    case 51: 
			do
		    {
		        system("cls");
                srand(time(NULL));
		        cout<<"Cuanto deseas apostar? (Rango de apuesta $5000 a $1000) "<<endl;
		        cout<<"Saldo actual: "<<dinero<<endl;
		         memset(can,0,sizeof(can));
	            gets(can);
	            int lon=strlen(can);
	            int te=0;
	            for(int i=0;i<lon;i++)
	            {
		            te=isdigit(can[i]);
		            if(te==0)
		            ban=1;
                }
                if(lon==0)
	            ban=2;
	            edad=atoi(can);
	            if(ban==1)
	            {
                  	printf("Ingresaste letras en vez de numeros.\n");
                  	getch();
                  	break;
                }
         	
                if(edad>dinero)
                {
                	cout<<"Usted ya no tiene los fondos necesarios. "<<endl;
                	getch();
                
                	break;
				}

                 	if(dinero<0)
				{
					cout<<"Usted ya no puede apostar. "<<endl;
					exit(0);
				}
                if(edad<5000||edad>10000)
                {
                	cout<<"Solo puede apostar entre 5000 a 10000. "<<endl;
                	getch();
                	break;
                
				}
				cout<<"Oprima cualquier tecla para tirar los dados. "<<endl;
                getch();
                dado1=1+rand()%6;
                dado2=1+rand()%6;
                girar=dado1+dado2;
                cout<<"Dado 1: "<<endl<<dado1<<endl<<"Dado 2: "<<endl<<dado2<<endl<<"La suma de sus dados da: "<<endl<<girar<<endl;
                if(girar==7)
                {
                	cout<<"HAS GANADO!!!"<<endl;
                	dinero=dinero+edad*3;
                	cout<<"\t\tSus dolares actuales: "<<dinero<<" Sus dolares con el premio "<<edad*3<<endl;
				}
				else
				{
					cout<<endl<<"HAS PERDIDO!!!"<<endl<<"Perdiste la cantidad de: "<<edad*3<<endl;
					dinero=dinero-edad*3;
					cout<<"Su monto es actual es: "<<dinero<<endl<<endl;
					
				}
				cout<<"\t\t\t\tSi quieres volver a intentar oprima **S**. "<<endl;
				cout<<"\t\t\t\tSi usted quiere volver al menu oprima otra tecla. "<<endl;
				cin>>volver;
						
		            }while(volver=='S'||volver=='s');
		            break;
		            
		                
	    }
	}while(opcion!=27);	
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
