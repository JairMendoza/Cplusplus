# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string.h>
# include <math.h>
using namespace std;
int main()
{
	int menu=0,valid=0,decimal=0,num=0,num2=0,valid2=0;
	long total=0,tot=0;
	char hexadecimal[20],octal[5],binario[100],ptr2,numero[1],dig2[0];
	do
	{
		system("cls");
		cout<<"Vamos a convertir un valor numerico a distintas bases.\n";
		cout<<"1.-De Decimal a (Hexadecima-Octal-Binario).\n";
		cout<<"2.-De Hexadecimal a (Octal-Binario-Decimal).\n";
		cout<<"3.-De Octal a (Hexadecimal-Binario-Decimal).\n";
		cin>>menu;
	}while(menu<0||menu>3);
	switch(menu)
	{
		case 1: do
				{
					system("cls");
					cout<<"Ingrese el numero a converir: ";
					cin>>decimal;
					if(decimal<0)
					valid=1;
					itoa(decimal,hexadecimal,16);
					itoa(decimal,octal,8);
					itoa(decimal,binario,2);
					cout<<"\nEl valor convertido a: \n";
					cout<<"Hexadecimal: "<<hexadecimal;
					cout<<"\nOctal: "<<octal;
					cout<<"\nBinario: "<<binario;
				}while(valid!=0);
			break;
		case 2: do
				{
					system("cls");
					valid2=0;
					memset(hexadecimal,0,sizeof(hexadecimal));
					cout<<"Ingrese el numero a converir: ";
					cin>>hexadecimal;
					if(strlen(hexadecimal)>5)
					valid2=1;
					for(int w=0;w<=3;w++)
					{
						hexadecimal[w]=toupper(hexadecimal[w]);
					}
					for(int u=strlen(hexadecimal);u>=0;u--)
					{
						ptr2=hexadecimal[u-1];
						if(ptr2=='A')
						num=10;
						if(ptr2=='B')
						num=11;
						if(ptr2=='C')
						num=12;
						if(ptr2=='D')
						num=13;
						if(ptr2=='E')
						num=14;
						if(ptr2=='F')
						num=15;
						if(ptr2!='A'&&ptr2!='B'&&ptr2!='C'&&ptr2!='D'&&ptr2!='E'&&ptr2!='F')
						{
							numero[0]=ptr2;
							memset(dig2,0,sizeof(dig2));
							num2=atoi(numero);
							num=num2;
						}	
						if(u==strlen(hexadecimal))
							tot=num;
						if(u==strlen(hexadecimal+1))
							tot=num*16;	
						if(u==strlen(hexadecimal+2))
							tot=num*256;
						if(u==strlen(hexadecimal+3))
						tot=num*4096;
						if(u==strlen(hexadecimal+4))
						tot=num*65536;
						total+=tot;
						num=0;
						tot=0;
					}
					decimal=total;
					itoa(decimal,octal,8);
					itoa(decimal,binario,2);
					cout<<"\nEl valor convertido a: \n";
					cout<<"Octal: "<<octal;
					cout<<"\nBinario: "<<binario;
					cout<<"\nDecimal: "<<decimal;
				}while(valid2!=0);
			break;
		case 3: do
				{
					int octal2=0;
					valid=0;
					
					system("cls");
					cout<<"Ingrese el numero a converir: ";
					cin>>octal2;
					
					if(octal2==8||octal2==9)
					valid=1;
					itoa(octal2,octal,10);
					for(int t=strlen(octal);t>=0;t--)
					{
						if(octal[t]=='8'||octal[t]=='9')
						valid=1;
					}
					
					
					decimal = 0; 
					int i = 0;

				    while(octal2 != 0)
				    {
				        decimal += (octal2%10) * pow(8,i);
				        ++i;
				        octal2/=10;
				    }
				    i = 1;
				    itoa(decimal,binario,2);
				    itoa(decimal,hexadecimal,16);
				    cout<<"\nEl valor convertido a: \n";
					cout<<"Hexadecimal: "<<hexadecimal;
					cout<<"\nBinario: "<<binario;
					cout<<"\nDecimal: "<<decimal;
					

				}while(valid!=0);
			break;
	}
}

