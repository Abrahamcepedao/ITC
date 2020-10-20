//  Act 3.2 MaxHeap class
// Abraham Cepeda Oseguera
// A00827666
// 19 de octubre 2020
#pragma once
#include "DLinkedList.h"
#include <vector>
#include <iostream>
using namespace std;
template <class T>
class MaxHeap{
    private:
        DLinkedList<T> dList;
        int size;
    public:
        MaxHeap();
        MaxHeap(DLinkedList<T> list);
        
        bool isEmpty(){return size == 0;};
        int getSize() { return size; };

        void insert(T data);
        void remove();
        
        Node<T> *operator[](int index);
        void operator=(DLinkedList<T> list);
        Node<T> *getNodeAt(int index);

        void swap(int i1, int i2);
        void heapifyUp(int index);
        void heapifyDown(int index);

        void clear();
        void print();
};

// default constructor
template<class T>
MaxHeap<T>::MaxHeap(){
    size = 0;
}

//constructor from a Double Linked List
template<class T>
MaxHeap<T>::MaxHeap(DLinkedList<T> list){
    if(list.isEmpty()){
        throw runtime_error("Error (heapConstructor): DlinkedList is empty..\n");
    }
    Node<T> *aux = list[1];
    size = 0;
    while(aux != NULL){
        insert(aux->data);
        aux = aux->next;
    }
}

// Method: insert
// Description: inserts elements at end of the list and rearranges it if necessary
// Input: data (data of  the new element)
// Output: NA
// Complexity: O(n)
template<class T>
void MaxHeap<T>::insert(T data){
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

// Method: remove
// Description: removes the first element of the list
// Input: NA
// Output: NA
// Complexity: O(n)
template<class T>
void MaxHeap<T>::remove(){
    if(isEmpty()){
        throw runtime_error("Error (remove): list is empty..\n");
    }
    if(size == 1){
        dList.clear();
        size--;
    } else{
        dList[1]->data = dList[size]->data;
        size--;
        dList[size]->next = NULL;
        heapifyDown(1);
    }
    dList.setSize(size);
}

// Method: swap
// Description: interchanges the values of to elements
// Input: i1 (index of first element), i2 (index  of  second element)
// Output: NA
// Complexity: O(1)
template<class T>
void MaxHeap<T>::swap(int i1, int i2){
    Node<T> *aux = dList[i1];
    Node<T> *aux2 = dList[i2];
    T temp = aux->data;
    aux->data = aux2->data;
    aux2->data = temp;
}


//Method: operator[]
//Description: overloading the operator "[]" for the heap to be used as an array
//Input: index (the index of the needed node)
//Output: the node at the given index || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
Node<T>* MaxHeap<T>::operator[](int index){
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
    throw runtime_error("Error (operator[] maxheap): index out of range or list is empty\n");
}

//Method: operator=
//Description: overloading the operator "=" to initialize a heap from a Double Linked List
//Input: list (a Double Linked List)
//Output: NA
//Complexity: O(n)
template<class T>
void MaxHeap<T>::operator=(DLinkedList<T> list){
    if(list.isEmpty()){
        throw runtime_error("Error (heapConstructor): DlinkedList is empty..\n");
    }
    Node<T> *aux = list[1];
    while(aux != NULL){
        insert(aux->data);
        aux = aux->next;
    }
}

// Method: heapifyUp
// Description: swaps the recently add element with its parent elements while they are greater
// Input: i1 (index of element to be swapped if necessary)
// Output: NA
// Complexity: O(n)
template<class T>
void MaxHeap<T>::heapifyUp(int i1){
    if(i1 == 1){
        return;
    }
    int i2 = i1 / 2;
    Node<T> *aux = dList[i1];
    Node<T> *aux2 = dList[i2];
    if(aux->data > aux2->data){
        cout << "swapping hU " << i1 << " and " << i2 << endl;
        swap(i1, i2);
    }
    heapifyUp(i2);
}

// Method: heapifyDown
// Description: Swaps the parent element with the smallest of it's children elements
// Input: i1 (index of element to be swapped if necessary)
// Output: NA
// Complexity: O(n)
template<class T>
void MaxHeap<T>::heapifyDown(int i1){
    if(i1 * 2 > size){
        return;
    }
    int i2 = i1 * 2;
    Node<T> *aux = dList[i1];
    Node<T> *aux2 = dList[i2];
    if((i1 * 2 + 1) > size){
        if(aux2->data > aux->data){
            swap(i1, i2);
        }
        return;
    }
    int i3 = i2 + 1;
    Node<T> *aux3 = dList[i3];
    if(aux2->data > aux3->data){
        if(aux2->data > aux->data){
            swap(i1, i2);
        }
        heapifyDown(i2);
    } else{
        if(aux3->data > aux->data){
            swap(i1, i3);
        }
        heapifyDown(i3);
    }
}

// Method: print
// Description: prints the entire heap if it is not empty
// Input: NA
// Output: Entire list
// Complexity: O(n)
template<class T>
void MaxHeap<T>::print(){
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

