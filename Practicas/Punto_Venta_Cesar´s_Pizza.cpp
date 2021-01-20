
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

#define ADMIN "arturo"
#define PASS "123"
#define ENTER 13 
#define BACKSPACE 8

using namespace std;

typedef struct Pizzeria 
{
    char Codigo [5];
    char Nombre_Producto [25];
    char Precio [5];
    char Cantidad [5];
    int  Reliminado;
} DATOS;

typedef struct Index_Pizzeria 
{
    char Codigo_Ind_Pro [5];
    char Nombre_Producto_Ind_Pro [25];
    int  Reliminado_Ind_Pro;
} IND_DATOS;

typedef struct Login_empleados
{
	char Codigo_log [5];
	char Nom_usuarios [20];
	char Contra_usuarios [20];
	int  Reliminado_log;
} LOGIN;

typedef struct Index_Login_empleados
{
	char Codigo_log_Ind_Em [5];
	char Nom_usuarios_Ind_Em [20];
	int  Reliminado_log_Ind_Em;
} IND_LOGIN;

typedef struct Ventas
{
	char Codigo_Venta [5];
    char Nombre_Producto_Venta [25];
    char Cantidad_Venta [5];
    char Pre_Total  [10];
} VENTAS;

///////////////////////////////////////////////
DATOS dat; IND_DATOS ind_dat; LOGIN logi; IND_LOGIN ind_logi; VENTAS vent; 
FILE *pf, *ind_pf, *log, *ind_log, *ven, *rep; 
///////////////////////////////////////////////
int  lon = 0 , aux = 0;
int  respuesta, respuesta2, respuesta3;
char caracter = '\0';
char buscar[50];
bool ban = false;
///////////////////////////////////////////////
char Menu             (void);
int  Contador  		  ();
int Login     		  ();
int F1_Ventas    	  ();
int F2_Alta    	      ();
int F3_Bajas		  ();
int F4_Edicion        ();
int F5_Consultas      ();
int F6_Reportes 	  ();
int F7_Papelera  	  ();
///////////////////////////////////////////////
char Marco            ();
char Loading_bar 	  ();
void gotoxy(int,int);
void Setcolor(WORD color);
void ResetColor(WORD Attributes);
///////////////////////////////////////////////
void baja_pro    	  ();
void baja_usu    	  ();
void edicion_pro 	  ();
void edicion_usu 	  ();
void Seek             ();
void Seek_Usu         ();
void Show_Usu 	 	  ();
void Show_Ventas 	  ();
void Show_Inventario  ();
///////////////////////////////////////////////

int main ()
{
	char Opcion = '\0';
	Loading_bar ();
	Login ();
	
	do
	{	
		Opcion = Menu();
		
		switch(Opcion)
		{	
			case 59: //F1
		    system("cls"); F1_Ventas (); break;
			case 60: //F2
			system("cls"); F2_Alta (); break;
		    case 61: //F3
		    system("cls"); F3_Bajas (); break;
		    case 62: //F4
		    system("cls"); F4_Edicion (); break;
		    case 63: //F5
		    system("cls"); F5_Consultas ();break;
		    case 64: //F6
		    system("cls"); F6_Reportes (); break;
			case 65: //F7
		    system("cls"); F7_Papelera (); break;
			case 27: // Esq
			return Login ();
		}
	}while(Opcion!=27);
	return Login ();
}

char Marco ()
{
	char p;
	memset(&p,218,sizeof(p));
	for (int i=2;i<=117;i++)
	{
		gotoxy (i,1); cout << p;   
   		gotoxy (i,30); cout << p;
	}                          
	for (int i=1;i<=30;i++)
	{
		gotoxy (1,i); cout << p;   
   		gotoxy (118,i); cout << p;
	}                           
}

char Loading_bar ()
{	
	char barra;
	memset(&barra,219,sizeof(barra));
	for (int j=0; j<=100; j++)
	{
		system("cls");
		Setcolor(3); 
		gotoxy(50,12);	cout << "CARGANDO SISTEMA..."<< j << "%" << endl;
		Setcolor(7);
		Setcolor(11);  
		gotoxy(36,14);	cout << "";
		for(int i=1; i<=j; i++)
		{
			if(i%2==0)
			{
				cout << barra;
			}
		}
		cout << endl;
		Sleep(5);
	}
}

char Menu (void)
{
	char opcion = '\0';
	memset(&opcion,0,sizeof(opcion));
	setlocale(LC_CTYPE, "Spanish");
	system("cls");
	Setcolor(14); 
	gotoxy(0,2);cout << "  ____________________________________________________________________________________________________________________" << endl;
	gotoxy(0,4);cout << "                                                      CESAR´S PIZZA                                                     " << endl;
	gotoxy(0,5);cout << "  ____________________________________________________________________________________________________________________" << endl;
	ResetColor(7);
	gotoxy(47,9);  cout << "  [F1] Ventas                 ";
	gotoxy(47,11); cout << "  [F2] Alta                   ";
	gotoxy(47,13); cout << "  [F3] Baja                   ";
	gotoxy(47,15); cout << "  [F4] Edición                ";
	gotoxy(47,17); cout << "  [F5] Consultas              ";
	gotoxy(47,19); cout << "  [F6] Reportes               ";
	gotoxy(47,21); cout << "  [F7] Papelera Reciclaje     ";
	gotoxy(47,23); cout << "  [Esc] SALIR                 ";
	Setcolor(14); 
	Marco ();
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    gotoxy(102,4); strftime(output,128,"%d/%m/%y %H:%M",tlocal);
    gotoxy(102,4); cout << output;
	gotoxy(45,26); cout << "INGRESE UNA OPCIÓN: "; fflush(stdin);
	ResetColor(7); 
	opcion = getch();
}
/*******************************Inicio Validaciones*******************************/

void Descripcion_Pizzas_Calzone ()
{
	gotoxy(1,5);  cout << "[1] Pizza Grande: Una Pizza Grande Con Tres Ingrediente a Elegir ";
	gotoxy(1,7);  cout << "[2] Pizza Mediana: Una Pizza Mediana Con Tres Ingrediente a Elegir ";
	gotoxy(1,9);  cout << "[3] Pizza Chica: Una Pizza Chica Con Tres Ingrediente a Elegir ";
	gotoxy(1,11); cout << "[4] Calzone: Un Calzone Tamaño Unico Con Tres Ingrediente a Elegir ";
}

void Productos_Pizza_Calzone ()
{
	char op_pizza;
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	Descripcion_Pizzas_Calzone ();
	Setcolor(14); 
	gotoxy(1,13); cout << "Ingresa Una Opción: ";
	ResetColor(7);
		
	do
	{
		fflush(stdin);
		op_pizza = getch(); 
		
		switch(op_pizza)
		{
			case 49: 
			strcpy(dat.Nombre_Producto,"Pizza Grande"); break;
			case 50:
			strcpy(dat.Nombre_Producto,"Pizza Mediana"); break;
			case 51:
			strcpy(dat.Nombre_Producto,"Pizza Chica"); break;
		 	case 52:
			strcpy(dat.Nombre_Producto,"Calzone"); break;
		}
	}while(op_pizza!=49 && op_pizza!=50 && op_pizza!=51 && op_pizza!=52);
}

void Descripcion_Bebidas ()
{
	gotoxy(1,5); cout << "[1] Refresco: Refresco de 600 ml. Varios Sabores A Elegir ";
	gotoxy(1,7); cout << "[2] Cerveza: Cerveza De 350 ml. Diferetes Marcas A Elegir ";
	gotoxy(1,9); cout << "[3] Jugo Natural: Jugo Natural De 500 ml. Varios Sumos A Escojer ";
	
}

void Productos_Bebidas ()
{
	char op_bebida;
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	Descripcion_Bebidas ();
	Setcolor(14); 
	gotoxy(1,11); cout << "Ingresa Una Opción: ";
	ResetColor(7);
		
	do
	{
		fflush(stdin);
		op_bebida = getch(); 
		
		switch(op_bebida)
		{
			case 49: 
			strcpy(dat.Nombre_Producto,"Refresco"); break;
			case 50:
			strcpy(dat.Nombre_Producto,"Cerveza"); break;
			case 51:
			strcpy(dat.Nombre_Producto,"Jugo Natural"); break;
		}
	}while(op_bebida!=49 && op_bebida!=50 && op_bebida!=51);
}

void Descripcion_Combos ()
{
	gotoxy(1,5);  cout << "[1] Combo Envidioso: Una Pizza Grande Con Tres Ingrediente Con Refresco"; 
	gotoxy(1,7);  cout << "[2] Combo Familiar: Una Pizza Grande Cuatro Ingrediente Acompañadas Con Papas Gajo";
	gotoxy(1,9);  cout << "[3] Combo Cuates: Dos Pizza Medianas Con Un Ingrediente";
	gotoxy(1,11); cout << "[4] Combo Amigos: Una Pizza Medianas Con Dos Ingrediente, Refresco o Cervesa Y Acompañadas Con Papas Gajo";
	gotoxy(1,13); cout << "[5] Combo Compartido: Seis Piezas De Alitas, Papas Gajo Y Un Refresco";
	gotoxy(1,15); cout << "[6] Combo Borracho: Seis Piezas De Alitas Con Una Cervesa";
	gotoxy(1,17); cout << "[7] Combo Solitario: Un Calzone Con Tres Ingredientes, Acompañado De Un Refresco o Cervesa";
	gotoxy(1,19); cout << "[8] Combo Fieston: Dos Pizzas Grandes Con Cuatro Ingresdientes, Pack de Seis Alitas, Papas Gajo Y Un Six De Cervesa";
}

