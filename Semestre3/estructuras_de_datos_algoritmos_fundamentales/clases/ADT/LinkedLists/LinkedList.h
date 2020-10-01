// Act 2.1.1 - Linked List class
// Abraham Cepeda Oseguera
// A00827666
// 26 de septiembre 2020
#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
template <class T>

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

        void insertAt(int index, T data);
        void clear();
        void duplicate();
        void removeDuplicates();
        void reverse();

        void mergeSort(vector<T> &vect, int l, int r);
        void merge(vector<T> &vect, int l, int m, int r);
        void order();

        Node<T> *operator[](int index);
        LinkedList<T> operator=(vector<T> list);

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
            cout << "Succes: node deleted\n";
            return true;
        }
        Node<T> *auxF = head;
        while(aux != NULL){
            if(aux->data == data){
                auxF->next = aux->next;
                delete aux;
                size--;
                cout << "Succes: node deleted\n";
                return true;
            }
            auxF = aux;
            aux = aux->next;
        }
    }
    cout << "Error: node was not found..\n";
    return false;
}

//Method: deleteAt
//Description: delete node at a given index
//Input: index (the index of the node to be deleted)
//Output: the new list without the deleted node || runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
bool LinkedList<T>::deleteAt(int index){
    if(!isEmpty() && index <= size && index > 0){
        int count = 1;
        Node<T> *aux = head;
        if(index == count){
            head = aux->next;
            size--;
            cout << "Succes: node deleted\n";
            return true;
        }
        Node<T> *auxF = head;
        while(aux != NULL){
            cout << count << " ";
            if(count == index){
                auxF->next = aux->next;
                delete aux;
                size--;
                cout << "Succes: node deleted\n";
                return true;
            }
            count++;
            auxF = aux;
            aux = aux->next;
        }
    }
    cout << "Error: node was not found\n";
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
    throw runtime_error("Error: index out of range or list is empty\n");
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
                cout << "Node updated succesfully\n";
                return true;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Error: index out of range or list is empty\n");
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
                cout << "Node updated succesfully\n";
                return true;
            }
            count++;
            aux = aux->next;
        }
    }
    throw runtime_error("Error: data was not found\n");
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
    throw runtime_error("Error: index out of range or list is empty\n");
}

//Method: insertAt
//Description: insert data at the given index
//Input: index (the index where to insert data), data (the data to be inserted)
//Output: The list with the new value|| runtime error if invalid index or empty Linkedlist
//Complexity: O(n)
template<class T>
void LinkedList<T>::insertAt(int index, T data){
    if(!isEmpty() && index > 0 && index <= size){
        if(index == 1){
            addFirst(data);
        } else {
            Node<T> *aux = head;
            Node<T> *auxF = head;
            int count = 1;
            while(aux != NULL){
                if(count == index){
                    auxF->next = new Node<T>(data,aux);
                    size++;
                }
                count++;
                auxF = aux;
                aux = aux->next;
            }
        }
    } else{
        throw runtime_error("Error: index out of range or list is empty\n");
    }
}

//Method: clear
//Description: Deletes all the elements of the list
//Input: NA
//Output: empty list
//Complexity: O(n)
template<class T>
void LinkedList<T>::clear(){
    while(!isEmpty()){
        deleteAt(1);
    }
    cout << "Succes: data deleted..\n";
}

//Method: duplicate
//Description: Duplicates all the elements of the list
//Input: NA
//Output: List with a duplicate of each element
//Complexity: O(n)
template<class T>
void LinkedList<T>::duplicate(){
    if(!isEmpty()){
        Node<T> *aux = head;
        int count = 2;
        while(aux != NULL){
            count > size ? addLast(aux->data) : insertAt(count, aux->data);
            count += 2;
            aux = aux->next->next;
        }
    } else{
        throw runtime_error("Error: list is empty\n");
    }
}

