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
};
class RedSocial{
private:
    vector<Usuario*> usuarios;
    vector<Publicacion*> publicaciones;
public:
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaiones;

    void agregarUsuario();
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

void RedSocial::agregarUsuario(){
    this->usuarios.push_back(&);
}

void RedSocial::mostrarUsuarios(){
    for(int i = 0; i < this->usuarios.size(); i++){
        cout << this->usuarios[i]->nombre << endl;
    }
}

void RedSocial::mostrarPublicaciones(){
    for(int i = 0; i < this->publicaciones.size(); i++){
        cout << this->publicaciones[i]->mostrarPublicacion() << endl;
    }
}

Usuario* RedSocial::getUsuario(int id){

}

void Publicacion::mostrarPublicacion(){
    
}

#endif