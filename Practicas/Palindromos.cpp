# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string.h>
#include <ctype.h>
using namespace std;
char frase[100],frase2[100];
int cont=0,si=0,no=0;
int main()
{
	cout<<"Ingrese una frase o palabra a verificar:\n";
	gets(frase);
	for(int y=0;y<=strlen(frase);y++)
	{
		frase[y]=toupper(frase[y]);
	}
	int i=strlen(frase);
	memset(frase2,0,sizeof(frase2));
	for( ;i>=0;i--)
	{
		if(frase[i]==' ')
		{
			
		}
		else
		{
			frase2[cont-1]=frase[i];
			cont++;
		}
	}
	i=0;
	
	for(int x=0;x<=strlen(frase);x++)
	{
		
		if(frase[i]==' ')
		{
			i+=2;
		}
		else
		{
			if(frase[i]==frase2[x])
			{
				si++;
			}
			else
			{
				no++;
			}
			i++;
		}	
	}
	if(no>0)
	{
		cout<<frase2<<"\n";
		cout<<"NO ES UNA FRASE O PLABRA PALINDROMA.\n";
	}
	else
	{
		cout<<frase2<<"\n";
		cout<<"ES UNA FRASE O PALABRA PALINDROMA.\n";
	}
}
