// This program contains different algorithms for sorting a vector
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
void orderBubble(vector<T> &vect){
    for(int i = 0; i < vect.size(); i++){
        for(int j = 0; j < (vect.size()-i); j++){
            if(vect[j] > vect[j+1]){
                exchange(vect, j, j+1);
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
    }
}

int menu(){
    int ans;
    cout << "1. Order by Exchange\n";
    cout << "2. Order by Bubble\n";
    cout << "3. Order by Merge\n";
    cout << "0. To exit\n\n";
    cout << "Enter answer: ";
    cin >> ans;
    return ans;
}

int main(){
    int n, ans = 1;
    cout << "Enter the n value: ";
    cin >> n;
    while(ans != 0){
        vector<int> vect;
        createVector(vect, n, 100);
        ans = menu();
        switch (ans){
            case 1:
                cout << "Ordered vector by Exchange\n";
                orderExchange(vect);
                break;
            case 2:
                cout << "Ordered vector by Bubble\n";
                orderExchange(vect);
                break;
            case 3:
                cout << "Ordered vector by Merge\n";
                //orderExchange(vect);
                break;
            default:
                break;
        }
        if(ans != 0){
            printVector(vect);
        } else{
            cout << "The program has finished\n";
        }
    }
    return 0;
}