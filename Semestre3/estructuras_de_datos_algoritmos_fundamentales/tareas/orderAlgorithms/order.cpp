// This program contains different algorithms for sorting a vector
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <chrono>
#include <ctime>
#include <random>
using namespace std;
using namespace std::chrono;


char lettersC[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                          'r', 's', 't', 'u', 'v', 'w', 'x',
                          'y', 'z'};

string lettersS[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};


template<class T>
void exchange(vector<T> &vect, int num1, int num2){
    T num = vect[num1];
    vect[num1] = vect[num2];
    vect[num2] = num;
}

template<class T>
void orderExchange(vector<T> &vect, int &comp, int &inter, double &duration){
    chrono::time_point<chrono::system_clock> start, stop;
    start = chrono::system_clock::now();
    for(int i = 0; i < vect.size(); i++){
        for(int j = i+1; j < vect.size(); j++){
            comp++;
            if(vect[i] > vect[j]){
                inter++;
                exchange(vect, i, j);
            }
        }
    }
    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = stop - start;
    duration = elapsed_seconds.count();
}

template<class T>
void orderBubble(vector<T> &vect, int &comp, int &inter, double &duration){
    chrono::time_point<chrono::system_clock> start, stop;
    start = chrono::system_clock::now();
    bool cont = true;
    for(int i = 0; i < vect.size() && cont; i++){
        cont = false;
        for(int j = 0; j < (vect.size()-i); j++){
            comp++;
            if(vect[j] > vect[j+1]){
                inter++;
                exchange(vect, j, j+1);
                cont = true;
            }
        }
    }
    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = stop - start;
    duration = elapsed_seconds.count();
}

template<class T>
void orderSelection(vector<T> &vect, int &comp, int &inter, double &duration){
    chrono::time_point<chrono::system_clock> start, stop;
    start = chrono::system_clock::now();
    int min;
    for(int i = 0; i < vect.size(); i++){
        min = i;
        for(int j = i+1; j < vect.size(); j++){
            comp++;
            if(vect[j] < vect[min]){
                min = j;
            }
        }
        if(min != i){
            inter++;
            exchange(vect, i, min);
        }
    }
    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = stop - start;
    duration = elapsed_seconds.count();
}

template<class T>
void orderInsertion(vector<T> &vect, int &comp, int &inter, double &duration){
    chrono::time_point<chrono::system_clock> start, stop;
    start = chrono::system_clock::now();
    int c = 1, i = 0, aux = 1;
    while(c < vect.size()){
        comp++;
        if(vect[c] < vect[i] && i >= 0){
            inter++;
            exchange(vect, i, c);
            c--;
            i--;
        } else{
            aux++;
            c = aux;
            i = aux-1;
        }
    }
    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = stop - start;
    duration = elapsed_seconds.count();
}

template<class T>
void merge(vector<T> &vect, int l, int m, int r, int &comp, int &iter){
    int i = 0, j = 0, count = l;
    vector<T> vect1, vect2;
    for(int e = l; e <= m; e++){
        vect1.push_back(vect[e]);
    }
    for(int k = m+1; k <= r; k++){
        vect2.push_back(vect[k]);
    }
    while(i < (m-l+1) && j < (r-m)){
        comp++;
        iter++;
        if(vect1[i] > vect2[j]){
            vect[count] = vect2[j];
            j++;
        } else{
            vect[count] = vect1[i];
            i++;
        }
        count++;
    }
    while(i < (m - l + 1)){
        iter++;
        vect[count] = vect1[i];
        count++;
        i++;
    }
    while(j < (r-m)){
        iter++;
        vect[count] = vect2[j];
        count++;
        j++;
    }
} 

template<class T>
void orderMerge(vector<T> &vect, int l, int r, int &comp, int &iter){
    if(l < r){
        int m = l + (r-l) / 2;
        orderMerge(vect, l, m, comp, iter);
        orderMerge(vect, m + 1, r, comp, iter);
        merge(vect, l, m, r, comp, iter);
    }
}

template<class T>
int separate(vector<T> &vect, int begin, int end, int &comp, int &inter){
    int pos = begin+1, r = end;
    while(pos < r){
        comp++;
        while(vect[pos] < vect[begin] && pos != end){
            pos++;
            comp++;
        }
        while(vect[r] >= vect[begin] && r != begin){
            r--;
            comp++;
        }
        (r > pos) ? exchange(vect, pos, r) : exchange(vect, begin, r);
        inter++;
    }
    if(vect[begin] > vect[r]){
        exchange(vect, begin, r);
        inter++;
    }
    return r;
} 

