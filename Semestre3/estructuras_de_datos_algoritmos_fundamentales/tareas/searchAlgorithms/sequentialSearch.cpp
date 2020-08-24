// This algorithm makes a sequential search to find a given number
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
T sequentialSearch(vector<T> vect, T elem){
    for(int i = 0; i < vect.size(); i++){
        if(elem == vect[i]){
            return i;
        }
    }
    throw runtime_error("Element was not found...\n");
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
    try{
        int index = sequentialSearch(numbers, num);
        cout << "The " << num << " is located at: " << sequentialSearch(numbers, num) << "\n";
    } catch(runtime_error& e){
        cout << e.what();
    }
    
    return 0;
}