/*DESCRIPCOION: EL ALGORITMO CONSISTE EN UN PROGRAMA IMPLEMENTADO PARA UNA BIBLIOTECA, CUYA FUNCIONALIDAD ES PERMITIR TENER UNA BASE
DE DATOS DE LOS LIBROS QUE SE TIENEN, DENTRO DE LAS PRESTACIONES QUE TIENE EL PROGRAMA ES DAR DE ALTA LOS TITULOS, LES PERMITE
VISUALIZAR LOS TITULOS QUE SE TIENEN, PERMITE LA BUSQUEDA POR TITULO, Y EL ORDENAMIENTO POR NOMBRE ALFABETICO*/
// INTEGRANTES: GABRIEL ADÁN ESTRADA ORTIZ, JORGE RICARDO TORRES PADILLA, ARTURO CUEVAS PEREZ
// FECHA DE ELABORACION: 01/03/2018 8:00am


/************* DECLARACIÓN DE LIBRERIAS **************/
# include <iostream>
# include <windows.h>
# include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/**************** VARIABLES GLOBALES *****************/

string libros_almacenados[20];
int contador=0;

/************ DECLARACIÓN (Prototipos) DE FUNCIONES ***************/
char menu (void);
void gotoxy(int,int);
void alta();
void mostrar();
void busqueda();
void ordenamiento();

/* TE ENCUENTRAS EN EL MENU DEL PROGRAMA, DONDE APRECIARAS 4 OPCIONES (ALTA,MOSTRAR,ORDENAR,BUSQUEDA) QUE SERVIRAN PARA
LLEVAR UN MEJOR CONTROL DE LOS LIBROS (TITULOS) QUE SE TIENEN ALMACENADOS EN UNA BIBLIOTECA*/

int main ()    // INICIO DEL MAIN
{

    //DECLARACIÓN DE VARIABLES
    char opc;

    do   //Do principal- contiene la estructura general del programa
    {

        opc= menu();

        switch (opc)
        {
            char o;

        case 59: //F1 OPCION PARA DAR DE ALTA LOS TITULOS

            system("cls"); //LIMPIA PANTALLA
            alta(); // FUNCION PARA DAR DE ALTA LOS LIBROS
            o=getch();
            break;

        case 60://F2 OPCION PARA MOSTRAR LOS TITULOS DADOS DE ALTA

            system("cls"); //LIMPIA PANTALLA
            mostrar(); //FUNCION PARA MOSTRAR LOS LIBROS ALMACENADOS
            break;

        case 61://F3 OPCION PARA ORDENAR LOS TITULOS YA ALMACENADOS

            system("cls"); // LIMPIA PANTALLA
            ordenamiento(); // FUNCION PARA ORDENAR LOS TITULOS REGISTRADOS
            break;

        case 62://F4 OPCION PARA BUSQUEDA DE TITULOS

            system("cls"); // LIMPIA PANTALLA
            busqueda(); // FUNCION PARA BUSCAR LOS TITULOS ALMACENADOS
            break;

        default: // CUALQUIER OPCION NO VALIDA PARA EL MENU OCACIONARA QUE SE ESCUCHE UN BEEP

            if (opc !=27)
            {
                Beep(500,1000);
            }

        }//Fin del Switch


    }
    while(opc !=27); // MIENTRAS NO SE  PRESIONE LA OPCION DE SALIR SE SEGUIRA CICLANDO EL MENU

    return 0;

}//FIN DEL MAIN


/*****************     FUNCIONES     ****************/

//FUNCION MENU ++++++++++++++++++++++++++++++++++++++++++++++
char menu()
{

    char opc1 = '\0'; //Declaracion de variable local para manejo de la opcion

    system("cls");

    gotoxy(25,3); cout<<"SISTEMA BIBLIOTECARIO DE UTEG";
    gotoxy(28,5); cout<<"[F1] Registrar titulos";
    gotoxy(28,6); cout<<"[F2] Mostrar titulos almacenados";
    gotoxy(28,7); cout<<"[F3] Ordenar titulos alfabeticamente";
    gotoxy(28,8); cout<<"[F4] Buscar titulo";
    gotoxy(28,9); cout<<"[ESC]Salir";
    gotoxy(28,13); cout<<"Seleccione una opcion: ";

    //Captura de la opcion
    opc1 = getch();

    if (opc1==0)
    {

        opc1 = getch();
    }

    return opc1;//Retornar la opcion ingresada


}

//FUNCION GOTOXY ++++++++++++++++++++++++++++++++++++++++++++
void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

