
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>
#include<locale.h>
#include<time.h>

using namespace std;

int array[1000];

void Bubble ();
void Selection ();
void Insertion ();

void Shell ();
 
void gotoxy(int,int);

// Mergesort funciones
void merge_sort(int, int);
void merge_array(int, int, int, int);
int array_merge[15];
// Heapsort funciones
void heap_sort();
void heap_adjust(int, int);
int array_heap[15], t, a;
// Quicksort funciones
void quick_sort(int, int);
int array_quick[1000];
////////////////////////////////////////


int main ()
{
	int opcion;
	int salir = 1;
	int i;
	
	do
	{
		system("cls");
		gotoxy(45,8);  cout<<"________MENU ORDENAMIENTOS________"<<endl;
		gotoxy(45,9);  cout<<"[1] Bubble Sort			  "<<endl;
		gotoxy(45,10); cout<<"[2] Selection Sort          "<<endl;
		gotoxy(45,11); cout<<"[3] Insertion Sort  	      "<<endl;
		gotoxy(45,12); cout<<"[4] Shell Sort              "<<endl;
		gotoxy(45,13); cout<<"[5] Merge Sort              "<<endl;
		gotoxy(45,14); cout<<"[6] Heap Sort               "<<endl;
		gotoxy(45,15); cout<<"[7] Quick Sort              "<<endl;
		gotoxy(45,16); cout<<"[Esc] SALIR                 "<<endl;
		gotoxy(45,18); cout<<"INGRESE UNA OPCION: "; fflush(stdin);
		gotoxy(65,18); opcion=getch();
		
		switch(opcion)
		{
			case 49: //1
		    
		    system("cls");
		    Bubble ();
			
		    break;
		    
			case 50: //2
		
			system("cls");
			Selection ();	
			
		    break;

		    case 51: //3
		    
		    system("cls");
			Insertion ();
				
		    break;
		    
		    case 52: //4
		    
		    system("cls");
			Shell ();
				
		    break;
		    
		    case 53: //5
		    
		    system("cls");
		  	cout << "\nNumeros que se ordenaran: ";
				
			for(i = 0; i < 15; i++)
			{
				array_merge[i] = rand() % 100 + 1;
				cout << array_merge[i] << " ";
			}
			getch();
		
		
		    merge_sort(0, 15 - 1);
		
		    cout << "\n\nOrden Ascendente: ";
			for(i = 0; i < 15; i++)
			{
				cout << array_merge[i] << " ";
			}
			getch();
				
		    break;
		    
		    case 54: //6
		    
		    system("cls");
			cout << "\nNumeros que se ordenaran: ";
				
			for(i = 0; i < 15; i++)
			{
				array_heap[i] = rand() % 100 + 1;
				cout << array_heap[i] << " ";
			}
			getch();
			
		    heap_sort();
		
		    cout << "\n\nOrden Ascendente: ";
			for(i = 0; i < 15; i++)
			{
				cout << array_heap[i] <<" ";
			}	
			getch();
				
		    break;
		    
		    case 55: //7
		    
		    system("cls");
		  	cout << "\nNumeros que se ordenaran: ";	
			for(i = 0; i < 1000; i++)
			{
				array_quick[i] = rand() % 100 + 1;
				cout << array_quick[i] << " ";
			}
			getch();
		
		    quick_sort(0, 1000 - 1);
		
		    cout<<"\n\nOrden Ascendente: ";
			for(i = 0; i < 1000; i++)
			{
				cout << array_quick[i] << " ";
			}
			getch();
		    
			break;

			case 27: exit(-1);
		}
	}while(salir==1);
	return 0;
}

void Bubble ()
{
    clock_t time = clock(); 

	int i,x,aux;
	
	gotoxy(24,1); cout << "Numeros que se ordenaran: ";
		
	for(i = 0; i < 1000; i++)
	{
		array[i] = rand() % 1000 + 1;
		cout << array[i] << " ";
	}
	getch();	
	for(i = 0; i < 1000; i++)
	{
		for(x = 0; x < 1000; x++)
		{
			if(array[x] > array[x+1])
			{
				aux = array[x];
				array[x] = array[x + 1];
				array[x + 1] = aux;	
			}
			
		}
			cout << "\n\n\t\t\t";
			for(int i = 1; i < 1000; i++)
			{
				cout << "|" << array[i] << "|"  << " ";
			}
	}
	cout << "\n\n\n\t\t\t";
	cout << "Orden Ascendente: ";
	for(i = 0; i < 1000; i++)
	{
		cout << array[i] << " ";
	}
	
	time = (clock() - time)/1000;
	cout << "\n\nTiempo: " << time << endl;
	
	getch();
}

void Selection ()
{
	clock_t time = clock(); 
	
	int i,j,aux,min;
	
	gotoxy(24,1); cout << "\nNumeros que se ordenaran: ";
		
	for(i = 0; i < 1000; i++)
	{
		array[i] = rand() % 100 + 1;
		cout << array[i] << " ";
	}
	getch();
	
	for(i=0;i<1000;i++)
	{
		min = i;
		
		for(j=i+1;j<1000;j++)
		{	
			if(array[j] < array[min])
			{
				min = j;
			}
		}
		
		aux = array[i];
		array[i] = array[min];
		array[min] = aux;
		
		cout << "\n\n\t\t\t";
		for(int i = 1; i < 1000; i++)
		{
			cout << "|" << array[i] << "|"  << " ";
		}
	}
	cout << "\n\n\n\t\t\t";
	cout << "Orden Ascendente: ";
	for(i = 0; i < 1000; i++)
	{
		cout << array[i] << " ";
	}
	
	time = (clock() - time)/1000;
	cout << "\n\nTiempo: " << time << endl;
	
	getch();
}

