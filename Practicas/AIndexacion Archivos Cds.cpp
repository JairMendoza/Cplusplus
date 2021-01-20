
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
#include<stdbool.h>

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

typedef struct indice_album 
{
    char NombreAlbum_ind [20];
    char Codigo_ind_alb [5];
    int  Reliminado_ind_alb;
} INDEX_ALB;

typedef struct indice_artista 
{
    char NombreArtista_ind [20];
    char Codigo_ind_art [5];
    int  Reliminado_ind_art;
} INDEX_ART;

typedef struct indice_genero 
{
    char Genero_ind [20];
    char Codigo_ind_gen [5];
    int  Reliminado_ind_gen;
} INDEX_GEN;

///////////////////////////////////////////////
DATOS dat; INDEX_ALB ind_alb; INDEX_ART ind_art; INDEX_GEN ind_gen;
FILE *pf, *Ialb, *Iart, *Igen;
char archivo_ori [100], archivo_index_album   [100], archivo_index_artista [100], archivo_index_genero  [100];
///////////////////////////////////////////////
int  lon = 0;
int  aux = 0;
int  Rcreado = 0 , Rcreado_Ialb = 0, Rcreado_Iart = 0, Rcreado_Igen = 0;
int  respuesta2;
int  respuesta3;
char respuesta;
char caracter = '\0';
char buscar[30];
bool ban = false;
///////////////////////////////////////////////
char Menu  (void);
int  Contador  ();
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
void Seek      ();
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

bool Album (char NombreAlbum [20])
{
	if (strlen(NombreAlbum) > 20)
		return false;
	if (isspace(NombreAlbum[0]))
		return false;
	for (int i = 0; i < strlen(NombreAlbum); i++)
		if (isdigit(NombreAlbum[i]) && isalpha(NombreAlbum[i]) && isspace(NombreAlbum[i]))
			return true;
		else if (ispunct(NombreAlbum[i]))
			return false;
}

bool Artista (char NombreArtista[20])
{
	if (strlen(NombreArtista) > 20)
		return false;
	if (isspace(NombreArtista[0]))
		return false;
		for (int i = 0; i < strlen(NombreArtista); i++)
		if (!isalpha(NombreArtista[i]) && !isspace(NombreArtista[i]))
			return false;
}

bool Year(int Publicacion)
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
				return false;
		}
		if (year[0] == '0')
			return false;
		for (int i = 0; i < strlen(year); i++)
			if (!isdigit(year[i]))
				return false;
		return true;
	}
	return false;
}

