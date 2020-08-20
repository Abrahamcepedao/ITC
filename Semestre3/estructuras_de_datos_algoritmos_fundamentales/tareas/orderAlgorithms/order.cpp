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
void orderExchange(vector<T> &vect, int &comp, int &inter){
    for(int i = 0; i < vect.size(); i++){
        for(int j = i+1; j < vect.size(); j++){
            comp++;
            if(vect[i] > vect[j]){
                inter++;
                exchange(vect, i, j);
            }
        }
    }
}

template<class T>
void orderBubble(vector<T> &vect, int &comp, int &inter){
    for(int i = 0; i < vect.size(); i++){
        for(int j = 0; j < (vect.size()-i); j++){
            comp++;
            if(vect[j] > vect[j+1]){
                inter++;
                exchange(vect, j, j+1);
            }
        }
    }
}

template<class T>
void orderSelection(vector<T> &vect, int &comp, int &inter){
    T min;
    for(int i = 0; i < vect.size(); i++){
        min = i;
        for(int j = i+1; j < vect.size(); j++){
            comp++;
            if(vect[j] < vect[min]){
                min = j;
            }
        }
        if(min != i){
            inter++;
            exchange(vect, i, min);
        }
    }
}


template<class T>
void printVector(vector<T> vect, int comp, int inter){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << "\nComparisons: " << comp << "\n";
    cout << "Exchanges:   " << inter << "\n";
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
    cout << "\n\n\n\n1. Order by Exchange\n";
    cout << "2. Order by Bubble\n";
    cout << "3. Order by Selection\n";
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
        int comp = 0, inter = 0;
        ans = menu();
        printVector(vect, comp, inter);
        switch (ans){
            case 1:
                cout << "\nOrdered vector by Exchange\n";
                orderExchange(vect, comp, inter);
                break;
            case 2:
                cout << "\nOrdered vector by Bubble\n";
                orderExchange(vect, comp, inter);
                break;
            case 3:
                cout << "\nOrdered vector by Direct Selection\n";
                orderSelection(vect, comp, inter);
                break;
            case 4:
                cout << "\nOrdered vector by Merge\n";
                //orderExchange(vect);
                break;
            default:
                break;
        }
        if(ans != 0){
            printVector(vect, comp, inter);
        } else{
            cout << "The program has finished\n";
        }
    }
    return 0;
}