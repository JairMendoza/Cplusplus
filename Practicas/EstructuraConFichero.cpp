#include <stdio.h>
#include <conio.h>
#include <cstdlib>


char producto [30];
char precio [100];

int Rcreado = 0;

char caracter='\0';
char menu();
void insertar();
void mostrar();
void crear ();

int main(void)
{
	char op;
	do{
		op = menu();
		switch(op){
			case '1':
				system("cls");
				crear();
			break;
			case '2':
				system("cls");
				insertar();
			break;
			
			case '3':
				system("cls");
				mostrar();
			break;
		}
	}while(op!='3');
	return 0;
}
char menu(){
	char op;
	system("cls");
	printf("\n  MENU ESTETICA");
	printf("\n [1] Crear");
	printf("\n [2] Mostrar Inventario");
	printf("\n [3] Mostrar Inventario");
	printf("\n [3] Salir");
	printf("\n Opcion: "); fflush(stdin);
	op = getch();
	return op;
}

void Crear ()
{
	system("color C");

	do
	{
		do
		{
			cout << "¿Que archivo desea abrir o crear?: " << endl; 
			gets(carpeta_ori);
			
			unsigned int i;
			lon=strlen(carpeta_ori);
			aux=0;
			for (int i = 0; i < lon; i++)
			{
				if(carpeta_ori[lon-1] == 't' && carpeta_ori[lon-2] == 'x' && carpeta_ori[lon-3] == 't' && carpeta_ori[lon-4] == '.')
				{
					ban = 0;
				}
				else
				{
					ban = 1;
				}
			}
			if(ban == 1)
			{
				cout << "¡Es necesario el punto y la extencion txt!" << endl;
			}
		}while(ban == 1);
		if (lon == 0)
		{
	    	aux=1;
	    	cout << "¡Campo vacio!" << endl;
		}
		if(isspace(lon))
		{
			aux=1;
			cout << "¡No se admiten espacios!" << endl;
		}
	}while(aux == 1);
			
			
    pf = fopen(carpeta_ori, "r");
	
	if(pf==NULL)
	{
		system("color A");
		pf = fopen(carpeta_ori, "w");
		cout << "¡El archivo no exite pero fue creado!" << endl;
		Rcreado=1;
		getch();
	}
	else 
	{
		system("color A");
		cout << "¡Apertura exitosa!" << endl;
		Rcreado=1;
		getch();
	}
	
	fclose(pf);
}

void insertar()
{
	FILE *fich;
	
	if((fich = fopen("Inventario.txt","a"))==NULL)
	{
		printf("\nFichero no existe! ");
	}
	else
	{
		
		printf("\n Ingrese producto: "); fflush(stdin);
		gets(producto);
		printf(" Ingrese precio: "); fflush(stdin);
		scanf("%i",&precio);
	}
		fputs(producto,fich);
		fputs(precio,fich);
		
		fclose(fich);
}

void mostrar(){
	FILE *fich;
	
	char longitudChar[100];
	
	if((fich = fopen("Inventario.txt","r")) == NULL)
	{
		printf("\n Fichero no existe ");
	}
	
	else
	{
   		do
		{	   
	        Rcreado=0;
	        
	        for(int j=0; j < 2; j++)
			{
				for(int i=0; i < 3; i++)
				{
					caracter=fgetc(fich);
					longitudChar[i]=caracter;
				}
		
				Rcreado=atoi(longitudChar);
			
				if(j==0)
				{
					fgets(producto,Rcreado+1,fich);
				}
				if(j==1)
				{
					fgets(precio,Rcreado+1,fich);
				}
			}
			
			if(!feof(fich))
			{
				printf("\n ____________________________");
				printf("\n producto......: %s",producto);
				printf("\n precio........: %i",precio);
				printf("\n ____________________________");
	        }
		}while(caracter!=EOF);
	}
	fclose(fich);
	getch();
}








