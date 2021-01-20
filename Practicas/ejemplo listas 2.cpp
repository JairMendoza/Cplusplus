# include <conio.h>
# include <stdio.h>
# include <stdlib.h>  

//creacion de los tipos de dato nodo   

		typedef struct dato
		{
		int numero, telef;
		char nombre[40];
		struct dato *enlace;
		}nodo;
		nodo *primero=NULL;
		nodo *ultimo=NULL;
		

        typedef struct elemento
		{
		int numero, telef;
		char nombre[40];
		struct elemento *enlaceA, *enlaceB;
		}nodo1;


//DECLARACION DE FUNCIONES

//simplemente enlazadas

void menulistas();

nodo* crear_registro();
void  agregar_final(nodo*);
nodo* agregar_inicio(nodo*);
void  agregar_lugar(nodo*,int);
nodo* elimina_inicio(nodo*);
void  elimina_final(nodo*);
void elimina_lugar_especifico(nodo*,int);
void  mostrar_lista(nodo*);

////simplemente enlazadas circulares
void  agregar_finalcir(nodo*);
nodo* agregar_iniciocir(nodo*);
void  agregar_lugarcir(nodo*,int);
nodo* elimina_iniciocir(nodo*);
void  elimina_finalcir(nodo*);
void elimina_lugar_especificocir(nodo*,int);
void mostrar_listacir(nodo*);
//
////dobles enlazadas
//
nodo1* crear_registrodo();
void  agregar_finaldo(nodo1*);
nodo1* agregar_iniciodo(nodo1*);
void  agregar_lugardo(nodo1*,int);
nodo1* elimina_iniciodo(nodo1*);
void  elimina_finaldo(nodo1*);
void elimina_lugar_especificodo(nodo1*,int);
void mostrar_listado(nodo1*);
//
////dobles enlazadas circulares
//
//
//void  agregar_finaldoc(nodo1*);
//nodo1* agregar_iniciodoc(nodo1*);
//void  agregar_lugardoc(nodo1*,int);
//nodo1* elimina_iniciodoc(nodo1*);
//void  elimina_finaldoc(nodo1*);
//void elimina_lugar_especificodoc(nodo1*,int);
//void mostrar_listadoc(nodo1*,int);




