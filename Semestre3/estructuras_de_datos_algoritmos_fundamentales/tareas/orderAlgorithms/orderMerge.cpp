// This algorithm sort a  vector with the Merge method
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

template<class T>
void merge(vector<T> &vect, int l, int m, int r){
    // there must  be condition
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

// Function to print the vector O(n)
template<class T>
void simplePrintVector(vector<T> vect){
    for(int i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << "\n";
}

template<class T>
void createVector(vector<T> &vect, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        vect.push_back(rand() % n + 1);
    }
}

int main(){
    int n;
    cout << "Enter the n value: ";
    cin >> n;
    vector<int> numbers;
    createVector(numbers, n);
    simplePrintVector(numbers);
    orderMerge(numbers, 0, (n-1));
    simplePrintVector(numbers);
    return 0;
}