void Productos_Combo ()
{
	char op_combo;
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	Descripcion_Combos ();
	Setcolor(14); 
	gotoxy(1,21); cout << "Ingresa Una Opción: ";
	ResetColor(7);
		
	do
	{
		fflush(stdin);
		op_combo = getch(); 
		
		switch(op_combo)
		{
			case 49: 
			strcpy(dat.Nombre_Producto,"Combo Envidioso"); break;
			case 50:
			strcpy(dat.Nombre_Producto,"Combo Familiar"); break;
			case 51:
			strcpy(dat.Nombre_Producto,"Combo Cuates"); break;
		 	case 52:
			strcpy(dat.Nombre_Producto,"Combo Amigos"); break;
		 	case 53:
			strcpy(dat.Nombre_Producto,"Combo Compartido"); break;
		 	case 54:
			strcpy(dat.Nombre_Producto,"Combo Borracho"); break;
			case 55:
			strcpy(dat.Nombre_Producto,"Combo Solitario"); break;
			case 56:
			strcpy(dat.Nombre_Producto,"Combo Fieston"); break;
		}
	}while(op_combo!=49 && op_combo!=50 && op_combo!=51 && op_combo!=52 && op_combo!=53 && op_combo!=54 && op_combo!=55 && op_combo!=56);
}

int Menu_seleccion_Product ()
{
	char op_product;
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	gotoxy(45,11); cout << "[1] Pizzas Por Tamaños Y Calzone "; 
	gotoxy(45,13); cout << "[2] Bebidas ";
	gotoxy(45,15); cout << "[3] Combos ";
	gotoxy(45,17); cout << "[Esc] Salir";
	Setcolor(14); 
	gotoxy(45,19); cout << "Seleccione Una Categoria De Productos: ";
	ResetColor(7);
	
	do
	{
		fflush(stdin);
		op_product = getch(); 
		
		switch(op_product)
		{
			case 49:
			system("cls"); Productos_Pizza_Calzone (); break;
			case 50:
			system("cls"); Productos_Bebidas (); break;
			case 51:
			system("cls"); Productos_Combo (); break;
			case 27:
			return F2_Alta ();
			break;
		}
	}while(op_product!=49 && op_product!=50 && op_product!=51 && op_product!=27);	
}

int Venta (char Precio [5])
{
	if (strlen(Precio) < 4)
	{
		if (Precio[0] == '\0')
			return 0;
		for (int i = 0; i < strlen(Precio); i++)
			if (!isdigit(Precio[i]))
				return 0;
		return 1;
	}
	return 0;
}

int Piezas (char Cantidad [5])
{
	if (strlen(Cantidad) < 5)
	{
		if (Cantidad[0] == '\0')
			return 0;
		for (int i = 0; i < strlen(Cantidad); i++)
			if (!isdigit(Cantidad[i]))
				return 0;
		return 1;
	}
	return 0;
}
/*******************************Fin Validaciones*********************************/ 

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

int Contador_Usu ()
{
	LOGIN logi;
	int TamR = 1;
	int TamARC = 0;
	int Registros = 0;
	
	TamR=sizeof(logi);
	
	fseek(log,0,SEEK_END); 
	TamARC=ftell(log); 
	
	Registros=TamARC/TamR; 
	return Registros + 1; 
}

int Contador_Venta ()
{
	VENTAS vent;
	int TamR = 1;
	int TamARC = 0;
	int Registros = 0;
	
	TamR=sizeof(vent);
	
	fseek(ven,0,SEEK_END); 
	TamARC=ftell(ven); 
	
	Registros=TamARC/TamR; 
	return Registros + 1;  
}

void PassW (char *enter, int maximo)
{
	char caracter;
	int x = 0;
	fflush(stdin);
	while(1)
	{
		caracter=getch();
		if(caracter == 13)
		{
			enter[x]='\0';
			break;
		}
		if(caracter == 8 && x!=0)
		{
			cout << "\b \b";
			if(x <= maximo && x > 0)
			x--;
		}
		else
		if (x < maximo && caracter!=8)
		{
			cout << "*";
			enter[x] = caracter;
			x++;
		}
	}
}

int Login ()
{
	string alias, password;
	char op_login;
    int  contador = 0;
    bool ingresar = false;
    int  codi=0, posicion_log=0;  
	char code[5];

	system("cls");
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(14); 
	gotoxy(0,2);cout << "  ____________________________________________________________________________________________________________________" << endl;
	gotoxy(0,4);cout << "                                                  LOGIN CESAR´S PIZZA                                                     " << endl;
	gotoxy(0,5);cout << "  ____________________________________________________________________________________________________________________" << endl;
	ResetColor(7);
	Setcolor(7);			
	gotoxy(45,13); cout << "[F1] Iniciar Sesión Como Administrador"; 
	gotoxy(45,15); cout << "[F2] Iniciar Sesión Como Empleado";
	gotoxy(45,17); cout << "[Esc] Salir";
	Setcolor(14); 
	Marco ();
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    gotoxy(102,4); strftime(output,128,"%d/%m/%y %H:%M",tlocal);
    gotoxy(102,4); cout << output;
	gotoxy(45,20); cout << "INGRESE UNA OPCIÓN: "; 
	ResetColor(7);
	
	do
	{
		fflush(stdin);
		op_login = getch();
		
		switch(op_login)
		{
			case 59:
			
			do 
			{
				system("cls");
				Marco ();
				system("color 3");
				gotoxy(45,11); cout << "Nombre Del Administrador:"; fflush(stdin);
				gotoxy(71,11); getline(cin,alias);
				gotoxy(45,13); cout << "Contraseña: "; fflush(stdin);
	          	char caracter;
	          	caracter = getch();
	     
	          	password = "";
	     
	          	while (caracter != ENTER) 
				{
					if (caracter != BACKSPACE) 
					{
						password.push_back(caracter);
	    	         	cout << "*";
					} 
					else 
					{
						if (password.length() > 0) 
						{
	    					cout << "\b \b";
	    					password = password.substr(0, password.length() - 1);
	    				}
	    			}
	     
	    			caracter = getch();
				}
				
		  		if (alias == ADMIN && password == PASS) 
			  	{
					ingresar = true;
	          	} 
				else 
			  	{
					gotoxy(40,17); cout << "Nombre y/o Contraseña Son Incorrectos" << endl;
	             	getch();
	             	contador++;
	          	}
		    }while (ingresar == false && contador < 3);
		     
	       		if (ingresar == false) 
				{
					system("cls");
					system("color C");
	          		gotoxy(40,14); cout << "¡Acceso Denegado Maximo 3 Intentos!" << endl;
	          		exit(0);
	       		}	 
				else 
				{
					system("cls");
					system("color A");
	          		gotoxy(50,13); cout << "!BIENVENIDO ARTURO!" << endl;
	          		getch();
	       		}
	       		return Menu ();
			
			break;
			
			case 60:
				
			char buscar_alias [20], buscar_contra [20];
			
		
			if((log = fopen("Usuarios.dat","rb")) == NULL)
			{
				system("cls");
				system("color C");
				gotoxy(40,14); cout << "¡No Se Encontro El Archivo Para La Lectura!";
				getch();
				return Login();
			}
				
			do
			{
				system("cls");
				Marco ();
				system("color 3");
				gotoxy(45,11); cout << "Nombre Del Usuario: "; fflush(stdin);
				gotoxy(65,11); gets(buscar_alias);
				gotoxy(45,13); cout << "Contraseña Del Usuario: "; fflush(stdin);
				PassW (buscar_contra,19);
		
				do
				{
					memset(&logi,0,sizeof(logi));
					
					fread(&logi,52,1,log);
					
					for(int i=0; i < 2; i++)
					{
						caracter=fgetc(log);
					}
					
		      	 	if(!strcmpi(buscar_alias,logi.Nom_usuarios) && !strcmpi(buscar_contra,logi.Contra_usuarios))
		            {
		        		ingresar = true;
		            	getch();	
		            }
		            else 
				  	{
		             	contador++;
		          	}
            	
				}while(!feof(log));
			
			}while (ingresar == false && contador < 4);
	          	
		          	if (ingresar == false) 
					{
						system("cls");
						system("color C");
		          		cout << "¡Acceso Denegado Maximo 3 Intentos!" << endl;
		          		exit(0);
		       		}	 
					else 
					{
						system("cls");
						system("color A");
		          		gotoxy(50,13); cout << "!BIENVENIDO!" << endl;
		          		getch();	
		       		}
				
			fclose(log);
			return Menu();
			
			break;
			
			case 27:
			system("cls");
			system("color A");
			gotoxy(50,11); cout<<"¡Hasta La Proxima!";
			exit(0);
		}
	}while(op_login!=59 && op_login!=60 && op_login!=27);
}

void mostrar_inventario ()
{
	do
	{
		char x;
		memset(&dat,0,sizeof(dat));
        
        fread(&dat,sizeof(dat),1,pf);
        
        for(int i=0; i < 2; i++)
		{
			caracter=fgetc(pf);
		}
		if(!feof(pf) && dat.Reliminado == 0)
		{
			Show_Inventario ();
			x=x+2;
			gotoxy(20,x+5); cout << dat.Codigo;
			gotoxy(40,x+5); cout << dat.Nombre_Producto;
			gotoxy(65,x+5); cout << dat.Cantidad;
			gotoxy(85,x+5); cout << "$" << dat.Precio;
        }
       
	}while(caracter!=EOF);
}

