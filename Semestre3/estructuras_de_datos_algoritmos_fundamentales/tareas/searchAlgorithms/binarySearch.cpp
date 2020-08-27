// This algorithm makes a binary search to find a given number
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int binarySearch(vector<int> numbers, int num){
    int low = 0;
    int high = numbers.size()-1;
    while(low <= high){
        int medium = (high + low) / 2;
        if(numbers[medium] == num){
            return medium;
        } else if(numbers[medium] > num){
            high = medium - 1;
        } else{
            low = medium + 1;
        }
    }
    return -1;
}

int main(){
    int n, num;
    cout << "Enter the n value: ";
    cin >> n;
    vector<int> numbers;
    for (int i = 1; i <= n; i++){
        numbers.push_back(i);
    }
    cout << "Enter the value you want to look for: ";
    cin >> num;
    cout << "The " << num << " is located at: " << binarySearch(numbers, num) << "\n";
    return 0;
}