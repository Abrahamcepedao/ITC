#include <iostream>
#include <string>
#ifndef Paquete_h
#define Paquete_h
using namespace std;

class Paquete: public Envio{
    private:
        double peso;
        double costoKg;
    public:
        Paquete();
        Paquete(Persona, Persona, double, double, double);
        void setPeso(double p){peso = p;};
        void setCostoKg(double ck){costoKg = ck;};
        double getPeso(){return peso;};
        double getCosotKg(){return costoKg;};
        double calculaCostoEnvio();
};
//constructors
Paquete::Paquete(){
    peso = 0;
    costoKg = 0;
}

Paquete::Paquete(Persona r, Persona d, double c, double p, double ck):Envio(r, d, c){
    peso = p;
    costoKg = ck;
}

//methods
double Paquete::calculaCostoEnvio(){
    return costoEstandar + (peso * costoKg);
}

#endif