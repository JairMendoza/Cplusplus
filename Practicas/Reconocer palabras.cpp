# include <conio.h>
#include <dos.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string.h>
#include <ctype.h>
# include <iostream>
# include <windows.h>
# include <conio.h>
#include <string.h>
# include <locale.h>
# include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;
char palabra[40];
typedef struct diccionario
{
	char palabras[30];
}dic;
dic palabras1[16];
char aux11[30];
char verificar(char palabra1);
char identificar(char id);
void gotoxy(int,int);
void menu();
void menuar();
void menuco();
void menuve();
void menua();
void menex();
void exple();
void expin();
int shar=0;
int ban=1,correcto=0,y=0,validerr=0;

 enum Colors { blue=1, green, cyan, red, purple, yellow, grey, dgrey, hblue, hgreen, hred, hpurple, hyellow, hwhite };
void coutc(int color, char* output)
{
   HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute( handle, color);
   cout<< output;
   SetConsoleTextAttribute( handle, color);
}
char identificar(char palabra[10])
{
	int lon2=0,lonid=0,banid=0;
	lon2=strlen(palabra);		
			if(lon2!=0)
			{
				lonid=strlen(palabra);
				if(palabra[0]!='.'||palabra[lonid-1]!='-')
				{
					banid=1;
					validerr=1;	
				}
				if(lonid>10||lonid<3)
				{
					banid=1;
					validerr=2;
				}
				if(palabra[1]<97||palabra[1]>122)
				{
					banid=1;
					validerr=3;
				}
				for(int t=2;t<(lon2-1);t++)
				{
					if(isupper(palabra[t])==1)
					{
						banid=1;
						validerr=4;
					}
					if(isalnum(palabra[t])==0)
					{
						banid=1;
						validerr=5;
					}
				}
				if(palabra[0]==' ')
				{
					validerr=8;
				}
				if(banid==1)
				{
					correcto=1;
				}
				else
				{
					correcto=0;
				}
			}
}
char verificar(char palabras[800])
{
	int ban1=0,e=0,i=0,f=0,lon=0,ban2=0,banid=0,lonid=0,operacion=0,contop=0,valido=0,contador=0,val=0,idval=0,cuenta=0,siletra=0,puntos=0;
	char cadena[20],ident1[20],ident2[20],menor[5]="MEN",mayor[5]="MAY",igual[5]="IGU",diferente[5]="DIF",signo[3],mensaje1[40],mensaje2[40],mensaje3[40];	
	char * pch;
	FILE *pr;
	FILE *ph;
	FILE *po;
	FILE *ere;
	char* p; 
	char* q;
	char* h;
	char* o;
	pr=fopen("C:\\Users\\USER\\Documents\\analisis_LN.txt","wb+");
	ph=fopen("C:\\Users\\USER\\Documents\\codigo_intermedio.txt","wb+");
	po=fopen("C:\\Users\\USER\\Documents\\codigo_objeto.txt","wb+");
	ere=fopen("C:\\Users\\USER\\Documents\\error.txt","wb+");
	fseek(ph,0,0);
	fseek(pr,0,0);
	fseek(po,0,0);
	strcpy(palabras1[0].palabras,"si");
	strcpy(palabras1[1].palabras,"no");
	strcpy(palabras1[2].palabras,"entonces");
	strcpy(palabras1[3].palabras,"este");
	strcpy(palabras1[4].palabras,"mientras");
	strcpy(palabras1[5].palabras,"para");
	strcpy(palabras1[6].palabras,"desde");
	strcpy(palabras1[7].palabras,"ir");
	strcpy(palabras1[8].palabras,"parar");
	strcpy(palabras1[9].palabras,"cortar");
	strcpy(palabras1[10].palabras,"saltar");
	strcpy(palabras1[11].palabras,"contrario");
	strcpy(palabras1[12].palabras,"todo");
	strcpy(palabras1[13].palabras,"inicio");
	strcpy(palabras1[14].palabras,"principal");
	strcpy(palabras1[15].palabras,"funcion");	
	do
	{
		correcto=0;
		operacion=0;
		valido=0;
		contop=0;
		contador=0;
		validerr=0;	
		idval=0;
		val=0;
		siletra=0;
		e=0;
		banid=0;
		puntos=0;
		memset(signo,0,sizeof(signo));
		memset(palabra,0,sizeof(palabra));
		memset(ident1,0,sizeof(ident1));
		memset(ident2,0,sizeof(ident2));
		
		for(i=f;i<strlen(palabras);i++)
		{
			palabra[e]=palabras[i];
			f++;
			if(i==strlen(palabras)-1)
			{
				ban2=1;
			}
			if(palabra[e]=='\r')
			{
				palabra[e]='\0';
				break;	
			}
			e++;
		}
		int lon2=strlen(palabra);
		for(int c=0;c<strlen(palabra);c++)
		{
			if(palabra[c]=='+'||palabra[c]=='_'||palabra[c]=='X'||palabra[c]=='/')
			{
				operacion=1;
				signo[contop]=palabra[c];
				contop++;	
			}
		}
		q = strstr(signo,"++");
		if(q)
		{
			validerr=10;
		}
		q = strstr(signo,"+_");
		if(q)
		{
			validerr=11;
		}
		q = strstr(signo,"+X");
		if(q)
		{
			validerr=12;
		}
		q = strstr(signo,"+/");
		if(q)
		{
			validerr=13;
		}
		q = strstr(signo,"_+");
		if(q)
		{
			validerr=14;
		}
		q = strstr(signo,"__");
		if(q)
		{
			validerr=15;
		}
		q = strstr(signo,"_X");
		if(q)
		{
			validerr=16;
		}
		q = strstr(signo,"_/");
		if(q)
		{
			validerr=17;
		}
		q = strstr(signo,"XX");
		if(q)
		{
			validerr=18;
		}
		q = strstr(signo,"X+");
		if(q)
		{
			validerr=19;
		}
		q = strstr(signo,"X_");
		if(q)
		{
			validerr=20;
		}
		q = strstr(signo,"|");
		if(q)
		{
			validerr=21;
		}
		p = strstr(palabra,menor); 
		if(p)
		{
			siletra=1;
			cuenta=p-palabra;
			for(int b=0;b<strlen(palabra);b++)
			{
				if(b<cuenta)
				{
					ident1[b]=palabra[b];
				}
				if(b>=cuenta+3)
				{
					ident2[contador]=palabra[b];
					contador++;
				}
			}
			identificar(ident1);
					if(correcto==1)
					{
						idval++;
					}
					identificar(ident2);
					if(correcto==1)
					{
						idval++;
					}
					if(idval!=0)
					{
						if(idval==1)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'||palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								correcto=0;
							}
						}
						if(idval==2)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'&&palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								if(lon2==5)
								{
									correcto=0;
								}
							}
						}	
					}
					if(correcto==0)
					{
						coutc(green," ");
						gotoxy(13,y);cout<<ban;
						gotoxy(17,y);cout<<palabra;
						gotoxy(35,y);cout<<"Comparacion Valida.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"Comparacion Valida.\r\n");
						if(strlen(palabra)==3)
						{
							fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"50\r\n");
						    //fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(po,"01010000\r\n");
						}
						else
						{
						
						    fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"AB\r\n");
						    fprintf(po,"10101011\r\n");
					    }
						y++;
						ban2=0;	
						val=1;
					}		
		}
		p = strstr(palabra,mayor); 
		if(p)
		{
			siletra=1;
			cuenta=p-palabra;
			for(int b=0;b<strlen(palabra);b++)
			{
				if(b<cuenta)
				{
					ident1[b]=palabra[b];
				}
				if(b>=cuenta+3)
				{
					ident2[contador]=palabra[b];
					contador++;
				}
			}
			identificar(ident1);
					if(correcto==1)
					{
						idval++;
					}
					identificar(ident2);
					if(correcto==1)
					{
						idval++;
					}
					if(idval!=0)
					{
						if(idval==1)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'||palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								correcto=0;
							}
						}
						if(idval==2)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'&&palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								if(lon2==5)
								{
									correcto=0;
								}
							}
						}	
					}
					if(correcto==0)
					{
						coutc(green," ");
						gotoxy(13,y);cout<<ban;
						gotoxy(17,y);cout<<palabra;
						gotoxy(35,y);cout<<"Comparacion Valida.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"Comparacion Valida.\r\n");
						if(strlen(palabra)==3)
						{
							fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"50\r\n");
						    fprintf(po,"01010000\r\n");
						}
						else
						{
						    fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"AB\r\n");
						    fprintf(po,"10101011\r\n");
					    }
						y++;
						ban2=0;	
						val=1;
					}		
		}
		p = strstr(palabra,igual); 
		if(p)
		{
			siletra=1;
			cuenta=p-palabra;
			for(int b=0;b<strlen(palabra);b++)
			{
				if(b<cuenta)
				{
					ident1[b]=palabra[b];
				}
				if(b>=cuenta+3)
				{
					ident2[contador]=palabra[b];
					contador++;
				}
			}
			identificar(ident1);
					if(correcto==1)
					{
						idval++;
					}
					identificar(ident2);
					if(correcto==1)
					{
						idval++;
					}
					if(idval!=0)
					{
						if(idval==1)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'||palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								correcto=0;
							}
						}
						if(idval==2)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'&&palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								if(lon2==5)
								{
									correcto=0;
								}
							}
						}	
					}
					if(correcto==0)
					{
						coutc(green," ");
						gotoxy(13,y);cout<<ban;
						gotoxy(17,y);cout<<palabra;
						gotoxy(35,y);cout<<"Comparacion Valida.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"Comparacion Valida.\r\n");
						if(strlen(palabra)==3)
						{
							fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"50\r\n");
						    fprintf(po,"01010000\r\n");
						}
						else
						{
						    fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"AB\r\n");
						    fprintf(po,"10101011\r\n");
					    }
						y++;
						ban2=0;	
						val=1;
					}		
		}
		p = strstr(palabra,diferente); 
		if(p)
		{
			siletra=1;
			cuenta=p-palabra;
			for(int b=0;b<strlen(palabra);b++)
			{
				if(b<cuenta)
				{
					ident1[b]=palabra[b];
				}
				if(b>=cuenta+3)
				{
					ident2[contador]=palabra[b];
					contador++;
				}
			}
			identificar(ident1);
					if(correcto==1)
					{
						idval++;
					}
					identificar(ident2);
					if(correcto==1)
					{
						idval++;
					}
					if(idval!=0)
					{
						if(idval==1)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'||palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								correcto=0;
							}
						}
						if(idval==2)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'&&palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								if(lon2==5)
								{
									correcto=0;
								}
							}
						}	
					}
					if(correcto==0)
					{
						coutc(green," ");
						gotoxy(13,y);cout<<ban;
						gotoxy(17,y);cout<<palabra;
						gotoxy(35,y);cout<<"Comparacion Valida.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"Comparacion Valida.\r\n");
						if(strlen(palabra)==3)
						{
							fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"50\r\n");
						    fprintf(po,"01010000\r\n");
						}
						else
						{
						    fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"AB\r\n");
						    fprintf(po,"10101011\r\n");
					    }
						y++;
						ban2=0;	
						val=1;
					}		
		}
		else if(validerr==10||validerr==11||validerr==12||validerr==13||validerr==14||validerr==15||validerr==16||validerr==17||validerr==18||validerr==19||validerr==20||validerr==21)
		{
			
			coutc(red," ");
			gotoxy(13,y);cout<<ban;
			gotoxy(17,y);cout<<palabra;
			if(validerr==10)
			{
				gotoxy(35,y);cout<<"ERR 10 No se admiten operadores ++.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 10 No se admiten operadores ++.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 10 No se admiten operadores ++.\r\n");
			}
			if(validerr==11)
			{
				gotoxy(35,y);cout<<"ERR 11 No se admiten operadores +_.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 11 No se admiten operadores +_.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 11 No se admiten operadores +_.\r\n");
			}
			if(validerr==12)
			{
				gotoxy(35,y);cout<<"ERR 12 No se admiten operadores +X.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 12 No se admiten operadores +X.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 12 No se admiten operadores +X.\r\n");
			}
			if(validerr==13)
			{
				gotoxy(35,y);cout<<"ERR 13 No se admiten operadores +/.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 13 No se admiten operadores +/.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 13 No se admiten operadores +/.\r\n");
			}
			if(validerr==14)
			{
				gotoxy(35,y);cout<<"ERR 14 No se admiten operadores _+.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 14 No se admiten operadores _+.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 14 No se admiten operadores _+.\r\n");
			}
			if(validerr==15)
			{
				gotoxy(35,y);cout<<"ERR 15 No se admiten operadores __.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 15 No se admiten operadores __.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 15 No se admiten operadores __.\r\n");
			}
			if(validerr==16)
			{
				gotoxy(35,y);cout<<"ERR 16 No se admiten operadores _X.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 16 No se admiten operadores _X.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 16 No se admiten operadores _X.\r\n");
			}
			if(validerr==17)
			{
				gotoxy(35,y);cout<<"ERR 17 No se admiten operadores _/.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 17 No se admiten operadores _/.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 17 No se admiten operadores _/.\r\n");
			}
			if(validerr==18)
			{
				gotoxy(35,y);cout<<"ERR 18 No se admiten operadores XX.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 18 No se admiten operadores XX.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 18 No se admiten operadores XX.\r\n");
			}
			if(validerr==19)
			{
				gotoxy(35,y);cout<<"ERR 19 No se admiten operadores X+.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 19 No se admiten operadores X+.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 19 No se admiten operadores X+.\r\n");
			}
			if(validerr==20)
			{
				gotoxy(35,y);cout<<"ERR 20 No se admiten operadores X_.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 20 No se admiten operadores X_.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 20 No se admiten operadores X_.\r\n");
			}
			if(validerr==21)
			{
				gotoxy(35,y);cout<<"ERR 404 Desconocido.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"ERR 404 Desconocido.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ere);
				fprintf(ere,"ERR 404 Desconocido.\r\n");
			}
			y++;
		}
		else if(operacion==1)
		{
			if(valido==0)
			{
				pch = (char*) memchr (palabra, '+', strlen(palabra));
				if(pch!=NULL)
				{
					for(int v=0;v<strlen(palabra);v++)
					{
						if(pch-palabra>v)
						{
							ident1[v]=palabra[v];
						}
						if(pch-palabra<v)
						{
							ident2[contador]=palabra[v];
							contador++;
						}
					}
					identificar(ident1);
					if(correcto==1)
					{
						idval++;
					}
					identificar(ident2);
					if(correcto==1)
					{
						idval++;
					}
					if(idval!=0)
					{
						if(idval==1)
						{
							correcto=1;
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'||palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								correcto=0;
							}
							
						}
						if(idval==2)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'&&palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								if(lon2==3)
								{
									correcto=0;
								}
							}
						}	
					}
					if(correcto==0)
					{
						coutc(green," ");
						gotoxy(13,y);cout<<ban;
						gotoxy(17,y);cout<<palabra;
						gotoxy(35,y);cout<<"Suma Valida.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"Suma Valida.\r\n");
						if(strlen(palabra)==1)
						{
							fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"40\r\n");
						    fprintf(po,"01000000\r\n");
						}
						else
						{
						
						    fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"AA\r\n");
						    fprintf(po,"10101010\r\n");
					    }
						y++;
						ban2=0;	
						val=1;
					}	
				}
				pch = (char*) memchr (palabra, '_', strlen(palabra));
				if(pch!=NULL)
				{
					for(int v=0;v<strlen(palabra);v++)
					{
						if(pch-palabra>v)
						{
							ident1[v]=palabra[v];
						}
						if(pch-palabra<v)
						{
							ident2[contador]=palabra[v];
							contador++;
						}
					}
					identificar(ident1);
					if(correcto==1)
					{
						idval++;
					}
					identificar(ident2);
					if(correcto==1)
					{
						idval++;
					}
					if(idval!=0)
					{
						if(idval==1)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'||palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								correcto=0;
							}
						}
						if(idval==2)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'&&palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								if(lon2==3)
								{
									correcto=0;
								}
							}
						}	
					}
					if(correcto==0)
					{
						coutc(green," ");
						gotoxy(13,y);cout<<ban;
						gotoxy(17,y);cout<<palabra;
						gotoxy(35,y);cout<<"Resta Valida.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"Resta Valida.\r\n");
						if(strlen(palabra)==1)
						{
							fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"40\r\n");
						    fprintf(po,"01000000\r\n");
						}
						else
						{
						
						    fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"AA\r\n");
						    fprintf(po,"10101010\r\n");
					    }
						y++;
						ban2=0;	
						val=1;
					}	
				}
				pch = (char*) memchr (palabra, 'X', strlen(palabra));
				if(pch!=NULL)
				{
					///multiplicacion
					for(int v=0;v<strlen(palabra);v++)
					{
						if(pch-palabra>v)
						{
							ident1[v]=palabra[v];
						}
						if(pch-palabra<v)
						{
							ident2[contador]=palabra[v];
							contador++;
						}
					}
					identificar(ident1);
					if(correcto==1)
					{
						idval++;
					}
					identificar(ident2);
					if(correcto==1)
					{
						idval++;
					}
					if(idval!=0)
					{
						if(idval==1)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'||palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								correcto=0;
							}
						}
						if(idval==2)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'&&palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								if(lon2==3)
								{
									correcto=0;
								}
							}
						}	
					}
					if(correcto==0)
					{
						coutc(green," ");
						gotoxy(13,y);cout<<ban;
						gotoxy(17,y);cout<<palabra;
						gotoxy(35,y);cout<<"Multiplicacion Valida.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"Multiplicacion Valida.\r\n");
						if(strlen(palabra)==1)
						{
							fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"40\r\n");
						    fprintf(po,"01000000\r\n");
						}
						else
						{
						
						    fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"AA\r\n");
						    fprintf(po,"10101010\r\n");
					    }
						y++;
						ban2=0;	
						val=1;
					}	
				}
				pch = (char*) memchr (palabra, '/', strlen(palabra));
				if(pch!=NULL)
				{
					///divicion
					for(int v=0;v<strlen(palabra);v++)
					{
						if(pch-palabra>v)
						{
							ident1[v]=palabra[v];
						}
						if(pch-palabra<v)
						{
							ident2[contador]=palabra[v];
							contador++;
						}
					}
					identificar(ident1);
					if(correcto==1)
					{
						idval++;
					}
					identificar(ident2);
					if(correcto==1)
					{
						idval++;
					}
					if(idval!=0)
					{
						if(idval==1)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'||palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								correcto=0;
							}
						}
						if(idval==2)
						{
							if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0'&&palabra[lon2-1]=='1'||palabra[lon2-1]=='2'||palabra[lon2-1]=='3'||palabra[lon2-1]=='4'||palabra[lon2-1]=='5'||palabra[lon2-1]=='6'||palabra[lon2-1]=='7'||palabra[lon2-1]=='8'||palabra[lon2-1]=='9'||palabra[lon2-1]=='0')
							{
								if(lon2==3)
								{
									correcto=0;
								}
							}
						}	
					}
					if(correcto==0)
					{
						coutc(green," ");
						gotoxy(13,y);cout<<ban;
						gotoxy(17,y);cout<<palabra;
						gotoxy(35,y);cout<<"Divicion Valida.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"Divicion Valida.\r\n");
						if(strlen(palabra)==1)
						{
							fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"40\r\n");
						    fprintf(po,"01000000\r\n");
						}
						else
						{
						
						    fwrite(&palabra,sizeof(palabra),1,ph);
						    fprintf(ph,"AA\r\n");
						    fprintf(po,"10101010\r\n");
					    }
						y++;
						ban2=0;	
						val=1;
					}	
				}
				if(val==0)
				{
					coutc(red," ");
					gotoxy(13,y);cout<<ban;
					gotoxy(17,y);cout<<palabra;
					if(validerr==8)
					{
						gotoxy(35,y);cout<<"ERR 8 No debe de haber espacios en una operacion.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"ERR 8 No debe de haber espacios en una operacion.\r\n");
						fwrite(&palabra,sizeof(palabra),1,ere);
						fprintf(ere,"ERR 8 No debe de haber espacios en una operacion.\r\n");
					}
					y++;	
				}
			}
			else
			{
				coutc(red," ");
				gotoxy(13,y);cout<<ban;
				gotoxy(17,y);cout<<palabra;
				if(validerr==10)
			{
				gotoxy(35,y);cout<<"ERR 10 No se admiten operadores ++.";
			}
			if(validerr==11)
			{
				gotoxy(35,y);cout<<"ERR 11 No se admiten operadores +_.";
			}
			if(validerr==12)
			{
				gotoxy(35,y);cout<<"ERR 12 No se admiten operadores +X.";
			}
			if(validerr==13)
			{
				gotoxy(35,y);cout<<"ERR 13 No se admiten operadores +/.";
			}
			if(validerr==14)
			{
				gotoxy(35,y);cout<<"ERR 14 No se admiten operadores _+.";
			}
			if(validerr==15)
			{
				gotoxy(35,y);cout<<"ERR 15 No se admiten operadores __.";
			}
			if(validerr==16)
			{
				gotoxy(35,y);cout<<"ERR 16 No se admiten operadores _X.";
			}
			if(validerr==17)
			{
				gotoxy(35,y);cout<<"ERR 17 No se admiten operadores _/.";
			}
			if(validerr==18)
			{
				gotoxy(35,y);cout<<"ERR 18 No se admiten operadores XX.";
			}
			if(validerr==19)
			{
				gotoxy(35,y);cout<<"ERR 19 No se admiten operadores X+.";
			}
			if(validerr==20)
			{
				gotoxy(35,y);cout<<"ERR 20 No se admiten operadores X_.";
			}
			if(validerr==21)
			{
				gotoxy(35,y);cout<<"ERR 404 Desconocido.";
			}
				y++;
			}
		}
		else if(siletra==0)
		{
		
			lon2=strlen(palabra);
			
			if(lon2!=0)
			{
				lonid=strlen(palabra);
				if(palabra[0]!='.')
				{
					banid=1;	
					validerr=1;
				}
				if(palabra[lonid-1]!='-')
				{
					banid=1;	
					validerr=5;	
				}
				if(lonid>10)
				{
					banid=1;
					validerr=2;
				}
				if(lonid<=3)
				{
					banid=1;
					validerr=6;
				}
				if(palabra[1]<97||palabra[1]>122)
				{
					banid=1;
					validerr=3;
				}
				for(int t=2;t<(lon2-1);t++)
				{
					if(palabra[t]==' ')
					{
						banid=1;
						validerr=9;
					}
					if(isupper(palabra[t])==1)
					{
						banid=1;
						validerr=4;
					}
					if(isalnum(palabra[t])==0)
					{
						banid=1;
					}	
				}
				for(int o=0;o<lon2;o++)
				{
					if(palabra[o]=='.')
					{
						puntos++;
					}
				}
				if(puntos>1)
				{
					validerr=7;
				}
			}	
			for(int y=0; y<=16;y++)
			{
				if(ban2==1)
				break;
				if(strcmp(palabra,palabras1[y].palabras)==0)
				{
				  coutc(green," ");
					gotoxy(13,y);cout<<ban;
					gotoxy(17,y);cout<<palabra;
					gotoxy(25,y);cout<<"Palabra Correcta";
					fwrite(&palabra,sizeof(palabra),1,pr);
					fprintf(pr,"Palabra Correcta.\r\n");
					fwrite(&palabra,sizeof(palabra),1,ph);
				    fprintf(ph,"AC\r\n");
				    fprintf(po,"10101100\r\n");
					y++;
					ban2=0;
					break;
				}
				else
				{
					ban1++;
				}	
			}
			if(palabra[0]=='a'||palabra[0]=='b'||palabra[0]=='c'||palabra[0]=='d'||palabra[0]=='e'||palabra[0]=='f'||palabra[0]=='g'||palabra[0]=='h'||palabra[0]=='i'||palabra[0]=='j'||palabra[0]=='k'||palabra[0]=='l'||palabra[0]=='m'||palabra[0]=='n'||palabra[0]=='o'||palabra[0]=='p'||palabra[0]=='q'||palabra[0]=='r'||palabra[0]=='s'||palabra[0]=='t'||palabra[0]=='w'||palabra[0]=='x'||palabra[0]=='y'||palabra[0]=='z')
			{
				if(palabra[1]=='\0')
				{
						coutc(green," ");
					gotoxy(13,y);cout<<ban;
					gotoxy(17,y);cout<<palabra;
					gotoxy(35,y);cout<<"Letra minuscula correcta";
					fwrite(&palabra,sizeof(palabra),1,pr);
					fprintf(pr,"Letra minuscula Correcta.\r\n");
					fwrite(&palabra,sizeof(palabra),1,ph);
					fprintf(ph,"10\r\n");
					fprintf(po,"00010000\r\n");
					y++;
					ban2=0;
					ban1=0;
				}
			}
			if(palabra[0]=='A'||palabra[0]=='B'||palabra[0]=='C'||palabra[0]=='D'||palabra[0]=='F'||palabra[0]=='G'||palabra[0]=='H'||palabra[0]=='I'||palabra[0]=='J'||palabra[0]=='K'||palabra[0]=='L'||palabra[0]=='E'||palabra[0]=='M'||palabra[0]=='N'||palabra[0]=='O'||palabra[0]=='P'||palabra[0]=='Q'||palabra[0]=='R'||palabra[0]=='S'||palabra[0]=='T'||palabra[0]=='W'||palabra[0]=='X'||palabra[0]=='Y'||palabra[0]=='Z')
			{
				if(palabra[1]=='\0')
				{
					coutc(green," ");
					gotoxy(13,y);cout<<ban;
					gotoxy(17,y);cout<<palabra;
					gotoxy(35,y);cout<<"Letra Mayuscula correcta";
					fwrite(&palabra,sizeof(palabra),1,pr);
					fprintf(pr,"Letra Mayuscula Correcta.\r\n");
					fwrite(&palabra,sizeof(palabra),1,ph);
					fprintf(ph,"10\r\n");
					fprintf(po,"00010000\r\n");
					y++;
					ban2=0;
					ban1=0;
				}
			}
			int lonpal=0;
			lonpal=strlen(palabra);
			if(lonpal==1)
			{
			
			if(palabra[0]=='.'||palabra[0]==','||palabra[0]==';'||palabra[0]=='<'||palabra[0]=='>'||palabra[0]=='+'||palabra[0]=='-'||palabra[0]=='('||palabra[0]==')'||palabra[0]=='{'||palabra[0]=='}')
			{
			
				if(palabra[1]=='\0')
				{
						coutc(green," ");
					gotoxy(13,y);cout<<ban;
					gotoxy(17,y);cout<<palabra;
					gotoxy(35,y);cout<<"Caracter correcto";
					fwrite(&palabra,sizeof(palabra),1,pr);
					fprintf(pr,"Caracter Correcto.\r\n");
					fwrite(&palabra,sizeof(palabra),1,ph);
				    fprintf(ph,"30\r\n");
				    fprintf(po,"00110000\r\n");
					y++;
					ban2=0;
					ban1=0;
				}
			}
			}
			if(palabra[0]=='1'||palabra[0]=='2'||palabra[0]=='3'||palabra[0]=='4'||palabra[0]=='5'||palabra[0]=='6'||palabra[0]=='7'||palabra[0]=='8'||palabra[0]=='9'||palabra[0]=='0')
			{
				if(palabra[1]=='\0')
				{
					coutc(green," ");
					gotoxy(13,y);cout<<ban;
					gotoxy(17,y);cout<<palabra;
					gotoxy(35,y);cout<<"Numero correcto";
					fwrite(&palabra,sizeof(palabra),1,pr);
					fprintf(pr,"Numero Correcto.\r\n");
					fwrite(&palabra,sizeof(palabra),1,ph);
				    fprintf(ph,"20\r\n");
				    fprintf(po,"00100000\r\n");
					y++;
					ban2=0;
					ban1=0;
				}
			}
			if(ban1==17)
			{
				if(banid!=0)
				{
					coutc(red," ");
					gotoxy(13,y);cout<<ban;
					gotoxy(17,y);cout<<palabra;
					if(validerr==1)
					{
						gotoxy(35,y);cout<<"ERR 1 Falta punto al inicio.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"ERR 1 Falta punto al inicio.\r\n");
						fwrite(&palabra,sizeof(palabra),1,ere);
						fprintf(ere,"ERR 1 Falta punto al inicio.\r\n");
					}
					if(validerr==2)
					{
						gotoxy(35,y);cout<<"ERR 2 La long debe de ser menor a 10.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"ERR 2 La long debe de ser menor a 10.\r\n");
						fwrite(&palabra,sizeof(palabra),1,ere);
						fprintf(ere,"ERR 2 La long debe de ser menor a 10.\r\n");
					}
					if(validerr==3)
					{
						gotoxy(35,y);cout<<"ERR 3 Seguido del punto debe ser una minuscula.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"ERR 3 Seguido del punto debe ser una minuscula.\r\n");
						fwrite(&palabra,sizeof(palabra),1,ere);
						fprintf(ere,"ERR 3 Seguido del punto debe ser una minuscula.\r\n");
					}
					if(validerr==4)
					{
						gotoxy(35,y);cout<<"ERR 4 Un identificador no debe tener mayusculas.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"ERR 4 Un identificador no debe tener mayusculas.\r\n");
						fwrite(&palabra,sizeof(palabra),1,ere);
						fprintf(ere,"ERR 4 Un identificador no debe tener mayusculas.\r\n");
					}
					if(validerr==5)
					{
						gotoxy(35,y);cout<<"ERR 5 Falta un guion al final.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"ERR 5 Falta un guion al final.\r\n");
						fwrite(&palabra,sizeof(palabra),1,ere);
						fprintf(ere,"ERR 5 Falta un guion al final.\r\n");
					}
					if(validerr==6)
					{
						gotoxy(35,y);cout<<"ERR 6 La long debe ser mayor a 3";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"ERR 6 La long debe ser mayor a 3.\r\n");
						fwrite(&palabra,sizeof(palabra),1,ere);
						fprintf(ere,"ERR 6 La long debe ser mayor a 3.\r\n");
					}
					if(validerr==7)
					{
						gotoxy(35,y);cout<<"ERR 7 un id no puede contener mas de un punto.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"ERR 7 un id no puede contener mas de un punto.\r\n");
						fwrite(&palabra,sizeof(palabra),1,ere);
						fprintf(ere,"ERR 7 un id no puede contener mas de un punto.\r\n");
					}
					if(validerr==9)
					{
						gotoxy(35,y);cout<<"ERR 9 El id no debe contener espacios.";
						fwrite(&palabra,sizeof(palabra),1,pr);
						fprintf(pr,"ERR 9 El id no debe contener espacios.\r\n");
						fwrite(&palabra,sizeof(palabra),1,ere);
						fprintf(ere,"ERR 9 El id no debe contener espacios.\r\n");
					}
					
					y++;
				}
			}
			if(banid==0)
			{
				coutc(green," ");
				gotoxy(13,y);cout<<ban;
				gotoxy(17,y);cout<<palabra;
				gotoxy(35,y);cout<<"Identificador Valido.";
				fwrite(&palabra,sizeof(palabra),1,pr);
				fprintf(pr,"Identificador Valido.\r\n");
				fwrite(&palabra,sizeof(palabra),1,ph);
			    fprintf(ph,"0A\r\n");
			    fprintf(po,"00001010\r\n");
				y++;
				ban2=0;
			}
		}
		ban1=0;
		ban++;
		
	}while(ban2!=1);
	fclose(pr);	
	fclose(ph);
	fclose(po);
	fclose(ere)	;
}
/*int main()
{
	int ban=0,ban1=0,cont=0,e=0,var=0,cont2=0;
	char opc,letra,arreglo[200],opc2;
	char c='\0';
		do
		{
			var=0;
			system("cls");
			cout<<"Elija una opcion: \n";
			cout<<"1.-Ingresar codigo desde consola.\n";
			cout<<"2.-Ingresar codigo desde archivo de texto.\n";
			cout<<"opcion: ";
			opc2=getch();
			if(opc2=='2'||opc2=='1')
			{
				var=1;
			}
			
		}while(var!=1);
		if(opc2=='1')
		{
			cout<<"Vamos a ingresar palabras o caracteres para ver si estan dentro del lenguaje.\n";
			cout<<"Ingrese la palabra numero "<<cont<<"\n";
			memset(arreglo,0,sizeof(arreglo));
				do
				{
					letra='\0';
					letra= getch();
					cout<<letra;
					arreglo[cont]=letra;			
					fflush(stdin);
					cont++;
					if(letra==13)
					{
						arreglo[cont]='~';
						cout<<"\n";
					}
				}while(letra!=27);
				system("cls");
				verificar(arreglo);
		}
		if(opc2=='2')
		{
			FILE *pf;
			pf=fopen("C:\\Users\\USER\\Documents\\Archivo_fuente.txt","rb+");
			fseek(pf,0,0);
			do
			{
				c=fgetc(pf);
				if(c=='\n')
				{
					c=fgetc(pf);
				}
				arreglo[cont2]=c;
				cont2++;
			}while(c!=EOF);
			system("cls");
			verificar(arreglo);
			
			fclose(pf);
		}
}*/
main()
{
int cat=0,dog=0;
int ban=0,ban1=0,cont=0,e=0,var=0,cont2=0;
	char opc,letra,arreglo[200],opc2;
	char c='\0';
	char mopc='\0';
	do{
	do{	
		//memset(arreglo,0,sizeof(arreglo));
		system("cls");
		menu();
		mopc=getch();
		if(mopc==59||mopc==60||mopc==61||mopc==62||mopc==13||mopc==27)
		{
			cat=1;
		}
		if(mopc==9)
		{
			shar++;
		}
		if(shar==4)
		{
			shar=0;
		}
	}while(cat!=1);
	if(shar==0&&mopc==13)
	{
		mopc=59;
	}
	if(shar==1&&mopc==13)
	{
		mopc=60;
	}
	if(shar==2&&mopc==13)
	{
		mopc=61;
	}
	if(shar==3&&mopc==13)
	{
		mopc=62;
	}
	///////////////////////////////////////////////INICIA SWITCH
	switch(mopc)
	{
		///////////////////////////////////////////////CASO F1
		case 59:
			cat=0;
			shar=0;
			do{
				system("cls");
				menuar();
				
				mopc=getch();
				if(mopc==59||mopc==60||mopc==13||mopc==27)
				{
					cat=1;
				}
				if(mopc==9)
				{
					shar++;
				}
				if(shar==3)
				{
					shar=0;
				}
			}while(cat!=1);
			if(shar==0&&mopc==13)
			{
				mopc=59;
			}
			if(shar==1&&mopc==13)
			{
				mopc=60;
			}
			if(mopc==59)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"Vamos a ingresar palabras o caracteres para ver si estan dentro del lenguaje.\n";
				cout<<"Ingrese la palabra numero "<<cont<<"\n";
				memset(arreglo,0,sizeof(arreglo));
				do
				{
					letra='\0';
					letra= getch();
					cout<<letra;
					arreglo[cont]=letra;			
					fflush(stdin);
					cont++;
					if(letra==13)
					{
						arreglo[cont]='~';
						cout<<"\n";
					}
				}while(letra!=27);
				system("cls");
				getch();
			}
			if(mopc==60)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				FILE *pf;
				pf=fopen("C:\\Users\\USER\\Documents\\Archivo_fuente.txt","rb+");
				fseek(pf,0,0);
				do
				{
					c=fgetc(pf);
					if(c=='\n')
					{
						c=fgetc(pf);
					}
					arreglo[cont2]=c;
					cont2++;
				}while(c!=EOF);
				ifstream archivo;
				string texto;
				archivo.open("C:\\Users\\USER\\Documents\\Archivo_fuente.txt",ios::in);//////////////////////////////cambia la direccion de BNF.txt
				if(archivo.fail())
				{
					cout<<"no se pudo abrir archivo";
				}
				while(!archivo.eof())
				{
					getline(archivo,texto);
					cout<<texto<<endl;
				}
				archivo.close();
			//system("cls");
			
			fclose(pf);
			getch();

			}
			shar=0;
			break;
		///////////////////////////////////////////////TERMINA CASO F1

		///////////////////////////////////////////////CASO F2
		case 60:
			cat=0;
			shar=0;
			do{
				system("cls");
				menuco();
				mopc=getch();
				if(mopc==59||mopc==60||mopc==13||mopc==27)
				{
					cat=1;
				}
				if(mopc==9)
				{
					shar++;
				}
				if(shar==3)
				{
					shar=0;
				}
			}while(cat!=1);
			if(shar==0&&mopc==13)
			{
				mopc=59;
			}
			if(shar==1&&mopc==13)
			{
				mopc=60;
			}
			if(mopc==59)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				verificar(arreglo);
				getch();
			}
			if(mopc==60)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				//cout<<"analizis de consola\n";/////////////////////////////BORRA ESTA LINEA
				verificar(arreglo);	
				getch();/////////////////////////////BORRA ESTA LINEA
			}
			shar=0;
			break;
		///////////////////////////////////////////////TERMINA CASO F2
		
		///////////////////////////////////////////////CASO F3
		case 61:
			cat=0;
			shar=0;
			do{
				system("cls");
				menuve();
				mopc=getch();
				if(mopc==59||mopc==60||mopc==61||mopc==62||mopc==63||mopc==13||mopc==27)
				{
					cat=1;
				}
				if(mopc==9)
				{
					shar++;
				}
				if(shar==6)
				{
					shar=0;
				}
			}while(cat!=1);
			if(shar==0&&mopc==13)
			{
				mopc=59;
			}
			if(shar==1&&mopc==13)
			{
				mopc=60;
			}
			if(shar==2&&mopc==13)
			{
				mopc=61;
			}
			if(shar==3&&mopc==13)
			{
				mopc=62;
			}
			if(shar==4&&mopc==13)
			{
				mopc=63;
			}
			if(mopc==59)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"Codigo fuente\n";/////////////////////////////BORRA ESTA 
				ifstream archivo;
				string texto;
				archivo.open("C:\\Users\\USER\\Documents\\Archivo_fuente.txt",ios::in);//////////////////////////////cambia la direccion de BNF.txt
				if(archivo.fail())
				{
					cout<<"no se pudo abrir archivo";
				}
				while(!archivo.eof())
				{
					getline(archivo,texto);
					cout<<texto<<endl;
				}
				archivo.close();
				getch();/////////////////////////////BORRA ESTA LINEA
			}
			if(mopc==60)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"analizis_LN";/////////////////////////////BORRA ESTA LINEA
				ifstream archivo;
				string texto;
				archivo.open("C:\\Users\\USER\\Documents\\analisis_LN.txt",ios::in);//////////////////////////////cambia la direccion de BNF.txt
				if(archivo.fail())
				{
					cout<<"no se pudo abrir archivo";
				}
				while(!archivo.eof())
				{
					getline(archivo,texto);
					cout<<texto<<endl;
				}
				archivo.close();
				getch();
			}
			if(mopc==61)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"errores\n";/////////////////////////////BORRA ESTA LINEA
				ifstream archivo;
				string texto;
				archivo.open("C:\\Users\\USER\\Documents\\error.txt",ios::in);//////////////////////////////cambia la direccion de BNF.txt
				if(archivo.fail())
				{
					cout<<"no se pudo abrir archivo";
				}
				while(!archivo.eof())
				{
					getline(archivo,texto);
					cout<<texto<<endl;
				}
				archivo.close();
				getch();
			}
			if(mopc==62)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"codigo intermedio\n";/////////////////////////////BORRA ESTA LINEA
				ifstream archivo;
				string texto;
				archivo.open("C:\\Users\\USER\\Documents\\codigo_intermedio.txt",ios::in);//////////////////////////////cambia la direccion de BNF.txt
				if(archivo.fail())
				{
					cout<<"no se pudo abrir archivo";
				}
				while(!archivo.eof())
				{
					getline(archivo,texto);
					cout<<texto<<endl;
				}
				archivo.close();
				getch();/////////////////////////////BORRA ESTA LINEA
			}
			if(mopc==63)
			{
				system("cls");/////////////////////////////BORRA ESTA LINEA
				cout<<"codigo objeto\n";/////////////////////////////BORRA ESTA LINEA
				ifstream archivo;
				string texto;
				archivo.open("C:\\Users\\USER\\Documents\\codigo_objeto.txt",ios::in);//////////////////////////////cambia la direccion de BNF.txt
				if(archivo.fail())
				{
					cout<<"no se pudo abrir archivo";
				}
				while(!archivo.eof())
				{
					getline(archivo,texto);
					cout<<texto<<endl;
				}
				archivo.close();
				getch();/////////////////////////////BORRA ESTA LINEA
			}
			shar=0;
			break;
		///////////////////////////////////////////////TERMINA CASO F3
		///////////////////////////////////////////////CASO F4
		case 62:
			cat=0;
			shar=0;
			int opa=0;
			do{
				system("cls");
				menua();
				mopc=getch();
				if(mopc==59||mopc==60||mopc==61||mopc==13||mopc==27)
				{
					cat=1;
				}
				if(mopc==9)
				{
					shar++;
				}
				if(shar==4)
				{
					shar=0;
				}
			}while(cat!=1);
			if(shar==0&&mopc==13)
			{
				mopc=59;
			}
			if(shar==1&&mopc==13)
			{
				mopc=60;
			}
			if(shar==2&&mopc==13)
			{
				mopc=61;
			}
			if(mopc==59)
			{
				cat=0;
				shar=0;
				do{
					system("cls");
					menex();
					mopc=getch();
					if(mopc==59||mopc==60||mopc==61||mopc==13||mopc==27)
					{
						cat=1;
					}
					if(mopc==9)
					{
						shar++;
					}
					if(shar==3)
					{
						shar=0;
					}
				}while(cat!=1);
				if(shar==0&&mopc==13)
				{
					mopc=59;
				}
				if(shar==1&&mopc==13)
				{
					mopc=60;
				}
				if(shar==2&&mopc==13)
				{
					mopc=61;
				}
				if(mopc==59)
				{
					exple();
					getch();
				}
				if(mopc==60)
				{
					expin();
					getch();
					opa=1;
				}
			}
			if(mopc==60&&opa==0)
			{
				system("cls");
				ifstream archivo;
				string texto;
				archivo.open("C:\\Users\\USER\\Documents\\BNF.txt",ios::in);//////////////////////////////cambia la direccion de BNF.txt
				if(archivo.fail())
				{
					cout<<"no se pudo abrir archivo";
				}
				while(!archivo.eof())
				{
					getline(archivo,texto);
					cout<<texto<<endl;
				}
				archivo.close();
				getch();
			}
			if(mopc==61)
			{
				system("cls");
				cout<<"Hecho por:\n";
				cout<<"Jair Emanuelle Mendoza Reynoso\n";
				cout<<"Farid Josua Olmedo Lopez\n";
				cout<<"Deriam Abraham Lule Ramirez\n";
				cout<<"Oscar Ivan Sanchez Lopez";
				getch();
			}
			shar=0;
			break;
		///////////////////////////////////////////////TERMINA CASO F4
		///////////////////////////////////////////////TERMINA CASO F4
		///////////////////////////////////////////////TERMINA CASO F4
	}
	///////////////////////////////////////////////tERMINA SWITCH
	///////////////////////////////////////////////tERMINA SWITCH
	///////////////////////////////////////////////tERMINA SWITCH
	}while(dog!=1);
}

