# include <iostream>
# include <windows.h>
# include <conio.h>
# include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include <bitset>
#include <sstream>
#include <math.h>
#include <time.h>

using namespace std;

typedef struct loteria
{
	char cat_videojuegos[30];
	char cat_peliculas[30];
	char cat_jugadores_fut[30];
}lot;
int n=0,menu=0;
int main()
{
	lot categorias[10];
	lot categorias1[10];
	char salir;
	
	int ban=0;
	char numero[50];

	do
	{
		 menu=0;
        system("cls");
		ban=0;
		cout<<endl;
		cout<<"Puntos "<<n<<endl;
		cout<<"Bienvenido seleccione una categoria"<<endl;
		cout<<"1.-Videojuegos. "<<endl;
		cout<<"2.-Peliculas. "<<endl;
		cout<<"3.-Jugadores de futbol "<<endl;
		gets(numero);
		for (int i=0; i<strlen(numero); i++)
	    {
	        if (isdigit(numero[i]))
	        {
	        	
			}
			else
			{
				ban=1;
			}
	    }
	}while(ban==1);
	ban=0;
    menu=atoi(numero);
   	switch(menu)
   	{
   		case 1:  
	    {
	    	char letra[100];
	    	memset(letra,0,sizeof(letra));
	    		srand(static_cast<unsigned>(time(NULL)));
                int num = rand() % 9;
	            strcpy(categorias[0].cat_videojuegos,"Halo");
	            strcpy(categorias[1].cat_videojuegos,"Fifa");
	            strcpy(categorias[2].cat_videojuegos,"Silent hill");
	            strcpy(categorias[3].cat_videojuegos,"Resident evil");
	            strcpy(categorias[4].cat_videojuegos,"Final fantasy");
	            strcpy(categorias[5].cat_videojuegos,"Street fighter");
	            strcpy(categorias[6].cat_videojuegos,"Mortal kombat");
	            strcpy(categorias[7].cat_videojuegos,"Killer instinct");
	            strcpy(categorias[8].cat_videojuegos,"Pokemon");
	            strcpy(categorias[9].cat_videojuegos,"Digimon");
				if(num==0)
				{
			    	cout<<"Palabra adivinar: "<<categorias[0].cat_videojuegos<<endl; strcpy(letra,categorias[0].cat_videojuegos);		    	
			    }	   
			   	if(num==1)	
			   	{   
				  	cout<<"Palabra adivinar: "<<categorias[1].cat_videojuegos<<endl; strcpy(letra,categorias[1].cat_videojuegos);
				}	
				if(num==2)
				{
					cout<<"Palabra adivinar: "<<categorias[2].cat_videojuegos<<endl;  strcpy(letra,categorias[2].cat_videojuegos);
			    }
				if(num==3)	
				{
					cout<<"Palabra adivinar: "<<categorias[3].cat_videojuegos<<endl; strcpy(letra,categorias[3].cat_videojuegos);
				}
				if(num==4)
				{
			    	cout<<"Palabra adivinar: "<<categorias[4].cat_videojuegos<<endl; strcpy(letra,categorias[4].cat_videojuegos);
				}
				if(num==5)	
				{
				 cout<<"Palabra adivinar: "<<categorias[5].cat_videojuegos<<endl;  strcpy(letra,categorias[5].cat_videojuegos);
				}
				if(num==6)
			    {
					cout<<"Palabra adivinar: "<<categorias[6].cat_videojuegos<<endl; strcpy(letra,categorias[6].cat_videojuegos);
				}
				if(num==7)	
				{
					cout<<"Palabra adivinar: "<<categorias[7].cat_videojuegos<<endl; strcpy(letra,categorias[7].cat_videojuegos);
				}
				if(num==8)
			    {
					cout<<"Palabra adivinar: "<<categorias[8].cat_videojuegos<<endl; strcpy(letra,categorias[8].cat_videojuegos);
				}
				if(num==9)
				{
				 	cout<<"Palabra adivinar: "<<categorias[9].cat_videojuegos<<endl; strcpy(letra,categorias[9].cat_videojuegos); 
	        	}
	        	
	        	cout<<endl<<letra<<endl;
	    }
	    break;
	    case 2:
	    	{
	    	    strcpy(categorias1[0].cat_peliculas,"Scary movie");
	            strcpy(categorias1[1].cat_peliculas,"Avengers");
	            strcpy(categorias1[2].cat_peliculas,"Spiderman");
	            strcpy(categorias1[3].cat_peliculas,"Ironman");
	            strcpy(categorias1[4].cat_peliculas,"Matrix");
	            strcpy(categorias1[5].cat_peliculas,"Venom");
	            strcpy(categorias1[6].cat_peliculas,"Origen");
	            strcpy(categorias1[7].cat_peliculas,"DonnieDarko");
	            strcpy(categorias1[8].cat_peliculas,"Exmachine");
	            strcpy(categorias1[9].cat_peliculas,"Her");	 
			}
	  break;
	
	}	
}
