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

int daysMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // number of days of each month
string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dic"}; // months

// Function: checkInt
// This function validates that the input is a number and between a given range
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

// Function: checkMonth
// This function verifies that a given month is valid
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

// Function: getMonthIndex
// This function returns the index of a given month
int getMonthIndex(string str){
    for(int i = 0; i < 12; i++){
        if(str == months[i]){
            return i;
        }
    }
    return -1;
}

// Struct: Registry
// This structs has the attributes of the file data as well as operator overloading to make comparisons
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

// Function: split
// This function splits a string given a pattern
void split(vector<string> &vect, string str, string pattern){
    int beg = 0, end = 0;
    string value;
    while(end >= 0){
        end = str.find(pattern, beg);
        vect.push_back(str.substr(beg, end - beg));
        beg = end + 1;
    }   
}
// Function: exchange
// This function exchanges two values from a vector
template<class T>
void exchange(vector<T> &vect, int elem1, int elem2){
    T elem = vect[elem1];
    vect[elem1] = vect[elem2];
    vect[elem2] = elem;
}

// Function: separate
// This is a fundamental part for the orderQuick algorithm
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
    vect[begin] > vect[r] ? exchange(vect, begin, r) : void();
    return r;
}

// Function: orderQuick 
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
    string date = (registry.hour < 10 ? "0" + to_string(registry.hour) : to_string(registry.hour)) + ":" + (registry.min < 10 ? "0" + to_string(registry.min) : to_string(registry.min)) + ":" + (registry.sec < 10 ? "0" + to_string(registry.sec) : to_string(registry.sec));
    cout << setw(5) << left << registry.mon << setw(4) << left << registry.day << setw(10) << left << date << setw(20) << left << registry.ip << setw(20) << registry.err << "\n";
}

// Function: fetchPrint
// This function recieves a vector and to ints. It prints the data from the vector within the indexes.
void fecthPrint(vector<Registry> &registries, int indexF, int indexL){
    cout << "Printing database ...\n\n";
    cout << "From-> ";
    printRegistry(registries[indexF]);
    cout << "To->   ";
    printRegistry(registries[indexL]);
    cout << "\n";
    int count = 1, i = indexF, pages = (indexL - indexF) / 20 + 1;
    string ans;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(ans != "0" && count <= pages){
        cout << "Printing page (" << count << "/" << pages << ")...\n";
        while(i < (indexF + 20*count) && i <= indexL){
            printRegistry(registries[i]);
            i++;
        }
        count++;
        cout << "Anything to go to next page\n";
        cout << "0 to finish\n";
        cout << "Enter option: ";
        getline( cin, ans );
        
    }
    cout << "\n\n";
}

// Function: getErrorData
// This function recieves a vector and a string, and uses the values of the vector to concatenate a string and save it on the string
void getErrorData(string &str, vector<string> values){
    str = values[4];
    for(int i = 5; i < values.size(); i++){
        str = str + " " + values[i];
    }
}

// Function: reaData
// This function reads data from "bitacora.txt" and saves it in a vector of type Registry (struct)
void readData(vector<Registry> &registries){
    ifstream file("bitacora.txt"); //open file
    vector<string> values; //initialize necessary vectors and variables
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
        registry.ip = values[3]; // get ip (string)
        getErrorData(registry.err, values); //get error (concatenate strings)
        registries.push_back(registry); // push new registry
        values.clear(); // clear temporal vectors
        date.clear();
    }
}

// Function: getIndexF ()
/* This function get the first index where the element can be found.
Furthermore, it is relevant to note that this functions can find the index  of months, days, hours, minutes, and seconds.
If the function does not find the value, it calls its self with the value + 1 while the value its less than the maximum value
 */
int getIndexF(int elem, vector<Registry> &registries, int low, int high, int num, int monIndex){
    int index, lowT = low, highT = high;
    int comparison[] = {11, daysMonth[monIndex]-1, 23, 59, 59};
    vector<int> numbers;
    while(low <= high){
        index = (high + low) / 2;
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
        numbers.clear();
    }
    return elem < comparison[num] ? getIndexF(elem + 1, registries, lowT, highT, num, monIndex) : -1;
}

