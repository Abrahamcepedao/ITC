#include <iostream>
using namespace std;

int power(int x, int y){
    return y > 1 ? x * power(x, y-1) : x;
}

int main(){
    int x, y;
    cout << "Enter value of x: ";
    cin >> x;
    cout << "Enter value of y: ";
    cin >> y;
    cout << "The value of " << x << "^" << y << " is: " << power(x,y) << "\n";
    return 0;
}