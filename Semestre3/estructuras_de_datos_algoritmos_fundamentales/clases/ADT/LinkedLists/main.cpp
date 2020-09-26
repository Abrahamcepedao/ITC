#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(){
    LinkedList<int> list;
    for(int i = 10; i > 0; i--){
        list.addFirst(i);
    }
    list.print();
    
    try{
        list.updateAt(11, 100);
    } catch(runtime_error& e) {
        cout << e.what();
    }
    list.print();
    /*  if(list.deleteData(100)){
        cout << "Elemento borrado\n";
    } else{
        cout << "No se encontró el elemento\n";
    } 
    list.print();*/
    /* list.deleteAt(10);
    list.print();

    try{
        cout << list.getData(100) << "\n";
    } catch(runtime_error& e) {
        cout << e.what() << endl;
    } */
    /* Node<int> *node = new Node<int>(5);
    cout << node->data << endl;
    node->data = 6;
    cout << node->data << endl; */
    return 0;
}