void mostrar_inventario_2 ()
{
	do
	{
		char j;
		memset(&logi,0,sizeof(logi));
        
        fread(&logi,sizeof(logi),1,log);
        
        for(int i=0; i < 2; i++)
		{
			caracter=fgetc(log);
		}
		if(!feof(log) && logi.Reliminado_log == 0)
		{
			Show_Usu ();
   		 	j=j+2;
			gotoxy(30,j+5); cout << logi.Codigo_log;
			gotoxy(55,j+5); cout << logi.Nom_usuarios;
			gotoxy(80,j+5); cout << logi.Contra_usuarios;
			
        }
       
	}while(caracter!=EOF);
}

void mostrar_inventario_2_pape ()
{
	do
	{
		char j;
		memset(&logi,0,sizeof(logi));
        
        fread(&logi,sizeof(logi),1,log);
        
        for(int i=0; i < 2; i++)
		{
			caracter=fgetc(log);
		}
		if(!feof(log) && logi.Reliminado_log == 1)
		{
			Show_Usu ();
   		 	j=j+2;
			gotoxy(30,j+5); cout << logi.Codigo_log;
			gotoxy(55,j+5); cout << logi.Nom_usuarios;
			gotoxy(80,j+5); cout << logi.Contra_usuarios;
			
        }
       
	}while(caracter!=EOF);
}

void mostrar_inventario_pape ()
{
	do
	{
		char x;
		memset(&dat,0,sizeof(dat));
        
        fread(&dat,sizeof(dat),1,pf);
        
        for(int i=0; i < 2; i++)
		{
			caracter=fgetc(pf);
		}
		if(!feof(pf) && dat.Reliminado == 1)
		{
			Show_Inventario ();
			x=x+2;
			gotoxy(20,x+5); cout << dat.Codigo;
			gotoxy(40,x+5); cout << dat.Nombre_Producto;
			gotoxy(65,x+5); cout << dat.Cantidad;
			gotoxy(85,x+5); cout << "$" << dat.Precio;
        }
       
	}while(caracter!=EOF);
}

void mostrar_inventario_ventas ()
{
	do
	{
		char v;
		memset(&vent,0,sizeof(vent));
        
        fread(&vent,sizeof(vent),1,ven);
        
        for(int i=0; i < 2; i++)
		{
			caracter=fgetc(ven);
		}
		if(!feof(ven))
		{
			Show_Ventas ();
			v=v+2;
			gotoxy(20,v+5); cout << vent.Codigo_Venta;
			gotoxy(40,v+5); cout << vent.Nombre_Producto_Venta;
			gotoxy(65,v+5); cout << vent.Cantidad_Venta;
			gotoxy(85,v+5); cout << "$" << vent.Pre_Total;
        }
       
	}while(caracter!=EOF);
}

int F1_Ventas ()
{
	char op_F1;
	char code_venta [5], codigos_ven [5];
	int codi_venta = 0, posicion_pro=0, Multi_canti = 0, dinero_usuario = 0, cont_ven = 0;  
	
	system("cls");
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	gotoxy(45,11); cout << "[1] Vender Productos"; 
	gotoxy(45,13); cout << "[Esc] Salir";
	Setcolor(14);
	Marco ();
	gotoxy(45,15); cout << "INGRESE UNA OPCIÓN: ";
	ResetColor(7);
	
	do
	{
		fflush(stdin);
		op_F1 = getch();
	
		switch(op_F1)
		{
			case 49:
				
			do
			{
				int cantidad_V = 0, Resta_canti = 0, datCanti = 0, datPrecio = 0, total = 0;
				char convertir_1 [25], convertir_2 [25], venta [5], pretotal [10], CodigoR_ven [5] = "V00";
		
			
				if((pf = fopen("Inventario.dat","rb+")) == NULL || (ven = fopen("Ventas.dat","rb")) == NULL)
				{	
					ven = fopen("Ventas.dat","wb");	
					system("color C");
					system("cls");
					gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
					getch();
					return  Menu ();
				}
				ven = fopen("Ventas.dat","ab+");
				
				//memset(&vent,0,sizeof(vent));
				
				cont_ven=Contador_Venta ();	
				
				itoa(cont_ven,codigos_ven,10);
				strcat(CodigoR_ven,codigos_ven);
				strcpy(vent.Codigo_Venta,CodigoR_ven);
				
				memset(&CodigoR_ven,0,sizeof(CodigoR_ven));
				
				system("cls");
				mostrar_inventario ();
				Marco ();
				
				fseek(pf,0,SEEK_SET);
				
	            gotoxy(3,2); cout << "Introduce El Codigo Del Producto: "; fflush(stdin);		  
	            gets(buscar);
	            if(strlen(buscar) == '\0')
	            {
	            	return F1_Ventas ();
				}
	            
	        	do
	        	{
					char x;
					memset(&x,0,sizeof(x));
					memset(&dat,0,sizeof(dat));
					memset(&code_venta,0,sizeof(code_venta));
			        
			        fread(&dat,44,1,pf);
			       
              	 	for(int i=0; i <2; i++)
					{
						caracter=fgetc(pf);
					}
					
              	 	if(!strcmpi(buscar,dat.Codigo))
              	 	{
              	 		strcpy(code_venta,dat.Codigo + 1);
						codi_venta = atoi(code_venta);
						posicion_pro = (codi_venta)*46;
						fseek(pf,posicion_pro-46,SEEK_SET);	
			        
			        	fread(&dat,sizeof(dat),1,pf);
			        	if (dat.Reliminado == 1)
						{
							break;
						}
						
						system("cls");
						Marco ();
			   		 	Show_Inventario ();
						x=x+2;
						gotoxy(20,x+5); cout << dat.Codigo;
						gotoxy(40,x+5); cout << dat.Nombre_Producto;
						gotoxy(65,x+5); cout << dat.Cantidad;
						gotoxy(85,x+5); cout << "$" << dat.Precio;
						gotoxy(40,2); cout << "Producto Agregado Correctamente";
						getch();
		     		 
						while(cantidad_V >= datCanti)
						{
							char x;
							datCanti = atoi(dat.Cantidad);
							datPrecio = atoi(dat.Precio);
							total= atoi(vent.Pre_Total);
							
							system("cls");
							Marco ();
							Show_Inventario ();
							x=x+2;
							gotoxy(20,x+5); cout << dat.Codigo;
							gotoxy(40,x+5); cout << dat.Nombre_Producto;
							gotoxy(65,x+5); cout << dat.Cantidad;
							gotoxy(85,x+5); cout << "$" << dat.Precio;
							gotoxy(3,2); cout << "Introduce La Cantidad A Vender: "; fflush(stdin);
							cin >> cantidad_V;
					
							Resta_canti=datCanti-cantidad_V;
							
							itoa(Resta_canti,convertir_1,10);
							strcpy(dat.Cantidad,convertir_1);
							
							fseek(pf,-44,SEEK_CUR);
							fwrite(&dat,sizeof(dat),1,pf);
							fseek(pf,44,SEEK_CUR);
							
							total=cantidad_V*datPrecio;
							Multi_canti=Multi_canti+total;
							
							memset(&x,0,sizeof(x));
	              	 		system("cls");
							Marco ();
				   		 	Show_Inventario ();
							x=x+2;
							gotoxy(20,x+5); cout << dat.Codigo;
							gotoxy(40,x+5); cout << dat.Nombre_Producto;
							gotoxy(65,x+5); cout << dat.Cantidad;
							gotoxy(85,x+5); cout << "$" << dat.Precio;
							gotoxy(40,2); cout << "Cantidad Agrega Correctamente";
							getch();
							
							itoa(cantidad_V,venta,10);
							itoa(total,pretotal,10);
							strcpy(vent.Pre_Total,pretotal);
					   		strcpy(vent.Cantidad_Venta,venta);
							strcpy(vent.Nombre_Producto_Venta,dat.Nombre_Producto);
							fwrite(&vent,sizeof(vent),1,ven);
							fprintf(ven,"\r\n");
						}
					}
				 	
		   		}while(!feof(pf));
		   					
		   		fclose(pf);
				fclose(ven);
		   		
		   		do
				{	
					system("cls");
					Marco ();
					gotoxy(38,12); cout << "¿Deseas Agregar Otro Producto A La Venta? [S] / [N]";
					respuesta=getch();
					
					if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
					{
						gotoxy(47,14); cout << "Introduce Una Opcion: ";
						getch();
					}
				}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
			}while(respuesta=='s' || respuesta=='S');
			
					while(dinero_usuario < Multi_canti)
					{
						system("cls");
						Marco ();			
						if(Multi_canti == 0)
						return 0;
						
						ven = fopen("Ventas.dat","rb");
						mostrar_inventario_ventas ();
						
						gotoxy(42,25); cout << "Total De La Compra: " << "$" << Multi_canti;
						gotoxy(42,27); cout << "Introduce El dinero Para Pagar La Cuenta: " << "$"; fflush(stdin);
						cin >> dinero_usuario;
						
						if(dinero_usuario < Multi_canti)
						{
							gotoxy(20,2); cout << "¡La cantidad de dinero con la que quiere pagar el cliente no es suficiente para cerrar la cuenta!";
						}
						
						system("cls");
						Marco ();
					    if(dinero_usuario >= Multi_canti && Multi_canti!= 0)
						{
							ven = fopen("Ventas.dat","rb");
							mostrar_inventario_ventas ();
					    	gotoxy(42,25);  cout << "Dinero Ingresado: " << "$" << dinero_usuario;
					    	gotoxy(42,27); cout << "El Cambio es de: " << "$" << dinero_usuario-Multi_canti;
					    	getch();
						}
					}
			
					return F1_Ventas ();
			break;
		
			case 27:
			return Menu();
			break;
		}
	}while(op_F1!=49 && op_F1!=27);
}

