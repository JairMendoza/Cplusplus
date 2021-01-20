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

FILE *pf;
FILE *pa;

char carpeta_ori[100];
char carpeta_copy[100] = {"agenda_tmp.txt"};

char nombre[20];
char telefono[10];
char email[30];

char caracter='\0';
char Dspace = '*';
char Dend = '#';
char respuesta;

int ban = 0;
int aux = 0;
int lon;
int Rcreado=0;

void Crear ();
void Alta ();
void Mostrar ();
void Consultar ();
void Eliminar ();
void Editar ();
void gotoxy(int,int);

int ema;


int main ()
{
	//int salir = 1;
	do
	{	
		setlocale(LC_CTYPE, "Spanish");
		system("cls");
		gotoxy(45,7);  cout << "____________MENU____________" << endl;
		gotoxy(45,8);  cout << "[1] Abrir o Crear fichero   " << endl;
		gotoxy(45,9);  cout << "[2] Registrar               " << endl;
		gotoxy(45,10); cout << "[3] Mostrar registros       " << endl;
		gotoxy(45,11); cout << "[4] Consultar               " << endl;
		gotoxy(45,12); cout << "[5] Editar                  " << endl;
		gotoxy(45,13); cout << "[6] Eliminar                " << endl;
		gotoxy(45,14); cout << "[Esc] SALIR                 " << endl;
		gotoxy(45,16); cout << "INGRESE UNA OPCION: ";  fflush(stdin);
		gotoxy(65,16); respuesta=getch();
		
		switch(respuesta)
		{
			case 49: //1
		    
		    system("cls");
		    Crear ();
			
		    break;
		    
			case 50: //2
		
			system("cls");
			Alta ();	
			
		    break;

		    case 51: //3
		    
		    system("cls");
			Mostrar ();
				
		    break;
		    
		    case 52: //4
		    
		    system("cls");
			Consultar ();
				
		    break;
		    
		    case 53: //5
		    
		    system("cls");
			Editar ();
				
		    break;
		    
		    case 54: //6
		    
		    system("cls");
			Eliminar ();
				
		    break;

			case 27: //ESC
			//exit(-1);
			system("cls");
			gotoxy(50,11); cout<<"¡Hasta la proxima!";
		}
	}while(respuesta!=27);
	return 0;
}

int Arroba(char email[30])
{
	int arroba = 0;
	if (strlen(email) <= 30)
	{
		ema=atoi(email);
	if(ema<0 || ema>130)
	{
		cout << "¡Fuera de rango ingresa nuevamente el dato!\n";
		getch();
		return 0;
	}
	for (int i = 0; i < strlen(email); i++)

		if (email[i] == '@')
			arroba = arroba + 1;
		if (arroba == 1)
			return 1;
		else
			return 0;
	}return 0;
}
	
void Crear ()
{
	system("color C");
	memset(carpeta_ori,0,sizeof(carpeta_ori));
	do
	{
		do
		{
			cout << "¿Que archivo desea abrir o crear?: " << endl; 
			gets(carpeta_ori);
			
			unsigned int i;
			lon=strlen(carpeta_ori);
			aux=0;
			for (int i = 0; i < lon; i++)
			{
				if(carpeta_ori[lon-1] == 't' && carpeta_ori[lon-2] == 'x' && carpeta_ori[lon-3] == 't' && carpeta_ori[lon-4] == '.')
				{
					ban = 0;
				}
				else
				{
					ban = 1;
				}
			}
			if(ban == 1)
			{
				cout << "¡Es necesario el punto y la extencion txt!" << endl;
			}
		}while(ban == 1);
		if (lon == 0)
		{
	    	aux=1;
	    	cout << "¡Campo vacio!" << endl;
		}
		if(isspace(lon))
		{
			aux=1;
			cout << "¡No se admiten espacios!" << endl;
		}
	}while(aux == 1);
			
			
    pf = fopen(carpeta_ori, "r");
	
	if(pf==NULL)
	{
		system("color A");
		pf = fopen(carpeta_ori, "w");
		cout << "¡El archivo no exite pero fue creado!" << endl;
		Rcreado=1;
		getch();
	}
	else 
	{
		system("color A");
		cout << "¡Apertura exitosa!" << endl;
		Rcreado=1;
		getch();
	}
	
	fclose(pf);
}

