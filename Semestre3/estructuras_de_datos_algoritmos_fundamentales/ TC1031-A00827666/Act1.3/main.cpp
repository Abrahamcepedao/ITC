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
    cout << (num == -1 ? "Enter a valid month: " : num == 0 ? "Enter month: " : "Enter a prior month: ");
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

void fecthPrint(vector<Registry> &registries, int indexF, int indexL){
    cout << "Printing database ...\n\n";
    for(int i = indexF; i <= indexL; i++){
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
    while(getline(file, line)){
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
    }
}


int getIndexF(int elem, vector<Registry> &registries, int low, int high, int num, int monIndex){
    int index, lowT = low, highT = high;
    int comparison[] = {11, daysMonth[monIndex]-1, 23, 59, 59};
    while(low <= high){
        index = (high + low) / 2;
        vector<int> numbers;
        for(int i = -1; i < 1; i++){
            numbers.push_back(getMonthIndex(registries[index+i].mon));
            numbers.push_back(registries[index + i].day);
            numbers.push_back(registries[index + i].hour);
            numbers.push_back(registries[index + i].min);
            numbers.push_back(registries[index + i].sec);
        }
        if(numbers[num+5] == elem){
            if(index == low ||  numbers[num+5] > numbers[num]){
                return index;
            } else{
                high = index - 1;
            }
        } else if(numbers[num+5] > elem){
            high = index - 1;
        } else{
            low = index + 1;
        }
    }
    return elem < comparison[num] ? getIndexF(elem + 1, registries, lowT, highT, num, monIndex) : -1;
}

int getIndexL(int elem, vector<Registry> &registries, int low, int high, int num, int monIndex){
    int index, lowT = low, highT = high;
    int comparison[] = {12, daysMonth[elem], 23, 60, 60};
    while(low <= high){
        index = (high + low) / 2;
        vector<int> numbers;
        for(int i = 0; i < 2; i++){
            numbers.push_back(getMonthIndex(registries[index+i].mon));
            numbers.push_back(registries[index + i].day);
            numbers.push_back(registries[index + i].hour);
            numbers.push_back(registries[index + i].min);
            numbers.push_back(registries[index + i].sec);
        }
        if(numbers[num] == elem){
            if(index == high ||  numbers[num] < numbers[num+5]){
                return index;
            } else{
                low = index + 1;
            }
        } else if(numbers[num] > elem){
            high = index - 1;
        } else{
            low = index + 1;
        }
    }
    return elem < comparison[num] ? getIndexF(elem + 1, registries, lowT, highT, num, monIndex) : -1;
}

void searchByDate(vector<Registry> registries){
    cout << "-> Searching by date...\n\n";
    string valuesText[] = {"month", "day", "hour", "minute", "second"};
    vector<int> indexes;
    for(int j = 0; j < 2; j++){
        cout << (j == 0 ? "Enter first date..\n" : "Enter last date..\n");
    
        vector<int> newValues(5, -1);
        vector<int> values;
        int indexF = 0, indexL = registries.size() - 1;

        values.push_back(getMonthIndex(checkMonth(0)));
        values.push_back(checkInt(1, daysMonth[values[0]], "day"));
        values.push_back(checkInt(0, 23, "hour"));
        values.push_back(checkInt(0, 59, "minute"));
        values.push_back(checkInt(0, 59, "sec"));
        
        for(int i = 0; i < 5; i++){
            int tempIndex = indexF;
            indexF = getIndexF(values[i], registries, indexF, indexL, i, newValues[1] != -1 ? newValues[1] : values[1]);
            while(indexF ==  -1){
                newValues[i] = i == 0 ? getMonthIndex(checkMonth(1)) : checkInt(i == 1 ? 1 : 0, values[i] - 1, "a prior " + valuesText[i]);
                indexF = getIndexF(newValues[i], registries, tempIndex, indexL, i, newValues[1] != -1 ? newValues[1] : values[1]);
            }
            indexL = getIndexL(newValues[i] != -1 ? newValues[i] : values[i], registries, indexF, indexL, i, newValues[1] != -1 ? newValues[1] : values[1]);
        }
        printRegistry(registries[indexF]);
        newValues.clear();
        values.clear();
        j == 0 ? indexes.push_back(indexF) : indexes.push_back(indexL);
    }
    registries[indexes[1]] > registries[indexes[0]] ? fecthPrint(registries, indexes[0], indexes[1]) : fecthPrint(registries, indexes[1], indexes[0]);
}

void writeData(vector<Registry> &registries){
    ofstream orderedData("bitacoraOrdenada.txt");
    for(int i = 0; i < registries.size(); i++){
        string date = to_string(registries[i].hour) + ":" + to_string(registries[i].min) + ":" + to_string(registries[i].sec);
        orderedData << setw(5) << left << registries[i].mon << setw(4) << left << registries[i].day << setw(10) << left << date << setw(20) << left << registries[i].ip << setw(20) << registries[i].err << "\n";
    }
    orderedData.close();
}

void menu(vector<Registry> &registries){
    cout << "\n\n\n-> Select an option\n";
    cout << "1. Print entire database\n";
    cout << "2. Search by date\n";
    cout << "3. Terminate\n";
    int ans = checkInt(1, 3, "option");
    switch(ans){
        case 1:
            fecthPrint(registries, 0, registries.size()-1);
            break;
        case 2:
            searchByDate(registries);
            break;
        case 3:
            cout <<  "The program has finished with ease..\n\n";
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
    writeData(registries);
    menu(registries);
    return 0;
}