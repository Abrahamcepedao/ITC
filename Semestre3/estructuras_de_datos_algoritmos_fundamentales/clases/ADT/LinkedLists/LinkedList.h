#pragma once
#include "Node.h"
template<class T>
class LinkedList{
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList();
        void addFirst(T data);
        void addLast(T data);
        bool deleteData(T data);
        bool deleteAt(int index);
        T getData(int index);
        bool updateAt(int index, T newData);
        bool updateData(T data, T newData);
        void operator[](int index);
        void print();
        bool isEmpty(){return size == 0;};
};

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}

template<class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}

template<class T>
void LinkedList<T>::addLast(T data){
    if(isEmpty()){
        head = new Node<T>(data);
    } else{
        Node<T> *aux = head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
        
    }
    size++;
}

template<class T>
bool LinkedList<T>::deleteData(T data){
    if(!isEmpty()){
        Node<T> *aux = head;
        if(aux->data == data){
            head = aux->next;
            size--;
            return true;
        }
        Node<T> *auxF = head;
        int count = 0;
        while(count < size){
            if(aux->data == data){
                auxF->next = aux->next;
                delete aux;
                size--;
                return true;
            }
            count++;
            auxF = aux;
            aux = aux->next;
        }
    }
    return false;
}

template<class T>
void LinkedList<T>::print(){
    Node<T> *aux = head;
    if(size > 0){
        for(int i = 0; i < size; i++){
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "La lista esta vacía..";
    }
    cout << "\n";
}