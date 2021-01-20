
/*Este programa construye una clase llamada Rectángulo que contiene los siguientes atributos: largo y ancho,
y los siguientes métodos: perímetro y área. Se hace uso de Templates. El programa deberá obtener el área y perímetro de un rectángulo 
con datos leídos desde consola.
INTEGRANTES: GABRIEL ADÁN ESTRADA ORTIZ, JORGE RICARDO TORRES PADILLA, ARTURO CUEVAS PÉREZ.
FECHA DE ELABORACION: 22/03/2018 9:00 am.*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

template <class TipoDato> // Creamos el Template a usar llamada TipoDato y llamamos en cada una de las funciones
class Rectangulo // Creamos la clase llamada Rectangulo
{
	private: // Variables tipo flotantes para hacer las operaciones
    TipoDato largo;
    TipoDato ancho;

	public: // Declaramos metodos y contructor
    Rectangulo(TipoDato,TipoDato);
    TipoDato Perimetro();
    TipoDato Area();
};

template <class TipoDato>
Rectangulo<TipoDato>::Rectangulo(TipoDato l,TipoDato a) // Construtor con parametros necesarios
{
    largo=l;
    ancho=a;
}

template <class TipoDato>
TipoDato Rectangulo<TipoDato>::Perimetro() // Metodo operacion perimetro
{
    TipoDato lado1,lado2,perimetro_;
    lado1=largo*2;
    lado2=ancho*2;

    perimetro_=lado1+lado2;

    cout << "\nEl perimetro del rectangulo es " << perimetro_ << endl;
    getch();
}

template <class TipoDato>
TipoDato Rectangulo<TipoDato>::Area() // Metodo operacion perimetro
{
    TipoDato area_;

    area_=largo*ancho;

    cout << "\n\nEl area del rectangulo es " << area_ << endl;
}


int main() // Capturamos datos por consola y validamos que sean correctos
{
    float ancho_,largo_;
    int bandera=0;
    do
    {

     system("cls");
     cout << "Ingres el ancho del rectangulo: ";
     cin  >> ancho_;
     cout << "Ingres el largo del rectangulo: ";
     cin  >> largo_;

     if(ancho_==largo_ || (ancho_==0 || largo_==0))
     {
         cout << "No es un rectangulo..." << endl;
         getch();
         bandera=0;
     }
     else
     {
         bandera=1;
     }

    }while(bandera!=1);


    Rectangulo <float> A1(largo_,ancho_); // Asignamos el tipo de dato flotante al Template que es que deseamos utilizar

    A1.Area();
    A1.Perimetro();

    system("pause");
    return 0;
}
