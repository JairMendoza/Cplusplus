# include <iostream>
# include <windows.h>
# include <conio.h>
# include <ctype.h>

using namespace std;

/**************** VARIABLES GLOBALES *****************/


/************ DECLARACIÓN (Prototipos) DE FUNCIONES ***************/
//Inicia estructura
typedef struct
{
	char codigo[10];
	char nombrealb[10];
	char nombreart[10];
	int publicacion;
	int numtracks;
	char genero[10];
	int tiempo;
	int ban;
}musica;
musica cd;
///////////////////////////////////////////////////////////////////
typedef struct
{
	char codigo2[10];
	char indalb[10];
	int ban1;
}index;
index indexal;
//////////////////////////////////////////////////////////////////
typedef struct
{
	char codigo3[10];
	char indar[10];
	int ban2;
}indexa;
indexa indexar;
/////////////////////////////////////////////////////////////////
typedef struct
{
	char codigo4[10];
	char indage[10];
	int ban3;
}indexag;
indexag indexge;
//////////////////////////////////////////////////////////////////////////
int tam=0, numreg=0, lon1=0, te, ban1;
///Variables
char c2[]="C00";
char c1[]="C0";
int bandera=0;
char cam[5];
char cam2[5];
int shar=1;
int am;
char menu (void);
char caracter='\0';//Capturo un solo caracter
char ext[30];//Mi contador para mi nombre
char auxx[30], auxxx[30], auxxxx[30];

FILE *pf, *ar, *pa, *pg;//Punteros
	int longitud=0;
