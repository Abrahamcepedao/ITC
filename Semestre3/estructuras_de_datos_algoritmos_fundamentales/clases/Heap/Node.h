// Act 3.2 - Node Struct
// Abraham Cepeda Oseguera
// A00827666
// 19 de octubre 2020
#pragma once
template<class T>
struct Node{
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(T data);
    Node(T data, Node<T> *next);
    Node(T data, Node<T> *next, Node<T> *prev);
};

template <class T>
Node<T>::Node(T data){
    this->data = data;
    next = NULL;
    prev = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T> *next){
    this->data = data;
    this->next = next;
}

template <class T>
Node<T>::Node(T data, Node<T> *next, Node<T> *prev){
    this->data = data;
    this->next = next;
    this->prev = prev;
}