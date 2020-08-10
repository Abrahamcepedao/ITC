#include<iostream>
#include<string>
#include<vector>

using namespace std;

int suma(int a, int b, int c){
    return a+b+c;
}

int main(){
    int a = 10;
    int b = 20;
    int c = 30;

    int s = suma(a,b,c);
    cout << "La suma  de a b c = " << s << endl;
}