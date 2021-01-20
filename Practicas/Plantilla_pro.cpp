
// Arturo Cuevas Pérez
// 3er Semestre Ing. Computación UteG
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#include<cwchar>

using namespace std;

char Menu (void);
void Font ();
void Gotoxy(int,int);
void Setcolor(WORD color);
void ResetColor(WORD Attributes);

int main ()
{
	char op;
	
	do
	{
		op = Menu();
		
		switch(op)
		{	
			case 59: //F1
			
		    system("cls"); break;
		    
			case 60: //F2
			system("cls"); break;

		    case 61: //F3
		    
		    system("cls"); break;
		    
		    case 62: //F4
		
		    system("cls"); break;
		    
		    case 63: //F5
		    
		    system("cls"); break;
		    
		    case 64: //F6
		    
		    system("cls"); break;

			case 27: //ESC
			
			system("cls");
			Gotoxy(50,11); cout<<"¡Hasta la proxima!";
		}
	}while(op!=27);
	return 0;
}

char Menu ()
{
	char opcion;
	Font ();
	WORD Attributes = 10;
	setlocale(LC_CTYPE, "Spanish");
	system("cls");
	Setcolor(14);
	Gotoxy(46,9);  cout << "__________MENU CDs__________  ";
	ResetColor(Attributes); 
	Gotoxy(45,10); cout << "  [F1] Abrir o Crear Fichero  ";
	Gotoxy(45,11); cout << "  [F2] Registrar CDs          ";
	Gotoxy(45,12); cout << "  [F3] Mostrar Registros      ";
	Gotoxy(45,13); cout << "  [F4] Consultar Registros    ";
	Gotoxy(45,14); cout << "  [F5] Editar Registros       ";
	Gotoxy(45,15); cout << "  [F6] Eliminar Registros     ";
	Gotoxy(45,16); cout << "  [F7] Mostrar Reg Eliminados ";
	Gotoxy(45,17); cout << "  [F8] Recuperar Registros    ";
	Gotoxy(45,18); cout << "  [Esc] SALIR                 ";
	Setcolor(14); 
	Gotoxy(45,20); cout << "    INGRESE UNA OPCIÓN: "; fflush(stdin);
	ResetColor(Attributes); 
	opcion = getch();
}

void Gotoxy(int x,int y)
{  
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
}
//Setcolor(BACKGROUND_INTENSITY | BACKGROUND_GREEN);
void Font ()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 9;    // Width of each character in the font
	cfi.dwFontSize.Y = 20;   // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L" ");  // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Setcolor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void ResetColor(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
} 
