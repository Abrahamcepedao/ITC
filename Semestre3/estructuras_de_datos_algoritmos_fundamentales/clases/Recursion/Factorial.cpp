// This algorithm calculates de factorail of any given number
// Abraham Cepeda Oseguera
// A00827666
// August 13th 2020
#include<iostream>
#include<string>
using namespace std;

// Factorial function - O(n)
int factorial(int n){
    return n <= 1 ? 1 : n * factorial(n-1);
}

int main(){
    int n;
    cout << "Enter an int: " << endl;
    cin >> n;
    cout << "The factorial of " << n << " is equal to " << factorial(n) << "\n";
    return 0;
}