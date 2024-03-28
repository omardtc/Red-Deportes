#ifndef class_h
#define class_h
#include <bits/stdc++.h>
using namespace std;

class Publicacion{
private:
    int id;
public:
    string fecha;
    string contenido;
    Usuario* usuario;

    void mostrarPublicacion();

    Publicacion(Usuario* usuario, string fecha, string contenido){
        this->usuario = usuario;
        this->fecha = fecha;
        this->contenido = contenido;
    }
};
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
    void crearPublicacion();
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
    }
};
class RedSocial{
private:
    vector<Usuario*> usuarios;
    vector<Publicacion*> publicaciones;
public:
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaiones;

    void agregarUsuario(Usuario* x);
    void mostrarUsuarios();
    void mostrarPublicaciones();
    Usuario* getUsuario(int id);

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
    cout << "Fecha: " << this->fecha << endl;
    cout << "Contenido: " << this->contenido << endl;
    cout << "Usuario: " << this->usuario->nombre << endl;

}

void RedSocial::agregarUsuario(Usuario* x){
    this->usuarios.push_back(x);
}

void RedSocial::mostrarUsuarios(){
    for(int i = 0; i < this->usuarios.size(); i++){
        cout << this->usuarios[i]->nombre << endl;
    }
}

void RedSocial::mostrarPublicaciones(){
    for(int i = 0; i < this->publicaciones.size(); i++){
        this->publicaciones[i]->mostrarPublicacion();
    }
}

Usuario* RedSocial::getUsuario(int id){
    for (int i = 0; i < usuarios.size(); i++)
    {
        if (id == this->usuarios[i]->getId())
        {
            return this->usuarios[i];
        }
    }
    return nullptr;
    cout << "No existe ese usuario" << endl;
}


int Usuario::getId()
{
    return this->id;
}

void Usuario::mostrar()
{
    cout << "ID: " << this->getId() << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Nacionalidad: " << this->nacionalidad << endl;
    cout << "Deporte practicado: " << this->deporte << endl;
}

void Usuario::mostrarAmigos()
{
    for (int i = 0; i < amigos.size(); i++){
        this->amigos[i]->mostrar();
    }
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
    //Falta agregar que el usuario tambien se agregue a la lista de amigos del nuevo amigo
}

void Usuario::crearPublicacion()
{
    string f, c;
    cout << "Escriba el contenido de su publicacion" << endl;    
    cin >> c;
    cout << "Escriba la fecha de su publicacion" << endl;    
    cin >> f;
    Publicacion p(Usuario* usuario, string f, string c);
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
#endif