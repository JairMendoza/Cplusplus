
// Arturo Cuevas Pérez 
// 3er Semestre Ing. Computación UteG
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#include<time.h>

using namespace std;

typedef struct musica 
{
    char Codigo [5];
    char NombreAlbum [20];
    char NombreArtista [20];
    int  Publicacion;
    int  NumTracks;
    char Genero [20];
    int  Tiempo;
    int  Reliminado;
} DATOS;
///////////////////////////////////////////////
DATOS dat;
FILE *pf;
char carpeta_ori[300];
///////////////////////////////////////////////
int  Ascii=0;
int  lon = 0;
int  aux = 0;
int  ban = 0;
int  Rcreado = 0;
char respuesta2;
char respuesta3;
char respuesta;
char caracter = '\0';
char buscar[50];
char Clave[30];
///////////////////////////////////////////////
char Menu  (void);
int  Contador  ();
int  Hash();
int  Val_Ascii();
void Codigo    ();
void Crear     ();
void Alta 	   ();
void Mostrar   ();
void Consultar ();
void Editar    ();
void Eliminar  ();
void Restaurar ();
void Papelera  ();
void ShowR     ();
void GeneroV   ();
void SwitchE   ();
void gotoxy(int,int);
void Setcolor(WORD color);
void ResetColor(WORD Attributes);
///////////////////////////////////////////////

int main ()
{
	char Opcion;
	
	do
	{
		Opcion = Menu();
		
		switch(Opcion)
		{	
			case 59: //F1
		    system("cls");
		    Crear (); break;
		    
			case 60: //F2
			system("cls");
			Alta (); break;

		    case 61: //F3
		    system("cls");
			Mostrar (); break;
		    
		    case 62: //F4
		    system("cls");
			Consultar (); break;
		    
		    case 63: //F5
		    system("cls");
			Editar (); break;
		    
		    case 64: //F6
		    system("cls");
			Eliminar (); break;
		
			case 27: //ESC
			system("cls");
			gotoxy(50,11); cout<<"¡Hasta la proxima!";
		}
	}while(Opcion!=27);
	return 0;
}

/*******************************Inicio Validaciones*******************************/

int Album (char NombreAlbum [20])
{
	if (strlen(NombreAlbum) > 20)
		return 0;
	if (isspace(NombreAlbum[0]))
		return 0;
	for (int i = 0; i < strlen(NombreAlbum); i++)
		if (isdigit(NombreAlbum[i]) && isalpha(NombreAlbum[i]) && isspace(NombreAlbum[i]))
			return 1;
		else if (ispunct(NombreAlbum[i]))
			return 0;
}

int Artista (char NombreArtista[20])
{	
	if (strlen(NombreArtista) > 20)
		return 0;
	if (isspace(NombreArtista[0]))
		return 0;
		for (int i = 0; i < strlen(NombreArtista); i++)
		if (!isalpha(NombreArtista[i]) && !isspace(NombreArtista[i]))
			return 0;
}


int Year(int Publicacion)
{
	char year [4];
	int  num;
	
	itoa(Publicacion,year,10);
	
	if (strlen(year) <= 4)
	{
		num = atoi(year);
		if(num > 2018 || num < 1000 )
		{
			cout << "¡Fecha De Publicacion Invalida!\n";
				return 0;
		}
		if (year[0] == '0')
			return 0;
		for (int i = 0; i < strlen(year); i++)
			if (!isdigit(year[i]))
				return 0;
		return 1;
	}
	return 0;
}

int Canciones(int NumTracks)
{
	char songs [5];
	int  num1;
	
	itoa(NumTracks,songs,10);
	
	if (strlen(songs) < 5)
	{
		num1 = atoi(songs);
		if(num1 > 1000)
		{
			cout << "¡Limite Maximo De Canciones!\n";
			getch();
			return 0;
		}
		if (songs[0] == '0')
			return 0;
		for (int i = 0; i < strlen(songs); i++)
			if (!isdigit(songs[i]))
				return 0;
		return 1;
	}
	return 0;
}

