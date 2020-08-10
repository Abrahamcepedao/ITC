#include<iostream>
#include<string>
#include<vector>

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

    int s = suma(a,b,c);
    double t = suma(d,e,f);
    cout << "La suma  de a b c = " << s << endl;
    cout << "La suma  de d e f = " << t << endl;
    return 0;
}