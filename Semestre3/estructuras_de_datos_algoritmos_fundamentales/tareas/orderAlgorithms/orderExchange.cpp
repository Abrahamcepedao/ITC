// This algorithm sort a  vector with the exchange method
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void orderExchange(vector<int> &numbers){

}

int main(){
    int n, num;
    cout << "Enter the n value: ";
    cin >> n;
    vector<int> numbers;
    for(int i = 0; i < n; i++){
        cout << "Enter a number: ";
        cin >> num;
        numbers.push_back(num);
    }
    orderExchange(numbers);
    return 0;
}