//FUNCION ALTA
void alta()
{
    if(contador<=19) // MIENRAS NO SE LLEGUE AL MAXIMO DE REGISTROS PERMITIRA SEGUIR REGISTRANDO
    {
    char titulo[50];
    system("cls"); // LIMPIA PANTALLA
    fflush(stdin); // LIMPIA EL BUFFER
    cout << "Ingresa nombre del titulo a registrar: "; // SOLICITA AL USUARIO NOMBRE DEL LIBRO A REGISTRAR
    gets(titulo);

    libros_almacenados[contador]=titulo;

    contador++; // CADA VEZ QUE REGISTRAS UNO NUEVO SE VA INCREMENTANDO EL CONTADOR

    }
    else // SI EL CONTADOR YA ES MAYOR A 19 YA NO PERMITIRA REGISTRAR MAS TITULOS
    {
        system("cls");
        cout << "No es posible almacenar mas libros";
        getch();
    }

}

//FUNCON MOSTRAR
void mostrar()
{
    if(contador>0) // SI AUN NO REGISTRAS LIBROS ESTA OPCION NO FUNCIONARA
    {
    system("cls");
    cout << "LIBROS ALMACENADOS\n\n";
    for( int i = 0; i < contador; i ++) // SE CREA UN FOR PARA RECORRER EL ARREGLO QUE ALMACENA LOS TITULOS.
    {
        cout << libros_almacenados[i] << endl;
    }

    getch();
    }
    else // SI NO AUN NO REGISTRAN NINGUN TITULO ARROJARA UN MENSAJE DE ERROR
    {
        system("cls");
        cout << "No hay registrado ningun titulo aun...";
        getch();
    }
}

//FUNCION ORDENAMIENTO BUBBLE
// SE UTILIZO EL ORDENAMIENTO BUBBLE POR QUE PARA LA CANTIDAD QUE DE DATOS QUE MANEJAMOS CREEMOS QUE ES EL MAS ADECUADO PARA NUESTRO CODIGO
void ordenamiento()
{
    string temporal;
    if(contador>0) // SI NO SE HA REGISTRADO NADA AUN NO LE PERMITIRA ORDENAR
    {
    system("cls");  // LIMPIA PANTALLA
    for(int i = 1; i < contador; i++)
    {
        for( int j = 0; j < contador-1; j++)
        {
            if(libros_almacenados[j] > libros_almacenados[j+1]) // SE VA COMPARANDO EL REGISTRO DESDE LA POSICION 0 HASTA EL ULTIMO EN EL ARREGLO
            {
                temporal=libros_almacenados[j]; // ASIGNA EL REGISTRO A UNA VARIABLE TEMPORAL
                libros_almacenados[j]=libros_almacenados[j+1]; // EL REGISTRO QUE TIENE MAYOR VALOR, ES REMPLAZADO EN LA POSICION DEL CUAL FUE COMPARADO
                libros_almacenados[j+1]=temporal; // Y EL QUE INICIALMENTE SE ESTABA COMPARANDO SE ASIGNA AHORA EN LA POSICION DEL REGISTRO QUE ESTABA ENSEGUIDA DE EL
            }
        }
    }

    cout << "Fueron ordenados con exito...";
    getch();
    }
    else
    {
        system("cls");
        cout << "No hay registrado ningun titulo aun...";
        getch();
    }
}

//FUNCION BUSQUEDAA SECUENCIAL
//POR LA MISMA RAZON UTILIZAMOS LA BUSQUEDA SECUENCIAL, A RAZON DE QUE COMO SON POCOS LOS DATOS QUE MANEJAMOS EN EL PROGRAMA NO ES NECESARIO UNA
//BUSQUEDA BINARIA, TAL VEZ SI NUESTRO PROGRAMA UTILIZARA UNA CANTIDAD DE DATOS CONSIDERABLES PROBABLEMENTE SI FUERA NECESARIO UTILIZAR LA BUSQUEDA BINARIA

void busqueda()
{
    char titulo_buscado[50];
    int encontrado=0;
    if(contador>0) // SI AUN NO SE REGISTRA NADA, NO PERMITIRA BUSCAR
    {
    system("cls");
    cout << "LIBROS ALMACENADOS\n\n";
    cout << "Nombre de libro a bucar: "; // SOLICITA EL DATO DEL LIBRO A BUSCAR
    gets(titulo_buscado);

    for(int i = 0; i < contador; i ++) // RECORRE TODA LA LISTA
    {

        if(titulo_buscado==libros_almacenados[i]) // VA COMPARANDO UNO POR UNO HASTA ENCONTRAR EL QUE SE BUSCA
        {
            cout << "El libro que buscas si se encuentra en almacen...";
            getch();
            encontrado=1; // SE UTILIZA UNA BANDERA LA CUAL CAMBIARA SI EL REGISTRO FUE ENCONTRADO
        }
    }

    if(encontrado==0) // SI LA BANDERA NUNCA FUE CAMBIADA, QUIERE DECIR QUE EL TITULO NO FUE ENCONTRADO
    {
        cout << "El libro que buscas no se encuentra en almacen...";
        getch();
    }
    }
    else
    {
        system("cls");
        cout << "No hay registrado ningun titulo aun...";
        getch();
    }

}
