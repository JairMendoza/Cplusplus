#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
    int  nr;
    char clave[8];
    char data[8];
    int sr;
}r, a, s;

struct encabezado{
    int nrs;
}ed, ec;     /// encabezado de dispersion y colisiones

FILE *fdd, *fdc;
int lr, le;

int fh( char *clave )
{
    int nr = 0;

    for(int i=0; i<strlen(clave); i++)
    {
        nr += int(clave[i]);
    }
    nr = nr%10 + 1;
    return nr;
}

/********************** Funcion Escribir ***********************/

void escribir()
{
    int  pos, x;
    char rpt;
    bool band;


    fdd = fopen("dispersion.dat", "w+");
    if(fdd==NULL){
        cout << " No se pudo crear dispersion.dat" << endl;
        return;
    }

    fdc = fopen("colisiones.dat", "w+");
    if(fdc==NULL){
        cout << " No se pudo crear colisiones.dat" << endl;
        return;
    }

    cout <<" LR = "<<lr<<" | LE = "<<le<<endl<<endl;

    /// Inicializando variables
    ed.nrs = 0;
    ec.nrs = 0;
    fwrite(&ed, le, 1, fdd);
    fwrite(&ec, le, 1, fdc);

    /// Bucle para insertar varios registros
    do
    {
        fflush(stdin);

        cout << " Clave: "; gets(r.clave);
        cout << " Data : "; gets(r.data);

        fflush(stdin);
        r.sr = -1;
        r.nr = fh(r.clave);

        cout << " Clave = "<< r.nr << endl;
        pos = (r.nr-1)*lr + le;
        fseek(fdd, pos, 0);
        fread(&s, lr, 1, fdd);

        if(strcmp(s.clave, "")==0)
        {
            fseek(fdd, pos, 0);
            fwrite(&r, lr, 1, fdd);
            ++ed.nrs;
        }
        else
        {
            band = false;
            x = s.sr;
            /// entramos al archivo de colisiones
            while(x != -1)
            {
                band = true;
                pos = (x-1)*lr + le;
                fseek(fdc, pos, 0);
                fread(&s, lr, 1, fdc);

                a = s;
                x = s.sr;
            }

            /// Listas de en el archivo de colision
            if(band==true)
            {
                r.nr = ++ec.nrs;
                a.sr = r.nr;
                fseek(fdc, pos, 0);
                fwrite(&a, lr, 1, fdc);
                fseek(fdc, 0, 2);
                fwrite(&r, lr, 1, fdc);
            }
            if(band==false)
            {
                r.nr = ++ec.nrs;
                s.sr = r.nr;
                fseek(fdd, pos, 0);
                fwrite(&s, lr, 1, fdd);
                fseek(fdc, 0, 2);
                fwrite(&r, lr, 1, fdc);
            }
        }
        cout << " Mas registros [s/n] : "; cin >> rpt; cout << endl;

    }while(rpt!='n');

    fseek(fdd, 0, 0);
    fwrite(&ed, le, 1, fdd);   /// actualizamos la cabezera del archivo DISPERSION
    fseek(fdc, 0, 0);
    fwrite(&ec, le, 1, fdc);   /// actualizamos la cabezera del archivo COLISIONES

    fclose(fdd);
    fclose(fdc);
}
/********************** Funcion Leer ***********************/
void leer()
{
    int  pos, x, nr;
    char v_clave[10];
    bool band;

    fdd = fopen("dispersion.dat", "r");
    if(fdd==NULL){
        cout << " No se pudo abrir disperson.dat" << endl; return;
    }

    fdc = fopen("colisiones.dat", "r");
    if(fdc==NULL){
        cout << " No se pudo abrir colisiones.dat " << endl; return;
    }

    fflush(stdin);
    cout << " Ingrese clave : "; gets(v_clave);
    nr = fh(v_clave);
    pos = (nr-1)*lr + le;

    fseek(fdd, pos, 0);
    fread(&r, lr, 1, fdd);

    if(strcmp(v_clave, r.clave)==0)
    {
        cout << " Su data es: " << r.data << endl;
        return;
    }
    else
    {
        band = false;
        x = r.sr;

        while( x != -1 )
        {
            pos = (x-1)*lr + le;
            fseek(fdc, pos, 0);
            fread(&r, lr, 1, fdc);
            if(strcmp(v_clave, r.clave)==0)
            {
                band = true;
                cout << " Su data es : " << r.data << endl;
                break;
            }
        }

        if(band == false)
        {
            cout << " No esta registrado..!" << endl;
        }
    }

    fclose(fdd);
    fclose(fdc);
}

void menu()
{
    cout << "\t\t METODO DE DISPERSION - HASHING \n\n";
    cout << "\t 1. Escribir              \n";
    cout << "\t 2. Leer                  \n";
    cout << "\t 3. Salir                 \n";
    cout << "\t >> Ingrese opcion:  ";
}

/********************** Funcion Principal ***********************/

int main()
{
    int op;
    lr = sizeof(struct registro);
    le = sizeof( struct encabezado);

    do
    {
        menu(); cin >> op;  cout << endl;

        switch(op)
        {
            case 1:
                escribir(); break;
            case 2:
                leer(); break;
            case 3:
                exit(0);
        }
        cout <<"\n\n ";
        system("pause"); system("cls");

    }while(op>0);


    return 0;
}
