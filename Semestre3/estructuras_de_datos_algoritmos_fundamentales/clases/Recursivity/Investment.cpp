#include <iostream>
using namespace std;

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