void GeneroV ()
{
	char op2;
	cout << "\nPreciona el Numero del Genero al que Pertenece el Album: ";		
	cout << "\n\n[1] Pop" << "\n[2] Rock" << "\n[3] Rap" << "\n[4] Mexicanas" << "\n[5] Electronica" << "\n[6] Reggeton";
		
	do
	{
		fflush(stdin);
		op2 = getch(); 
		
		switch(op2)
		{
			case 49: 
			strcpy(dat.Genero,"Pop"); break;
			
			case 50:
			strcpy(dat.Genero,"Rock"); break;
			
			case 51:
			strcpy(dat.Genero,"Rap"); break;
		 	
		 	case 52:
			strcpy(dat.Genero,"Mexicanas"); break;
			 	
		 	case 53:
			strcpy(dat.Genero,"Electronica"); break;
		 	
		 	case 54:
			strcpy(dat.Genero,"Reggeton"); break;
		}
	}while(op2!=49 && op2!=50 && op2!=51 && op2!=52 && op2!=53 && op2!=54);
}

int Time (int Tiempo)
{
	char time [4];
	int  num2;
	
	memset(&time,0,sizeof(time));
	itoa(Tiempo,time,10);
	
	if (strlen(time) < 4)
	{
		num2 = atoi(time);
		if(num2 > 250)
		{
			cout << "¡Demaciada Duracion Para un Album!\n";
			getch();
			return 0;
		}
		if (time[0] == '0')
			return 0;
		for (int i = 0; i < strlen(time); i++)
			if (!isdigit(time[i]))
				return 0;
		return 1;
	}
	return 0;
}

/*******************************Fin Validaciones*******************************/ 

char Menu ()
{
	char opcion;
	setlocale(LC_CTYPE, "Spanish");
	system("cls");
	 time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%I:%M%p",timeinfo);
  puts (buffer);
	gotoxy(46,9);  cout << "__________MENU CDs__________  ";
	gotoxy(45,10); cout << "  [F1] Abrir o Crear Fichero  ";
	gotoxy(45,11); cout << "  [F2] Registrar CDs          ";
	gotoxy(45,12); cout << "  [F3] Mostrar Registros      ";
	gotoxy(45,13); cout << "  [F4] Consultar Registros    ";
	gotoxy(45,14); cout << "  [F5] Editar Registros       ";
	gotoxy(45,15); cout << "  [F6] Eliminar Registros     ";
	gotoxy(45,16); cout << "  [Esc] SALIR                 ";
	Setcolor(14); 
	gotoxy(45,18); cout << "    INGRESE UNA OPCIÓN: "; fflush(stdin);
	ResetColor(10); 
	getch();
}

void Crear ()
{
	int caracter;
	system("color C");
	memset(carpeta_ori,0,sizeof(carpeta_ori));
	do
	{
		do
		{
			system("cls");
			gotoxy(40,12); cout << "¿Que archivo desea abrir o crear?: " << endl; 
			gotoxy(75,12); gets(carpeta_ori);
			
			unsigned int i;
			lon=strlen(carpeta_ori);
			aux=0;
			for (int i = 0; i < lon; i++)
			{
				if(carpeta_ori[lon-1] == 'n' && carpeta_ori[lon-2] == 'i' && carpeta_ori[lon-3] == 'b' && carpeta_ori[lon-4] == '.')
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
				gotoxy(42,14); cout << "¡Es necesario la extencion .bin!";
				getch();
			}
		}while(ban == 1);
		if (lon == 0)
		{
	    	aux=1;
	    	gotoxy(50,14); cout << "¡Campo vacio!";
	    	getch();
		}
	}while(aux == 1);
			
	
	if((pf = fopen(carpeta_ori,"rb+")) == NULL)
	{
		system("color A");
		pf = fopen(carpeta_ori, "ab+");
		
		memset(&dat,' ',sizeof(dat));
				 	
	 	for (caracter = 0; caracter < 299; caracter ++)
		{
	 		fwrite(&dat,sizeof(dat),1,pf);
	 		fprintf(pf,"\r\n");
		}
		gotoxy(42,14); cout << "¡El archivo no exite pero fue creado!";
		Rcreado=1;
		getch();
	}
	else 
	{
		system("color A");
		gotoxy(48,14); cout << "¡Apertura exitosa!";
		Rcreado=1;
		getch();
	}
	
	fclose(pf);
}

