#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define CANTELE 50
#include "LISTAA.H"

//typedef int tipo;
//#include "LISTAA.H"

#include "Persona.h"

#define BS    8
#define ESC  27
#define F1   59
#define UP   72
#define DOWN 80
#define INS  82
#define DEL  83

using namespace std;
typedef int tipo;

template<class T> void ordInsert(T, Lista<T> &);
template<class T> void catList(Lista<T>, Lista<T>);
template<class T> void insList(Lista<T> &, int, Lista<T>);
template<class T> Lista<T> invList(Lista<T>);
template<class T> Lista<T> invList(Lista<T>, posicion);
template<class T> Lista<T> difList1(Lista<T>, Lista<T>);
template<class T> Lista<T> difList2(Lista<T>, Lista<T>);
template<class T> Lista<T> itcList(Lista<T>, Lista<T>);
template<class T> Lista<T> subList(Lista<T>, unsigned char, unsigned char);
template<class T> Lista<T> mixList(Lista<T>, Lista<T>);

void agenda(bool);
bool eliminar(Lista<Persona> &, string, unsigned);
void reordenar(Lista<Persona> &);
void insertar(Lista<Persona> &);
posicion buscar(Lista<Persona> &, const string &, posicion);
bool leer(string &);
bool leer(unsigned short &);
bool leerNum(string &);
bool esImprimible(unsigned char);
string minu(string);
void mueveCursor(int &, bool );
void gotoxy(int, int);
COORD cursorPos(void);

int main()
{
    agenda(1);
}