void Insertion ()
{
	clock_t time = clock(); 
	
	int i,pos,aux;		
	
	cout << "\nNumeros que se ordenaran: ";
		
	for(i = 0; i < 1000; i++)
	{
		array[i] = rand() % 100 + 1;
		cout << array[i] << " ";
	}
	getch();
	
	for(i = 0; i < 1000; i++)
	{
		pos = i; 
		aux = array[i];
		
		while((pos>0) && (array[pos-1] > aux))
		{
			array[pos] = array[pos-1];
			pos--;
		}
		array[pos] = aux;
		
		cout << "\n\n\t\t\t";
		for(int i = 1; i < 1000; i++)
		{
			cout << "|" << array[i] << "|"  << " ";
		}
	}

	cout << "\n\n\n\t\t\t";
	cout << "Orden Ascendente: ";
	for(i = 0; i < 1000; i++)
	{
		cout << array[i] <<" ";
	}
	
	time = (clock() - time)/1000;
	cout << "\n\nTiempo: " << time << endl;
	
	getch();
}

void Shell ()
{
	clock_t time = clock(); 
	
	int cont,pasos,temp,i;
	
	cout << "\nNumeros que se ordenaran: ";
		
	for(i = 0; i < 1000; i++)
	{
		array[i] = rand() % 100 + 1;
		cout << array[i] << " ";
	}
	getch();
 
	for(cont = 15/2; cont!= 0; cont/=2)
		for(pasos = 1; pasos!= 0;)
		{
			pasos=0;
			for(i = cont; i < 1000; i++)
				if(array[i-cont] > array[i])
				{
					temp = array[i];
					array[i] = array[i-cont];
					array[i-cont] = temp;
					pasos++;
				}
				cout << "\n\n";
				for(int i = 1; i < 1000; i++)
				{
					cout << "|" << array[i] << "|"  << " ";
				}
		}
	
	cout << "\n\nOrden Ascendente: ";
	for(i = 0; i < 1000; i++)
	{
		cout << array [i] <<" ";
	}
	
	time = (clock() - time)/1000;
	cout << "\n\nTiempo: " << time << endl;
	getch();	
}

//Inicio Funcion Mergesort ///////////////////////////////////////////////////////////////////////////////////
void merge_sort(int i, int j) 
{
    int m;

    if (i < j) 
	{
        m = (i + j) / 2;
        merge_sort(i, m);
        merge_sort(m + 1, j);
        // Merging two arrays
        merge_array(i, m, m + 1, j);
        cout << "\n\n";
		for(int i = 1; i < 15; i++)
		{
			cout << "|" << array_merge[i] << "|"  << " ";
		}
    }
}

void merge_array(int a, int b, int c, int d) 
{
    int t[50];
    int i = a, j = c, k = 0;

    while (i <= b && j <= d) 
	{
        if (array_merge[i] < array_merge[j])
            t[k++] = array_merge[i++];
        else
            t[k++] = array_merge[j++];
    }

    while (i <= b)
        t[k++] = array_merge[i++];

    while (j <= d)
        t[k++] = array_merge[j++];

    for (i = a, j = 0; i <= d; i++, j++)
        array_merge[i] = t[j];
}
//Fin Funcion Mergesort ///////////////////////////////////////////////////////////////////////////////////
//Inicio Funcion Heapsort ///////////////////////////////////////////////////////////////////////////////////
void heap_sort() 
{
    for (int i = 15 / 2 - 1; i >= 0; i--)
        heap_adjust(15, i);

    for (int i = 15 - 1; i >= 0; i--) 
	{
        t = array_heap[0];
        array_heap[0] = array_heap[i];
        array_heap[i] = t;
        heap_adjust(i, 0);
        cout << "\n\n";
		for(int i = 1; i < 15; i++)
		{
			cout << "|" << array_heap[i] << "|"  << " ";
		}
    }
}

void heap_adjust(int n, int i) 
{
    int large = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && array_heap[left] > array_heap[large])
        large = left;

    if (right < n && array_heap[right] > array_heap[large])
        large = right;


    if (large != i) 
	{
        t = array_heap[i];
        array_heap[i] = array_heap[large];
        array_heap[large] = t;
        heap_adjust(n, large);
    }
}
//Fin Funcion Heapsort ///////////////////////////////////////////////////////////////////////////////////
//Inicio Funcion Quicksort ///////////////////////////////////////////////////////////////////////////////
void quick_sort(int f, int l) 
{
	clock_t time = clock(); 
	
    int i, j, t, p = 0;

    if (f < l) 
	{
        p = f;
        i = f;
        j = l;

        while (i < j) 
		{
            while (array_quick[i] <= array_quick[p] && i < l)
                i++;
            while (array_quick[j] > array_quick[p])
                j--;
            if (i < j) 
			{
                t = array_quick[i];
                array_quick[i] = array_quick[j];
                array_quick[j] = t;
            }
        }
        cout << "\n\n";
		for(int i = 1; i < 100; i++)
		{
			cout << "|" << array_quick[i] << "|"  << " ";
		}
		
		time = (clock() - time)/1000;
	cout << "\n\nTiempo: " << time << endl;

        t = array_quick[p];
        array_quick[p] = array_quick[j];
        array_quick[j] = t;
        quick_sort(f, j - 1);
        quick_sort(j + 1, l);
        
        
    }
}
//Fin Funcion Quicksort ///////////////////////////////////////////////////////////////////////////////

void gotoxy(int x,int y)
{  
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
}            
