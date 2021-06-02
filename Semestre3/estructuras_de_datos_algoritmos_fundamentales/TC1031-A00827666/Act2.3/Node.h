// Act 2.3 - Node Struct
// Abraham Cepeda Oseguera
// A00827666
// 1 de octubre 2020
#pragma once
template<class T>
struct Node{
    T data;
    Node<T> *prev;
    Node<T> *next;
    Node(T data);
    Node(T data, Node<T> *prev, Node<T> *next);
};

template <class T>
Node<T>::Node(T data){
    this->data = data;
    prev = NULL;
    next = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T> *prev, Node<T> *next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}
