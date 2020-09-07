// This algorithm sort a  vector with the Quick sort method
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

int daysMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Registry{
    string mon;
    int day;
    int hour;
    int min;
    int sec;
    string ip;
    string err;
};

void split(vector<string> vect, string str, string pattern){
    int beg = 0, end = 0;
    string value;
    cout << "size " << str.size() << endl;
    while(end >= 0){
        end = str.find(pattern, beg);
        value = str.substr(beg, end - beg);
        beg = end + 1;
        vect.push_back(value);
    }
    
}

void readData(vector<Registry> &registries){
    //open file
    ifstream file("bitacora.txt");
    vector<string> values;
    string line;
    int count = 0;
    while(getline(file, line) && count < 10){
        split(values, line, " ");
        
        count++;
    }
}

int main(){
    // create vector
    vector<Registry> registries;
    readData(registries);
    return 0;
}