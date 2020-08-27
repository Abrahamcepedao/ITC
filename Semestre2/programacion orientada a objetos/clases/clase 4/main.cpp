#include <iostream>

using namespace std;


 

#include "Complejo.h"


 

int main() {
    Complejo c1(3,2), c2(5, 3), c3, c4;
    cout << "valores originales "<< endl;
    cout << "C1 = ";
    c1.muestra();
    cout << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;
    cout << "C4 = ";
    c4.muestra();
    cout << endl;
    cout << endl;
    if (c3 == c4){
        cout << "c3 y c4 son iguales"<< endl;
    }
    cout << endl;
    cout << "prueba del >" << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;
    bool greater = c3 > c4;
    if(greater){
        cout << "C3 is greater\n";
    } else{
        cout << "C3 is not greater\n";
    }

    cout << "prueba del *" << endl;
    c3 = c1 * c2;
    cout << "C1 = ";
    c1.muestra();
    cout << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;

    cout << "La suma de c1 + c2 " << endl;
    c3 = c1 + c2;
    cout << "C1 = ";
    c1.muestra();
    cout << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;
    cout << endl;

    cout << "prueba del ++" << endl;
    ++c2;
    c3 = ++c3;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;

    cout << "prueba del >" << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;
    greater = c2 > c3;
    if(greater){
        cout << "C2 is greater\n";
    } else{
        cout << "C3 is greater\n";
    }
    int n[100] = { 0 };
    cout << n[56];
    return 0;
}