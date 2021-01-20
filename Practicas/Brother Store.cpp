/************* DECLARACIqerwiuPOÓN DE LIBRERIAS **************/
# include <iostream>
# include <windows.h>
# include <conio.h>
#include <string.h>
# include <locale.h>
# include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#define Color_Red 12
#define Color_Def 15
#define Color_Yellow 11
#define Delay_us 0

using namespace std;

/**************** VARIABLES GLOBALES *****************/
char c2[5]="C00",codigo2[3],cristal[20]="Mica de cristal.",tpu[20]="Protector silicon.",cargador[20]="Cargador.",memoria[20]="Memoria.",otro[20]="Otro.",cable[20]="Cable USB.",audifono[20]="Audifono.",cable2[20]="Cable de Video.",adaptador[20]="Adaptador.",holder[20]="Holder para Coche.",sim[20]="Sim.",bateria[20]="Bateria.";
char c='\0',c3='\0',samsung[10]="SAMSUNG.",motorola[10]="MOTOROLA.",lg[10]="LG.",iphone[10]="IPHONE.",sony[10]="SONY.",alcatel[10]="ALCATEL.",huawei[10]="HUAWEI.",htc[10]="HTC.",zte[10]="ZTE.",otrom[10]="OTRO.",lanix[10]="LANIX.",m4[10]="M4.",nokia[10]="NOKIA.",hisense[10]="HISENSE.",kingston[10]="KINGSTON.";
char caracter='\0',nom_archivo[100];
char user[50],pass[50],pre[7];
int reg=0,adm=0,con=0,o=44,t=10,esc=0,contador=0,tam=0,cod=0,dia=0;
/************ DECLARACIÓN (Prototipos) DE FUNCIONES ***************/
char menu (void);
char menuus (void);
void gotoxy(int,int);
void abrir();
void ingresar();
void alta_user();
void add_articulo();
void elim_user();
void modificar_articulo();
void modificar_usuario();
void mostrar_mermas();
void mostrar();
void buscar();
void eliminar();
void venta();
void papelera();
void mermas();
void faltantes();
void recarga();
void contra(char *con);
void edit(void);
FILE *pf;
FILE *pf2;
FILE *pm;
FILE *pc;
FILE *pv;
FILE *pa;
struct com
{
	char nombre[50];
	char passwo[15];
	int ban;
	int eliminado;	
}usuario;
struct art
{
	char codigo[5];
	char nom[50];
	char marca[15];
	char categoria [20];
	int precio;
	int cantidad;
	int eliminado;
}articulo;
struct arti
{
	char codigo[5];
	char nom[50];
	char marca[15];
	char categoria [20];
	int precio;
	int cantidad;
	int eliminado;
}articulo2;
struct mar
{
	char codigo[5];
	char marca [20];
	int ban;
}marcai;
struct cat
{
	char codigo[5];
	char categoria [20];
	int ban;
}categoriai;
int tamreg=0,numreg=0,taminm=0,taminc=0;

/////////INICIO DE MAIN//////////////////////////////////////////////////////////////////////
int main ()
{   // INICIO DEL MAIN
	setlocale(LC_ALL,"spanish");
	system("color B");
	//DECLARACIÓN DE VARIABLES
	char opc;
	abrir();
	ingresar();		
	do 
	{ //Do principal- contiene la estructura general del programa
		if(adm==1)
		{
		opc= menu();
		switch (opc){
			char o;
			
			case 59: //F1
				
			 	system("cls");
			 	venta();
				break;
				
			case 60://F2
				do
				{
					system("cls");
					fflush (stdin);
					gotoxy(28,5); cout<<"1.-Agregar un Articulo.";
					gotoxy(28,6); cout<<"2.-Dar de Alta un Usuario";
					gotoxy(28,7); cout<<"3.-Abonar (Recargas).";
					gotoxy(28,8); cout<<"ESC.-Salir.";
					gotoxy(28,10);cout<<"Seleccione una opcion: ";
					c=getch();
				}while(c!='1'&&c!='2'&&c!='3'&&c!=27);
				switch(c)
				{
					case 49:add_articulo();
							break;
					case 50:alta_user();
							break;
					case 51:recarga();
					case 27:menu();
							break;
				}
				break;
				
			case 61://F3
					do
					{
						system("cls");
						fflush (stdin);
						gotoxy(28,5); cout<<"1.-Modificar un Articulo.";
						gotoxy(28,6); cout<<"2.-Modificar un Usuario";
						gotoxy(28,7); cout<<"ESC.-Salir.";
						gotoxy(28,9); cout<<"Seleccione una opcion: ";
						c=getch();
					}while(c!='1'&&c!='2'&&c!=27);
					switch(c)
					{
						case 49:modificar_articulo();
								break;
						case 50:modificar_usuario();
								break;
						case 27:menu();
								break;
					}			
					break;
				
			case 62://F4
					system("cls");
			 		mostrar();
					break;
				
			case 63://F5
					system("cls");
			 		buscar();
					break;
				
			case 64://F6
					system("cls");
			 		eliminar();
					break;
				
			case 65://f7
					system("cls");
					faltantes();
					break;
					
			case 66://F8
					do
					{
						system("cls");
						fflush (stdin);
						gotoxy(28,5); cout<<"1.-Reportar Merma.";
						gotoxy(28,6); cout<<"2.-Mostrar Mermas.";
						gotoxy(28,7); cout<<"ESC.-Salir.";
						gotoxy(28,9); cout<<"Seleccione una opcion: ";
						c=getch();
					}while(c!='1'&&c!='2'&&c!=27);
					switch(c)
					{
						case 49:mermas();
								break;
						case 50:mostrar_mermas();
								break;
						case 27: menu();
								break;
					}
					break;
			case 67://F9
					system("cls");
					papelera();
					break;
			case 27://Esc.
				system("cls");
				gotoxy(32,21);cout<<"GRACIAS POR PASAR";
				
				break;
					
			default:
				
				if (opc !=27){
					Beep(500,1000);
				}
		
		}//Fin del Switch
		}
		else
		{
			opc= menuus();
			switch (opc)
			{
			char o;
			
			case 59: //F1
			 	system("cls");
			 	venta();
				break;
				
			case 60://F2
				system("cls");
				mostrar();
				break;
				
			case 61://F3
				
				system("cls");
			 	buscar();			
				break;
			
			case 27://Esc.
				system("cls");
				gotoxy(32,21);cout<<"GRACIAS POR PASAR";
				
				break;
			default:
				
				if (opc !=27){
					Beep(500,1000);
				}
		}
		}
			
		
	}while(opc !=27);

	return 0;	

}
//FIN DEL MAIN////////////////////////////////////////////////////////////////////////
/*****************     FUNCIONES     ****************/

//FUNCION MENU ++++++++++++++++++++++++++++++++++++++++++++++
char menu()
{	
	char opc1 = '\0'; //Declaracion de variable local para manejo de la opcion	
	system("color 09");
	system("cls");
	gotoxy(100,1);cout<<"Caja: "<<dia;
	gotoxy(33,3); cout<<"Menu Administrador";
	gotoxy(33,5); cout<<"[F1]  Vender Articulo.";
	gotoxy(33,6); cout<<"[F2]  Agregar Articulo/Usuario/Abonar.";
	gotoxy(33,7); cout<<"[F3]  Modificar Articulo/Usuario.";
	gotoxy(33,8); cout<<"[F4]  Mostrar Articulos.";
	gotoxy(33,9); cout<<"[F5]  Buscar articulo.";
	gotoxy(33,10);cout<<"[F6]  Eliminar articulo.";
	gotoxy(33,11);cout<<"[F7]  Mostrar Faltantes.";
	gotoxy(33,12);cout<<"[F8]  Mermas.";
	gotoxy(33,13);cout<<"[F9]  Papelera de Reciclaje.";
	gotoxy(33,14);cout<<"ESC.  Salir";
	gotoxy(36,16);cout<<"Seleccione una opcion: ";	
	
	//Captura de la opcion
	opc1 = getch();
	
	if (opc1==0){
		
		opc1 = getch();
	}
	
	return opc1;//Retornar la opcion ingresada
	
	
}
//////////////INICIA FUNCION MENU US*****************************************************888
char menuus()
{
	char opc1 = '\0'; //Declaracion de variable local para manejo de la opcion	
	system("cls");
	system("color 09");
	gotoxy(100,1);cout<<"Caja: "<<dia;
	gotoxy(40,2);cout<<"---------------------------";
	gotoxy(40,3);cout<<"        Menu Usuario";
	gotoxy(40,5);cout<<"  [F1] Vender articulo. ";
	gotoxy(40,6);cout<<"  [F2] Mostrar Articulos.";
	gotoxy(40,7);cout<<"  [F3] Buscar articulo.";
	gotoxy(40,8);cout<<"  ESC. Salir";
	gotoxy(40,9);cout<<"---------------------------";
	gotoxy(43,10);cout<<" Seleccione una opcion: ";	
	
	//Captura de la opcion
	opc1 = getch();
	
	if (opc1==0){
		
		opc1 = getch();
	}
	
	return opc1;//Retornar la opcion ingresada
}
//////////////////TERMINA FUNCON MENUUS***************************************************8
//FUNCION GOTOXY ++++++++++++++++++++++++++++++++++++++++++++ 
void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 // fin de la funcion GOTOXY************************************************************
 //INICIA FUNCION ABRIR*****************************************************************************8
