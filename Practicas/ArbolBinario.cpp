/*La práctica consta en desarrollar un algoritmo para representar la estructura de un árbol binario, 
en el cual cada nodo contiene un dato, los cuales están relacionados a su ves con más datos, 
los cuales pueden ser recorridos por los métodos de pre-orden, in-orden y pos-orden.

INTEGRANTES: GABRIEL ADÁN ESTRADA ORTIZ, JORGE RICARDO TORRES PADILLA, ARTURO CUEVAS PÉREZ.
FECHA DE ELABORACION: 12/04/2018 9:00 pm.*/

// Comentario: No supimos cómo hacerlo con nombres porque no sabiamos cuáles tenian que ir a la izquierda y cuáles a la derecha disculpe.
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct nodo // Struct necesario llamado nodo con sus respectivos punteros *izq y *der
{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ArbolBinario; /* este es  un puntero de tipo nodo que hemos llamado Arbol Binario, 
que ulitizaremos para mayor facilidad de creacion de variables */

ArbolBinario crearNodo(int x) // Creacion de nodos izquierdos y derechos
{
     ArbolBinario nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ArbolBinario &arbol, int x) // Funcion para insertar nodos
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ArbolBinario arbol) // Funcion que orden los vectores en Pre orden
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void inOrden(ArbolBinario arbol) // Funcion que orden los vectores en In orden
{
     if(arbol!=NULL)
     {
          inOrden(arbol->izq);
          cout << arbol->nro << " ";
          inOrden(arbol->der);
     }
}

void postOrden(ArbolBinario arbol) // Funcion que orden los vectores en Post orden
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(ArbolBinario arbol, int n) // Funcion que muestra el arbol girado 90° a la izquierda
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}

int main()
{
    ArbolBinario arbol = NULL;   // Arbol creado

    int n;  // Numero de nodos del arbol
    int x; // Elemento a insertar en cada nodo

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }
	
	system("cls");
    cout << "\n Mostrando Arbol Binario girado en 90° \n\n";
    verArbol( arbol, 0);

    cout << "\n Recorridos del Arbol Binario";

    cout << "\n\n In orden   :  ";   inOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);

    cout << endl << endl;

    getch();
    return 0;
}
