#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;
#include "Sobre.h"
#include "Paquete.h"

int main(){
    ifstream archivo;
    archivo.open("datosEnvios.txt");

    Envio *envios[10];
    char tipo;
    string nombreD, estadoD, ciudadD, cpD;
    string nombreR, estadoR, ciudadR, cpR;
    double costoEstandar, largo, ancho, cargoAdicional, peso, costoKg, costoTotal;
    int count = 0;

    while (archivo >> tipo >> nombreR >> estadoR >> ciudadR >> cpR >> nombreD >> estadoD >> ciudadD >> cpD){
        Persona remitente(nombreR, estadoR, ciudadR, cpR);
        Persona destinatario(nombreD, estadoD, ciudadD, cpD);
        if(tipo == 'p'){
            archivo >> costoEstandar >> peso >> costoKg;
            envios[count] = new Paquete(remitente, destinatario, costoEstandar, peso, costoKg);
        } else{
            archivo >> costoEstandar >> largo >> ancho >> cargoAdicional;
            envios[count] = new Sobre(remitente, destinatario, costoEstandar, largo, ancho, cargoAdicional);
        }
        costoTotal += envios[count]->calculaCostoEnvio();
        cout << "Remitente:\n";
        remitente.imprimir();
        cout << "Destinatario:\n";
        destinatario.imprimir();
        cout << "Costo: " << envios[count]->calculaCostoEnvio() << "\n";
        count++;
    }
    cout << "Total envios: " << costoTotal;
    return 0;
}