void Alta ()
{	
	pf=fopen(carpeta_ori,"a");
	
	if(pf==NULL)
	{
		system("color C");
		cout << "¡No fue posible cargar el archivo para escribir!";
		exit(0);
		getch();
	}
	else
	{
		do
		{
			system("cls");
			memset(nombre,0,sizeof(nombre));
			memset(telefono,0,sizeof(telefono));
			memset(email,0,sizeof(email));
		
///////////////////////////////////////////////////////////////////////////////
		
			do
        	{
        		do
        		{
			        cout << "Ingresa un nombre: "; fflush(stdin);
			        gets(nombre);
			        lon=strlen(nombre);
			        aux = 0;
					for(int i = 0; i < lon; i++)
					{
						if(isalpha(nombre[i]) || isspace(nombre[i]))
					    ban = 0;
					    else
						{
					    ban = 1;
					    break;
					    }
				    }
				    if(ban == 1)
			   	    cout << "¡Solo letras!" << endl;
		   		}while(ban == 1);
		   			if (lon == 0)
					{
					   	aux = 1;
					   	cout << "¡Campo vacio!" << endl;
					}
		   	    	if(lon > 20)
					aux = 1;
					if(aux == 1)
					{
						cout << "¡Rango invalido! " << endl;
					}
	    	}while(aux == 1);
	
///////////////////////////////////////////////////////////////////////////////

        	do
        	{
        		do
        		{
			        cout << "Ingrese un numero de telefono: "; fflush(stdin);
			        gets(telefono);
			        lon=strlen(telefono);
			        aux = 0;
					for(int i=0; i < lon; i++)
					{
						if(isdigit(telefono[i]))
					    ban = 0;
					    else
						{
					    	ban = 1;
					    	break;
					    }
				    }
				    if(ban == 1)
			   	    cout << "¡Solo digitos!" << endl;
		   		}while(ban == 1);
	   	 		if (lon == 0)
				{
			    	aux=1;
			    	cout << "¡Campo vacio!" << endl;
				}
	   	    	if(lon!= 10 && lon!= 8)
				aux=1;
				if(aux == 1)
				{
					cout << "¡Rango invalido, solo numeros entre 8 y 10 digitos! " << endl;
				}
	   		}while(aux == 1);
	    
///////////////////////////////////////////////////////////////////////////////

			/*do
			{
				do
				{
					cout << "Ingresa una direccion de email: " << endl; fflush(stdin);
					gets(email);
					unsigned int i;
					lon=strlen(email);
					aux=0;
					for (int i = 0; i < lon; i++)
					{
						if(email[0] == '@' || email[lon-1])
						{
							ban = 0;
						}
						else
						{
							ban = 1;
						}
					}
					if(ban == 1)
					{
						cout << "Es necesario el simbolo @" << endl;
					}
				}while(ban == 1);
				if (lon == 0)
				{
			    	aux = 1;
			    	cout << "Campo vacio!" << endl;
				}
				if(isspace(lon))
				{
					aux = 1;
					cout << "No se admiten espacios!" << endl;
				}
			}while(aux == 1);*/
			
				do
				{	
				    cout << "Ingresa el email: "; fflush(stdin);
					gets(email);
					if (Arroba(email))
					{
						ban=1;
					}
					else
					{
						cout << "¡Dato incorrecto" << endl;
						ban=0;
					}
				}while (ban==0);
		
			fputs(nombre,pf);
			fputc(Dspace,pf);
			fputs(telefono,pf);
			fputc(Dspace,pf);
			fputs(email,pf);
			fputc(Dend,pf);
	
			do
			{	
				system("cls");
				cout << "¿Deseas agregar otro registro? S/N " << endl;
				respuesta=getch();
				
				if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
				{
					cout << "\n\nIntroduce una opcion: ";
					getch();
				}
			
			}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
		}while(respuesta=='s' || respuesta=='S');
	}
	fclose(pf);
}

