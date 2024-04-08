#include <bits/stdc++.h>
#include <stdio.h>  
#include <windows.h> 
#include "class.h"
using namespace std;
#define log(x) cout << x << endl;

void MenuDeUsuario(Usuario* u);
int id;
RedSocial r("Deportics");
void PantallaDeCarga();
void gotoxy(int x, int y);


int main()
{
    PantallaDeCarga();
    LimpiarPantalla();
    while(true)
    {
    system("color F1");
    gotoxy(1,8);
    int x;
    log("Elige una de las siguientes opciones:");
    log("1. Ver lista de usuarios");
    log("2. Ver lista de publicaciones");
    log("3. Entrar a perfil de usuario");
    log("4. Agregar nuevo usuario");
    log("5. Salir");
    cin >> x;

    switch (x)
        {
            case 1:
            LimpiarPantalla();
            r.mostrarUsuarios();
            break;
            case 2:
            LimpiarPantalla();
            r.mostrarPublicaciones();
            break;
            case 3:
            LimpiarPantalla();
            log("Ingrese su ID de usuario");
            cin >> id;
            MenuDeUsuario(r.getUsuario(id));
            break;
            case 4:
            r.CrearUsuario();
            break;
            case 5:
            return 0; //Cierra programa
            break;
            default:
            log("Ingresa un numero valido"); //Numeros invalidos
            LimpiarPantalla();
            main();
            break;
        }
    }
}






void MenuDeUsuario(Usuario* u)
{
    if(u == nullptr)
    {
        string op;
        cout << "Usuario no encontrado" << endl;
        cout << endl;
        cout << "Escriba OK para volver al menu" << endl;
        cin >> op;
        LimpiarPantalla();
        return;
    }
    
    LimpiarPantalla();
    system("color F5");
    int x, f, y;
    gotoxy(1,8);
    log("Que quieres hacer?");
    log("1. Ver lista de amigos");
    log("2. Ver publicaciones");
    log("3. Crear publicacion");
    log("4. Entrar a perfil de amigo");
    log("5. Agregar nuevo amigo");
    log("6. Regresar al menu principal");
    cin >> x;

switch (x)
        {
            case 1:
            LimpiarPantalla();
            u->mostrarAmigos();
            MenuDeUsuario(u);
            break;
            case 2:
            LimpiarPantalla();
            u->mostrarPublicaciones();
            MenuDeUsuario(u);
            break;
            case 3:
            LimpiarPantalla();
            r.agregarPublicacion(u->crearPublicacion());
            MenuDeUsuario(u);
            break;
            case 4:
            LimpiarPantalla();
            u->mostrarAmigos();
            log("Ingrese el ID de su amigo");
            cin >> f;
            u->getAmigo(f);
            MenuDeUsuario(u);
            break;
            case 5:
            LimpiarPantalla();
            r.mostrarUsuarios();
            cout << "Introduce el ID del perfil al que quieras agregar de amigo" << endl;
            cin >> y;
            u->agregarAmigo(r.getUsuario(y));
            MenuDeUsuario(u);
            break;
            case 6:
            main();
            break;
            default:
            log("Ingresa un numero valido"); //Numeros invalidos
            LimpiarPantalla();
            MenuDeUsuario(u);
            break;
        }
}

void PantallaDeCarga()
{
    system("color F1");
    LimpiarPantalla();
    gotoxy(20, 8);
    cout << r.nombre << ", tu red social deportiva" << endl;
    gotoxy(20, 10);
    cout << "Cargando..." << endl;
    _sleep(5000);
}

void gotoxy(int x, int y)
{
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);
}


