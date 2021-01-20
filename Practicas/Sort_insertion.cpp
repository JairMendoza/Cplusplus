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

int main()
{
	int numeros[] = {3,5,1,4,2};
	int i,pos,aux;		
		
		for(i=0;i<5;i++)
		{
			pos = i; 
			aux = numeros[i];
			
			while((pos>0) && (numeros[pos-1] > aux))
			{
				numeros[pos] = numeros[pos-1];
				pos--;
			}
			numeros[pos] = aux;
		}


	
	cout<<"Orden Ascendente: ";
	for(i=0;i<5;i++){
		cout<<numeros[i]<<" ";
	}	
	getch();
	return 0;
}
