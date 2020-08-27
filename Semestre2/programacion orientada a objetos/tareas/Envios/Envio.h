#include <iostream>
#include <string>
#ifndef Envio_h
#define Envio_h
#include "Persona.h"
using namespace std;

class Envio: public Persona{
    protected:
        Persona remitente;
        Persona destinatario;
        double costoEstandar; 
    public:
        Envio();
        Envio(Persona, Persona, double);
        void setRemitente(Persona r) { remitente = r; };
        void setDestinatario(Persona d) { destinatario = d; };
        void setCostoEstandar(double c) { costoEstandar = c; };
        Persona getRemitente() { return remitente; };
        Persona getDestinatario() { return destinatario; };
        double getCostoEstandar() { return costoEstandar; };
        virtual double calculaCostoEnvio() = 0;
};

Envio::Envio(){
    remitente = Persona();
    destinatario = Persona();
    costoEstandar = 0;
}

Envio::Envio(Persona r, Persona d, double c){
    remitente = r;
    destinatario = d;
    costoEstandar = c;
}
#endif