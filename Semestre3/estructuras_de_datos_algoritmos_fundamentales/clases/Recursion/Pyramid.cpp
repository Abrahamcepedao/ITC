// This algorithm prints a piramid of * of n rows
// Abraham Cepeda Oseguera
// A00827666
// August 13th 2020
#include <iostream>
using namespace std;

// Recursive pyramid
void pyramid(int n, int m){
    // Print left spaces
    for(int i = 1; i < n; i++){
        cout << " ";
    }
    // Print * and spaces
    for(int i = 0; i < m; i++){
        if(i % 2 == 0){
            cout << "*";
        } else{
            cout << " ";
        }
    }
    cout << "\n";
    if(n > 1){
        pyramid(n-1, m+2);
    }
}

int main(){
    int n; 
    cout << "Enter a number: ";
    cin >> n;
    pyramid(n,1);
    return 0;
}