main()
{//INICIO DEL MAIN
int pos=0,con1=0;
nodo *inicio=NULL;


char opc=NULL,cadena[10]={'\0'};

int pos2=0,con2=0;
nodo1 *inicio2=NULL;
char cadena2[10]={'\0'};




do
{//menu principal

system("cls");

printf("\nMENU PRINCIPAL\n");
printf("\n1. Lista simple enlazada");
printf("\n2. Lista simple enlazada circular");
printf("\n3. Lista doble  enlazada");
printf("\n4. Lista doble  enlazada circular\n");
printf("\n5. Salir\n");

printf("\nElija una opcion");
opc=getch();


	  switch(opc)
	  {//inicio del switch menu principal

	  case '1':
	  do
	  {//do case1
	  system("cls");
	  printf("MENU LISTAS SIMPLES ENLAZADAS\n");
	  menulistas();
	  opc=getch();

			 switch(opc)
			 {//inicio switch  menu listas simplemente enlazadas

					case '1':
							  if(inicio==NULL||con1==0)
							  {
							  inicio=crear_registro();
							  con1++; 
							  }
							  else                                       
							  {
							  agregar_final(inicio);        
							  con1++;
							  }
							  //printf("\ncon = %d\n", con1);
							  mostrar_lista(inicio);

							  break;

					case '2':
							  if (inicio==NULL||con1==0)
							  {
									inicio=crear_registro();
									con1++ ;
							  }
							  else
							  {
									inicio=agregar_inicio(inicio);
									con1++ ;
							  }
							  //printf("\ncon = %d\n", con1);
							  mostrar_lista(inicio);


							  break;

					case '3':
							 if(inicio==NULL||con1==0)
							 {
								  printf("No existia ningun registro por lo que se creo el primero");
								  inicio=crear_registro();
								  con1++;
							 }

							 else
							 {
								  printf("\nEn que lugar de sea colocar el nuevo registro: ");
								  gets(cadena);
								  pos=atoi(cadena);

								  if (pos==1)
								  {
								  inicio=agregar_inicio(inicio);
								  con1++;
								  }


								  else
								  {

										if(pos>con1||pos==0)
										{
											 printf("\nNO EXISTE ESE REGISTRO\n");
											 getch();
										}

										else
										{
											 agregar_lugar(inicio,pos);
											 con1++;

										}
								  }
							 }
							 //printf("\ncon = %d\n", con1);
							 mostrar_lista(inicio);


				  break;

					case '4':

					 if(inicio==NULL||con1==0)
							 {
								  printf("\nNO EXISTE LISTA");
								  getch();
							 }
					 else
					 {
							 if (con1==1)
							 {
							 printf("\nSe elimino el unico registro que existia por lo tanto ...");
							 inicio=elimina_inicio(inicio);
							 con1--;
                      }
							 else
							 {
							 inicio=elimina_inicio(inicio);
							 con1--;
							 }
							 //printf("\ncon = %d\n", con1);
							 mostrar_lista(inicio);

					 }
					break;



					case '5':
                if(inicio==NULL||con1==0)
							 {
								  printf("\nNO EXISTE LISTA");
								  getch();
							 }

					 else
					 {

							 if(con1==1)
							 {
                      printf("\nSe elimino el unico registro qu existia por lo tanto...");
							 inicio=elimina_inicio(inicio);
							 con1--;
							 }
							 else
							 {
							  elimina_final(inicio);
							  con1--;
							 }
							 //printf("\ncon = %d\n", con1);
							 mostrar_lista(inicio);
					 }

					break;

					case '6':

					 if(inicio==NULL||con1==0)
							 {
								  printf("\nNO EXISTE LISTA");
								  getch();
							 }
					else
					{
							printf("\n\nIndique el numero de nodo que desea eliminar: ");
							gets(cadena);
							pos=atoi(cadena);
							printf("\ncon = %d\n", con1);
							  if (pos==1)
									{
									inicio=elimina_inicio(inicio);
									con1--;
									}

									else if(pos==con1)
									{
									elimina_final(inicio);
									con1--;
									}

									else if (pos>con1 || pos<1)
									{
									 printf("\n\nNO EXISTE ESE REGISTRO");
									}

									else
									{
									elimina_lugar_especifico(inicio,pos);
									con1--;
									}
									//printf("\ncon = %d", con1);
									mostrar_lista(inicio);

							}
									break;
				 				

			 }//fin del switch menu listas simplemente enlazadas

	  }//do case1
	  while (opc!='7');
	  break;
	  //------------------------------fin case 1--------------------------------

	  case '2':
	  do
	  {//do case2	
      system("cls");
	  printf("MENU LISTAS SIMPLES CIRCULARES ENLAZADAS\n");
	  menulistas();
	  opc=getch();

			 switch(opc)
			 {//inicio switch  menu listas simplemente enlazadas

					case '1':
							  if(inicio==NULL||con1==0)
							  {
							  inicio=crear_registro();
							  con1++; 
							  }
							  else                                       
							  {
							  agregar_finalcir(inicio);        
							  con1++;
							  }
							  //printf("\ncon = %d\n", con1);
							  mostrar_listacir(inicio);

							  break;

					case '2':
							  if (inicio==NULL||con1==0)
							  {
									inicio=crear_registro();
									con1++ ;
							  }
							  else
							  {
									inicio=agregar_iniciocir(inicio);
									con1++ ;
							  }
							  //printf("\ncon = %d\n", con1);
							  mostrar_listacir(inicio);


							  break;

					case '3':
							 if(inicio==NULL||con1==0)
							 {
								  printf("No existia ningun registro por lo que se creo el primero");
								  inicio=crear_registro();
								  con1++;
							 }

							 else
							 {
								  printf("\nEn que lugar de sea colocar el nuevo registro: ");
								  gets(cadena);
								  pos=atoi(cadena);

								  if (pos==1)
								  {
								  inicio=agregar_iniciocir(inicio);
								  con1++;
								  }


								  else
								  {

										if(pos>con1||pos==0)
										{
											 printf("\nNO EXISTE ESE REGISTRO\n");
											 getch();
										}

										else
										{
											 agregar_lugarcir(inicio,pos);
											 con1++;

										}
								  }
							 }
							 //printf("\ncon = %d\n", con1);
							 mostrar_listacir(inicio);


				  break;

					case '4':

					 if(inicio==NULL||con1==0)
							 {
								  printf("\nNO EXISTE LISTA");
								  getch();
							 }
					 else
					 {
							 if (con1==1)
							 {
							 printf("\nSe elimino el unico registro que existia por lo tanto ...");
							 inicio=elimina_iniciocir(inicio);
							 con1--;
                      }
							 else
							 {
							 inicio=elimina_iniciocir(inicio);
							 con1--;
							 }
							 //printf("\ncon = %d\n", con1);
							 mostrar_listacir(inicio);

					 }
					break;



					case '5':
                if(inicio==NULL||con1==0)
							 {
								  printf("\nNO EXISTE LISTA");
								  getch();
							 }

					 else
					 {

							 if(con1==1)
							 {
                      printf("\nSe elimino el unico registro qu existia por lo tanto...");
							 inicio=elimina_iniciocir(inicio);
							 con1--;
							 }
							 else
							 {
							  elimina_finalcir(inicio);
							  con1--;
							 }
							 //printf("\ncon = %d\n", con1);
							 mostrar_listacir(inicio);
					 }

					break;

					case '6':

					 if(inicio==NULL||con1==0)
							 {
								  printf("\nNO EXISTE LISTA");
								  getch();
							 }
					else
					{
							printf("\n\nIndique el numero de nodo que desea eliminar: ");
							gets(cadena);
							pos=atoi(cadena);
							printf("\ncon = %d\n", con1);
							  if (pos==1)
									{
									inicio=elimina_iniciocir(inicio);
									con1--;
									}

									else if(pos==con1)
									{
									elimina_finalcir(inicio);
									con1--;
									}

									else if (pos>con1 || pos<1)
									{
									 printf("\n\nNO EXISTE ESE REGISTRO");
									}

									else
									{
									elimina_lugar_especifico(inicio,pos);
									con1--;
									}
									//printf("\ncon = %d", con1);
									mostrar_lista(inicio);

							}
									break;
				 				

			 }//fin del switch menu listas simplemente enlazadas

	  }//do case1
	  while (opc!='7'); 
       
 
	  break;

	  //--------------------------------fin case2-------------------------------

	  case '3':
	  	do
	  {//do case1
	  system("cls");
	  printf("MENU LISTAS DOBLES SIMPLES ENLAZADAS\n");
	  menulistas();
	  opc=getch();

			 switch(opc)
			 {//inicio switch  menu listas simplemente enlazadas

					case '1':
							  if(inicio2==NULL||con2==0)
							  {
							  inicio2=crear_registrodo();
							  con2++; 
							  }
							  else                                       
							  {
							  agregar_finaldo(inicio2);        
							  con2++;
							  }
							  //printf("\ncon = %d\n", con1);
							  mostrar_listado(inicio2);

							  break;

					case '2':
							  if (inicio2==NULL||con2==0)
							  {
									inicio2=crear_registrodo();
									con1++ ;
							  }
							  else
							  {
									inicio2=agregar_iniciodo(inicio2);
									con2++ ;
							  }
							  //printf("\ncon = %d\n", con1);
							  mostrar_listado(inicio2);


							  break;

					case '3':
							 if(inicio2==NULL||con2==0)
							 {
								  printf("No existia ningun registro por lo que se creo el primero");
								  inicio2=crear_registrodo();
								  con2++;
							 }

							 else
							 {
								  printf("\nEn que lugar de sea colocar el nuevo registro: ");
								  gets(cadena2);
								  pos2=atoi(cadena2);

								  if (pos2==1)
								  {
								  inicio2=agregar_iniciodo(inicio2);
								  con2++;
								  }


								  else
								  {

										if(pos2>con2||pos2==0)
										{
											 printf("\nNO EXISTE ESE REGISTRO\n");
											 getch();
										}

										else
										{
											 agregar_lugardo(inicio2,pos2);
											 con2++;

										}
								  }
							 }
							 //printf("\ncon = %d\n", con2);
							 mostrar_listado(inicio2);


				  break;

					case '4':

					 if(inicio2==NULL||con2==0)
							 {
								  printf("\nNO EXISTE LISTA");
								  getch();
							 }
					 else
					 {
							 if (con2==1)
							 {
							 printf("\nSe elimino el unico registro que existia por lo tanto ...");
							 inicio2=elimina_iniciodo(inicio2);
							 con2--;
                      }
							 else
							 {
							 inicio2=elimina_iniciodo(inicio2);
							 con1--;
							 }
							 //printf("\ncon = %d\n", con1);
							 mostrar_listado(inicio2);

					 }
					break;



					case '5':
                if(inicio2==NULL||con2==0)
							 {
								  printf("\nNO EXISTE LISTA");
								  getch();
							 }

					 else
					 {

							 if(con2==2)
							 {
                      printf("\nSe elimino el unico registro qu existia por lo tanto...");
							 inicio2=elimina_iniciodo(inicio2);
							 con2--;
							 }
							 else
							 {
							  elimina_finaldo(inicio2);
							  con2--;
							 }
							 //printf("\ncon = %d\n", con1);
							 mostrar_listado(inicio2);
					 }

					break;

					case '6':

					 if(inicio2==NULL||con2==0)
							 {
								  printf("\nNO EXISTE LISTA");
								  getch();
							 }
					else
					{
							printf("\n\nIndique el numero de nodo que desea eliminar: ");
							gets(cadena2);
							pos2=atoi(cadena2);
							printf("\ncon = %d\n", con2);
							  if (pos==1)
									{
									inicio2=elimina_iniciodo(inicio2);
									con2--;
									}

									else if(pos==con2)
									{
									elimina_finaldo(inicio2);
									con2--;
									}

									else if (pos2>con2 || pos2<1)
									{
									 printf("\n\nNO EXISTE ESE REGISTRO");
									}

									else
									{
									elimina_lugar_especificodo(inicio2,pos2);
									con2--;
									}
									//printf("\ncon = %d", con1);
									mostrar_listado(inicio2);

							}
									break;
				 				

			 }//fin del switch menu listas simplemente enlazadas

	  }//do case1
	  while (opc!='7');

 
	  break;

	  //------------------------------fin case 3 --------------------------------

	  case '4':
	  	
 

 
	  break;

	  //-----------------------------fin del case 4------------------------------

	  }//fin del switch menu principal

}//do menu principal
while(opc!='5');
exit(0);

}//FIN DEL MAIN



