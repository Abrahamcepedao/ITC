#ifndef  ListaT_h
#define  ListaT_h
#include<iostream>
#include<string>
using namespace std;

const int MAX = 100;

template<class T>
class Lista{
    private:
        T data [MAX];
        int size;
    public:
        Lista();

        void insert(T num);
        void erase();
        int getData(int index);
        int getSize(){return size;};
        void print();

};

Lista::Lista(){
    size = 0;
}

void Lista::insert(int num){
    if(size < MAX){
        data[size] = num;
        size++;
    }
}

void Lista::erase(){
    if(size > 0){
        cout << "last num: " << data[size-1] << endl;
        size--;
    } else{
        cout << "No elements.." << endl;
    }
}
template<class T>
T Lista::getData(int index){
    if(index >= 0 && index < size){
        return data[index];
    } else{
        return 0;
    }
}

void Lista::print(){
    for(int i = 0; i < size; i++){
        cout << "[" << i << "]" << " - " << data[i] << endl;
    }
}

#endif