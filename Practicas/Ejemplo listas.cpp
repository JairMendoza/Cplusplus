# include <conio.h>
# include <stdio.h>
# include <stdlib.h>  

//creacion de los tipos de dato nodo   

		typedef struct dato
		{
		int numero;
		char nombre[40];
		struct dato *enlace;
		}nodo;

//			typedef struct elemento
//		{
//		int numero;
//		char nombre[40];
//		struct elemento *enlaceA, *enlaceS;
//		}nodo1;


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
//
//void  agregar_finalcir(nodo*);
//nodo* agregar_iniciocir(nodo*);
//void  agregar_lugarcir(nodo*,int);
//nodo* elimina_iniciocir(nodo*);
//void  elimina_finalcir(nodo*);
//void elimina_lugar_especificocir(nodo*,int);
//void mostrar_listacir(nodo*,int);
//
////dobles enlazadas
//
//nodo1* crear_registrodo();
//void  agregar_finaldo(nodo1*);
//nodo1* agregar_iniciodo(nodo1*);
//void  agregar_lugardo(nodo1*,int);
//nodo1* elimina_iniciodo(nodo1*);
//void  elimina_finaldo(nodo1*);
//void elimina_lugar_especificodo(nodo1*,int);
//void mostrar_listado(nodo1*,int);
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




void main()
{//INICIO DEL MAIN
int pos=0,con1=0;
nodo *inicio=NULL;
char opc=NULL,cadena[10]={'\0'};

//int pos2=0,con2=0;
//nodo *inicio2=NULL;
//char cadena2[10]={'\0'};




do
{//menu principal

clrscr();

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
	  clrscr();
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
 
//	  AQUI  LISTAS SIMPLES ENLAZADAS CIRCULARES
 
	  break;

	  //--------------------------------fin case2-------------------------------

	  case '3':
//	  AQUI LISTAS DOBLES ENLAZADAS
 
	  break;

	  //------------------------------fin case 3 --------------------------------

	  case '4':
 
//	  AQUI LISTAS DOBLES ENLAZADAS CIRCULARES\n");
 
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
nodo *aux=NULL;
aux=(nodo*)malloc (sizeof(nodo));

if (aux!=NULL)
	 {
	 printf("\n\nNombre: ");
	 gets(aux->nombre);
	 printf("\nEdad: ");
	 gets(h);
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
clrscr();

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







