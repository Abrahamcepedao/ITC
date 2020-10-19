// Act 2.1.1 - Node Struct
// Abraham Cepeda Oseguera
// A00827666
// 26 de septiembre 2020
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

/* class Node{
    private:
        T data;
        Node<T> *next;
    public:
        Node();
        Node(T data);
        Node(T data, Node<T> *next);

        //set Data
        void setData(T data){this->data = data;};
        void setNext(Node<T> *next){this->next = *next;};
        //get Data
        T getData(){return data;};
        Node<T>* getNext(){return *next;};
        
        //push
        //insert
        //apend
};

template <class T>
Node<T>::Node(){

}


template <class T>
Node<T>::Node(T data){
    this->data = data;
    next = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T> *next){
    this->data = data;
    this->next = next;
}
 */
