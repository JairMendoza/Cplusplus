
/*Este programa construye una clase llamada Rectángulo que contiene los siguientes atributos: largo y ancho,
y los siguientes métodos: perímetro y área. El programa deberá obtener el área y perímetro de un rectángulo 
con datos leídos desde consola.
INTEGRANTES: GABRIEL ADÁN ESTRADA ORTIZ, JORGE RICARDO TORRES PADILLA, ARTURO CUEVAS PÉREZ.
FECHA DE ELABORACION: 22/03/2018 9:00 am.*/

// Librerias necesarias
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Rectangulo // Creamos la clase llamada Rectangulo
{
	private: // Variables tipo flotantes para hacer las operaciones
	float largo;
    float ancho;

	public: // Declaramos metodos y contructor
	Rectangulo(float,float);
    void Perimetro();
    void Area();
};

Rectangulo::Rectangulo(float l,float a)  // Construtor con parametros necesarios
{
    largo=l;
    ancho=a;
}

void Rectangulo::Perimetro() // Metodo operacion perimetro
{
    float lado1,lado2,perimetro_;
    lado1=largo*2;
    lado2=ancho*2;

    perimetro_=lado1+lado2;

    cout << "\nEl perimetro del rectangulo es " << perimetro_ << endl;
    getch();
}

void Rectangulo::Area() // Metodo operacion perimetro
{
    float area_;

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


    Rectangulo A1(largo_,ancho_);

    A1.Area();
    A1.Perimetro();

    system("pause");
    return 0;
}