void agenda(bool datos)
{
    Lista<Persona> contactos;
    bool imp = true;
    unsigned char lectura = 255;
    string busqueda;
    int encontrados, cursor = 0;

    if (datos){      ///SOLO DE PRUEBA
        contactos.ordInsert( Persona("roldan", "mateo", "2302453627", "cochabamba 1614", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("sanchez", "ricardo", "2302234567", "delladodelasombra 1543", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("quito", "armando esteban", "2302987623", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("garcia", "carlos", "2302236754", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("garcia", "carmen", "2302126436", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("gonzalez", "pedro", "2302986414", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("prieto", "hernan", "23022467842", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("picapiedra", "pedro", "2302123456", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("gimenez", "susana", "2302654321", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("tangalanga", "gerardo", "2302765432", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("rivas", "matias", "2302567890", "dondelodejenquedarse 1678", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("perez", "daniel", "2302900876", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("uris", "diego", "230234567", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("papa", "fernanda", "2302123456", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("cisneros", "daniela", "2302765843", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("cisneros", "daniel", "2302871342", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("cravero", "cristian", "2302123562", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("cravero", "cristina", "2302235783", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("bori", "daniel", "2302235784", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("bori", "danilo", "23022357832", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("dan", "leo", "2302123567", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("sierra", "walter", "23021234456", "sincasa 1324", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("kirchner", "cristina", "2302123567", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("menem", "carlos", "2302123567", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("peron", "domingo", "2302123567", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("zapatero", "mauro", "2302123567", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("zapatta", "defensor de river", "2302123567", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("zabala", "tomas", "2302786346", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("balantta", "eder", "2302002934", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("carbonero", "carlos", "2302098012", "5(o) num 265", (FechaDM){2, 20}) );
        contactos.ordInsert( Persona("damico(comida)", "carlos", "230200000", "5(o) num 265", (FechaDM){2, 20}) );
    }

    do {
        if (lectura == '\0' || lectura == 224)
            switch ( getch() ){
                case UP:
                    if (cursor > 1)
                        mueveCursor(cursor, false);
                    break;
                case DOWN:
                    if (cursor < encontrados)
                        mueveCursor(cursor, true);
                    break;
                case DEL:
                    imp = eliminar(contactos, busqueda, cursor);
                    break;
                case F1:
                    reordenar(contactos);
                    imp = true;
                    break;
                case INS:
                    insertar(contactos);
                    busqueda = "";
                    imp = true;
                    break;
            }
        else if ( esImprimible(lectura) ){
            busqueda.push_back(lectura);
            imp = true;
        }
        else if (lectura == BS && busqueda != ""){
            busqueda.erase(busqueda.length() - 1, 1);
            imp = true;
        }

        if (imp){
            posicion p;

            system("cls");

            cout << "[INS] = Agregar contacto, [" << '\30' << "][" << '\31' << "] = Seleccionar, "
                 << "[DEL] = Eliminar\n[F1] = Nombre/Apellido, [ESC] = Salir\n"
                 << "--------------------------------------------------------------------------------\n\n";

            encontrados = 0;
            p = buscar( contactos, busqueda, contactos.primer() );
            while (p != contactos.fin()){
                encontrados++;
                cout << "  " << contactos.recuperar(p) << endl;
                p = buscar( contactos, busqueda, contactos.siguiente(p) );
            }

            if (!encontrados)
                cout << "No hay resultados...";

            gotoxy(0, 0);
            gotoxy(0, 3);
            cout << "Busqueda: " << busqueda;

            cursor = 0;
            imp = false;
        }

    } while ( (lectura = getch()) != ESC);

    system("cls");

    return;
}

bool eliminar(Lista<Persona> &contactos, string busqueda, unsigned ocurrencia)
{
    posicion p = buscar( contactos, busqueda, contactos.primer() );
    bool encontrado = false;

    for (int i = 1; i < ocurrencia && p != contactos.fin(); i++)
        p = buscar( contactos, busqueda, contactos.siguiente(p) );

    if ( p != contactos.fin() ){
        encontrado = true;
        contactos.eliminar(p);
    }

    return ocurrencia && encontrado;
}

void reordenar(Lista<Persona> &contactos)
{
    if (ordenPer() == APELLIDO)
        ordenPer(NOMBRE);
    else
        ordenPer(APELLIDO);

    contactos.ordenar();

    return;
}

void insertar(Lista<Persona> &contactos)
{
    string nom, ap, dir, num;
    FechaDM fecha;
    bool flag;

    system("cls");
    cout << "[ESC] = Cancelar\n"
         << "--------------------------------------------------------------------------------\n"
         << "Apelllido: ";
    if ( leer(ap) ){
        cout << "\nNombre: ";
        if ( leer(nom) ){
            cout << "\nNumero: ";
            if ( leerNum(num) ){
                cout << "\nDireccion: ";
                if ( leer(dir) ){
                    cout << "\nFecha de cumpleanios\nMes: ";
                    flag = leer(fecha.mes);
                    while (fecha.mes < 0 || 12 < fecha.mes){
                        cout << "\nMes no valido. Ingrese nuevamente: ";
                        flag = leer(fecha.mes);
                    }
                    if (flag){
                        if (fecha.mes){
                            cout << "\nDia: ";
                            flag = leer(fecha.dia);
                            while ( !validarFecha(fecha) ){
                                cout << "\nDia no valido. Ingrese nuevamente: ";
                                flag = leer(fecha.dia);
                            }
                        }
                        if (flag)
                            contactos.ordInsert( Persona(ap, nom, num, dir, fecha) );
                    }
                }
            }
        }
    }

    return;
}

posicion buscar(Lista<Persona> &c, const string &bus, posicion p)
{
    int len = bus.length();

    while ( p != c.fin() && minu( c.recuperar(p).ape() ).compare( 0, len, minu( bus ) )
                         && minu( c.recuperar(p).nom() ).compare( 0, len, minu( bus ) )
                         && minu( c.recuperar(p).num() ).compare( 0, len, minu( bus ) ) )
        p = c.siguiente(p);

    return p;
}

bool leer(string &cadena)
{
    char c;
    string resultado;

    while ( (c = getch()) != ESC && c != '\r' )
        if ( esImprimible(c) ){
            cout << c;
            resultado.push_back(c);
        }
        else if (c == BS && resultado != ""){
            cout << "\b \b";
            resultado.erase(resultado.length() - 1, 1);
        }

    if (c != ESC)
        cadena = resultado;

    return c != ESC;
}

bool leer(unsigned short &entero)
{
    bool flag;
    string numero;

    if ( flag = leerNum(numero) ){
        entero = 0;
        for (int i = 0; i < numero.length(); i++)
            entero = entero * 10 + numero[i] - '0';
    }

    return flag;
}

bool leerNum(string &numero)
{
    char c;
    string resultado;

    while ( (c = getch()) != ESC && c != '\r')
        if ('0' <= c && c <= '9'){
            cout << c;
            resultado.push_back(c);
        }
        else if (c == BS && resultado != ""){
            cout << "\b \b";
            resultado.erase(resultado.length() - 1, 1);
        }

    if (c != ESC)
        numero = resultado;

    return c != ESC;
}

bool esImprimible(unsigned char c)
{
    return c >= 32 && c != 127 && c != 255;
}

string minu(string cadena)
{
    for (int i = 0; i < cadena.length(); i++)
        if ('A' <= cadena[i] && cadena[i] <= 'Z')
            cadena[i] += 32;
    return cadena;
}

void mueveCursor(int &cursor, bool sentido)
{
    COORD coord = cursorPos();

    gotoxy(0, cursor + 4);
    cout << "  ";
    gotoxy(0, (sentido ? ++cursor : --cursor) + 4);
    cout << '\32';
    gotoxy(0, 0);
    gotoxy(coord.X, coord.Y);

    return;
}

void gotoxy(int columna, int linea)
{
    COORD coord = {columna, linea};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}

COORD cursorPos(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition;
}

