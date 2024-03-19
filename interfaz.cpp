#include <bits/stdc++.h>
#include "class.h"
using namespace std;
#define log(x) cout << x << endl;

void LimpiarPantalla();
void MenuDeUsuario(int i);
int id;

int main()
{
    LimpiarPantalla();
    while(true)
    {
    int x;
    log("Bienvenido a Deportics, tu red social deportiva. Elige una de las siguientes opciones");
    log("1. Ver lista de usuarios");
    log("2. Ver lista de publicaciones");
    log("3. Entrar a perfil de usuario");
    log("4. Salir");
    cin >> x;

    switch (x)
        {
            case 1: 
            //Mostrar listado de todos los usuarios existentes
            break;
            case 2:
            //Mostrar listado de todas las publicaciones existentes
            break;
            case 3:
            //Introduce ID de usuario 
            log("Ingrese su ID de usuario");
            cin >> id;
            MenuDeUsuario(id);
            break;
            case 4:
            return 0; //Cierra programa
            break;
            default:
            log("Ingresa un numero valido"); //Numeros invalidos
            break;
        }
    }
}



void LimpiarPantalla()
{
    if (system("CLS") == -1)
    {
        cout << "Error al borrar pantalla" << endl;
    }
    //Borra pantalla
}

void MenuDeUsuario(int i)
{
    LimpiarPantalla();
    int x, f;
    log("Que quieres hacer?");
    log("1. Ver lista de amigos");
    log("2. Ver publicaciones");
    log("3. Crear publicacion");
    log("4. Entrar a perfil de amigo");
    log("5. Regresar al menu principal");
    cin >> x;

switch (x)
        {
            case 1: 
            //Mostrar listado de todos los amigos del usuario
            break;
            case 2:
            //Mostrar listado de todas las publicaciones del usuario
            break;
            case 3:
            //Crear nuevo post
            break;
            case 4:
            //Introduce ID de amigo 
            log("Ingrese el ID de su amigo");
            cin >> f;
            MenuDeUsuario(f);
            break;
            case 5:
            main();
            break;
            default:
            log("Ingresa un numero valido"); //Numeros invalidos
            break;
        }
}