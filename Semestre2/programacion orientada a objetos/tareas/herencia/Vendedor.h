#include <iostream>
#include "Empleado.h"
using namespace std;

class Vendedor: public Empleado{
    private:
        double porcentajeComision;
        int ventas;
    public:
        Vendedor();
        Vendedor(int ide, double suel, double pv, int v);

        double getPorcentageComision() { return porcentajeComision; };
        int getVentas(){return ventas;};
        void setPorcentageComision(double pc) { porcentajeComision = pc; };
        void setVentas(int v){ ventas = v;};

        void muestra();
        double calculaPago();
};

Vendedor::Vendedor():Empleado(){
    porcentajeComision = 0;
    ventas = 0;
}
Vendedor::Vendedor(int ide, double suel, double pv, int v):Empleado(ide, suel){
    porcentajeComision = pv;
    ventas = v;
}

void Vendedor::muestra(){
    cout << "Id de empleado " << ident;
    cout << " sueldo $" << sueldo;
    cout << " %comision " << porcentajeComision;
    cout << " ventas " << ventas << endl;
}
double Vendedor::calculaPago(){
    return sueldo + porcentajeComision * ventas;
}