void menu()
{
	if(shar==0)
	{
		cout<<"||-----------------||---------------||---------------||---------------||\n";
		cout<<"||>> F1. ARCHIVOS  ||  F2.COMPILAR  ||     F3.VER    ||   F4.AYUDA    ||\n";
		cout<<"||-----------------||---------------||---------------||---------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-----------------||---------------||---------------||---------------||\n";
		cout<<"||   F1. ARCHIVOS  ||>> F2.COMPILAR ||     F3.VER    ||   F4.AYUDA    ||\n";
		cout<<"||-----------------||---------------||---------------||---------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-----------------||---------------||---------------||---------------||\n";
		cout<<"||   F1. ARCHIVOS  ||   F2.COMPILAR ||    >>F3.VER   ||    F4.AYUDA   ||\n";
		cout<<"||-----------------||---------------||---------------||---------------||\n";
	}
	if(shar==3)
	{
		cout<<"||-----------------||---------------||---------------||---------------||\n";
		cout<<"||   F1. ARCHIVOS  ||   F2.COMPILAR ||      F3.VER   ||  >>F4.AYUDA   ||\n";
		cout<<"||-----------------||---------------||---------------||---------------||\n";
	}
}

void menuar()
{
	if(shar==0)
	{
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||>> F1. NUEVO CONSOLA  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   F2. ABRIR ARCHIVO  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   ESC. SALIR         ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   F1. NUEVO CONSOLA  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||>> F2. ABRIR ARCHIVO  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   ESC. SALIR         ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   F1. NUEVO CONSOLA  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||   F2. ABRIR ARCHIVO  ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
		cout<<"||>> ESC. SALIR         ||\n";
		cout<<"||----------------------||\n";
		cout<<"||----------------------||\n";
	}
}

