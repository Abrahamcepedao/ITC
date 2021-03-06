// This algorithm calculates de amount of bacteria  after n days
// Abraham Cepeda Oseguera
// A00827666
// August 13th 2020
#include <iostream>
using namespace std;

//Recursive bacteria - O(n)
double bacteria(int n, double m){
    return ((n > 0) ? bacteria(n-1, m*3.78/2.34): m);
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The number of bacteria until the " << n << "th  day is: " << int(bacteria(n, 1.0)) << "\n";
    return 0;
}