int Contador ()
{
	DATOS dat;
	int TamR = 1;
	int TamARC = 0;
	int Registros = 0;
	
	TamR=sizeof(dat);
	
	fseek(pf,0,SEEK_END); 
	TamARC=ftell(pf); 
	
	Registros=TamARC/TamR; 
	return Registros + 1; 
}

int Val_Ascii(char valor[50])
{
   for(int i = 0; i < strlen(dat.NombreAlbum); i++)
   {
   	   Ascii+=dat.NombreAlbum[i];	   
   }
   
   Ascii = Ascii*84;
   Ascii = Ascii%300;
   
   return Ascii;
}

void Alta()
{
	char codigos [5];
	int  cont;
	
	do
	{
		char CodigoR [5] = "R";
		
		if((pf = fopen(carpeta_ori,"rb+"))==NULL)
		{
			system("color C");
			gotoxy(40,14); cout << "¡No se encontro el archivo para la lectura!";
			exit(0);
			getch();
		}
		
		Rcreado=0;
		
		system("cls");
		memset(&dat,0,sizeof(dat));
				
		
		
		cout << "\n" << dat.Codigo;
		
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		do
		{	
		    cout << "\n\nIngresa el Nombre del Album: "; fflush(stdin);
			gets(dat.NombreAlbum);
			if (Album(dat.NombreAlbum))
			{
				ban=1;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=0;
			}
		}while (ban==0);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		do
		{	
		    cout << "\nIngresa el Nombre del Artista: "; fflush(stdin);
			gets(dat.NombreArtista);
			if (Artista(dat.NombreArtista))
			{
				ban=1;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=0;
			}
		}while (ban==0);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		do
		{	
			char year [4];
		
		    cout << "\nIngresa el Año de Publicacion del Album: "; fflush(stdin);
	 		cin  >> year;
			dat.Publicacion=atoi(year);
			if (Year(dat.Publicacion))
			{
				ban=1;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=0;
			}
		}while (ban==0);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		do
		{	
			char songs [5];
		
		    cout << "\nIngresa el Numero de Canciones que Contiene el Album: "; fflush(stdin);
	 		cin  >> songs;
			dat.NumTracks=atoi(songs);
			if (Canciones(dat.NumTracks))
			{
				ban=1;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=0;
			}
		}while (ban==0);
	 	
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		memset(&dat.Genero,0,sizeof(dat.Genero));
		GeneroV ();
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	 	do
		{	
			char time [4];
			
			cout << "\n\nIngresa el Tiempo de Duracion del Album: "; fflush(stdin);
	 		cin  >> time;
			dat.Tiempo=atoi(time);
			if (Time(dat.Tiempo))
			{
				ban=1;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=0;
			}
		}while (ban==0);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		int Asc, posicion_ascii;
		memset(&posicion_ascii,0,sizeof(posicion_ascii));
		memset(&Asc,0,sizeof(Asc));
		Asc=Ascii=Val_Ascii(dat.NombreAlbum);
		memset(&posicion_ascii,0,sizeof(posicion_ascii));
		posicion_ascii=Asc*86;
	    fseek(pf,posicion_ascii-86,SEEK_SET);
	    
	    cont=Ascii;	
		
		itoa(cont,codigos,10);
		
		strcpy(dat.Codigo,strcat(CodigoR,codigos));
		
	    fwrite(&dat,84,1,pf);
	    
	    cout<<Ascii;
		getch();		
		
		fclose(pf);	
			
/////////////////////////////////////////////////////////////////////////////////////////////////////////
			do
			{	
				system("cls");
				gotoxy(38,12); cout << "¿Deseas Agregar Otro Registro? [S] / [N]";
				respuesta=getch();
				
				if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
				{
					gotoxy(47,14); cout << "Introduce Una Opcion: ";
					getch();
				}
			}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
	}while(respuesta=='s' || respuesta=='S');
}