//FUNCIONES
void gotoxy(int,int);
void codigo();
void alta();
void mostrar();
void error();
int crear();
void consulta();
void editar();
void eliminar();
int  er, amat;
int copy=0;
int main (){   // INICIO DEL MAIN
	//DECLARACIÓN DE VARIABLES
	tam=sizeof(cd);
	char opc;
	do { //Do principal- contiene la estructura general del programa
	
		opc= menu();
	
		switch (opc){
			char o;
			
			case 59: //F1
				
			 	system("cls");
			 	bandera=crear();
			 	getch();
				
				break;
				
			case 60://F2
				if(bandera==1)
				{
				system("cls");
			 	cout<<"Bienvenidos a la seccion para agregar registros al archivo"<<endl;
			 	alta();
			    }
			    else
			    {
			    	error();
				}
				getch();
				break;
				
			case 61://F3
				if(bandera==1)
				{
				system("cls");
			 	cout<<"Bienvenidos a la seccion para mostrar los registros"<<endl;
			 	mostrar();
			    }
			    else
			    {
			    	error();
				}
				getch();
				break;
				
			case 62://F4
				if(bandera==1)
				{
				system("cls");
			 	cout<<"Bienvenidos a la seccion para buscar registros"<<endl;
			 	consulta();
			    }
			    else
			    {
			    	error();
				}
				getch();
				break;
				
			case 63://F5
				if(bandera==1)
				{
				system("cls");
			 	cout<<"Bienvenidos a la seccion para editar registros"<<endl;
				editar();
				
			    }
			    else
			    {
			    	error();
				}
				getch();
				break;
				
			case 64://F6
				
				if(bandera==1)
				{
				system("cls");
			 	cout<<"Bienvenidos a la seccion para editar registros"<<endl;
				eliminar();
				
			    }
			    else
			    {
			    	error();
				}
				getch();
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
			
		
	}while(opc !=27);

	return 0;	

}//FIN DEL MAIN


/*****************     FUNCIONES     ****************/

//FUNCION MENU ++++++++++++++++++++++++++++++++++++++++++++++
char menu(){
	
	char opc1 = '\0'; //Declaracion de variable local para manejo de la opcion
	
	system("cls");
	
	gotoxy(28,3); cout<<"Menu Agenda";
	gotoxy(28,5); cout<<"[F1] Crear o abrir archivo";
	gotoxy(28,6); cout<<"[F2] Agregar Registros del CD";
	gotoxy(28,7); cout<<"[F3] Mostrar Registros del CD";
	gotoxy(28,8); cout<<"[F4] Buscar Registro del CD";
	gotoxy(28,9); cout<<"[F5] Modificar Registro del CD";
	gotoxy(28,10);cout<<"[F6] Eliminar Registro del CD";
	gotoxy(28,11);cout<<"ESC. Salir";
	gotoxy(28,13);cout<<"Seleccione una opcion: ";
	
	//Captura de la opcion
	opc1 = getch();
	
	if (opc1==0){
		
		opc1 = getch();
	}
	
	return opc1;//Retornar la opcion ingresada
	
	
}

//FUNCION GOTOXY ++++++++++++++++++++++++++++++++++++++++++++
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 int crear()
 {
 	int contador=0, ban=0, aux;
 	memset(ext,0,sizeof(ext));
 	int lon3=0;
 	char indice[30]={"Indice Album "};
 	char indice1[30]={"Indice Artista "};
 	char indice2[30]={"Indice Genero "};

 	do
	{
		do
		{
			system("cls");
			printf("Que archivo desea abrir?: " );
			fflush(stdin);
			gets(ext);
			strcat(indice,ext);
	        strcpy(auxx,indice);
	        strcat(indice1,ext);
	        strcpy(auxxx,indice1);
	        strcat(indice2,ext);
	        strcpy(auxxxx,indice2);
			unsigned int i;
			lon3=strlen(ext);
			aux=0;
		    for(int x=0; x<lon3; x++)
			   {
			   	  if(ext[lon3-4]=='.' && ext[lon3-3]=='b' && ext[lon3-2]=='i' && ext[lon3-1]=='n')
			   	  {
			   	  	ban=0;
				  }
				  else
				  {
				  	ban=1;
				  }
			   }
		}while(ban == 1);
		if (lon3 == 0)
		{
	    	aux=1;
	    	printf("Cadena vacia. \n");
		}
		if(isspace(lon3))
		{
			aux=1;
			printf("Error. \n");
		}
	}while(aux == 1);
	
    pf=fopen(ext, "rb");//Leeo mis archivos en modo binario
    ar=fopen(auxx, "rb");
    pa=fopen(auxxx, "rb");
     pg=fopen(auxxxx, "rb");
    if(pf==NULL)//Si no existe lo creara.
    {
       pf=fopen(ext, "wb");
       ar=fopen(auxx, "wb");
       pa=fopen(auxxx, "wb");
        pg=fopen(auxxxx, "rb");
       printf("Si no se encontro un archivo existente, automaticamente se creara uno. ");
	   contador=1;	
	  
	}
	
    else
    {
    	printf("Se encontro su archivo. \n");
    	if(cd.codigo!='\0')
		{
    	   do
    	   {
    		caracter=fgetc(pf);
    	    contador++;	
		   }while(caracter!=EOF);
			numreg=contador/tam;
			shar=numreg;
	    }
	 
	}
	fclose(pf);
	fclose(ar);
	return 1;
 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 void alta()
 {
 		int ban, lon, aux, lon1, te, ban1, rango, longe;
 			int convertidor, convertidor2, convertidor3;
 	char cod1[5];
 	char cod[5]="C00";
 	int num=0;
    pf= fopen(ext,"ab+");
    ar=fopen(auxx,"ab+");
    pa=fopen(auxxx,"ab+");
	pg=fopen(auxxxx,"ab+");
   
 		if(pf==NULL)
		{//Comprobar la apertura correcta del archivo
		perror ("No fue posible crear el archivo para escritura");//Envio error al usuario
		exit(0);//Salir del programa
		}//Cierra flujo
		
   	
	do
	{
	   system("cls");		//Limpieza de contenedores	
	   memset(&cd,0,sizeof(cd));
	   memset(cod1,0,sizeof(cod1));
	        if(shar==156)
	        shar=1;
 	  	    char c1[]="C00";
	   	  	char c[]="C0";
		
			itoa(shar,cam,10);
            longitud=strlen(cam);
	        itoa(longitud,cam2,10);
	        longitud=strlen(cam2);
	        if(longitud==1)
		    {        	
		        strcpy(cam,strcat(c1,cam));
			}
			if(longitud==2)
		    {
            	strcpy(cam,strcat(c,cam));
			}
			strcpy(cd.codigo,cam);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		fflush(stdin);
	   cout<<"\n\nCodigo: "<<cd.codigo<<endl;
	 do
	   {  
	   memset(cd.nombrealb,0,sizeof(cd.nombrealb));
	   cout<<"Nombre del album. \n";fflush(stdin);
	   gets(cd.nombrealb);
		 lon=strlen(cd.nombrealb);
		 if(lon > 10)
			{
				cout<<"\nLongitud invalida\n";
				getch();
			}
			        aux = 0;
					for(int i = 0; i < lon; i++)
					{
						if(isalnum(cd.nombrealb[i]) || isspace(cd.nombrealb[i]))
					    ban = 0;
					    else
						{
					    ban = 1;
					    break;
					    }
				    }
				    if(ban == 1)
				    {
				   	    cout << "Error!" << endl;
				   	    getch();
				    }
				    	if (lon == 0)
					{
					   	aux = 1;
					   	cout << "Campo vacio!" << endl;
					   	getch();
					}
		}while(ban == 1||lon==0 ||lon>10);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   do
	   {
	   cout<<"Nombre del artista. \n";fflush(stdin);
	   gets(cd.nombreart);
	   if(lon > 10)
			{
				cout<<"\nError\n";
			}
	   lon=strlen(cd.nombreart);
			        aux = 0;
					for(int i = 0; i < lon; i++)
					{
						if(isalpha(cd.nombreart[i]) || isspace(cd.nombreart[i]))
					    ban = 0;
					    else
						{
					    ban = 1;
					    break;
					    }
				    }
				    if(ban == 1)
				    {
				   	    cout << "Solo letras!" << endl;
				   	    getch();
				    }
				    	if (lon == 0)
					{
					   	aux = 1;
					   	cout << "Campo vacio!" << endl;
					   	getch();
					}
		}while(ban == 1||lon==0);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
	   do
	   { 
	   
	   char year[10];
	   convertidor=0;
	   memset(year,0,sizeof(year));
	   cout<<"Fecha. \n"; 
	   fflush(stdin);
	   gets(year);
		 lon1=strlen(year);
		    	te=0;
					for(int i=0;i<lon1;i++)
					{
						if(isdigit(year[i]))
					    ban1=0;
					    else
						{
					    ban1=1;
					    break;
					    }
				    }
		    if(ban1==1)
		    {
		   	    printf("Digite numeros \n");
		   	    getch();
	   	    }
	   	    	if (lon1 == 0)
					{
					   	aux = 1;
					   	cout << "Campo vacio!" << endl;
					   	getch();
					}	
			convertidor=atoi(year);
			if(convertidor<1900||convertidor>2018)
			ban1=3;		
			if(ban1==3)
			{
				cout<<"Fecha invalida. Ejemplo: 1900-2018"<<endl;
				getch();
			}

	   	    }while(ban1==1 || lon1==0||ban1==3 ||lon1>10);
	   	    cd.publicacion=convertidor;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
     do
	   { 
	   
	   char tie[10];
	   memset(tie,0,sizeof(tie));
	   fflush(stdin);
	  convertidor2=0;
	   cout<<"Duracion. \n";
	   gets(tie);
	   if(lon>10)
			{
				cout<<"\nError\n";
			}
		 lon=strlen(tie);
			        aux = 0;
					for(int i = 0; i < lon; i++)
					{
						if(isdigit(tie[i]) || isspace(tie[i]) || tie[i]==':')
					    ban = 0;
					    else
						{
					    ban = 1;
					    break;
					    }
				    }

				    	if (lon == 0)
					{
					   	aux = 1;
					   	cout << "Campo vacio!" << endl;
					   	getch();
					}
						 convertidor2=atoi(tie);
			if( convertidor2<1|| convertidor2>120)
			ban=3;		
			if(ban==3)
			{
				cout<<"Maximo de tiempo."<<endl;
				getch();
			}
					
		}while(ban == 1||lon==0 ||ban==3|| lon>10);
		cd.tiempo=convertidor2;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	  do
	   {
	   	convertidor3=0;
	   
	   	char dur[10];
	   		memset(dur,0,sizeof(dur));
	   	fflush(stdin);
	   cout<<"Numero de tracks. \n";
	   gets(dur);
	   if(lon1 > 10)
			{
				cout<<"\nError\n";
			}
	   lon1=strlen(dur);
		    	te=0;
					for(int i=0;i<lon1;i++)
					{
						if(isdigit(dur[i]))
					    ban1=0;
					    else
						{
					    ban1=1;
					    break;
					    }
				    }
		    if(ban1==1)
		    {
		   	    printf("Digite numeros \n");
		   	    getch();
	   	    }
	   	    	if (lon1 == 0)
					{
					   	aux = 1;
					   	cout << "Campo vacio!" << endl;
					   	getch();
					}	
			convertidor3=atoi(dur);
			if(convertidor3<0||convertidor3>200)
			ban1=3;		
			if(ban1==3)
			{
				cout<<"Fuera del rango."<<endl;
				getch();
			}

	   	    }while(ban1==1 || lon1==0||ban1==3 ||lon1>10);
	   	    cd.numtracks=convertidor3;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
	   do
	   {
	   	fflush(stdin);
        er=1;
	    cout<<"Seleccione genero\n";
	    cout<<"1.-Blues\n";
	    
	    cout<<"2.-Pop\n";
	    cout<<"3.-Clasico\n";
	    cout<<"4.-Opera\n";
	    cout<<"5.-Jazz\n";
	    cout<<"6.-Rock\n";
		cin>>amat;
		if(amat<1||amat>6)
			er=0;
		}while(amat<1|amat>6);
			if(amat==1)
			{
				fflush(stdin);
				char blu[]="Blues";
				strcpy(cd.genero,blu);
			}
			if(amat==2)
			{
				fflush(stdin);
				char ele[]="Pop";
				strcpy(cd.genero,ele);
			}
			if(amat==3)
			{
				fflush(stdin);
				char hea[]="Clasico";
				strcpy(cd.genero,hea);
			}
			if(amat==4)
			{
				fflush(stdin);
				char hip[]="Opera";
				strcpy(cd.genero,hip);
			}
			if(amat==5)
			{
				fflush(stdin);
				char jaz[]="Jazz";
				strcpy(cd.genero,jaz);
			}
			if(amat==6)
			{
				fflush(stdin);
				char roc[]="Rock";
				strcpy(cd.genero,roc);
			}
       cd.ban=0;
       indexal.ban1=0;
       indexar.ban2=0;
       indexge.ban3=0;
       
       fwrite(&cd,sizeof(cd),1,pf); 
       fprintf(pf,"\r\n");
       
       fwrite(&cd.codigo,sizeof(indexal.codigo2),1,ar);
       fwrite(&cd.nombrealb,sizeof(indexal.indalb),1,ar);
	   fwrite(&cd.ban,sizeof(indexal.ban1),1,ar); 
       fprintf(ar,"\r\n");
       
       fwrite(&cd.codigo,sizeof(indexar.codigo3),1,pa);
       fwrite(&cd.nombreart,sizeof(indexar.indar),1,pa);
	   fwrite(&cd.ban,sizeof(indexar.ban2),1,pa);  
       fprintf(pa,"\r\n");
       
        fwrite(&cd.codigo,sizeof(indexge.codigo4),1,pg);
       fwrite(&cd.genero,sizeof(indexge.indage),1,pg);
	   fwrite(&cd.ban,sizeof(indexge.ban3),1,pg);
       fprintf(pg,"\r\n");
       

      
	   do
	   {
	   	   printf("Desea agregar mas registros? S-N");
	   	   caracter=getch();
	   	   if(caracter!='S'&& caracter!='s'&& caracter!='N' && caracter!='n')
	   	   {
	   	       Beep(500,100);  	
		   }
	   }while(caracter!='S'&& caracter!='s'&& caracter!='N'&&caracter!='n');
	   
        shar++;
	}while(caracter=='S'||caracter=='s');
	fclose(pf);//Cierro flujo*/
	fclose(ar);
	fclose(pa);
	fclose(pg);
 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 void mostrar()
 {
 	memset(&cd,0,sizeof(cd));
 	pf=fopen(ext, "rb");//Leeo mis archivos en modo binario
 	ar=fopen(auxx, "rb");
 	pa=fopen(auxxx,"rb");
 	pg=fopen(auxxxx,"rb");
    if(pf==NULL)
    {
    	perror ("No fue posible crear el archivo para escritura");//Envio error al usuario
		exit(0);//Salir del programa
	}
	fflush(stdin);
    do
				{
					memset(&cd,0,sizeof(cd));
			        fread(&cd,sizeof(cd),1,pf);
			      
			        for(int i=0; i < 2; i++)
					{
						caracter=fgetc(pf);
					}
						if(!feof(pf)&&cd.ban==0)
						{
						    	cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;	
				        }
				}while(caracter!=EOF);
  	

  fclose(pf);
  fclose(pa);
  fclose(ar);
  fclose(pg);
 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 void consulta()
 {
 	char op;
 	int ba=0;
 	int cod2=0, puntero=0; 
	char coda[10];
	 int longbus=0;
	 int longbus2=0;
	pf=fopen(ext, "rb");//Leeo mis archivos en modo binario
	ar=fopen(auxx,"rb");//Leeo mis archivos en modo binario
	pa=fopen(auxxx,"rb");//Leo mis archivos en modo binario
	pg=fopen(auxxxx,"rb");//Leo mis archivos en modo binario
    if(pf==NULL)
    {
    	perror ("No fue posible crear el archivo para escritura");//Envio error al usuario
		exit(0);//Salir del programa
	}
//	do
//	{
		
	do
	{
		fflush(stdin);
		system("cls");
		 
		cout<<"Ingrese la opcion para ejecutar la busqueda. "<<endl;
		cout<<"1.-Indice album. "<<endl;
		cout<<"2.-Indice artista. "<<endl;
		cout<<"3.-Indice genero. "<<endl;
		cout<<"ESC. Para volver al menu. "<<endl;
		cout<<"ELIGA OPCION. "<<endl;
      	op=getch();
	    switch(op)
	    {
		    case '1':  fseek(ar,0,SEEK_SET);
			          char consulta[10];
		              memset(coda,0,sizeof(coda));
		              cout<<"Ingrese el nombre que desea buscar. "<<endl;fflush(stdin);
		              memset(consulta,0,sizeof(consulta));
		              gets(consulta);
		              longbus=strlen(consulta);
		              if(longbus==0)
		              {
		              	 cout<<"Vacio. ";
					  }
					  else
					  {
		              do
		              {
		                    memset(&indexal,0,sizeof(indexal));	
				            memset(&indexal,0,sizeof(indexal));
							memset(&cd,0,sizeof(cd));
		              	 	fread(&indexal,sizeof(indexal),1,ar);
		              	 		for(int i=0; i <2; i++)
							{
								caracter=fgetc(ar);
							}
		              	 	if(!strcmpi(consulta, indexal.indalb))
		              	 	{
		              	 		strcpy(coda,indexal.codigo2+1);
		              	 		cod2=atoi(coda);
		              	 		puntero=(cod2)*62;
		              	 		fseek(pf,puntero-62,SEEK_SET);
		              	 		fread(&cd, sizeof(cd),1,pf);
		              	 		if(cd.ban==0)
		              	 		{
	              	 			cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;
		        	            }
						 }
					  }while(!feof(ar));
		            }
		            getch();
			        break;
			 //////////////////////////////////////////////////////////////////////////////////////////    
			 case '2':  fseek(pa,0,SEEK_SET);
			          char consulta2[10];
		              memset(coda,0,sizeof(coda));
		              cout<<"Ingrese el nombre que desea buscar. "<<endl;fflush(stdin);
		              memset(consulta2,0,sizeof(consulta2));
		              gets(consulta2);
		              longbus2=strlen(consulta2);
		              if(longbus2==0)
		              {
		              	 cout<<"Vacio. ";
					  }
					  else
					  {
		              do
		              {
		                    memset(&indexar,0,sizeof(indexar));	
				            memset(&indexar,0,sizeof(indexar));
							memset(&cd,0,sizeof(cd));
		              	 	fread(&indexar,sizeof(indexar),1,pa);
		              	 		for(int i=0; i <2; i++)
							{
								caracter=fgetc(pa);
							}
		              	 	if(!strcmpi(consulta2, indexar.indar))
		              	 	{
		              	 		strcpy(coda,indexar.codigo3+1);
		              	 		cod2=atoi(coda);
		              	 		puntero=(cod2)*62;
		              	 		fseek(pf,puntero-62,SEEK_SET);
		              	 		fread(&cd, sizeof(cd),1,pf);
		              	 			if(cd.ban==0)
		              	 		{
	              	 			cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;
							    }
		        		
							}
						
					  }while(!feof(pa));
		           }
			             getch();
			             break;
		case '3': pg=fopen(auxxxx,"rb");
		           char buscar[10];
		              memset(coda,0,sizeof(coda));
		              int bus2=0;
		              cout<<"Ingrese el nombre que desea buscar. "<<endl;fflush(stdin);//Limpio buffer
		              memset(buscar,0,sizeof(buscar));
		              gets(buscar);
		              bus2=strlen(buscar);//Mido la longitud-
		              if(bus2==0)//Si mi longitud es 0: Marco que mi cadena esta vacia
		              {
		              	 cout<<"Vacio. ";
					  }
					  else
					  {
					   do
		              {
		                    memset(&indexge,0,sizeof(indexge));	
				            memset(&indexge,0,sizeof(indexge));
							memset(&cd,0,sizeof(cd));
		              	 	fread(&indexge,sizeof(indexge),1,pg);
		              	 		for(int i=0; i <2; i++)
							{
								caracter=fgetc(pg);
							}
		              	 	if(!strcmpi(buscar, indexge.indage))
		              	 	{
		              	 		strcpy(coda,indexge.codigo4+1);
		              	 		cod2=atoi(coda);
		              	 		puntero=(cod2)*62;
		              	 		fseek(pf,puntero-62,SEEK_SET);
		              	 		fread(&cd, sizeof(cd),1,pf);
		              	 			if(cd.ban==0)
		              	 		{
	              	 			cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;
							  }
							}
					  }while(!feof(pg));	 
				      }
					  getch();
					  break;
			        	  
					  		
	    }
//	    	do
//			{
//				system("cls");
//				gotoxy(10,10);
//				cout<<"Decea buscar mas albums? S/N ";
//				caracter=getch();
//				if(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S')
//				Beep(500,100);
//			}while(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S');
//			 
//    }while(caracter=='s'||caracter=='S');
    }while(op!=27);
   

	fclose(pf);
	fclose(ar);
	fclose(pa);
	fclose(pg);
//	if(conta==0)
//		{
//			cout<<"No se encontro el cd.\n";
//			getch();
//		}
 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 void editar()
 {
 	char op;
 	int ba=0;
 	int cod2=0, puntero=0, punteroar=0, punteroge=0;  
	char coda[10];
	 int longbus=0;
	 int longbus2=0;
	 int lon=0, aux=0, ban=0;
	 int convertidor=0, convertidor2=0, convertidor3=0;
	pf=fopen(ext, "rb+");//Leeo mis archivos en modo binario
	ar=fopen(auxx,"rb+");//Leeo mis archivos en modo binario
	pa=fopen(auxxx,"rb+");//Leo mis archivos en modo binario
	pg=fopen(auxxxx,"rb+");//Leo mis archivos en modo binario
    if(pf==NULL)
    {
    	perror ("No fue posible crear el archivo para escritura");//Envio error al usuario
		exit(0);//Salir del programa
	}
//	do
//	{
		
	do
	{
		fflush(stdin);
		system("cls");
		 
		cout<<"Ingrese la opcion para ejecutar la busqueda. "<<endl;
		cout<<"1.-Indice album. "<<endl;
		cout<<"2.-Indice artista. "<<endl;
		cout<<"3.-Indice genero. "<<endl;
		cout<<"ESC. Para volver al menu. "<<endl;
		cout<<"ELIGA OPCION. "<<endl;
      	op=getch();
	    switch(op)
	    {
		    case '1':  fseek(ar,0,SEEK_SET);
			          char consulta[10];
		              memset(coda,0,sizeof(coda));
		              cout<<"Ingrese el nombre el album que desea editar. "<<endl;fflush(stdin);
		              memset(consulta,0,sizeof(consulta));
		              gets(consulta);
		              longbus=strlen(consulta);
		              if(longbus==0)
		              {
		              	 cout<<"Vacio. ";
					  }
					  else
					  {
		              do
		              {
		                    memset(&indexal,0,sizeof(indexal));	
				            memset(&indexal,0,sizeof(indexal));
							memset(&cd,0,sizeof(cd));
		              	 	fread(&indexal,sizeof(indexal),1,ar);
		              	 		for(int i=0; i <2; i++)
							{
								caracter=fgetc(ar);
							}
							
		              	 	if(!strcmpi(consulta, indexal.indalb))
		              	 	{
		              	 		strcpy(coda,indexal.codigo2+1);
		              	 		cod2=atoi(coda);
		              	 		puntero=(cod2)*62;
		              	 		fseek(pf,puntero-62,SEEK_SET);
		              	 		fread(&cd, sizeof(cd),1,pf);
		              	 		if(cd.ban==0)
		              	 		{
	              	 			cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;
							  	do
						        {			
										cout<<"\nSon los datos que decea modificar? S/N "<<endl;
										caracter=getch();
										if(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S')
										Beep(500,100);
						       }while(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S');
						if(caracter=='s'||caracter=='S')
						{
								int opc=0;
								do
								{
								memset(&indexal,0,sizeof(indexal));
								memset(coda,0,sizeof(coda));
								strcpy(coda,cd.codigo+1);
								cod2=atoi(coda);
								puntero=(cod2)*26;
								punteroar=(cod2)*26;
								punteroge=(cod2)*26;
		              	 		fseek(ar,puntero-26,SEEK_SET);
		              	 		fread(&indexal, sizeof(indexal),1,ar);
		              	 		fseek(pa,punteroar-26,SEEK_SET);
		              	 		fread(&indexar, sizeof(indexar),1,pa);
		              	 		fseek(pg,puntero-26,SEEK_SET);
		              	 		fread(&indexge, sizeof(indexge),1,pg);
		              	 		cout<<"Que campo desea editar. "<<endl;
		              	 		cout<<"1.-Nombre del album. "<<endl;
		              	 		cout<<"2.-Nombre del artista. "<<endl;
		              	 		cout<<"3.-Year. "<<endl;
		              	 		cout<<"4.-Duracion. "<<endl;
		              	 		cout<<"5.-track. "<<endl;
		              	 		cout<<"6.genero. "<<endl;
		              	 		cout<<"Eliga una opcion. "<<endl;
		              	 		cin>>opc;
								system("cls");
								if(opc!=1&&opc!=2&&opc!=3&&opc!=4&&opc!=5&&opc!=6)
								Beep(500,100);
								}while(opc!=1&&opc!=2&&opc!=3&&opc!=4&&opc!=5&&opc!=6);
								switch(opc)
								{
								 case 1: 
		              	 		              do
										   {  
										   memset(cd.nombrealb,0,sizeof(cd.nombrealb));
		              	 		            memset(indexal.indalb,0,sizeof(indexal.indalb));
										   memset(cd.nombrealb,0,sizeof(cd.nombrealb));
										   cout<<"Nombre del album. \n";fflush(stdin);
										   gets(cd.nombrealb);
											 lon=strlen(cd.nombrealb);
											 if(lon > 10)
												{
													cout<<"\nLongitud invalida\n";
													getch();
												}
												        aux = 0;
														for(int i = 0; i < lon; i++)
														{
															if(isalnum(cd.nombrealb[i]) || isspace(cd.nombrealb[i]))
														    ban = 0;
														    else
															{
														    ban = 1;
														    break;
														    }
													    }
													    if(ban == 1)
													    {
													   	    cout << "Error!" << endl;
													   	    getch();
													    }
													    	if (lon == 0)
														{
														   	aux = 1;
														   	cout << "Campo vacio!" << endl;
														   	getch();
														}
												
											}while(ban == 1||lon==0 ||lon>10);
											strcpy(indexal.indalb,cd.nombrealb);
										    fseek(ar,-24,SEEK_CUR);
											fwrite(&indexal,sizeof(indexal),1,ar);
											fseek(ar,24,SEEK_CUR);
											system("cls");
	
											         cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
													    case 2:   do
									   {
									   	 memset(cd.nombreart,0,sizeof(cd.nombreart));
		              	 		            memset(indexar.indar,0,sizeof(indexar.indar));
									   cout<<"Nombre del artista. \n";fflush(stdin);
									   gets(cd.nombreart);
									   if(lon > 10)
											{
												cout<<"\nError\n";
											}
									   lon=strlen(cd.nombreart);
											        aux = 0;
													for(int i = 0; i < lon; i++)
													{
														if(isalpha(cd.nombreart[i]) || isspace(cd.nombreart[i]))
													    ban = 0;
													    else
														{
													    ban = 1;
													    break;
													    }
												    }
												    if(ban == 1)
												    {
												   	    cout << "Solo letras!" << endl;
												   	    getch();
												    }
												    	if (lon == 0)
													{
													   	aux = 1;
													   	cout << "Campo vacio!" << endl;
													   	getch();
													}
										}while(ban == 1||lon==0);
										strcpy(indexar.indar,cd.nombreart);
										    fseek(pa,-24,SEEK_CUR);
											fwrite(&indexar,sizeof(indexar),1,pa);
											fseek(pa,24,SEEK_CUR);
											system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
			                    case 3:  do
								   { 
								   
								   char year[10];
								   convertidor=0;
								   memset(year,0,sizeof(year));
								   cout<<"Fecha. \n"; 
								   fflush(stdin);
								   gets(year);
									 lon1=strlen(year);
									    	te=0;
												for(int i=0;i<lon1;i++)
												{
													if(isdigit(year[i]))
												    ban1=0;
												    else
													{
												    ban1=1;
												    break;
												    }
											    }
									    if(ban1==1)
									    {
									   	    printf("Digite numeros \n");
									   	    getch();
								   	    }
								   	    	if (lon1 == 0)
												{
												   	aux = 1;
												   	cout << "Campo vacio!" << endl;
												   	getch();
												}	
										convertidor=atoi(year);
										if(convertidor<1900||convertidor>2018)
										ban1=3;		
										if(ban1==3)
										{
											cout<<"Fecha invalida. Ejemplo: 1900-2018"<<endl;
											getch();
										}
							
								   	    }while(ban1==1 || lon1==0||ban1==3 ||lon1>10);
								   	    cd.publicacion=convertidor;	
										   	system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
				                  case 4:  do
										   { 
										   
										   char tie[10];
										   memset(tie,0,sizeof(tie));
										   fflush(stdin);
										  convertidor2=0;
										   cout<<"Duracion. \n";
										   gets(tie);
										   if(lon>10)
												{
													cout<<"\nError\n";
												}
											 lon=strlen(tie);
												        aux = 0;
														for(int i = 0; i < lon; i++)
														{
															if(isdigit(tie[i]) || isspace(tie[i]) || tie[i]==':')
														    ban = 0;
														    else
															{
														    ban = 1;
														    break;
														    }
													    }
									
													    	if (lon == 0)
														{
														   	aux = 1;
														   	cout << "Campo vacio!" << endl;
														   	getch();
														}
															 convertidor2=atoi(tie);
												if( convertidor2<1|| convertidor2>120)
												ban=3;		
												if(ban==3)
												{
													cout<<"Maximo de tiempo."<<endl;
													getch();
												}
														
											}while(ban == 1||lon==0 ||ban==3|| lon>10);
											cd.tiempo=convertidor2;	
												system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
								case 5:					  do
										   {
										   	convertidor3=0;
										   
										   	char dur[10];
										   	memset(dur,0,sizeof(dur));
										   	fflush(stdin);
										    cout<<"Numero de tracks. \n";
										    gets(dur);
										    if(lon1 > 10)
												{
													cout<<"\nError\n";
												}
										   lon1=strlen(dur);
											    	te=0;
														for(int i=0;i<lon1;i++)
														{
															if(isdigit(dur[i]))
														    ban1=0;
														    else
															{
														    ban1=1;
														    break;
														    }
													    }
											    if(ban1==1)
											    {
											   	    printf("Digite numeros \n");
											   	    getch();
										   	    }
										   	    	if (lon1 == 0)
														{
														   	aux = 1;
														   	cout << "Campo vacio!" << endl;
														   	getch();
														}	
												convertidor3=atoi(dur);
												if(convertidor3<0||convertidor3>200)
												ban1=3;		
												if(ban1==3)
												{
													cout<<"Fuera del rango."<<endl;
													getch();
												}
									
										   	    }while(ban1==1 || lon1==0||ban1==3 ||lon1>10);
										   	    cd.numtracks=convertidor3;	
												 system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\tPresione enter. "<<endl;
													  break;
								case 6:		do
									   {
									   	fflush(stdin);
								        er=1;
									    cout<<"Seleccione genero\n";
									    cout<<"1.-Blues\n";
									    cout<<"2.-Pop\n";
									    cout<<"3.-Clasico\n";
									    cout<<"4.-Opera\n";
									    cout<<"5.-Jazz\n";
									    cout<<"6.-Rock\n";
										cin>>amat;
										if(amat<1||amat>6)
											er=0;
										}while(amat<1|amat>6);
											if(amat==1)
											{
												fflush(stdin);
												char blu[]="Blues";
												strcpy(cd.genero,blu);
											}
											if(amat==2)
											{
												fflush(stdin);
												char ele[]="Pop";
												strcpy(cd.genero,ele);
											}
											if(amat==3)
											{
												fflush(stdin);
												char hea[]="Clasico";
												strcpy(cd.genero,hea);
											}
											if(amat==4)
											{
												fflush(stdin);
												char hip[]="Opera";
												strcpy(cd.genero,hip);
											}
											if(amat==5)
											{
												fflush(stdin);
												char jaz[]="Jazz";
												strcpy(cd.genero,jaz);
											}
											if(amat==6)
											{
												fflush(stdin);
												char roc[]="Rock";
												strcpy(cd.genero,roc);
											}
												memset(&indexge,0,sizeof(indexge));
											strcpy(indexge.indage,cd.genero);
										    fseek(pg,-22,SEEK_CUR);
											fwrite(&indexge,sizeof(indexge),1,pg);
											fseek(pg,22,SEEK_CUR);
											system("cls");
	
											         cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\tPresione enter. "<<endl;
													  break;			    							  						
							      }//Cierra switch
							
						   
			
								fseek(pf,-60,SEEK_CUR);
								fwrite(&cd,sizeof(cd),1,pf);
								fseek(pf,60,SEEK_CUR);
									
						}
		        	 }
					}
					
					  }while(!feof(ar));
		            }
		            getch();
			        break;
			 //////////////////////////////////////////////////////////////////////////////////////////    
			 case '2': fseek(pa,0,SEEK_SET);
			          char consulta1[10];
		              memset(coda,0,sizeof(coda));
		              cout<<"Ingrese el nombre el album que desea editar. "<<endl;fflush(stdin);
		              memset(consulta1,0,sizeof(consulta1));
		              gets(consulta1);
		              longbus=strlen(consulta1);
		              if(longbus==0)
		              {
		              	 cout<<"Vacio. ";
					  }
					  else
					  {
		              do
		              {
		                    memset(&indexar,0,sizeof(indexar));	
				            memset(&indexar,0,sizeof(indexar));
							memset(&cd,0,sizeof(cd));
		              	 	fread(&indexar,sizeof(indexar),1,pa);
		              	 		for(int i=0; i <2; i++)
							{
								caracter=fgetc(pa);
							}
							
		              	 	if(!strcmpi(consulta1, indexar.indar))
		              	 	{
		              	 		strcpy(coda,indexar.codigo3+1);
		              	 		cod2=atoi(coda);
		              	 		puntero=(cod2)*62;
		              	 		fseek(pf,puntero-62,SEEK_SET);
		              	 		fread(&cd, sizeof(cd),1,pf);
		              	 		if(cd.ban==0)
		              	 		{
	              	 			cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;
							  	do
						        {			
										cout<<"\nSon los datos que decea modificar? S/N "<<endl;
										caracter=getch();
										if(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S')
										Beep(500,100);
						       }while(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S');
						if(caracter=='s'||caracter=='S')
						{
								int opc=0;
								do
								{
								memset(&indexal,0,sizeof(indexal));
								memset(coda,0,sizeof(coda));
								strcpy(coda,cd.codigo+1);
								cod2=atoi(coda);
								puntero=(cod2)*26;
								punteroar=(cod2)*26;
								punteroge=(cod2)*26;
		              	 		fseek(ar,puntero-26,SEEK_SET);
		              	 		fread(&indexal, sizeof(indexal),1,ar);
		              	 		fseek(pa,punteroar-26,SEEK_SET);
		              	 		fread(&indexar, sizeof(indexar),1,pa);
		              	 		fseek(pg,puntero-26,SEEK_SET);
		              	 		fread(&indexge, sizeof(indexge),1,pg);
		              	 		cout<<"Que campo desea editar. "<<endl;
		              	 		cout<<"1.-Nombre del album. "<<endl;
		              	 		cout<<"2.-Nombre del artista. "<<endl;
		              	 		cout<<"3.-Year. "<<endl;
		              	 		cout<<"4.-Duracion. "<<endl;
		              	 		cout<<"5.-track. "<<endl;
		              	 		cout<<"6.genero. "<<endl;
		              	 		cout<<"Eliga una opcion. "<<endl;
		              	 		cin>>opc;
								system("cls");
								if(opc!=1&&opc!=2&&opc!=3&&opc!=4&&opc!=5&&opc!=6)
								Beep(500,100);
								}while(opc!=1&&opc!=2&&opc!=3&&opc!=4&&opc!=5&&opc!=6);
								switch(opc)
								{
								 case 1: 
		              	 		              do
										   {  
										   memset(cd.nombrealb,0,sizeof(cd.nombrealb));
		              	 		            memset(indexal.indalb,0,sizeof(indexal.indalb));
										   memset(cd.nombrealb,0,sizeof(cd.nombrealb));
										   cout<<"Nombre del album. \n";fflush(stdin);
										   gets(cd.nombrealb);
											 lon=strlen(cd.nombrealb);
											 if(lon > 10)
												{
													cout<<"\nLongitud invalida\n";
													getch();
												}
												        aux = 0;
														for(int i = 0; i < lon; i++)
														{
															if(isalnum(cd.nombrealb[i]) || isspace(cd.nombrealb[i]))
														    ban = 0;
														    else
															{
														    ban = 1;
														    break;
														    }
													    }
													    if(ban == 1)
													    {
													   	    cout << "Error!" << endl;
													   	    getch();
													    }
													    	if (lon == 0)
														{
														   	aux = 1;
														   	cout << "Campo vacio!" << endl;
														   	getch();
														}
												
											}while(ban == 1||lon==0 ||lon>10);
											strcpy(indexal.indalb,cd.nombrealb);
										    fseek(ar,-24,SEEK_CUR);
											fwrite(&indexal,sizeof(indexal),1,ar);
											fseek(ar,24,SEEK_CUR);
											system("cls");
	
											         cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
													    case 2:   do
									   {
									   	 memset(cd.nombreart,0,sizeof(cd.nombreart));
		              	 		            memset(indexar.indar,0,sizeof(indexar.indar));
									   cout<<"Nombre del artista. \n";fflush(stdin);
									   gets(cd.nombreart);
									   if(lon > 10)
											{
												cout<<"\nError\n";
											}
									   lon=strlen(cd.nombreart);
											        aux = 0;
													for(int i = 0; i < lon; i++)
													{
														if(isalpha(cd.nombreart[i]) || isspace(cd.nombreart[i]))
													    ban = 0;
													    else
														{
													    ban = 1;
													    break;
													    }
												    }
												    if(ban == 1)
												    {
												   	    cout << "Solo letras!" << endl;
												   	    getch();
												    }
												    	if (lon == 0)
													{
													   	aux = 1;
													   	cout << "Campo vacio!" << endl;
													   	getch();
													}
										}while(ban == 1||lon==0);
										strcpy(indexar.indar,cd.nombreart);
										    fseek(pa,-24,SEEK_CUR);
											fwrite(&indexar,sizeof(indexar),1,pa);
											fseek(pa,24,SEEK_CUR);
											system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
			                    case 3:  do
								   { 
								   
								   char year[10];
								   convertidor=0;
								   memset(year,0,sizeof(year));
								   cout<<"Fecha. \n"; 
								   fflush(stdin);
								   gets(year);
									 lon1=strlen(year);
									    	te=0;
												for(int i=0;i<lon1;i++)
												{
													if(isdigit(year[i]))
												    ban1=0;
												    else
													{
												    ban1=1;
												    break;
												    }
											    }
									    if(ban1==1)
									    {
									   	    printf("Digite numeros \n");
									   	    getch();
								   	    }
								   	    	if (lon1 == 0)
												{
												   	aux = 1;
												   	cout << "Campo vacio!" << endl;
												   	getch();
												}	
										convertidor=atoi(year);
										if(convertidor<1900||convertidor>2018)
										ban1=3;		
										if(ban1==3)
										{
											cout<<"Fecha invalida. Ejemplo: 1900-2018"<<endl;
											getch();
										}
							
								   	    }while(ban1==1 || lon1==0||ban1==3 ||lon1>10);
								   	    cd.publicacion=convertidor;	
										   	system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
				                  case 4:  do
										   { 
										   
										   char tie[10];
										   memset(tie,0,sizeof(tie));
										   fflush(stdin);
										  convertidor2=0;
										   cout<<"Duracion. \n";
										   gets(tie);
										   if(lon>10)
												{
													cout<<"\nError\n";
												}
											 lon=strlen(tie);
												        aux = 0;
														for(int i = 0; i < lon; i++)
														{
															if(isdigit(tie[i]) || isspace(tie[i]) || tie[i]==':')
														    ban = 0;
														    else
															{
														    ban = 1;
														    break;
														    }
													    }
									
													    	if (lon == 0)
														{
														   	aux = 1;
														   	cout << "Campo vacio!" << endl;
														   	getch();
														}
															 convertidor2=atoi(tie);
												if( convertidor2<1|| convertidor2>120)
												ban=3;		
												if(ban==3)
												{
													cout<<"Maximo de tiempo."<<endl;
													getch();
												}
														
											}while(ban == 1||lon==0 ||ban==3|| lon>10);
											cd.tiempo=convertidor2;	
												system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
								case 5:					  do
										   {
										   	convertidor3=0;
										   
										   	char dur[10];
										   	memset(dur,0,sizeof(dur));
										   	fflush(stdin);
										    cout<<"Numero de tracks. \n";
										    gets(dur);
										    if(lon1 > 10)
												{
													cout<<"\nError\n";
												}
										   lon1=strlen(dur);
											    	te=0;
														for(int i=0;i<lon1;i++)
														{
															if(isdigit(dur[i]))
														    ban1=0;
														    else
															{
														    ban1=1;
														    break;
														    }
													    }
											    if(ban1==1)
											    {
											   	    printf("Digite numeros \n");
											   	    getch();
										   	    }
										   	    	if (lon1 == 0)
														{
														   	aux = 1;
														   	cout << "Campo vacio!" << endl;
														   	getch();
														}	
												convertidor3=atoi(dur);
												if(convertidor3<0||convertidor3>200)
												ban1=3;		
												if(ban1==3)
												{
													cout<<"Fuera del rango."<<endl;
													getch();
												}
									
										   	    }while(ban1==1 || lon1==0||ban1==3 ||lon1>10);
										   	    cd.numtracks=convertidor3;	
												 system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\tPresione enter. "<<endl;
													  break;
								case 6:		do
									   {
									   	fflush(stdin);
								        er=1;
									    cout<<"Seleccione genero\n";
									    cout<<"1.-Blues\n";
									    cout<<"2.-Pop\n";
									    cout<<"3.-Clasico\n";
									    cout<<"4.-Opera\n";
									    cout<<"5.-Jazz\n";
									    cout<<"6.-Rock\n";
										cin>>amat;
										if(amat<1||amat>6)
											er=0;
										}while(amat<1|amat>6);
											if(amat==1)
											{
												fflush(stdin);
												char blu[]="Blues";
												strcpy(cd.genero,blu);
											}
											if(amat==2)
											{
												fflush(stdin);
												char ele[]="Pop";
												strcpy(cd.genero,ele);
											}
											if(amat==3)
											{
												fflush(stdin);
												char hea[]="Clasico";
												strcpy(cd.genero,hea);
											}
											if(amat==4)
											{
												fflush(stdin);
												char hip[]="Opera";
												strcpy(cd.genero,hip);
											}
											if(amat==5)
											{
												fflush(stdin);
												char jaz[]="Jazz";
												strcpy(cd.genero,jaz);
											}
											if(amat==6)
											{
												fflush(stdin);
												char roc[]="Rock";
												strcpy(cd.genero,roc);
											}
												strcpy(indexge.indage,cd.genero);
										    fseek(pg,-24,SEEK_CUR);
											fwrite(&indexge,sizeof(indexge),1,pg);
											fseek(pg,24,SEEK_CUR);
											system("cls");
	
											         cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\tPresione enter. "<<endl;
													  break;			    							  						
							      }//Cierra switch
							
						   
			
								fseek(pf,-60,SEEK_CUR);
								fwrite(&cd,sizeof(cd),1,pf);
								fseek(pf,60,SEEK_CUR);
									
						}
		        	 }
					}
					
					  }while(!feof(pa));
		            }
		            getch();
			        break;

		case '3': fseek(pg,0,SEEK_SET);
			          char consulta2[10];
		              memset(coda,0,sizeof(coda));
		              cout<<"Ingrese el genero que desea editar. "<<endl;fflush(stdin);
		              memset(consulta2,0,sizeof(consulta2));
		              gets(consulta2);
		              longbus=strlen(consulta2);
		              if(longbus==0)
		              {
		              	 cout<<"Vacio. ";
					  }
					  else
					  {
		              do
		              {
		                    memset(&indexge,0,sizeof(indexge));	
				            memset(&indexge,0,sizeof(indexge));
							memset(&cd,0,sizeof(cd));
		              	 	fread(&indexge,sizeof(indexge),1,pg);
		              	 		for(int i=0; i <2; i++)
							{
								caracter=fgetc(pg);
							}
							
		              	 	if(!strcmpi(consulta2, indexge.indage))
		              	 	{
		              	 		strcpy(coda,indexge.codigo4+1);
		              	 		cod2=atoi(coda);
		              	 		puntero=(cod2)*62;
		              	 		fseek(pf,puntero-62,SEEK_SET);
		              	 		fread(&cd, sizeof(cd),1,pf);
		              	 		if(cd.ban==0)
		              	 		{
	              	 			cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;
							  	do
						        {			
										cout<<"\nSon los datos que decea modificar? S/N "<<endl;
										caracter=getch();
										if(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S')
										Beep(500,100);
						       }while(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S');
						if(caracter=='s'||caracter=='S')
						{
								int opc=0;
								do
								{
								memset(&indexal,0,sizeof(indexal));
								memset(coda,0,sizeof(coda));
								strcpy(coda,cd.codigo+1);
								cod2=atoi(coda);
								puntero=(cod2)*26;
								punteroar=(cod2)*26;
								punteroge=(cod2)*26;
		              	 		fseek(ar,puntero-26,SEEK_SET);
		              	 		fread(&indexal, sizeof(indexal),1,ar);
		              	 		fseek(pa,punteroar-26,SEEK_SET);
		              	 		fread(&indexar, sizeof(indexar),1,pa);
		              	 		fseek(pg,puntero-26,SEEK_SET);
		              	 		fread(&indexge, sizeof(indexge),1,pg);
		              	 		cout<<"Que campo desea editar. "<<endl;
		              	 		cout<<"1.-Nombre del album. "<<endl;
		              	 		cout<<"2.-Nombre del artista. "<<endl;
		              	 		cout<<"3.-Year. "<<endl;
		              	 		cout<<"4.-Duracion. "<<endl;
		              	 		cout<<"5.-track. "<<endl;
		              	 		cout<<"6.genero. "<<endl;
		              	 		cout<<"Eliga una opcion. "<<endl;
		              	 		cin>>opc;
								system("cls");
								if(opc!=1&&opc!=2&&opc!=3&&opc!=4&&opc!=5&&opc!=6)
								Beep(500,100);
								}while(opc!=1&&opc!=2&&opc!=3&&opc!=4&&opc!=5&&opc!=6);
								switch(opc)
								{
								 case 1: 
		              	 		              do
										   {  
										   memset(cd.nombrealb,0,sizeof(cd.nombrealb));
		              	 		            memset(indexal.indalb,0,sizeof(indexal.indalb));
										   memset(cd.nombrealb,0,sizeof(cd.nombrealb));
										   cout<<"Nombre del album. \n";fflush(stdin);
										   gets(cd.nombrealb);
											 lon=strlen(cd.nombrealb);
											 if(lon > 10)
												{
													cout<<"\nLongitud invalida\n";
													getch();
												}
												        aux = 0;
														for(int i = 0; i < lon; i++)
														{
															if(isalnum(cd.nombrealb[i]) || isspace(cd.nombrealb[i]))
														    ban = 0;
														    else
															{
														    ban = 1;
														    break;
														    }
													    }
													    if(ban == 1)
													    {
													   	    cout << "Error!" << endl;
													   	    getch();
													    }
													    	if (lon == 0)
														{
														   	aux = 1;
														   	cout << "Campo vacio!" << endl;
														   	getch();
														}
												
											}while(ban == 1||lon==0 ||lon>10);
											strcpy(indexal.indalb,cd.nombrealb);
										    fseek(ar,-24,SEEK_CUR);
											fwrite(&indexal,sizeof(indexal),1,ar);
											fseek(ar,24,SEEK_CUR);
											system("cls");
	
											         cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
													    case 2:   do
									   {
									   	 memset(cd.nombreart,0,sizeof(cd.nombreart));
		              	 		            memset(indexar.indar,0,sizeof(indexar.indar));
									   cout<<"Nombre del artista. \n";fflush(stdin);
									   gets(cd.nombreart);
									   if(lon > 10)
											{
												cout<<"\nError\n";
											}
									   lon=strlen(cd.nombreart);
											        aux = 0;
													for(int i = 0; i < lon; i++)
													{
														if(isalpha(cd.nombreart[i]) || isspace(cd.nombreart[i]))
													    ban = 0;
													    else
														{
													    ban = 1;
													    break;
													    }
												    }
												    if(ban == 1)
												    {
												   	    cout << "Solo letras!" << endl;
												   	    getch();
												    }
												    	if (lon == 0)
													{
													   	aux = 1;
													   	cout << "Campo vacio!" << endl;
													   	getch();
													}
										}while(ban == 1||lon==0);
										strcpy(indexar.indar,cd.nombreart);
										    fseek(pa,-24,SEEK_CUR);
											fwrite(&indexar,sizeof(indexar),1,pa);
											fseek(pa,24,SEEK_CUR);
											system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
			                    case 3:  do
								   { 
								     memset(&cd,0,sizeof(cd));
								   char year[10];
								   convertidor=0;
								   memset(year,0,sizeof(year));
								   cout<<"Fecha. \n"; 
								   fflush(stdin);
								   gets(year);
									 lon1=strlen(year);
									    	te=0;
												for(int i=0;i<lon1;i++)
												{
													if(isdigit(year[i]))
												    ban1=0;
												    else
													{
												    ban1=1;
												    break;
												    }
											    }
									    if(ban1==1)
									    {
									   	    printf("Digite numeros \n");
									   	    getch();
								   	    }
								   	    	if (lon1 == 0)
												{
												   	aux = 1;
												   	cout << "Campo vacio!" << endl;
												   	getch();
												}	
										convertidor=atoi(year);
										if(convertidor<1900||convertidor>2018)
										ban1=3;		
										if(ban1==3)
										{
											cout<<"Fecha invalida. Ejemplo: 1900-2018"<<endl;
											getch();
										}
							
								   	    }while(ban1==1 || lon1==0||ban1==3 ||lon1>10);
								   	    cd.publicacion=convertidor;	
										   	system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
				                  case 4:  do
										   { 
										   
										   char tie[10];
										    memset(&cd,0,sizeof(cd));
										   memset(tie,0,sizeof(tie));
										   fflush(stdin);
										  convertidor2=0;
										   cout<<"Duracion. \n";
										   gets(tie);
										   if(lon>10)
												{
													cout<<"\nError\n";
												}
											 lon=strlen(tie);
												        aux = 0;
														for(int i = 0; i < lon; i++)
														{
															if(isdigit(tie[i]) || isspace(tie[i]) || tie[i]==':')
														    ban = 0;
														    else
															{
														    ban = 1;
														    break;
														    }
													    }
									
													    	if (lon == 0)
														{
														   	aux = 1;
														   	cout << "Campo vacio!" << endl;
														   	getch();
														}
															 convertidor2=atoi(tie);
												if( convertidor2<1|| convertidor2>120)
												ban=3;		
												if(ban==3)
												{
													cout<<"Maximo de tiempo."<<endl;
													getch();
												}
														
											}while(ban == 1||lon==0 ||ban==3|| lon>10);
											cd.tiempo=convertidor2;	
												system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\t Oprima enter para continuar. "<<endl;
													  break;
								case 5:					  do
										   {
										   	convertidor3=0;
										     memset(&cd,0,sizeof(cd));
								        
										   	char dur[10];
										   	memset(dur,0,sizeof(dur));
										   	fflush(stdin);
										    cout<<"Numero de tracks. \n";
										    gets(dur);
										    if(lon1 > 10)
												{
													cout<<"\nError\n";
												}
										   lon1=strlen(dur);
											    	te=0;
														for(int i=0;i<lon1;i++)
														{
															if(isdigit(dur[i]))
														    ban1=0;
														    else
															{
														    ban1=1;
														    break;
														    }
													    }
											    if(ban1==1)
											    {
											   	    printf("Digite numeros \n");
											   	    getch();
										   	    }
										   	    	if (lon1 == 0)
														{
														   	aux = 1;
														   	cout << "Campo vacio!" << endl;
														   	getch();
														}	
												convertidor3=atoi(dur);
												if(convertidor3<0||convertidor3>200)
												ban1=3;		
												if(ban1==3)
												{
													cout<<"Fuera del rango."<<endl;
													getch();
												}
									
										   	    }while(ban1==1 || lon1==0||ban1==3 ||lon1>10);
										   	    cd.numtracks=convertidor3;	
												 system("cls");
	
											          cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\tPresione enter. "<<endl;
													  break;
								case 6:		do
									   {
									   	fflush(stdin);
								        er=1;
								        
								        memset(cd.genero,0,sizeof(cd.genero));
								        memset(indexge.indage,0,sizeof(indexge.indage));
									    cout<<"Seleccione genero\n";
									    cout<<"1.-Blues\n";
									   	cout<<"2.-Pop\n";
									    cout<<"3.-Clasico\n";
									    cout<<"4.-Opera\n";
									    cout<<"5.-Jazz\n";
									    cout<<"6.-Rock\n";
										cin>>amat;
										if(amat<1||amat>6)
											er=0;
										}while(amat<1|amat>6);
											if(amat==1)
											{
												fflush(stdin);
												char blu[]="Blues";
												strcpy(cd.genero,blu);
											}
											if(amat==2)
											{
												fflush(stdin);
												char ele[]="Pop";
												strcpy(cd.genero,ele);
											}
											if(amat==3)
											{
												fflush(stdin);
												char hea[]="Clasica";
												strcpy(cd.genero,hea);
											}
											if(amat==4)
											{
												fflush(stdin);
												char hip[]="Opera";
												strcpy(cd.genero,hip);
											}
											if(amat==5)
											{
												fflush(stdin);
												char jaz[]="Jazz";
												strcpy(cd.genero,jaz);
											}
											if(amat==6)
											{
												fflush(stdin);
												char roc[]="Rock";
												strcpy(cd.genero,roc);
											}
												strcpy(indexge.indage,cd.genero);
										    fseek(pg,-24,SEEK_CUR);
											fwrite(&indexge,sizeof(indexge),1,pg);
											fseek(pg,26,SEEK_CUR);
											system("cls");
	
											         cout<<"\n\n\n\n\n\t\t\t\t\tArchivo editandose espere...!.\n";
											          Sleep(2000);
											          cout<<"\t\t\t\t\tCampo modificado. "<<endl;
											          cout<<"\t\t\t\t\tPresione enter. "<<endl;
													  break;			    							  						
							      }//Cierra switch
							
						   
			
								fseek(pf,-60,SEEK_CUR);
								fwrite(&cd,sizeof(cd),1,pf);
								fseek(pf,60,SEEK_CUR);
									
						}
		        	 }
					}
					
					  }while(!feof(pg));
		            }
		            getch();
			        break;
			        	  
					  		
	    }
    }while(op!=27);
   

	fclose(pf);
	fclose(ar);
	fclose(pa);
	fclose(pg);	

 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 void eliminar()
 {	
 	char op;
 	int ba=0;
 	int cod2=0, puntero=0, puntero2=0, puntero3=0; 
	char coda[10];
	 int longbus=0;
	 int longbus2=0;
	 int cod2s=0;
	pf=fopen(ext, "rb+");//Leeo mis archivos en modo binario
	ar=fopen(auxx,"rb+");//Leeo mis archivos en modo binario
	pa=fopen(auxxx,"rb+");//Leo mis archivos en modo binario
	pg=fopen(auxxxx,"rb+");//Leo mis archivos en modo binario
    if(pf==NULL)
    {
    	perror ("No fue posible crear el archivo para escritura");//Envio error al usuario
		exit(0);//Salir del programa
	}
//	do
//	{
		
	do
	{
		fflush(stdin);
		system("cls");
		 
		cout<<"Ingrese la opcion para ejecutar la busqueda. "<<endl;
		cout<<"1.-Indice album. "<<endl;
		cout<<"2.-Indice artista. "<<endl;
		cout<<"3.-Indice genero. "<<endl;
		cout<<"ESC. Para volver al menu. "<<endl;
		cout<<"ELIGA OPCION. "<<endl;
      	op=getch();
	    switch(op)
	    {
		    case '1':  fseek(ar,0,SEEK_SET);
			          char consulta[10];
		              memset(coda,0,sizeof(coda));
		              cout<<"Ingrese el nombre que desea buscar. "<<endl;fflush(stdin);
		              memset(consulta,0,sizeof(consulta));
		              gets(consulta);
		              longbus=strlen(consulta);
		              if(longbus==0)
		              {
		              	 cout<<"Vacio. ";
					  }
					  else
					  {
		              do
		              {
		                    memset(&indexal,0,sizeof(indexal));	
				            memset(&indexal,0,sizeof(indexal));
							memset(&cd,0,sizeof(cd));
		              	 	fread(&indexal,sizeof(indexal),1,ar);
		              	 		for(int i=0; i <2; i++)
							{
								caracter=fgetc(ar);
							}
		              	 	if(!strcmpi(consulta, indexal.indalb))
		              	 	{
		              	 		strcpy(coda,indexal.codigo2+1);
		              	 		cod2=atoi(coda);
		              	 		puntero=(cod2)*62;
		              	 		fseek(pf,puntero-62,SEEK_SET);
		              	 		fread(&cd, sizeof(cd),1,pf);
		              	 		if(cd.ban==0)
		              	 		{
	              	 			cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;
							  		do
									{	
										fflush(stdin);			
										cout<<"\nSon los datos que decea eliminar? S/N ";
										caracter=getch();
										if(caracter!='n'&&	caracter!='N'&&	caracter!='s'&&	caracter!='S')
										Beep(500,100);
									}while(	caracter!='n'&&	caracter!='N'&&	caracter!='s'&&	caracter!='S');
		        	            }//If bandera
						 }//Termina mi comparacion
						 if(	caracter=='s'||	caracter=='S')
							{
								puntero=0;
								puntero2=0;
								puntero3=0;
								cod2s=0;
								strcpy(coda,cd.codigo+1);
								cod2s=atoi(coda);
								puntero=cod2s*26;
								fseek(ar,puntero-26,SEEK_SET);
								fread(&indexal,sizeof(indexal),1,ar);
								
								fseek(pa,puntero-26,SEEK_SET);	
								fread(&indexar,sizeof(indexar),1,pa);
								
								fseek(pg,puntero-26,SEEK_SET);
								fread(&indexge,sizeof(indexge),1,pg);
							
								cd.ban=1;
								indexal.ban1=1;
								indexar.ban2=1;
								indexge.ban3=1;
					
								system("cls");					
							     cout<<"\n\n\n\n\n\t\t\t\t\tArchivo eliminandose espere...!.\n";
				                Sleep(2000);
					            cout<<"\t\t\t\t\tEliminacion exitosa. "<<endl;
								
								fseek(pf,-60,SEEK_CUR);
								fwrite(&cd,sizeof(cd),1,pf);
								fseek(pf,60,SEEK_CUR);
								
								fseek(ar,-24,SEEK_CUR);
								fwrite(&indexal,sizeof(indexal),1,ar);
								fseek(ar,24,SEEK_CUR);
								
								fseek(pa,-24,SEEK_CUR);
								fwrite(&indexar,sizeof(indexar),1,pa);
								fseek(pa,24,SEEK_CUR);
								
								fseek(pg,-24,SEEK_CUR);
								fwrite(&indexge,sizeof(indexge),1,pg);
								fseek(pg,24,SEEK_CUR);
								
							}/////////fin de if de aceptacion	
					  }while(!feof(ar));
		            }
		            getch();
			        break;
			 //////////////////////////////////////////////////////////////////////////////////////////    
			 case '2':  fseek(pa,0,SEEK_SET);
			          char consulta1[10];
		              memset(coda,0,sizeof(coda));
		              cout<<"Ingrese el artista que desea buscar. "<<endl;fflush(stdin);
		              memset(consulta1,0,sizeof(consulta1));
		              gets(consulta1);
		              longbus=strlen(consulta);
		              if(longbus==0)
		              {
		              	 cout<<"Vacio. ";
					  }
					  else
					  {
		              do
		              {
		                    memset(&indexar,0,sizeof(indexar));	
				            memset(&indexar,0,sizeof(indexar));
							memset(&cd,0,sizeof(cd));
		              	 	fread(&indexar,sizeof(indexar),1,pa);
		              	 		for(int i=0; i <2; i++)
							{
								caracter=fgetc(pa);
							}
		              	 	if(!strcmpi(consulta1, indexar.indar))
		              	 	{
		              	 		strcpy(coda,indexar.codigo3+1);
		              	 		cod2=atoi(coda);
		              	 		puntero2=(cod2)*62;
		              	 		fseek(pf,puntero2-62,SEEK_SET);
		              	 		fread(&cd, sizeof(cd),1,pf);
		              	 		if(cd.ban==0)
		              	 		{
	              	 			cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;
							  		do
									{	
										fflush(stdin);			
										cout<<"\nSon los datos que decea eliminar? S/N ";
										caracter=getch();
										if(caracter!='n'&&	caracter!='N'&&	caracter!='s'&&	caracter!='S')
										Beep(500,100);
									}while(	caracter!='n'&&	caracter!='N'&&	caracter!='s'&&	caracter!='S');
		        	            }//If bandera
						 }//Termina mi comparacion
						 if(	caracter=='s'||	caracter=='S')
							{
								puntero=0;
								puntero2=0;
								puntero3=0;
								cod2s=0;
								strcpy(coda,cd.codigo+1);
								cod2s=atoi(coda);
								puntero=cod2s*26;
								fseek(ar,puntero2-26,SEEK_SET);
								fread(&indexal,sizeof(indexal),1,ar);
								fseek(pa,puntero2-26,SEEK_SET);
								fread(&indexar,sizeof(indexar),1,pa);
								fseek(pg,puntero2-26,SEEK_SET);
								fread(&indexge,sizeof(indexge),1,pg);
							
							
								cd.ban=1;
							    indexal.ban1=1;
								indexar.ban2=1;
								indexge.ban3=1;
					
								system("cls");					
							     cout<<"\n\n\n\n\n\t\t\t\t\tArchivo eliminandose espere...!.\n";
				                Sleep(2000);
					            cout<<"\t\t\t\t\tEliminacion exitosa. "<<endl;
								
								fseek(pf,-60,SEEK_CUR);
								fwrite(&cd,sizeof(cd),1,pf);
								fseek(pf,60,SEEK_CUR);
								
							    fseek(ar,-24,SEEK_CUR);
								fwrite(&indexal,sizeof(indexal),1,ar);
								fseek(ar,24,SEEK_CUR);
								
								fseek(pa,-24,SEEK_CUR);
								fwrite(&indexar,sizeof(indexar),1,pa);
								fseek(pa,24,SEEK_CUR);
								
								fseek(pg,-24,SEEK_CUR);
								fwrite(&indexge,sizeof(indexge),1,pg);
								fseek(pg,24,SEEK_CUR);
							}/////////fin de if de aceptacion	
					  }while(!feof(pa));
		            }
		            getch();
			        break;
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		 case '3':  fseek(pg,0,SEEK_SET);
			          char consulta2[10];
		              memset(coda,0,sizeof(coda));
		              cout<<"Ingrese el genero que desea buscar. "<<endl;fflush(stdin);
		              memset(consulta2,0,sizeof(consulta2));
		              gets(consulta2);
		              longbus=strlen(consulta);
		              if(longbus==0)
		              {
		              	 cout<<"Vacio. ";
					  }
					  else
					  {
		              do
		              {
		                    memset(&indexge,0,sizeof(indexge));	
				            memset(&indexge,0,sizeof(indexge));
							memset(&cd,0,sizeof(cd));
		              	 	fread(&indexge,sizeof(indexge),1,pg);
		              	 		for(int i=0; i <2; i++)
							{
								caracter=fgetc(pg);
							}
		              	 	if(!strcmpi(consulta2, indexge.indage))
		              	 	{
		              	 		strcpy(coda,indexge.codigo4+1);
		              	 		cod2=atoi(coda);
		              	 		puntero2=(cod2)*62;
		              	 		fseek(pf,puntero2-62,SEEK_SET);
		              	 		fread(&cd, sizeof(cd),1,pf);
		              	 		if(cd.ban==0)
		              	 		{
	              	 			cout<<"\n\nCodigo: "<<cd.codigo<<endl;
							  	cout<<"Nombre del album: "<<cd.nombrealb << endl;
							  	cout<<"Nombre del artista: "<<cd.nombreart << endl;
							  	cout<<"Nombre del album: "<<cd.publicacion << endl ;
							  	cout<<"Tiempo: "<<cd.tiempo << endl;
							  	cout<<"Num. tracks: "<<cd.numtracks<<endl;
							  	cout<<"Genero: "<<cd.genero << endl;
							  		do
									{	
										fflush(stdin);			
										cout<<"\nSon los datos que decea eliminar? S/N ";
										caracter=getch();
										if(caracter!='n'&&	caracter!='N'&&	caracter!='s'&&	caracter!='S')
										Beep(500,100);
									}while(	caracter!='n'&&	caracter!='N'&&	caracter!='s'&&	caracter!='S');
		        	            }//If bandera
						 }//Termina mi comparacion
						 if(	caracter=='s'||	caracter=='S')
							{
								puntero=0;
								puntero2=0;
								puntero3=0;
								cod2s=0;
								strcpy(coda,cd.codigo+1);
								cod2s=atoi(coda);
								puntero3=cod2s*26;
								fseek(ar,puntero3-26,SEEK_SET);
								fread(&indexal,sizeof(indexal),1,ar);
								fseek(pa,puntero3-26,SEEK_SET);
								fread(&indexar,sizeof(indexar),1,pa);
								fseek(pg,puntero3-26,SEEK_SET);
								fread(&indexge,sizeof(indexge),1,pg);
							
								cd.ban=1;
								indexal.ban1=1;
								indexar.ban2=1;
								indexge.ban3=1;
					
								system("cls");					
							     cout<<"\n\n\n\n\n\t\t\t\t\tArchivo eliminandose espere...!.\n";
				                Sleep(2000);
					            cout<<"\t\t\t\t\tEliminacion exitosa. "<<endl;
								
								fseek(pf,-60,SEEK_CUR);
								fwrite(&cd,sizeof(cd),1,pf);
								fseek(pf,60,SEEK_CUR);
								
								fseek(ar,-24,SEEK_CUR);
								fwrite(&indexal,sizeof(indexal),1,ar);
								fseek(ar,24,SEEK_CUR);
								
								fseek(pa,-24,SEEK_CUR);
								fwrite(&indexar,sizeof(indexar),1,pa);
								fseek(pa,24,SEEK_CUR);
								
								fseek(pg,-24,SEEK_CUR);
								fwrite(&indexge,sizeof(indexge),1,pg);
								fseek(pg,24,SEEK_CUR);
								
							}/////////fin de if de aceptacion	
					  }while(!feof(pg));
		            }
		            getch();
			        break;	        	  
					  		
	    }//Cierre switch
//	    	do
//			{
//				system("cls");
//				gotoxy(10,10);
//				cout<<"Decea buscar mas albums? S/N ";
//				caracter=getch();
//				if(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S')
//				Beep(500,100);
//			}while(caracter!='n'&&caracter!='N'&&caracter!='s'&&caracter!='S');
//			 
//    }while(caracter=='s'||caracter=='S');
    }while(op!=27);
   

	fclose(pf);
	fclose(ar);
	fclose(pa);
	fclose(pg);
//	if(conta==0)
//		{
//			cout<<"No se encontro el cd.\n";
//			getch();
//		}
 	
		
 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 void error()
 {
 	cout<<"Error. "<<endl;
 }
