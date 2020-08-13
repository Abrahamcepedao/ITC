// This program manipulates an array that can have several datatypes since the class uses Templates
// Abraham Cepeda Oseguera
// A00827666
// August 10th 2020
#include<iostream>
#include<string>
using namespace std;

int factorial(int n){
    return (n<= 1 ? 1 : (n*factorial(n-1)));
}

int main(){
    int n;
    cout << "Enter an int: " << endl;
    cin >> n;
    cout << "The factorial of " << n << " is equal to " << factorial(n) << "\n";
    return 0;
}