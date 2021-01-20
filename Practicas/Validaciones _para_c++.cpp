#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

int ed,dom,num,sig,deci,prop,file,tel,codi;

using namespace std;

int Matricula(char Matri[100])
{
	if (strlen(Matri) == 100)
	{
		if (Matri[0] == NULL)
			return 0;
		for (int i = 0; i < strlen(Matri); i++)
			if (!isdigit(Matri[i]))
				return 0;
		return 1;
	}
	return 0;
}

int Domicilio(char Dom[30])
{
	int Numeros = 0, Letras = 0;
	if (strlen(Dom) <= 30)
	for (int i = 0; i < strlen(Dom); i++)

		if (isdigit(Dom[i]))
			Numeros = 1;
		else
			Letras = 1;

		if (Letras == 1  && Numeros == 1 )
			return 1;
		else
			return 0;
}

int EnteroPositivo(char Num[3])
{
	if (strlen(Num) <= 3)
	{
		num=atoi(Num);
		if(num>130)
	{
		printf("Fuera de rango ingresa nuevamente el dato!\n");
		return 0;
	}
		if (Num[0] == '0')
			return 0;
		for (int i = 0; i < strlen(Num); i++)
			if (!isdigit(Num[i]))
				return 0;
		return 1;
	}
	return 0;
}

int EnteroSigno(char Sig[3])
{
	int Suma = 0, Resta = 0;
	if (strlen(Sig) <= 3)
	{
		sig=atoi(Sig);
	if(sig<0 || sig>130)
	{
		printf("Fuera de rango ingresa nuevamente el dato!\n");
		system("pause");
		return 0;
	}
	if (Sig[0] == '0')
			return 0;
	for (int i = 0; i < strlen(Sig); i++)

		if (Sig[i] == '-')
			Resta = Resta + 1;
		else if (Sig[i] == '+')
			Suma = Suma + 1;
		else if (!isdigit(Sig[i]))
			return 0;
		if (Resta <= 1 && Suma <= 1 )
			return 1;
		else
			return 0;
	}return 0;
}

int PuntoDecimal(char Deci[3])
{
	int Punto = 0;
	if (strlen(Deci) <= 3)
	{
		deci=atoi(Deci);
	if(deci<0 || deci>130)
	{
		printf("Fuera de rango ingresa nuevamente el dato!\n");
		system("pause");
		return 0;
	}
	for (int i = 0; i < strlen(Deci); i++)

		if (Deci[i] == '.')
			Punto = Punto + 1;
		else if (!isdigit(Deci[i]))
			return 0;
		if (Punto == 1)
			return 1;
		else
			return 0;
	}return 0;
}

int NombrePropio (char Prop[30])
{
	if (strlen(Prop) <= 30)
	for (int i = 1; i < strlen(Prop); i++)
		if(Prop[0] >= 'A' && Prop[0] <= 'Z' && Prop[i] >= 'a' && Prop[i] <= 'z' && !isdigit(Prop[i]) )
			return 1;
		else
			return 0;
		return 0;
}

int ArchivoExtencion(char File[13])
{
	int Exte = 0;
	if (strlen(File) <= 13)
	for (int i = 0; i < strlen(File); i++)

		if (File[i] == '.')
			Exte = Exte + 1;
		else if (!isalpha(File[i]))
			return 0;

		if (Exte == 1)
			return 1;
		else
			return 0;
}

int NumTelefono(char Tel[10])
{
	if (strlen(Tel) == 10 || strlen(Tel) == 8)
	{
		if (Tel[0] == '0')
			return 0;
		for (int i = 0; i < strlen(Tel); i++)
			if (!isdigit(Tel[i]))
				return 0;
		return 1;
	}
	return 0;
}

int CodigoPostal(char Codi[5])
{
	if (strlen(Codi) == 5)
	{
		if (Codi[0] == '0')
			return 0;
		for (int i = 0; i < strlen(Codi); i++)
			if (!isdigit(Codi[i]))|
				return 0;
		return 1;
	}
	return 0;
}

