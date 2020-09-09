// This algorithm sort a  vector with the Quick sort method
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

int daysMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dic"};

// Input validation
int checkInt(int min, int max, string inquiry){
    int num;
    cout << "Enter " << inquiry << ": ";
    cin >> num;
    while(1){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Input must be a number.. try again: ";
            cin >> num;
        }
        if(!cin.fail()){
            if(num < min || num > max){
                cout << "Enter a valid " << inquiry << ": ";
                cin >> num;
            } else{
                break;
            }
        }
    }
    return num;
}

string checkMonth(int num){
    cout << (num != -1 ? "Enter month: " : "Enter a valid month: ");
    string mon;
    bool accept = false;
    cin >> mon;
    for(int i = 0; i < 12; i++){
        if(mon == months[i]){
            accept = true;
        }
    }
    return (accept ? mon : checkMonth(-1));
}

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
    string date = to_string(registry.hour) + ":" + to_string(registry.min) + ":" + to_string(registry.sec);
    cout << setw(5) << left << registry.mon << setw(4) << left << registry.day << setw(10) << left << date << setw(20) << left << registry.ip << setw(20) << registry.err << "\n";
}

void printRegistries(vector<Registry> registries){
    cout << "Printing database ...\n\n";
    for(int i = 0; i < registries.size(); i++){
        printRegistry(registries[i]);
    }
    cout << "\n\n";
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


int getIndexMonthF(string mon, vector<Registry> &registries, int low, int high){
    int index;
    while(low <= high){
        index = (high + low) / 2;
        if(getMonthIndex(registries[index].mon) == getMonthIndex(mon)){
            if(index == low ||  getMonthIndex(registries[index].mon) > getMonthIndex(registries[index-1].mon)){
                return index;
            } else{
                high = index - 1;
            }
        } else if(getMonthIndex(registries[index].mon) > getMonthIndex(mon)){
            high = index - 1;
        } else{
            low = index + 1;
        }
    }
    return getMonthIndex(mon) < 6 ? getIndexMonthF(months[getMonthIndex(mon) + 1], registries, 0, registries.size() - 1) : getIndexMonthF(months[getMonthIndex(mon) - 1], registries, 0, registries.size() - 1);
}

int getIndexMonthL(string mon, vector<Registry> &registries, int low, int high){
    int index;
    while(low <= high){
        index = (high + low) / 2;
        if(getMonthIndex(registries[index].mon) == getMonthIndex(mon)){
            if(index == high ||  getMonthIndex(registries[index].mon) < getMonthIndex(registries[index+1].mon)){
                return index;
            } else{
                low = index + 1;
            }
        } else if(getMonthIndex(registries[index].mon) > getMonthIndex(mon)){
            high = index - 1;
        } else{
            low = index + 1;
        }
    }
    return getMonthIndex(mon) < 6 ? getIndexMonthF(months[getMonthIndex(mon) + 1], registries, 0, registries.size() - 1) : getIndexMonthF(months[getMonthIndex(mon) - 1], registries, 0, registries.size() - 1);
}

int getIndexDay(int day, vector<Registry> &registries, int monIndex, int low, int high){
    int index;
    int lowT = low;
    int highT = high;
    while(low <= high){
        index = (high + low) / 2;
        if(registries[index].day == day){
            if(index == low ||  registries[index].day > registries[index-1].day){
                return index;
            } else{
                high = index - 1;
            }
        } else if(registries[index].day > day){
            high = index - 1;
        } else{
            low = index + 1;
        }
    }
    return day < daysMonth[getMonthIndex(registries[monIndex].mon)] ? getIndexDay(day + 1, registries, monIndex, lowT, highT) : -1;
}

void searchByDate(vector<Registry> registries){
    cout << "-> Searching by date...\n\n";
    cout << "Enter first date..\n";
    string mon = checkMonth(0);
    int day = checkInt(1, daysMonth[getMonthIndex(mon)], "day");
    int hour = checkInt(0,23, "hour");
    int min = checkInt(0, 59, "minute");
    int sec2 = checkInt(0, 59, "sec");
    int indexF = getIndexMonthF(mon, registries, 0, registries.size() - 1);
    int indexL = getIndexMonthL(mon, registries, indexF, registries.size() - 1);
    cout << "indexF-> " << indexF << endl;
    cout << "indexL-> " << indexL << endl;
    int indexD =  getIndexDay(day, registries, indexF, indexF, indexL);
    while(indexD == -1){
        int newDay = checkInt(1, day-1, "a prior day");
        indexD = getIndexDay(newDay, registries, indexF, indexF, indexL);
    }
    cout << "indexD-> " << indexD << endl;
    /* cout << "Enter second date..";
    string mon2 = checkMonth(0);
    cout << "Enter day: ";
    int day2 = checkInt(1, daysMonth[getMonthIndex(mon)]);
    cout << "Enter hour: ";
    int hour2 = checkInt(0, 23);
    cout << "Enter minute: ";
    int min2 = checkInt(0, 59);
    cout << "Enter sec: ";
    int sec2 = checkInt(0, 59); */
    
    
}



void menu(vector<Registry> &registries){
    cout << "-> Select an option\n";
    cout << "1. Print entire database\n";
    cout << "2. Search by date\n";
    cout << "3. Terminate\n";
    int ans = checkInt(1, 3, "option");
    switch(ans){
        case 1:
            printRegistries(registries);
            break;
        case 2:
            searchByDate(registries);
            break;
        case 3:
            break;
        default:
            break;
    }
    (ans != 3 ? menu(registries) : void());
}

int main(){
    vector<Registry> registries; // create vector
    readData(registries); // read data
    orderQuick(registries, 0, registries.size()-1); // order vector using quick sort
    //printRegistries(registries); // print registries
    cout << "\n\n\n<-----------------Welcome to the registry database!---------------->\n\n\n";
    menu(registries);

    return 0;
}