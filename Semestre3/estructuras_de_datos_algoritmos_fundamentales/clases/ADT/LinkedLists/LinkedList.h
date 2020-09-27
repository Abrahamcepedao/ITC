// Act 2.1.1 - Linked List class
// Abraham Cepeda Oseguera
// A00827666
// 26 de septiembre 2020
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

        Node<T> *operator[](int index); // listo
        LinkedList<T> operator=(T list[]);

        void print();
        bool isEmpty(){return size == 0;};
        
        int getSize(){return size;};
        int findData(T data);
};

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}

//Method: addFirst
//Description: adds a node and makes it the head of the LinkedList
//Input: data (the data that the head will have)
//Output: the new list with it's new head node
//Complexity: O(1)
template<class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}

//Method: addLast
//Description: adds node to the back of the LinkedList
//Input: data (the data the last node will have)
//Output: the new list with the new last node
//Complexity: O(n)
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

//Method: deleteData
//Description: delete the node that contains the given data
//Input: data (the data of the node to be deleted)
//Output: the new list without the deleted node || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
bool LinkedList<T>::deleteData(T data){
    if(!isEmpty()){
        Node<T> *aux = head;
        if(aux->data == data){
            head = aux->next;
            size--;
            cout << "Node deleted\n";
            return true;
        }
        Node<T> *auxF = head;
        int count = 0;
        while(count < size){
            if(aux->data == data){
                auxF->next = aux->next;
                delete aux;
                size--;
                cout << "Node deleted\n";
                return true;
            }
            count++;
            auxF = aux;
            aux = aux->next;
        }
    }
    cout << "Node was not found\n";
    return false;
}

//Method: deleteAt
//Description: delete node at a given index
//Input: index (the index of the node to be deleted)
//Output: the new list without the deleted node || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
bool LinkedList<T>::deleteAt(int index){
    if(!isEmpty() || index > size || index < 0){
        int count = 1;
        Node<T> *aux = head;
        if(index == count){
            head = aux->next;
            size--;
            cout << "Node deleted\n";
            return true;
        }
        Node<T> *auxF = head;
        while(count < size){
            if(count == index){
                auxF->next = aux->next;
                delete aux;
                size--;
                cout << "Node deleted\n";
                return true;
            }
            count++;
            auxF = aux;
            aux = aux->next;
        }
    }
    cout << "Node was not found\n";
    return false;
}

//Method: getData
//Description: gets data of node at the given index
//Input: index (the index of the node)
//Output: the data of the node at the given index || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
T LinkedList<T>::getData(int index){
    if(!isEmpty() && index > 0 && index <= size){
        int count = 1;
        Node<T> *aux = head;
        while(count <= size){
            if(count == index){
                return aux->data;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Index out of range or list is empty\n");
}

//Method: updateAt
//Description: updates node's data at a given index
//Input: index (the index of the node to be updated), newData (the data to replace the current data)
//Output: the new list with the node's new data || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
bool LinkedList<T>::updateAt(int index, T newData){
    if(!isEmpty() && index > 0 && index <= size){
        int count = 1;
        Node<T> *aux = head;
        while(count <= size){
            if(count == index){
                aux->data = newData;
                return true;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Index out of range or list is empty\n");
}

//Method: updateData
//Description: updates node's data of a node with a given data
//Input: data (the data to be looked for, newData (the data to replace the current data)
//Output: the new list with the node's new data || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
bool LinkedList<T>::updateData(T data, T newData){
    if(!isEmpty()){
        Node<T> *aux = head;
        int count = 1;
        while(count <= size){
            if(aux->data == data){
                aux->data = newData;
                return true;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Data was not found\n");
}

//Method: operator[]
//Description: overloading the operator "[]" for the LinkedList to be used as an array
//Input: index (the index of the needed node)
//Output: the node at the given index || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
Node<T>* LinkedList<T>::operator[](int index){
    if(!isEmpty() && index > 0 && index <= size){
        Node<T> *aux = head;
        int count = 1;
        while(count <= size){
            if(count == index){
                return aux;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Index out of range or list is empty\n");
}

//Method: operator=
//Description: overloading the operator "=" to assing a linked list a set of values. It also keeps the values that the list may already have
//Input: list[] (an array of elements to be add to the linked list)
//Output: a linked list with the given set of elements || runtime error the array is empty
//Complexity: O(n)
template<class T>
LinkedList<T> LinkedList<T>::operator=(T list[]){
    if(sizeof(list) != 0){
        for (int i = 0; i <= sizeof(list)/sizeof(list[0]); i++){
            this->addLast(list[i]);
        }
        return *this;
    }
    throw runtime_error("Enter a non empty list\n");
}

//Method: findData
//Description: Finds the index of the node that has the given data
//Input: data (data to be found)
//Output: the index at which the data was found || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
int LinkedList<T>::findData(T data){
    if(!isEmpty()){
        Node<T> *aux = head;
        int count = 1;
        while(count <= size){
            if(aux->data == data){
                return count;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Enter a non empty list\n");
}

//Method: print
//Description: prints the elements of the linked list
//Input: NA
//Output: The elements of the linked list || message if the list is empty
//Complexity: O(n)
template<class T>
void LinkedList<T>::print(){
    Node<T> *aux = head;
    if(size > 0){
        for(int i = 0; i < size; i++){
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "The linked list is empty..";
    }
    cout << "\n";
}