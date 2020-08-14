// This algorithm calculates de composite investment with a monthly return
// Abraham Cepeda Oseguera
// A00827666
// August 13th 2020
#include <iostream>
using namespace std;

// Recursive investment - O(n)
double investment(int n, double m) {
    return n > 0 ? investment(n-1, m*1.1875): m;
}

int main(){
    int n, c;
    cout << "Enter a number of month: ";
    cin >> n;
    cout << "Enter a the initial investment: ";
    cin >> c;
    cout << "The investment after the " << n << "th month is: " << investment(n, c) << "\n";
    return  0;
}