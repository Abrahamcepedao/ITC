// Act 2.2.2 - Queue class
// Abraham Cepeda Oseguera
// A00827666
// 1 de octubre 2020
#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
template <class T>

class DLinkedList{
    private:
        Node<T> *head;
        Node<T> *tail;
        int size;
    public:
        DLinkedList();
        
        bool isEmpty(){return size == 0;};
        int getSize() { return size; };

        void enqueue(T data);
        T dequeue();

        T front();
        T back();

        

        void clear();
        void print();
};

// constructor
template<class T>
DLinkedList<T>::DLinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}


