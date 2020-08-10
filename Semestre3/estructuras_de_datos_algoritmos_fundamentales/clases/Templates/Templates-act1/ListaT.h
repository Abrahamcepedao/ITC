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
        T erase();
        T getData(int index);
        int getSize(){return size;};
        void print();

};

template<class T>
Lista<T>::Lista(){
    size = 0;
}

template<class T>
void Lista<T>::insert(T num) {
    if(size < MAX){
        data[size] = num;
        size++;
    } else{
        throw runtime_error("Exceeded array");
    }
}

template<class T>
T Lista<T>::erase() {
    if(size > 0){
        return data[size-1];
        size--;
    } else{
        throw runtime_error("No elements..");
    }
}

template<class T>
T Lista<T>::getData(int index){
    if(index >= 0 && index < size){
        return data[index];
    } else{
        throw runtime_error("Index out of bounds");
    }
}

template<class T>
void Lista<T>::print() {
    for(int i = 0; i < size; i++){
        cout << "[" << i << "]" << " - " << data[i] << endl;
    }
}
#endif