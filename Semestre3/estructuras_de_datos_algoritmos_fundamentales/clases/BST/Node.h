// Act 2.3 - Node Struct
// Abraham Cepeda Oseguera
// A00827666
// 1 de octubre 2020
#pragma once
template<class T>
struct Node{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T data);
    Node(T data, Node<T> *left, Node<T> *right);
};

template <class T>
Node<T>::Node(T data){
    this->data = data;
    left = NULL;
    right = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T> *left, Node<T> *right){
    this->data = data;
    this->left = left;
    this->right = right;
}
