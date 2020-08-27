//
//  Cuadratica.h
//  claseCuadraticaSinFriend
//
//  Created by Yolanda Martinez on 01/06/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//

#ifndef Cuadratica_h
#define Cuadratica_h

class Cuadratica {
    
public:
    Cuadratica();
    Cuadratica(int, int, int);
      // suma
      // resta
      // multiplicar por un número entero
      // sumar 1 entero a la ecuación, o sea, modifica sólo el coeficiente
      // comparar si son iguales
      // comparar si son diferentes
    Cuadratica operator+(Cuadratica);
    Cuadratica operator-(Cuadratica);
    Cuadratica operator*(int);
    Cuadratica operator++();
    bool operator==(Cuadratica);
    bool operator!=(Cuadratica);
    void muestra();
private:
    int coefA, coefB, coefC;
    
};

Cuadratica::Cuadratica() {
    coefA = 1;
    coefB = 1;
    coefC = 1;
}

Cuadratica::Cuadratica(int a, int b, int c) {
    coefA = a;
    coefB = b;
    coefC = c;
}


void Cuadratica::muestra() {
    if (coefA != 0) {
        cout << coefA;
        cout << "x^2 ";
    }
    if (coefB != 0) {
        if (coefB > 0)
            cout << " + ";
        cout << coefB;
        cout << "x ";
    }
    if (coefC != 0) {
        if (coefC > 0)
            cout << " + ";
        cout << coefC << endl;
    }
}
Cuadratica Cuadratica::operator+(Cuadratica e2) {
    int a = coefA + e2.coefA;
    int b = coefB + e2.coefB;
    int c = coefC + e2.coefC;
    Cuadratica nueva(a, b, c);
    return nueva;
}

Cuadratica Cuadratica::operator-(Cuadratica e2) {
    int a = coefA - e2.coefA;
    int b = coefB - e2.coefB;
    int c = coefC - e2.coefC;
    Cuadratica nueva(a, b, c);
    return nueva;
}
Cuadratica Cuadratica::operator*(int num) {
    int a = coefA * num;
    int b = coefB * num;
    int c = coefC * num;
    Cuadratica nueva(a, b, c);
    return nueva;
}
Cuadratica Cuadratica::operator++(){
    Cuadratica nueva(coefA,coefB,coefC++);
    return nueva;
}
bool Cuadratica::operator==(Cuadratica e2){
    if(coefA == e2.coefA){
        if(coefB == e2.coefB){
            if(coefC == e2.coefC){
                return true;
            }
        }
    }
    return false;
}
bool Cuadratica::operator!=(Cuadratica e2){
    if(coefA == e2.coefA){
        if(coefB == e2.coefB){
            if(coefC == e2.coefC){
                return false;
            }
        }
    }
    return true;
}

#endif /* Cuadratica_h */
