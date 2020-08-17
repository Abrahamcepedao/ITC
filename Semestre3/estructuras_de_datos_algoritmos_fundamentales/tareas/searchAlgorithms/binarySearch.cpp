// This algorithm makes a binary search to find a given number
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int binarySearch(vector<int> numbers, int num){
    
    return -1;
}

int main(){
    int n, num;
    cout << "Enter the n value: ";
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++){
        numbers.push_back(i+1);
    }
    cout << "Enter the value you want to look for: ";
    cin >> num;
    cout << "The " << num << " is located at: " << binarySearch(numbers, num) << "\n";
    return 0;
}