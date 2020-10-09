// Act .. - Binary Search Tree Class
// Abraham Cepeda Oseguera
// A00827666
// 5 de octubre 2020
#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree{
    private:
        Node<T> *root;
        int numChilds;
        void printTree(Node<T> *node, int level);
        void numChild(Node<T> *node);
    public:
        BinarySearchTree();

        bool isEmpty(){return root == NULL;};

        void insert(T data);
        void deleteData(T data);
        Node<T>* findNode(T data);
        Node<T> *findPrevNode(T data);

        //void clear();
        void print();
};

// constructor
template<class T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
    numChilds = 0;
}

template<class T>
void BinarySearchTree<T>::numChild(Node<T> *node){
    if(node->left != NULL){
        numChilds++;
        numChild(node->left);
    }
    if(node->right != NULL){
        numChilds++;
        numChild(node->right);
    }
}

// method: insert
template<class T>
void BinarySearchTree<T>::insert(T data){
    if(!isEmpty()){
        Node<T> *aux = root;
        while(aux != NULL){
            if(aux->data > data){
                if(aux->left == NULL){
                    aux->left = new Node<T>(data);
                    return;
                } else{
                    aux = aux->left;
                }
            } else{
                if(aux->right == NULL){
                    aux->right = new Node<T>(data);
                    return;
                } else{
                    aux = aux->right;
                }
            }
        }
    } else{
        root = new Node<T>(data);
    }
}

template<class T>
Node<T>* BinarySearchTree<T>::findNode(T data){
    if(!isEmpty()){
        Node<T> *aux = root;
        while(aux != NULL){
            if(aux->data == data){
                return aux;
            }
            aux->data > data ? aux = aux->left : aux = aux->right;
        }
    }
    throw runtime_error("Error (findNode): node not found..\n");
}

template<class T>
Node<T>* BinarySearchTree<T>::findPrevNode(T data){
    if(!isEmpty()){
        Node<T> *aux = root;
        Node<T> *auxTemp = root;
        while(aux != NULL){
            if(aux->data == data){
                return auxTemp;
            }
            auxTemp = aux;
            aux->data > data ? aux = aux->left : aux = aux->right;
        }
    }
    throw runtime_error("Error (findNode): node not found..\n");
}

//delete
template<class T>
void BinarySearchTree<T>::deleteData(T data){
    Node<T> *aux = findNode(data);
    numChild(aux);
    if(numChilds == 0){
        Node<T> *auxPrev = findPrevNode(data);
        auxPrev->left == aux ? auxPrev->left = NULL : auxPrev->right = NULL;
        delete aux;
    } else if(numChilds == 1){
        Node<T> *auxPrev = findPrevNode(data);
        auxPrev->left == aux ? (aux->left != NULL ? auxPrev->left = aux->left : auxPrev->left = aux->right) : (aux->left != NULL ? auxPrev->right = aux->left : auxPrev->right = aux->right);
        delete aux;
    } else{
        Node<T> *auxTemp = aux;
        if(aux->left != NULL){
            aux = aux->left;
            if(aux->right == NULL){
                auxTemp->data = aux->data;
                auxTemp->left = aux->left;
            } else{
                while(aux->right != NULL){
                    aux = aux->right;
                }
                Node<T> *auxPrev = findPrevNode(aux->data);
                auxTemp->data = aux->data;
                auxPrev->left == aux ? auxPrev->left = NULL : auxPrev->right = NULL;
            }
        } else{
            while(aux->right != NULL){
                aux = aux->right;
            }
            Node<T> *auxPrev = findPrevNode(aux->data);
            auxTemp->data = aux->data;
            auxPrev->left == aux ? auxPrev->left = NULL : auxPrev->right = NULL;
        }
        delete aux;
    }
}

template<class T>
void BinarySearchTree<T>::printTree(Node<T> *node, int level){
    if(node != NULL){
        printTree(node->right, level + 1);
        for(int i = 0; i < level; i ++){
            cout << " ";
        }
        cout << node->data << "\n";
        printTree(node->left, level + 1);
    }
}


template<class T>
void BinarySearchTree<T>::print(){
    int level = 0;
    cout << endl;
    printTree(root, level);
    cout << "\n";
}
