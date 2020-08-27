#include <iostream>
#include <string>
#ifndef Sobre_h
#define Sobre_h
#include "Envio.h"
using namespace std;

class Sobre: public Envio{
    private:
        double largo;
        double ancho;
        double cargoAdicional;
    public:
        Sobre();
        Sobre(Persona, Persona, double, double, double, double);
        void setLargo(double l){largo = l;};
        void setAncho(double a){ancho = a;};
        void setCargoAdicional(double ca){cargoAdicional = ca;};
        double getLargo(){return largo;};
        double getAncho(){return ancho;};
        double getCargoAdicional(){return cargoAdicional;};
        double calculaCostoEnvio();
};

Sobre::Sobre(){
    largo = 0;
    ancho = 0;
    cargoAdicional = 0;
}

Sobre::Sobre(Persona r, Persona d, double c, double l, double a, double ca) : Envio(r, d, c){
    largo = l;
    ancho = a;
    cargoAdicional = ca;
}

double Sobre::calculaCostoEnvio(){
    if(largo > 25 && ancho > 30){
        return costoEstandar + cargoAdicional;
    } else{
        return costoEstandar;
    }
}

#endif