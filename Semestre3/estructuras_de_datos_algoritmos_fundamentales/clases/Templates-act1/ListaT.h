#ifndef  ListaT_h
#define  ListaT_h
#include<iostream>
#include<string>
using namespace std;

const int MAX = 100;

template<class T>
class ListaT{
    private:
        T data [MAX];
        int size;
    public:
        ListaT();

        void insert(T num);
        T erase();
        T getData(int index);
        int getSize(){return size;};
        void print();

};

template<class T>
ListaT<T>::ListaT() {
    size = 0;
}

template<class T>
void ListaT<T>::insert(T num) {
    if (size < MAX) {
        data[size] = num;
        size++;
    } else{
        throw runtime_error("Exceeded MAX..");
    }
}

template<class T>
T ListaT<T>::erase() {
    if (size > 0) {
        size--;
        return data[size];
    } else{
        throw runtime_error("No elements..");
    }
}

template<class T>
T ListaT<T>::getData(int index) {
    if (index >= 0 && index < size) {
        return data[index];
    } else{
        throw runtime_error("Index out of bounds");
    }
}

template<class T>
void ListaT<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]" << " - " << data[i] << '\n';
    }
}
#endif