void ShowR ()
{
	cout << "\n\t\t\t\t\t   " << dat.Codigo << endl;
	cout << "\t\t\t\t\t   ____________________________" << endl;
	cout << "\t\t\t\t\t      Nombre Album: " << dat.NombreAlbum << endl;
	cout << "\t\t\t\t\t      Nombre Artista: " << dat.NombreArtista << endl;
	cout << "\t\t\t\t\t      Publicacion: " << dat.Publicacion << endl;
	cout << "\t\t\t\t\t      Num Canciones: " << dat.NumTracks << endl;
	cout << "\t\t\t\t\t      Genero: " << dat.Genero << endl;
	cout << "\t\t\t\t\t      Duracion del album: " << dat.Tiempo << endl;
	cout << "\t\t\t\t\t   ____________________________" << endl;
}

void SwitchE ()
{
	char op;
					
	cout << "\n\n\n[1] Editar Nombre Album" << "\n[2] Editar Nombre Artista" << "\n[3] Editar Año Publicacion" << "\n[4] Editar Numero de Canciones" << "\n[5] Editar Genero" << "\n[6] Editar Duracion del Album";
	cout << "\n\nPreciona el Numero de la Opcion Que Deseas Editar: ";
	
	do
	{
		fflush(stdin);
		op = getch();
		
		switch(op)
		{
			case 49:
			
				do
				{
					memset(&dat.NombreAlbum,0,sizeof(dat.NombreAlbum));
				
				    cout << "\n\nIngresa el Nombre del Album: "; fflush(stdin);
					gets(dat.NombreAlbum);
					if (Album(dat.NombreAlbum))
					{
						ban=1;
					}
					else
					{
						cout << "¡Dato incorrecto!" << endl;
						ban=0;
					}
				}while (ban==0);
				
				
	            
			break;
			
			case 50:
				
			do
			{	
				memset(&dat.NombreArtista,0,sizeof(dat.NombreArtista));
					
			    cout << "\n\nIngresa el Nombre del Artista: "; fflush(stdin);
				gets(dat.NombreArtista);
				if (Artista(dat.NombreArtista))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
	
			break;
			
			case 51:
				
			do
			{
				memset(&dat.Publicacion,0,sizeof(dat.Publicacion));
				char year [4];
			
			    cout << "\n\nIngresa el Año de Publicacion del Album: "; fflush(stdin);
		 		cin  >> year;
				dat.Publicacion=atoi(year);
				if (Year(dat.Publicacion))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato Incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
		 	
		 	break;
		 	
		 	case 52:
		 	
		 	do
			{	
				memset(&dat.NumTracks,0,sizeof(dat.NumTracks));
				char songs [4];
			
			    cout << "\n\nIngresa el Numero de Canciones que Contiene el Album: "; fflush(stdin);
		 		cin  >> songs;
				dat.NumTracks=atoi(songs);
				if (Canciones(dat.NumTracks))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato Incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);
		 
		 	break;
		 	
		 	case 53:
		 	
		 	memset(&dat.Genero,0,sizeof(dat.Genero));
		 	system("cls");
		 	GeneroV ();
			
		 	break;
		 	
		 	case 54:
		 	
		 	do
			{	
				memset(&dat.Tiempo,0,sizeof(dat.Tiempo));
				char time [4];
				
				cout << "\n\nIngresa el Tiempo de Duracion del Album: "; fflush(stdin);
		 		cin  >> time;
				dat.Tiempo=atoi(time);
				if (Time(dat.Tiempo))
				{
					ban=1;
				}
				else
				{
					cout << "¡Dato Incorrecto!" << endl;
					ban=0;
				}
			}while (ban==0);

			break;
		}
		
	}while(op!=49 && op!=50 && op!=51 && op!=52 && op!=53 && op!=54);
}

void Mostrar()
{	
	if((pf = fopen(carpeta_ori,"rb")) == NULL)
	{
		system("color C");
		gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
		exit(0);
		getch();
	}
	
	do
	{
		memset(&dat,0,sizeof(dat));
		
		Rcreado=0;
        
        fread(&dat,sizeof(dat),1,pf);
        
        for(int i=0; i < 2; i++)
		{
			caracter=fgetc(pf);
		}
		if(!feof(pf) && dat.Reliminado == 0)
		{
			ShowR ();
        }
	}while(caracter!=EOF);
		
	fclose(pf);
	getch();
}

void Consultar()
{	
	if((pf = fopen(carpeta_ori,"rb")) == NULL)
	{
		system("color C");
		gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
		exit(0);
		getch();
	}
	
	cout << "\nIntroduce el Nombre del Album a Consultar: "; fflush(stdin);
	gets(buscar);
	
	do
	{
		memset(&dat,0,sizeof(dat));
		
		Rcreado=0;
        
        fread(&dat,sizeof(dat),1,pf);
        
        for(int i=0; i < 2; i++)
		{
			caracter=fgetc(pf);
		}
		if(!strcmpi(buscar,dat.NombreAlbum) && !feof(pf) && dat.Reliminado == 0)
		{
			ShowR ();
        }
	}while(caracter!=EOF);
		
	fclose(pf);
	getch();
}

void Editar()
{
 	char op;

	if((pf = fopen(carpeta_ori,"rb+")) == NULL)
	{
		system("color C");
		gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
		exit(0);
		getch();
	}
		fflush(stdin);
		system("cls");
		    	
		fseek(pf,0,SEEK_SET);
		char buscar [30];		
		cout << "\n\nIntroduce el Nombre del Album a Consultar y Editar: "; fflush(stdin);
		memset(buscar,0,sizeof(buscar));
		gets(buscar);
			
		do
		{
			memset(&dat,0,sizeof(dat));
			
			fread(&dat,84,1,pf);
			
			for(int i=0; i < 2; i++)
			{
				caracter=fgetc(pf);
			}
			
      	 	if(!strcmpi(buscar,dat.NombreAlbum))
            {
            	int Asc=0, posicion_ascii=0, posicion_actual=0;
            	memset(&Asc,0,sizeof(Asc));
            	memset(&posicion_ascii,0,sizeof(posicion_ascii));
            	memset(&posicion_actual,0,sizeof(posicion_actual));
            	
            	char c = ' ';
						 		    
      	 		if(dat.Reliminado == 0)
      	 		{
      	 				posicion_actual=ftell(pf);
      	 				cout << posicion_actual/86;
      	 				getch();
					   	ShowR ();
      	 				cout<<Ascii;
						getch();
      	 			
				  	do
			        {			
						gotoxy(36,13); cout << "¿Este Es El Registro Que Quieres Editar? [S] / [N]";
						respuesta=getch();
						if(respuesta!='n' && respuesta!='N' && respuesta!='s' && respuesta!='S')
						{
							gotoxy(49,15); cout << "Introduce Una Opcion: ";
							getch();
						}
					}while(respuesta!='n' && respuesta!='N' && respuesta!='s' && respuesta!='S');
					
					if(respuesta == 's'||respuesta == 'S')
					{
						fseek(pf,posicion_actual-86,SEEK_SET);
						for (caracter = 0; caracter < 84; caracter ++)
						{
			 				fwrite(&c,sizeof(c),1,pf);
						}
						
						int Asc=0, posicion_ascii=0;
						memset(&posicion_ascii,0,sizeof(posicion_ascii));
						memset(&Asc,0,sizeof(Asc));
						Asc=Ascii=Val_Ascii(dat.NombreAlbum);
						memset(&posicion_ascii,0,sizeof(posicion_ascii));
						posicion_ascii=Asc*86;
					    fseek(pf,posicion_ascii-86,SEEK_SET);
					
              	 		SwitchE ();
              	 		
              	 		fseek(pf,-86,SEEK_CUR);
						fwrite(&dat,84,1,pf);
						fseek(pf,86,SEEK_CUR);
						
						cout<<Ascii;
						getch();
						
						system("cls");
						gotoxy(44,14); cout << "¡Registro Editado con exito!";
						getch();
					}	
        	 	}
			}
			
		}while(!feof(pf));

	fclose(pf);	
}

void Eliminar()
 {
 	char op;

	if((pf = fopen(carpeta_ori,"rb+")) == NULL)
	{
		system("color C");
		gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
		exit(0);
		getch();
	}
		fflush(stdin);
		system("cls");
		    	
		fseek(pf,0,SEEK_SET);
		char buscar [30];		
		cout << "\n\nIntroduce el Nombre del Album a Consultar y Eliminar: "; fflush(stdin);
		memset(buscar,0,sizeof(buscar));
		gets(buscar);
			
		do
		{
			memset(&dat,0,sizeof(dat));
			
			fread(&dat,84,1,pf);
			
			for(int i=0; i < 2; i++)
			{
				caracter=fgetc(pf);
			}
			
      	 	if(!strcmpi(buscar,dat.NombreAlbum))
            {
            	int Asc=0, posicion_ascii=0, posicion_actual=0;
            	memset(&Asc,0,sizeof(Asc));
            	memset(&posicion_ascii,0,sizeof(posicion_ascii));
            	memset(&posicion_actual,0,sizeof(posicion_actual));
            	char c = ' ';
								 		    
      	 		if(dat.Reliminado == 0)
      	 		{
      	 				posicion_actual=ftell(pf);
      	 				cout << posicion_actual/86;
      	 				getch();
					   	ShowR ();
      	 			
				  	do
			        {			
						gotoxy(36,13); cout << "¿Este Es El Registro Que Quieres Eliminar? [S] / [N]";
						respuesta=getch();
						if(respuesta!='n' && respuesta!='N' && respuesta!='s' && respuesta!='S')
						{
							gotoxy(49,15); cout << "Introduce Una Opcion: ";
							getch();
						}
					}while(respuesta!='n' && respuesta!='N' && respuesta!='s' && respuesta!='S');
					
					if(respuesta == 's'||respuesta == 'S')
					{
						fseek(pf,posicion_actual-86,SEEK_SET);
						for (caracter = 0; caracter < 84; caracter ++)
						{
			 				fwrite(&c,sizeof(c),1,pf);
						}
						
						int Asc=0, posicion_ascii=0;
						memset(&posicion_ascii,0,sizeof(posicion_ascii));
						memset(&Asc,0,sizeof(Asc));
						Asc=Ascii=Val_Ascii(dat.NombreAlbum);
						memset(&posicion_ascii,0,sizeof(posicion_ascii));
						posicion_ascii=Asc*86;
					    fseek(pf,posicion_ascii-86,SEEK_SET);
							
						system("cls");
						gotoxy(44,14); cout << "¡Registro Eliminado con exito!";
						getch();
					}	
        	 	}
			}
			
		}while(!feof(pf));

	fclose(pf);	
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

void Setcolor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void ResetColor(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}
