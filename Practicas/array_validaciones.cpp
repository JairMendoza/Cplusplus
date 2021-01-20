#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>
#include<locale.h>

typedef struct alumno{
   char carne[32];
   char nombre[20];
   char direccion[30];
   char correoe[20];
   int  nota1;
   int  nota2;
   int  nota3;
   int  nota4;
   int  tot;
   }Alumno;

/* Arreglo que almacena alumnos */
Alumno alumnos[40];
/* Contiene el numero de alumnos actual */
int total = 0;

void cargar(), guardar(), insertar(Alumno info);
void ingresar(), buscar(), modificar(), eliminar(), ordenar(), mostrar(), ayuda();
char menu(void);

main()
{


   cargar();
   char op;

   for(;;)
   {
     switch(op=menu())
     {
        case '1':
           ingresar();
           getch();
           break;
        case '2':
           buscar();
           getch();
           break;
        case '3':
           modificar();
           getch();
           break;
        case '4':
           eliminar();
           getch();
           break;
        case '5':
           ordenar();
           getch();
           break;
        case '6':
           mostrar();
           getch();
           break;
        case '7':
           ayuda();
           getch();
           break;
        case '8':
           break;
        default :
           printf("Opcion no valida");
           getch();
           break;
     }

     if(op=='8') break;

   }

   printf("Presione (g) para guardar los cambios: ");

   if(getche()=='g')
      guardar();
}


void insertar(Alumno info)
{
   strcpy(alumnos[total].carne, info.carne);
   strcpy(alumnos[total].nombre, info.nombre);
   strcpy(alumnos[total].direccion, info.direccion);
   strcpy(alumnos[total].correoe, info.correoe);
   alumnos[total].nota1 = info.nota1;
   alumnos[total].nota2 = info.nota2;
   alumnos[total].nota3 = info.nota3;
   alumnos[total].nota4 = info.nota4;
   alumnos[total].tot = info.tot;
   total++;
}

void cargar()
{
   Alumno info;
   FILE *fp;

   fp=fopen("alumnos.txt","r");
   if(fp==NULL)
   {
      printf("No se puede abrir el archivo\n");
      return;
   }

   while(!feof(fp))
   {
      if(fread(&info, sizeof(Alumno), 1, fp)!=1) break;
      insertar(info);
   }

   fclose(fp);
}

void guardar()
{
   Alumno info;
   FILE *fp;

   fp=fopen("alumnos.txt","w");
   if(fp==NULL)
   {
      printf("No se puede abrir el archivo\n");
      return;
   }

   for(int i=0; i<total; i++)
     fwrite(&alumnos[i], sizeof(Alumno), 1, fp);

   fclose(fp);
}

void ingresar()
{
   Alumno info;

   printf("Ingrese carne: "); gets(info.carne);
   printf("Ingrese nombre: "); gets(info.nombre);
   printf("Ingrese direccion: "); gets(info.direccion);
   printf("Ingrese Correo:"); gets(info.correoe);
   printf("Ingrese Parcial No 1: "); scanf("%d", &(info.nota1));
   printf("Ingrese Parcial No 2: "); scanf("%d", &(info.nota2));
   printf("Ingrese Zona: "); scanf("%d", &(info.nota3));
   printf("Ingrese Exmen Final: "); scanf("%d", &(info.nota4));
   insertar(info);
   printf("Alumno ingresado exitosamente\n");
}

void buscar()
{
   char carne[32];
   int i;

   printf("Ingrese carne a buscar: ");
   gets(carne);



   for(i=0; i<total; i++)
      if(!strcmp(alumnos[i].carne, carne))
      {
  printf("--- Datos del alumno ---\n");
  printf("Num.: %d\n", i+1);
    printf("Carné: %s\n", alumnos[i].carne);
  printf("Nombre: %s\n", alumnos[i].nombre);
  printf("Direccion: %s\n", alumnos[i].direccion);
  printf("Correo: %s\n", alumnos[i].correoe);
  printf("Nota1: %d", alumnos[i].nota1);
    printf("Nota2: %d", alumnos[i].nota2);
    printf("Nota3: %d", alumnos[i].nota3);
    printf("Nota4: %d", alumnos[i].nota4);
    printf("Promedio: %d", alumnos[i].nota1+alumnos[i].nota2+alumnos[i].nota3+alumnos[i].nota4);
    break;
      }

   if(i==total)
      printf("Alumno no encontrado");
}

void modificar()
{
   char nombre[20];
   int i;

   printf("Ingrese nombre a modificar: ");
   gets(nombre);

   for(i=0; i<total; i++)
      if(!strcmp(alumnos[i].nombre, nombre))
      {
  printf("--- Datos actuales del alumno ---\n");
  printf("Num.: %d\n", i+1);
    printf("Carné: %s\n", alumnos[i].carne);
  printf("Nombre: %s\n", alumnos[i].nombre);
  printf("Direccion: %s\n", alumnos[i].direccion);
   printf("correo: %s\n", alumnos[i].correoe);
      printf("Nota1: %d\n\n", alumnos[i].nota1);
     printf("Nota2: %d\n\n", alumnos[i].nota2);
     printf("Nota3: %d\n\n", alumnos[i].nota3);
     printf("Nota4: %d\n\n", alumnos[i].nota4);
         printf("--- Nuevos datos del alumno ---\n");
         printf("Carné: %s\n", alumnos[i].carne);
         printf("Ingrese nombre: "); gets(alumnos[i].nombre);
         printf("Ingrese direccion: "); gets(alumnos[i].direccion);
         printf("Ingrese correo: "); gets(alumnos[i].correoe);
         printf("Ingrese nota1: "); scanf("%d", &(alumnos[i].nota1));
         printf("Ingrese nota2: "); scanf("%d", &(alumnos[i].nota2));
         printf("Ingrese nota3: "); scanf("%d", &(alumnos[i].nota3));
         printf("Ingrese nota4: "); scanf("%d", &(alumnos[i].nota4));

         printf("\n\nDatos actualizados exitosamente!");

         break;
      }

   if(i==total)
      printf("Alumno no encontrado");
}

