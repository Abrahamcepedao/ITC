// Act 2.2.2 - Queue class
// Abraham Cepeda Oseguera
// A00827666
// 1 de octubre 2020
#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
template <class T>

class Queue{
    private:
        Node<T> *head;
        Node<T> *tail;
        int size;
    public:
        Queue();
        
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
Queue<T>::Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}


//Method: eenqueue
//Description: Adds element as the tail
//Input: data (the data of the new tail)
//Output: NA
//Complexity: O(1)
template<class T>
void Queue<T>::enqueue(T data){
    if(!isEmpty()){
        tail->next = new Node<T>(data);
        tail = tail->next;
        size++;
    } else{
        head = new Node<T>(data);
        tail = head;
        size++;
    }
}

//Method: dequeue
//Description: Get data of the head and deletes it
//Input: NA
//Output: Data of the head and deletes it
//Complexity: O(1)
template<class T>
T Queue<T>::dequeue(){
   if(!isEmpty()){
        Node<T> *aux = head;
        T data = aux->data;
        head = head->next;
        delete aux;
        size--;
        return data;
    }
    throw runtime_error("Error: the queue is empty..\n");
}

//Method: front
//Description: get the data of the head element
//Input: NA
//Output: Data of head element || "the queue is empty" if there are no elements
//Complexity: O(1)
template<class T>
T Queue<T>::front(){
    if(!isEmpty()){
        return head->data;
    }
    throw runtime_error("Error: the queue is empty..\n");
}

//Method: back
//Description: get the data of the tail element
//Input: NA
//Output: Data of tail element || "the queue is empty" if there are no elements
//Complexity: O(1)
template<class T>
T Queue<T>::back(){
    if(!isEmpty()){
        return tail->data;
    }
    throw runtime_error("Error: the queue is empty..\n");
}

//Method: clear
//Description: clears all the elements of the queue
//Input: NA
//Output: Succes message if elements deleted successfuly || error message if the stack is empty
//Complexity: O(n)
template<class T>
void Queue<T>::clear(){
    if(!isEmpty()){
        while(size > 0){
            if(size > 1){
                Node<T> *aux = head;
                head = head->next;
                delete aux;
                size--;
            } else{
                head = tail = NULL ;
                size--;
            }
        }
        cout << "Succes: elements deleted..\n";
    } else{
        cout << "There are no elements to delete..\n";
    }
}

//Method: print
//Description: prints all the elements of the queue
//Input: NA
//Output: All the elements || "the queue is empty" if there are no elements
//Complexity: O(n)
template<class T>
void Queue<T>::print(){
    if(!isEmpty()){
        Node<T> *aux = head;
        while(aux != NULL){
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "The queue is empty..";
    }
    cout << "\n";
}
