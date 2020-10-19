// MinHeap class
// Abraham Cepeda Oseguera
// A00827666
// 1 de octubre 2020
#pragma once
#include "DLinkedList.h"
#include <vector>
#include <iostream>
using namespace std;
template <class T>
class MinHeap{
    private:
        DLinkedList<T> dList;
        int size;
    public:
        MinHeap();
        MinHeap(DLinkedList<T> list);
        
        bool isEmpty(){return size == 0;};
        int getSize() { return size; };

        void insert(T data);
        void remove();

        void heapSort();

        Node<T> *operator[](int index);
        void operator=(DLinkedList<T> list);
        Node<T> *getNodeAt(int index);

        void swap(int i1, int i2);
        void heapifyUp(int index);
        void heapifyDown(int index);

        void clear();
        void print();
        void printHead();
};

// constructor
template<class T>
MinHeap<T>::MinHeap(){
    size = 0;
}

template<class T>
MinHeap<T>::MinHeap(DLinkedList<T> list){
    if(list.isEmpty()){
        throw runtime_error("Error (heapConstructor): DlinkedList is empty..\n");
    }
    Node<T> *aux = list[1];
    while(aux != NULL){
        insert(aux->data);
        aux = aux->next;
    }
}

// methods
template<class T>
void MinHeap<T>::insert(T data){
    if(isEmpty()){
        dList.addBack(data);
        size++;
    } else{
        dList.addBack(data);
        size++;
        heapifyUp(size);
    }
    dList.setSize(size);
}

template<class T>
void MinHeap<T>::remove(){
    if(isEmpty()){
        throw runtime_error("Error (remove): list is empty..\n");
    }
    if(size == 1){
        dList.clear();
        size--;
        cout << "list should be empty.. size: " << size << endl;
    } else{
        dList[1]->data = dList[size]->data;
        size--;
        //dList[size] = getNodeAt(size);
        dList[size]->next = NULL;
        heapifyDown(1);
    }
    dList.setSize(size);
}


template<class T>
void MinHeap<T>::swap(int i1, int i2){
    Node<T> *aux = dList[i1];
    Node<T> *aux2 = dList[i2];
    T temp = aux->data;
    aux->data = aux2->data;
    aux2->data = temp;
}


template<class T>
Node<T>* MinHeap<T>::getNodeAt(int index){
    if(!isEmpty() && index > 0 && index <= size){
        Node<T> *aux = dList[1];
        int count = 1;
        while(count <= size){
            if(count == index){
                return aux;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Error (getNodeAt): index out of range or list is empty\n");
}



//Method: operator[]
//Description: overloading the operator "[]" for the LinkedList to be used as an array
//Input: index (the index of the needed node)
//Output: the node at the given index || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
Node<T>* MinHeap<T>::operator[](int index){
    if(!isEmpty() && index > 0 && index <= size){
        Node<T> *aux = dList[1];
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

//Method: operator[]
//Description: overloading the operator "[]" for the LinkedList to be used as an array
//Input: index (the index of the needed node)
//Output: the node at the given index || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
void MinHeap<T>::operator=(DLinkedList<T> list){
    if(list.isEmpty()){
        throw runtime_error("Error (heapConstructor): DlinkedList is empty..\n");
    }
    Node<T> *aux = list[1];
    while(aux != NULL){
        insert(aux->data);
        aux = aux->next;
    }
}

template<class T>
void MinHeap<T>::heapSort(){
    while(size > 0){
        cout << dList[1]->data << " ";
        remove();
    }
    cout << "\n";
}


template<class T>
void MinHeap<T>::heapifyUp(int i1){
    if(i1 == 1){
        return;
    }
    int i2 = i1 / 2;
    Node<T> *aux = dList[i1];
    Node<T> *aux2 = dList[i2];
    if(aux->data < aux2->data){
        swap(i1, i2);
    }
    heapifyUp(i2);
}

template<class T>
void MinHeap<T>::heapifyDown(int i1){
    if(i1 * 2 > size){
        return;
    }
    int i2 = i1 * 2;
    Node<T> *aux = dList[i1];
    Node<T> *aux2 = dList[i2];
    if((i1 * 2 + 1) > size){
        if(aux2->data < aux->data){
            swap(i1, i2);
        }
        return;
    }
    int i3 = i2 + 1;
    Node<T> *aux3 = dList[i3];
    if(aux2->data < aux3->data){
        if(aux2->data < aux->data){
            swap(i1, i2);
        }
        heapifyDown(i2);
    } else{
        if(aux3->data < aux->data){
            swap(i1, i3);
        }
        heapifyDown(i3);
    }
}

template<class T>
void MinHeap<T>::printHead(){
    if(!isEmpty()){
        cout <<  "head->data: " <<  dList[1]->data << endl;
    }
}

template<class T>
void MinHeap<T>::print(){
    if(isEmpty()){
        throw runtime_error("Error (print): list is empty..\n");
    }
    Node<T> *aux = dList[1];
    while(aux != NULL){
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << "\n";
}

