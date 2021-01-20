#include<iostream>
#include<stdlib.h>

using namespace std;

class Persona
{
	private:
		string nombre;
		int edad;
		
		public:
			Persona(int,string);
			void Leer ();
			void Correr ();
};

Persona :: Persona (int e,string n)
{
	edad = e;
	nombre = n;
}

void Persona :: Leer ()
{
	cout << "Soy " << nombre << " y estoy leyendo un libro" << endl;
}

void Persona :: Correr ()
{
	cout << "Soy " << nombre << " y estoy corriendo un maraton y tengo " << edad << " años" << endl;
}

int main ()
{
	Persona p1= Persona (20,"Pedro");
	Persona p2= Persona (19,"Maria");
	Persona p3= Persona (32,"Juan");
	
	p1.Leer();
	p2.Correr();
	
	p3.Leer();
	p3.Correr();
	
	system("pause");
}