//INICIO DE FUNCIONES//

//Funcion  para mostrar el menu de las listas

void menulistas()
{//inicio  de la funcion menu listas

	  printf("\n1. Agregar registro al final  de la lista");
	  printf("\n2. Agregar registro al inicio de la lista");
	  printf("\n3. Insertar registro");
	  printf("\n4. Eliminar primer registro");
	  printf("\n5. Eliminar ultimo registro");
	  printf("\n6. Eliminar un registro especifico");
	  printf("\n7. Volver al menu principal");
	  printf("\n\n Elija una opcion : ");

}//fin de la funcion menu listas


//funcion crear nodo

nodo * crear_registro()
{
char h[10]={'\0'};
char t[10]={'\0'};
nodo *aux=NULL;
aux=(nodo*)malloc (sizeof(nodo));

if (aux!=NULL)
	 {
	 printf("\n\nNombre: ");
	 gets(aux->nombre);
	 printf("\nEdad: ");
	 gets(h);
	 printf("\nTelefono: ");
	 gets(t);
	 aux->telef=atoi(t);
	 aux->numero=atoi(h);
	 aux->enlace=NULL;
	 }
	 return aux;
}

//funcion agregar final

void agregar_final(nodo*inicio)

{
nodo *nuevo,*fin=inicio;
nuevo=crear_registro();


while(fin->enlace!=NULL)
{
fin=fin->enlace;
}

fin->enlace=nuevo;

}