void menuco()
{
	if(shar==0)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F1. ANALIZAR ARCHIVO  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALIZAR CONSOLA  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. ANALIZAR ARCHIVO  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F2. ANALIZAR CONSOLA  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. ANALIZAR ARCHIVO  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALIZAR CONSOLA  ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
}

void menuve()
{
	if(shar==0)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==3)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==4)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==5)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. CODIGO FUENTE     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. ANALISIS_LN       ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ERRORES           ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F4. CODIGO INTERMEDIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F5. CODIGO OBJETO     ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
}

void menua()
{
	if(shar==0)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F1. MANUAL DE USUARIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. BNF               ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ACERCA DE         ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. MANUAL DE USUARIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F2. BNF               ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ACERCA DE         ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. MANUAL DE USUARIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. BNF               ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F3. ACERCA DE         ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==3)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. MANUAL DE USUARIO ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. BNF               ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F3. ACERCA DE         ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
}

void menex()
{
	if(shar==0)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F1. SOBRE LENGUAJE    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. SOBRE INTERFAZ    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==1)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. SOBRE LENGUAJE    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> F2. SOBRE INTERFAZ    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
	if(shar==2)
	{
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F1. SOBRE LENGUAJE    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||   F2. SOBRE INTERFAZ    ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
		cout<<"||>> ESC. SALIR            ||\n";
		cout<<"||-------------------------||\n";
		cout<<"||-------------------------||\n";
	}
}


