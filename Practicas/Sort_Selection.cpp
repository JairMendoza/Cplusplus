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
	int numeros[] = {3,4,5,2,1};
	int i,j,aux,min;
	
	for(i=0;i<5;i++)
	{
		min = i;
		for(j=i+1;j<5;j++)
		{	
			if(numeros[j] < numeros[min])
			{
				min = j;
			}
		}
		aux = numeros[i];
		numeros[i] = numeros[min];
		numeros[min] = aux;
	}
	
	cout<<"Orden Ascendente: ";
	for(i=0;i<5;i++)
	{
		cout<<numeros[i]<<" ";
	}
	
	cout<<"\nOrden Descendente: ";
	for(i=4;i>=0;i--)
	{
		cout<<numeros[i]<<" ";
	}
	
	getch();
	return 0;
}
