#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<iostream>

struct empleados
{
	char num_empleado [100];
	char nombre_empleado [100];
	char domicilio [100];
	char puesto [100];
	char antiguedad [100];
	float salario;
} empleado;

using namespace std;

int main ()
{
	int x,respuesta;
		
	   system ("cls");
       fflush(stdin);
       cout <<"Numero del empleado: \n";
       cin >> empleado.num_empleado;
       fflush(stdin);
       system ("cls");
       cout <<"Nombre del empleado: \n";
       gets  (empleado.nombre_empleado);
       fflush(stdin);
       system ("cls");
       cout <<"Direccion del empleado: 3\n";
       gets (empleado.domicilio);
	   fflush(stdin);
	   system ("cls");
       cout <<"Puesto del empleado: \n";
       gets (empleado.puesto);
	   fflush(stdin);
	   system ("cls");
       cout << "Antiguedad del empleado: \n";
       cin  >> empleado.antiguedad;
	   fflush(stdin);
	   system ("cls");
       cout << "Salario del empleado: \n";
       cin  >> empleado.salario;
	   fflush(stdin);
	   system ("cls");
	 cout << "Deseas ver los datos ingresados preciona 's' \n";
	 cin  >> respuesta;
	 if (respuesta =='s');
	 {
	 	system ("cls");
	 	cout << "Numero del empleado: "     << empleado.num_empleado    << "\n";
	 	cout << "Nombre del empleado: "     << empleado.nombre_empleado << "\n";
	 	cout << "Domicilio del empleado: "  << empleado.domicilio       << "\n";
	 	cout << "Puesto del empleado: "     << empleado.puesto          << "\n";
	 	cout << "Antiguedad del empleado: " << empleado.antiguedad      << "\n";
	 	cout << "Sueldo del empleado: "     << empleado.salario         << "\n";
	 }
	 system("pause");
	 exit(-1);
}
