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
string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dic"};

int getMonthIndex(string str){
    for(int i = 0; i < 12; i++){
        if(str == months[i]){
            return i;
        }
    }
    return -1;
}

struct Registry{
    string mon;
    int day;
    int hour;
    int min;
    int sec;
    string ip;
    string err;

    bool operator>(const Registry ry){
        return getMonthIndex(mon) > getMonthIndex(ry.mon) ? true : getMonthIndex(mon) < getMonthIndex(ry.mon) ? false : day > ry.day ? true : day < ry.day ? false : hour > ry.hour ? true : hour < ry.hour ? false : min > ry.min ? true : min < ry.min ? false : sec > ry.sec ? true : false;
    }
    bool operator>=(const Registry ry){
        return getMonthIndex(mon) > getMonthIndex(ry.mon) ? true : getMonthIndex(mon) < getMonthIndex(ry.mon) ? false : day > ry.day ? true : day < ry.day ? false : hour > ry.hour ? true : hour < ry.hour ? false : min > ry.min ? true : min < ry.min ? false : sec < ry.sec ? false : true;
    }

    
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

template<class T>
void exchange(vector<T> &vect, int elem1, int elem2){
    T elem = vect[elem1];
    vect[elem1] = vect[elem2];
    vect[elem2] = elem;
}


template<class T>
int separate(vector<T> &vect, int begin, int end){
    int pos = begin+1, r = end;
    while(pos < r){
        while(vect[begin] > vect[pos] && pos != end){
            pos++;
        }
        while(vect[r] >= vect[begin] && r != begin){
            r--;
        }
        (r > pos) ? exchange(vect, pos, r) : exchange(vect, begin, r);
    }
    if(vect[begin] > vect[r]){
        exchange(vect, begin, r);
    }
    return r;
}

// Quick sort algorithm - Comlplexity O(nlogn)
template<class T>
void orderQuick(vector<T> &vect, int l, int r){
    int pos;
    if(l < r){
        pos = separate(vect, l, r);
        orderQuick(vect, l, pos-1);
        orderQuick(vect, pos+1, r);
    }
}

void printRegistry(Registry registry){
    cout << "\n" << registry.mon << "  " << registry.day << "  " << registry.hour << ":" << registry.min << ":" << registry.sec << "  " << registry.ip << "  " << registry.err;
}

void printRegistries(vector<Registry> registries){
    for(int i = 0; i < registries.size(); i++){
        printRegistry(registries[i]);
    }
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
    //initialize necessary vectors and variables
    vector<string> values;
    vector<string> date;
    string line;
    int count = 0;
    while(getline(file, line) && count < 10){
        Registry registry;
        split(values, line, " "); // split each line " "
        registry.mon = values[0]; // get month
        registry.day = stoi(values[1]); // get day (numeric)
        split(date, values[2], ":"); // split date ":"
        registry.hour = stoi(date[0]); // get hour (numeric)
        registry.min = stoi(date[1]); //get minute (numeric)
        registry.sec = stoi(date[2]); //get second (numeric)
        registry.ip = values[3];
        getErrorData(registry.err, values);
        registries.push_back(registry);
        values.clear();
        date.clear();
        count++;
    }
}

int main(){
    vector<Registry> registries; // create vector
    readData(registries); // read data
    orderQuick(registries, 0, registries.size()-1);
    printRegistries(registries);
    
    return 0;
}