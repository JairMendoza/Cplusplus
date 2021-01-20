#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<windows.h>

typedef int TipoClave;

#define N 716

using namespace std;

typedef struct 
{
	TipoClave clave;
} Registro;

void mezclaDirecta (FILE *f);
void distribuir (FILE *f, FILE *f1, FILE *f2, int lonSec, int numReg);
void mezclar (FILE *f1, FILE *f2, FILE *f, int *lonSec, int numReg);
void subSecuencia (FILE *f, FILE *t, int lonSec);
void escribir (FILE *F);

int cuentaReg (FILE *f);

FILE *f, *f1, f2, *t;

int main ()
{
	int j;
	FILE *f;
	Registro r;
	
	f = fopen("fileorg.bin","wt");
	
	for (j = 1; j <= N; j++)
	{
		r.clave = rand() % 999 + 1;
		fprintf(f,"%d",r.clave);
	}
	fclose(f);
	
	mezclaDirecta(f);
	
	f = fopen ("fileorg.bin","rt");
	escribir (f);
}

int cuentaReg (FILE *f)
{
	int k = 0;
	Registro r;
	
	f = fopen ("fileorg.bin","rt");
	while (!feof (f))
	{
		if (fscanf (f, "%d", &r.clave) != EOF)
		{
			k++;
		}
	}
	
	printf("\n Numero de registros: %d\n",k);
	return k;
}

/* La funcion mezclaDrecta () recibe el archivo que a sido abierto en modo lectura. */

void mezclaDirecta (FILE *f)
{
	int longSec;
	int numReg;
	FILE *f1, *f2;
	
	numReg = cuentaReg (f);
	longSec = 1;
	
	while (longSec < numReg)
	{
		distribuir (f, f1, f2, longSec, numReg);
		mezclar (f1 , f2, f, &longSec, numReg);
	}
}

void distribuir (FILE *f, FILE *f1, FILE *f2, int lonSec, int numReg)
{
	int numSec, resto, i;
	
	numSec = numReg / (2*lonSec);
	resto = numReg % (2*lonSec);
	
	f = fopen ("fileorg.bin","rt");
	f1 = fopen ("fileAux1.bin","wt");
	f2 = fopen ("fileAux2.bin","wt");
	
	for (i = 1; i <= numSec; i++)
	{
		subSecuencia (f, f1, lonSec);
		subSecuencia (f, f2, lonSec);
	}
	
	/* Se procesa el resto de registros del archivo */
	
	if (resto > lonSec)
		resto -= lonSec;
	else
	{
		lonSec = resto;
		resto = 0;
	}
	
	subSecuencia (f, f1, lonSec);
	subSecuencia (f, f2, resto);
	
	fclose (f1); fclose(f2); fclose (f);
}

void subSecuencia (FILE *f, FILE *t, int longSec)
{
	Registro r;
	int j;
	
	for (j = 1; j <= longSec; j++)
	{
		fscanf (f, "%d", &r.clave);
		fprintf (t, "%d", r.clave);
	}
}

void mezclar (FILE *f1, FILE *f2, FILE *f, int *lonSec, int numReg)
{
	int numSec, resto, s, i, j, k, n1, n2;
	Registro r1, r2;
	
	numSec = numReg / (2*(*lonSec));
	resto = numReg % (2*(*lonSec));
	
	f = fopen ("fileorg.bin", "wt");
	f1 = fopen ("fileAux1.bin", "rt");
	f2 = fopen ("fileAux2.bin", "rt");
	
	fscanf (f1, "%d", &r1.clave);
	fscanf (f2, "%d", &r2.clave);
	
	for (s = 1; s <= numSec+1; s++)
	{
		n1 = n2 = (*lonSec);
		if (s == numSec+1)
			if (resto > (*lonSec))
				n2 = resto - (*lonSec);
			else
			{
				n1 = resto;
				n2 = 0;
			}
	}
	
	i = j = 1;
	while (i <= n1 && j <= n2)
	{
		Registro d;
		if (r1.clave < r2.clave)
		{
			d = r1;
			fscanf (f1, "%d", &r1.clave);
			i++;
		}
		else
		{
			d = r2;
			fscanf (f2, "%d", &r2.clave);
			j++;
		}
		fprintf (f, "%d", d.clave);
	}
	
	/* Los registros no procesados se escriben directamente */
	
	for (k = i; k <= n1; k++)
	{
		fprintf (f, "%d", r1.clave);
		fscanf (f1, "%d", &r1.clave);
	}
	
	for (k = j; k <= n2; k++)
	{
		fprintf (f, "%d", r2.clave);
		fscanf (f2, "%d", &r2.clave);
	}

	(*lonSec) *= 2;
	fclose (f); fclose (f1); fclose (f2);
}

void escribir (FILE *f)
{
	int j;Registro r;
	
	j = 0; 
	while (!feof (f) && j < N )
	{
		j++;
		
		if (fscanf (f, "%d", &r.clave) != EOF)
		{
			printf ("%d", r.clave);
		}
	}
	
	printf ("---\n ");
}