void Mostrar ()
{	 	
 	pf = fopen(carpeta_ori,"r");
	if(pf==NULL)
	{
		system("color C");
		cout << "¡No se encontro el archivo para la lectura!";
		exit(0);
		getch();
	}
	else
	{
   		do
		{
			memset(nombre,0,sizeof(nombre));
	        memset(telefono,0,sizeof(telefono));
	        memset(email,0,sizeof(email));
	   
	        Rcreado=0;
	        
	        do
	        {
	        	caracter=fgetc(pf);
	        	if(caracter!='*')
	        	{
	        		nombre[Rcreado]=caracter;
				}
				Rcreado++;
			}while(caracter!='*'&&caracter!=EOF);
			Rcreado=0;
			do
	        {
	        	caracter=fgetc(pf);
	        	if(caracter!='*')
	        	{
	        		telefono[Rcreado]=caracter;
				}
				Rcreado++;
			}while(caracter!='*'&&caracter!=EOF);
			Rcreado=0;
			do
	        {
	        	caracter=fgetc(pf);
	        	if(caracter!='#')
	        	{
	        		email[Rcreado]=caracter;
				}
				Rcreado++;
			}while(caracter!='#'&&caracter!=EOF);
			Rcreado=0;
			
			if(!feof(pf))
			{
			cout << "____________________________" << endl;
			cout << "Nombre: "    << nombre   << endl;
			cout << "Telefono : " << telefono << endl;
			cout << "Email: "     << email    << endl;
			cout << "____________________________" << endl;
	        }
		}while(caracter!=EOF);
	}
	fclose(pf);
	getch();
}

void Consultar ()
{
	char buscar[100];
	
 	pf= fopen(carpeta_ori,"r");
 	
	if(pf==NULL)
	{
		system("color C");
		cout << "¡No se encontro el archivo para la lectura!";
		exit(0);
		getch();
	}
	else
	{
		cout << "Introduce su Nombre: "; fflush(stdin);
		gets(buscar);
			
   		do
		{
			memset(nombre,0,sizeof(nombre));
	        memset(telefono,0,sizeof(telefono));
	        memset(email,0,sizeof(email));
	   
	        Rcreado=0;
	        
	        do
	        {
	        	caracter=fgetc(pf);
	        	if(caracter!='*')
	        	{
	        		nombre[Rcreado]=caracter;
				}
				Rcreado++;
			}while(caracter!='*'&&caracter!=EOF);
			Rcreado=0;
			do
	        {
	        	caracter=fgetc(pf);
	        	if(caracter!='*')
	        	{
	        		telefono[Rcreado]=caracter;
				}
				Rcreado++;
			}while(caracter!='*'&&caracter!=EOF);
			Rcreado=0;
			do
	        {
	        	caracter=fgetc(pf);
	        	if(caracter!='#')
	        	{
	        		email[Rcreado]=caracter;
				}
				Rcreado++;
			}while(caracter!='#'&&caracter!=EOF);
			Rcreado=0;
			
			if(!strcmpi(buscar,nombre))
			{
			cout << "____________________________" << endl;
			cout << "Nombre: "    << nombre   << endl;
			cout << "Telefono : " << telefono << endl;
			cout << "Email: "     << email    << endl;
			cout << "____________________________" << endl;
	        }
	        
		}while(caracter!=EOF);
	}
	fclose(pf);
	getch();
}