//Funcion agregar al inicio de la lista

nodo * agregar_inicio(nodo *inicio)
{
char h[10];
nodo *nuevo;
nuevo =(nodo*)malloc(sizeof(nodo));

	  if (nuevo!=NULL)
	  {
	  printf("\nNombre: ");
	  gets(nuevo->nombre);
	  printf("\nEdad: ");
	  gets(h);
	  nuevo->numero=atoi(h);
	  nuevo->enlace=inicio;
	  inicio=nuevo;

	  }
	  return inicio;


}

//funcion agregar en un lugar especifico

void agregar_lugar(nodo *inicio, int pos)

{
nodo *nuevo,*aux=inicio;
int c=1;
nuevo=crear_registro();

while(c<pos-1)
	{
	aux=aux->enlace;
	c++;
	}
	nuevo->enlace=aux->enlace;
	aux->enlace=nuevo;
}

//funcion eliminar al inicio

nodo* elimina_inicio(nodo * inicio)
{
 if (inicio==NULL)
  {
  printf("NO EXISTE LISTA");
  }
 else
	{
  nodo *aux=inicio->enlace;
  inicio->enlace=NULL;
  free(inicio);
  inicio=aux;
	}
return inicio;

}

//funcion eliminar al final

void elimina_final(nodo *inicio)
{

nodo *aux1,*aux2;

aux1=inicio->enlace;
aux2=inicio;

	 while (aux1->enlace!=NULL)
	 {
	 aux1=aux1->enlace;
	 aux2=aux2->enlace;
	 }

	 free(aux1);
	 aux2->enlace=NULL;

}

