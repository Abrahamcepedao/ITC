#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int SIZE = 50;

template<class T>
class Hash{
    private:
        T table[SIZE];

        int getNums(string key);
        int getHash(int k, int j) { return fmod(k + pow(j, 2), SIZE); };
        inline bool isInteger(const char & s);
    public: 
        Hash();
        void insert(string key);
        void print();
};


//Constuctor
template<class T>
Hash<T>::Hash(){

}

template<class T>
inline bool Hash<T>::isInteger(const char & ss){
   string s = to_string(ss);
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

template<class T>
int Hash<T>::getNums(string key){
    string numbers = "";
    for(int i = 0; i < key.size(); i++){
        if(isdigit(key[i])){
            numbers += key[i];
        }
    }
    return stoi(numbers);
}

template<class T>
void Hash<T>::insert(string key){
    int j = 0;
    int newKey = getNums(key);
    int hash = getHash(newKey, j);
    while(table[hash] != "" && j < SIZE){
        hash = getHash(newKey, j++);
    }
    table[hash] = key;
}

template<class T>
void Hash<T>::print(){
    cout << "Position  " << "  Value\n";
    for(int i = 0; i < SIZE; i++){
        cout << i << "             ";
        cout << table[i] << "\n";
    }
    cout << "\n";
}