template<class T>
void orderQuick(vector<T> &vect, int l, int r, int &comp, int &inter){
    int pos;
    if(l < r){
        pos = separate(vect, l, r, comp, inter);
        orderQuick(vect, l, pos-1, comp, inter);
        orderQuick(vect, pos+1, r, comp, inter);
    }
}


template<class T>
int sequentialSearch(vector<T> vect, T elem, int &comp, double &duration){
    chrono::time_point<chrono::system_clock> start, stop;
    start = chrono::system_clock::now();
    for(int i = 0; i < vect.size(); i++){
        comp++;
        if(elem == vect[i]){
            stop = chrono::system_clock::now();
            chrono::duration<double> elapsed_seconds = stop - start;
            duration = elapsed_seconds.count();
            return i;
        }
    }
    throw runtime_error("Element was not found...\n");
    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = stop - start;
    duration = elapsed_seconds.count();
}

template<class T>
int binarySearch(vector<T> vect, T elem, int &comp, double &duration){
    chrono::time_point<chrono::system_clock> start, stop;
    start = chrono::system_clock::now();
    int low = 0;
    int high = vect.size() - 1;
    while(low <= high){
        int medium = (high + low) / 2;
        comp++;
        if(vect[medium] == elem){
            return medium;
        } else if(vect[medium] > elem){
            high = medium - 1;
        } else{
            low = medium + 1;
        }
    }
    throw runtime_error("Element was not found...\n");
    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = stop - start;
    duration = elapsed_seconds.count();
}

template<class T>
void simplePrintVector(vector<T> vect){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << "\n";
}

template<class T>
void printVector(vector<T> vect, int comp, int inter, double duration){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    printf("\n<----Comparisons/iterations: %d\n", comp);
    printf("<----Exhanges: %d\n", inter);
    printf("<----Duration: %.6fs\n", duration);
}

template<class T>
void createVectorInt(vector<T> &vect, int n){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, n);
    for(int i = 0; i < n; i++){
        vect.push_back(dist(mt));
    }
}

template<class T>
void createVectorDouble(vector<T> &vect, double n){
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.0, n);
    /* default_random_engine generator;
    uniform_real_distribution<double> dist(0.0, n); */
    for(int i = 0; i < n; i++){
        /* vect.push_back(dist(generator)); */
        vect.push_back(dist(mt));
    }
}

template<class T>
void createVectorChar(vector<T> &vect, int n){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 25);
    for(int i = 0; i < n; i++){
        vect.push_back(lettersC[dist(mt)]);
    }
}

template<class T>
void createVectorString(vector<T> &vect, int n){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 25);
    for(int i = 0; i < n; i++){
        vect.push_back(lettersS[dist(mt)] + lettersS[dist(mt)]);
    }
}

int typeMenu(){
    int ans;
    cout << "\n\n\n\n1. Integers\n";
    cout << "2. Doubles\n";
    cout << "3. Character\n";
    cout << "4. String\n";
    cout << "0. To exit\n\n";
    cout << "Enter answer: ";
    cin >> ans;
    return ans;
}

int menu(){
    int ans;
    cout << "\n\n\n\n1. Order by Exchange\n";
    cout << "2. Order by Bubble\n";
    cout << "3. Order by Selection\n";
    cout << "4. Order by Insertion\n";
    cout << "5. Order by Merge\n";
    cout << "6. Order by Quick\n";
    cout << "7. Sequential search\n";
    cout << "8. Binary search\n";
    cout << "0. To exit\n\n";
    cout << "Enter answer: ";
    cin >> ans;
    return ans;
}