// Function: getIndexL ()
/* This function get the last index where the element can be found.
Furthermore, it is relevant to note that this functions can find the index  of months, days, hours, minutes, and seconds.
If the function does not find the value, it calls its self with the value + 1 while the value its less than the maximum value
 */
int getIndexL(int elem, vector<Registry> &registries, int low, int high, int num, int monIndex){
    int index, lowT = low, highT = high;
    int comparison[] = {11, daysMonth[monIndex] - 1, 23, 59, 59};
    vector<int> numbers;
    while(low <= high){
        index = (high + low) / 2;
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
        numbers.clear();
    }
    return elem < comparison[num] ? getIndexL(elem + 1, registries, lowT, highT, num, monIndex) : -1;
}

// Function: Search by date
/* This function reads the date and hour of the first and last date to be outputed.
Then it gets the first and final index of each date.
Finally it calls fectPrint to print the registries within those dates
 */
void searchByDate(vector<Registry> registries){
    cout << "-> Searching by date...\n\n";
    string valuesText[] = {"month", "day", "hour", "minute", "second"};
    vector<int> indexes;
    vector<int> values;
    for(int j = 0; j < 2; j++){
        cout << (j == 0 ? "Enter first date..\n" : "\n\nEnter last date..\n");
        int indexF = 0, indexL = registries.size() - 1;

        values.push_back(getMonthIndex(checkMonth(0)));
        values.push_back(checkInt(1, daysMonth[values[0]], "day"));
        values.push_back(checkInt(0, 23, "hour"));
        values.push_back(checkInt(0, 59, "minute"));
        values.push_back(checkInt(0, 59, "sec"));
        
        for(int i = 0; i < 5; i++){
            int tempIndex = indexF;
            indexF = getIndexF(values[i], registries, indexF, indexL, i, values[0]);
            while(indexF ==  -1){
                values[i]--;
                values[i + 1] = i == 0 ? 1 : 0;
                indexF = getIndexF(values[i], registries, tempIndex, indexL, i, values[0]);
            }
            indexL = getIndexL(values[i], registries, indexF, indexL, i, values[0]);
        }
        values.clear();
        j == 0 ? indexes.push_back(indexF) : indexL != 0 && registries[indexL].day == registries[indexL+1].day ? indexes.push_back(indexL-1) : indexes.push_back(indexL);
    }
    registries[indexes[1]] > registries[indexes[0]] ? fecthPrint(registries, indexes[0], indexes[1]) : fecthPrint(registries, indexes[1], indexes[0]);
}

// Function: writeData
// This function writes the values of all the registries in a new file "bitacoraOrdenada.txt"
void writeData(vector<Registry> &registries){
    ofstream orderedData("bitacoraOrdenada.txt");
    for(int i = 0; i < registries.size(); i++){
        string date = (registries[i].hour < 10 ? "0" + to_string(registries[i].hour) : to_string(registries[i].hour)) + ":" + (registries[i].min < 10 ? "0" + to_string(registries[i].min) : to_string(registries[i].min)) + ":" + (registries[i].sec < 10 ? "0" + to_string(registries[i].sec) : to_string(registries[i].sec));
        orderedData << setw(5) << left << registries[i].mon << setw(4) << left << registries[i].day << setw(10) << left << date << setw(20) << left << registries[i].ip << setw(20) << registries[i].err << "\n";
    }
    orderedData.close();
}

// Function: menu
// This function has an input for the user to choose what does he/she wants to do. It also calls itself while the answer 1= 3
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
    readData(registries); // read data from file
    orderQuick(registries, 0, registries.size()-1); // order vector using the quick sort method
    cout << "\n\n\n<-----------------Welcome to the registry database!---------------->\n\n\n";
    writeData(registries); // write data on new file
    menu(registries); // call menu
    return 0;
}