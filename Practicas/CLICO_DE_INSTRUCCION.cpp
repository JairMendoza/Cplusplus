# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string.h>
using namespace std;
int main()
{
	char dato1[3], dato2[4],dato3[4],dato4[4],dato5[4];
	int num=0,suma=0,tot=0,total=0,deci=0;
	int div1,div2,res1,res2,div3,div4,res3,res4,sum1,sum2,total2,ban=0;
	char ptr,dig1[0],hexa[3],h[0],hexa2[4],dig2[0],dig3[0],bin[5],dig4[0],binhex[30],ptr2[0],bini[5],ptr22;
	memset(dig1,0,sizeof(dig1));
	memset(h,0,sizeof(h));
	dig1[0]='0';
	
	do
	{	
		system("cls");
		cout<<"Ingrese el valor de PC(3 caracteres): ";
		gets(dato1);
		cout<<"Ingrese el VALOR DE AC(4 caracteres): ";
		gets(dato2);
		cout<<"Ingrese el dato para M["<<dato1<<"](4 caracteres): ";
		gets(dato3);
		cout<<"Ingrese el dato para M["<<dato3+1<<"](4 caracteres): ";
		gets(dato4);
		cout<<"Ingrese el dato para M["<<dato4+1<<"](4 caracteres): ";
		gets(dato5);
	}while(3!=strlen(dato1)||4!=strlen(dato2)||4!=strlen(dato3)||4!=strlen(dato4)||4!=strlen(dato5));
	for(int w=0;w<=3;w++)
	{
		dato1[w]=toupper(dato1[w]);
		dato2[w]=toupper(dato2[w]);
		dato3[w]=toupper(dato3[w]);
		dato4[w]=toupper(dato4[w]);
		dato5[w]=toupper(dato5[w]);
	}
	cout<<"T0 AR <- PC\n";
	cout<<"AR = "<<dato1;
	cout<<"\nT1: IR <- M [AR] PC <- PC +1 \n";
	cout<<"IR <- M["<<dato1<<"]. PC <- "<<dato1<<"+1 \n";
	memset(dig1,0,sizeof(dig1));
	for(int x=2;x>=0;x--)
	{
		ptr=dato1[x];
		if(ptr=='A')
		num=10;
		if(ptr=='B')
		num=11;
		if(ptr=='C')
		num=12;
		if(ptr=='D')
		num=13;
		if(ptr=='E')
		num=14;
		if(ptr=='F')
		num=15;
		if(ptr!='A'&&ptr!='B'&&ptr!='C'&&ptr!='D'&&ptr!='E'&&ptr!='F')
		{
			memset(dig2,0,sizeof(dig2));
			dig2[0]=ptr;
			num=atoi(dig2);
		}	
		if(x==2)
			tot=num;
		if(x==1)
			tot=num*16;	
		if(x==0)
		{
			tot=num*256;
		}
		total+=tot;
		num=0;
		tot=0;
		ptr='\0';
	}//fin for
	total+=1;//le sumamos 1 a pc
	//convertimos de decimal a hexadecimal
	itoa(total,hexa,16);
	cout<<"IR = "<<dato3<<" :. PC = "<<hexa;
	cout<<"\nT2: AR = "<<dato3+1<<"\n";
	ptr22=dato3[0];
	cout<<"D"<<ptr22<<"\n";
	cout<<"I 0\n";
	//deci=atoi(ptr22);
	//itoa(deci,bini,2);
	
	cout<<"D7|T3 = AR <- M["<<dato3+1<<"]\n";
	cout<<":.AR = "<<dato4<<"\n";
	cout<<"D1|T4: DR <- M["<<dato4+1<<"]\n";
	cout<<":. DR = "<<dato5<<"\n";
	cout<<"D1|T5: AC <- AC + DR\n";
	total=0;
	memset(dig1,0,sizeof(dig1));
	for(int y=3;y>=0;y--)
	{
		ptr=dato2[y];
		if(ptr=='A')
		num=10;
		if(ptr=='B')
		num=11;
		if(ptr=='C')
		num=12;
		if(ptr=='D')
		num=13;
		if(ptr=='E')
		num=14;
		if(ptr=='F')
		num=15;
		if(ptr!='A'&&ptr!='B'&&ptr!='C'&&ptr!='D'&&ptr!='E'&&ptr!='F')
		{
			dig3[0]=ptr;
			num=atoi(dig3);
		}	
		if(y==3)
			tot=num;
		if(y==2)
			tot=num*16;	
		if(y==1)
			tot=num*256;
		if(y==0)
			tot=num*4096;
		total+=tot;
		num=0;
		tot=0;
		ptr='\0';
	}//fin for
	sum1=total;
	total=0;
	for(int t=3;t>=0;t--)
	{
		ptr=dato5[t];
		if(ptr=='A')
		num=10;
		if(ptr=='B')
		num=11;
		if(ptr=='C')
		num=12;
		if(ptr=='D')
		num=13;
		if(ptr=='E')
		num=14;
		if(ptr=='F')
		num=15;
		if(ptr!='A'&&ptr!='B'&&ptr!='C'&&ptr!='D'&&ptr!='E'&&ptr!='F')
		{
			dig2[0]=ptr;
			num=atoi(dig2);
		}	
		if(t==3)
			tot=num;
		if(t==2)
			tot=num*16;	
		if(t==1)
			tot=num*256;
		if(t==0)
			tot=num*4096;
		total+=tot;
		num=0;
		tot=0;
		ptr='\0';
	}//fin for
	sum2=total;
	total=0;
	total2=sum1+sum2;
	itoa(total2,hexa2,16);
	itoa(total2,binhex,2);
	cout<<"AC = "<<hexa2<<"\n";
	if(hexa2[0]>10)
	{
		dig4[0]=hexa2[0];
		num=atoi(dig4);
		itoa(num,bin,2);
	}
	if(hexa2[0]=='a')
	{
		num=10;
		itoa(num,bin,2);
	}
	if(hexa2[0]=='b')
	{
		num=11;
		itoa(num,bin,2);
	}
	if(hexa2[0]=='c')
	{
		num=12;
		itoa(num,bin,2);
	}
	if(hexa2[0]=='d')
	{
		num=13;
		itoa(num,bin,2);
	}
	if(hexa2[0]=='e')
	{
		num=14;
		itoa(num,bin,2);
	}
	if(hexa2[0]=='f')
	{
		num=15;
		itoa(num,bin,2);
	}
	if(strlen(binhex)>16)
	{
		cout<<"E = 1\n";
	}
	else
	{
		cout<<"E = 0\n";
	}
	cout<<"SC = "<<bin;
}

