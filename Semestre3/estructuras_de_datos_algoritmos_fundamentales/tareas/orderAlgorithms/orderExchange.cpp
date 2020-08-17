// This algorithm sort a  vector with the exchange method
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
using namespace std;

template<class T>
void exchange(vector<T> &vect, int num1, int num2){
    int num = vect[num1];
    vect[num1] = vect[num2];
    vect[num2] = num;
}

template<class T>
void orderExchange(vector<T> &vect){
    for(int i = 0; i < vect.size(); i++){
        for(int j = i+1; j < vect.size(); j++){
            if(vect[i] > vect[j]){
                exchange(vect, i, j);
            }
        }
    }
}

template<class T>
void printVector(vector<T> vect){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << "\n";
    }
}

template<class T>
void createVector(vector<T> &vect, int n, int max){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        vect.push_back(rand() % max + 1);
        cout << vect[i] << endl;
    }
}

int main(){
    int n;
    cout << "Enter the n value: ";
    cin >> n;
    vector<int> vect;
    createVector(vect, n, 100);
    orderExchange(vect);
    cout << "Ordered vector\n";
    printVector(vect);
    return 0;
}