bool Canciones(int NumTracks)
{
	char songs [4];
	int  num1;
	
	itoa(NumTracks,songs,10);
	
	if (strlen(songs) <= 4)
	{
		num1 = atoi(songs);
		if(num1 > 1000)
		{
			cout << "¡Limite Maximo De Canciones!\n";
			getch();
			return false;
		}
		if (songs[0] == '0')
			return false;
		for (int i = 0; i < strlen(songs); i++)
			if (!isdigit(songs[i]))
				return false;
		return true;
	}
	return false;
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

bool Time (int Tiempo)
{
	char time [4];
	int  num2;
	
	itoa(Tiempo,time,10);
	
	if (strlen(time) <= 3)
	{
		num2 = atoi(time);
		if(num2 > 250)
		{
			cout << "¡Demaciada Duracion Para un Album!\n";
			getch();
			return false;
		}
		if (time[0] == '0')
			return 0;
		for (int i = 0; i < strlen(time); i++)
			if (!isdigit(time[i]))
				return false;
		return true;
	}
	return false;
}

/*******************************Fin Validaciones*******************************/ 

char Menu ()
{
	char opcion;
	setlocale(LC_CTYPE, "Spanish");
	system("cls");
	Setcolor(14); 
	gotoxy(0,2);cout << "========================================================================================================================" << endl;
	gotoxy(0,3);cout << "                                              MENU CDs BUSQUEDA POR INDICES                                             " << endl;
	gotoxy(0,4);cout << "========================================================================================================================" << endl;
	ResetColor(7);
	gotoxy(45,7);  cout << "  [F1] Abrir o Crear Fichero  ";
	gotoxy(45,9);  cout << "  [F2] Registrar CDs          ";
	gotoxy(45,11); cout << "  [F3] Mostrar Registros      ";
	gotoxy(45,13); cout << "  [F4] Consultar Registros    ";
	gotoxy(45,15); cout << "  [F5] Editar Registros       ";
	gotoxy(45,17); cout << "  [F6] Eliminar Registros     ";
	gotoxy(45,19); cout << "  [Esc] SALIR                 ";
	Setcolor(14); 
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    gotoxy(100,6); strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    gotoxy(100,6); cout << output;
	gotoxy(45,23); cout << "    INGRESE UNA OPCIÓN: "; fflush(stdin);
	ResetColor(10); 
	opcion = getch();
}

void Crear ()
{
	memset(archivo_ori,0,sizeof(archivo_ori));
	memset(archivo_index_album,0,sizeof(archivo_index_album));
	memset(archivo_index_artista,0,sizeof(archivo_index_artista));
	memset(archivo_index_genero,0,sizeof(archivo_index_genero));
	do
	{
		do
		{
			system("cls");
			system("color C");
			gotoxy(0,1);cout << "___________________________________________ ¡FUNCION CREAR ARCHIVOS BINARIOS! ___________________________________________" << endl;
			gotoxy(43,14); cout << "¿Que archivo desea abrir o crear?: " << endl; 
			gotoxy(78,14); gets(archivo_ori);
			
			unsigned int i;
			lon=strlen(archivo_ori);
			aux=0;
			for (int i = 0; i < lon; i++)
			{
				if(archivo_ori[lon-1] == 'n' && archivo_ori[lon-2] == 'i' && archivo_ori[lon-3] == 'b' && archivo_ori[lon-4] == '.')
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
				gotoxy(45,16); cout << "¡Es necesario la extencion .bin!";
				getch();
			}
		}while(ban == 1);
		if (lon == 0)
		{
	    	aux=1;
	    	gotoxy(53,16); cout << "¡Campo vacio!";
	    	getch();
		}
	}while(aux == 1);
	
	char indexAl [100] = "Index Album ", indexAr [100] = "Index Artista ", indexGe [100] = "Index Genero ";
	
	strcat(indexAl,archivo_ori);
	strcpy(archivo_index_album,indexAl);
	
	strcat(indexAr,archivo_ori);
	strcpy(archivo_index_artista,indexAr);
	
	strcat(indexGe,archivo_ori);
	strcpy(archivo_index_genero,indexGe);
			
	if((pf = fopen(archivo_ori,"rb")) == NULL && (Ialb = fopen(archivo_index_album,"rb")) == NULL && (Iart = fopen(archivo_index_artista,"rb")) == NULL && (Igen = fopen(archivo_index_genero,"rb")) == NULL)
	{
		system("color A");
		pf = fopen(archivo_ori, "wb");
		gotoxy(44,16); cout << "¡El archivo no exite pero fue creado!";
		Rcreado = 1;
		
		Ialb = fopen(archivo_index_album, "wb");
		Iart = fopen(archivo_index_artista, "wb");
		Igen = fopen(archivo_index_genero, "wb");
		
		gotoxy(38,18); cout << "¡Los archivos index no exiten pero fueron creados!";
		Rcreado_Ialb = 1, Rcreado_Iart = 1, Rcreado_Igen = 1;
		getch();
	}
	else 
	{
		system("color A");
		gotoxy(51,16); cout << "¡Apertura exitosa!";
		Rcreado = 1;
		getch();
	}
	
	fclose(pf);
	fclose(Ialb);
	fclose(Iart);
	fclose(Igen);
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

void Alta()
{
	char codigos [5];
	int  cont;
	
	musica *g = new musica();
	
	do
	{
		char CodigoR [5] = "R00";
		
		if((pf = fopen(archivo_ori,"ab+"))==NULL || (Ialb = fopen(archivo_index_album,"ab+"))==NULL || (Iart = fopen(archivo_index_artista,"ab+"))==NULL || (Igen = fopen(archivo_index_genero,"ab+"))==NULL)
		{
			system("color C");
			gotoxy(40,14); cout << "¡No se encontro el archivo para la lectura!";
			exit(0);
			getch();
		}
		
		Rcreado = 0 , Rcreado_Ialb = 0, Rcreado_Iart = 0, Rcreado_Igen = 0;
		
		system("cls");
		
		memset(&dat,0,sizeof(dat));
		
		cont=Contador ();	
		
		itoa(cont,codigos,10);
		strcat(CodigoR,codigos);
		strcpy(dat.Codigo,CodigoR);
		
		memset(&CodigoR,0,sizeof(CodigoR));
		
		gotoxy(0,1);cout << "______________________________________________ ¡FUNCION ALTA REGISTROS! ________________________________________________" << endl;
		
		cout << "\n" << dat.Codigo;
		
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		do
		{	
		    cout << "\n\nIngresa el Nombre del Album: "; fflush(stdin);
			gets(dat.NombreAlbum);
			if (Album(dat.NombreAlbum))
			{
				ban=true;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=false;
			}
		}while (ban==false);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		do
		{	
		    cout << "\nIngresa el Nombre del Artista: "; fflush(stdin);
			gets(dat.NombreArtista);
			if (Artista(dat.NombreArtista))
			{
				ban=true;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=false;
			}
		}while (ban==false);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		do
		{	
			char year [4];
		
		    cout << "\nIngresa el Año de Publicacion del Album: "; fflush(stdin);
	 		cin  >> year;
			dat.Publicacion=atoi(year);
			if (Year(dat.Publicacion))
			{
				ban=true;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=false;
			}
		}while (ban==false);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		do
		{	
			char songs [4];
		
		    cout << "\nIngresa el Numero de Canciones que Contiene el Album: "; fflush(stdin);
	 		cin  >> songs;
			dat.NumTracks=atoi(songs);
			if (Canciones(dat.NumTracks))
			{
				ban=true;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=false;
			}
		}while (ban==false);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
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
				ban=true;
			}
			else
			{
				cout << "¡Dato Incorrecto!" << endl;
				ban=false;
			}
		}while (ban==false);
/////////////////////////////////////////////////////////////////////////////////////////////////////////

		dat.Reliminado = 0;
		fwrite(&dat,sizeof(dat),1,pf);
		fprintf(pf,"\r\n");
		
		ind_alb.Reliminado_ind_alb = 0;
		fwrite(&dat.NombreAlbum,sizeof(ind_alb.NombreAlbum_ind),1,Ialb);
		fwrite(&dat.Codigo,sizeof(ind_alb.Codigo_ind_alb),1,Ialb);
		fwrite(&dat.Reliminado,sizeof(ind_alb.Reliminado_ind_alb),1,Ialb);
		fprintf(Ialb,"\r\n");
		
		ind_art.Reliminado_ind_art = 0;
		fwrite(&dat.NombreArtista,sizeof(ind_art.NombreArtista_ind),1,Iart);
		fwrite(&dat.Codigo,sizeof(ind_art.Codigo_ind_art),1,Iart);
		fwrite(&dat.Reliminado,sizeof(ind_art.Reliminado_ind_art),1,Iart);
		fprintf(Iart,"\r\n");
		
		ind_gen.Reliminado_ind_gen = 0;
		fwrite(&dat.Genero,sizeof(ind_gen.Genero_ind),1,Igen);
		fwrite(&dat.Codigo,sizeof(ind_gen.Codigo_ind_gen),1,Igen);
		fwrite(&dat.Reliminado,sizeof(ind_gen.Reliminado_ind_gen),1,Igen);
		fprintf(Igen,"\r\n");
		
		fclose(pf);
		fclose(Ialb);
		fclose(Iart);
		fclose(Igen);
			
//////////////////////////////////////////////////////////////////////////////////////////////
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

void Mostrar()
{	
	gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION MOSTRAR REGISTROS! ______________________________________________" << endl;
	if((pf = fopen(archivo_ori,"rb")) == NULL)
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

void Consultar ()
{
	char op;
	char code [5];
	int codi = 0, posicion = 0;
	
	if((pf = fopen(archivo_ori,"rb")) == NULL || (Ialb = fopen(archivo_index_album,"rb"))==NULL || (Iart = fopen(archivo_index_artista,"rb"))==NULL || (Igen = fopen(archivo_index_genero,"rb"))==NULL)
	{
		system("color C");
		gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
		exit(0);
		getch();
	}
	gotoxy(0,1);cout << "____________________________________________ ¡FUNCION CONSULTAR REGISTROS! _____________________________________________" << endl;	
	cout << "\n\n[1] Por Nombre Album" << "\n[2] Por Nombre Artista" << "\n[3] Por Nombre Genero";
	cout << "\n\nPreciona el Numero del Indice Que Deseas Abrir: "; fflush(stdin);
	
	do
	{
		op = getch();
		
		switch(op)
		{
			case 49:
							
			cout << "\n\nIntroduce el Nombre del Album a Consultar: "; fflush(stdin);
			gets(buscar);
			
			do
			{
				memset(&dat,0,sizeof(dat));
				memset(&ind_alb,0,sizeof(ind_alb));
				memset(&code,0,sizeof(code));
				
				Rcreado = 0 , Rcreado_Ialb = 0;
		        
		        fread(&ind_alb,29,1,Ialb);
		        
		        for(int i=0; i < 2; i++)
				{
					caracter=fgetc(Ialb);
				}
				
				if(!strcmpi(buscar,ind_alb.NombreAlbum_ind) && !feof(Ialb))
				{
					strcpy(code,ind_alb.Codigo_ind_alb + 1);
					codi = atoi(code);
					posicion = (codi)*86;
					fseek(pf,posicion-86,SEEK_SET);	
		        
		        	fread(&dat,sizeof(dat),1,pf);
		        	if (dat.Reliminado == 1)
					{
						break;
					}
					system("cls");
					gotoxy(0,1);cout << "____________________________________________ ¡FUNCION CONSULTAR REGISTROS! _____________________________________________" << endl;	
		   		 	ShowR ();
		   		 	getch();	
		        }
		     
			}while(caracter!=EOF);
			
			break;
			
			case 50:
				
			cout << "\n\nIntroduce el Nombre del Artista a Consultar: "; fflush(stdin);
			gets(buscar);
			
			do
			{
				memset(&dat,0,sizeof(dat));
				memset(&ind_art,0,sizeof(ind_art));
				memset(&code,0,sizeof(code));
				
				Rcreado = 0 , Rcreado_Iart = 0;
		        
		        fread(&ind_art,29,1,Iart);
		        
		        for(int i=0; i < 2; i++)
				{
					caracter=fgetc(Iart);
				}
				
				if(!strcmpi(buscar,ind_art.NombreArtista_ind) && !feof(Iart))
				{
					strcpy(code,ind_art.Codigo_ind_art + 1);
					codi = atoi(code);
					posicion = (codi)*86;
					fseek(pf,posicion-86,SEEK_SET);	
		        
		        	fread(&dat,sizeof(dat),1,pf);
		        	if (dat.Reliminado == 1)
					{
						break;
					}
					system("cls");
					gotoxy(0,1);cout << "____________________________________________ ¡FUNCION CONSULTAR REGISTROS! _____________________________________________" << endl;	
		   		 	ShowR ();
		   		 	getch();	
		        }
		     
			}while(caracter!=EOF);
			
			break;
			      
			case 51:
				
			cout << "\n\nIntroduce el Nombre del Genero a Consultar: "; fflush(stdin);
			gets(buscar);
			
			do
			{
				memset(&dat,0,sizeof(dat));
				memset(&ind_gen,0,sizeof(ind_gen));
				memset(&code,0,sizeof(code));
				
				Rcreado = 0 , Rcreado_Igen = 0;
		        
		        fread(&ind_gen,29,1,Igen);
		        
		        for(int i=0; i < 2; i++)
				{
					caracter=fgetc(Igen);
				}
		        
				if(!strcmpi(buscar,ind_gen.Genero_ind) && !feof(Igen) && ind_gen.Reliminado_ind_gen == 0)
				{
					strcpy(code,ind_gen.Codigo_ind_gen + 1);
					codi = atoi(code);
					posicion = (codi)*86;
					fseek(pf,posicion-86,SEEK_SET);	
		        
		        	fread(&dat,sizeof(dat),1,pf);
		        	if (dat.Reliminado == 1)
					{
						break;
					}
					system("cls");
					gotoxy(0,1);cout << "____________________________________________ ¡FUNCION CONSULTAR REGISTROS! _____________________________________________" << endl;	
		   		 	ShowR ();
		   		 	getch();	
		        }
		     
			}while(caracter!=EOF);
		
		 	break;
		 }
		 	
	}while(op!=49 && op!=50 && op!=51);
	
	fclose(pf);
	fclose(Ialb);
	fclose(Iart);
	fclose(Igen);
}

/*void Editar ()
{
	do
	{
		system("cls");
		char op;
		char code [5];
		int codi = 0, posicion_alb = 0, posicion_art, posicion_gen;
		
		if((pf = fopen(archivo_ori,"rb+")) == NULL || (Ialb = fopen(archivo_index_album,"rb+"))==NULL || (Iart = fopen(archivo_index_artista,"rb+"))==NULL || (Igen = fopen(archivo_index_genero,"rb+"))==NULL)
		{
			system("color C");
			gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
			exit(0);
			getch();
		}
		gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;			
		cout << "\n\n[1] Por Nombre Album" << "\n[2] Por Nombre Artista" << "\n[3] Por Nombre Genero";
		cout << "\n\nPreciona el Numero del Indice Que Deseas Abrir: "; fflush(stdin);
		
		do
		{
			op = getch();
			
			switch(op)
			{
				case 49:
				
				fseek(Ialb,0,SEEK_SET);			
				cout << "\n\nIntroduce el Nombre del Album a Consultar y Editar: "; fflush(stdin);
				gets(buscar);
				
				do
				{
					respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
					memset(&ind_alb,0,sizeof(ind_alb));
					memset(&ind_alb,0,sizeof(ind_alb));
					memset(&dat,0,sizeof(dat));
					
			        fread(&ind_alb,29,1,Ialb);
			        fread(&ind_art,29,1,Iart);
			        fread(&ind_gen,29,1,Igen);
			       
			        for(int i=0; i < 2; i++)
					{
						caracter=fgetc(Ialb);
					}
			        
					if(!strcmpi(buscar,ind_alb.NombreAlbum_ind))
					{
						strcpy(code,ind_alb.Codigo_ind_alb + 1);
						codi = atoi(code);
						posicion_alb = (codi)*86;
						fseek(pf,posicion_alb-86,SEEK_SET);	
						
			        	fread(&dat,sizeof(dat),1,pf);
			        	if (dat.Reliminado == 1)
						{
							break;
						}
						system("cls");
						gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			   		 	ShowR ();
							
						do
						{
							gotoxy(36,13); cout << "¿Este Es El Registro Que Quieres Editar? [S] / [N]";
							respuesta=getch();
							
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								gotoxy(49,15); cout << "Introduce Una Opcion: ";
								getch();
							}
								
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S');
				
							if(respuesta == 's' || respuesta == 'S')
							{
									
								do
								{
									system("cls");
									gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
									
									ShowR ();
									
									memset(&ind_alb,0,sizeof(ind_alb));
									memset(code,0,sizeof(code));
								
									strcpy(code,dat.Codigo + 1);
									codi = atoi(code);
									posicion_alb = codi*31;
									posicion_art = codi*31;
									posicion_gen = codi*31;
									
									fseek(Ialb,posicion_alb-31,SEEK_SET);
									fread(&ind_alb,sizeof(ind_alb),1,Ialb);
									
									fseek(Iart,posicion_art-31,SEEK_SET);	
									fread(&ind_art,sizeof(ind_art),1,Iart);
									
									fseek(Igen,posicion_gen-31,SEEK_SET);
									fread(&ind_gen,sizeof(ind_gen),1,Igen);
								
									SwitchE ();
									
									strcpy(ind_alb.NombreAlbum_ind,dat.NombreAlbum);
									fseek(Ialb,-31,SEEK_CUR);
									fwrite(&dat.NombreAlbum,sizeof(ind_alb.NombreAlbum_ind),1,Ialb);
									fwrite(&dat.Codigo,sizeof(ind_alb.Codigo_ind_alb),1,Ialb);
									fwrite(&dat.Reliminado,sizeof(ind_alb.Reliminado_ind_alb),1,Ialb);
									fseek(Ialb,31,SEEK_CUR);
									
									fseek(Iart,-31,SEEK_CUR);
									fwrite(&dat.NombreArtista,sizeof(ind_art.NombreArtista_ind),1,Iart);
									fwrite(&dat.Codigo,sizeof(ind_art.Codigo_ind_art),1,Iart);
									fwrite(&dat.Reliminado,sizeof(ind_art.Reliminado_ind_art),1,Iart);
									fseek(Iart,31,SEEK_CUR);
									
									fseek(Igen,-31,SEEK_CUR);
									fwrite(&dat.Genero,sizeof(ind_gen.Genero_ind),1,Igen);
									fwrite(&dat.Codigo,sizeof(ind_gen.Codigo_ind_gen),1,Igen);
									fwrite(&dat.Reliminado,sizeof(ind_gen.Reliminado_ind_gen),1,Igen);
									fseek(Igen,31,SEEK_CUR);
									
									system("cls");
									gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
									gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
									getch();
						 	
									do
									{
										if(respuesta == 'n' || respuesta == 'N')
										{
											break;
										}
								
										system("cls");
										gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
										gotoxy(42,14); cout << "¿Quieres Editar Otro Campo? [S] / [N]";
										respuesta3=getch();
										
										if(respuesta3!= 'n' && respuesta3!= 'N' && respuesta3!= 's' && respuesta3!= 'S' )
										{
											gotoxy(47,16); cout << "Introduce Una Opcion: ";
											getch();
										}
									}while(respuesta3!= 'n' && respuesta3!= 'N' && respuesta3!= 's' && respuesta3!= 'S' );
							
								}while(respuesta3 == 's' || respuesta3 == 'S');
								
								fseek(pf,-84,SEEK_CUR);
								fwrite(&dat,sizeof(dat),1,pf);
								fseek(pf,84,SEEK_CUR);
			        		}
			        }
			     
				}while(caracter!=EOF);
								
				fclose(pf);
				fclose(Ialb);
				fclose(Iart);
				fclose(Igen);
				
				break;
				
				case 50:
								
				fseek(Iart,0,SEEK_SET);			
				cout << "\n\nIntroduce el Nombre del Artista a Consultar y Editar: "; fflush(stdin);
				gets(buscar);
				
				do
				{
					respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
					memset(&ind_art,0,sizeof(ind_art));
					memset(&ind_art,0,sizeof(ind_art));
					memset(&dat,0,sizeof(dat));
					
			        fread(&ind_alb,29,1,Ialb);
			        fread(&ind_art,29,1,Iart);
			        fread(&ind_gen,29,1,Igen);
			       
			        for(int i=0; i < 2; i++)
					{
						caracter=fgetc(Iart);
					}
			        
					if(!strcmpi(buscar,ind_art.NombreArtista_ind))
					{
						strcpy(code,ind_art.Codigo_ind_art + 1);
						codi = atoi(code);
						posicion_art = (codi)*86;
						fseek(pf,posicion_art-86,SEEK_SET);	
			        
			        	fread(&dat,sizeof(dat),1,pf);
			        	if (dat.Reliminado == 1)
						{
							break;
						}
						system("cls");
						gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			   		 	ShowR ();
							
						do
						{
							gotoxy(36,13); cout << "¿Este Es El Registro Que Quieres Editar? [S] / [N]";
							respuesta=getch();
							
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								gotoxy(49,15); cout << "Introduce Una Opcion: ";
								getch();
							}
								
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S');
				
							if(respuesta == 's' || respuesta == 'S')
							{
									
								do
								{
									system("cls");
									gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
									
									ShowR ();
									
									memset(&ind_art,0,sizeof(ind_art));
									memset(code,0,sizeof(code));
								
									strcpy(code,dat.Codigo + 1);
									codi = atoi(code);
									posicion_alb = codi*31;
									posicion_art = codi*31;
									posicion_gen = codi*31;
									
									fseek(Ialb,posicion_alb-31,SEEK_SET);
									fread(&ind_alb,sizeof(ind_alb),1,Ialb);
									
									fseek(Iart,posicion_art-31,SEEK_SET);	
									fread(&ind_art,sizeof(ind_art),1,Iart);
									
									fseek(Igen,posicion_gen-31,SEEK_SET);
									fread(&ind_gen,sizeof(ind_gen),1,Igen);
								
									SwitchE ();
									
									strcpy(ind_art.NombreArtista_ind,dat.NombreArtista);
									
									fseek(Ialb,-31,SEEK_CUR);
									fwrite(&dat.NombreAlbum,sizeof(ind_alb.NombreAlbum_ind),1,Ialb);
									fwrite(&dat.Codigo,sizeof(ind_alb.Codigo_ind_alb),1,Ialb);
									fwrite(&dat.Reliminado,sizeof(ind_alb.Reliminado_ind_alb),1,Ialb);
									fseek(Ialb,31,SEEK_CUR);
									
									fseek(Iart,-31,SEEK_CUR);
									fwrite(&dat.NombreArtista,sizeof(ind_art.NombreArtista_ind),1,Iart);
									fwrite(&dat.Codigo,sizeof(ind_art.Codigo_ind_art),1,Iart);
									fwrite(&dat.Reliminado,sizeof(ind_art.Reliminado_ind_art),1,Iart);
									fseek(Iart,31,SEEK_CUR);
									
									fseek(Igen,-31,SEEK_CUR);
									fwrite(&dat.Genero,sizeof(ind_gen.Genero_ind),1,Igen);
									fwrite(&dat.Codigo,sizeof(ind_gen.Codigo_ind_gen),1,Igen);
									fwrite(&dat.Reliminado,sizeof(ind_gen.Reliminado_ind_gen),1,Igen);
									fseek(Igen,31,SEEK_CUR);
									
									system("cls");
									gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
									gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
									getch();
						 	
									do
									{
										if(respuesta == 'n' || respuesta == 'N')
										{
											break;
										}
								
										system("cls");
										gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
										gotoxy(42,14); cout << "¿Quieres Editar Otro Campo? [S] / [N]";
										respuesta3=getch();
										
										if(respuesta3!= 'n' && respuesta3!= 'N' && respuesta3!= 's' && respuesta3!= 'S' )
										{
											gotoxy(47,16); cout << "Introduce Una Opcion: ";
											getch();
										}
									}while(respuesta3!= 'n' && respuesta3!= 'N' && respuesta3!= 's' && respuesta3!= 'S' );
							
								}while(respuesta3 == 's' || respuesta3 == 'S');
								
								fseek(pf,-84,SEEK_CUR);
								fwrite(&dat,sizeof(dat),1,pf);
								fseek(pf,84,SEEK_CUR);
			        		}
			        }
			     
				}while(caracter!=EOF);
								
				fclose(pf);
				fclose(Ialb);
				fclose(Iart);
				fclose(Igen);
				
				break;
				      
				case 51:
								
				fseek(Igen,0,SEEK_SET);			
				cout << "\n\nIntroduce el Nombre del Album a Consultar y Editar: "; fflush(stdin);
				gets(buscar);
				
				do
				{
					respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
					memset(&ind_gen,0,sizeof(ind_gen));
					memset(&ind_gen,0,sizeof(ind_gen));
					memset(&dat,0,sizeof(dat));
					
			        fread(&ind_alb,29,1,Ialb);
			        fread(&ind_art,29,1,Iart);
			        fread(&ind_gen,29,1,Igen);
			       
			        for(int i=0; i < 2; i++)
					{
						caracter=fgetc(Igen);
					}
			        
					if(!strcmpi(buscar,ind_gen.Genero_ind))
					{
						strcpy(code,ind_gen.Genero_ind + 1);
						codi = atoi(code);
						posicion_gen = (codi)*86;
						fseek(pf,posicion_gen-86,SEEK_SET);	
			        
			        	fread(&dat,sizeof(dat),1,pf);
			        	if (dat.Reliminado == 1)
						{
							break;
						}
						system("cls");
						gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			   		 	ShowR ();
							
						do
						{
							gotoxy(36,13); cout << "¿Este Es El Registro Que Quieres Editar? [S] / [N]";
							respuesta=getch();
							
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								gotoxy(49,15); cout << "Introduce Una Opcion: ";
								getch();
							}
								
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S');
				
							if(respuesta == 's' || respuesta == 'S')
							{
									
								do
								{
									system("cls");
									gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
									
									ShowR ();
									
									memset(&ind_gen,0,sizeof(ind_gen));
									memset(code,0,sizeof(code));
								
									strcpy(code,dat.Codigo + 1);
									codi = atoi(code);
									posicion_alb = codi*31;
									posicion_art = codi*31;
									posicion_gen = codi*31;
									
									fseek(Ialb,posicion_alb-31,SEEK_SET);
									fread(&ind_alb,sizeof(ind_alb),1,Ialb);
									
									fseek(Iart,posicion_art-31,SEEK_SET);	
									fread(&ind_art,sizeof(ind_art),1,Iart);
									
									fseek(Igen,posicion_gen-31,SEEK_SET);
									fread(&ind_gen,sizeof(ind_gen),1,Igen);
								
									SwitchE ();
									
									strcpy(ind_gen.Genero_ind,dat.Genero);
									
									fseek(Ialb,-31,SEEK_CUR);
									fwrite(&dat.NombreAlbum,sizeof(ind_alb.NombreAlbum_ind),1,Ialb);
									fwrite(&dat.Codigo,sizeof(ind_alb.Codigo_ind_alb),1,Ialb);
									fwrite(&dat.Reliminado,sizeof(ind_alb.Reliminado_ind_alb),1,Ialb);
									fseek(Ialb,31,SEEK_CUR);
									
									fseek(Iart,-31,SEEK_CUR);
									fwrite(&dat.NombreArtista,sizeof(ind_art.NombreArtista_ind),1,Iart);
									fwrite(&dat.Codigo,sizeof(ind_art.Codigo_ind_art),1,Iart);
									fwrite(&dat.Reliminado,sizeof(ind_art.Reliminado_ind_art),1,Iart);
									fseek(Iart,31,SEEK_CUR);
									
									fseek(Igen,-31,SEEK_CUR);
									fwrite(&dat.Genero,sizeof(ind_gen.Genero_ind),1,Igen);
									fwrite(&dat.Codigo,sizeof(ind_gen.Codigo_ind_gen),1,Igen);
									fwrite(&dat.Reliminado,sizeof(ind_gen.Reliminado_ind_gen),1,Igen);
									fseek(Igen,31,SEEK_CUR);
									
									system("cls");
									gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
									gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
									getch();
						 	
									do
									{
										if(respuesta == 'n' || respuesta == 'N')
										{
											break;
										}
								
										system("cls");
										gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
										gotoxy(42,14); cout << "¿Quieres Editar Otro Campo? [S] / [N]";
										respuesta3=getch();
										
										if(respuesta3!= 'n' && respuesta3!= 'N' && respuesta3!= 's' && respuesta3!= 'S' )
										{
											gotoxy(47,16); cout << "Introduce Una Opcion: ";
											getch();
										}
									}while(respuesta3!= 'n' && respuesta3!= 'N' && respuesta3!= 's' && respuesta3!= 'S' );
							
								}while(respuesta3 == 's' || respuesta3 == 'S');
								
								fseek(pf,-84,SEEK_CUR);
								fwrite(&dat,sizeof(dat),1,pf);
								fseek(pf,84,SEEK_CUR);
			        		}
			        }
			     
				}while(caracter!=EOF);
								
				fclose(pf);
				fclose(Ialb);
				fclose(Iart);
				fclose(Igen);
			
			 	break;
			 }
			 	
		}while(op!=49 && op!=50 && op!=51);
		
		do
		{
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(38,14); cout << "¿Deseas Seguir Modificando Registros? [S] / [N]";
			respuesta2=getch();
	
			if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
			{
				gotoxy(47,16); cout << "Introduce Una Opcion: ";
				getch();
			}
		}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
	
	}while(respuesta2 == 's' || respuesta2 == 'S');
}*/

void Editar()
 {
 	char op;
 	int codi=0, posicion_alb=0, posicion_art=0, posicion_gen=0;  
	char code[5];

	if((pf = fopen(archivo_ori,"rb+")) == NULL || (Ialb = fopen(archivo_index_album,"rb+"))==NULL || (Iart = fopen(archivo_index_artista,"rb+"))==NULL || (Igen = fopen(archivo_index_genero,"rb+"))==NULL)
	{
		system("color C");
		gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
		exit(0);
		getch();
	}
		
	do
	{
		fflush(stdin);
		system("cls");
		
		gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;			
		cout << "\n\n[1] Por Nombre Album" << "\n[2] Por Nombre Artista" << "\n[3] Por Nombre Genero";
		cout << "\n\nPreciona el Numero del Indice Que Deseas Abrir: "; fflush(stdin);
      	op=getch();
      	
	    switch(op)
	    {
		    case '1':
		    	
			fseek(Ialb,0,SEEK_SET);
			char buscar [30];	
		    memset(code,0,sizeof(code));		
			cout << "\n\nIntroduce el Nombre del Album a Consultar y Editar: "; fflush(stdin);
			memset(buscar,0,sizeof(buscar));
			gets(buscar);
			
				do
				{
					memset(&ind_alb,0,sizeof(ind_alb));
					memset(&ind_alb,0,sizeof(ind_alb));
					memset(&dat,0,sizeof(dat));
					
					fread(&ind_alb,29,1,Ialb);
              	 
              	 	for(int i=0; i <2; i++)
					{
						caracter=fgetc(Ialb);
					}
					
              	 	if(!strcmpi(buscar, ind_alb.NombreAlbum_ind))
		            {
              	 		strcpy(code,ind_alb.Codigo_ind_alb + 1);
              	 		codi=atoi(code);
              	 		posicion_alb=(codi)*86;
              	 		fseek(pf,posicion_alb-86,SEEK_SET);
              	 		fread(&dat,sizeof(dat),1,pf);
              	 		
              	 		if(dat.Reliminado == 0)
              	 		{
              	 			ShowR ();
              	 			
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
									
								memset(&ind_alb,0,sizeof(ind_alb));
								memset(code,0,sizeof(code));
								strcpy(code,dat.Codigo + 1);
								codi=atoi(code);
								posicion_alb = (codi)*31;
								posicion_art = (codi)*31;
								posicion_gen = (codi)*31;
		              	 		fseek(Ialb,posicion_alb-31,SEEK_SET);
		              	 		fread(&ind_alb,29,1,Ialb);
		              	 		fseek(Iart,posicion_art-31,SEEK_SET);
		              	 		fread(&ind_art,29,1,Iart);
		              	 		fseek(Igen,posicion_gen-31,SEEK_SET);
		              	 		fread(&ind_gen,29,1,Igen);
		              	 		
		              	 		Seek ();
		              	 		
		              	 		fseek(pf,-84,SEEK_CUR);
								fwrite(&dat,sizeof(dat),1,pf);
								fseek(pf,84,SEEK_CUR);
							}	
		        	 	}
					}
					
				}while(!feof(Ialb));
		
			break;  
			
			/*case '2': 
			
			case '3': */
			        	  	  		
	    }
    }while(op!=27);

	fclose(pf);
	fclose(Ialb);
	fclose(Iart);
	fclose(Igen);	
 }

void Eliminar ()
{
	do
	{
		char op;
		char code [5];
		int codi = 0, posicion_alb = 0, posicion_art = 0, posicion_gen = 0;
		
		if((pf = fopen(archivo_ori,"rb+")) == NULL || (Ialb = fopen(archivo_index_album,"rb+"))==NULL || (Iart = fopen(archivo_index_artista,"rb+"))==NULL || (Igen = fopen(archivo_index_genero,"rb+"))==NULL)
		{
			system("color C");
			gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
			exit(0);
			getch();
		}
		gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;		
		cout << "\n\n[1] Por Nombre Album" << "\n[2] Por Nombre Artista" << "\n[3] Por Nombre Genero";
		cout << "\n\nPreciona el Numero del Indice Que Deseas Abrir: "; fflush(stdin);
		
		do
		{
			op = getch();
			
			switch(op)
			{
				case 49:
			    fseek(Ialb,0,SEEK_SET);

                cout << "\n\nIntroduce El Nombre Del Album a Consultar y Eliminar: "; fflush(stdin);		  
                gets(buscar);
				
				do
				{
                    respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
					memset(&dat,0,sizeof(dat));
					memset(&ind_alb,0,sizeof(ind_alb));
					memset(&code,0,sizeof(code));
					
					Rcreado = 0 , Rcreado_Iart = 0;
			        
			        fread(&ind_alb,29,1,Ialb);
			        fread(&ind_art,29,1,Iart);
			        fread(&ind_gen,29,1,Igen);
			        
              	 	for(int i=0; i <2; i++)
					{
						caracter=fgetc(Ialb);
					}
					
              	 	if(!strcmpi(buscar,ind_alb.NombreAlbum_ind))
              	 	{
              	 		strcpy(code,ind_alb.Codigo_ind_alb + 1);
						codi = atoi(code);
						posicion_alb = (codi)*86;
						fseek(pf,posicion_alb-86,SEEK_SET);	
			        
			        	fread(&dat,sizeof(dat),1,pf);
			        	if (dat.Reliminado == 1)
						{
							break;
						}
						system("cls");
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
			   		 	ShowR ();
              	
				  		do
						{
							gotoxy(36,13); cout << "¿Este es el Registro que Quieres Eliminar [S] / [N]";
							respuesta=getch();
							
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								gotoxy(49,15); cout << "Introduce una opcion: ";
								getch();
							}
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
        	        
		     		 }
				    if(respuesta == 's' || respuesta == 'S')
					{
						posicion_alb=0;
			
						codi=0;
						strcpy(code,dat.Codigo + 1);
						codi = atoi(code);
						posicion_alb = codi*31;
						
						fseek(Ialb,posicion_alb-31,SEEK_SET);
						fread(&ind_alb,sizeof(ind_alb),1,Ialb);
						
						fseek(Iart,posicion_art-31,SEEK_SET);	
						fread(&ind_art,sizeof(ind_art),1,Iart);
						
						fseek(Igen,posicion_gen-31,SEEK_SET);
						fread(&ind_gen,sizeof(ind_gen),1,Igen);
					
						dat.Reliminado = 1;
						ind_alb.Reliminado_ind_alb = 1;
						ind_art.Reliminado_ind_art = 1;
						ind_gen.Reliminado_ind_gen = 1;
			
						system("cls");
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
						gotoxy(44,14); cout << "¡Registro Eliminado con exito!";
						
						fseek(Ialb,-31,SEEK_CUR);
						fwrite(&dat.NombreAlbum,sizeof(ind_alb.NombreAlbum_ind),1,Ialb);
						fwrite(&dat.Codigo,sizeof(ind_alb.Codigo_ind_alb),1,Ialb);
						fwrite(&dat.Reliminado,sizeof(ind_alb.Reliminado_ind_alb),1,Ialb);
						fseek(Ialb,31,SEEK_CUR);
						
						fseek(Iart,-31,SEEK_CUR);
						fwrite(&dat.NombreArtista,sizeof(ind_art.NombreArtista_ind),1,Iart);
						fwrite(&dat.Codigo,sizeof(ind_art.Codigo_ind_art),1,Iart);
						fwrite(&dat.Reliminado,sizeof(ind_art.Reliminado_ind_art),1,Iart);
						fseek(Iart,31,SEEK_CUR);
						
						fseek(Igen,-31,SEEK_CUR);
						fwrite(&dat.Genero,sizeof(ind_gen.Genero_ind),1,Igen);
						fwrite(&dat.Codigo,sizeof(ind_gen.Codigo_ind_gen),1,Igen);
						fwrite(&dat.Reliminado,sizeof(ind_gen.Reliminado_ind_gen),1,Igen);
						fseek(Igen,31,SEEK_CUR);
						
						fseek(pf,-84,SEEK_CUR);
						fwrite(&dat,sizeof(dat),1,pf);
						fseek(pf,84,SEEK_CUR);
						
					}	
			   }while(!feof(Ialb));
	            
	            fclose(pf);
				fclose(Ialb);
		        break;
							
				case 50:
					
				fseek(Iart,0,SEEK_SET);

                cout << "\n\nIntroduce El Nombre Del Artista a Consultar y Eliminar: "; fflush(stdin);		  
                gets(buscar);
				
				do
				{
                    respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
					memset(&dat,0,sizeof(dat));
					memset(&ind_art,0,sizeof(ind_art));
					memset(&code,0,sizeof(code));
			        
			        fread(&ind_alb,29,1,Ialb);
			        fread(&ind_art,29,1,Iart);
			        fread(&ind_gen,29,1,Igen);
			        
              	 	for(int i=0; i <2; i++)
					{
						caracter=fgetc(Iart);
					}
					
              	 	if(!strcmpi(buscar,ind_art.NombreArtista_ind) && !feof(Iart) && ind_art.Reliminado_ind_art == 0)
              	 	{
              	 		strcpy(code,ind_art.Codigo_ind_art + 1);
						codi = atoi(code);
						posicion_art = (codi)*86;
						fseek(pf,posicion_art-86,SEEK_SET);	
			        
			        	fread(&dat,sizeof(dat),1,pf);
			    
						system("cls");
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
			   		 	ShowR ();
              	
				  		do
						{
							gotoxy(36,13); cout << "¿Este es el Registro que Quieres Eliminar [S] / [N]";
							respuesta=getch();
							
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								gotoxy(49,15); cout << "Introduce una opcion: ";
								getch();
							}
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
        	        
		     		 }
				    if(respuesta == 's' || respuesta == 'S')
					{
						posicion_art=0;
						codi=0;
						strcpy(code,dat.Codigo + 1);
						codi = atoi(code);
						posicion_art = codi*31;
						
						fseek(Ialb,posicion_alb-31,SEEK_SET);
						fread(&ind_alb,sizeof(ind_alb),1,Ialb);
						
						fseek(Iart,posicion_art-31,SEEK_SET);	
						fread(&ind_art,sizeof(ind_art),1,Iart);
						
						fseek(Igen,posicion_gen-31,SEEK_SET);
						fread(&ind_gen,sizeof(ind_gen),1,Igen);
					
						dat.Reliminado = 1;
						ind_alb.Reliminado_ind_alb = 1;
						ind_art.Reliminado_ind_art = 1;
						ind_gen.Reliminado_ind_gen = 1;
			
						system("cls");
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
						gotoxy(44,14); cout << "¡Registro Eliminado con exito!";
						
						fseek(Ialb,-31,SEEK_CUR);
						fwrite(&dat.NombreAlbum,sizeof(ind_alb.NombreAlbum_ind),1,Ialb);
						fwrite(&dat.Codigo,sizeof(ind_alb.Codigo_ind_alb),1,Ialb);
						fwrite(&dat.Reliminado,sizeof(ind_alb.Reliminado_ind_alb),1,Ialb);
						fseek(Ialb,31,SEEK_CUR);
						
						fseek(Iart,-31,SEEK_CUR);
						fwrite(&dat.NombreArtista,sizeof(ind_art.NombreArtista_ind),1,Iart);
						fwrite(&dat.Codigo,sizeof(ind_art.Codigo_ind_art),1,Iart);
						fwrite(&dat.Reliminado,sizeof(ind_art.Reliminado_ind_art),1,Iart);
						fseek(Iart,31,SEEK_CUR);
						
						fseek(Igen,-31,SEEK_CUR);
						fwrite(&dat.Genero,sizeof(ind_gen.Genero_ind),1,Igen);
						fwrite(&dat.Codigo,sizeof(ind_gen.Codigo_ind_gen),1,Igen);
						fwrite(&dat.Reliminado,sizeof(ind_gen.Reliminado_ind_gen),1,Igen);
						fseek(Igen,31,SEEK_CUR);
						
						fseek(pf,-84,SEEK_CUR);
						fwrite(&dat,sizeof(dat),1,pf);
						fseek(pf,84,SEEK_CUR);
						
					}	
			   }while(!feof(Iart));
	            
	            fclose(pf);
				fclose(Iart);
				
				break;
				      
				case 51:
								
				fseek(Igen,0,SEEK_SET);

                cout << "\n\nIntroduce El Nombre Del Artista a Consultar y Eliminar: "; fflush(stdin);		  
                gets(buscar);
				
				do
				{
                    respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
					memset(&dat,0,sizeof(dat));
					memset(&ind_gen,0,sizeof(ind_gen));
					memset(&code,0,sizeof(code));
			        
			        fread(&ind_alb,29,1,Ialb);
			        fread(&ind_art,29,1,Iart);
			        fread(&ind_gen,29,1,Igen);
			        
              	 	for(int i=0; i <2; i++)
					{
						caracter=fgetc(Igen);
					}
					
              	 	if(!strcmpi(buscar,ind_gen.Genero_ind) && !feof(Igen) && ind_gen.Reliminado_ind_gen == 0)
              	 	{
              	 		strcpy(code,ind_gen.Codigo_ind_gen + 1);
						codi = atoi(code);
						posicion_gen = (codi)*86;
						fseek(pf,posicion_gen-86,SEEK_SET);	
			        
			        	fread(&dat,sizeof(dat),1,pf);
			    
						system("cls");
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
			   		 	ShowR ();
              	
				  		do
						{
							gotoxy(36,13); cout << "¿Este es el Registro que Quieres Eliminar [S] / [N]";
							respuesta=getch();
							
							if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
							{
								gotoxy(49,15); cout << "Introduce una opcion: ";
								getch();
							}
						}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
        	        
		     		 }
				    if(respuesta == 's' || respuesta == 'S')
					{
						posicion_gen=0;
						codi=0;
						strcpy(code,dat.Codigo + 1);
						codi = atoi(code);
						posicion_gen = codi*31;
						
						fseek(Ialb,posicion_alb-31,SEEK_SET);
						fread(&ind_alb,sizeof(ind_alb),1,Ialb);
						
						fseek(Iart,posicion_art-31,SEEK_SET);	
						fread(&ind_art,sizeof(ind_art),1,Iart);
						
						fseek(Igen,posicion_gen-31,SEEK_SET);
						fread(&ind_gen,sizeof(ind_gen),1,Igen);
					
						dat.Reliminado = 1;
						ind_alb.Reliminado_ind_alb = 1;
						ind_art.Reliminado_ind_art = 1;
						ind_gen.Reliminado_ind_gen = 1;
			
						system("cls");
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
						gotoxy(44,14); cout << "¡Registro Eliminado con exito!";
						
						fseek(Ialb,-31,SEEK_CUR);
						fwrite(&dat.NombreAlbum,sizeof(ind_alb.NombreAlbum_ind),1,Ialb);
						fwrite(&dat.Codigo,sizeof(ind_alb.Codigo_ind_alb),1,Ialb);
						fwrite(&dat.Reliminado,sizeof(ind_alb.Reliminado_ind_alb),1,Ialb);
						fseek(Ialb,31,SEEK_CUR);
						
						fseek(Iart,-31,SEEK_CUR);
						fwrite(&dat.NombreArtista,sizeof(ind_art.NombreArtista_ind),1,Iart);
						fwrite(&dat.Codigo,sizeof(ind_art.Codigo_ind_art),1,Iart);
						fwrite(&dat.Reliminado,sizeof(ind_art.Reliminado_ind_art),1,Iart);
						fseek(Iart,31,SEEK_CUR);
						
						fseek(Igen,-31,SEEK_CUR);
						fwrite(&dat.Genero,sizeof(ind_gen.Genero_ind),1,Igen);
						fwrite(&dat.Codigo,sizeof(ind_gen.Codigo_ind_gen),1,Igen);
						fwrite(&dat.Reliminado,sizeof(ind_gen.Reliminado_ind_gen),1,Igen);
						fseek(Igen,31,SEEK_CUR);
						
						fseek(pf,-84,SEEK_CUR);
						fwrite(&dat,sizeof(dat),1,pf);
						fseek(pf,84,SEEK_CUR);
						
					}	
			   }while(!feof(Igen));
	            
	            fclose(pf);
				fclose(Igen);
				
			 	break;
			 }
			 	
		}while(op!=49 && op!=50 && op!=51);
		
		do
		{
			system("cls");
			gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
			gotoxy(38,14); cout << "¿Deseas Seguir Eliminando Registros? [S] / [N]";
			respuesta2=getch();
	
			if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
			{
				gotoxy(47,16); cout << "Introduce una opcion: ";
				getch();
			}
		}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
	
	}while(respuesta2 == 's' || respuesta2 == 'S');
}

void ShowR ()
{
	cout << "\n\t\t\t\t\t      " << dat.Codigo << endl;
	cout << "\t\t\t\t\t      ____________________________" << endl;
	cout << "\t\t\t\t\t         Nombre Album: " << dat.NombreAlbum << endl;
	cout << "\t\t\t\t\t         Nombre Artista: " << dat.NombreArtista << endl;
	cout << "\t\t\t\t\t         Publicacion: " << dat.Publicacion << endl;
	cout << "\t\t\t\t\t         Num Canciones: " << dat.NumTracks << endl;
	cout << "\t\t\t\t\t         Genero: " << dat.Genero << endl;
	cout << "\t\t\t\t\t         Duracion del album: " << dat.Tiempo << endl;
	cout << "\t\t\t\t\t      ____________________________" << endl;
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

void Seek ()
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
					memset(ind_alb.NombreAlbum_ind,0,sizeof(ind_alb.NombreAlbum_ind));
					memset(&dat.NombreAlbum,0,sizeof(dat.NombreAlbum));
					ind_alb.Reliminado_ind_alb = 0;
				
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
				
				strcpy(ind_alb.NombreAlbum_ind,dat.NombreAlbum);
			    fseek(Ialb,-29,SEEK_CUR);
				fwrite(&dat.NombreAlbum,sizeof(ind_alb.NombreAlbum_ind),1,Ialb);
				fseek(Ialb,29,SEEK_CUR);
				
				system("cls");
				gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
				gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
				getch();

			break;
			
			case 50:
				
			do
			{	
				memset(ind_art.NombreArtista_ind,0,sizeof(ind_art.NombreArtista_ind));
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
			
			strcpy(ind_art.NombreArtista_ind,dat.NombreArtista);
		    fseek(Iart,-29,SEEK_CUR);
			fwrite(&dat.NombreArtista,sizeof(ind_art.NombreArtista_ind),1,Iart);
			fseek(Iart,29,SEEK_CUR);
			
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();
	
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
		
			
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();
		 	
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
			
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();
		 
		 	break;
		 	
		 	case 53:
		 	
		 	memset(ind_gen.Genero_ind,0,sizeof(ind_gen.Genero_ind));
		 	memset(&dat.Genero,0,sizeof(dat.Genero));
		 	system("cls");
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
			
			strcpy(ind_gen.Genero_ind,dat.Genero);
		    fseek(Igen,-29,SEEK_CUR);
			fwrite(&dat.Genero,sizeof(ind_gen.Genero_ind),1,Igen);
			fseek(Igen,29,SEEK_CUR);
			
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();
		 	
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
			
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();

			break;
		}
		
	}while(op!=49 && op!=50 && op!=51 && op!=52 && op!=53 && op!=54);
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
