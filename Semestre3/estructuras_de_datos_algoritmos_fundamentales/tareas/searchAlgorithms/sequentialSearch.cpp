// This algorithm makes a sequential search to find a given number
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sequentialSearch(vector<int> numbers, int  num){
    for(int i = 0; i < numbers.size(); i++){
        if(num == numbers[i]){
            return i;
        }
    }
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
    cout << "The " << num << " is located at: " << sequentialSearch(numbers, num) << "\n";
    return 0;
}