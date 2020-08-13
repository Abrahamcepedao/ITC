#include <iostream>
using namespace std;

/* int fibonacciIter(int n){

} */

int fibonacciRec(int n){
    return ((n == 0 || n == 1) ? 1: (fibonacciRec(n-1)+fibonacciRec(n-2)));
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The fibonacci number of the " << n << "th positin is: " << fibonacciRec(n-1) << "\n";
    return 0;
}