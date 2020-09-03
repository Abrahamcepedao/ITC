// This algorithm sort a  vector with the Quick sort method
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

template<class T>
void sort(vector<T> &vect, int l, int m, int r){
    
} 

template<class T>
void orderQuick(vector<T> &vect, int l, int r){
    if(l < r){
        int m = l + (r-l) / 2;
        orderMerge(vect, l, m);
        orderMerge(vect, m+1, r);
        merge(vect, l, m, r);
    }
}

// Function to print the vector O(n)
template<class T>
void simplePrintVector(vector<T> vect){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << "\n";
}

template<class T>
void createVector(vector<T> &vect, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        vect.push_back(rand() % n + 1);
    }
}

int main(){
    int n;
    cout << "Enter the n value: ";
    cin >> n;
    vector<int> numbers;
    createVector(numbers, n);
    simplePrintVector(numbers);
    orderQuick(numbers, 0, (n-1));
    simplePrintVector(numbers);
    return 0;
}