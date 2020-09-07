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

void split(vector<string> &vect, string str, string pattern){
    int beg = 0, end = 0;
    string value;
    while(end >= 0){
        end = str.find(pattern, beg);
        value = str.substr(beg, end - beg);
        beg = end + 1;
        vect.push_back(value);
    }
    
}

void printRegistry(Registry registry){
    cout << "\n" << registry.mon << "  " << registry.day << "  " << registry.hour << ":" << registry.min << ":" << registry.sec << "  " << registry.ip << "  " << registry.err;
}

void getErrorData(string &str, vector<string> values){
    str = values[4];
    for(int i = 5; i < values.size(); i++){
        str = str + " " + values[i];
    }
}

void readData(vector<Registry> &registries){
    //open file
    ifstream file("bitacora.txt");
    vector<string> values;
    vector<string> date;
    string line;
    int count = 0;
    while(getline(file, line) && count < 10){
        Registry registry;
        split(values, line, " ");
        registry.mon = values[0];
        registry.day = stoi(values[1]);
        split(date, values[2], ":");
        registry.hour = stoi(date[0]);
        registry.min = stoi(date[1]);
        registry.sec = stoi(date[2]);
        registry.ip = values[3];
        getErrorData(registry.err, values);
        registries.push_back(registry);
        values.clear();
        date.clear();
        count++;
    }
}

int main(){
    // create vector
    vector<Registry> registries;
    readData(registries);
    printRegistry(registries[0]);
    printRegistry(registries[5]);
    return 0;
}