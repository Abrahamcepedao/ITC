// Act 2.2.1 - Stack class
// Abraham Cepeda Oseguera
// A00827666
// 1 de octubre 2020
#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
template <class T>

class Stack{
    private:
        Node<T> *top;
        int size;
    public:
        Stack();
        
        bool isEmpty(){return size == 0;};
        int getSize(){return size;};

        void push(T data);
        T pop();
        T getTop();

        void clear();
        void print();
        void deleteTop();
};

//default constructor
template<class T>
Stack<T>::Stack(){
    top = NULL;
    size = 0;
}

//Method: push
//Description: Adds element as the new top
//Input: data (the data of the new top)
//Output: NA
//Complexity: O(1)
template<class T>
void Stack<T>::push(T data){
    if(!isEmpty()){
        top = new Node<T>(data, top);
        size++;
    } else{
        top = new Node<T>(data);
        size++;
    }
}

//Method: pop
//Description: Gets the data of the top element at deletes it
//Input: NA
//Output: The top elements and deletes it || "the stack is empty" if there are no elements
//Complexity: O(1)
template<class T>
T Stack<T>::pop(){
    if(!isEmpty()){
        Node<T> *aux = top;
        T data = aux->data;
        top = top->next;
        delete aux;
        size--;
        return data;
    }
    throw runtime_error("Error: the stack is empty..\n");
}

//Method: getTop
//Description: get the data of the top element
//Input: NA
//Output: Data of top element || "the stack is empty" if there are no elements
//Complexity: O(1)
template<class T>
T Stack<T>::getTop(){
    if(!isEmpty()){
        return top->data;
    }
    throw runtime_error("Error: the stack is empty..\n");
}

//Method: deleteTop
//Description: Deleted the top element
//Input: NA
//Output: NA (simply deleted the element if it exists)
//Complexity: O(1)
template<class T>
void Stack<T>::deleteTop(){
    if(size > 1){
        Node<T> *aux = top;
        top = top->next;
        delete aux;
        size--;
    } else if(size == 1){
        top = NULL;
        size--;
    }
}

//Method: clear
//Description: Deletes all the elements of the stack
//Input: NA
//Output: Succes message if elements deleted successfuly || error message if the stack is empty
//Complexity: O(n)
template<class T>
void Stack<T>::clear(){
    if(!isEmpty()){
        Node<T> *aux = top;
        while(aux != NULL){
            deleteTop();
            aux = aux->next;
        }
        deleteTop();
        cout << "Succes: elements deleted..\n";
    } else{
        cout << "There are no elements to delete..\n";
    }
}

//Method: print
//Description: prints all the elements of the stack
//Input: NA
//Output: All the elements || "the stack is empty" if there are no elements
//Complexity: O(n)
template<class T>
void Stack<T>::print(){
    if(!isEmpty()){
        Node<T> *aux = top;
        while(aux != NULL){
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "The stack is empty..";
    }
    cout << "\n";
}