void Editar ()
{
	char buscar[100];
	int respuesta2;
	
	do
	{
	 	pf = fopen(carpeta_ori,"r");
	 	pa = fopen(carpeta_copy, "w");
	 	
		if(pf==NULL)
		{
			system("color C");
			cout << "¡No se encontro el archivo para la lectura!";
			exit(0);
			getch();
		}
		else
		{	
			system("cls");
			cout << "\nIntroduce un nombre para buscarlo y editarlo: "; fflush(stdin);
			gets(buscar);
				
			do
			{
				respuesta = 'n';
				respuesta2 = 'n';
				memset(nombre,0,sizeof(nombre));
		        memset(telefono,0,sizeof(telefono));
		        memset(email,0,sizeof(email));
		   
		        Rcreado=0;
		        
		        do
		        {
		        	caracter=fgetc(pf);
		        	if(caracter!='*')
		        	{
		        		nombre[Rcreado]=caracter;
					}
					Rcreado++;
				}while(caracter!='*'&&caracter!=EOF);
				Rcreado=0;
				do
		        {
		        	caracter=fgetc(pf);
		        	if(caracter!='*')
		        	{
		        		telefono[Rcreado]=caracter;
					}
					Rcreado++;
				}while(caracter!='*'&&caracter!=EOF);
				Rcreado=0;
				do
		        {
		        	caracter=fgetc(pf);
		        	if(caracter!='#')
		        	{
		        		email[Rcreado]=caracter;
					}
					Rcreado++;
				}while(caracter!='#'&&caracter!=EOF);
				
				if(caracter!=EOF)
				{
					if(!strcmpi(buscar,nombre))
					{
						system("cls");
						cout << "\n____________________________" << endl;
						cout << "Nombre: "    << nombre   << endl;
						cout << "Telefono : " << telefono << endl;
						cout << "Email: "     << email    << endl;
						cout << "____________________________" << endl;
						do
						{
							cout << "\n\n¿Este es el registro que quieres modificar? S/N ";
							respuesta=getch();
				
						if(respuesta == 's' || respuesta == 'S')
						{
							do
				        	{
				        		do
				        		{
							        cout << "\n\n¿Cual es el nuevo nombre a editar?: "; fflush(stdin);
									gets(nombre);
							        lon=strlen(nombre);
							        aux = 0;
									for(int i = 0; i < lon; i++)
									{
										if(isalpha(nombre[i]) || isspace(nombre[i]))
									    ban = 0;
									    else
										{
									    ban = 1;
									    break;
									    }
								    }
								    if(ban == 1)
							   	    cout << "Solo letras!" << endl;
						   		}while(ban == 1);
						   			if (lon == 0)
									{
									   	aux = 1;
									   	cout << "Cadena vacia" << endl;
									}
						   	    	if(lon > 20)
									aux=1;
									if(aux == 1)
									{
										cout << "Rango invalido! " << endl;
									}
							}while(aux == 1);
									
									///////////////////////////////////////////////////////////////////////////////
									
									do
						        	{
						        		do
						        		{
									        cout << "\nCual es el nuevo numero a editar: "; fflush(stdin);
									        gets(telefono);
									        lon=strlen(telefono);
									        aux = 0;
											for(int i=0; i < lon; i++)
											{
												if(isdigit(telefono[i]))
											    ban = 0;
											    else
												{
											    	ban = 1;
											    	break;
											    }
										    }
										    if(ban == 1)
									   	    cout << "Solo digitos!" << endl;
								   		}while(ban == 1);
							   	 		if (lon == 0)
										{
									    	aux=1;
									    	cout << "Campo vacio!" << endl;
										}
							   	    	if(lon!= 10 && lon!= 8)
										aux=1;
										if(aux == 1)
										{
											cout << "Rango invalido, solo numeros entre 8 y 10 digitos! " << endl;
										}
							   		}while(aux == 1);
							    
									///////////////////////////////////////////////////////////////////////////////
						
									do
									{
										do
										{
											cout << "\nCual es el nuevo email a editar: "; fflush(stdin);
											gets(email);
											unsigned int i;
											lon=strlen(email);
											aux=0;
											for (int i = 0; i < lon; i++)
											{
												if(strchr(email, ('@')) != NULL)
												{
													ban = 0;
												}
												else
												{
													ban = 1;
												}
											}
											if(ban == 1)
											{
												cout << "Es necesario el simbolo @" << endl;
											}
										}while(ban == 1);
										if (lon == 0)
										{
									    	aux = 1;
									    	cout << "Campo vacio!" << endl;
										}
										if(isspace(lon))
										{
											aux = 1;
											cout << "No se admiten espacios!" << endl;
										}
									}while(aux == 1);
									
									cout << "\n\n\n¡Registro modificado con exito!";
									getch();
						}
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								cout << "\n\nIntroduce una opcion: ";
								getch();
							}
						
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
					}
						fputs(nombre,pa);
				    	fputc(Dspace,pa);
				    	
				    	fputs(telefono,pa);
				    	fputc(Dspace,pa);
				    	
						fputs(email,pa);
				    	fputc(Dend,pa);
		    	}
			}while(caracter!=EOF);
		
			fclose(pf);
			fclose(pa);
					
			remove(carpeta_ori);        
			rename(carpeta_copy,carpeta_ori);
		
			do
			{
				cout << "\n\n¿Deseas seguir editando? S/N ";
				respuesta2=getch();
		
				if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
				{
					cout << "\n\nIntroduce una opcion: ";
					getch();
				}
			}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
		}
	
	}while(respuesta2 == 's' || respuesta2 == 'S');
}