void abrir()
 {
 	pf = fopen("C:\\Users\\mary\\Documents\\proyecto\\Usuarios.bin","rb");
 	if(pf==NULL)
	{
		pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Usuarios.bin","wb");
		cout<<"Se Creo un archivo para usuaros correctamente.\n";
		Sleep(1000);
	}
	else
	{
		cout<<"Iniciando sistema...\n";
		Sleep(1000);
		reg=1;
	}
 }
 //TERINA FUNCION ABRIR*********************************************************************************
 //INICIA LA FUNCION INGRESAR*************************************************************************
 void ingresar()
 {
 	int selec=0,val=0,usuval=0,valid=0,lonu=0;
 	pf2=fopen("C:\\Users\\mary\\Documents\\proyecto\\Recargas.bin","ab+");
 	pv=fopen("C:\\Users\\mary\\Documents\\proyecto\\Ventas.bin","ab+");
 	if((pf = fopen("C:\\Users\\mary\\Documents\\proyecto\\Usuarios.bin","rb")) == NULL)
	{
		cout << "¡No se encontro el archivo para la lectura!";
		exit(0);
		getch();
	}
	system("cls");
	edit();

	Sleep(2500);
 	if(reg==1)
 	{
		do
		{
			do
			{
				valid=0;
				lonu=0;
				fseek(pf,0,SEEK_SET);
				fflush(stdin);
				system("cls");
				gotoxy(20,5);cout<<"BIENVENIDO A BROTHERS STORE.";
				memset(user,0,sizeof(user));
				gotoxy(20,7);cout<<"Ingrese su usuario: ";
				gets(user);
				lonu=strlen(user);
				if(lonu>50)
				{
					gotoxy(20,9);cout<<"Usuario incorrecto.";
					Sleep(1000);
					valid=1;
				}
				if(lonu==0)
				{
					gotoxy(20,9);cout<<"Usuario incorrecto.";
					Sleep(1000);
					valid=1;
				}
			}while(valid!=0);
			do
			{
				system("cls");
				valid=0;
				lonu=0;
				memset(pass,0,sizeof(pass));
				gotoxy(20,10);cout<<"Ingrese su contraseña: ";
				contra(pass);	
				lonu=strlen(pass);
				if(lonu>50)
				{
					gotoxy(20,12);cout<<"Contraseña No valida.";
					Sleep(1000);
					valid=1;
				}
				if(lonu==0)
				{
					gotoxy(20,12);cout<<"Contraseña No valida.";
					Sleep(1000);
					valid=1;
				}
			}while(valid!=0);
		do
		{
			memset(&usuario,0,sizeof(usuario));
			fread(&usuario,sizeof(usuario),1,pf);
			for(int i=0; i < 2; i++)
			{
				c=fgetc(pf);
			}
			if(!strcmp(user,usuario.nombre)&&!strcmp(pass,usuario.passwo)&&usuario.eliminado==0)
			{
				usuval=1;
				if(usuario.ban==1)
				adm=1;
			}
		}while(c!=EOF);
		if(usuval==0)
		{
			gotoxy(20,13);cout<<"Usuario o Contraseña incorrecto.\n";
			Sleep(2000);
		}
		}while(usuval!=1);
		pm=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb+");
		do
    	{
    		c=fgetc(pm);
			if(c!=EOF)
			{
				contador++;	
			}	
		}while(c!=EOF);
		tam=sizeof(articulo);
		taminm=sizeof(marcai);
		taminc=sizeof(categoriai);
		cod=contador/tam;
		cod+=1;
		if(usuario.ban==1)
		adm=1;
	}
	fclose (pf);
	fclose (pm);
	fclose (pv);
	fclose (pf2);
 }
 /////TERMINA LA FUNCION INGRESAR*******************************************************************
 void contra(char *con)
 {
 	 char op;
     op=0;
     while(op!=13)//Retorno de carro
     {
        do
        {
            op=getch();
            if(op==8)//Retroceso 
            {
	            con--;
	            o--;
            	gotoxy(o,t);
				putchar(' ');
            }
                if(op==27)//Escape
                {
				      esc=1;
				      break;
                }
        }
		  while(op==8);
		  if(esc==1)
		   {
		    esc=2;
		    break;
		   }
		    *con=op;
		    if(op!=13)
		    gotoxy(o++,t); 
			putchar('*');
		  con++;
		 }
		 con--;
		 *con='\0';
		 o++;
 }
 //INICIA LA FUNCION AULTA_USER*************************************************************************8
 void alta_user()
{
	int ban=0,to=0;
	char q;
	int lonu=0,lonc=0;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Usuarios.bin","ab+");
	do
	{
		system("cls");
		ban=0;
		memset(&usuario,0,sizeof(usuario));
		fflush(stdin);
		gotoxy(20,3);cout<<"Bienvenido a la funcion para registrar un nuevo usuario.\n";
		gotoxy(20,5);cout<<"Ingrese el nombre de usuario: ";
		gets(usuario.nombre);
		lonu=strlen(usuario.nombre);
		if(lonu>50)
		{
			ban=1;
			gotoxy(20,7);cout<<"No se acepta un nombre de usuario de mas de 50 caracteres.\n";
			Sleep(1000);
		}
		if(lonu==0)
		{
			gotoxy(20,7);cout<<"No ingresaste nada.";
			Sleep(1000);
			ban=1;
		}
		for(int u=0;u<lonu;u++)
		{
			to=isalpha(usuario.nombre[u]);
			if(strchr(usuario.nombre,' '))
			ban=0;
			if(to==0)
			ban=2;
		}
		if(ban==2)
		{
			gotoxy(20,7);cout<<"No se aceptan numeros como nombre.";
			Sleep(1000);
		}
	}while(ban!=0);
	do
	{
		system("cls");
		ban=0;
		lonc=0;
		gotoxy(24,10);cout<<"Ingresa tu contraseña: ";
		contra(usuario.passwo);
		lonc=strlen(usuario.passwo);
		if(lonc>50)
		{
			ban=1;
			gotoxy(20,11);cout<<"No se acepta una contraseña de ese tamaño.";
			Sleep(1000);
		}	
		if(lonc==0)
		{
			ban=1;
			gotoxy(20,11);cout<<"No ingresaste nada.";
			Sleep(1000);
		}
	}while(ban!=0);
	do
		{
			system("cls");
			gotoxy(20,13);cout<<"Como decea registrarlo?\n";
			gotoxy(20,14);cout<<"[A] Administrador\n";
			gotoxy(20,15);cout<<"[U] Usuario.\n";
			q=getch();
			if(q=='A'||q=='a')
			usuario.ban=1;
		}while(q!='a'&&q!='A'&&q!='U'&&q!='u');
		gotoxy(20,17);cout<<"Usuario Añadido Correctamente.";
		Sleep(2000);
	fwrite(&usuario,sizeof(usuario),1,pf);
	fprintf(pf,"\r\n");
	fclose (pf);
}
//////////TERMINA LA FUNCON ALTA_USER**************************************************************************8
///////INICIA LA FUNCION AÑADIR UN ARTICULO***********************************************************************
void add_articulo()
{
	int val=0,lon=0,vali=0,suma=0,puntero=0,y=10,enc=0;
	char pre[10],cant[10],cant2[10],selec='\0';
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","ab+");
	pv=fopen("C:\\Users\\mary\\Documents\\proyecto\\Ventas.bin","ab+");
	pf2=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb+");
	pm=fopen("C:\\Users\\mary\\Documents\\proyecto\\Marcas_Articulos.bin","ab+");
	pc=fopen("C:\\Users\\mary\\Documents\\proyecto\\Categoria_Articulos.bin","ab+");
	do
	{
			char c2[5]="C00",c3[5]="C0",c4[5]="C";
			memset(&articulo,0,sizeof(articulo));
			memset(&marcai,0,sizeof(marcai));
			memset(&categoriai,0,sizeof(categoriai));
			memset(codigo2,0,sizeof(codigo2));
			itoa(cod,codigo2,10);
			if(cod<=9)
			{
				strcat(c2,codigo2);
			}
			if(cod>=10&&cod<=99)
			{
				strcat(c3,codigo2);
			}
			if(cod>=100&&cod<=999)
			{
				strcat(c4,codigo2);
			}
			do
			{
				lon=0;
				vali=0;
				system("cls");
				fflush(stdin);			
				gotoxy(20,5);cout<<"Nombre del Articulo que desea agregar: ";
				gets(articulo.nom);
				lon=strlen(articulo.nom);
				if(lon==0)
				{
					gotoxy(20,7);cout<<"No ingresaste nada.";
					vali=1;
					Sleep(1000);
				}
				if(lon>50)
				{
					gotoxy(20,7);cout<<"No se acepta un nombre de ese tamaño";
					vali=1;
					Sleep(1000);
				}
			}while(vali!=0);
			fseek(pf2,0,SEEK_SET);
			do
			{
				memset(&articulo2,0,sizeof(articulo2));
				fread(&articulo2,sizeof(articulo2),1,pf2);
				y=10;
				for(int i=0; i < 2; i++)
				{
					c=fgetc(pf2);
				}
				if(!strcmpi(articulo2.nom,articulo.nom)&&articulo2.eliminado==0)
				{
					system("cls");
					gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
					y++;
					gotoxy(15,y);cout<<"|"<<articulo2.codigo;gotoxy(25,y);cout<<"|"<<articulo2.nom;gotoxy(40,y);cout<<"| $"<<articulo2.precio;gotoxy(50,y);cout<<"|"<<articulo2.marca;gotoxy(65,y);cout<<"|"<<articulo2.categoria;gotoxy(85,y);cout<<"|"<<articulo2.cantidad;
					enc=1;
					y++;
		
				do
				{			
					gotoxy(20,15);cout<<"Es el Articulo que Desea Agregar? S/N ";
					c=getch();
					if(c!='n'&&c!='N'&&c!='s'&&c!='S')
					Beep(500,100);
				}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
				if(c=='s'||c=='S')
				{
					do
					{
						system("cls");
						vali=0;
						gotoxy(20,10);cout<<"Cuantos Articulos Deseas Agregar?";
						gets(cant2);
						if(strlen(cant2)==0||strlen(cant2)>10)
						{
							gotoxy(20,12);cout<<"Cantidad No valida";
							vali=1;
							Sleep(1000);
						}
						articulo.cantidad=atoi(cant2);
						if(articulo.cantidad==0||articulo.cantidad<0)
						{
							gotoxy(20,12);cout<<"Cantidad No valida.";
							vali=1;
							Sleep(1000);
						}
					}while(vali!=0);
					articulo2.cantidad=articulo2.cantidad+articulo.cantidad;
					fseek(pf2,-tam-2,SEEK_CUR);
					fwrite(&articulo2,sizeof(articulo2),1,pf2);
					fseek(pf2,2,SEEK_CUR);
					enc=9;
				}//fin del if de aceptacion
				if(c=='s'||c=='S')
				break;
			}//fin de if de comparacion
			}while(c!=EOF);
			if(enc==9)
			{
				gotoxy(20,13);cout<<"Los Articulos Fueron Agregados Exitosamente.";
				Sleep(1000);
			}
			else
			{
				do
				{
					vali=0;
					system("cls");
					gotoxy(20,9);cout<<"Precio del articulo: $";
					gets(pre);
					if(strlen(pre)==0||strlen(pre)>10)
					{
						gotoxy(20,11);cout<<"Precio No valido";
						vali=1;
						Sleep(1000);
					}
					articulo.precio=atoi(pre);
					if(articulo.precio==0||articulo.precio<0)
					{
						gotoxy(20,11);cout<<"El articulo no puede tener ese valor";
						vali=1;
						Sleep(1000);
					}
				}while(vali!=0);
				do
				{
					vali=0;
					system("cls");
					gotoxy(20,13);cout<<"Seleccione la categoria del articulo.";
					gotoxy(20,15);cout<<"0.-Mica de cristal.";
					gotoxy(20,16);cout<<"1.-Protector silicon.";
					gotoxy(20,17);cout<<"2.-Cargador.";
					gotoxy(20,18);cout<<"3.-Memoria.";
					gotoxy(20,19);cout<<"4.-Cable USB.";
					gotoxy(20,20);cout<<"5.-Audifono.";
					gotoxy(20,21);cout<<"6.-Cable de Video.";
					gotoxy(20,22);cout<<"7.-Adaptador.";
					gotoxy(20,23);cout<<"8.-Holder para Coche.";
					gotoxy(20,24);cout<<"9.-Sim.";
					gotoxy(20,25);cout<<"A.-Bateria.";
					gotoxy(20,26);cout<<"B.-Otro.";
					selec=getch();
					if(selec==48)
					{
						strcpy(articulo.categoria,cristal);
						strcpy(categoriai.categoria,cristal);
					}
					else if(selec==49)
					{
						strcpy(articulo.categoria,tpu);
						strcpy(categoriai.categoria,tpu);
					}
					else if(selec==50)
					{
						strcpy(articulo.categoria,cargador);
						strcpy(categoriai.categoria,cargador);
					}	
					else if(selec==51)
					{
						strcpy(articulo.categoria,memoria);
						strcpy(categoriai.categoria,memoria);
					}
					else if(selec==52)
					{
						strcpy(articulo.categoria,cable);
						strcpy(categoriai.categoria,cable);
					}
					else if(selec==53)
					{
						strcpy(articulo.categoria,audifono);
						strcpy(categoriai.categoria,audifono);
					}
					else if(selec==54)
					{
						strcpy(articulo.categoria,cable2);
						strcpy(categoriai.categoria,cable2);
					}
					else if(selec==55)
					{
						strcpy(articulo.categoria,adaptador);
						strcpy(categoriai.categoria,adaptador);
					}
					else if(selec==56)
					{
						strcpy(articulo.categoria,holder);
						strcpy(categoriai.categoria,holder);
					}
					else if(selec==57)
					{
						strcpy(articulo.categoria,sim);
						strcpy(categoriai.categoria,sim);
					}
					else if(selec==65||selec==97)
					{
						strcpy(articulo.categoria,bateria);
						strcpy(categoriai.categoria,bateria);
					}
					else if(selec==66||selec==98)
					{
						strcpy(articulo.categoria,otro);
						strcpy(categoriai.categoria,otro);
					}
					else
					vali=1;
				}while(vali!=0);
				do
				{
					vali=0;
					system("cls");
					gotoxy(20,13);cout<<"Seleccione la marca del articulo.";
					gotoxy(20,15);cout<<"0.-SAMSUNG.";
					gotoxy(20,16);cout<<"1.-MOTOROLA.";
					gotoxy(20,17);cout<<"2.-LG.";
					gotoxy(20,18);cout<<"3.-IPHONE.";
					gotoxy(20,19);cout<<"4.-SONY.";
					gotoxy(20,20);cout<<"5.-ALCATEL.";
					gotoxy(20,21);cout<<"6.-HUAWEI.";
					gotoxy(20,22);cout<<"7.-HTC.";
					gotoxy(20,23);cout<<"8.-ZTE.";
					gotoxy(20,24);cout<<"9.-LANIX.";
					gotoxy(20,25);cout<<"A.-M4.";
					gotoxy(20,26);cout<<"B.-NOKIA.";
					gotoxy(20,27);cout<<"C.-HISENSE.";
					gotoxy(20,28);cout<<"D.-KINGSTON.";
					gotoxy(20,29);cout<<"E.-OTRO.";
					selec=getch();
					if(selec==48)
					{
						strcpy(articulo.marca,samsung);
						strcpy(marcai.marca,samsung);
					}
					else if(selec==49)
					{
						strcpy(articulo.marca,motorola);
						strcpy(marcai.marca,motorola);
					}
					else if(selec==50)
					{
						strcpy(articulo.marca,lg);
						strcpy(marcai.marca,lg);
					}
					else if(selec==51)
					{
						strcpy(articulo.marca,iphone);
						strcpy(marcai.marca,iphone);
					}
					else if(selec==52)
					{
						strcpy(articulo.marca,sony);
						strcpy(marcai.marca,sony);
					}
					else if(selec==53)
					{
						strcpy(articulo.marca,alcatel);
						strcpy(marcai.marca,alcatel);
					}
					else if(selec==54)
					{
						strcpy(articulo.marca,huawei);
						strcpy(marcai.marca,huawei);
					}
					else if(selec==55)
					{
						strcpy(articulo.marca,htc);
						strcpy(marcai.marca,htc);
					}
					else if(selec==56)
					{
						strcpy(articulo.marca,zte);
						strcpy(marcai.marca,zte);
					}
					else if(selec==57)
					{
						strcpy(articulo.marca,lanix);
						strcpy(marcai.marca,lanix);
					}
					else if(selec==65||selec==97)
					{
						strcpy(articulo.marca,m4);
						strcpy(marcai.marca,m4);
					}
					else if(selec==66||selec==98)
					{
						strcpy(articulo.marca,nokia);
						strcpy(marcai.marca,nokia);
					}
					else if(selec==67||selec==99)
					{
						strcpy(articulo.marca,hisense);
						strcpy(marcai.marca,hisense);
					}
					else if(selec==68||selec==100)
					{
						strcpy(articulo.marca,kingston);
						strcpy(marcai.marca,kingston);
					}
					else if(selec==69||selec==101)
					{
						strcpy(articulo.marca,otrom);
						strcpy(marcai.marca,otrom);
					}
					else
					vali=1;
				}while(vali!=0);
				do
				{
					vali=0;
					memset(cant,0,sizeof(cant));
					system("cls");
					gotoxy(20,10);cout<<"Ingrese la cantidad de articulos: ";
					gets(cant);
					if(strlen(cant)==0||strlen(cant)>10)
					{
						gotoxy(20,12);cout<<"Cantidad No valida";
						vali=1;
						Sleep(1000);
					}
					articulo.cantidad=atoi(cant);
					if(articulo.cantidad==0||articulo.cantidad<0)
					{
						gotoxy(20,12);cout<<"Cantidad No valida.";
						vali=1;
						Sleep(1000);
					}
				}while(vali!=0);
			/*if(cod!=1)
			{
				do
				{
					memset(&articulo2,0,sizeof(articulo2));
					fread(&articulo2,sizeof(articulo2),1,pf2);
					for(int i=0; i < 2; i++)
					{
						c=fgetc(pf2);
					}
					if(!strcmpi(articulo2.nom,articulo.nom)&&!strcmpi(articulo2.categoria,articulo.categoria)&&!strcmpi(articulo2.marca,articulo.marca)&&articulo.precio==articulo2.precio&&articulo2.eliminado==0)
					{
						strcpy(articulo.codigo,articulo2.codigo);
						articulo.cantidad=articulo.cantidad+articulo2.cantidad;
						suma=1;
						fseek(pf2,-tam-2,SEEK_CUR);
						fwrite(&articulo,sizeof(articulo),1,pf2);
						fseek(pf2,2,SEEK_CUR);
					}
				}while(c!=EOF);
			}*/
		if(suma==0)
		{
			if(cod<=9)
			{
				strcpy(articulo.codigo,c2);
				strcpy(marcai.codigo,c2);
				strcpy(categoriai.codigo,c2);
			}
			if(cod>=10&&cod<=99)
			{
				strcpy(articulo.codigo,c3);
				strcpy(marcai.codigo,c3);
				strcpy(categoriai.codigo,c3);
			}
			if(cod>=100&&cod<=999)
			{
				strcpy(articulo.codigo,c4);
				strcpy(marcai.codigo,c4);
				strcpy(categoriai.codigo,c4);
			}
			cod++;
			marcai.ban=0;
			articulo.eliminado=0;
			categoriai.ban=0;
			fwrite(&articulo,sizeof(articulo),1,pf);
			fprintf(pf,"\r\n");
			fwrite(&categoriai,sizeof(categoriai),1,pc);
			fprintf(pc,"\r\n");
			fwrite(&marcai,sizeof(marcai),1,pm);
			fprintf(pm,"\r\n");
		}
	}
		do
		{
			gotoxy(20,26);
			cout<<"Desea Agregar mas Articulos? S/N ";
			c=getch();
			if(c!='n'&&c!='N'&&c!='s'&&c!='S')
			Beep(500,100);
		}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
	}while(c=='s'||c=='S');//Fin de captura de datos
	fclose (pf);
	fclose (pv);
	fclose (pc);
	fclose (pm);
	fclose (pf2);
}
//////////TERMINA LA FUNCION AÑADIR ARTICULO***********************************************************************
////////////INICIA LA FUNCION ELIMINAR UN USUARIO*****************************************************************
void elim_user()
{
	char consulta[50];
	int del=0,vali=0,lon=0,enc=0;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Usuarios.bin","rb+");
	do
	{
		do
		{
			enc=0;
			vali=0;
			fflush(stdin);
			memset(consulta,0,sizeof(consulta));
			gotoxy(20,5);cout<<"Ingrese el usuario que desea eliminar: ";
			gets(consulta);
			lon=strlen(consulta);
			if(lon==0||lon>50)
			{
				gotoxy(20,7);cout<<"Usuario No valido.";
				vali=1;
				Sleep(1000);
			}
		}while(vali!=0);
		do
		{
			del=0;
			memset(&usuario,0,sizeof(usuario));
			fread(&usuario,sizeof(usuario),1,pf);
			for(int i=0; i < 2; i++)
			{
				c=fgetc(pf);
			}
			if(!strcmpi(consulta,usuario.nombre)&&usuario.eliminado==0)
			{
				gotoxy(20,9);cout<<"El usuario "<<consulta<<" a sido eliminado.";
				Sleep(2000);
				usuario.eliminado=1;
				del=1;
				enc=1;
			}
			if(del==1)
			{
				fseek(pf,-78,SEEK_CUR);
				fwrite(&usuario,sizeof(usuario),1,pf);
				fseek(pf,2,SEEK_CUR);
				Sleep(1000);
			}
		}while(c!=EOF);
		if(enc==0)
		{
			gotoxy(20,15);cout<<"No se encntro ningun registro con ese nombre.";
		}
		Sleep(2000);
		do
		{
			gotoxy(20,13);
			cout<<"Desea Eliminar mas Usuarios? S/N ";
			c=getch();
			if(c!='n'&&c!='N'&&c!='s'&&c!='S')
			Beep(500,100);
		}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
	}while(c=='s'||c=='S');
	fclose (pf);
}
///////////////////TERMINA LA FUNCION ELIMINAR USUARIO************************************************************
///////////////////INICIA LA FUNCION MODIFICAR USUARIO*****************************************************************
void modificar_usuario()
{
	char consulta[50],consulta2[50];
	int del=0,vali=0,lon=0,enc=0;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Usuarios.bin","rb+");
	do
	{
		do
		{
			vali=0;
			enc=0;
			fflush(stdin);
			memset(consulta,0,sizeof(consulta));
			system("cls");
			gotoxy(20,5);cout<<"Ingrese el Nombre del Usuario que Desea Modificar: ";
			gets(consulta);
			lon=strlen(consulta);
			if(lon==0||lon>50)
			{
				gotoxy(20,7);cout<<"Usuario No valido.";
				vali=1;
				Sleep(1000);
			}
		}while(vali!=0);
		do
		{
			vali=0;
			fflush(stdin);
			memset(consulta2,0,sizeof(consulta2));
			gotoxy(20,10);cout<<"Ingrese la Contraseña: ";
			contra(consulta2);
			lon=strlen(consulta2);
			if(lon==0||lon>50)
			{
				gotoxy(20,12);cout<<"Contraseña No Valida.";
				vali=1;
				Sleep(1000);
			}
		}while(vali!=0);
		do
		{
			del=0;
			memset(&usuario,0,sizeof(usuario));
			fread(&usuario,sizeof(usuario),1,pf);
			for(int i=0; i < 2; i++)
			{
				c=fgetc(pf);
			}
			if(!strcmpi(consulta,usuario.nombre)&&!strcmpi(consulta2,usuario.passwo)&&usuario.eliminado==0)
			{
				do
				{
					vali=0;
					fflush(stdin);
					system("cls");
					memset(&usuario,0,sizeof(&usuario));
					gotoxy(20,5);cout<<"Ingrese el Nuevo Nombre del Usuario: ";
					gets(usuario.nombre);
					lon=strlen(usuario.nombre);
					if(lon==0||lon>50)
					{
						gotoxy(20,7);cout<<"Usuario No valido.";
						vali=1;
						Sleep(1000);
					}
				}while(vali!=0);
				do
				{
					vali=0;
					fflush(stdin);
					memset(usuario.passwo,0,sizeof(usuario.passwo));
					gotoxy(20,10);cout<<"Ingrese la Nueva Contraseña: ";
					contra(usuario.passwo);
					lon=strlen(usuario.passwo);
					if(lon==0||lon>50)
					{
						gotoxy(20,12);cout<<"Contraseña No Valida.";
						vali=1;
						Sleep(1000);
					}
				}while(vali!=0);
				
				gotoxy(20,13);cout<<"El Usuario "<<consulta<<" a Sido Modificado.";
				Sleep(2000);
				del=1;
			}
			if(del==1)
			{
				fseek(pf,-78,SEEK_CUR);
				fwrite(&usuario,sizeof(usuario),1,pf);
				fseek(pf,2,SEEK_CUR);
			}
		}while(c!=EOF);
		if(enc==0)
		{
			gotoxy(20,15);cout<<"No se encntro ningun registro con ese nombre.";
		}
		Sleep(2000);
		do
		{
			gotoxy(20,15);
			cout<<"Desea Modificar mas Usuarios? S/N ";
			c=getch();
			if(c!='n'&&c!='N'&&c!='s'&&c!='S')
			Beep(500,100);
		}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
	}while(c=='s'||c=='S');
	fclose (pf);
}
////////////////////TERMINA LA FUNCION MODIFCAR USUARIO******************************************************************
///////////////////INICIA LA FUNCION MODIFICAR ARTICULO************************************************************
void modificar_articulo()
{
	char consulta[50];
	char pre[10],cant[10],selec='\0',coda[5],c='\0';
	int vali=0,lon=0,puntero=0,codig=0,tren=30,enc=0;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb+");
	pm=fopen("C:\\Users\\mary\\Documents\\proyecto\\Marcas_Articulos.bin","rb+");
	pc=fopen("C:\\Users\\mary\\Documents\\proyecto\\Categoria_Articulos.bin","rb+");
	do
	{
		do
		{
			fseek(pf,0,SEEK_SET);
			tren=30;
			vali=0;
			lon=0;
			enc=0;
			fflush(stdin);
			memset(consulta,0,sizeof(consulta));
			system("cls");
			gotoxy(20,5);cout<<"Ingrese el articulo que desea modificar: ";
			gets(consulta);
			lon=strlen(consulta);
			if(lon==0||lon>50)
			{
				gotoxy(20,7);cout<<"Nombre de Articulo No valido.";
				vali=1;
				Sleep(1000);
			}
		}while(vali!=0); 
		do
		{
			memset(&articulo,0,sizeof(articulo));
			fread(&articulo,sizeof(articulo),1,pf);
			for(int i=0; i < 2; i++)
			{
				c=fgetc(pf);
			}
			if(!strcmpi(consulta,articulo.nom)&&articulo.eliminado==0)
			{
				system("cls");
				gotoxy(15,9);cout<<"|CODIGO";gotoxy(25,9);cout<<"|NOMBRE";gotoxy(40,9);cout<<"|PRECIO";gotoxy(50,9);cout<<"|MARCA";gotoxy(65,9);cout<<"|CATEGORIA";gotoxy(85,9);cout<<"|CANTIDAD"<<endl;
				gotoxy(15,10);cout<<"|"<<articulo.codigo;gotoxy(25,10);cout<<"|"<<articulo.nom;gotoxy(40,10);cout<<"| $"<<articulo.precio;gotoxy(50,10);cout<<"|"<<articulo.marca;gotoxy(65,10);cout<<"|"<<articulo.categoria;gotoxy(85,10);cout<<"|"<<articulo.cantidad;
				enc=1;
				do
				{			
					gotoxy(20,15);cout<<"Son los datos que decea modificar? S/N ";
					c3=getch();
					if(c3!='n'&&c3!='N'&&c3!='s'&&c3!='S')
					Beep(500,100);
				}while(c3!='n'&&c3!='N'&&c3!='s'&&c3!='S');
				if(c3=='s'||c3=='S')
				{
					do
					{
						system("cls");
						gotoxy(20,5);cout<<"Que Desea Modificar?";
						gotoxy(20,6);cout<<"1.-Nombre.";
						gotoxy(20,7);cout<<"2.-Precio.";
						gotoxy(20,8);cout<<"3.-Marca.";
						gotoxy(20,9);cout<<"4.-Categoria.";
						gotoxy(20,10);cout<<"5.-Cantidad.";
						c=getch();
					}while(c!=49&&c!=50&&c!=51&&c!=52&&c!=53);
					fflush(stdin);
					strcpy(marcai.codigo,articulo.codigo);
					strcpy(categoriai.codigo,articulo.codigo);
					switch(c)
					{
						case 49:do
								{
									lon=0;
									vali=0;
									system("cls");
									fflush(stdin);	
									memset(&articulo.nom,0,sizeof(articulo.nom));	
									gotoxy(20,3);cout<<"Codigo del ariculo: "<<articulo.codigo;			
									gotoxy(20,5);cout<<"Ingrese el Nuevo Nombre del Articulo: ";
									gets(articulo.nom);
									lon=strlen(articulo.nom);
									if(lon==0)
									{
										gotoxy(20,7);cout<<"No ingresaste nada.";
										vali=1;
										Sleep(1000);
									}
									if(lon>50)
									{
										gotoxy(20,7);cout<<"No se hacepta un nombre de ese tamaño";
										vali=1;
										Sleep(1000);
									}
								}while(vali!=0);
								break;
						case 50:do
								{
									vali=0;
									system("cls");
									articulo.precio=0;
									gotoxy(20,9);cout<<"Nuevo Precio del articulo: $";
									gets(pre);
									if(strlen(pre)==0||strlen(pre)>10)
									{
										gotoxy(20,11);cout<<"Precio No valido";
										vali=1;
										Sleep(1000);
									}
									articulo.precio=atoi(pre);
									if(articulo.precio==0||articulo.precio<0)
									{
										gotoxy(20,11);cout<<"El articulo no puede tener ese valor";
										vali=1;
										Sleep(1000);
									}
								}while(vali!=0);
								break;
						case 52:do
								{
									vali=0;
									system("cls");
									gotoxy(20,13);cout<<"Seleccione la categoria del articulo.";
									gotoxy(20,15);cout<<"0.-Mica de cristal.";
									gotoxy(20,16);cout<<"1.-Protector silicon.";
									gotoxy(20,17);cout<<"2.-Cargador.";
									gotoxy(20,18);cout<<"3.-Memoria.";
									gotoxy(20,19);cout<<"4.-Cable USB.";
									gotoxy(20,20);cout<<"5.-Audifono.";
									gotoxy(20,21);cout<<"6.-Cable de Video.";
									gotoxy(20,22);cout<<"7.-Adaptador.";
									gotoxy(20,23);cout<<"8.-Holder para Coche.";
									gotoxy(20,24);cout<<"9.-Sim.";
									gotoxy(20,25);cout<<"A.-Bateria.";
									gotoxy(20,26);cout<<"B.-Otro.";
									selec=getch();
									if(selec==48)
									{
										strcpy(articulo.categoria,cristal);
										strcpy(categoriai.categoria,cristal);
									}
									else if(selec==49)
									{
										strcpy(articulo.categoria,tpu);
										strcpy(categoriai.categoria,tpu);
									}
									else if(selec==50)
									{
										strcpy(articulo.categoria,cargador);
										strcpy(categoriai.categoria,cargador);
									}	
									else if(selec==51)
									{
										strcpy(articulo.categoria,memoria);
										strcpy(categoriai.categoria,memoria);
									}
									else if(selec==52)
									{
										strcpy(articulo.categoria,cable);
										strcpy(categoriai.categoria,cable);
									}
									else if(selec==53)
									{
										strcpy(articulo.categoria,audifono);
										strcpy(categoriai.categoria,audifono);
									}
									else if(selec==54)
									{
										strcpy(articulo.categoria,cable2);
										strcpy(categoriai.categoria,cable2);
									}
									else if(selec==55)
									{
										strcpy(articulo.categoria,adaptador);
										strcpy(categoriai.categoria,adaptador);
									}
									else if(selec==56)
									{
										strcpy(articulo.categoria,holder);
										strcpy(categoriai.categoria,holder);
									}
									else if(selec==57)
									{
										strcpy(articulo.categoria,sim);
										strcpy(categoriai.categoria,sim);
									}
									else if(selec==65||selec==97)
									{
										strcpy(articulo.categoria,bateria);
										strcpy(categoriai.categoria,bateria);
									}
									else if(selec==66||selec==98)
									{
										strcpy(articulo.categoria,otro);
										strcpy(categoriai.categoria,otro);
									}
									else
									vali=1;
								}while(vali!=0);
								break;
						case 51:do
								{
									vali=0;
									system("cls");
									memset(&articulo.marca,0,sizeof(articulo.marca));
									memset(&marcai.marca,0,sizeof(marcai.marca));
									gotoxy(20,13);cout<<"Seleccione la marca del articulo.";
									gotoxy(20,15);cout<<"0.-SAMSUNG.";
									gotoxy(20,16);cout<<"1.-MOTOROLA.";
									gotoxy(20,17);cout<<"2.-LG.";
									gotoxy(20,18);cout<<"3.-IPHONE.";
									gotoxy(20,19);cout<<"4.-SONY.";
									gotoxy(20,20);cout<<"5.-ALCATEL.";
									gotoxy(20,21);cout<<"6.-HUAWEI.";
									gotoxy(20,22);cout<<"7.-HTC.";
									gotoxy(20,23);cout<<"8.-ZTE.";
									gotoxy(20,24);cout<<"9.-LANIX.";
									gotoxy(20,25);cout<<"A.-M4.";
									gotoxy(20,26);cout<<"B.-NOKIA.";
									gotoxy(20,27);cout<<"C.-HISENSE.";
									gotoxy(20,28);cout<<"D.-KINGSTON.";
									gotoxy(20,29);cout<<"E.-OTRO.";
									selec=getch();
									if(selec==48)
									{
										strcpy(articulo.marca,samsung);
										strcpy(marcai.marca,samsung);
									}
									else if(selec==49)
									{
										strcpy(articulo.marca,motorola);
										strcpy(marcai.marca,motorola);
									}
									else if(selec==50)
									{
										strcpy(articulo.marca,lg);
										strcpy(marcai.marca,lg);
									}
									else if(selec==51)
									{
										strcpy(articulo.marca,iphone);
										strcpy(marcai.marca,iphone);
									}
									else if(selec==52)
									{
										strcpy(articulo.marca,sony);
										strcpy(marcai.marca,sony);
									}
									else if(selec==53)
									{
										strcpy(articulo.marca,alcatel);
										strcpy(marcai.marca,alcatel);
									}
									else if(selec==54)
									{
										strcpy(articulo.marca,huawei);
										strcpy(marcai.marca,huawei);
									}
									else if(selec==55)
									{
										strcpy(articulo.marca,htc);
										strcpy(marcai.marca,htc);
									}
									else if(selec==56)
									{
										strcpy(articulo.marca,zte);
										strcpy(marcai.marca,zte);
									}
									else if(selec==57)
									{
										strcpy(articulo.marca,lanix);
										strcpy(marcai.marca,lanix);
									}
									else if(selec==65||selec==97)
									{
										strcpy(articulo.marca,m4);
										strcpy(marcai.marca,m4);
									}
									else if(selec==66||selec==98)
									{
										strcpy(articulo.marca,nokia);
										strcpy(marcai.marca,nokia);
									}
									else if(selec==67||selec==99)
									{
										strcpy(articulo.marca,hisense);
										strcpy(marcai.marca,hisense);
									}
									else if(selec==68||selec==100)
									{
										strcpy(articulo.marca,kingston);
										strcpy(marcai.marca,kingston);
									}
									else if(selec==69||selec==101)
									{
										strcpy(articulo.marca,otrom);
										strcpy(marcai.marca,otrom);
									}
									else
									vali=1;
								}while(vali!=0);
								break;
						case 53:do
								{
									vali=0;
									articulo.cantidad=0;
									memset(cant,0,sizeof(cant));
									system("cls");
									gotoxy(20,10);cout<<"Ingrese la cantidad de articulos: ";
									gets(cant);
									if(strlen(cant)==0||strlen(cant)>10)
									{
										gotoxy(20,12);cout<<"Cantidad No valida";
										vali=1;
										Sleep(1000);
									}
									articulo.cantidad=atoi(cant);
									if(articulo.cantidad==0||articulo.cantidad<0)
									{
										gotoxy(20,12);cout<<"Cantidad No valida.";
										vali=1;
										Sleep(1000);
									}
								}while(vali!=0);
								break;
					}//fin de while 
					system("cls");
					gotoxy(20,15);cout<<"El articulo "<<consulta<<" a sido editado\n";
					fseek(pf,-tam-2,SEEK_CUR);
					fwrite(&articulo,sizeof(articulo),1,pf);
					fseek(pf,2,SEEK_CUR);
					strcpy(coda,articulo.codigo+1);
					codig=atoi(coda);
					puntero=codig*34;
					if(c==51)
					{
						fseek(pm,puntero-34,SEEK_SET);
						fwrite(&marcai,sizeof(marcai),1,pm);
					}
					if(c==52)
					{
						fseek(pc,puntero-34,SEEK_SET);
						fwrite(&categoriai,sizeof(categoriai),1,pc);
					}
					Sleep(1500);
				}//fin de if de haceptacion
				if(c3=='s'||c3=='S')
				break;
			}//fin del if strcpy
		}while(c!=EOF);
		if(enc==0)
		{
			gotoxy(20,15);cout<<"No se encontro ningun registro con ese nombre.";
		}
		Sleep(2000);
		do
		{
			gotoxy(20,17);
			cout<<"Desea Modificar mas Articulos? S/N ";
			c=getch();
			if(c!='n'&&c!='N'&&c!='s'&&c!='S')
			Beep(500,100);
		}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
	}while(c=='s'||c=='S');
	fclose (pf);
	fclose (pc);
	fclose (pm);
}
////////////////////////TERMINA LA FUNCION MODIFICAR ARTICULO********************************************************8
////////////////////////INICIA LA FUNCION MOSTRAR ARTICULOS**************************************************************
void mostrar()
{
	int y=7;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb");
	if((pf = fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb")) == NULL)
	{
		cout << "¡No se encontro el archivo para la lectura!";
		exit(0);
		getch();
	}
	else
	{
		gotoxy(20,5);cout<<"Bienvenido a la funcion mostrar.";
		gotoxy(15,6);cout<<"|CODIGO";gotoxy(25,6);cout<<"|NOMBRE";gotoxy(40,6);cout<<"|PRECIO";gotoxy(50,6);cout<<"|MARCA";gotoxy(65,6);cout<<"|CATEGORIA";gotoxy(85,6);cout<<"|CANTIDAD"<<endl;
		do
		{
			memset(&articulo,0,sizeof(articulo));
	        fread(&articulo,sizeof(articulo),1,pf);
	        for(int i=0; i < 2; i++)
			{
				c=fgetc(pf);
			}
			if(!feof(pf)&&articulo.eliminado==0)
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
	        	y++;
			}
		}while(c!=EOF);
		fclose(pf);
		getch();
	}
}
////////////////////////TERMINA LA FUNCION MOSTRAR ARTICULOS**********************************************************
//////////////////////INICIA LA FUNCION BUSCAR ARTICULO********************************************************************
void buscar()
{	
	char consulta[50],coda[5],selec='\0';
	int vali=0,lon=0,codig=0,puntero=0,enc=0,y=9;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb");
	pm=fopen("C:\\Users\\mary\\Documents\\proyecto\\Marcas_Articulos.bin","rb");
	pc=fopen("C:\\Users\\mary\\Documents\\proyecto\\Categoria_Articulos.bin","rb");
	do
	{
		system("cls");
		gotoxy(20,5);cout<<"Como desea buscar el articulo?";
		gotoxy(20,7);cout<<"1.-Por Nombre.\n";
		gotoxy(20,8);cout<<"2.-Por Marca.\n";
		gotoxy(20,9);cout<<"3.-Por Categoria.\n";
		c=getch();
	}while(c!='1'&&c!='2'&&c!='3');
	switch(c)
	{
		case 49:do
				{	
					fseek(pf,0,SEEK_SET);
					y=10;
					do
					{
						system("cls");
						vali=0;
						lon=0;
						fflush(stdin);
						memset(consulta,0,sizeof(consulta));
						gotoxy(20,5);cout<<"Ingrese el nombre del articulo que desea ver: ";
						gets(consulta);
						lon=strlen(consulta);
						if(lon==0||lon>50)
						{
							gotoxy(20,7);cout<<"Nombre de Articulo No valido.";
							vali=1;
							Sleep(1000);
						}
					}while(vali!=0);
					gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
					y++;
					do
					{
						memset(&articulo,0,sizeof(articulo));
						fread(&articulo,sizeof(articulo),1,pf);
						for(int i=0; i < 2; i++)
						{
							c=fgetc(pf);
						}
						if(!strcmpi(consulta,articulo.nom)&&articulo.eliminado==0)
						{
							gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
							enc=1;
							y++;
						}
					}while(c!=EOF);
					if(enc==0)
					{
						gotoxy(20,15);cout<<"No se encntro ningun registro con ese nombre.";
					}
					do
					{
						gotoxy(20,17);
						cout<<"Desea Buascar mas Articulos? S/N ";
						c=getch();
						if(c!='n'&&c!='N'&&c!='s'&&c!='S')
						Beep(500,100);
					}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
				}while(c=='s'||c=='S');
				break;
		case 50:do
				{
					system("cls");
					vali=0;
					enc=0;
					lon=0;
					y=19;
					fflush(stdin);
					memset(consulta,0,sizeof(consulta));
				    gotoxy(20,13);cout<<"Seleccione la marca del articulo.";
					gotoxy(20,15);cout<<"0.-SAMSUNG.";
					gotoxy(20,16);cout<<"1.-MOTOROLA.";
					gotoxy(20,17);cout<<"2.-LG.";
					gotoxy(20,18);cout<<"3.-IPHONE.";
					gotoxy(20,19);cout<<"4.-SONY.";
					gotoxy(20,20);cout<<"5.-ALCATEL.";
					gotoxy(20,21);cout<<"6.-HUAWEI.";
					gotoxy(20,22);cout<<"7.-HTC.";
					gotoxy(20,23);cout<<"8.-ZTE.";
					gotoxy(20,24);cout<<"9.-LANIX.";
					gotoxy(20,25);cout<<"A.-M4.";
					gotoxy(20,26);cout<<"B.-NOKIA.";
					gotoxy(20,27);cout<<"C.-HISENSE.";
					gotoxy(20,28);cout<<"D.-KINGSTON.";
					gotoxy(20,29);cout<<"E.-OTRO.";
					selec=getch();
					if(selec==48)
					{
						strcpy(articulo.marca,samsung);
						strcpy(marcai.marca,samsung);
					}
					else if(selec==49)
					{
						strcpy(articulo.marca,motorola);
						strcpy(marcai.marca,motorola);
					}
					else if(selec==50)
					{
						strcpy(articulo.marca,lg);
						strcpy(marcai.marca,lg);
					}
					else if(selec==51)
					{
						strcpy(articulo.marca,iphone);
						strcpy(marcai.marca,iphone);
					}
					else if(selec==52)
					{
						strcpy(articulo.marca,sony);
						strcpy(marcai.marca,sony);
					}
					else if(selec==53)
					{
						strcpy(articulo.marca,alcatel);
						strcpy(marcai.marca,alcatel);
					}
					else if(selec==54)
					{
						strcpy(articulo.marca,huawei);
						strcpy(marcai.marca,huawei);
					}
					else if(selec==55)
					{
						strcpy(articulo.marca,htc);
						strcpy(marcai.marca,htc);
					}
					else if(selec==56)
					{
						strcpy(articulo.marca,zte);
						strcpy(marcai.marca,zte);
					}
					else if(selec==57)
					{
						strcpy(articulo.marca,lanix);
						strcpy(marcai.marca,lanix);
					}
					else if(selec==65||selec==97)
					{
						strcpy(articulo.marca,m4);
						strcpy(marcai.marca,m4);
					}
					else if(selec==66||selec==98)
					{
						strcpy(articulo.marca,nokia);
						strcpy(marcai.marca,nokia);
					}
					else if(selec==67||selec==99)
					{
						strcpy(articulo.marca,hisense);
						strcpy(marcai.marca,hisense);
					}
					else if(selec==68||selec==100)
					{
						strcpy(articulo.marca,kingston);
						strcpy(marcai.marca,kingston);
					}
					else if(selec==69||selec==101)
					{
						strcpy(articulo.marca,otrom);
						strcpy(marcai.marca,otrom);
					}
					else
					vali=1;
				}while(vali!=0);
				gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
				y++;
				do
				{
					memset(&marcai,0,sizeof(marcai));
					fread(&marcai,sizeof(marcai),1,pm);
					for(int i=0; i < 2; i++)
					{
						c=fgetc(pm);
					}
					if(!strcmpi(consulta,marcai.marca)&&marcai.ban==0)
					{
						strcpy(coda,marcai.codigo+1);
						codig=atoi(coda);
						puntero=codig*106;
						fseek(pf,puntero-106,SEEK_SET);
						fread(&articulo,sizeof(articulo),1,pf);
						gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
						enc=1;
						y++;
					}
				}while(c!=EOF);
				if(enc==0)
				{
					gotoxy(20,15);cout<<"No se encntro ningun registro con ese nombre.";
				}
				getch();
				break;
		case 51:do
				{
					system("cls");
					vali=0;
					enc=0;
					lon=0;
					y=16;
					fflush(stdin);
					gotoxy(20,13);cout<<"Seleccione la categoria del articulo.";
					gotoxy(20,15);cout<<"0.-Mica de cristal.";
					gotoxy(20,16);cout<<"1.-Protector silicon.";
					gotoxy(20,17);cout<<"2.-Cargador.";
					gotoxy(20,18);cout<<"3.-Memoria.";
					gotoxy(20,19);cout<<"4.-Cable USB.";
					gotoxy(20,20);cout<<"5.-Audifono.";
					gotoxy(20,21);cout<<"6.-Cable de Video.";
					gotoxy(20,22);cout<<"7.-Adaptador.";
					gotoxy(20,23);cout<<"8.-Holder para Coche.";
					gotoxy(20,24);cout<<"9.-Sim.";
					gotoxy(20,25);cout<<"A.-Bateria.";
					gotoxy(20,26);cout<<"B.-Otro.";
					selec=getch();
					if(selec==48)
					{
						strcpy(articulo.categoria,cristal);
						strcpy(categoriai.categoria,cristal);
					}
					else if(selec==49)
					{
						strcpy(articulo.categoria,tpu);
						strcpy(categoriai.categoria,tpu);
					}
					else if(selec==50)
					{
						strcpy(articulo.categoria,cargador);
						strcpy(categoriai.categoria,cargador);
					}	
					else if(selec==51)
					{
						strcpy(articulo.categoria,memoria);
						strcpy(categoriai.categoria,memoria);
					}
					else if(selec==52)
					{
						strcpy(articulo.categoria,cable);
						strcpy(categoriai.categoria,cable);
					}
					else if(selec==53)
					{
						strcpy(articulo.categoria,audifono);
						strcpy(categoriai.categoria,audifono);
					}
					else if(selec==54)
					{
						strcpy(articulo.categoria,cable2);
						strcpy(categoriai.categoria,cable2);
					}
					else if(selec==55)
					{
						strcpy(articulo.categoria,adaptador);
						strcpy(categoriai.categoria,adaptador);
					}
					else if(selec==56)
					{
						strcpy(articulo.categoria,holder);
						strcpy(categoriai.categoria,holder);
					}
					else if(selec==57)
					{
						strcpy(articulo.categoria,sim);
						strcpy(categoriai.categoria,sim);
					}
					else if(selec==65||selec==97)
					{
						strcpy(articulo.categoria,bateria);
						strcpy(categoriai.categoria,bateria);
					}
					else if(selec==66||selec==98)
					{
						strcpy(articulo.categoria,otro);
						strcpy(categoriai.categoria,otro);
					}
					else
					vali=1;
				}while(vali!=0);
				gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
				y++;
				do
				{
					memset(&categoriai,0,sizeof(categoriai));
					fread(&categoriai,sizeof(categoriai),1,pc);
					for(int i=0; i < 2; i++)
					{
						c=fgetc(pc);
					}
					if(!strcmpi(consulta,categoriai.categoria)&&categoriai.ban==0)
					{
						strcpy(coda,categoriai.codigo+1);
						codig=atoi(coda);
						puntero=codig*106;
						fseek(pf,puntero-106,SEEK_SET);
						fread(&articulo,sizeof(articulo),1,pf);
						gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
						y++;
						enc=1;
					}
				}while(c!=EOF);
				if(enc==0)
				{
					gotoxy(20,15);cout<<"No se encntro ningun registro con ese nombre.";
				}
				getch();
				break; 
	}
	fclose(pf);
	fclose(pm);
	fclose(pc);
}
//////////////////////////TERMINA LA FUNCION BUSCAR ARTICULO**********************************************************
//////////////////////////INICIA LA FUNCION ELIMINAR ARTICULO**************************************************************
void eliminar()
{
	int vali=0,lon=0,codig=0,puntero=0,enc=0,y=8;
	char consulta[50],coda[5],selec='\0';
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb+");
	pm=fopen("C:\\Users\\mary\\Documents\\proyecto\\Marcas_Articulos.bin","rb+");
	pc=fopen("C:\\Users\\mary\\Documents\\proyecto\\Categoria_Articulos.bin","rb+");
	do
	{
		system("cls");
		gotoxy(20,5);cout<<"Como desea buscar el articulo a eliminar?";
		gotoxy(20,7);cout<<"1.-Por Nombre.\n";
		gotoxy(20,8);cout<<"2.-Por Marca.\n";
		gotoxy(20,9);cout<<"3.-Por Categoria.\n";
		
		c=getch();
	}while(c!='1'&&c!='2'&&c!='3');
	switch(c)
	{
		case 49:do
				{
					system("cls");
					vali=0;
					lon=0;
					fflush(stdin);
					memset(consulta,0,sizeof(consulta));
					gotoxy(20,5);cout<<"Ingrese el nombre del articulo que desea eliminar: ";
					gets(consulta);
					lon=strlen(consulta);
					if(lon==0||lon>50)
					{
						gotoxy(20,7);cout<<"Nombre de Articulo No valido.";
						vali=1;
						Sleep(1000);
					}
				}while(vali!=0);
				gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
				y++;
				do
				{
					memset(&articulo,0,sizeof(articulo));
					fread(&articulo,sizeof(articulo),1,pf);
					for(int i=0; i < 2; i++)
					{
						c=fgetc(pf);
					}
					if(!strcmpi(consulta,articulo.nom)&&articulo.eliminado==0)
					{
						gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
						y++;
						enc=1;
						do
						{	
							fflush(stdin);			
							gotoxy(20,15);cout<<"Son los datos que decea eliminar? S/N ";
							c=getch();
							if(c!='n'&&c!='N'&&c!='s'&&c!='S')
							Beep(500,100);
						}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
					}//FIN DEL IF DE COMPARACION
					if(c=='s'||c=='S')
					{
						articulo.eliminado=1;
						fseek(pf,-tam-2,SEEK_CUR);
						fwrite(&articulo,sizeof(articulo),1,pf);
						fseek(pf,2,SEEK_CUR);
						strcpy(coda,articulo.codigo+1);
						codig=atoi(coda);
						puntero=codig*34;
						fseek(pm,puntero-34,SEEK_SET);
						fread(&marcai,sizeof(marcai),1,pm);
						
						marcai.ban=1;
						fseek(pm,-taminm,SEEK_CUR);
						fwrite(&marcai,sizeof(marcai),1,pm);
						
						
						fseek(pc,puntero-34,SEEK_SET);
						fread(&categoriai,sizeof(categoriai),1,pc);
						categoriai.ban=1;
						fseek(pc,-taminc,SEEK_CUR);
						fwrite(&categoriai,sizeof(categoriai),1,pc);
						
						gotoxy(20,17);cout<<"El articulo fue eliminado.";
					}
				}while(c!=EOF);
				if(enc==0)
				{
					gotoxy(20,15);cout<<"No se encntro ningun registro con ese nombre.";
				}
				Sleep(2000);
				break;
		case 50:do
				{
					system("cls");
					vali=0;
					enc=0;
					lon=0;
					y=10;
					fflush(stdin);
					memset(consulta,0,sizeof(consulta));
					gotoxy(20,13);cout<<"Seleccione la marca del articulo.";
					gotoxy(20,15);cout<<"0.-SAMSUNG.";
					gotoxy(20,16);cout<<"1.-MOTOROLA.";
					gotoxy(20,17);cout<<"2.-LG.";
					gotoxy(20,18);cout<<"3.-IPHONE.";
					gotoxy(20,19);cout<<"4.-SONY.";
					gotoxy(20,20);cout<<"5.-ALCATEL.";
					gotoxy(20,21);cout<<"6.-HUAWEI.";
					gotoxy(20,22);cout<<"7.-HTC.";
					gotoxy(20,23);cout<<"8.-ZTE.";
					gotoxy(20,24);cout<<"9.-LANIX.";
					gotoxy(20,25);cout<<"A.-M4.";
					gotoxy(20,26);cout<<"B.-NOKIA.";
					gotoxy(20,27);cout<<"C.-HISENSE.";
					gotoxy(20,28);cout<<"D.-KINGSTON.";
					gotoxy(20,29);cout<<"E.-OTRO.";
					selec=getch();
					if(selec==48)
					{
						strcpy(articulo.marca,samsung);
						strcpy(marcai.marca,samsung);
					}
					else if(selec==49)
					{
						strcpy(articulo.marca,motorola);
						strcpy(marcai.marca,motorola);
					}
					else if(selec==50)
					{
						strcpy(articulo.marca,lg);
						strcpy(marcai.marca,lg);
					}
					else if(selec==51)
					{
						strcpy(articulo.marca,iphone);
						strcpy(marcai.marca,iphone);
					}
					else if(selec==52)
					{
						strcpy(articulo.marca,sony);
						strcpy(marcai.marca,sony);
					}
					else if(selec==53)
					{
						strcpy(articulo.marca,alcatel);
						strcpy(marcai.marca,alcatel);
					}
					else if(selec==54)
					{
						strcpy(articulo.marca,huawei);
						strcpy(marcai.marca,huawei);
					}
					else if(selec==55)
					{
						strcpy(articulo.marca,htc);
						strcpy(marcai.marca,htc);
					}
					else if(selec==56)
					{
						strcpy(articulo.marca,zte);
						strcpy(marcai.marca,zte);
					}
					else if(selec==57)
					{
						strcpy(articulo.marca,lanix);
						strcpy(marcai.marca,lanix);
					}
					else if(selec==65||selec==97)
					{
						strcpy(articulo.marca,m4);
						strcpy(marcai.marca,m4);
					}
					else if(selec==66||selec==98)
					{
						strcpy(articulo.marca,nokia);
						strcpy(marcai.marca,nokia);
					}
					else if(selec==67||selec==99)
					{
						strcpy(articulo.marca,hisense);
						strcpy(marcai.marca,hisense);
					}
					else if(selec==68||selec==100)
					{
						strcpy(articulo.marca,kingston);
						strcpy(marcai.marca,kingston);
					}
					else if(selec==69||selec==101)
					{
						strcpy(articulo.marca,otrom);
						strcpy(marcai.marca,otrom);
					}
					else
					vali=1;
				}while(vali!=0);
				gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
				y++;
				do
				{
					memset(&marcai,0,sizeof(marcai));
					fread(&marcai,sizeof(marcai),1,pm);
					for(int i=0; i < 2; i++)
					{
						c=fgetc(pm);
					}
					if(!strcmpi(consulta,marcai.marca)&&marcai.ban==0)
					{
						system("cls");
						strcpy(coda,marcai.codigo+1);
						codig=atoi(coda);
						puntero=codig*106;
						fseek(pf,puntero-106,SEEK_SET);
						fread(&articulo,sizeof(articulo),1,pf);
						gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
						enc=1;
						do
						{	
							fflush(stdin);			
							gotoxy(20,15);cout<<"Son los datos que decea eliminar? S/N ";
							c=getch();
							if(c!='n'&&c!='N'&&c!='s'&&c!='S')
							Beep(500,100);
						}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
					}
					if(c=='s'||c=='S')
					{
						marcai.ban=1;
						fseek(pm,-taminm-2,SEEK_CUR);
						fwrite(&marcai,sizeof(marcai),1,pm);
						fseek(pm,2,SEEK_CUR);
						strcpy(coda,marcai.codigo+1);
						codig=atoi(coda);
						
						articulo.eliminado=1;
						fseek(pf,-tam,SEEK_CUR);
						fwrite(&articulo,sizeof(articulo),1,pf);
						puntero=codig*34;
						fseek(pc,puntero-34,SEEK_SET);
						fread(&categoriai,sizeof(categoriai),1,pc);
						categoriai.ban=1;
						fseek(pc,-taminc,SEEK_CUR);
						fwrite(&categoriai,sizeof(categoriai),1,pc);
						
						gotoxy(20,17);cout<<"El articulo fue eliminado.";
					}
				}while(c!=EOF);
				if(enc==0)
				{
					gotoxy(20,19);cout<<"No se encntro ningun registro con ese nombre.";
				}
				Sleep(2000);
				break;
		case 51:do
				{
					system("cls");
					vali=0;
					enc=0;
					lon=0;
					y=10;
					fflush(stdin);
					memset(consulta,0,sizeof(consulta));
					gotoxy(20,13);cout<<"Seleccione la categoria del articulo.";
					gotoxy(20,15);cout<<"0.-Mica de cristal.";
					gotoxy(20,16);cout<<"1.-Protector silicon.";
					gotoxy(20,17);cout<<"2.-Cargador.";
					gotoxy(20,18);cout<<"3.-Memoria.";
					gotoxy(20,19);cout<<"4.-Cable USB.";
					gotoxy(20,20);cout<<"5.-Audifono.";
					gotoxy(20,21);cout<<"6.-Cable de Video.";
					gotoxy(20,22);cout<<"7.-Adaptador.";
					gotoxy(20,23);cout<<"8.-Holder para Coche.";
					gotoxy(20,24);cout<<"9.-Sim.";
					gotoxy(20,25);cout<<"A.-Bateria.";
					gotoxy(20,26);cout<<"B.-Otro.";
					selec=getch();
					if(selec==48)
					{
						strcpy(articulo.categoria,cristal);
						strcpy(categoriai.categoria,cristal);
					}
					else if(selec==49)
					{
						strcpy(articulo.categoria,tpu);
						strcpy(categoriai.categoria,tpu);
					}
					else if(selec==50)
					{
						strcpy(articulo.categoria,cargador);
						strcpy(categoriai.categoria,cargador);
					}	
					else if(selec==51)
					{
						strcpy(articulo.categoria,memoria);
						strcpy(categoriai.categoria,memoria);
					}
					else if(selec==52)
					{
						strcpy(articulo.categoria,cable);
						strcpy(categoriai.categoria,cable);
					}
					else if(selec==53)
					{
						strcpy(articulo.categoria,audifono);
						strcpy(categoriai.categoria,audifono);
					}
					else if(selec==54)
					{
						strcpy(articulo.categoria,cable2);
						strcpy(categoriai.categoria,cable2);
					}
					else if(selec==55)
					{
						strcpy(articulo.categoria,adaptador);
						strcpy(categoriai.categoria,adaptador);
					}
					else if(selec==56)
					{
						strcpy(articulo.categoria,holder);
						strcpy(categoriai.categoria,holder);
					}
					else if(selec==57)
					{
						strcpy(articulo.categoria,sim);
						strcpy(categoriai.categoria,sim);
					}
					else if(selec==65||selec==97)
					{
						strcpy(articulo.categoria,bateria);
						strcpy(categoriai.categoria,bateria);
					}
					else if(selec==66||selec==98)
					{
						strcpy(articulo.categoria,otro);
						strcpy(categoriai.categoria,otro);
					}
					else
					vali=1;
				}while(vali!=0);
				gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
				y++;
				do
				{
					memset(&categoriai,0,sizeof(categoriai));
					fread(&categoriai,sizeof(categoriai),1,pc);
					for(int i=0; i < 2; i++)
					{
						c=fgetc(pc);
					}
					if(!strcmpi(consulta,categoriai.categoria)&&categoriai.ban==0)
					{
						system("cls");
						strcpy(coda,categoriai.codigo+1);
						codig=atoi(coda);
						puntero=codig*106;
						fseek(pf,puntero-106,SEEK_SET);
						fread(&articulo,sizeof(articulo),1,pf);
						gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
						enc=1;
							do
						{	
							fflush(stdin);			
							gotoxy(20,15);cout<<"Son los datos que decea eliminar? S/N ";
							c=getch();
							if(c!='n'&&c!='N'&&c!='s'&&c!='S')
							Beep(500,100);
						}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
					}
					if(c=='s'||c=='S')
					{
						categoriai.ban=1;
						fseek(pc,-taminc-2,SEEK_CUR);
						fwrite(&categoriai,sizeof(categoriai),1,pc);
						fseek(pc,2,SEEK_CUR);
						strcpy(coda,categoriai.codigo+1);
						codig=atoi(coda);
						articulo.eliminado=1;
						fseek(pf,-tam,SEEK_CUR);
						fwrite(&articulo,sizeof(articulo),1,pf);
						puntero=codig*34;
						fseek(pm,puntero-34,SEEK_SET);
						fread(&marcai,sizeof(marcai),1,pm);
						marcai.ban=1;
						fseek(pm,-taminm,SEEK_CUR);
						fwrite(&marcai,sizeof(marcai),1,pm);
						
						gotoxy(20,17);cout<<"El articulo fue eliminado.";
					}
				}while(c!=EOF);
				if(enc==0)
				{
					gotoxy(20,17);cout<<"No se encntro ningun registro con ese nombre.";
				}
				Sleep(2000);
				break; 
	}
	fclose(pf);
	fclose(pm);
	fclose(pc);
}
///////////////////////////TERMINA LA FUNCIOON ELIMIANR ARTICULO*****************************************************************
/////////////////////////////INICIA LA FUNCION VENTA*********************************************************************************
void venta()
{
	char venta1[50],cant[5],coda[5],pago[10],rec[]="recarga",cantu[5];
	int lonu=0,ban=0,vali=0,canti=0,codig=0,puntero=0,total=0,pagos=0,cambio=0,enc=0,bandera=0,mont=0,bandera1=0,canti1=0,pre1=0,y=10;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb+");
	pm=fopen("C:\\Users\\mary\\Documents\\proyecto\\Marcas_Articulos.bin","rb+");
	pc=fopen("C:\\Users\\mary\\Documents\\proyecto\\Categoria_Articulos.bin","rb+");
	pf2=fopen("C:\\Users\\mary\\Documents\\proyecto\\Recargas.bin","rb+");
		if(cod==1)
		{
			gotoxy(20,5);cout<<"NO a registrado articulos.";
			gotoxy(20,6);cout<<"Ingrese a la opcion de añadir articulo para registrar uno nuevo.";
			Sleep(4000);
		}
		else
		{
			do
			{
				ban=0;
				pv=fopen("C:\\Users\\mary\\Documents\\proyecto\\Ventas.bin","ab+");
				do
				{
					fseek(pf,0,SEEK_SET);
					system("cls");
					bandera1=0;
					memset(venta1,0,sizeof(venta1));
					gotoxy(100,1);cout<<"Caja: "<<dia;
					gotoxy(20,5);cout<<"Bienvenido a la funcion de Venta.";
					gotoxy(20,7);cout<<"Ingrese el Articulo a Vender:";
					gets(venta1);
					lonu=strlen(venta1);
					if(lonu>50)
					{
						ban=1;
						gotoxy(20,9);cout<<"Nombre de articulo no valido.";
						Sleep(1000);
					}
					if(lonu==0)
					{
						gotoxy(20,9);cout<<"No ingresaste nada.";
						Sleep(1000);
						ban=1;
					}
					if(!strcmpi(venta1,rec))
					{
						do
						{
							vali=0;
							system("cls");
							gotoxy(20,9);cout<<"Monto de la recarga.";
							gets(cantu);
							if(strlen(cantu)==0||strlen(cantu)>10)
							{
								gotoxy(20,21);cout<<"Cantidad No valida.";
								vali=1;
								Sleep(1000);
							}
							canti1=atoi(cantu);
							if(canti1==0||canti1<0)
							{
								gotoxy(20,21);cout<<"Cantidad No valida.";
								vali=1;
								Sleep(1000);
							}
						
							memset(pre,0,sizeof(pre));
							fseek(pf2,0,SEEK_SET);
							fread(pre,sizeof(pre),1,pf2);
							pre1=atoi(pre);
							pre1=pre1-canti1;
							if(pre1<0)
							{
								gotoxy(20,21);cout<<"No Hay Suficiente Saldo.";
								vali=1;
								Sleep(1000);	
							}
						}while(vali!=0);
						if(pre1==0)
						{
							memset(pre,0,sizeof(pre));
							fseek(pf2,0,SEEK_SET);
							fwrite(pre,sizeof(pre),1,pf2);
							total=total+canti1;
							bandera1=1;
						}
						else
						{
							itoa(pre1,pre,10);
							fseek(pf2,0,SEEK_SET);
							fwrite(pre,sizeof(pre),1,pf2);
							total=total+canti1;
							bandera1=1;
						}
					}
				}while(ban!=0);
				if(bandera1==0)
				{
					do
					{
						y=10;
						memset(&articulo,0,sizeof(articulo));
						fread(&articulo,sizeof(articulo),1,pf);
						for(int i=0; i < 2; i++)
						{
							c=fgetc(pf);
						}
						if(!strcmpi(venta1,articulo.nom)&&articulo.eliminado==0)
						{
							system("cls");
							gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
							y++;
							gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
							enc=1;
							do
							{			
								gotoxy(20,18);cout<<"Es el articulo que desea vender? S/N ";
								c=getch();
								if(c!='n'&&c!='N'&&c!='s'&&c!='S')
								Beep(500,100);
							}while(c!='n'&&c!='N'&&c!='s'&&c!='S');					
							if(c=='s'||c=='S')
							{
								do
								{
									do
									{
										vali=0;
										system("cls");
										ban=0;
										memset(cant,0,sizeof(cant));
										gotoxy(20,20);cout<<"Ingrese la cantidad de articulos a vender: ";
										gets(cant);
										if(strlen(cant)==0||strlen(cant)>10)
										{
											gotoxy(20,21);cout<<"Cantidad No valida.";
											vali=1;
											Sleep(1000);
										}
										canti=atoi(cant);
										if(canti==0||canti<0)
										{
											gotoxy(20,21);cout<<"Cantidad No valida.";
											vali=1;
											Sleep(1000);
										}
									}while(vali!=0);
									articulo.cantidad=articulo.cantidad-canti;
									if(articulo.cantidad<0)
									{
										gotoxy(20,21);cout<<"No hay "<<cant<<" en existencia.";
										articulo.cantidad=articulo.cantidad+canti;
										Sleep(2000);
										ban=1;
									}
								}while(ban!=0);
								fseek(pf,-tam-2,SEEK_CUR);
								fwrite(&articulo,sizeof(articulo),1,pf);
								fseek(pf,2,SEEK_CUR);	
				
								fwrite(&articulo,sizeof(articulo),1,pv);
								fprintf(pv,"\r\n");
								
								total=total+articulo.precio*canti;
								bandera++;
								fclose(pv);
							}//fin del if de haceptacion
							if(c=='s'||c=='S')
							break;
						}//fin del if de strcmpi
					}while(c!=EOF);
					if(enc==0)
					{
						gotoxy(20,15);cout<<"No se encntro ningun registro con ese nombre.";
					}
				}//fin if articulo
				do
				{
					gotoxy(20,25);
					cout<<"Desea Vender mas Articulos? S/N ";
					c=getch();
					if(c!='n'&&c!='N'&&c!='s'&&c!='S')
					Beep(500,100);
				}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
			}while(c=='s'||c=='S');	
			if(bandera!=0||bandera1!=0)
			{
				system("cls");
				gotoxy(20,21);cout<<"Total de la compra: $"<<total;
				do
				{
					vali=0;
					memset(pago,0,sizeof(pago));
					gotoxy(20,23);cout<<"Pago: ";
					gets(pago);
					if(strlen(pago)==0||strlen(pago)>5)
					{
						gotoxy(20,24);cout<<"Pago No valido";
						vali=1;
						Sleep(1000);
					}
					pagos=atoi(pago);
					if(pagos==0||pagos<0||pagos<total)
					{
						gotoxy(20,24);cout<<"Pago No valido";
						vali=1;
						Sleep(1000);
					}
				}while(vali!=0);
				dia=dia+total;
				cambio=pagos-total;
				gotoxy(20,25);cout<<"Cambio: $"<<cambio;
				gotoxy(20,26);cout<<"Articulo vendido correctamente.";
				total=0;
			}
			getch();			
		}//fin del else principal
	fclose(pf);
	fclose(pm);
	fclose(pc);
	fclose(pv);
	fclose(pf2);
}
///////////////////////////////TERMINA LA FUNCION VENTA****************************************************************************
///////////////////////////////INICIA LA FUNCION PAPELERA DE RECICLAJE***************************************************************
void papelera()
{
	int vali=0,lon=0,codig=0,puntero=0,enc=0,cont=0,y=8;
	char consulta[50],coda[5],selec='\0';
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb+");
	pm=fopen("C:\\Users\\mary\\Documents\\proyecto\\Marcas_Articulos.bin","rb+");
	pc=fopen("C:\\Users\\mary\\Documents\\proyecto\\Categoria_Articulos.bin","rb+");
	do
	{
		gotoxy(20,5);cout<<"Bienvenido a la funcion Papelera de Reciclaje.";
		gotoxy(20,7);cout<<"1.Restaurar un Registro.";
		gotoxy(20,8);cout<<"2.Restaurar Todo.";
		c=getch();
	}while(c!='1'&&c!='2');
	switch(c)
	{
		case 49: do
				{
					system("cls");
					fflush(stdin);
					gotoxy(20,5);cout<<"Como desea buscar el articulo a Restaurar?";
					gotoxy(20,7);cout<<"1.-Por Nombre.\n";
					gotoxy(20,8);cout<<"2.-Por Marca.\n";
					gotoxy(20,9);cout<<"3.-Por Categoria.\n";
					
					c=getch();
				}while(c!='1'&&c!='2'&&c!='3');
				switch(c)
				{	
					case 49:do
							{
								system("cls");
								vali=0;
								lon=0;
								fflush(stdin);
								memset(consulta,0,sizeof(consulta));
								gotoxy(20,5);cout<<"Ingrese el nombre del articulo que desea Restaurar: ";
								gets(consulta);
								lon=strlen(consulta);
								if(lon==0||lon>50)
								{
									gotoxy(20,7);cout<<"Nombre de Articulo No valido.";
									vali=1;
									Sleep(1000);
								}
							}while(vali!=0);
							gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
							y++;
							do
							{
								memset(&articulo,0,sizeof(articulo));
								fread(&articulo,sizeof(articulo),1,pf);
								for(int i=0; i < 2; i++)
								{
									c=fgetc(pf);
								}
								if(!strcmpi(consulta,articulo.nom)&&articulo.eliminado==1)
								{
									gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
									enc=1;
									do
									{	
										fflush(stdin);			
										gotoxy(20,15);cout<<"Son los datos que decea restaurar? S/N ";
										c=getch();
										if(c!='n'&&c!='N'&&c!='s'&&c!='S')
										Beep(500,100);
									}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
								}//FIN DEL IF DE COMPARACION
								if(c=='s'||c=='S')
								{
									articulo.eliminado=0;
									fseek(pf,-tam-2,SEEK_CUR);
									fwrite(&articulo,sizeof(articulo),1,pf);
									fseek(pf,2,SEEK_CUR);
									strcpy(coda,articulo.codigo+1);
									codig=atoi(coda);
									puntero=codig*34;
									fseek(pm,puntero-34,SEEK_SET);
									fread(&marcai,sizeof(marcai),1,pm);
									
									marcai.ban=0;
									fseek(pm,-taminm,SEEK_CUR);
									fwrite(&marcai,sizeof(marcai),1,pm);
									
									
									fseek(pc,puntero-34,SEEK_SET);
									fread(&categoriai,sizeof(categoriai),1,pc);
									categoriai.ban=0;
									fseek(pc,-taminc,SEEK_CUR);
									fwrite(&categoriai,sizeof(categoriai),1,pc);
									
									gotoxy(20,17);cout<<"El articulo fue Restaurado Exitosamente.";
								}
							}while(c!=EOF);
							if(enc==0)
							{
								gotoxy(20,15);cout<<"No se encontro ningun registro con ese nombre.";
							}
							Sleep(2000);
							break;
					case 50:do
							{
								system("cls");
								vali=0;
								enc=0;
								lon=0;
								y=10;
								fflush(stdin);
								memset(consulta,0,sizeof(consulta));
								gotoxy(20,13);cout<<"Seleccione la marca del articulo.";
								gotoxy(20,15);cout<<"0.-SAMSUNG.";
								gotoxy(20,16);cout<<"1.-MOTOROLA.";
								gotoxy(20,17);cout<<"2.-LG.";
								gotoxy(20,18);cout<<"3.-IPHONE.";
								gotoxy(20,19);cout<<"4.-SONY.";
								gotoxy(20,20);cout<<"5.-ALCATEL.";
								gotoxy(20,21);cout<<"6.-HUAWEI.";
								gotoxy(20,22);cout<<"7.-HTC.";
								gotoxy(20,23);cout<<"8.-ZTE.";
								gotoxy(20,24);cout<<"9.-LANIX.";
								gotoxy(20,25);cout<<"A.-M4.";
								gotoxy(20,26);cout<<"B.-NOKIA.";
								gotoxy(20,27);cout<<"C.-HISENSE.";
								gotoxy(20,28);cout<<"D.-KINGSTON.";
								gotoxy(20,29);cout<<"E.-OTRO.";
								selec=getch();
								if(selec==48)
								{
									strcpy(articulo.marca,samsung);
									strcpy(marcai.marca,samsung);
								}
								else if(selec==49)
								{
									strcpy(articulo.marca,motorola);
									strcpy(marcai.marca,motorola);
								}
								else if(selec==50)
								{
									strcpy(articulo.marca,lg);
									strcpy(marcai.marca,lg);
								}
								else if(selec==51)
								{
									strcpy(articulo.marca,iphone);
									strcpy(marcai.marca,iphone);
								}
								else if(selec==52)
								{
									strcpy(articulo.marca,sony);
									strcpy(marcai.marca,sony);
								}
								else if(selec==53)
								{
									strcpy(articulo.marca,alcatel);
									strcpy(marcai.marca,alcatel);
								}
								else if(selec==54)
								{
									strcpy(articulo.marca,huawei);
									strcpy(marcai.marca,huawei);
								}
								else if(selec==55)
								{
									strcpy(articulo.marca,htc);
									strcpy(marcai.marca,htc);
								}
								else if(selec==56)
								{
									strcpy(articulo.marca,zte);
									strcpy(marcai.marca,zte);
								}
								else if(selec==57)
								{
									strcpy(articulo.marca,lanix);
									strcpy(marcai.marca,lanix);
								}
								else if(selec==65||selec==97)
								{
									strcpy(articulo.marca,m4);
									strcpy(marcai.marca,m4);
								}
								else if(selec==66||selec==98)
								{
									strcpy(articulo.marca,nokia);
									strcpy(marcai.marca,nokia);
								}
								else if(selec==67||selec==99)
								{
									strcpy(articulo.marca,hisense);
									strcpy(marcai.marca,hisense);
								}
								else if(selec==68||selec==100)
								{
									strcpy(articulo.marca,kingston);
									strcpy(marcai.marca,kingston);
								}
								else if(selec==69||selec==101)
								{
									strcpy(articulo.marca,otrom);
									strcpy(marcai.marca,otrom);
								}
								else
								vali=1;
							}while(vali!=0);
							system("cls");
							gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
							y++;
							do
							{
								memset(&marcai,0,sizeof(marcai));
								fread(&marcai,sizeof(marcai),1,pm);
								for(int i=0; i < 2; i++)
								{
									c=fgetc(pm);
								}
								if(!strcmpi(consulta,marcai.marca)&&marcai.ban==1)
								{
									strcpy(coda,marcai.codigo+1);
									codig=atoi(coda);
									puntero=codig*106;
									fseek(pf,puntero-106,SEEK_SET);
									fread(&articulo,sizeof(articulo),1,pf);
									gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
									enc=1;
									do
									{	
										fflush(stdin);			
										gotoxy(20,15);cout<<"Son los datos que decea Restaurar? S/N ";
										c=getch();
										if(c!='n'&&c!='N'&&c!='s'&&c!='S')
										Beep(500,100);
									}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
								}
								if(c=='s'||c=='S')
								{
									marcai.ban=0;
									fseek(pm,-taminm-2,SEEK_CUR);
									fwrite(&marcai,sizeof(marcai),1,pm);
									fseek(pm,2,SEEK_CUR);
									strcpy(coda,marcai.codigo+1);
									codig=atoi(coda);
									
									articulo.eliminado=0;
									fseek(pf,-tam,SEEK_CUR);
									fwrite(&articulo,sizeof(articulo),1,pf);
									puntero=codig*34;
									fseek(pc,puntero-34,SEEK_SET);
									fread(&categoriai,sizeof(categoriai),1,pc);
									categoriai.ban=0;
									fseek(pc,-taminc,SEEK_CUR);
									fwrite(&categoriai,sizeof(categoriai),1,pc);
									
									gotoxy(20,17);cout<<"El articulo fue Restaurado Exitosamente.";
								}
							}while(c!=EOF);
							if(enc==0)
							{
								gotoxy(20,15);cout<<"No se encontro ningun registro con ese nombre.";
							}
							Sleep(2000);
							break;
					case 51:do
							{
								system("cls");
								vali=0;
								enc=0;
								lon=0;
								y=10;
								fflush(stdin);
								memset(consulta,0,sizeof(consulta));
								gotoxy(20,13);cout<<"Seleccione la categoria del articulo.";
								gotoxy(20,15);cout<<"0.-Mica de cristal.";
								gotoxy(20,16);cout<<"1.-Protector silicon.";
								gotoxy(20,17);cout<<"2.-Cargador.";
								gotoxy(20,18);cout<<"3.-Memoria.";
								gotoxy(20,19);cout<<"4.-Cable USB.";
								gotoxy(20,20);cout<<"5.-Audifono.";
								gotoxy(20,21);cout<<"6.-Cable de Video.";
								gotoxy(20,22);cout<<"7.-Adaptador.";
								gotoxy(20,23);cout<<"8.-Holder para Coche.";
								gotoxy(20,24);cout<<"9.-Sim.";
								gotoxy(20,25);cout<<"A.-Bateria.";
								gotoxy(20,26);cout<<"B.-Otro.";
								selec=getch();
								if(selec==48)
								{
									strcpy(articulo.categoria,cristal);
									strcpy(categoriai.categoria,cristal);
								}
								else if(selec==49)
								{
									strcpy(articulo.categoria,tpu);
									strcpy(categoriai.categoria,tpu);
								}
								else if(selec==50)
								{
									strcpy(articulo.categoria,cargador);
									strcpy(categoriai.categoria,cargador);
								}	
								else if(selec==51)
								{
									strcpy(articulo.categoria,memoria);
									strcpy(categoriai.categoria,memoria);
								}
								else if(selec==52)
								{
									strcpy(articulo.categoria,cable);
									strcpy(categoriai.categoria,cable);
								}
								else if(selec==53)
								{
									strcpy(articulo.categoria,audifono);
									strcpy(categoriai.categoria,audifono);
								}
								else if(selec==54)
								{
									strcpy(articulo.categoria,cable2);
									strcpy(categoriai.categoria,cable2);
								}
								else if(selec==55)
								{
									strcpy(articulo.categoria,adaptador);
									strcpy(categoriai.categoria,adaptador);
								}
								else if(selec==56)
								{
									strcpy(articulo.categoria,holder);
									strcpy(categoriai.categoria,holder);
								}
								else if(selec==57)
								{
									strcpy(articulo.categoria,sim);
									strcpy(categoriai.categoria,sim);
								}
								else if(selec==65||selec==97)
								{
									strcpy(articulo.categoria,bateria);
									strcpy(categoriai.categoria,bateria);
								}
								else if(selec==66||selec==98)
								{
									strcpy(articulo.categoria,otro);
									strcpy(categoriai.categoria,otro);
								}
								else
								vali=1;
							}while(vali!=0);
							system("cls");
							gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
							y++;
							do
							{
								memset(&categoriai,0,sizeof(categoriai));
								fread(&categoriai,sizeof(categoriai),1,pc);
								for(int i=0; i < 2; i++)
								{
									c=fgetc(pc);
								}
								if(!strcmpi(consulta,categoriai.categoria)&&categoriai.ban==1)
								{
									strcpy(coda,categoriai.codigo+1);
									codig=atoi(coda);
									puntero=codig*106;
									fseek(pf,puntero-106,SEEK_SET);
									fread(&articulo,sizeof(articulo),1,pf);
									gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
									enc=1;
										do
									{	
										fflush(stdin);			
										gotoxy(20,15);cout<<"Son los datos que decea Restaurar? S/N ";
										c=getch();
										if(c!='n'&&c!='N'&&c!='s'&&c!='S')
										Beep(500,100);
									}while(c!='n'&&c!='N'&&c!='s'&&c!='S');
								}
								if(c=='s'||c=='S')
								{
									categoriai.ban=0;
									fseek(pc,-taminc-2,SEEK_CUR);
									fwrite(&categoriai,sizeof(categoriai),1,pc);
									fseek(pc,2,SEEK_CUR);
									strcpy(coda,categoriai.codigo+1);
									codig=atoi(coda);
									articulo.eliminado=0;
									fseek(pf,-tam,SEEK_CUR);
									fwrite(&articulo,sizeof(articulo),1,pf);
									puntero=codig*34;
									fseek(pm,puntero-34,SEEK_SET);
									fread(&marcai,sizeof(marcai),1,pm);
									marcai.ban=0;
									fseek(pm,-taminm,SEEK_CUR);
									fwrite(&marcai,sizeof(marcai),1,pm);
									
									gotoxy(20,17);cout<<"El articulo fue Restaurado Exitosamente.";
								}
							}while(c!=EOF);
							if(enc==0)
							{
								gotoxy(20,15);cout<<"No se encontro ningun registro con ese nombre.";
							}
							Sleep(2000);
							break; 
				}//fin de switch secundario
				break;
		case 50:contador=cod-1;
				do
				{
			 		system("cls");
					fflush(stdin);
					memset(&articulo,0,sizeof(articulo));
					fread(&articulo,sizeof(articulo),1,pf);
					for(int i=0; i < 2; i++)
					{
						c=fgetc(pf);
					}
					articulo.eliminado=0;
					fseek(pf,-tam-2,SEEK_CUR);
					fwrite(&articulo,sizeof(articulo),1,pf);
					fseek(pf,2,SEEK_CUR);
					strcpy(coda,articulo.codigo+1);
					codig=atoi(coda);
					puntero=codig*34;
					fseek(pm,puntero-34,SEEK_SET);
					fread(&marcai,sizeof(marcai),1,pm);
									
					marcai.ban=0;
					fseek(pm,-taminm,SEEK_CUR);
					fwrite(&marcai,sizeof(marcai),1,pm);
							
					fseek(pc,puntero-34,SEEK_SET);
					fread(&categoriai,sizeof(categoriai),1,pc);
					categoriai.ban=0;
					fseek(pc,-taminc,SEEK_CUR);
					fwrite(&categoriai,sizeof(categoriai),1,pc);
					contador--;				
				}while(contador!=0);
				gotoxy(20,5);cout<<"Restauracion Completa Realizada.";
				Sleep(4000);
				break;
	}//fin de switch principal
	fclose(pf);
	fclose(pm);
	fclose(pc);
}
///////////////////////////////TERMINA LA FUNCION PAPELERA DE RECICLAJE**************************************************************
///////////////////////////////INICIA LA FUNCION MERMAS******************************************************************************
void mermas()
{
	char merma[50],cant[5],coda[5],pago[10];
	int lonu=0,ban=0,vali=0,canti=0,codig=0,puntero=0,total=0,pagos=0,cambio=0,enc=0,y=10;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb+");
	pm=fopen("C:\\Users\\mary\\Documents\\proyecto\\Marcas_Articulos.bin","rb+");
	pc=fopen("C:\\Users\\mary\\Documents\\proyecto\\Categoria_Articulos.bin","rb+");
	pa=fopen("C:\\Users\\mary\\Documents\\proyecto\\Mermas.bin","ab+");	
		if(cod==1)
		{
			gotoxy(20,5);cout<<"NO a registrado articulos.";
			gotoxy(20,6);cout<<"Ingrese a la opcion de añadir articulo para registrar uno nuevo.";
			Sleep(4000);
		}
		else
		{
			do
			{
				enc=0;
				system("cls");
				gotoxy(20,5);cout<<"Bienvenido a la funcion para Reporte de Mermas.";
				gotoxy(20,7);cout<<"Ingrese el Articulo de Merma: ";
				gets(merma);
				lonu=strlen(merma);
				if(lonu>50)
				{
					ban=1;
					gotoxy(20,7);cout<<"Nombre de articulo no valido.";
					Sleep(1000);
				}
				if(lonu==0)
				{
					gotoxy(20,7);cout<<"No ingresaste nada.";
					Sleep(1000);
					ban=1;
				}
			}while(ban!=0);
			gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
			y++;
			do
			{
				memset(&articulo,0,sizeof(articulo));
				fread(&articulo,sizeof(articulo),1,pf);
				for(int i=0; i < 2; i++)
				{
					c=fgetc(pf);
				}
				if(!strcmpi(merma,articulo.nom)&&articulo.eliminado==0)
				{
					gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
					enc=1;
					do
					{			
						gotoxy(20,18);cout<<"Es el articulo que desea ingresar a merma? S/N ";
						c=getch();
						if(c!='n'&&c!='N'&&c!='s'&&c!='S')
						Beep(500,100);
					}while(c!='n'&&c!='N'&&c!='s'&&c!='S');					
					if(c=='s'||c=='S')
					{
						do
						{
							do
							{
								vali=0;
								system("cls");
								ban=0;
								memset(cant,0,sizeof(cant));
								gotoxy(20,20);cout<<"Ingrese la cantidad de articulos merma: ";
								gets(cant);
								if(strlen(cant)==0||strlen(cant)>10)
								{
									gotoxy(20,21);cout<<"Cantidad No valida.";
									vali=1;
									Sleep(1000);
								}
								canti=atoi(cant);
								if(canti==0||canti<0)
								{
									gotoxy(20,21);cout<<"Cantidad No valida.";
									vali=1;
									Sleep(1000);
								}
							}while(vali!=0);
							articulo.cantidad=articulo.cantidad-canti;
							if(articulo.cantidad<0)
							{
								gotoxy(20,21);cout<<"No hay "<<cant<<" en existencia.";
								articulo.cantidad=articulo.cantidad+canti;
								Sleep(2000);
								ban=1;
							}
						}while(ban!=0);
						fseek(pf,-tam-2,SEEK_CUR);
						fwrite(&articulo,sizeof(articulo),1,pf);
						fseek(pf,2,SEEK_CUR);
						do
						{
							memset(&articulo2,0,sizeof(articulo2));
							fread(&articulo2,sizeof(articulo2),1,pa);
							for(int i=0; i < 2; i++)
							{
								c3=fgetc(pa);
							}
						}while(c3!=EOF);
						fwrite(&articulo,sizeof(articulo),1,pa);
						fprintf(pa,"\r\n");
						
						
						gotoxy(20,26);cout<<"El Articulo a Sido Añadido a la Merma.";
						Sleep(2000);
					}//fin del if de haceptacion
				}//fin del if de strcmpi
			}while(c!=EOF);
			if(enc==0)
			{
				gotoxy(20,15);cout<<"No se encntro ningun registro con ese nombre.";
			}
			getch();
		}
	fclose(pf);
	fclose(pm);
	fclose(pc);
	fclose(pa);
}
///////////////////////////////TERMINA LA FUNCION MERMAS******************************************************************************
///////////////////////////////INICIA LA FUNCION FALTANTES*************************************************************************
void faltantes()
{
	int y=7;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb");
	if((pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Articulos.bin","rb")) == NULL)
	{
		cout << "¡No se encontro el archivo para la lectura!";
		exit(0);
		getch();
	}
	else
	{
		gotoxy(20,5);cout<<"Bienvenido a la Funcion Mostrar Faltantes.";
		gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
		y++;
		do
		{
			memset(&articulo,0,sizeof(articulo));
	        fread(&articulo,sizeof(articulo),1,pf);
	        for(int i=0; i < 2; i++)
			{
				c=fgetc(pf);
			}
			if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<5&&!strcmpi(cargador,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<2&&!strcmpi(memoria,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<5&&!strcmpi(cable,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<1&&!strcmpi(otro,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<5&&!strcmpi(audifono,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<2&&!strcmpi(cristal,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<2&&!strcmpi(tpu,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<2&&!strcmpi(cable2,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<3&&!strcmpi(adaptador,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<2&&!strcmpi(holder,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<4&&!strcmpi(sim,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
			else if(c!=EOF&&articulo.eliminado==0&&articulo.cantidad<1&&!strcmpi(bateria,articulo.categoria))
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
			}
		}while(c!=EOF);
		fclose(pa);
		getch();
	}
}
//////////////////////////////////TERMINA LA FUNCION FALTANTES*************************************************************************
//////////////////////////////////INICIA LA FUNCION MOSTRAR MERMAS***********************************************************************
void mostrar_mermas()
{
	int y=7;
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Mermas.bin","rb");
	if((pf = fopen("C:\\Users\\mary\\Documents\\proyecto\\Mermas.bin","rb")) == NULL)
	{
		cout << "¡No se encontro el archivo para la lectura!";
		exit(0);
		getch();
	}
	else
	{
		system("cls");
		gotoxy(20,5);cout<<"Bienvenido a la Funcion Mostrar Mermas.\n";
		gotoxy(15,y);cout<<"|CODIGO";gotoxy(25,y);cout<<"|NOMBRE";gotoxy(40,y);cout<<"|PRECIO";gotoxy(50,y);cout<<"|MARCA";gotoxy(65,y);cout<<"|CATEGORIA";gotoxy(85,y);cout<<"|CANTIDAD"<<endl;
		y++;
		do
		{
			memset(&articulo,0,sizeof(articulo));
	        fread(&articulo,sizeof(articulo),1,pf); 
	        for(int i=0; i < 2; i++)
			{
				c=fgetc(pf);
			}
			if(c!=EOF&&articulo.eliminado==0)
			{
				gotoxy(15,y);cout<<"|"<<articulo.codigo;gotoxy(25,y);cout<<"|"<<articulo.nom;gotoxy(40,y);cout<<"| $"<<articulo.precio;gotoxy(50,y);cout<<"|"<<articulo.marca;gotoxy(65,y);cout<<"|"<<articulo.categoria;gotoxy(85,y);cout<<"|"<<articulo.cantidad;
				y++;
	        }
		}while(c!=EOF);
		fclose(pf);
		getch();
	}
}
//////////////////////////////////TERMINA LA FUNCION MOSTAR MERMAS**************************************************************************
void edit (void)
{
setlocale(LC_CTYPE, "Spanish");
 int X = 0;
    int Y = 0;

    system("cls");

    char Line1[] = {"		 ---------------------------------------------------------------------------------   "};
    char Line2[] = {"		|				BBBBBBB      SSSSSSSS                             |  "};
    char Line3[] = {"		|				BBBBBBBB    SSSSSSSSSS                            |  "};
    char Line4[] = {"		|				BB    BB   SSSSS                                  |  "};
    char Line5[] = {"		|				BBBBBBB     SSSSSS                                |  "};
    char Line6[] = {"		|				BBBBBBB        SSSSSS                             |  "};
    char Line7[]= {"		|				BB    BB          SSSS                            |  "};
    char Line8[]= {"		|				BBBBBBBB   SSSSSSSSSS                             |  "};
    char Line9[]= {"		|				BBBBBBB     SSSSSSSS                              |  "};
   char Line10[]= {"		 ---------------------------------------------------------------------------------   "};
   char Line11[]= {"						Powered by:Jair Mendoza.                               "};
   char Line12[]= {"							V0.779 ALFA.                                     "};


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    gotoxy (X,Y+2);
    for (unsigned int i= 0; i < sizeof(Line1); i++)
    {
        cout << Line1[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+3);
    for (unsigned int i= 0; i < sizeof(Line2); i++)
    {
        cout << Line2[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+4);
    for (unsigned int i= 0; i < sizeof(Line3); i++)
    {
        cout << Line3[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+5);
    for (unsigned int i= 0; i < sizeof(Line4); i++)
    {
        cout << Line4[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+6);
    for (unsigned int i= 0; i < sizeof(Line5); i++)
    {
        cout << Line5[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+7);
    for (unsigned int i= 0; i < sizeof(Line6); i++)
    {
        cout << Line6[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+8);
    for (unsigned int i= 0; i < sizeof(Line7); i++)
    {
        cout << Line7[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+9);
    for (unsigned int i= 0; i < sizeof(Line8); i++)
    {
        cout << Line8[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+10);
    for (unsigned int i= 0; i < sizeof(Line9); i++)
    {
        cout << Line9[i];
        Sleep(Delay_us);
    }
     gotoxy (X,Y+11);
    for (unsigned int i= 0; i < sizeof(Line10); i++)
    {
        cout << Line10[i];
        Sleep(Delay_us);
    }
     gotoxy (X,Y+12);
    for (unsigned int i= 0; i < sizeof(Line11); i++)
    {
        cout << Line11[i];
        Sleep(Delay_us);
    }
     gotoxy (X,Y+13);
    for (unsigned int i= 0; i < sizeof(Line12); i++)
    {
        cout << Line12[i];
        Sleep(Delay_us);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}
/////////////////////////////////////////////////////////INICIA FUNCION RECARGA
void recarga()
{
	int vali=0,abono=0,abono1=0;
	char pre2[7];
	pf=fopen("C:\\Users\\mary\\Documents\\proyecto\\Recargas.bin","rb+");
	do
	{
		vali=0;
		memset(pre2,0,sizeof(pre2));
		system("cls");
		gotoxy(20,9);cout<<"Cantidad del Abono: ";
		gets(pre);
		if(strlen(pre)==0||strlen(pre)>10)
		{
			gotoxy(20,11);cout<<"Cantidad No valida";
			vali=1;
			Sleep(1000);
		}
		abono=atoi(pre);
		if(abono==0||abono<0)
		{
			gotoxy(20,11);cout<<"Abono no valido.";
			vali=1;
			Sleep(1000);
		}
	}while(vali!=0);
	memset(pre,0,sizeof(pre));
	fread(pre,sizeof(pre),1,pf);
	abono1=atoi(pre);
	abono1=abono1+abono;
	memset(pre,0,sizeof(pre));
	itoa(abono1,pre,10);
	fseek(pf,0,SEEK_SET);
	fwrite(pre,sizeof(pre),1,pf);
	gotoxy(20,13);cout<<"Abonado Correctamente.";
	Sleep(2000);
	fclose(pf);
	
}
///////////////////////////////////////////////////////////////TERMINA FUNCION RECARGA
