// This program get the unique value within a string of duplicate letters using binary and sequantial search
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

template<class T>
void sequentialSearch(vector<T> vect, int &comp, T elem){
    int step = 0;
    for(int i = 0; i < vect.size() && step == 0; i++){
        comp++;
        if(vect[i] == elem){
            cout << vect[i] << " " << comp;
            step = 1;
        }
    }
}

template<class T>
void binarySearch(vector<T> vect, int &comp, T elem){
    int low = 0;
    int high = vect.size() - 1;
    int step = 0;
    while(low <= high && step == 0){
        int medium = (high + low) / 2;
        comp++;
        //cout << "-->" << vect[medium] << " " << comp << endl;
        if(vect[medium] == elem){
            cout << vect[medium] << " " << comp;
            step = 1;
        } else if(vect[medium] > elem){
            high = medium - 1;
        } else{
            low = medium + 1;
        }
    }
}

char uniqueLetter(string letters){
    char c[letters.size() + 1];
    strcpy(c, letters.c_str());
    for(int i = 0; i < letters.size(); i++){
        if(c[i] != c[i+1] && c[i] != c[i-1]){
            return c[i];
        }
    }
    throw runtime_error("Could not find unique letter\n\n");
}

template<class T>
void createVector(vector<T> &vect, string letters){
    for(int i = 0; i < letters.size(); i++){
        vect.push_back(letters[i]);
    }
}

template<class T>
void simplePrintVector(vector<T> vect){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << "\n";
}

int main(){
    string fileNumbers[] = {"01", "02", "03", "04"};
    for (int i = 0; i < 4; i++){
        ifstream lettersFile(fileNumbers[i] + ".in");
        cout << "\n\n<-----File " << fileNumbers[i] << "------>\n";
        int n, count = 0;
        string letters;
        while(lettersFile >> letters){
            if(count != 0){
                int comp = 0;
                char uL = uniqueLetter(letters); // get unique letter
                vector<char> vLetters;
                createVector(vLetters, letters);      // convert string to vector
                orderInsertion(vLetters);             // order vector
                sequentialSearch(vLetters, comp, uL); // find letter (Sequential)
                cout << " ";
                comp = 0;                         // restart comp counter
                binarySearch(vLetters, comp, uL); // find letter binary
                cout << "\n";  
            }
            count++;
        }
    }
    return 0;
}