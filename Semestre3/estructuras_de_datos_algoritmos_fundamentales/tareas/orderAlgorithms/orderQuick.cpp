// This algorithm sort a  vector with the Quick sort method
// Abraham Cepeda Oseguera
// A00827666
// August 17th 2020
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

template<class T>
void exchange(vector<T> &vect, int num1, int num2){
    int num = vect[num1];
    vect[num1] = vect[num2];
    vect[num2] = num;
}

template<class T>
int separate(vector<T> &vect, int begin, int end){
    int pos = begin+1, r = end;
    while(pos < r){
        while(vect[pos] < vect[begin] && pos != end){
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

template<class T>
void orderQuick(vector<T> &vect, int l, int r){
    int pos;
    if(l < r){
        pos = separate(vect, l, r);
        orderQuick(vect, l, pos-1);
        orderQuick(vect, pos+1, r);
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
    orderQuick(numbers, 0, (n-1));
    simplePrintVector(numbers);
    return 0;
}