// Act 5.1 - Node Struct
// Abraham Cepeda Oseguera
// A00827666
// 30 de noviembre 2020
#pragma once
template<class T>
struct Node{
    T data;
    Node<T> *next;
    Node(T data);
    Node(T data, Node<T> *next);
};

template <class T>
Node<T>::Node(T data){
    this->data = data;
    next = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T> *next){
    this->data = data;
    this->next = next;
}