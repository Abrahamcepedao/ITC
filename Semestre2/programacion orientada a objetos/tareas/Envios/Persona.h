#include <string>
#include <iostream>
#ifndef Persona_h
#define Persona_h
using namespace std;

class Persona{
    protected:
        string nombre;
        string estado;
        string ciudad;
        string cp;
    public:
        Persona();
        Persona(string, string, string, string);
        void imprimir();
};
// constructors
Persona::Persona(){
    nombre = "";
    estado = "";
    ciudad = "";
    cp = "";
}
Persona::Persona(string n, string e, string c, string co){
    nombre = n;
    estado = e;
    ciudad = c;
    cp = co;
}

// methods
void Persona::imprimir(){
    cout << "Nombre: " << nombre << "\n";
    cout << "Dirección: " << estado << " " << ciudad << " " << cp << "\n";
}
#endif