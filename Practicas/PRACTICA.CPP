#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct empresa
{
  char nombre[50];
  char domicilio[50];
  char puesto;
  char antiguedad;
  char no.empleado[20];
  char salario;
};
struct empresa empleado[99];
void main (void)
{

 char aux[5];
 char laux[5];
 char maux[20];
 char buscar[70];
 char editar[70];
 char borrar;
 int opc=0,bucle=0,band=0, nband=0, z=0, menu=1;
 do{
 fflush(stdin);
 clrscr();
 printf("proporciona una opcion\n");
 printf("1. proporcionar Empleado y los datos del empleado\n");
 printf("2. Mostrar empleados\n");
 printf("3. Buscar empleado\n");
 printf("4. Editar empleado\n");
 printf("5. Eliminar empleado\n");
 printf("6. Salir\n");
 scanf("%i",&opc);
 switch(opc)
 {
  case 1:
	      do{
	      fflush(stdin);
	      clrscr();
	      printf("proporciona el nombre completo del empleado\n");
	      gets(empleado[z].nombre);
	      printf("proporciona la direccion del empleado\n");
	      gets(empleado[z].direccion);
	      printf("proporciona el numero de empleado\n");
	      gets(empleado[z].numero);
	      printf("proporciona el puesto del empleado\n");
	      scanf("%s",&empleado[z].puesto);
	      printf("proporciona la antiguedad\n");
	      scanf("%s",&empleado[z].antiguedad);
	      printf("proporciona el salario\n");
	      scanf("%s",&empleado[z].salario);
	      z++;
	      printf("Desea anadir otro empleado?\nPresione 1 para anadir otro empleado\nPresione cualquier otro numero para salir\n");
	      scanf("%i",&bucle);
	      }while(bucle==1);
	      break;


   case 2:
	      for(int w=0;w<z;w++)
	      {
	       printf("\nEmpleado numero: %i",w+1);
	       printf("\n%s",empleado[w].nombre);
	       printf("\n%s",empleado[w].direccion);
	       printf("\n%s",empleado[w].numero de empleado);
	       printf("\n%s",empleado[w].puesto);
	       printf("\n%s",empleado[w].antiguedad);
	       printf("\n%s",empleado[w].salario);
	      }
	      getch();
	      break;
   case 3:
	      do{
		 clrscr();
		 fflush(stdin);
		 printf("proporciona el empleado que desea bucar\n");
		 gets(buscar);
		 clrscr();
		 for(int w=0;w<z;w++)
		  {
		    if((strcmp(empleado[w].nombre,buscar)==0))
		      {
		       printf("Empleado numero: %i",w+1);
		       printf("\n%s",empleado[w].nombre);
		       printf("\n%s",empleado[w].direccion);
		       printf("\n%s",empleado[w].numero de empleado);
		       printf("\n%s",empleado[a].puesto);
		       printf("\n%s",empleado[a].antiguedad);
		       printf("\n%s",empleado[a].salario);
		      }
		   else
		      {
			band=band+1;
		      }
		  }
	       if(band==z)
		{
		 clrscr();
		 printf("\nNo hay nombre registrado\n");
		}
	      getch();
	      clrscr();
	       printf("\nDesea buscar otro nombre\nPresione 1 para continuar buscando\n");
	       scanf("%i",&bucle);
	       }while(bucle==1);
	      break;

    case 4:   do{
		 clrscr();
		 fflush(stdin);
		 printf("\nIngrese el empleado que desea editar\n");
		 gets(editar);
		 clrscr();
		 for(int z=0;w<z;w++)
		  {
		    if((strcmp(empleado[w].nombre,editar)==0))
		      {
			 printf("\nEmpleado numero: %i",w+1);
			 printf("\n%s",empleado[w].nombre);
			 printf("\n%s",empleado[w].direccion);
			 printf("\n%s",empleado[w].numero de empleado);
			 printf("\n%s",empleado[w].puesto);
			 printf("\n%s",empleado[w].antiguedad);
			 printf("\n%s",empleado[w].salario);
			 printf("\nDesea editar estos datos?\nPresione S para editar, N para no editar\n");
			 fflush(stdin);
			 scanf("%c",&borrar);
			 if(borrar=='s'||borrar=='S')
			  {
			    empleado[w].nombre[0]='\0';
			    empleado[w].direccion[0]='\0';
			    empleado[w].numero de empleado[0]='\0';
			    empleado[w].pesto=0;
			    empleado[w].antiguedad=0;
			    empleado[w].salario=0;
			    for(int b=w;b<z;b++)
			     {
			       empleado[b]=empleado[b+1];
			     }
			       b--;z--;

			     do{
			      fflush(stdin);
			      clrscr();
			      printf("Ingrese el nombre completo del empleado\n");
			      gets(empleado[z].nombre);
			      printf("Ingrese la direccion\n");
			      gets(empleado[z].direccion);
			      printf("Ingrese el numero de empleado\n");
			      gets(empleado[z].numero de empleado);
			      printf("Ingrese el puesto del empleado\n");
			      scanf("%s",&empleado[z].puesto);
			      printf("Ingrese la antiguedad\n");
			      scanf("%s",&empleado[z].antiguedad);
			      printf("\nIngrese el sueldo\n");
			      scanf("%s",&empleado[z].sueldo);
			      z++;
			      printf("\nDesea ingresar otro empleado?\nPresione 1 para ingresar otro empleado\nPresione cualquier otro numero para salir\n");
			      scanf("%i",&bucle);
			      }while(bucle==1);

			     printf("\nLos datos han sido editados\n");
			     getch();
			  }

			   else if(borrar=='n'||borrar=='N')
			    {
			      printf("\nNo se edito nada\n");
			      getch();
			    }
			   else
			    {
			      clrscr();
			      printf("\nElija otra opcion\n");
			      getch();
			    }
		      }
		   else
		   {
		    nband=nband+1;
		   }
		 }
	       if(nband==z)
		{
		 printf("\nNo hay nombre registrado\n");
		}
	      getch();
	      clrscr();
	       printf("\nDesea ingresar otro nombre? Presione 1 para ingresar otro nombre\n");
	       scanf("%i",&bucle);
	       }while(bucle==1);
	      break;

   case 5:     do{
		 clrscr();
		 fflush(stdin);
		 printf("\nIngrese el empleado que desea editar\n");
		 gets(editar);
		 clrscr();
		 for(int w=0;w<z;w++)
		  {
		    if((strcmp(empleado[w].nombre,editar)==0))
		      {
			 printf("Empleado numero: %i",w+1);
			 printf("\n%s",empleado[w].nombre);
			 printf("\n%s",empleado[w].direccion);
			 printf("\n%s",empleado[w].numero de empleado);
			 printf("\n%s",empleado[w].puesto);
			 printf("\n%s",empleado[w].antiguedad);
			 printf("\n%s",empleado[w].salario);
			 printf("\nDesea eliminar estos datos?\nPresione S para borrar, N para no borrar\n");
			 fflush(stdin);
			 scanf("%c",&borrar);
			 if(borrar=='s'||borrar=='S')
			  {
			    empleado[w].nombre[0]='\0';
			    empleado[w].direccion[0]='\0';
			    empleado[w].numero de empleado[0]='\0';
			    empleado[w].edad=0;
			    empleado[w].antiguedad=0;
			    empleado[w].sueldo=0;
			    for(int b=w;b<z;b++)
			    {
			      empleado[b]=empleado[b+1];
			    }
			     b--;z--;
			     printf("\nLos datos han sido eliminados\n");
			     getch();
			  }

			   else if(borrar=='n'||borrar=='N')
			    {
			      printf("\nNo se elimino nada\n");
			      getch();
			    }
			   else
			    {
			      clrscr();
			      printf("\nElija otra opcion\n");
			      getch();
			    }
		      }
		   else
		   {
		    nband=nband+1;
		   }
		 }
	       if(nband==z)
		{
		 printf("\nNo hay nombre registrado\n");
		}
	      getch();
	      clrscr();
	       printf("\nDesea ingresar otro nombre? Presione 1 para ingresar otro nombre\n");
	       scanf("%i",&bucle);
	       }while(bucle==1);
	      break;


   case 6:    exit (0);

   default:  printf("\nIngrese una opcion valida\n");

 }

 }while(menu==1);

}
