// This program contains different algorithms for sorting a vector
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

template<class T>
void exchange(vector<T> &vect, int num1, int num2){
    int num = vect[num1];
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
    T min;
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
void merge(vector<T> &vect, int l, int m, int r){
    int i = 0, j = 0, count = l;
    vector<T> vect1, vect2;
    for(int e = l; e <= m; e++){
        vect1.push_back(vect[e]);
    }
    for(int k = m+1; k <= r; k++){
        vect2.push_back(vect[k]);
    }
    while(i < (m-l+1) && j < (r-m)){
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
        vect[count] = vect1[i];
        count++;
        i++;
    }
    while(j < (r-m)){
        vect[count] = vect2[j];
        count++;
        j++;
    }
} 

template<class T>
void orderMerge(vector<T> &vect, int l, int r){
    if(l < r){
        int m = l + (r-l) / 2;
        orderMerge(vect, l, m);
        orderMerge(vect, m+1, r);
        merge(vect, l, m, r);
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
void createVector(vector<T> &vect, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        vect.push_back(rand() % n + 1);
    }
}

int menu(){
    int ans;
    cout << "\n\n\n\n1. Order by Exchange\n";
    cout << "2. Order by Bubble\n";
    cout << "3. Order by Selection\n";
    cout << "4. Order by Insertion\n";
    cout << "5. Order by Merge\n";
    cout << "6. Sequential search\n";
    cout << "7. Binary search\n";
    cout << "0. To exit\n\n";
    cout << "Enter answer: ";
    cin >> ans;
    return ans;
}

int main(){
    int n, ans = 1;
    cout << "Enter the number of values: ";
    cin >> n;

    while(ans != 0){
        vector<int> vect;
        ans = menu();
        createVector(vect, n);
        simplePrintVector(vect);
        int comp = 0, inter = 0, num;
        double duration;

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
                cout << "\nOrdered vector by Merge\n";
                orderMerge(vect, 0, vect.size()-1);
                break;
            case 6:
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
            case 7:
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
            default:
                break;
        }

        if(ans != 0){
            printVector(vect, comp, inter, duration);
        } else{
            cout << "The program has finished\n";
        }
    }

    return 0;
}