#include<iostream>
#include<string>
#include "Lista.h"

using namespace std;

int main(){
    Lista myList;
    for(int i = 1; i < 21; i++){
        myList.insert(i);
    }
    myList.print();
    myList.erase();
    myList.print();
    cout << "myList size = " << myList.getSize() << endl;
    cout << "Data at 7 = " << myList.getData(7) << endl;
    return 0;
}