int main()
{
	char Matri  [100];
	char Dom    [30];
	char Num    [3];
	char Sig    [3];
	char Deci   [3];
	char Prop   [30];
	char File   [13];
	char Tel    [10];
	char Codi   [5];

	int opcion;
	int salir = 1;
	int ban=0;

	do
	{
		system("cls");
		cout<<"-----------MENU DE VALIDACIONES----------\n"<<endl;
		cout<<"[1]  Registrar Matricula                "<<endl;
		cout<<"[2]  VALIDAR DOMICILIO                  "<<endl;
		cout<<"[3]  VALIDAR NUMERO POSITIVO            "<<endl;
		cout<<"[4]  VALIDAR ENTERO CON SIGNO           "<<endl;
		cout<<"[5]  VALIDAR PUNTO DECIMAL          	"<<endl;
		cout<<"[6]  VALIDAR NOMBRE PROPIO        		"<<endl;
		cout<<"[7]  VALIDAR NOMBRE ARCHIVO       		"<<endl;
		cout<<"[8]  VALIDAR NUMERO CELULAR      		"<<endl;
		cout<<"[9]  VALIDAR CODIGO POSTAL              "<<endl;
		cout<<"[Esc] SALIR                              "<<endl;
		cout<<"\nINGRESE UNA OPCION: ";
		opcion=getch();


		switch(opcion)
		{
			case 49:
			
			// Validacion edad
			

			do{
				system("cls");
			    printf("Ingresa una edad: ");
				gets(Matri);


			    if (Matricula(Matri))
			    {
					cout << "Dato correcto"  << endl;
					ban=1;
			    }
			    else
			    {
					cout << "Dato incorrecto" << endl;
					ban=0;
					system("pause");
			    }
			}while (ban==0);
		    system("pause");

		    break;

		    case 50:

		    // Validacion domicilio
		    

		    do{
		    	system("cls");
			    printf("Ingresa un domicilio: ");
				gets(Dom);

				if (Domicilio(Dom))
				{
					cout << "Dato correcto" << endl;
					ban=1;
				}
				else
				{
					cout << "Dato incorrecto" << endl;
					ban=0;
					system("pause");
				}
				}while (ban==0);
				system("pause");

		    break;

		    case 51:

		    // Validacion positivos
		    
		    do{

			    system("cls");
			    printf("Ingresa un numero positivo: ");
				gets(Num);
				
				if (EnteroPositivo(Num))
				{
					cout << "Dato correcto"  << endl;
					ban=1;
				}
				else
				{
					cout << "Dato incorrecto" << endl;
					ban=0;
					system("pause");
				}
				}while (ban==0);
			    system("pause");

			break;

			case 52:

			// Validacion entero con signo
			
			do
			{
				system("cls");
			    printf("Ingresa un numero entero con signo: ");
				gets(Sig);
					
				if (EnteroSigno(Sig))
				{
					cout << "Dato correcto"  << endl;
					ban=1;
				}
				else
				{
					cout << "Dato incorrecto" << endl;
					ban=0;
					system("pause");
				}
				}while (ban==0);
			    system("pause");

			break;

			case 53:

			// Validacion decimales
		
			do
			{	
				system("cls");
			    printf("Ingresa un numero decimal: ");
				gets(Deci);
				if (PuntoDecimal(Deci))
				{
					cout << "Dato correcto"  << endl;
					ban=1;
				}
				else
				{
					cout << "Dato incorrecto" << endl;
					ban=0;
					system("pause");
				}
				}while (ban==0);
				system("pause");
			
			break;

			case 54:

			// Validacion nombre Propio
		
			do
			{	
				system("cls");
			    printf("Ingresa un nombre propio: ");
				gets(Prop);
				if (NombrePropio(Prop))
				{
					cout << "Dato correcto"  << endl;
					ban=1;
				}
				else
				{
					cout << "Dato incorrecto" << endl;
					ban=0;
					system("pause");
				}
				}while (ban==0);
				system("pause");
			
			break;

			case 55:

			// Validacion nombre archivo
		
			do
			{	
				system("cls");
			 	printf("Ingresa un nombre de un archivo con su extencion: ");
				gets(File);
				if (ArchivoExtencion(File))
				{
					cout << "Dato correcto"  << endl;
					ban=1;
				}
				else
				{
					cout << "Dato incorrecto" << endl;
					ban=0;
					system("pause");
				}
				}while (ban==0);
				system("pause");

			break;

			case 56:

			// Validacion numero de telefono
			
			do
			{	
				system("cls");
				printf("Ingresa un numero de telefono celular: ");
				gets(Tel);
				if (NumTelefono(Tel))
				{
					cout << "Dato correcto"  << endl;
					ban=1;
				}
				else
				{
					cout << "Dato incorrecto" << endl;
					ban=0;
					system("pause");
				}
				}while (ban==0);
				system("pause");

			break;

			case 57:

			// Validacion codigo postal
		
			do
			{	
				system("cls");
				printf("Ingresa un numero de telefono celular: ");
				gets(Codi);
				if (CodigoPostal(Codi))
				{
					cout << "Dato correcto"  << endl;
					ban=1;
				}
				else
				{
					cout << "Dato incorrecto" << endl;
					ban=0;
					system("pause");
				}
				}while (ban==0);
				system("pause");
			
			break;

		    case 27: exit(-1);
		}
	}while(salir==1);
    return 0;
}
