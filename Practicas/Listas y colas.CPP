#include <iostream.h> 
#include <stdlib.h>
#include <conio.h>
 
struct nodo
{
    int nro;
    struct nodo *pnt;
};
 
typedef nodo *ptrPila;  
 

void push( ptrPila &p, int valor )
{
     ptrPila aux;
     aux = new(struct nodo); 
     aux->nro = valor;
     
     aux->pnt = p ;
     p = aux ;
}
 
int pop( ptrPila &p )
{
     int num ;
     ptrPila aux;
     
     aux = p ;
     num = aux->nro; 
     
     p = aux->pnt ;
     delete(aux);
     
     return num;
}
 
void mostrar( ptrPila p )
{
     ptrPila aux;
     aux = p;   
     
     while( aux !=NULL )
     {
            cout<<"\t"<< aux->nro <<endl;
            aux = aux->pnt;
     }    
}

void eliminar( ptrPila &p)
{
     ptrPila aux;
     
     while( p != NULL)
     {
           aux = p;
           p = aux->pnt;
           delete(aux);
     }
}

void menu()
{
    cout<<"-------Menu de los programas-------"<<endl;
    cout<<"1. PROGRAMA PILA                          "<<endl;
    cout<<"2. PROGRAMA COLA                          "<<endl;
    cout<<"3. SALIR                                  "<<endl;
}
 
void submenupila()
{
    cout<<"**************Programa Pila***************"<<endl;
    cout<<" 1. INTRODUCIR                            "<<endl;
    cout<<" 2. ELIMINAR                              "<<endl;
    cout<<" 3. MOSTRAR PILA                          "<<endl;
    cout<<" 4. ELIMINAR PILA                         "<<endl;
    cout<<" 5. SALIR                                 "<<endl;
    cout<<"\n INGRESE UNA OPCION: ";
}

void submenucola()
{
    cout<<"**************Programa Cola***************"<<endl;
    cout<<" 1. INTRODUCIR                            "<<endl;
    cout<<" 2. ELIMINAR                              "<<endl;
    cout<<" 3. MOSTRAR PILA                          "<<endl;
    cout<<" 4. ELIMINAR PILA                         "<<endl;
    cout<<" 5. SALIR                                 "<<endl;
    cout<<"\n INGRESE UNA OPCION: ";
}
 
int main()
{
    ptrPila p = NULL;
    int dato;
    int opcion,opcion1,opcion2;
    int x ;

    do
    {
    menu ();  cin>> opcion;

    switch(opcion)
    {
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
    }

    do
    {
    submenucola ();  cin>> opcion2;

    switch(opcion2)
    {
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
    }

    do
    {
    submenupila (); cin>> opcion1;

    switch(opcion1)
    {
        case 1:

              cout<< " "; cin>> dato;
              push( p, dato );
              cout<<"\n\n\t\tNumero " << dato << " apilado.\n\n";
        break;


        case 2:

              x = pop( p );
              cout<<"\n\n\t\tNumero "<< x <<" desapilado.\n\n";
        break;


        case 3:

         if(p!=NULL)
              mostrar( p );
         else
              cout<<"\n\n\tPila vacia."<<endl;
        break;


        case 4:

                eliminar( p );
                cout<<"\n\n\t\tPila eliminada.\n\n";
            break;
           
         }

    
 
        cout<<endl<<endl;
        system("pause");  system("cls");


    }while(opcion2!=5);
    }while(opcion1!=5);
    }while(opcion!=3);
    

   
   
    return 0;
}



