#include "CtaBanc.h"
class CtaComision: public CtaBanc{
    private:
        double comision;
    public:
        CtaComision();
        CtaComision(int n, double s, double c);
        double getComision(){return comision;};
        void setComision(double c){comision = c;};
        bool retira(double cant);
        void mostrar();
        
};

CtaComision::CtaComision():CtaBanc(){
    comision = 10;
}

CtaComision::CtaComision(int n, double s, double c):CtaBanc(n, s){
    comision = c;
}

bool CtaComision::retira(double cant){
    if (saldo >= (cant + comision)) {
        saldo -= (cant + comision);
        return true;
    }
    else
        return false;
}

void CtaComision::mostrar(){
    CtaBanc::mostrar();
    cout << "Comision: " << comision << endl;
}