#ifndef Maestro_h
#define Maestro_h

#include "Persona.h"
#include <iostream>
using namespace std;
class Maestro : public Persona {
public:
    Maestro();
    Maestro(string, int, string);
    string getDepto() { return depto; };
    void setDepto(string de) {     depto = de; };
    void muestraDatos();
private:
    string depto;
};

Maestro::Maestro() : Persona() {
    depto = "N/A";
}

Maestro::Maestro(string nom, int ed, string ca) : Persona(nom, ed) {
    depto = ca;
}


void Maestro::muestraDatos() {
    cout<<"Nombre: "<<nombre<<" Edad: "<<edad<<" Depto: "<<depto << endl;
}




#endif /* Maestro_h */