void Eliminar ()
{
	char buscar[100];
	int respuesta2;
	
	do
	{
	 	pf = fopen(carpeta_ori,"r");
	 	pa = fopen(carpeta_copy, "w");
	 	
		if(pf==NULL)
		{
			system("color C");
			cout << "¡No se encontro el archivo para la lectura!";
			exit(0);
			getch();
		}
		else
		{	
			system("cls");
			cout << "Introduce un nombre para buscarlo y eliminarlo: "; fflush(stdin);
			gets(buscar);
				
			do
			{
				respuesta2='n';
				respuesta='n';
				memset(nombre,0,sizeof(nombre));
		        memset(telefono,0,sizeof(telefono));
		        memset(email,0,sizeof(email));
		   
		        Rcreado=0;
		        
		        do
		        {
		        	caracter=fgetc(pf);
		        	if(caracter!='*')
		        	{
		        		nombre[Rcreado]=caracter;
					}
					Rcreado++;
				}while(caracter!='*'&&caracter!=EOF);
				Rcreado=0;
				do
		        {
		        	caracter=fgetc(pf);
		        	if(caracter!='*')
		        	{
		        		telefono[Rcreado]=caracter;
					}
					Rcreado++;
				}while(caracter!='*'&&caracter!=EOF);
				Rcreado=0;
				do
		        {
		        	caracter=fgetc(pf);
		        	if(caracter!='#')
		        	{
		        		email[Rcreado]=caracter;
					}
					Rcreado++;
				}while(caracter!='#'&&caracter!=EOF);
				Rcreado=0;
				
				if(caracter!=EOF)
				{
					if(!strcmpi(buscar,nombre))
					{      
						system("cls");
						cout << "\n____________________________" << endl;
						cout << "Nombre: "    << nombre   << endl;
						cout << "Telefono : " << telefono << endl;
						cout << "Email: "     << email    << endl;
						cout << "____________________________" << endl;
						do
						{
							cout << "\n\n¿Este es el registro que quieres eliminar? S/N ";
							respuesta=getch();
							
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								cout << "\n\nIntroduce una opcion: ";
								getch();
							}
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
					}
					
						if(respuesta == 's' || respuesta == 'S')
						{	
							cout << "\n\n\n¡Registro eliminado con exito!";
							getch();
						}
						else 
						{
							fputs(nombre,pa);
					    	fputc(Dspace,pa);
					    	
					    	fputs(telefono,pa);
					    	fputc(Dspace,pa);
					    	
							fputs(email,pa);
					    	fputc(Dend,pa);
						}	
		    	}
		    	
			}while(caracter!=EOF);
			
			fclose(pf);
			fclose(pa);
					
			remove(carpeta_ori);        
			rename(carpeta_copy,carpeta_ori);
		
			do
			{
				cout << "\n\n¿Deseas seguir eliminando? S/N ";
				respuesta2=getch();
		
				if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
				{
					cout << "\n\nIntroduce una opcion: ";
					getch();
				}
			}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
		}
	
	}while(respuesta2 == 's' || respuesta2 == 'S');
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
