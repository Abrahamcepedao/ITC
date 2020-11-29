#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include "LinkedList.h"

using namespace std;

const int SIZE2 = 50;

template<class T>
class HashC{
    private:
        vector< LinkedList<T> > table;
        
        int getNums(string key);
        int getHash(int k, int j){return fmod(k + pow(j, 2), SIZE2);};
        inline bool isInteger(const char & s);
    public:
        HashC();
        void insert(string key);
        void print();
};


//Constuctor
template<class T>
HashC<T>::HashC(){
    LinkedList<T> temp;
    vector< LinkedList<T> > tempTable(SIZE2, temp);
    table = tempTable;
}

template<class T>
inline bool HashC<T>::isInteger(const char & ss){
   string s = to_string(ss);
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

template<class T>
int HashC<T>::getNums(string key){
    string numbers = "";
    for(int i = 0; i < key.size(); i++){
        if(isdigit(key[i])){
            numbers += key[i];
        }
    }
    return stoi(numbers);
}

template<class T>
void HashC<T>::insert(string key){
    int j = 0;
    int newKey = getNums(key);
    int hash = getHash(newKey, j);
    if(table[hash].isEmpty()){
        table[hash].addFirst(key);
    } else{
        table[hash].addLast(key);
    }
    table[hash].print();
}

template<class T>
void HashC<T>::print(){
    cout << "Position  " << "  Value\n";
    for(int i = 0; i < SIZE2; i++){
        cout << i << "             ";
        table[i].print();
    }
    cout << "\n";
}