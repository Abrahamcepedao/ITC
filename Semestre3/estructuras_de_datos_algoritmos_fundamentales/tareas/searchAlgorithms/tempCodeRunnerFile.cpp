// This program contains different algorithms for sorting a vector
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

void exchange(vector<char> &vect, int num1, int num2){
    int num = vect[num1];
    vect[num1] = vect[num2];
    vect[num2] = num;
}

void orderInsertion(vector<char> &vect){
    int c = 1, i = 0, aux = 1;
    while(c < vect.size()){
        if(vect[c] < vect[i] && i >= 0){
            exchange(vect, i, c);
            c--;
            i--;
        } else{
            aux++;
            c = aux;
            i = aux-1;
        }
    }
}

void sequentialSearch(vector<char> vect, int &comp){
    int step = 0;
    for(int i = 0; i < vect.size() && step == 0; i++){
        comp++;
        if(vect[i] != vect[i+1] && vect[i] != vect[i-1]){
            cout << vect[i];
            step = 1;
        }
    }
}

template<class T>
void orderVector(int n, vector<T> list){
    string str;
    for(int i = 0; i < n; i++){
        vector<char> characters;
        int comp = 0;
        str = list[i];
        char c[str.size()+1];
        strcpy(c, str.c_str());
        for(int j = 0; j < sizeof(c); j++){
            characters.push_back(c[j]);
        }
        orderInsertion(characters);
        for(int j = 0; j < characters.size(); j++){
            cout << characters[j] << " ";
        }
        cout << "\n";
        sequentialSearch(characters, comp);
        cout << " " << comp << "\n";
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> lettersList;
    string letters;
    ifstream lettersFile;
    lettersFile.open("letters.txt");
    while(lettersFile >> letters){
        lettersList.push_back(letters);
    }
    orderVector(n, lettersList);
    return 0;
}