// This program contains different ways to make the sum of 1...n
// Abraham Cepeda Oseguera
// A00827666
// August 13th 2020
#include <iostream>
using namespace std;

// Iterative sum - O(n)
int sumaIter(int n){
    int suma = 0;
    for(int i = 1; i <= n; i++){
        suma += i;
    }
    return suma;
}

// Recursive sum - O(n)
int sumaRec(int n) {
    return (n > 1 ? (n+(sumaRec(n-1))) : 1);
}

// Direct sum - O(1)
int sumaDir(int n) {
    return (n*(n+1))/2;
}

int main() {
    int n;
    cout << "Enter an int: " << endl;
    cin >> n;
    cout << "The sum  of (Iter)" << n << " is equal to " << sumaIter(n) << "\n";
    cout << "The sum  of (Rec)" << n << " is equal to " << sumaRec(n) << "\n";
    cout << "The sum  of (Dir)" << n << " is equal to " << sumaDir(n) << "\n";
    return 0;
}