void eliminar()
{
   char nombre[20];
   int i;

   printf("Ingrese nombre a eliminar: ");
   gets(nombre);

   for(i=0; i<total; i++)
      if(!strcmp(alumnos[i].nombre, nombre))
      {
         /* Recorre registros posteriores */
         for(int j=i+1; j<total; j++)
         {
            strcpy(alumnos[j-1].carne, alumnos[j].carne);
            strcpy(alumnos[j-1].nombre, alumnos[j].nombre);
            strcpy(alumnos[j-1].direccion, alumnos[j].direccion);
            strcpy(alumnos[j-1].correoe, alumnos[j].correoe);
            alumnos[j-1].nota1 = alumnos[j].nota1;
            alumnos[j-1].nota2 = alumnos[j].nota2;
            alumnos[j-1].nota3 = alumnos[j].nota3;
            alumnos[j-1].nota4 = alumnos[j].nota4;
         }

         printf("Alumno eliminado");
         total--;
         break;
      }

   if(i==total)
      printf("Alumno no encontrado");
}

void ordenar()
{
   int i, j;
   Alumno temp;

   for(i=0; i<total-1; i++)
   {
      for(j=i+1; j<total; j++)
      if(strcmp(alumnos[i].nombre, alumnos[j].nombre)>0)
      {
         /* Copia en variable temporal datos actuales */
         strcpy(temp.carne, alumnos[i].carne);
         strcpy(temp.nombre, alumnos[i].nombre);
         strcpy(temp.direccion, alumnos[i].direccion);
         strcpy(temp.correoe, alumnos[i].correoe);
         temp.nota1 = alumnos[i].nota1;
         temp.nota2 = alumnos[i].nota2;
         temp.nota3 = alumnos[i].nota3;
         temp.nota4 = alumnos[i].nota4;
         /* Intercambia informacion */
         strcpy(alumnos[i].carne, alumnos[j].carne);
         strcpy(alumnos[i].nombre, alumnos[j].nombre);
         strcpy(alumnos[i].direccion, alumnos[j].direccion);
         strcpy(temp.correoe, alumnos[i].correoe);
         temp.nota1 = alumnos[i].nota1;
         temp.nota2 = alumnos[i].nota2;
         temp.nota3 = alumnos[i].nota3;
         temp.nota4 = alumnos[i].nota4;

         strcpy(alumnos[i].carne, alumnos[j].carne);
         strcpy(alumnos[j].nombre, temp.nombre);
         strcpy(alumnos[j].direccion, temp.direccion);
         strcpy(temp.correoe, alumnos[i].correoe);
         temp.nota1 = alumnos[i].nota1;
         temp.nota2 = alumnos[i].nota2;
         temp.nota3 = alumnos[i].nota3;
         temp.nota4 = alumnos[i].nota4;
      }
   }
   printf("Se han ordenado los registros");
}

void mostrar()
{

   for(int i=0; i<total; i++)
   {
      printf("Num: %d\n", i+1);
      printf("carne: %s\n", alumnos[i].carne);
      printf("nombre: %s\n", alumnos[i].nombre);
      printf("direccion: %s\n", alumnos[i].direccion);
      printf("correo electronico: %s\n", alumnos[i].correoe);
      printf("parcial No 1: %d\n", alumnos[i].nota1);
      printf("parcial No 2: %d\n", alumnos[i].nota2);
      printf("parcial No 3: %d\n", alumnos[i].nota3);
      printf("parcial No 4: %d\n", alumnos[i].nota4);
      printf("Promedio: %d", alumnos[i].nota1+alumnos[i].nota2+alumnos[i].nota3+alumnos[i].nota4);
         }
}

void ayuda()
{
 
   printf("\n Este trabajo es un programa que tiene como fin, mostrar el listado de alumnos\n de la Carrera de Ingenieria en Sistemas de Informacion y Ciencias de la\n Computacion. En este programa se tienen que especificar los datos principales\n del alumno para ingresarlo o buscarlo en el mismo. Los datos son: nombres\n carne, correo electronico y las notas adquiridas en el semestre correspondiente\n\n");
   printf("1. Ingresar = Aqui podras ingresar los datos del alumno.\n");
   printf("2. Buscar = Por medio del carne en esta opcion podras hallar al alumno que\n   buscas.\n");
   printf("3. Modificar = En esta opcion se podran hacer cambios en los datos del alumno\n   ya ingresado.\n");
   printf("4. Eliminar = Esta opcion servira para quitar del listado de alumnos x y de la\n   base de datos.\n");
   printf("5. Ordenar = Los ordena en forma que fueron ingresados.\n");
   printf("6. Mostrar lista = Muestra el total de alumnos ingresados en base de datos en\n   una lista.\n");
   printf("7. Ayuda = Proporciona sopporte para dudas.\n");
   printf("8. Salida = Opcion para salir del programa, si desea guardar los cambios\n   presiona (g).\n");
   }

char menu(void)
{
   char c;
 printf("(1)Ingresar, (2)Buscar, (3)Modificar, (4)Eliminar, (5)Ordenar, (6)Mostrar lista\n, (7)Ayuda, (8)Salir\n");

   printf("\nSeleccion: ");
   c=getche();
   printf("\n");
   return(c);
}
