// MinHeap class
// Abraham Cepeda Oseguera
// A00827666
// 1 de octubre 2020
#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
using namespace std;
template <class T>
class MinHeap{
    private:
        Node<T> *head;
        Node<T> *tail;
        int cIndex; // current index
        int size;
    public:
        MinHeap();
        
        bool isEmpty(){return size == 0;};
        int getSize() { return size; };

        void insert(T data);
        void remove();

        void heapSort();

        Node<T> *operator[](int index);
        Node<T> *getNodeAt(int index);

        void clear();
        void print();
        void printHead();
};

// constructor
template<class T>
MinHeap<T>::MinHeap(){
    head = NULL;
    tail = NULL;
    cIndex = 1;
    size = 0;
}

// methods
template<class T>
void MinHeap<T>::insert(T data){
    if(isEmpty()){
        head = new Node<T>(data);
        tail = head;
        size++;
    } else{
        tail->next = new Node<T>(data);
        tail = tail->next;
        size++;
    }
}


template<class T>
Node<T>* MinHeap<T>::getNodeAt(int index){
    cout << "Getting node at index...\n";
    return this[index];
}



//Method: operator[]
//Description: overloading the operator "[]" for the LinkedList to be used as an array
//Input: index (the index of the needed node)
//Output: the node at the given index || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
Node<T>* MinHeap<T>::operator[](int index){
    if(!isEmpty() && index > 0 && index <= size){
        Node<T> *aux = head;
        int count = 1;
        while(count <= size){
            if(count == index){
                return aux;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Error (operator[]): index out of range or list is empty\n");
}


template<class T>
void MinHeap<T>::printHead(){
    if(!isEmpty()){
        cout <<  "head->data: " <<  head->data << endl;
    }
}

template<class T>
void MinHeap<T>::print(){
    if(isEmpty()){
        throw runtime_error("Error (print): list is empty..\n");
    }
    cout << "Printing minHeap...\n";
    Node<T> *aux = head;
    while(aux != NULL){
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << "\n";
}

