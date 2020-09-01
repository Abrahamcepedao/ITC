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

//Function to exchange the value of two elements in a given vector O(1)
void exchange(vector<char> &vect, int num1, int num2){
    int num = vect[num1];
    vect[num1] = vect[num2];
    vect[num2] = num;
}

//Function to find a given element using binary search O(log n)
template<class T>
void binarySearch(vector<T> vect, int &comp){
    int low = 0, high = vect.size()-1,step = 0, mid;
    while(low <= high  &&  step == 0){
        mid = (high + low) / 2 % 2 != 0 ? (high + low) / 2 + 1 : (high + low) / 2;
        comp++;
        vect[mid] == vect[mid + 1] ? low = mid + 2: (vect[mid] == vect[mid - 1]) ? high = mid - 2 : step = 1;
    }
    cout << vect[mid] << " " << comp;
}

//Function to find the unique character O(n)
void uniqueSequential(string letters, int &comp){
    int step = 0;
    char c[letters.size() + 1];
    strcpy(c, letters.c_str());
    for(int i = 0; i < letters.size() && step == 0; i++){
        comp++;
        if(c[i] != c[i+1] && c[i] != c[i-1]){
            cout << c[i] << " " << comp;
            step = 1;
        }
    }
}

//Function to convert the string to a vector O(n)
template<class T>
void createVector(vector<T> &vect, string letters){
    for(int i = 0; i < letters.size(); i++){
        vect.push_back(letters[i]);
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

int main(){
    string fileNumbers[] = {"01", "02", "03", "04"};
    for (int i = 0; i < 4; i++){
        ifstream lettersFile(fileNumbers[i] + ".in");
        cout << "\n\n<-----File " << fileNumbers[i] << "------>\n";
        int n, count = 0, comp = 0;
        string letters;
        while(lettersFile >> letters){
            if(count != 0){
                comp = 0;
                vector<char> vLetters;
                uniqueSequential(letters, comp); // get unique letter
                createVector(vLetters, letters);      // convert string to vector
                cout << " ";
                comp = 0;                         // restart comp counter
                binarySearch(vLetters, comp); // get unique letter with binary search
                cout << "\n";  
            }
            count++;
        }
    }
    return 0;
}