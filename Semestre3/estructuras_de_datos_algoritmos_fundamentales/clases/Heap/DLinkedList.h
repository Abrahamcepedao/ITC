// Act 2.3 - DoubleLinkedClass class
// Abraham Cepeda Oseguera
// A00827666
// 7 de octubre 2020
#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
using namespace std;
template<class T>
class DLinkedList{
    private:
        Node<T> *head;
        Node<T> *tail;
        int size;
    public:
        DLinkedList();
        
        bool isEmpty(){return size == 0;};
        int getSize() { return size; };
        void setSize(int size){this->size = size;};

        Node<T>* getData(int index);
        void addBack(T data);


        Node<T>* operator[](int index);
        void operator=(vector<T> list);

        void clear();
        void print();
        void printReverse(int n, int m);
};

// constructor
template<class T>
DLinkedList<T>::DLinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

//Method: operator=
//Description: overloading the operator "=" to assing a linked list a set of values. It also keeps the values that the list may already have
//Input: list[] (an array of elements to be add to the linked list)
//Output: a linked list with the given set of elements || runtime error the array is empty
//Complexity: O(n)
template<class T>
void DLinkedList<T>::operator=(vector<T> list){
    if(sizeof(list) != 0){
        for (T listItem : list){
            this->addBack(listItem);
        }
    } else{
        throw runtime_error("Error: enter a non empty list\n");
    }
}

//Method: operator[]
//Description: overloading the operator "[]" for the LinkedList to be used as an array
//Input: index (the index of the needed node)
//Output: the node at the given index || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
Node<T>* DLinkedList<T>::operator[](int index){
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

//Method: getData
//Description: gets data from a given index
//Input: index (the index from which the data will be retrieved)
//Output: data (the data at that index) || Error if index does not exists
//Complexity: O(n)
template<class T>
Node<T>* DLinkedList<T>::getData(int index){
    if(!isEmpty() && index > 0 && index <= size){
        int count = 1;
        Node<T> *aux = head;
        while(count <= size){
            if(count == index){
                return aux;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Error (getData): index out of range or list is empty\n");
}



//Method: addBack
//Description: adds a node and makes it the tail of the DLinkedList
//Input: data (the data that the tail will have)
//Output: the new list with it's new tail node
//Complexity: O(1)
template<class T>
void DLinkedList<T>::addBack(T data){
    if(!isEmpty()){
        tail->next = new Node<T>(data);
        tail= tail->next;
    } else{
        head = new Node<T>(data);
        tail = head;
    }
    size++;
}




//Method: print
//Description: prints the elements of the doubled linked list
//Input: NA
//Output: The elements of the doubled linked list || message if the list is empty
//Complexity: O(n)
template<class T>
void DLinkedList<T>::print(){
    if(!isEmpty()){
        Node<T> *aux = head;
        while(aux != NULL){
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "The linked list is empty..";
    }
    cout << "\n";
}

//Method: clear
//Description: removes all the elements of  the  
//Input: NA
//Output: The elements of the doubled linked list || message if the list is empty
//Complexity: O(n)
template<class T>
void DLinkedList<T>::clear() {
    Node<T> *aux = head;
    while (head->next != NULL) {
        Node<T> *aux = head;
        head = aux->next;
        delete aux;
    }
    size = 0;
    tail = NULL;
    head = NULL;
}