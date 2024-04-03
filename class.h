#ifndef class_h
#define class_h
#include <bits/stdc++.h>
using namespace std;

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
        this->usuarios[i]->mostrar();
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

void RedSocial::CrearUsuario()
{
    int age;
    string name, nation, sport;
    Usuario u("");
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
    this->agregarUsuario(&u);
}

int Usuario::getId()
{
    int x = rand()%10;
    this->id = x;
    return this->id;
}

void Usuario::mostrar()
{
    cout << "ID: " << this->id << endl;
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
    Usuario u(this->nombre, this->edad, this->nacionalidad, this->deporte);
    nuevoAmigo->amigos.push_back(&u);
}

void Usuario::crearPublicacion()
{
    string f, c;
    cout << "Escriba el contenido de su publicacion" << endl;
    cin >> c;
    cout << "Escriba la fecha de su publicacion" << endl;
    cin >> f;
    Usuario u(this->nombre, this->edad, this->nacionalidad, this->deporte);
    Publicacion p(&u, f, c);
    this->publicaciones.push_back(&p);
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