//Method: removeDuplicates
//Description: Removes all duplicate elements of the list
//Input: NA
//Output: List with solely unique elements
//Complexity: O(n^2)
template<class T>
void LinkedList<T>::removeDuplicates(){
    if(!isEmpty()){
        vector<T> vect;
        Node<T> *aux = head;
        while(aux != NULL){
            bool condition = true;
            for(T i : vect){
                if(aux->data == i){
                    condition = false;
                }
            }
            if(condition){
                vect.push_back(aux->data);
            } else{
                deleteData(aux->data);
            }
            aux = aux->next;
        }
        cout << "Succes: Duplicates removed\n";
    } else{
        throw runtime_error("Error: list is empty\n");
    }
}

//Method: reverse
//Description: Reverses all the elements of the list
//Input: NA
//Output: List with reversed elements
//Complexity: O(n^2)
template<class T>
void LinkedList<T>::reverse(){
    if(!isEmpty()){
        vector<T> vect;
        Node<T> *aux = head;
        while(aux != NULL){
            vect.push_back(aux->data);
            aux = aux->next;
        }
        clear();
        for(T i : vect){
            addFirst(i);
        }
    } else{
        throw runtime_error("Error: list is empty\n");
    }
}

//Method: merge
//Description: Merges two lists
//Input: NA
//Output: merged list
//Complexity: O(n^2)
template<class T>
void LinkedList<T>::merge(vector<T> & vect, int l, int  m, int r){
    int i = 0, j = 0, count = l;
    vector<T> vect1, vect2;
    for(int e = l; e <= m; e++){
        vect1.push_back(vect[e]);
    }
    for(int k = m+1; k <= r; k++){
        vect2.push_back(vect[k]);
    }
    while(i < (m-l+1) && j < (r-m)){
        if(vect1[i] > vect2[j]){
            vect[count] = vect2[j];
            j++;
        } else{
            vect[count] = vect1[i];
            i++;
        }
        count++;
    }
    while(i < (m - l + 1)){
        vect[count] = vect1[i];
        count++;
        i++;
    }
    while(j < (r-m)){
        vect[count] = vect2[j];
        count++;
        j++;
    }
}

//Method: mergeSort
//Description: Orders a list  by diving it into two and then merges them
//Input: NA
//Output: Ordered list
//Complexity: O(n^2)
template<class T>
void LinkedList<T>::mergeSort(vector<T> & vect, int l, int r){
    if(!isEmpty()){
        if(l < r){
            int m = l + (r-l) / 2;
            mergeSort(vect, l, m);
            mergeSort(vect, m + 1, r);
            merge(vect, l, m, r);
        }
    } else{
        throw runtime_error("Error: list is empty\n");
    }
}

//Method: order
//Description: Wirtes the list's data into a vector for more simple ordering
//Input: NA
//Output: Orders the list
//Complexity: O(n^2)
template<class T>
void LinkedList<T>::order(){
    if(!isEmpty()){
        vector<T> vect;
        Node<T> *aux = head;
        while(aux != NULL){
            vect.push_back(aux->data);
            aux = aux->next;
        }
        mergeSort(vect, 0, size-1);
        for(int i = 1; i <= vect.size(); i++){
            updateAt(i, vect[i-1]);
        }
    }
}

//Method: operator=
//Description: overloading the operator "=" to assing a linked list a set of values. It also keeps the values that the list may already have
//Input: list[] (an array of elements to be add to the linked list)
//Output: a linked list with the given set of elements || runtime error the array is empty
//Complexity: O(n)
template<class T>
LinkedList<T> LinkedList<T>::operator=(vector<T> list){
    if(sizeof(list) != 0){
        for (T listItem : list){
            this->addLast(listItem);
        }
        return *this;
    } else{
        throw runtime_error("Error: enter a non empty list\n");
    }
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
    throw runtime_error("Error: index out of range\n");
}

//Method: print
//Description: prints the elements of the linked list
//Input: NA
//Output: The elements of the linked list || message if the list is empty
//Complexity: O(n)
template<class T>
void LinkedList<T>::print(){
    Node<T> *aux = head;
    if(!isEmpty()){
        for(int i = 0; i < size; i++){
            cout << aux->data << " ";
            aux = aux->next;
        }
    } else{
        cout << "The linked list is empty..";
    }
    cout << "\n";
}