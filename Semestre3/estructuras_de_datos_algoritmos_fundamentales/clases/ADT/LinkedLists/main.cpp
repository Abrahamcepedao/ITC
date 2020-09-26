#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(){
    LinkedList<int> list;
    for(int i = 9; i >= 0; i--){
        list.addHead(i);
    }
    list.print();
    list.addLast(10);
    list.print();

    if(list.deleteData(5)){
        cout << "Elemento borrado\n";
    } else{
        cout << "No se encontró el elemento\n";
    }
    /* Node<int> *node = new Node<int>(5);
    cout << node->data << endl;
    node->data = 6;
    cout << node->data << endl; */
    return 0;
}