# include <iostream>
# include <windows.h>
# include <conio.h>

using namespace std;


char Menu (void);
void gotoxy(int,int);


int main ()
{ 
	char opcion;
	
	do 
	{
		opcion = Menu();
	
		switch (opcion)
		{
			
			case 59: //F1
				
			 	system("cls");
			 	cout<<"Presione cualquier tecla para continuar";
			 
				
				break;
				
			case 60://F2
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para agregar registros al archivo";
			 	Sleep(3000);
				
				break;
				
			case 61://F3
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para mostrar los registros";
			 	Sleep(3000);
				
				break;
				
			case 62://F4
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para buscar registros";
			 	Sleep(3000);
				
				break;
				
			case 63://F5
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para editar registros";
			 	Sleep(3000);
				
				break;
				
			case 64://F6
				
				system("cls");
			 	cout<<"Bienvenidos a la seccion para eliminar registros ";
			 	Sleep(3000);
				
				break;
				
			case 27://Esc.
				system("cls");
				gotoxy(32,21);cout<<"GRACIAS POR PASAR";
				Sleep(2500);
				
				break;
					
			default:
				
				if (opcion !=27)
				{
					Beep(500,1000);
				}
		}
		
	}while(opcion !=27);

	return 0;	
}

char Menu()
{
	char opc1 = '\0';
	
	system("cls");
	
	gotoxy(28,3); cout<<"Menu Agenda";
	gotoxy(28,5); cout<<"[F1] Crear o abrir archivo";
	gotoxy(28,6); cout<<"[F2] Agregar Registro";
	gotoxy(28,7); cout<<"[F3] Mostrar Registros";
	gotoxy(28,8); cout<<"[F4] Buscar Registro";
	gotoxy(28,9); cout<<"[F5] Modificar Registro";
	gotoxy(28,10);cout<<"[F6] Eliminar Registro";
	gotoxy(28,11);cout<<"[ESC] Salir";
	gotoxy(28,13);cout<<"Seleccione una opcion: ";
	
	opc1 = getch();
	
	if (opc1==0)
	{
		
		opc1 = getch();
	}
	
	return opc1;
}

void gotoxy(int x,int y)
{  
	  HANDLE hcon;  
	  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	  COORD dwPos;  
	  dwPos.X = x;  
	  dwPos.Y= y;  
	  SetConsoleCursorPosition(hcon,dwPos);  
}











 

