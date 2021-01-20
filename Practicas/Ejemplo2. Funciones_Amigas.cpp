
/*Ejemplo2. Funciones_Amigas.
El siguiente código del programa correspondiente a la aplicación de clases, objetos, métodos.
En donde deberás introducir los datos manualmete asi mismo mostrar cada uno de los atributos
que introduciste (Valor 1 y Valor 2), consecutivamente sumar los dos atributos mas el valor 10 
ya establecido en el codigo del programa.
INTEGRANTES: GABRIEL ADÁN ESTRADA ORTIZ, JORGE RICARDO TORRES PADILLA, ARTURO CUEVAS PÉREZ.
FECHA DE ELABORACION: 09/03/2018 4:30 pm */

// Librerias Necesarias
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<windows.h>

using namespace std; 

//funciones amigas
class Ejemplo
{
	private:
		int Atrib1, Atrib2;
		public:
			Ejemplo();
			Ejemplo(int, int);
			void Imprime();
			friend int Suma(int, Ejemplo);	
};//fin de la funcion amiga

//constructor por omision
Ejemplo::Ejemplo()
{
	
}

//construtor con parametros
Ejemplo::Ejemplo(int Num1, int Num2)
{
	Atrib1=Num1;
	Atrib2=Num2;
}

//metodo que despliega valores de los atributos de la clase
void Ejemplo::Imprime()
{
	system("cls");
	cout<<"\nvalor del primer atributo: "<<Atrib1<<endl;
	cout<<"\nValor del segundo atributo: "<<Atrib2<<endl;
}

//funcion declarada como amiga de la clase ejemplo
int Suma(int Dato, Ejemplo Valor)
{
	return (Dato+Valor.Atrib1+Valor.Atrib2);
}

//funcion para capturar los datos leerlos y dar el resultado de la suma 
void UsaFuncionesAmigas()
{
	int num1,num2;
	int Resultado;
	
	cout<<"\nvalor 1: ";
	cin >> num1;
	cout<<"\nValor 2: ";
	cin >> num2;
	system("pause");

	Ejemplo ObjEjemplo(num1,num2);
	
	ObjEjemplo.Imprime();
	
	Resultado=Suma(0,ObjEjemplo);
	cout<<"\n\nEl Resultado de la suma es: "<<Resultado<<endl;
}
//el main para llamar a la funcion UsaFuncionesAmigas 
int main ()
{
	UsaFuncionesAmigas();
	return 0;
}
