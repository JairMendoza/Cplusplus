
/*Ejemplo1. Clases_Amigas.
El siguiente código del programa correspondiente a la aplicación de clases, objetos, métodos.
En donde deberás introducir los datos de los dos pacientes A y B manualmete los cuales son:
(Nombre,Edad y Padecimiento) por consecutivo tambien deberas introduccir los datos del medico
(Nombre y Especialidad). 
Una vez ingresados se procedera a mostrar los datos del paciente A enlazados con el medico, 
asi mismo sucedera con el paciente B enlazado con el medico. 
INTEGRANTES: GABRIEL ADÁN ESTRADA ORTIZ, JORGE RICARDO TORRES PADILLA, ARTURO CUEVAS PÉREZ.
FECHA DE ELABORACION: 09/03/2018 4:00 pm */

// Librerias 
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<windows.h>

using namespace std;

//Prototipo de la clase paciente, La definicion se encuentra mas adelante
class Paciente;

//Definicion de la clase Medico
class Medico
{
private: // Se declaran variables necesarias para la clase medico
    char NombreCompleto[100],Especialidad[100];
public:
    Medico(); //Constructor por omision
    Medico(char *NomCom, char *Esp); // Constructor con parametros
    char *ObtenerNombreCompleto();
    char *ObtenerEspecialidades();
    void  ImprimeDatos();
    friend class Paciente;
};

//Constructor por omision
Medico::Medico()
{

}

//Contrsuctor con parametros
Medico::Medico(char *NomCom, char *Esp)
{
    strcpy(NombreCompleto,NomCom); // Funciones que copea el contenido Nomcom a NombreCompleto
    strcpy(Especialidad,Esp);  // Funcion que hace lo mismo que la anterior
}

//Metodo que permite, a los usuarios externos a la clase, conocer el nombre del medico
char *Medico::ObtenerNombreCompleto()
{
    return NombreCompleto;
}

//Metodo que permite, a los usuarios externos a la clase, conocer la especialidad del medico
char *Medico::ObtenerEspecialidades()
{
    return Especialidad;
}

//Metodo que despliega los valores de los atributos de un medico
void Medico::ImprimeDatos(void)
{
    cout << "Nombre Completo del medico: " << NombreCompleto << endl;
    cout << "Especialidades: " << Especialidad << endl;
}

//Definciion de la clase Paciente
class Paciente
{
private: // Se declaran variables necesarias para la clase paciente
    char NombreCompleto[100];
    int  Edad;
    char Padecimiento[100];
    Medico *MedicoEspecialista;
public:
    Paciente();
    Paciente(char *Nomcom, int Ed, char *Pad);
    char *ObtenerNombreCompleto();
    int  ObtenerEdad();
    char *ObtenerPadecimiento();
    void AsociarMedico();
    void ImprimeDatos();
};

//Constructor por omision
Paciente::Paciente()
{

}

//Constructor con parametros
Paciente::Paciente(char *Nomcom, int Ed, char *Pad)
{
    strcpy(NombreCompleto,Nomcom);
    Edad=Ed;
    strcpy(Padecimiento,Pad);
}

//Metodo que permite, a los usuarios externos de la clase, conocer el nombre del paciente
char *Paciente::ObtenerNombreCompleto()
{
    return NombreCompleto;
}
//Metodo que permite, a los usuarios externos de la clase, conocer la edad del paciente
int Paciente::ObtenerEdad()
{
    return Edad;
}

//Metodo que permite, a los usuarios externos a la clase, conocer el nombre del padecimiento del paciente
char *Paciente::ObtenerPadecimiento()
{
    return Padecimiento;
}

/*Metodo que asocia un medico especialista a cada paciente. Note como el miembro MedicoEspecialista (de tipo puntero
a un objeto tipo Medico). tiene acceso a los miembros privados de la clase Medico*/

void Paciente::AsociarMedico() // Capturamos los datos del medico enlazadas a sus respectivas variables
{
    MedicoEspecialista=new Medico();
    cout << "Ingresa el nombre completo del Medico: ";
    cin  >> MedicoEspecialista->NombreCompleto;
    cout << "Ingresa la especialidad: ";
    cin  >> MedicoEspecialista->Especialidad;
}


//Metodo que despliega los valores de los atributos de un paciente
void Paciente::ImprimeDatos() // Imprimimos los datos del paciente y medico
{
    cout << "\n Nombre completo: " << NombreCompleto << endl;
    cout << "\n Edad:   " << Edad << endl;
    cout << "\n Padecimiento: " << Padecimiento << endl;
    cout << "\n Datos del Medico Especialista: " << endl;
    MedicoEspecialista->ImprimeDatos();
}

void UsaClaseAmiga() // Capturamos los datos del paciente A y B. Que despues muestrara los datos del paciente junto con el medico enlazado
{
    char NombreA[40],PadecimientoA[40],NombreB[40],PadecimientoB[40];
    int  Edad1,Edad2;

    cout << "DATOS DEL PACIENTE A " << endl;
    cout << "======================\n";
    cout << "Nombre:"; gets(NombreA);
    cout << "Padecimiento: "; gets(PadecimientoA);
    cout << "Edad: "; cin >> Edad1;

    fflush(stdin);
    cout << "\nDATOS DEL PACIENTE B " << endl;
    cout << "======================\n";
    cout << "Nombre:"; gets(NombreB);
    cout << "Padecimiento: "; gets(PadecimientoB);
    cout << "Edad: "; cin >> Edad2;

    Paciente ObjetoPacienteA(NombreA,Edad1,PadecimientoA);
    Paciente ObjetoPacienteB(NombreB,Edad2,PadecimientoB);

    cout << "Paciente A: " << endl;
    ObjetoPacienteA.AsociarMedico();
    cout << "Datos del paciente A: " << endl;
    ObjetoPacienteA.ImprimeDatos();
    system("pause");


    cout << "Paciente B: " << endl;
    ObjetoPacienteB.AsociarMedico();
    cout << "Datos del paciente B: " << endl;
    ObjetoPacienteB.ImprimeDatos();
    system("pause");
}

int main()
{
    UsaClaseAmiga(); // Inicializacion de la claseamiga que ayuda entructurar bien los datos enlazados
    return 0;
}
