#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<windows.h>

using namespace std;

// Prototipo de la plantilla clase Arbol Binario
template <class T>
class ArbolBinario;


template <class T>
class NodoArbol
{
	private:
		T Info;
		NodoArbol <T> *HijoIzq;
		NodoArbol <T> *HijoDer;
		
	public:
		NodoArbol(); // Constructor
		T RegresaInfo ();
		void ActualizaInfo (T);
		friend class ArbolBinario <T>;
};


/* Constructor por omision, inicializa las ligas a los subarboles
cone el valor NULL, indicando que estan vacias */
// Constructor
template <class T>
NodoArbol <T> :: NodoArbol()
{
	HijoIzq = NULL;
	HijoDer = NULL;
}


// FUNCIONES

/* Permite conocer la informacion almacenada */
template <class T>
T NodoArbol <T> :: RegresaInfo()
{
	return Info;
}

template <class T>
void NodoArbol <T> :: ActualizaInfo (T Dato)
{
	Info = Dato;
}


// Class ArbolBinario
template <class T>
class ArbolBinario
{
	private:
		NodoArbol <T> *Raiz;
	public:
		ArbolBinario();
		NodoArbol <T> *RegresaRaiz();
		void CrearArbol (NodoArbol <T> *);
		void ImprimeIzq (NodoArbol <T> *);
};


/* Constructor, incializa el puntero a la raiz con el valor NULL, indicando que el arbol
esta vacio (no tiene nodos) */
template <class T>
ArbolBinario <T> :: ArbolBinario()
{
	Raiz = NULL;
}

// REGRESA RAIZ
template <class T>
NodoArbol <T> *ArbolBinario <T> :: RegresaRaiz()
{
	return Raiz;
}

// CREAR ARBOL BINARIO
template <class T>
void ArbolBinario <T> :: CrearArbol(NodoArbol <T> *Apunt)
{
	char resp;
	// Se creo un nodo
	Apunt = new NodoArbol <T>;
	cout << "Ingresa el dato a almacenar: ";
	cin  >> Apunt -> Info;
	cout << "\n\n " << Apunt -> Info << endl;
	cout << "Tiene hijo izquierdo? (S/N) ";
	cin  >> resp;
	resp = toupper(resp);
	if(resp == 'S')
	{
		CrearArbol (Apunt -> HijoIzq);
		Apunt -> HijoIzq = Raiz;
	}
	
	cout << "\n\n\t " << Apunt -> Info << endl;
	cout << "Tiene hijo derecho? (S/N) ";
	cin  >> resp;
	resp = toupper(resp);
	if(resp == 'S')
	{
		CrearArbol (Apunt -> HijoDer);
		Apunt -> HijoDer = Raiz;
	}
	Raiz = Apunt;
}

// IMPRIME
template <class T>
void ArbolBinario <T> :: ImprimeIzq (NodoArbol <T> *Apunt)
{
	if (Apunt)
	{
		if (Apunt -> HijoIzq)
		{
			cout << Apunt -> HijoIzq -> Info;
			ImprimeIzq (Apunt -> Hijoizq);
		}
		ImprimeIzq (Apunt -> HijoDer);
	}
}


// APLICACION PLANTILLA class persona

// Definicion de la clase Persona
class Persona
{
	private:
		char NomPers[100],
	public:
		Persona(); // Constructor
		Persona(char[]);
		friend istream & operator >> (istream &, Persona&);
		friend ostream & operator >> (ostream &, Persona&);
};

// Constructor 
Persona :: Persona()
{
}

// Constructor con parametros
Persona :: Persona (char NomP[])
{
	strcpy (NomPers, NomP);
}

/* Sobrecarga del operador >> para lectura de objetos tipo Persona */
istream & operator >> (istream & Lee, Persona & ObjPers)
{
	cout << "\n\n Ingrese nombre de la persona: ";
	Lee  >> ObjPers.NomPers;
	return Lee;
}

/* Sobrecarga del operador >> para la escritura de objetos tipo Persona */
ostream & operator << (ostream & Escribe, Persona & ObjPers)
{
	Escribe << ObjPers.NomPers << endl;
	return Escribe;
}

int main ()
{
	ArbolBinario <Persona> Genealogico;
	Persona Individuo;
	NodoArbol <Persona> *Ap;
	Ap = Genealogico.RegresaRaiz();
	Genealogico.CrearArbol(Ap);
	Ap = Genealogico.RegresaRaiz();
	Individuo = Ap -> RegresaInfo();
	cout << "     Descendientes de:    ";
	cout << Individuo << endl;
	Genealogico.ImprimeIzq(Ap);
	system("pause");
}