//FUNCION PARA ELIMINAR EN UN LUGAR ESPECIFICO SIMPLES

void elimina_lugar_especifico(nodo *inicio, int pos)
{
nodo *aux=inicio, *aux2=inicio->enlace;
int c=2;

		while(c<pos)
		{

		aux=aux->enlace;
		aux2=aux2->enlace;
		c++;
		}

		aux->enlace=aux2->enlace;
		aux2->enlace=NULL;
		free(aux2);

}


//FUNCION MOSTRAR_LISTA

 void mostrar_lista(nodo *inicio)
{
system("cls");

if (inicio==NULL)
printf("NO EXISTE LISTA");

else
{
int x=1;

	  while (inicio !=NULL)
		  {
		  printf("\nRegistro # %d",x);
		  printf("\nNombre: ");puts(inicio->nombre);
		  printf("Edad: %d\n",inicio->numero);
		  inicio=inicio->enlace;
		  x++;
		  }
}
		 getch();

}

//FUNCIONES DE LISTAS ENLAZADAS CIRCULARES-------------------------------------------------------------------------------------


void agregar_finalcir(nodo*inicio)

{
nodo *nuevo;
int numNodos;
nuevo=crear_registro();



if(primero==NULL){
    primero=nuevo;
	primero->enlace=primero;
	ultimo=primero;
	

}
else{
	
	
	ultimo->enlace=nuevo;
    nuevo->enlace = primero;
    ultimo=nuevo;
}
           
            
}





//Funcion agregar al inicio de la lista

nodo * agregar_iniciocir(nodo *inicio)
{
char h[10];
char t[10];

nodo *nuevo;
nuevo =(nodo*)malloc(sizeof(nodo));

	  if (nuevo==NULL)
	  {
	  printf("\nNombre: ");
	  gets(nuevo->nombre);
	  printf("\nEdad: ");
	  gets(h);
	  printf("\nTelefono: ");
	  gets(t);
	  
	  nuevo->numero=atoi(h);
	  nuevo->telef=atoi(t);
	  nuevo->enlace=inicio;
	  inicio=nuevo;

	  }
	  
	  
	  
	  
	
	  return inicio;


}

//funcion agregar en un lugar especifico

void agregar_lugarcir(nodo *inicio, int pos)

{
nodo *nuevo,*aux=inicio;
int c=1;
nuevo=crear_registro();

while(c<pos-1)
	{
	aux=aux->enlace;
	c++;
	}
	nuevo->enlace=aux->enlace;
	aux->enlace=nuevo;
}

//funcion eliminar al inicio

nodo* elimina_iniciocir(nodo * inicio)
{
 if (inicio==NULL)
  {
  printf("NO EXISTE LISTA");
  }
 else
	{
  nodo *aux=inicio->enlace;
  inicio->enlace=NULL;
  free(inicio);
  inicio=aux;
	}
return inicio;

}

//funcion eliminar al final

void elimina_finalcir(nodo *inicio)
{

nodo *aux1,*aux2;

aux1=inicio->enlace;
aux2=inicio;

	 while (aux1->enlace!=NULL)
	 {
	 aux1=aux1->enlace;
	 aux2=aux2->enlace;
	 }

	 free(aux1);
	 aux2->enlace=NULL;

}

//FUNCION PARA ELIMINAR EN UN LUGAR ESPECIFICO SIMPLES

void elimina_lugar_especificocir(nodo *inicio, int pos)
{
nodo *aux=inicio, *aux2=inicio->enlace;
int c=2;

		while(c<pos)
		{

		aux=aux->enlace;
		aux2=aux2->enlace;
		c++;
		}

		aux->enlace=aux2->enlace;
		aux2->enlace=NULL;
		free(aux2);

}


