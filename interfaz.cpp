#include <bits/stdc++.h>
#include "class.h"
using namespace std;
#define log(x) cout << x << endl;

void LimpiarPantalla();
void MenuDeUsuario(Usuario* u);
int id;
RedSocial r("Deportics");
Usuario u("");
Usuario a("");

int main()
{
    LimpiarPantalla();
    while(true)
    {
    int x, age;
    string name, nation, sport;
    log("Bienvenido a Deportics, tu red social deportiva. Elige una de las siguientes opciones");
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
            r.getUsuario(id);
            break;
            case 4:
            LimpiarPantalla();
            cout << "Ingresa nombre del nuevo usuario" << endl;
            cin >> name;
            LimpiarPantalla();
            cout << "Ingresa edad del nuevo usuario" << endl;
            cin >> age;
            LimpiarPantalla();
            cout << "Ingresa nacionalidad del nuevo usuario" << endl;
            cin >> nation;
            LimpiarPantalla();
            cout << "Ingresa deporte preferido del nuevo usuario" << endl;
            cin >> sport;
            LimpiarPantalla();
            u.nombre = name;
            u.nacionalidad = nation;
            u.edad = age;
            u.deporte = sport;
            cout << "Su ID es " << u.getId() << endl;
            r.agregarUsuario(&u);
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



void LimpiarPantalla()
{
    if (system("CLS") == -1)
    {
        cout << "Error al borrar pantalla" << endl;
    }
    //Borra pantalla
}

void MenuDeUsuario(Usuario* u)
{
    Usuario user = *u;
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
            user.mostrarAmigos();
            break;
            case 2:
            LimpiarPantalla();
            user.mostrarPublicaciones();
            break;
            case 3:
            LimpiarPantalla();
            user.crearPublicacion();
            break;
            case 4:
            LimpiarPantalla();
            user.mostrarAmigos();
            log("Ingrese el ID de su amigo");
            cin >> f;
            user.getAmigo(f);
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
