// Act .. - Binary Search Tree Class
// Abraham Cepeda Oseguera
// A00827666
// 5 de octubre 2020
#pragma once
#include "Node.h"
#include "Queue.h"
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree{
    private:
        Node<T> *root;
        int numChilds;
        int treeHeight;
        void printTree(Node<T> *node, int level);
        Node<T> *findRoot();
        void height(Node<T> *node);
        void numChild(Node<T> *node);
        void preorder(Node<T> *node);
        void inorder(Node<T> *node);
        void postorder(Node<T> *node);
        void levelByLevel();
    public:
        BinarySearchTree();

        bool isEmpty(){return root == NULL;};

        // Manage data
        void insert(T data);
        void deleteData(T data);

        // Find data
        bool find(T data);
        Node<T>* findNode(T data);
        Node<T> *findPrevNode(T data);
        
        
        // Get levels and height
        int whatlevelamI(T data);
        int getHeight();
        void setHeight(int height){treeHeight = height;};

        // Misc
        void print();
        void ancestors(T data); 
        void visit(int type);
};

// constructor
template<class T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
    numChilds = 0;
    treeHeight = 0;
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
bool BinarySearchTree<T>::find(T data){
    if(!isEmpty()){
        Node<T> *aux = root;
        while(aux != NULL){
            if(aux->data == data){
                return true;
            }
            aux = aux->data > data ? aux->left : aux->right;
        }
    }
    return false;
}


template<class T>
Node<T>* BinarySearchTree<T>::findNode(T data){
    if(!isEmpty()){
        Node<T> *aux = root;
        while(aux != NULL){
            if(aux->data == data){
                return aux;
            }
            aux = aux->data > data ? aux->left : aux->right;
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
            aux = aux->data > data ? aux->left : aux->right;
        }
    }
    throw runtime_error("Error (findNode): node not found..\n");
}


//delete
template<class T>
void BinarySearchTree<T>::deleteData(T data){
    if(isEmpty()){
        throw runtime_error("Error (deleteData): list is empty..\n");
    }
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
                auxTemp = aux;
                auxPrev->left == aux ? auxPrev->left = NULL : auxPrev->right = NULL;
            }
        } else{
            while(aux->right != NULL){
                aux = aux->right;
            }
            Node<T> *auxPrev = findPrevNode(aux->data);
            //auxTemp->data = aux->data;
            auxTemp = aux;
            auxPrev->left == aux ? auxPrev->left = NULL : auxPrev->right = NULL;
        }
        delete aux;
    }
}


template<class T>
Node<T>* BinarySearchTree<T>::findRoot(){
    if(isEmpty()){
        throw runtime_error("Error (height): list is empty..\n");
    }
    return root;
}

template<class T>
int BinarySearchTree<T>::whatlevelamI(T data){
    if(!isEmpty()){
        Node<T> *aux = root;
        int count = 0;
        while(aux != NULL){
            if(aux->data == data){
                return count;
            }
            count++;
            aux->data > data ? aux = aux->left : aux = aux->right;
        }
    }
    throw runtime_error("Error (findNode): node not found..\n");
}

template<class T>
int BinarySearchTree<T>::getHeight(){
    height(findRoot());
    return treeHeight;
}

template<class T>
void BinarySearchTree<T>::height(Node<T> *node){
    if(isEmpty()){
        throw runtime_error("Error (height): bts is empty..\n");
    }
    if(node->left != NULL){
        height(node->left);
    }
    if(node->right != NULL){
        height(node->right);
    }
    int number = whatlevelamI(node->data);
    treeHeight = number > treeHeight ? number + 1 :  treeHeight;
    setHeight(treeHeight);
}

template<class T>
void BinarySearchTree<T>::preorder(Node<T> *node){
    cout << node->data << " ";
    node->left != NULL ? preorder(node->left) : void();
    node->right != NULL ? preorder(node->right): void();
}

template<class T>
void BinarySearchTree<T>::inorder(Node<T> *node){
    node->left != NULL ? inorder(node->left) : void();
    cout << node->data << " ";
    node->right != NULL ? inorder(node->right): void();
}

template<class T>
void BinarySearchTree<T>::postorder(Node<T> *node){
    node->left != NULL ? postorder(node->left) : void();
    node->right != NULL ? postorder(node->right) : void();
    cout << node->data << " ";
}

template<class T>
void BinarySearchTree<T>::levelByLevel(){
    if(isEmpty()){
        throw runtime_error("Error: (levelBylevel): bts is empty..");
    }
    Queue<Node<T>*> queue;
    queue.enqueue(root);
    while(!queue.isEmpty()){
        Node<T> *aux = queue.dequeue();
        cout << aux->data << " ";
        aux->left != NULL ? queue.enqueue(aux->left) : void();
        aux->right != NULL ? queue.enqueue(aux->right) : void();
    }
    /* Node<T> *aux = node;
    int count = 0;
    if(node->left != NULL){
        cout << "  -" << node->left->data << "-  ";
    }
    if(node->right != NULL){
        cout << "  -" << node->right->data << "-  ";
    }

    int max = pow(2, level - 1);
    if(index == max){
        cout << "Index max: \n";
        while(count < (level - 1)){
            aux = findPrevNode(aux->data);
            count++;
        }
        count = 0;
        while(count < level){
            aux = aux->left != NULL ? aux->left : aux->right != NULL ? aux->right : NULL;
            count++;
        }
        levelByLevel(aux, 1, level + 1, 1);
        return;
    } else if(num == 1){
        cout << "Going right: ";
        aux = findPrevNode(node->data);
        if(aux->right != NULL){
            if(aux->right->data != node->data){
                levelByLevel(aux->right, 0, level, index + 1) : void();
            }
            return;
        }
        index++;
    }
    cout << "Going left: ";
    aux = findPrevNode(node->data);
    while(count < (level-2)){
        aux =  findPrevNode(aux->data);
        count++;
    }
    if(aux->right != NULL){
        aux = aux->right;
    }
    count = 0;
    while(count < (level-2)){
        aux = aux->left;
        count++;
    }
    levelByLevel(aux, 1, level, index + 1);
    return;*/
}

template<class T>
void BinarySearchTree<T>::visit(int type){
    if(isEmpty()){
        throw runtime_error("Error (preorder): list is empty..\n");
    }
    switch(type){
        case 1:
            cout << "preorder: ";
            preorder(root);
            break;
        case 2:
            cout << "inorder: ";
            inorder(root);
            break;
        case 3:
            cout << "postorder: ";
            postorder(root);
            break;
        case 4:
            cout << "Level by level: ";
            levelByLevel();
            break;
        default:
            break;
    }
    cout << "\n";
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
    if(isEmpty()){
        throw runtime_error("Error (print): tree is empty..\n");
    }
    int level = 0;
    cout << endl;
    printTree(root, level);
    cout << "\n";
}


// Ancestors
template<class T>
void BinarySearchTree<T>::ancestors(T data){
    if(isEmpty()){
        throw runtime_error("Error: (ancestors): tree is empty..\n");
    }
    BinarySearchTree<T> tempBts;
    Node<T> *aux = root;
    while(aux->data != data){
        tempBts.insert(aux->data);
        aux = aux->data > data ? aux->left : aux->right;
    }
    tempBts.print();
}
