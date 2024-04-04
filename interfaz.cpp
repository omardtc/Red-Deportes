#include <bits/stdc++.h>
#include "class.h"
using namespace std;
#define log(x) cout << x << endl;

void MenuDeUsuario(Usuario* u);
int id;
RedSocial r("Deportics");

int main()
{
    LimpiarPantalla();
    while(true)
    {
    int x;
    cout << "Bienvenido a " << r.nombre << ", tu red social deportiva" << endl;
    log("Elige una de las siguientes opciones:");
    log("1. Ver lista de usuarios");
    log("2. Ver lista de publicaciones");
    log("3. Entrar a perfil de usuario");
    log("4. Agregar nuevo usuario")
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
        cout << "Usuario no encontrado" << endl;
        return;
    }
    

    LimpiarPantalla();
    int x, f, y;
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
            break;
            case 2:
            LimpiarPantalla();
            u->mostrarPublicaciones();
            break;
            case 3:
            LimpiarPantalla();
            r.agregarPublicacion(u->crearPublicacion());
            break;
            case 4:
            LimpiarPantalla();
            u->mostrarAmigos();
            log("Ingrese el ID de su amigo");
            cin >> f;
            u->getAmigo(f);
            break;
            case 5:
            //Agregar amigo
            r.mostrarUsuarios();
            cout << "Introduce el ID del perfil al que quieras agregar de amigo" << endl;
            cin >> y;
            break;
            case 6:
            main();
            break;
            default:
            log("Ingresa un numero valido"); //Numeros invalidos
            break;
        }
}
