    #include <iostream>
    #include <string>
    #include <cstdlib>
    #include <conio.h> // getch
     
    #define USER "c++"
    #define PASS "java"
    #define ENTER 13 
    #define BACKSPACE 8
     
    using namespace std;
     
    int main()
    {
       string usuario, password;
       int contador = 0;
       bool ingresa = false;
     
       do {
          system("cls");
          cout << "\t\t\tLOGIN DE USUARIO" << endl;
          cout << "\t\t\t----------------" << endl;
          cout << "\n\tUsuario: ";
          getline(cin, usuario);
     
     
          cout << "\tPassword: ";
          // getline(cin, password);
          char caracter;
          caracter = getch();
     
          password = "";
     
          while (caracter != ENTER) {
     
             if (caracter != BACKSPACE) {
    	         password.push_back(caracter);
    	         cout << "*";
     
    			} else {
    				if (password.length() > 0) {
    					cout << "\b \b";
    					password = password.substr(0, password.length() - 1);
    				}
    			}
     
    			caracter = getch();
          }
     
     
          if (usuario == USER && password == PASS) {
             ingresa = true;
          } else {
             cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
             cin.get();
             contador++;
          }
       } while (ingresa == false && contador < 3);
     
       if (ingresa == false) {
          cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
       } else {
          cout << "\n\n\tBienvenido al sistema" << endl;
     
          // 
     
       }
     
     
     
       cin.get();
     
       return 0;
    }