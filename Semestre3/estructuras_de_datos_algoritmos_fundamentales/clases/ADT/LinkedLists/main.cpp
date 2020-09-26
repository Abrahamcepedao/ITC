#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(){
    LinkedList<int> list;
    for(int i = 100; i > 0; i--){
        list.addFirst(i);
    }
    list.print();

    if(list.deleteData(100)){
        cout << "Elemento borrado\n";
    } else{
        cout << "No se encontró el elemento\n";
    }
    list.print();
    /* Node<int> *node = new Node<int>(5);
    cout << node->data << endl;
    node->data = 6;
    cout << node->data << endl; */
    return 0;
}