//FUNCION MOSTRAR_LISTA

 void mostrar_listacir(nodo *actual)
{
system("cls");



if (primero==NULL)
{
int x=1;

	  do{
	  
		  {
		  printf("\nRegistro # %d",x);
		  printf("\nNombre: ");puts(actual->nombre);
		  printf("Edad: %d\n",actual->numero);
		  printf("Telefono: %d\n",actual->telef);
		  actual=actual->enlace;
		  x++;
		  }  
		}while(actual!=primero);
}else
{
	printf("NO EXISTE LISTA");
}
		 getch();

}

//Registro Listas Dobles enlazadas-----------------------------------------------------------------------------/
nodo1 * crear_registrodo()

{
char h[10]={'\0'};
char t[10]={'\0'};
nodo1 *aux=NULL;
aux=(nodo1*)malloc (sizeof(nodo1));

if (aux!=NULL)
	 {
	 printf("\n\nNombre: ");
	 gets(aux->nombre);
	 printf("\nEdad: ");
	 gets(h);
	 printf("\nTelefono: ");
	 gets(t);
	 aux->telef=atoi(t);
	 aux->numero=atoi(h);
	 aux->enlaceA=NULL;
	 aux->enlaceB=NULL;
	 
	 }
	 return aux;
}

//funcion agregar final

void agregar_finaldo(nodo1*inicio2)

{
nodo1 *nuevo1,*fin=inicio2;
nuevo1=crear_registrodo();


while(fin->enlaceA->enlaceB!=NULL)
{
fin=fin->enlaceA->enlaceB;
}

fin->enlaceA->enlaceB=nuevo1;

}

//Funcion agregar al inicio de la lista

nodo1 * agregar_iniciodo(nodo1 *inicio2)
{
char h[10];
nodo1 *nuevo1;
nuevo1 =(nodo1*)malloc(sizeof(nodo1));

	  if (nuevo1!=NULL)
	  {
	  printf("\nNombre: ");
	  gets(nuevo1->nombre);
	  printf("\nEdad: ");
	  gets(h);
	  nuevo1->numero=atoi(h);
	  nuevo1->enlaceA->enlaceB=inicio2;
	  
	  inicio2=nuevo1;

	  }
	  return inicio2;


}

//funcion agregar en un lugar especifico

void agregar_lugardo(nodo1 *inicio2, int pos2)

{
nodo1 *nuevo1,*aux=inicio2;
int c=1;
nuevo1=crear_registrodo();

while(c<pos2-1)
	{
	aux=aux->enlaceA->enlaceB;
	c++;
	}
	nuevo1->enlaceA=aux->enlaceB;
	aux->enlaceA=nuevo1;
}

//funcion eliminar al inicio

nodo1* elimina_iniciodo(nodo1 * inicio2)
{
 if (inicio2==NULL)
  {
  printf("NO EXISTE LISTA");
  }
 else
	{
  nodo1 *aux=inicio2->enlaceA->enlaceB;
  inicio2->enlaceA->enlaceB=NULL;
  free(inicio2);
  inicio2=aux;
	}
return inicio2;

}

//funcion eliminar al final

void elimina_finaldo(nodo1 *inicio2)
{

nodo1 *aux1,*aux2;

aux1=inicio2->enlaceA->enlaceB;
aux2=inicio2->enlaceA->enlaceB;

	 while (aux1->enlaceA=NULL)
	 {
	 aux1=aux1->enlaceA;
	 aux2=aux2->enlaceB;
	 }

	 free(aux1);
	 aux2->enlaceB=NULL;

}

//FUNCION PARA ELIMINAR EN UN LUGAR ESPECIFICO SIMPLES

void elimina_lugar_especificodo(nodo1 *inicio2, int pos2)
{
nodo1 *aux=inicio2, *aux2=inicio2->enlaceA->enlaceB;
int c=2;

		while(c<pos2)
		{

		aux=aux->enlaceA->enlaceB;
		aux2=aux2->enlaceA->enlaceB;
		c++;
		}

		aux->enlaceA->enlaceB=aux2->enlaceA->enlaceB;
		aux2->enlaceA->enlaceB=NULL;
		free(aux2);

}


//FUNCION MOSTRAR_LISTA

 void mostrar_listado(nodo1 *inicio2)
{
system("cls");

if (inicio2==NULL)
printf("NO EXISTE LISTA");

else
{
int x=1;

	  while (inicio2 !=NULL)
		  {
		  printf("\nRegistro # %d",x);
		  printf("\nNombre: ");puts(inicio2->nombre);
		  printf("Edad: %d\n",inicio2->numero);
		  inicio2=inicio2->enlaceA;
		  x++;
		  }
}
		 getch();

}









