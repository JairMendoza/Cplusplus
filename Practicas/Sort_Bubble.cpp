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
int array[5] = {2,3,1,5,4};
	int i,j,aux;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			if(array[j] > array[j+1])
			{
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
	}

	
	cout<<"Orden Ascendente: ";
	for(i=0;i<5;i++){
		cout<<array[i]<<" ";
	}	
	getch();
	return 0;
}
