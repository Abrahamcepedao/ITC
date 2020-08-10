#include<iostream>
#include<string>
#include<vector>
#include "Fraccion.h"

using namespace std;

template<class T>
T suma(T a, T b, T c){
    return a+b+c;
}


int main() {
    int a = 10;
    int b = 20;
    int c = 30;
    double d = 10.5;
    double e = 20.5;
    double f = 30.5;
    Fraccion f1 = Fraccion(1,4);
    Fraccion f2 = Fraccion(1,4);
    Fraccion f3 = Fraccion(1,4);

    int s = suma(a,b,c);
    double t = suma(d,e,f);
    Fraccion f4 = suma(f1,f2,f3);
    cout << "La suma  de a b c = " << s << endl;
    cout << "La suma  de d e f = " << t << endl;
    cout << "La suma  de f1 f2 f2 = " << f4 << endl;
    return 0;
}