void exple()
{
	system("cls");
	cout<<"Este lenguaje fue creado en base para reconocer palabras\n";
	cout<<"simples. Ademas de reconocer tembien algunas palabras de\n";
	cout<<"estructuras de control y de ciclos.\n";
	cout<<"Como extra puede reconocer si se esta haciendo una operacion\n";
	cout<<"aritmetica o logica.\n\n";
	cout<<"Estas son las palabras que reconoce\n";
	cout<<"si, no, entonces, este, mientras, para, desde, ir, parar,\n";
	cout<<"cortar, saltar, contrario, todo, inicio, principal, funcion.\n\n";
	cout<<"La sintaxis para reconocer si es una operacion logica o \n";
	cout<<"una  operacion aritmetica es:\n";
	cout<<"un numero o iniciar con un punto, el nombre del operando\n";
	cout<<"y un guion medio al final seguido de el operador aritmetico\n";
	cout<<"(+, _, X, /) o el operador logico (MEN, MAY, IGU, DIF) al \n";
	cout<<"final un numero o iniciar con un punto, el nombre del operando\n";
	cout<<"y termina con un guion medio.\n\n";
	cout<<"Para mas informacion consulte el BNF";
}

void expin()
{
	system("cls");
	cout<<"La interfaz funciona de dos formas distintas\n";
	cout<<"se puede mover entre las opciones precionando\n";
	cout<<"la tecla Tabulador y presionando enter en la\n"; 
	cout<<"opcion deseada o bien puede precionar las opciones\n";
	cout<<"precionando cualquiera de las teclas señaladas.\n";
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

