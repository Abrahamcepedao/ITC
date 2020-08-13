#ifndef  Lista_h
#define  Lista_h
#include<iostream>
#include<string>
using namespace std;

const int MAX = 100;

class Lista{
    private:
        int data [MAX];
        int size;
    public:
        Lista();

        void insert(int num);
        void erase();
        int getData(int index);
        int getSize(){return size;};
        void print();

};

Lista::Lista(){
    data [MAX];
    size = 0;
}

void Lista::insert(int num){
    if(size < MAX){
        data[size] = num;
        size++;
    } else{
        throw runtime_error("Exceded array");
    }
}

void Lista::erase(){
    if(size > 0){
        cout << "last num: " << data[size-1] << endl;
        size--;
    } else{
        cout << "No elements.." << endl;
    }
    (size > 0)
}

int Lista::getData(int index){
    return ((index >= 0 && index < size) ? data[index]: 0);
}

void Lista::print(){
    for(int i = 0; i < size; i++){
        cout << "[" << i << "]" << " - " << data[i] << endl;
    }
}

#endif