int main(){
    int n, ans = 1, typeAns;
    cout << "Enter the number of values: ";
    cin >> n;
    typeAns = typeMenu();
    while(ans != 0){
        ans = menu();
        
        int comp = 0, inter = 0;
        double duration;
        chrono::time_point<chrono::system_clock> start, stop;
        chrono::duration<double> elapsed_seconds;

        if(typeAns == 1  && ans != 0){
            vector<int> vect;
            createVectorInt(vect, n);
            simplePrintVector(vect);
            int num;
            switch (ans){
                case 1:
                    cout << "\nOrdered vector by Exchange\n";
                    orderExchange(vect, comp, inter, duration);
                    break;
                case 2:
                    cout << "\nOrdered vector by Bubble\n";
                    orderBubble(vect, comp, inter, duration);
                    break;
                case 3:
                    cout << "\nOrdered vector by Direct Selection\n";
                    orderSelection(vect, comp, inter, duration);
                    break;
                case 4:
                    cout << "\nOrdered vector by Insertion\n";
                    orderInsertion(vect, comp, inter, duration);
                    break;
                case 5:
                    start = chrono::system_clock::now();
                    cout << "\nOrdered vector by Merge\n";
                    orderMerge(vect, 0, vect.size()-1, comp, inter);
                    stop = chrono::system_clock::now();
                    elapsed_seconds = stop - start;
                    duration = elapsed_seconds.count();
                    break;
                case 6:
                    start = chrono::system_clock::now();
                    cout << "\nOrdered vector by Quick sort\n";
                    orderQuick(vect, 0, vect.size() - 1, comp, inter);
                    stop = chrono::system_clock::now();
                    elapsed_seconds = stop - start;
                    duration = elapsed_seconds.count();
                    break;
                case 7:
                    cout << "\nFind by Sequential search\n";
                    cout << "Enter the number you  want to find: ";
                    cin >> num;
                    orderInsertion(vect, comp, inter, duration);
                    comp = 0, inter = 0, duration = 0.0;
                    try{
                        int index = sequentialSearch(vect, num, comp, duration);
                        cout << "The " << num << " is located at: " << index << " index\n";
                    } catch(runtime_error& e){
                        cout << e.what();
                    }
                    break;
                case 8:
                    cout << "\nFind by Binary search\n";
                    cout << "Enter the number you  want to find: ";
                    cin >> num;
                    orderInsertion(vect, comp, inter, duration);
                    comp = 0, inter = 0, duration = 0.0;
                    try{
                        int index = binarySearch(vect, num, comp, duration);
                        cout << "The " << num << " is located at: " << index << " index\n";
                    } catch(runtime_error& e){
                        cout << e.what();
                    }
                    break;
                default:
                    break;
            }
            if(ans != 0){
                printVector(vect, comp, inter, duration);
            }
        } else if(typeAns == 2  && ans != 0){
            vector<double> vect;
            createVectorDouble(vect, n);
            simplePrintVector(vect);
            double num;
            switch (ans){
                case 1:
                    cout << "\nOrdered vector by Exchange\n";
                    orderExchange(vect, comp, inter, duration);
                    break;
                case 2:
                    cout << "\nOrdered vector by Bubble\n";
                    orderBubble(vect, comp, inter, duration);
                    break;
                case 3:
                    cout << "\nOrdered vector by Direct Selection\n";
                    orderSelection(vect, comp, inter, duration);
                    break;
                case 4:
                    cout << "\nOrdered vector by Insertion\n";
                    orderInsertion(vect, comp, inter, duration);
                    break;
                case 5:
                    start = chrono::system_clock::now();
                    cout << "\nOrdered vector by Merge\n";
                    orderMerge(vect, 0, vect.size()-1, comp, inter);
                    stop = chrono::system_clock::now();
                    elapsed_seconds = stop - start;
                    duration = elapsed_seconds.count();
                    break;
                case 6:
                    start = chrono::system_clock::now();
                    cout << "\nOrdered vector by Quick sort\n";
                    orderQuick(vect, 0, vect.size() - 1, comp, inter);
                    stop = chrono::system_clock::now();
                    elapsed_seconds = stop - start;
                    duration = elapsed_seconds.count();
                    break;
                case 7:
                    cout << "\nFind by Sequential search\n";
                    cout << "Enter the number you  want to find: ";
                    cin >> num;
                    orderInsertion(vect, comp, inter, duration);
                    comp = 0, inter = 0, duration = 0.0;
                    try{
                        int index = sequentialSearch(vect, num, comp, duration);
                        cout << "The " << num << " is located at: " << index << " index\n";
                    } catch(runtime_error& e){
                        cout << e.what();
                    }
                    break;
                case 8:
                    cout << "\nFind by Binary search\n";
                    cout << "Enter the number you  want to find: ";
                    cin >> num;
                    orderInsertion(vect, comp, inter, duration);
                    comp = 0, inter = 0, duration = 0.0;
                    try{
                        int index = binarySearch(vect, num, comp, duration);
                        cout << "The " << num << " is located at: " << index << " index\n";
                    } catch(runtime_error& e){
                        cout << e.what();
                    }
                    break;
                default:
                    break;
            }
            if(ans != 0){
                printVector(vect, comp, inter, duration);
            }
        }else if(typeAns == 3  && ans != 0){
            vector<char> vect;
            createVectorChar(vect, n);
            simplePrintVector(vect);
            char charac;
            switch (ans){
                case 1:
                    cout << "\nOrdered vector by Exchange\n";
                    orderExchange(vect, comp, inter, duration);
                    break;
                case 2:
                    cout << "\nOrdered vector by Bubble\n";
                    orderBubble(vect, comp, inter, duration);
                    break;
                case 3:
                    cout << "\nOrdered vector by Direct Selection\n";
                    orderSelection(vect, comp, inter, duration);
                    break;
                case 4:
                    cout << "\nOrdered vector by Insertion\n";
                    orderInsertion(vect, comp, inter, duration);
                    break;
                case 5:
                    start = chrono::system_clock::now();
                    cout << "\nOrdered vector by Merge\n";
                    orderMerge(vect, 0, vect.size()-1, comp, inter);
                    stop = chrono::system_clock::now();
                    elapsed_seconds = stop - start;
                    duration = elapsed_seconds.count();
                    break;
                case 6:
                    start = chrono::system_clock::now();
                    cout << "\nOrdered vector by Quick sort\n";
                    orderQuick(vect, 0, vect.size() - 1, comp, inter);
                    stop = chrono::system_clock::now();
                    elapsed_seconds = stop - start;
                    duration = elapsed_seconds.count();
                    break;
                case 7:
                    cout << "\nFind by Sequential search\n";
                    cout << "Enter the character you  want to find: ";
                    cin >> charac;
                    orderInsertion(vect, comp, inter, duration);
                    comp = 0, inter = 0, duration = 0.0;
                    try{
                        int index = sequentialSearch(vect, charac, comp, duration);
                        cout << "The " << charac << " is located at: " << index << " index\n";
                    } catch(runtime_error& e){
                        cout << e.what();
                    }
                    break;
                case 8:
                    cout << "\nFind by Binary search\n";
                    cout << "Enter the character you  want to find: ";
                    cin >> charac;
                    orderInsertion(vect, comp, inter, duration);
                    comp = 0, inter = 0, duration = 0.0;
                    try{
                        int index = binarySearch(vect, charac, comp, duration);
                        cout << "The " << charac << " is located at: " << index << " index\n";
                    } catch(runtime_error& e){
                        cout << e.what();
                    }
                    break;
                default:
                    break;
            }
            if(ans != 0){
                printVector(vect, comp, inter, duration);
            }
        }else if(typeAns == 4  && ans != 0){
            vector<string> vect;
            createVectorString(vect, n);
            simplePrintVector(vect);
            string word;
            switch (ans){
                case 1:
                    cout << "\nOrdered vector by Exchange\n";
                    orderExchange(vect, comp, inter, duration);
                    break;
                case 2:
                    cout << "\nOrdered vector by Bubble\n";
                    orderBubble(vect, comp, inter, duration);
                    break;
                case 3:
                    cout << "\nOrdered vector by Direct Selection\n";
                    orderSelection(vect, comp, inter, duration);
                    break;
                case 4:
                    cout << "\nOrdered vector by Insertion\n";
                    orderInsertion(vect, comp, inter, duration);
                    break;
                case 5:
                    start = chrono::system_clock::now();
                    cout << "\nOrdered vector by Merge\n";
                    orderMerge(vect, 0, vect.size()-1, comp, inter);
                    stop = chrono::system_clock::now();
                    elapsed_seconds = stop - start;
                    duration = elapsed_seconds.count();
                    break;
                case 6:
                    start = chrono::system_clock::now();
                    cout << "\nOrdered vector by Quick sort\n";
                    orderQuick(vect, 0, vect.size() - 1, comp, inter);
                    stop = chrono::system_clock::now();
                    elapsed_seconds = stop - start;
                    duration = elapsed_seconds.count();
                    break;
                case 7:
                    cout << "\nFind by Sequential search\n";
                    cout << "Enter the letters you  want to find: ";
                    cin >> word;
                    orderInsertion(vect, comp, inter, duration);
                    comp = 0, inter = 0, duration = 0.0;
                    try{
                        int index = sequentialSearch(vect, word, comp, duration);
                        cout << "The " << word << " is located at: " << index << " index\n";
                    } catch(runtime_error& e){
                        cout << e.what();
                    }
                    break;
                case 8:
                    cout << "\nFind by Binary search\n";
                    cout << "Enter the letters you  want to find: ";
                    cin >> word;
                    orderInsertion(vect, comp, inter, duration);
                    comp = 0, inter = 0, duration = 0.0;
                    try{
                        int index = binarySearch(vect, word, comp, duration);
                        cout << "The " << word << " is located at: " << index << " index\n";
                    } catch(runtime_error& e){
                        cout << e.what();
                    }
                    break;
                default:
                    break;
            }
            if(ans != 0){
                printVector(vect, comp, inter, duration);
            }
        } else{
            cout <<  "The program has finished with ease..\n\n\n";
        }
    }

    return 0;
}