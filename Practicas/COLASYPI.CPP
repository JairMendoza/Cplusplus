#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include<stdio.h>
void menupilas();
void menucolas();
struct nodo
{
    int datoo;
    struct nodo *pnt;
};

typedef nodo *ptrPila;
void push( ptrPila &pila, int espacio )
{
     ptrPila aux;
     aux = new(struct nodo);
     aux->datoo = espacio;

     aux->pnt = pila;
     pila = aux ;
}

int pop( ptrPila &pila )
{
     int num;
     ptrPila aux;

     aux = pila ;
     num = aux->datoo;

     pila = aux->pnt ;
     delete(aux);

     return num;
}

void mostrar( ptrPila pila )
{
     ptrPila aux;
     aux = pila;

     while(aux !=NULL )
     {
	    cout<<"\t"<< aux->datoo <<endl;
	    aux = aux->pnt;
     }
}
struct nodo1
{
    int dato3;
    struct nodo1 *pnt;
};

struct cola
{
    nodo1 *delante;
    nodo1 *atras  ;
};

void meter( struct cola &c, int valor )
{
     struct nodo1 *aux = new(struct nodo1);

     aux->dato3 = valor;
     aux->pnt = NULL;

     if( c.delante == NULL)
	 c.delante = aux;
     else
	 (c.atras)->pnt = aux;

     c.atras = aux;

}

int sacar( struct cola &c )
{
     int num ;
     struct nodo1 *aux ;

     aux = c.delante;
     num = aux->dato3;
     c.delante = (c.delante)->pnt;
     delete(aux);

     return num;
}

void mostrar( struct cola c )
{
     struct nodo1 *aux;

     aux = c.delante;

     while( aux != NULL )
     {
	    cout<<"   "<< aux->dato3;
	    aux = aux->pnt;
     }
}

void main(void)
{
    struct cola c;

    c.delante = NULL;
    c.atras   = NULL;
    int dato1;
    int x1 ;
    ptrPila p = NULL;
    int dato;
    int opcion;
    int x ;

  int opc, opc1, opc2;
     clrscr();
    do
    {

       printf("\tPilas dinamicas y Colas dinamicas\n");
       printf("\n\t1.- .:Pilas Dinamicas");
       printf("\n\t2.- .:Colas dinamicas");
       printf("\n\t3.- .:Salir");

       printf("\n\n\tEscoja una opcion: ");
       scanf("%d",&opc);



       switch(opc)
       {
	case 1: do
		{
		 menupilas();
		scanf("%d",&opc1);
		switch(opc1)
		{
		 case 1: clrscr();
		      printf("Ingrese elemento a la pila\n"); scanf("%d",&dato);
		      push( p, dato );
		      printf("Numero %d agregado correctamente.",dato);
		      break;

		 case 2: clrscr();
			int ban=1;
			 x = pop( p );
			 if(ban==0)
			 {
			  printf("La Pila Esta Vacia");
			  clrscr();
			 }
			 else
			 {
			 printf("Numero %d eliminado.",x);
			 }
			 break;

		 case 3: clrscr();
			 if(p!=NULL)
			 mostrar( p );
			 else
			 printf("Pila vacia.");
			 break;
	    case 4:  main();
		     getch();
		     break;
	    case 27: exit(0);

	    default: printf("Error!!!! ingrese los datos que se le pidan.\n");

	    break;
		}
		}while(opc1!=27);
		break;
	  case 2:do
		{
		clrscr();
		menucolas();
		scanf("%d",&opc2);
		switch(opc2)
		{
		 case 1: clrscr();
		  printf("Ingrese los elementos a la cola: "); scanf("%d",&dato1);
		 meter( c, dato1 );
		 printf("Numero %d agregado correctamente.",dato1);
		 getch();
		 break;

		 case 2:clrscr();
		 x1= sacar( c );
		 if(x1==0)
		 {
		 printf("La Cola esta vacia");

		 }
		 else
		 {

		 printf("Numero %d eliminado",x1);
		 }
		 getch();
		 break;
		 case 3: clrscr();
		 if(c.delante!=NULL) mostrar( c );
		 else   printf("Cola vacia.");
		 getch();
		 break;
		 case 4:main();
			getch();
			break;
		 case 5: exit(0);
		 break;
		 default: printf("\nError!!!! ingrese los datos que se le pidan.\n");
		 }
		 }while(opc2!=5);
		 break;


	 case 3: exit(0);
	  default: printf("\nError!!!! ingrese los datos que se le pidan.\n");
       }

     }while(opc!=3);
     exit(0);
}
void menupilas()
{
		printf("\nPilas Dinamicas\n");
		printf("\n1. Introducir\n");
		printf("\n2. Eliminar\n");
		printf("\n3. Mostrar\n");
		printf("\n4. Volver a menu\n");
		printf("\n5. Salir\n");
		printf("\nOpcion: \n");
}
void menucolas()
{
		printf("\nColas Dinamicas\n");
		printf("\n1. Agregar\n");
		printf("\n2. Eliminar\n");
		printf("\n3. Mostrar\n");
		printf("\n4. Regresar al menu\n");
		printf("\n5. Salir");
		printf("\n Opcion agregada: \n");

}

