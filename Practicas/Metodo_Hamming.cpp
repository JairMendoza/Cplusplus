# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string.h>
# include <math.h>
# include <windows.h>
void gotoxy(int,int);
using namespace std;
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
	int num=0,contador=0,ban=0,ban2=0,cont=0,suma=0,f=0,num2=0,eme=0,k=-1,u=0,izquierda=0,derecha=0,p0=0,p1=0,im0=0,im1=0,p2=0,im2=0,p3=0,im3=0,p4=0,im4=0,error=0;
	long tot=0,total=0,total2=0,total3=0,total4=0,totalm=0;
	char m[20],m1[10],m2[10],ptr,ptr2,dig3[0],dig2[0],binhex[25],hexa2[4];
	char dig1[4],numero[1];
	
	do
	{	
		error=0;
		suma=0;
		ban=0;
		ban2=0;	
		contador=0;
		cont=0;
		ptr='\0';
		ptr2='\0';
		num=0;
		num2=0;
		total=0;
		total2=0;
		totalm=0;
		tot=0;
		total3=0;
		memset(binhex,0,sizeof(binhex));
		memset(numero,0,sizeof(numero));
		memset(m,0,sizeof(m));
		memset(m1,0,sizeof(m1));
		memset(m2,0,sizeof(m2));
		memset(dig2,0,sizeof(dig2));
		system("cls");
		cout<<"Ingrese el valor de TX: ";
		gets(m);
		for(int y=0;y<=strlen(m);y++)
		{
			ptr=m[y];
			if(ptr=='+'||ptr=='*')
			{
				if(ptr=='+')
				suma=1;
				if(ptr=='*')
				suma=2;
				strncpy( m1, m, y );
				ban2=1;
			}
			if(ban2==1)
			{
				cont++;
				m2[cont-1]=m[y+1];
			}
		}
		for(int w=0;w<=strlen(m);w++)
		{
			m[w]=toupper(m[w]);
			m1[w]=toupper(m1[w]);
			m2[w]=toupper(m2[w]);
		}
		memset(dig2,0,sizeof(dig2));
		ptr='\0';
		for(int x=strlen(m1);x>=0;x--)
		{
			ptr2=m1[x-1];
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
			if(x==strlen(m1))
				tot=num;
			if(x==strlen(m1+1))
				tot=num*16;	
			if(x==strlen(m1+2))
				tot=num*256;
			if(x==strlen(m1+3))
			tot=num*4096;
			if(x==strlen(m1+4))
			tot=num*65536;
			if(x==strlen(m1+5))
			tot=num*1048576;
			total+=tot;
			num=0;
			tot=0;
			
		}//fin for	
		memset(dig2,0,sizeof(dig2));
		ptr2='\0';
		num=0;
		memset(numero,0,sizeof(numero));
		num2=0;
		for(int u=strlen(m2);u>=0;u--)
		{
			ptr2=m2[u-1];
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
			if(u==strlen(m2))
				tot=num;
			if(u==strlen(m2+1))
				tot=num*16;	
			if(u==strlen(m2+2))
				tot=num*256;
			if(u==strlen(m2+3))
			tot=num*4096;
			if(u==strlen(m2+4))
			tot=num*65536;
			if(u==strlen(m2+5))
			tot=num*1048576;
			total2+=tot;
			num=0;
			tot=0;	
		}//fin for
		
		for(int x=strlen(m);x>=0;x--)
		{
			ptr2=m[x-1];
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
			if(x==strlen(m))
				tot=num;
			if(x==strlen(m+1))
				tot=num*16;	
			if(x==strlen(m+2))
				tot=num*256;
			if(x==strlen(m+3))
			tot=num*4096;
			if(x==strlen(m+4))
			tot=num*65536;
			if(x==strlen(m+5))
			tot=num*1048576;
			totalm+=tot;
			num=0;
			tot=0;
			
		}//fin for	
		
		
		cont=0;
		memset(binhex,0,sizeof(binhex));
		total3=total;
		total3+=total2;
		cout<<"Convirtiendo a binario...\n";
			itoa(total3,binhex,2);
		itoa(total2,hexa2,16);
		if(suma==2)
		{
			total3=0;
			total3=total*total2;
			itoa(total3,binhex,2);
			itoa(total2,hexa2,16);
		}
		if(suma==0)
		{
			itoa(totalm,binhex,2);
			itoa(total2,hexa2,16);	
		}
		if(strlen(binhex)>26)
		{
			cout<<"........ERROR......\n";
			cout<<"CADENA BINARIA NO SOPORTADA.\n";
			cout<<"32 Bits es la mayor capacidad en la transmision.\n";
			getch();
			error=1;
		}
	}while(error!=0);
		cout<<"Buscamos [M]\n";
		for(int e=1;e<=strlen(binhex);e++)
		{
			eme++;
		}
		ban=0;
		do
		{
			
			izquierda=pow(2,k)-1;
			derecha=eme+k;
			if(izquierda>derecha)
			{
				ban=1;
				k--; 
			}
			k++;
		}while(ban!=1);
		cout<<"\n[M]="<<eme;
		cout<<"\n[K]="<<k;
		
		
		for(int b=0;b<=strlen(binhex);b++)
		{
			ptr=binhex[b];
			if(b==0&&ptr=='1'||b==1&&ptr=='1'||b==3&&ptr=='1'||b==4&&ptr=='1'||b==6&&ptr=='1'||b==8&&ptr=='1'||b==10&&ptr=='1'||b==11&&ptr=='1'||b==13&&ptr=='1'||b==15&&ptr=='1'||b==17&&ptr=='1'||b==19&&ptr=='1'||b==21&&ptr=='1'||b==23&&ptr=='1'||b==25&&ptr=='1')
			p0++;
			if(b==0&&ptr=='0'||b==1&&ptr=='0'||b==3&&ptr=='0'||b==4&&ptr=='0'||b==6&&ptr=='0'||b==8&&ptr=='0'||b==10&&ptr=='0'||b==11&&ptr=='0'||b==13&&ptr=='0'||b==15&&ptr=='0'||b==17&&ptr=='0'||b==19&&ptr=='0'||b==21&&ptr=='0'||b==23&&ptr=='0'||b==25&&ptr=='0')
			im0++;
			
			if(b==0&&ptr=='1'||b==2&&ptr=='1'||b==3&&ptr=='1'||b==5&&ptr=='1'||b==6&&ptr=='1'||b==9&&ptr=='1'||b==10&&ptr=='1'||b==12&&ptr=='1'||b==13&&ptr=='1'||b==16&&ptr=='1'||b==17&&ptr=='1'||b==20&&ptr=='1'||b==21&&ptr=='1'||b==24&&ptr=='1'||b==25&&ptr=='1')
			p1++;
			if(b==0&&ptr=='0'||b==2&&ptr=='0'||b==3&&ptr=='0'||b==5&&ptr=='0'||b==6&&ptr=='0'||b==9&&ptr=='0'||b==10&&ptr=='0'||b==12&&ptr=='0'||b==13&&ptr=='0'||b==16&&ptr=='0'||b==17&&ptr=='0'||b==20&&ptr=='0'||b==21&&ptr=='0'||b==24&&ptr=='0'||b==25&&ptr=='0')
			im1++;
			
			if(b==1&&ptr=='1'||b==2&&ptr=='1'||b==3&&ptr=='1'||b==7&&ptr=='1'||b==8&&ptr=='1'||b==9&&ptr=='1'||b==10&&ptr=='1'||b==14&&ptr=='1'||b==15&&ptr=='1'||b==16&&ptr=='1'||b==17&&ptr=='1'||b==22&&ptr=='1'||b==23&&ptr=='1'||b==24&&ptr=='1'||b==25&&ptr=='1')
			p2++;
			if(b==1&&ptr=='0'||b==2&&ptr=='0'||b==3&&ptr=='0'||b==7&&ptr=='0'||b==8&&ptr=='0'||b==9&&ptr=='0'||b==10&&ptr=='0'||b==14&&ptr=='0'||b==15&&ptr=='0'||b==16&&ptr=='0'||b==17&&ptr=='0'||b==22&&ptr=='0'||b==23&&ptr=='0'||b==24&&ptr=='0'||b==25&&ptr=='0')
			im2++;
			
			if(b==4&&ptr=='1'||b==5&&ptr=='1'||b==6&&ptr=='1'||b==7&&ptr=='1'||b==8&&ptr=='1'||b==9&&ptr=='1'||b==10&&ptr=='1'||b==18&&ptr=='1'||b==19&&ptr=='1'||b==20&&ptr=='1'||b==21&&ptr=='1'||b==22&&ptr=='1'||b==23&&ptr=='1'||b==24&&ptr=='1'||b==25&&ptr=='1')
			p3++;
			if(b==4&&ptr=='0'||b==5&&ptr=='0'||b==6&&ptr=='0'||b==7&&ptr=='0'||b==8&&ptr=='0'||b==9&&ptr=='0'||b==10&&ptr=='0'||b==18&&ptr=='0'||b==19&&ptr=='0'||b==20&&ptr=='0'||b==21&&ptr=='0'||b==22&&ptr=='0'||b==23&&ptr=='0'||b==24&&ptr=='0'||b==25&&ptr=='0')
			im3++;
			
			if(b==11&&ptr=='1'||b==12&&ptr=='1'||b==13&&ptr=='1'||b==14&&ptr=='1'||b==15&&ptr=='1'||b==16&&ptr=='1'||b==17&&ptr=='1'||b==18&&ptr=='1'||b==19&&ptr=='1'||b==20&&ptr=='1'||b==21&&ptr=='1'||b==22&&ptr=='1'||b==23&&ptr=='1'||b==24&&ptr=='1'||b==25&&ptr=='1')
			p4++;
			if(b==11&&ptr=='0'||b==12&&ptr=='0'||b==13&&ptr=='0'||b==14&&ptr=='0'||b==15&&ptr=='0'||b==16&&ptr=='0'||b==17&&ptr=='0'||b==18&&ptr=='0'||b==19&&ptr=='0'||b==20&&ptr=='0'||b==21&&ptr=='0'||b==22&&ptr=='0'||b==23&&ptr=='0'||b==24&&ptr=='0'||b==25&&ptr=='0')
			im4++;
		}
		if(p0%2==0)
			p0=0;
		else
			p0=1;
		if(p1%2==0)
			p1=0;
		else
			p1=1;
		if(p2%2==0)
			p2=0;
		else
			p2=1;
		if(p3%2==0)
			p3=0;
		else
			p3=1;
		if(p4%2==0)
			p4=0;
		else
			p4=1;
		if(im0%2==0)
			im0=1;
		else
			im0=0;
		if(im1%2==0)
			im1=1;
		else
			im1=0;
		if(im2%2==0)
			im2=1;
		else
			im2=0;
		if(im3%2==0)
			im3=1;
		else
			im3=0;
		if(im4%2==0)
			im4=1;
		else
			im4=0;
		if(p1==1)
		p1=0;
		if(p3==1)
		p3=0;
		if(p4==1)
		p4=0;
		if(im1==1)
		im1=0;
		if(im3==1)
		im3=0;
		if(im4==1)
		im4=0;
		
			
			
	  cout<<"\n\n    |P0|P1|"<<binhex[0]<<" |P2|"<<binhex[1]<<" |"<<binhex[2]<<" |"<<binhex[3]<<" |"<<"P3|"<<binhex[4]<<" |"<<binhex[5]<<" |"<<binhex[6]<<" |"<<binhex[7]<<" |"<<binhex[8]<<" |"<<binhex[9]<<" |"<<binhex[10]<<" |"<<"P4|"<<binhex[11]<<" |"<<binhex[12]<<" |"<<binhex[13]<<" |"<<binhex[14]<<" |"<<binhex[15]<<" |"<<binhex[16]<<" |"<<binhex[17]<<" |"<<binhex[18]<<" |"<<binhex[19]<<" |"<<binhex[20]<<" |"<<binhex[21]<<" |"<<binhex[22]<<" |"<<binhex[23]<<" |"<<binhex[24]<<" |"<<binhex[25]<<" |"<<"P5|";
	    cout<<"\n    |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30|31|32|  P  |  I  |";
		cout<<"\nP0  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |X |  |  "<<p0<<"  |  "<<im0<<"  |";
		cout<<"\nP1  |  |X |X |  |  |X |X |  |  |X |X |  |  |X |X |  |  |X |X |  |  |X |X |  |  |X |X |  |  |X |X |  |  "<<p1<<"  |  "<<im1<<"  |";
		cout<<"\nP2  |  |  |  |X |X |X |X |  |  |  |  |X |X |X |X |  |  |  |  |X |X |X |X |  |  |  |  |X |X |X |X |  |  "<<p2<<"  |  "<<im2<<"  |";
		cout<<"\nP3  |  |  |  |  |  |  |  |X |X |X |X |X |X |X |X |  |  |  |  |  |  |  |  |X |X |X |X |X |X |X |X |  |  "<<p3<<"  |  "<<im3<<"  |";
		cout<<"\nP4  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |X |X |X |X |X |X |X |X |X |X |X |X |X |X |X |X |  |  "<<p4<<"  |  "<<im4<<"  |";
		cout<<"\nP5  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |X |  ";		
	getch();

}