int F2_Alta()
{
	char op_F2;
	system("cls");
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	gotoxy(45,11); cout << "[1] Registrar Productos"; 
	gotoxy(45,13); cout << "[2] Dar De Alta Empleados";
	gotoxy(45,15); cout << "[Esc] Salir";
	Setcolor(14);
	Marco ();
	gotoxy(45,18); cout << "INGRESE UNA OPCIÓN: ";
	ResetColor(7);
	
	do
	{	
		fflush(stdin);
		op_F2 = getch();
	
		switch(op_F2)
		{
			case 49:
			int  cont;
			char codigos [5];
			
			do
			{
				char CodigoR [5] = "R00";
				
				if((pf = fopen("Inventario.dat","rb"))==NULL && (ind_pf = fopen("Index_Inventario.dat","rb"))==NULL)
				{
					pf = fopen("Inventario.dat","wb");
					ind_pf = fopen("Index_Inventario.dat","wb");
				}
			
				pf = fopen("Inventario.dat","ab+");
				ind_pf = fopen("Index_Inventario.dat","ab+");
			
				system("cls");
				
				memset(&dat,0,sizeof(dat));
				
				cont=Contador ();	
				
				itoa(cont,codigos,10);
				strcat(CodigoR,codigos);
				strcpy(dat.Codigo,CodigoR);
				
				memset(&CodigoR,0,sizeof(CodigoR));
				
				gotoxy(0,1);cout << "______________________________________________ ¡FUNCION ALTA REGISTROS! ________________________________________________" << endl;
				
				Marco ();
				gotoxy(3,3); cout << dat.Codigo;
			
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
				fflush(stdin);
				Menu_seleccion_Product ();
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
				do
				{	
					system("cls");
				    gotoxy(3,2);cout << "Introduce El Precio De Venta Del Producto: "; fflush(stdin);
			 		gets(dat.Precio);
					if (Venta(dat.Precio))
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
					system("cls");
				    gotoxy(3,2); cout << "Introduce La Cantidad Disponible Del Producto: "; fflush(stdin);
			 		gets(dat.Cantidad);
					if (Piezas(dat.Cantidad))
					{
						ban=true;
					}
					else
					{
						cout << "¡Dato Incorrecto!" << endl;
						ban=false;
					}
				}while (ban==false);

				dat.Reliminado = 0;
				fwrite(&dat,sizeof(dat),1,pf);
				fprintf(pf,"\r\n");
				
				ind_dat.Reliminado_Ind_Pro = 0;
				fwrite(&dat.Codigo,sizeof(ind_dat.Codigo_Ind_Pro),1,ind_pf);
				fwrite(&dat.Nombre_Producto,sizeof(ind_dat.Nombre_Producto_Ind_Pro),1,ind_pf);
				fwrite(&dat.Reliminado,sizeof(ind_dat.Reliminado_Ind_Pro),1,ind_pf);
				fprintf(ind_pf,"\r\n");		
				
				fclose(pf);
				fclose(ind_pf);
					
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
			return F2_Alta ();
			
			break;
			
			case 50:
				
			char codigos_usu [5];
		    int  cont_U;
			
			do
			{
				system("cls");
				Marco ();
				char CodigoR_usu [5] = "U00";
				
				if((log = fopen("Usuarios.dat","rb"))==NULL && (ind_log = fopen("Index_Usuarios.dat","rb"))==NULL)
				{
					log = fopen("Usuarios.dat","wb");
					ind_log = fopen("Index_Usuarios.dat","wb");
				}
			
				log = fopen("Usuarios.dat","ab+");
				ind_log = fopen("Index_Usuarios.dat","ab+");
				
				memset(&logi,0,sizeof(logi));
		
				cont_U=Contador_Usu ();	
				
				itoa(cont_U,codigos_usu,10);
				strcat(CodigoR_usu,codigos_usu);
				strcpy(logi.Codigo_log,CodigoR_usu);
				
				memset(&CodigoR_usu,0,sizeof(CodigoR_usu));
				
				gotoxy(3,3); cout << logi.Codigo_log;
				
			  	gotoxy(3,5);cout << "Alias Usuario: "; fflush(stdin);
			  	gets(logi.Nom_usuarios);
			
			    gotoxy(3,7);cout << "Contraseña: "; fflush(stdin);
			  	PassW (logi.Contra_usuarios,19);
			  	
			  	/*char c = '*';
			  	int posicion_actual=0;
			  	memset(&posicion_actual,0,sizeof(posicion_actual));
			  	posicion_actual=ftell(log);
 				cout << posicion_actual/86;
 				getch();
			  	fseek(log,posicion_actual-86,SEEK_SET);
			  	for (caracter = 0; caracter < sizeof(logi.Contra_usuarios); caracter ++)
				{
	 				fwrite(&c,sizeof(c),1,log);
				}*/
			  	
				logi.Reliminado_log = 0;
				fwrite(&logi,sizeof(logi),1,log);
				fprintf(log,"\r\n");
				
				ind_logi.Reliminado_log_Ind_Em = 0;
				fwrite(&logi.Codigo_log,sizeof(ind_logi.Codigo_log_Ind_Em),1,ind_log);
				fwrite(&logi.Nom_usuarios,sizeof(ind_logi.Nom_usuarios_Ind_Em),1,ind_log);
				fwrite(&logi.Reliminado_log,sizeof(ind_logi.Reliminado_log_Ind_Em),1,ind_log);
				fprintf(ind_log,"\r\n");
								
				fclose(log);
				fclose(ind_log);
				
				do
				{	
					system("cls");
					gotoxy(38,12); cout << "¿Deseas Agregar Otro Usuario? [S] / [N]";
					respuesta=getch();
					
					if(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' )
					{
						gotoxy(47,14); cout << "Introduce Una Opcion: ";
						getch();
					}
				}while(respuesta!= 'n' && respuesta!= 'N' && respuesta!= 's' && respuesta!= 'S' );
			}while(respuesta=='s' || respuesta=='S');
			return F2_Alta ();
		
			break;
			
			case 27:
			return Menu();
			break;
		}
	}while(op_F2!=49 && op_F2!=50 && op_F2!=51 && op_F2!=27);
}

int F3_Bajas ()
{
	char op_baja;
	
	system("cls");
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	gotoxy(45,11); cout << "[1] Eliminar Producto"; 
	gotoxy(45,13); cout << "[2] Eliminar Usuarios";
	gotoxy(45,15); cout << "[Esc] Salir";
	Setcolor(14);
	Marco ();
	gotoxy(45,17); cout << "INGRESE UNA OPCIÓN: ";
	ResetColor(7);
	
	do
	{
		fflush(stdin);
		op_baja = getch();
		
		switch(op_baja)
		{
			case 49:
			baja_pro ();
			break;

			case 50:				
			baja_usu ();	
			break;
			
			case 27:
			return Menu();
			break;
		}
	}while(op_baja!=49 && op_baja!=50 && op_baja!=27);
	
}

int F4_Edicion ()
{
	char op;
	
	system("cls");
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	gotoxy(45,11); cout << "[1] Editar Productos"; 
	gotoxy(45,13); cout << "[2] Editar Usuarios";
	gotoxy(45,15); cout << "[Esc] Salir";
	Setcolor(14);
	Marco ();
	gotoxy(45,17); cout << "INGRESE UNA OPCIÓN: ";
	ResetColor(7);
	
	do
	{
		fflush(stdin);
		op = getch();
		
		switch(op)
		{
			case 49:
			edicion_pro ();
			break;
			
			case 50:
			edicion_usu ();
			break;
			
			case 27:
			return Menu();
			break;
		}
	}while(op!=49 && op!=50 && op!=51 && op!=27);
 	
}

int F5_Consultas()
{
	char op;
	char code [5];
	int codi = 0, posicion_pro = 0, posicion_usu = 0;
	
	system("cls");
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	gotoxy(45,11); cout << "[1] Consultar Inventario General"; 
	gotoxy(45,13); cout << "[2] Consultar Productos";
	gotoxy(45,15); cout << "[3] Consultar Usuarios";
	gotoxy(45,17); cout << "[Esc] Salir";
	Setcolor(14);
	Marco ();
	gotoxy(45,19); cout << "INGRESE UNA OPCIÓN: ";
	ResetColor(7);
	
	do
	{
		fflush(stdin);
		op = getch();
		
		switch(op)
		{
			case 49:
				
			system("cls");
			if((pf = fopen("Inventario.dat","rb")) == NULL)
			{
				system("color C");
				gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
				getch();
				return F5_Consultas();
			}
			
			gotoxy(3,2); cout << "Inventario Productos:";
			mostrar_inventario ();
			getch();
			
			system("cls");
			if((log = fopen("Usuarios.dat","rb")) == NULL)
			{
				system("color C");
				gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
				getch();
				return F5_Consultas();
			}
			
			gotoxy(3,2); cout << "Usuarios Registrados:";
			mostrar_inventario_2 ();
			getch();
			
			fclose(pf);
			fclose(log);
	
			return F5_Consultas();
			
			break;
			
			case 50:
				
			if((pf = fopen("Inventario.dat","rb")) == NULL || (ind_pf = fopen("Index_Inventario.dat","rb"))==NULL)
			{
				system("color C");
				gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
				exit(0);
				getch();
			}
			
			
			system("cls");
			/*char x;
			mostrar_inventario ();*/
			Marco ();
		    fseek(ind_pf,0,SEEK_SET);
	
            gotoxy(3,2); cout << "Introduce El Nombre Del Producto a Consultar: "; fflush(stdin);		  
            gets(buscar);
			
			do
			{
				char x;
				memset(&dat,0,sizeof(dat));
				memset(&ind_dat,0,sizeof(ind_dat));
				memset(&code,0,sizeof(code));
		        
		        fread(&ind_dat,34,1,ind_pf);
		       
          	 	for(int i=0; i <2; i++)
				{
					caracter=fgetc(ind_pf);
				}
				
          	 	if(!strcmpi(buscar,ind_dat.Nombre_Producto_Ind_Pro) && !feof(ind_pf))
          	 	{
          	 		strcpy(code,ind_dat.Codigo_Ind_Pro + 1);
					codi = atoi(code);
					posicion_pro = (codi)*46;
					fseek(pf,posicion_pro-46,SEEK_SET);	
		        
		        	fread(&dat,sizeof(dat),1,pf);
		        	if (dat.Reliminado == 1)
					{
						break;
					}
					system("cls");
					Marco ();
					gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
		   		 	Show_Inventario ();
					x=x+2;
					gotoxy(20,x+5); cout << dat.Codigo;
					gotoxy(40,x+5); cout << dat.Nombre_Producto;
					gotoxy(65,x+5); cout << dat.Cantidad;
					gotoxy(85,x+5); cout << "$" << dat.Precio;
					getch();
          	
	     		 }	
		   }while(caracter!=EOF);
            
            fclose(pf);
			fclose(ind_pf);
			
			return F5_Consultas();
		
			break;
			
			case 51:
		
			if((log = fopen("Usuarios.dat","rb")) == NULL || (ind_log = fopen("Index_Usuarios.dat","rb"))==NULL)
			{
				system("color C");
				system("cls");
				gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
				exit(0);
				getch();
			}
				
			
			system("cls");
			/*char j;
			mostrar_inventario_2 ();*/
			Marco ();
		    fseek(log,0,SEEK_SET);
		    
            gotoxy(3,2); cout << "Introduce El Nombre Del Usuario a Editar: "; fflush(stdin);		  
            gets(buscar);
			
			do
			{
		        char j;
				memset(&logi,0,sizeof(logi));
				memset(&code,0,sizeof(code));
		        
		        fread(&logi,sizeof(logi),1,log);
		        
		        for(int i=0; i < 2; i++)
				{
					caracter=fgetc(log);
				}
				
          	 	if(!strcmpi(buscar,logi.Nom_usuarios) && !feof(log))
          	 	{
          	 		strcpy(code,logi.Codigo_log + 1);
					codi = atoi(code);
					posicion_usu = (codi)*54;
					fseek(log,posicion_usu-54,SEEK_SET);	
		        
		        	fread(&logi,sizeof(logi),1,log);
		        	if (logi.Reliminado_log == 1)
					{
						break;
					}
					system("cls");
					Marco ();
					gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
		   		 	Show_Usu ();
		   		 	j=j+2;
					gotoxy(30,j+5); cout << logi.Codigo_log;
					gotoxy(55,j+5); cout << logi.Nom_usuarios;
					gotoxy(80,j+5); cout << logi.Contra_usuarios;
					getch();
	     		 }
			   	
		   }while(caracter!=EOF);
            
            fclose(log);
			fclose(ind_log);
			
			return F5_Consultas();
		
			break;
			
			case 27:
			return Menu();
			break;
		}
	}while(op!=49 && op!=50 && op!=51 && op!=27);
}

int F6_Reportes ()
{
	char op;
	char code [5];
	int codi = 0, posicion_pro = 0, posicion_usu = 0;
	
	system("cls");
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	gotoxy(45,11); cout << "[1] Faltantes"; 
	gotoxy(45,13); cout << "[2] Perdidas";
	gotoxy(45,15); cout << "[3] Ventas Registradas";
	gotoxy(45,17); cout << "[Esc] Salir";
	Setcolor(14);
	Marco ();
	gotoxy(45,19); cout << "INGRESE UNA OPCIÓN: ";
	ResetColor(7);
	
	do
	{
		fflush(stdin);
		op = getch();
		
		switch(op)
		{
			case 49:
				
	
			break;
			
			case 50:
				
			
			break;
			
			case 51:
				
			system("cls");
			if((ven = fopen("Ventas.dat","rb")) == NULL)
			{
				system("color C");
				gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
				getch();
				return F6_Reportes();
			}
			
			gotoxy(3,2); cout << "Productos Vendidos:";
			mostrar_inventario_ventas ();
			getch();
			
			fclose(ven);
	
			return F6_Reportes();
		
			break;
			
			case 27:
			return Menu();
			break;
		}
	}while(op!=49 && op!=50 && op!=51 && op!=27);
	
}

int F7_Papelera ()
{
	char op;
	char code [5];
	int codi = 0, posicion_pro = 0, posicion_usu = 0;
	
	system("cls");
	setlocale(LC_CTYPE, "Spanish");
	Setcolor(7);			
	gotoxy(45,11); cout << "[1] Restaurar Productos"; 
	gotoxy(45,13); cout << "[2] Restaurar Usuarios";
	gotoxy(45,15); cout << "[3] Restaurar Todo";
	gotoxy(45,17); cout << "[Esc] Salir";
	Setcolor(14);
	Marco ();
	gotoxy(45,19); cout << "INGRESE UNA OPCIÓN: ";
	ResetColor(7);
	
	do
	{
		fflush(stdin);
		op = getch();
		
		switch(op)
		{
			case 49:
			
			do
			{
				
				if((pf = fopen("Inventario.dat","rb+")) == NULL || (ind_pf = fopen("Index_Inventario.dat","rb+"))==NULL)
				{
					system("color C");
					gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
					exit(0);
					getch();
				}
			
				char x;
				system("cls");
				mostrar_inventario_pape ();
				Marco ();			
			    fseek(ind_pf,0,SEEK_SET);
	
	            gotoxy(3,2); cout << "Introduce El Codigo Del Producto a Consultar y Restaurar: "; fflush(stdin);		  
	            gets(buscar);
				
				do
				{
	                respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
					char x;
					memset(&dat,0,sizeof(dat));
					memset(&ind_dat,0,sizeof(ind_dat));
					memset(&code,0,sizeof(code));
			        
			        fread(&ind_dat,34,1,ind_pf);
			       
	          	 	for(int i=0; i <2; i++)
					{
						caracter=fgetc(ind_pf);
					}
					
	          	 	if(!strcmpi(buscar,ind_dat.Codigo_Ind_Pro))
	          	 	{
	          	 		strcpy(code,ind_dat.Codigo_Ind_Pro + 1);
						codi = atoi(code);
						posicion_pro = (codi)*46;
						fseek(pf,posicion_pro-46,SEEK_SET);	
			        
			        	fread(&dat,sizeof(dat),1,pf);
			        	if (dat.Reliminado == 0)
						{
							break;
						}
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION RECUPERAR REGISTROS! ______________________________________________" << endl;
			   		 	Show_Inventario ();
						x=x+2;
						gotoxy(20,x+5); cout << dat.Codigo;
						gotoxy(40,x+5); cout << dat.Nombre_Producto;
						gotoxy(65,x+5); cout << dat.Cantidad;
						gotoxy(85,x+5); cout << "$" << dat.Precio;
	          	
				  		do
						{
							gotoxy(36,13); cout << "¿Este es el Registro que Quieres Restaurar [S] / [N]";
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
						posicion_pro=0;
			
						codi=0;
						strcpy(code,dat.Codigo + 1);
						codi = atoi(code);
						posicion_pro = codi*36;
						
						fseek(ind_pf,posicion_pro-36,SEEK_SET);
						fread(&ind_dat,sizeof(ind_dat),1,ind_pf);
					
						dat.Reliminado = 0;
						ind_dat.Reliminado_Ind_Pro = 0;
			
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION RECUPERAR REGISTROS! ______________________________________________" << endl;
						gotoxy(44,14); cout << "¡Registro Recuperado con exito!";
						
						fseek(ind_pf,-36,SEEK_CUR);
						fwrite(&dat.Codigo,sizeof(ind_dat.Codigo_Ind_Pro),1,ind_pf);
						fwrite(&dat.Nombre_Producto,sizeof(ind_dat.Nombre_Producto_Ind_Pro),1,ind_pf);
						fwrite(&dat.Reliminado,sizeof(ind_dat.Reliminado_Ind_Pro),1,ind_pf);
						fseek(ind_pf,36,SEEK_CUR);
						
						fseek(pf,-44,SEEK_CUR);
						fwrite(&dat,sizeof(dat),1,pf);
						fseek(pf,44,SEEK_CUR);
						
					}	
			   }while(!feof(ind_pf));
	            
				
				do
				{
					system("cls");
					Marco ();
					gotoxy(0,1);cout << "____________________________________________ ¡FUNCION RECUPERAR REGISTROS! ______________________________________________" << endl;
					gotoxy(38,14); cout << "¿Deseas Seguir Restaurando Registros? [S] / [N]";
					respuesta2=getch();
			
					if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
					{
						gotoxy(47,16); cout << "Introduce una opcion: ";
						getch();
					}
				}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
			
			}while(respuesta2 == 's' || respuesta2 == 'S');
			
			return F7_Papelera ();
				
			break;
			
			case 50:
			
			do
			{
				
				if((log = fopen("Usuarios.dat","rb+")) == NULL || (ind_log = fopen("Index_Usuarios.dat","rb+"))==NULL)
				{
					system("color C");
					gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
					exit(0);
					getch();
				}
			
				char j;
				system("cls");
				mostrar_inventario_2_pape ();
				Marco ();
			    fseek(log,0,SEEK_SET);
			    
	            gotoxy(3,2); cout << "Introduce El Codigo Del Usuario a Recuperar: "; fflush(stdin);		  
	            gets(buscar);
				
				do
				{
	                respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
		
			        char j;
					memset(&logi,0,sizeof(logi));
					memset(&code,0,sizeof(code));
			        
			        fread(&logi,sizeof(logi),1,log);
			        
			        for(int i=0; i < 2; i++)
					{
						caracter=fgetc(log);
					}
					
	          	 	if(!strcmpi(buscar,logi.Codigo_log) && !feof(log))
	          	 	{
	          	 		strcpy(code,logi.Codigo_log + 1);
						codi = atoi(code);
						posicion_usu = (codi)*54;
						fseek(log,posicion_usu-54,SEEK_SET);	
			        
			        	fread(&logi,sizeof(logi),1,log);
			        	if (logi.Reliminado_log == 0)
						{
							break;
						}
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION RECUPERAR REGISTROS! ______________________________________________" << endl;
			   		 	Show_Usu ();
			   		 	j=j+2;
						gotoxy(30,j+5); cout << logi.Codigo_log;
						gotoxy(55,j+5); cout << logi.Nom_usuarios;
						gotoxy(80,j+5); cout << logi.Contra_usuarios;
	          	
				  		do
						{
							gotoxy(36,13); cout << "¿Este es el Registro que Quieres Restaurar [S] / [N]";
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
							posicion_usu = 0;
							codi = 0;
						
							memset(code,0,sizeof(code));
							
							strcpy(code,logi.Codigo_log + 1);
							codi = atoi(code);
							
							posicion_usu = codi*31;
							fseek(ind_log,posicion_usu-31,SEEK_SET);
							fread(&ind_logi,31,1,ind_log);
			              	 		
							logi.Reliminado_log = 0;
							ind_logi.Reliminado_log_Ind_Em = 0;
				
							system("cls");
							Marco ();
							gotoxy(0,1);cout << "____________________________________________ ¡FUNCION RECUPERAR REGISTROS! ______________________________________________" << endl;
							gotoxy(44,14); cout << "¡Registro recuperado con exito!";
							
							fseek(ind_log,-31,SEEK_CUR);
							fwrite(&logi.Codigo_log,sizeof(ind_logi.Codigo_log_Ind_Em),1,ind_log);
							fwrite(&logi.Nom_usuarios,sizeof(ind_logi.Nom_usuarios_Ind_Em),1,ind_log);
							fwrite(&logi.Reliminado_log,sizeof(ind_logi.Reliminado_log_Ind_Em),1,ind_log);
							fseek(ind_log,31,SEEK_CUR);
							
							fseek(log,-52,SEEK_CUR);
							fwrite(&logi,sizeof(logi),1,log);
							fseek(log,52,SEEK_CUR);
							
						}	
			   }while(caracter!=EOF);
	
				do
				{
					system("cls");
					gotoxy(0,1);cout << "____________________________________________ ¡FUNCION RECUPERAR REGISTROS! ______________________________________________" << endl;
					gotoxy(38,14); cout << "¿Deseas Seguir Restaurando Registros? [S] / [N]";
					respuesta2=getch();
			
					if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
					{
						gotoxy(47,16); cout << "Introduce una opcion: ";
						getch();
					}
				}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
			
			}while(respuesta2 == 's' || respuesta2 == 'S');
			
			return F7_Papelera ();
				
			break;
			
			case 51:
				
			if((pf = fopen("Inventario.dat","rb+")) == NULL || (ind_pf = fopen("Index_Inventario.dat","rb+"))==NULL || (log = fopen("Usuarios.dat","rb+")) == NULL || (ind_log = fopen("Index_Usuarios.dat","rb+"))==NULL)
			{
				system("color C");
				gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
				exit(0);
				getch();
			}
			
			fseek(ind_pf,0,SEEK_SET);
				
			do
			{
				memset(&dat,0,sizeof(dat));
				memset(&ind_dat,0,sizeof(ind_dat));
				memset(&code,0,sizeof(code));
		        
		        fread(&ind_dat,34,1,ind_pf);
		       
          	 	for(int i=0; i <2; i++)
				{
					caracter=fgetc(ind_pf);
				}
		    
				if(!feof(ind_pf) && ind_dat.Reliminado_Ind_Pro == 1 || ind_dat.Reliminado_Ind_Pro == 0 )
				{
					strcpy(code,ind_dat.Codigo_Ind_Pro + 1);
					codi = atoi(code);
					posicion_pro = (codi)*46;
					fseek(pf,posicion_pro-46,SEEK_SET);	
		        
		        	fread(&dat,sizeof(dat),1,pf);
		        }
		        
			}while(caracter!=EOF);
			
			dat.Reliminado = 0;
			ind_dat.Reliminado_Ind_Pro = 0;
			
			fseek(pf,-44,SEEK_CUR);
			fwrite(&dat,sizeof(dat),1,pf);
			fseek(pf,44,SEEK_CUR);
			
			fseek(ind_pf,-36,SEEK_CUR);
			fwrite(&dat.Codigo,sizeof(ind_dat.Codigo_Ind_Pro),1,ind_pf);
			fwrite(&dat.Nombre_Producto,sizeof(ind_dat.Nombre_Producto_Ind_Pro),1,ind_pf);
			fwrite(&dat.Reliminado,sizeof(ind_dat.Reliminado_Ind_Pro),1,ind_pf);
			fseek(ind_pf,36,SEEK_CUR);
	
			
			fseek(log,0,SEEK_SET);
			
			do
			{
				memset(&logi,0,sizeof(logi));
				memset(&code,0,sizeof(code));
		        
		        fread(&logi,sizeof(logi),1,log);
		        
		        for(int i=0; i < 2; i++)
				{
					caracter=fgetc(log);
				}
				
				if(!feof(log) && logi.Reliminado_log == 1 || logi.Reliminado_log == 0)
				{
					strcpy(code,logi.Codigo_log + 1);
					codi = atoi(code);
					posicion_usu = (codi)*54;
					fseek(log,posicion_usu-54,SEEK_SET);	
		        
		        	fread(&logi,sizeof(logi),1,log);
		        }
		       
			}while(caracter!=EOF);
			
			logi.Reliminado_log = 0;
			ind_logi.Reliminado_log_Ind_Em = 0;
			
			fseek(log,-52,SEEK_CUR);
			fwrite(&logi,sizeof(logi),1,log);
			fseek(log,52,SEEK_CUR);
			
			fseek(ind_log,-31,SEEK_CUR);
			fwrite(&logi.Codigo_log,sizeof(ind_logi.Codigo_log_Ind_Em),1,ind_log);
			fwrite(&logi.Nom_usuarios,sizeof(ind_logi.Nom_usuarios_Ind_Em),1,ind_log);
			fwrite(&logi.Reliminado_log,sizeof(ind_logi.Reliminado_log_Ind_Em),1,ind_log);
			fseek(ind_log,31,SEEK_CUR);
			
			system("cls");
			cout << "Registros Restaurados";
			getch();
			
			return F7_Papelera ();
			
			break;
			
			case 27:
			return Menu();
			break;
		}
	}while(op!=49 && op!=50 && op!=51 && op!=27);
	fclose(pf); fclose(ind_pf); fclose(log); fclose(ind_log);
}

void Show_Ventas ()
{
	gotoxy(20,5); cout << "Codigo";
	gotoxy(40,5); cout << "Producto";
	gotoxy(65,5); cout << "Cantidad";
	gotoxy(85,5); cout << "Costo";
}
void Show_Inventario ()
{
	gotoxy(20,5); cout << "Codigo";
	gotoxy(40,5); cout << "Producto";
	gotoxy(65,5); cout << "Cantidad";
	gotoxy(85,5); cout << "Precio";
}

void Show_Usu ()
{
	gotoxy(30,5); cout << "Codigo";
	gotoxy(55,5); cout << "Usuario";
	gotoxy(80,5); cout << "Contraseña";
}

void baja_pro ()
{
	do
	{
		char op;
		char code [5];
		int codi = 0, posicion_pro = 0;
		
		if((pf = fopen("Inventario.dat","rb+")) == NULL || (ind_pf = fopen("Index_Inventario.dat","rb+"))==NULL)
		{
			system("color C");
			gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
			exit(0);
			getch();
		}
		gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;		
		system("cls");
		cout << "\n\n[1] Por Nombre Producto";
		cout << "\n\nPreciona el Numero del Indice: ";
		
		do
		{
			fflush(stdin);
			op = getch();
			
			switch(op)
			{
				case 49:
					
				char x;
				system("cls");
				mostrar_inventario ();
				Marco ();			
			    fseek(ind_pf,0,SEEK_SET);
	
                gotoxy(3,2); cout << "Introduce El Codigo Del Producto a Consultar y Eliminar: "; fflush(stdin);		  
                gets(buscar);
				
				do
				{
                    respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
					char x;
					memset(&dat,0,sizeof(dat));
					memset(&ind_dat,0,sizeof(ind_dat));
					memset(&code,0,sizeof(code));
			        
			        fread(&ind_dat,34,1,ind_pf);
			       
              	 	for(int i=0; i <2; i++)
					{
						caracter=fgetc(ind_pf);
					}
					
              	 	if(!strcmpi(buscar,ind_dat.Codigo_Ind_Pro))
              	 	{
              	 		strcpy(code,ind_dat.Codigo_Ind_Pro + 1);
						codi = atoi(code);
						posicion_pro = (codi)*46;
						fseek(pf,posicion_pro-46,SEEK_SET);	
			        
			        	fread(&dat,sizeof(dat),1,pf);
			        	if (dat.Reliminado == 1)
						{
							break;
						}
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
			   		 	Show_Inventario ();
						x=x+2;
						gotoxy(20,x+5); cout << dat.Codigo;
						gotoxy(40,x+5); cout << dat.Nombre_Producto;
						gotoxy(65,x+5); cout << dat.Cantidad;
						gotoxy(85,x+5); cout << "$" << dat.Precio;
              	
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
						posicion_pro=0;
			
						codi=0;
						strcpy(code,dat.Codigo + 1);
						codi = atoi(code);
						posicion_pro = codi*36;
						
						fseek(ind_pf,posicion_pro-36,SEEK_SET);
						fread(&ind_dat,sizeof(ind_dat),1,ind_pf);
					
						dat.Reliminado = 1;
						ind_dat.Reliminado_Ind_Pro = 1;
			
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
						gotoxy(44,14); cout << "¡Registro Eliminado con exito!";
						
						fseek(ind_pf,-36,SEEK_CUR);
						fwrite(&dat.Codigo,sizeof(ind_dat.Codigo_Ind_Pro),1,ind_pf);
						fwrite(&dat.Nombre_Producto,sizeof(ind_dat.Nombre_Producto_Ind_Pro),1,ind_pf);
						fwrite(&dat.Reliminado,sizeof(ind_dat.Reliminado_Ind_Pro),1,ind_pf);
						fseek(ind_pf,36,SEEK_CUR);
						
						fseek(pf,-44,SEEK_CUR);
						fwrite(&dat,sizeof(dat),1,pf);
						fseek(pf,44,SEEK_CUR);
						
					}	
			   }while(!feof(ind_pf));
	            
	            fclose(pf);
				fclose(ind_pf);
		        break;	
			}	
			 	
		}while(op!=49);
		
		do
		{
			system("cls");
			Marco ();
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

void baja_usu ()
{
	do
	{
		char op;
		char code [5];
		int codi = 0, posicion_usu = 0;
		
		if((log = fopen("Usuarios.dat","rb+")) == NULL || (ind_log = fopen("Index_Usuarios.dat","rb+"))==NULL)
		{
			system("color C");
			gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
			exit(0);
			getch();
		}
		gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;		
		system("cls");
		cout << "\n\n[1] Por Nombre Usuario";
		cout << "\n\nPreciona el Numero del Indice: ";
		
		do
		{
			fflush(stdin);
			op = getch();
			
			switch(op)
			{
				case 49:
					
				char j;
				system("cls");
				mostrar_inventario_2 ();
				Marco ();
			    fseek(log,0,SEEK_SET);
			    
                gotoxy(3,2); cout << "Introduce El Codigo Del Usuario a Eliminar: "; fflush(stdin);		  
                gets(buscar);
				
				do
				{
                    respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
		
			        char j;
					memset(&logi,0,sizeof(logi));
					memset(&code,0,sizeof(code));
			        
			        fread(&logi,sizeof(logi),1,log);
			        
			        for(int i=0; i < 2; i++)
					{
						caracter=fgetc(log);
					}
					
              	 	if(!strcmpi(buscar,logi.Codigo_log) && !feof(log))
              	 	{
              	 		strcpy(code,logi.Codigo_log + 1);
						codi = atoi(code);
						posicion_usu = (codi)*54;
						fseek(log,posicion_usu-54,SEEK_SET);	
			        
			        	fread(&logi,sizeof(logi),1,log);
			        	if (logi.Reliminado_log == 1)
						{
							break;
						}
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
			   		 	Show_Usu ();
			   		 	j=j+2;
						gotoxy(30,j+5); cout << logi.Codigo_log;
						gotoxy(55,j+5); cout << logi.Nom_usuarios;
						gotoxy(80,j+5); cout << logi.Contra_usuarios;
              	
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
						posicion_usu = 0;
						codi = 0;
					
						memset(code,0,sizeof(code));
						
						strcpy(code,logi.Codigo_log + 1);
						codi = atoi(code);
						
						posicion_usu = codi*31;
						fseek(ind_log,posicion_usu-31,SEEK_SET);
						fread(&ind_logi,31,1,ind_log);
		              	 		
						logi.Reliminado_log = 1;
						ind_logi.Reliminado_log_Ind_Em = 1;
			
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
						gotoxy(44,14); cout << "¡Registro Eliminado con exito!";
						
						fseek(ind_log,-31,SEEK_CUR);
						fwrite(&logi.Codigo_log,sizeof(ind_logi.Codigo_log_Ind_Em),1,ind_log);
						fwrite(&logi.Nom_usuarios,sizeof(ind_logi.Nom_usuarios_Ind_Em),1,ind_log);
						fwrite(&logi.Reliminado_log,sizeof(ind_logi.Reliminado_log_Ind_Em),1,ind_log);
						fseek(ind_log,31,SEEK_CUR);
						
						fseek(log,-52,SEEK_CUR);
						fwrite(&logi,sizeof(logi),1,log);
						fseek(log,52,SEEK_CUR);
						
					}	
			   }while(caracter!=EOF);
	            
	            fclose(log);
				fclose(ind_log);
		        break;	
			}	
			 	
		}while(op!=49);
		
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

void edicion_pro ()
{
	do
	{
		char op;
		char code [5];
		int codi = 0, posicion_pro = 0;
		
		if((pf = fopen("Inventario.dat","rb+")) == NULL || (ind_pf = fopen("Index_Inventario.dat","rb+"))==NULL)
		{
			system("color C");
			gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
			exit(0);
			getch();
		}
		gotoxy(0,1);cout << "____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;		
		system("cls");
		cout << "\n\n[1] Por Nombre Producto";
		cout << "\n\nPreciona el Numero del Indice: ";
		
		do
		{
			fflush(stdin);
			op = getch();
			
			switch(op)
			{
				case 49:
				
				char x;
				system("cls");
				mostrar_inventario ();
				Marco ();
			    fseek(ind_pf,0,SEEK_SET);
		
                gotoxy(3,2); cout << "Introduce El Codigo Del Producto a Consultar y Editar: "; fflush(stdin);		  
                gets(buscar);
				
				do
				{
                    respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
					char x;
					memset(&dat,0,sizeof(dat));
					memset(&ind_dat,0,sizeof(ind_dat));
					memset(&code,0,sizeof(code));
			        
			        fread(&ind_dat,34,1,ind_pf);
			       
              	 	for(int i=0; i <2; i++)
					{
						caracter=fgetc(ind_pf);
					}
					
              	 	if(!strcmpi(buscar,ind_dat.Codigo_Ind_Pro))
              	 	{
              	 		strcpy(code,ind_dat.Codigo_Ind_Pro + 1);
						codi = atoi(code);
						posicion_pro = (codi)*46;
						fseek(pf,posicion_pro-46,SEEK_SET);	
			        
			        	fread(&dat,sizeof(dat),1,pf);
			        	if (dat.Reliminado == 1)
						{
							break;
						}
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
			   		 	Show_Inventario ();
						x=x+2;
						gotoxy(20,x+5); cout << dat.Codigo;
						gotoxy(40,x+5); cout << dat.Nombre_Producto;
						gotoxy(65,x+5); cout << dat.Cantidad;
						gotoxy(85,x+5); cout << "$" << dat.Precio;
              	
				  		do
						{
							gotoxy(36,13); cout << "¿Este es el Registro que Quieres Editar [S] / [N]";
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
						posicion_pro=0;
			
						codi=0;
						strcpy(code,dat.Codigo + 1);
						codi = atoi(code);
						posicion_pro = codi*36;
						
						fseek(ind_pf,posicion_pro-36,SEEK_SET);
						fread(&ind_dat,sizeof(ind_dat),1,ind_pf);
						
						Seek ();
						
						fseek(pf,-44,SEEK_CUR);
						fwrite(&dat,sizeof(dat),1,pf);
						fseek(pf,44,SEEK_CUR);
						
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
						gotoxy(44,14); cout << "¡Registro Modificado con exito!";
					
					}	
			   }while(!feof(ind_pf));
	            
	            fclose(pf);
				fclose(ind_pf);
		        break;	
			}	
			 	
		}while(op!=49);
		
		do
		{
			system("cls");
			Marco ();
			gotoxy(0,1);cout << "____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(38,14); cout << "¿Deseas Seguir Modificando Registros? [S] / [N]";
			respuesta2=getch();
	
			if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
			{
				gotoxy(47,16); cout << "Introduce una opcion: ";
				getch();
			}
		}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
	
	}while(respuesta2 == 's' || respuesta2 == 'S');
}

void edicion_usu ()
{
	do
	{
		char op;
		char code [5];
		int codi = 0, posicion_usu = 0;
		
		if((log = fopen("Usuarios.dat","rb+")) == NULL || (ind_log = fopen("Index_Usuarios.dat","rb+"))==NULL)
		{
			system("color C");
			system("cls");
			gotoxy(40,14); cout << "¡No se Encontro el Archivo Para la Lectura!";
			exit(0);
			getch();
		}
		gotoxy(0,1);cout << "____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;		
		system("cls");
		cout << "\n\n[1] Por Nombre Usuario";
		cout << "\n\nPreciona el Numero del Indice: ";
		
		do
		{
			fflush(stdin);
			op = getch();
			
			switch(op)
			{
				case 49:
					
				char j;
				system("cls");
				mostrar_inventario_2 ();
				Marco ();
			    fseek(log,0,SEEK_SET);
			    
                gotoxy(3,2); cout << "Introduce El Codigo Del Usuario a Editar: "; fflush(stdin);		  
                gets(buscar);
				
				do
				{
                    respuesta  = 'n';
					respuesta2 = 'n';
					respuesta3 = 'n';
		
			        char j;
					memset(&logi,0,sizeof(logi));
					memset(&code,0,sizeof(code));
			        
			        fread(&logi,sizeof(logi),1,log);
			        
			        for(int i=0; i < 2; i++)
					{
						caracter=fgetc(log);
					}
					
              	 	if(!strcmpi(buscar,logi.Codigo_log) && !feof(log))
              	 	{
              	 		strcpy(code,logi.Codigo_log + 1);
						codi = atoi(code);
						posicion_usu = (codi)*54;
						fseek(log,posicion_usu-54,SEEK_SET);	
			        
			        	fread(&logi,sizeof(logi),1,log);
			        	if (logi.Reliminado_log == 1)
						{
							break;
						}
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION ELIMINAR REGISTROS! ______________________________________________" << endl;
			   		 	Show_Usu ();
			   		 	j=j+2;
						gotoxy(30,j+5); cout << logi.Codigo_log;
						gotoxy(55,j+5); cout << logi.Nom_usuarios;
						gotoxy(80,j+5); cout << logi.Contra_usuarios;
              	
				  		do
						{
							gotoxy(36,13); cout << "¿Este es el Registro que Quieres Editar [S] / [N]";
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
						posicion_usu = 0;
						codi = 0;
					
						memset(code,0,sizeof(code));
						
						strcpy(code,logi.Codigo_log + 1);
						codi = atoi(code);
						
						posicion_usu = codi*31;
						fseek(ind_log,posicion_usu-31,SEEK_SET);
						fread(&ind_logi,31,1,ind_log);
						
						Seek_Usu ();
						
						fseek(log,-52,SEEK_CUR);
						fwrite(&logi,sizeof(logi),1,log);
						fseek(log,52,SEEK_CUR);
						
						system("cls");
						Marco ();
						gotoxy(0,1);cout << "____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
						gotoxy(44,14); cout << "¡Registro Modificado con exito!";
						
					}	
			   }while(caracter!=EOF);
	            
	            fclose(log);
				fclose(ind_log);
		        break;	
			}	
			 	
		}while(op!=49);
		
		do
		{
			system("cls");
			Marco ();
			gotoxy(0,1);cout << "____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(38,14); cout << "¿Deseas Seguir Modificando Registros? [S] / [N]";
			respuesta2=getch();
	
			if(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' )
			{
				gotoxy(47,16); cout << "Introduce una opcion: ";
				getch();
			}
		}while(respuesta2!= 'n' && respuesta2!= 'N' && respuesta2!= 's' && respuesta2!= 'S' );
	
	}while(respuesta2 == 's' || respuesta2 == 'S');
}

void Seek ()
{
	char op;
					
	cout << "\n\n\n[1] Editar Nombre Del Producto" << "\n[2] Editar Precio Del Producto" << "\n[3] Editar Cantidad Del Producto";
	cout << "\n\nPreciona el Numero de la Opcion Que Deseas Editar: ";
	
	do
	{
		fflush(stdin);
		op = getch();
		
		switch(op)
		{
			case 49:
			
			memset(ind_dat.Nombre_Producto_Ind_Pro,0,sizeof(ind_dat.Nombre_Producto_Ind_Pro));
		 	memset(&dat.Nombre_Producto,0,sizeof(dat.Nombre_Producto));
		 	system("cls");
		 	char op2;
			setlocale(LC_CTYPE, "Spanish");
			Setcolor(7);			
			gotoxy(45,11); cout << "[1] Pizzas Por Tamaños Y Calzone "; 
			gotoxy(45,13); cout << "[2] Bebidas ";
			gotoxy(45,15); cout << "[3] Combos ";
			gotoxy(45,17); cout << "[Esc] Salir";
			Setcolor(14); 
			gotoxy(45,19); cout << "Ingresa Una Opción: ";
			ResetColor(7);
			
			do
			{
				fflush(stdin);
				op2 = getch(); 
				
				switch(op2)
				{
					case 49:
					system("cls"); Productos_Pizza_Calzone (); break;
					case 50:
					system("cls"); Productos_Bebidas (); break;
					case 51:
					system("cls"); Productos_Combo (); break;
				}
			}while(op2!=49 && op2!=50 && op2!=51);
			
			strcpy(ind_dat.Nombre_Producto_Ind_Pro,dat.Nombre_Producto);
		    fseek(ind_pf,-36,SEEK_CUR);
			fwrite(&dat.Codigo,sizeof(ind_dat.Codigo_Ind_Pro),1,ind_pf);
			fwrite(&dat.Nombre_Producto,sizeof(ind_dat.Nombre_Producto_Ind_Pro),1,ind_pf);
			fwrite(&dat.Reliminado,sizeof(ind_dat.Reliminado_Ind_Pro),1,ind_pf);
			fseek(ind_pf,36,SEEK_CUR);
			
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();

			break;
			
			case 50:
						
			do
			{	
				memset(&dat.Precio,0,sizeof(dat.Precio));
				system("cls");
			    gotoxy(3,2);cout << "Introduce El Precio De Venta Del Producto: "; fflush(stdin);
		 		gets(dat.Precio);
				if (Venta(dat.Precio))
				{
					ban=true;
				}
				else
				{
					cout << "¡Dato Incorrecto!" << endl;
					ban=false;
				}
			}while (ban==false);
					
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();
	
			break;
			
			case 51:
				
			do
			{	
				memset(&dat.Cantidad,0,sizeof(dat.Cantidad));
				system("cls");
			    gotoxy(3,3); cout << "Introduce La Cantidad Disponible Del Producto: "; fflush(stdin);
		 		gets(dat.Cantidad);
				if (Piezas(dat.Cantidad))
				{
					ban=true;
				}
				else
				{
					cout << "¡Dato Incorrecto!" << endl;
					ban=false;
				}
			}while (ban==false);
				
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();
		 	
		 	break;
		}
		
	}while(op!=49 && op!=50 && op!=51);
}

void Seek_Usu ()
{
	char op;
					
	cout << "\n\n\n[1] Editar Nombre Del Usuario" << "\n[2] Editar Contraseña Del Usuario";
	cout << "\n\nPreciona el Numero de la Opcion Que Deseas Editar: ";
	
	do
	{
		fflush(stdin);
		op = getch();
		
		switch(op)
		{
			case 49:
			
			memset(ind_logi.Nom_usuarios_Ind_Em,0,sizeof(ind_logi.Nom_usuarios_Ind_Em));
			memset(&logi.Nom_usuarios,0,sizeof(logi.Nom_usuarios));
				
		  	gotoxy(3,5);cout << "Nombre Usuario: "; fflush(stdin);
		  	gets(logi.Nom_usuarios);
			
			strcpy(ind_logi.Nom_usuarios_Ind_Em,logi.Nom_usuarios);
		    fseek(ind_log,-31,SEEK_CUR);
			fwrite(&logi.Codigo_log,sizeof(ind_dat.Codigo_Ind_Pro),1,ind_log);
			fwrite(&logi.Nom_usuarios,sizeof(ind_logi.Nom_usuarios_Ind_Em),1,ind_log);
			fwrite(&logi.Reliminado_log,sizeof(ind_logi.Reliminado_log_Ind_Em),1,ind_log);
			fseek(ind_log,31,SEEK_CUR);
			
			system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();

			break;
			
			case 50:
			
			memset(&logi.Contra_usuarios,0,sizeof(logi.Contra_usuarios));				
		    gotoxy(3,7);cout << "Contraseña: "; fflush(stdin);
		  	PassW (logi.Contra_usuarios,19);
		  	
		  	system("cls");
			gotoxy(0,1);cout << "_____________________________________________ ¡FUNCION EDITAR REGISTROS! ______________________________________________" << endl;
			gotoxy(44,14); cout << "¡Registro Modificado Con Exito!";
			getch();
		  	
		  	break;
		}
		
	}while(op!=49 && op!=50);
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
