#ifndef class_h
#define class_h
#include <bits/stdc++.h>
using namespace std;

class Usuario;
class RedSocial;
class Publicacion;

void LimpiarPantalla();

class Usuario{
private:
    int id;
public:
    string nombre;
    int edad;
    string nacionalidad;
    string deporte;
    vector<Usuario*> amigos;
    vector<Publicacion*> publicaciones;

    int getId();
    void mostrar();
    void mostrarAmigos();
    void mostrarPublicaciones();
    void agregarAmigo(Usuario *nuevoAmigo);
    Publicacion* crearPublicacion();
    Usuario* getAmigo(int id);

    Usuario(string nombre){
        this->nombre = nombre;
    }
    Usuario(string nombre, int edad){
        this->nombre = nombre;
        this->edad = edad;
    }
    Usuario(string nombre, int edad, string nacionalidad){
        this->nombre = nombre;
        this->edad = edad;
        this->nacionalidad = nacionalidad;
    }
    Usuario(string nombre, int edad, string nacionalidad, string deporte){
        this->nombre = nombre;
        this->edad = edad;
        this->nacionalidad = nacionalidad;
        this->deporte = deporte;
        this->id = rand()%10;
    }
};

class Publicacion{
private:
    int id;
public:
    int dia, mes, anio;
    string contenido;
    Usuario* usuario;

    void mostrarPublicacion();

    Publicacion(string contenido)
    {
        this->contenido = contenido;
    }
    
    Publicacion(Usuario* usuario, string contenido, int dia, int mes, int anio){
        this->usuario = usuario;
        this->contenido = contenido;
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }
};

class RedSocial{
private:
    vector<Usuario*> usuarios;
    vector<Publicacion*> publicaciones;
public:
    string nombre;
    int numeroDeUsuarios = usuarios.size();
    int numeroDePublicaiones = publicaciones.size();

    void agregarUsuario(Usuario* x);
    void mostrarUsuarios();
    void mostrarPublicaciones();
    Usuario* getUsuario(int id);
    void CrearUsuario();
    void agregarPublicacion(Publicacion* x);

    RedSocial(string nombre){
        this->nombre = nombre;
    }
    RedSocial(string nombre, vector<Usuario*> usuarios){
        this->nombre = nombre;
        this->usuarios = usuarios;
    }
    RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones){
        this->nombre = nombre;
        this->usuarios = usuarios;
        this->publicaciones = publicaciones;
    }
};

void Publicacion::mostrarPublicacion(){
    cout << "Fecha: " << this->dia << "/" << this->mes << "/" << this-anio << endl;
    cout << "Contenido: " << this->contenido << endl;
    cout << "Usuario: " << this->usuario->nombre << endl;

}

void RedSocial::agregarPublicacion(Publicacion* x)
{
    this->publicaciones.push_back(x);
}

void RedSocial::agregarUsuario(Usuario* x){
    this->usuarios.push_back(x);
}

void RedSocial::mostrarUsuarios(){
    string op;
    for(int i = 0; i < this->usuarios.size(); i++){
        this->usuarios[i]->mostrar();
    }
    cout << "Escriba OK para volver al menu" << endl;
    cin >> op;
    LimpiarPantalla();
}

void RedSocial::mostrarPublicaciones(){
    string op;
    for(int i = 0; i < this->publicaciones.size(); i++){
        this->publicaciones[i]->mostrarPublicacion();
    }
    cout << "Escriba OK para volver al menu" << endl;
    cin >> op;
    LimpiarPantalla();
}

Usuario* RedSocial::getUsuario(int id){
    for (int i = 0; i < this->usuarios.size(); i++)
    {
        if (id == this->usuarios[i]->getId())
        {
            return this->usuarios[i];
        }
    }
    return nullptr;
    cout << "No existe ese usuario" << endl;
}

void RedSocial::CrearUsuario()
{
    int age;
    string name, nation, sport;
    Usuario* u = new Usuario("");
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
    u->nombre = name;
    u->nacionalidad = nation;
    u->edad = age;
    u->deporte = sport;
    cout << "Su ID es " << u->getId() << endl;
    this->agregarUsuario(u);
}

int Usuario::getId()
{
    return this->id;
}

void Usuario::mostrar()
{
    cout << "ID: " << this->id << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Nacionalidad: " << this->nacionalidad << endl;
    cout << "Deporte practicado: " << this->deporte << endl;
    cout << endl;
}

void Usuario::mostrarAmigos()
{
    string op;
    for (int i = 0; i < amigos.size(); i++){
        this->amigos[i]->mostrar();
    }
    cout << "Escriba OK para volver al menu" << endl;
    cin >> op;
    LimpiarPantalla();
}

void Usuario::mostrarPublicaciones()
{
    for (int i = 0; i < publicaciones.size(); i++){
        this->publicaciones[i]->mostrarPublicacion();
    }
}

void Usuario::agregarAmigo(Usuario *nuevoAmigo)
{
    this->amigos.push_back(nuevoAmigo);
    Usuario u(this->nombre, this->edad, this->nacionalidad, this->deporte);
    nuevoAmigo->amigos.push_back(&u);
}

Publicacion* Usuario::crearPublicacion()
{
    string cont;
    int day, month, year;
    Usuario u(this->nombre, this->edad, this->nacionalidad, this->deporte);
    Publicacion* p = new Publicacion("");
    cout << "Escriba la actividad que hace en su publicacion" << endl;
    cin >> cont;
    cout << "Escriba la fecha de su publicacion en formato DD/MM/YYYY" << endl;
    cout << "NOTA: No use diagonales, presione ENTER despues de llenar cada dato" << endl;
    cin >> day;
    cin >> month;
    cin >> year;
    p->usuario = &u;
    p->contenido = cont;
    p->dia = day;
    p->mes = month;
    p->anio = year;
    this->publicaciones.push_back(p);
    return this->publicaciones.back();
}

Usuario* Usuario::getAmigo(int id)
{
    for (int i = 0; i < amigos.size(); i++)
    {
        if (id == this->amigos[i]->getId())
        {
            return this->amigos[i];
        }
    }
    return nullptr;
    cout << "No existe ese amigo" << endl;
}

void LimpiarPantalla()
{
    if (system("CLS") == -1)
    {
        cout << "Error al borrar pantalla" << endl;
    }
    //Borra pantalla
}



#endif
