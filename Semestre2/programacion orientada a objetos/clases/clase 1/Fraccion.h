// Abraham Cepeda
// A00827666
#include <iostream>
using namespace std;
class Fraccion{
    private:
        int numerador;
        int denominador;
    
    public:
        Fraccion();
        Fraccion(int n, int d);
        
        int getNumerador();
        int getDenominador();
    
        void setNumerador(int n);
        void setDenominador(int d);
    
        Fraccion sumaFracciones(Fraccion f2);
        Fraccion multiFracciones(Fraccion f2);

        void simplifica();
        void muestra();
};

//constructores
Fraccion::Fraccion(){
    int numerador = 0;
    int denominador = 1;
}
Fraccion::Fraccion(int n, int d){
    if(n < 0 && d < 0){
        numerador = -n;
        denominador = -d;
    } else if(n > 0 && d < 0){
        numerador = -n;
        denominador = -d;
    } else{
        numerador = n;
        denominador = d;
    }
    simplifica();
}

//get methods
int Fraccion::getNumerador(){
    return numerador;
}
int Fraccion::getDenominador(){
    return denominador;
}
void Fraccion::muestra(){
    cout << numerador << "/" << denominador << "\n";
}

//set methods
void Fraccion::setNumerador(int n){
    numerador = n;
}
void Fraccion::setDenominador(int d){
    denominador = d;
}

// other methods
Fraccion Fraccion::sumaFracciones(Fraccion f2){
    int num = numerador * f2.getDenominador() + f2.getNumerador() * denominador;
    int den = denominador * f2.denominador;
    Fraccion newFraccion(num, den);
    newFraccion.simplifica();
    return newFraccion;
}

Fraccion Fraccion::multiFracciones(Fraccion f2){
    int num = numerador * f2.getNumerador();
    int den = denominador * f2.denominador;
    Fraccion newFraccion(num, den);
    newFraccion.simplifica();
    return newFraccion;
}

void Fraccion::simplifica(){
    for(int i = 2; i < 7; i++){
        while (numerador % i == 0 && denominador % i == 0){
            numerador = numerador / i;
            denominador = denominador / i;
        }
    }
}
