// This program manipulates an array that can have several datatypes since the class uses Templates
// Abraham Cepeda Oseguera
// A00827666
// August 10th 2020
#include<iostream>
#include<string>
#include "ListaT.h"

using namespace std;

//Menu function
int menu(){
    cout << "1 Insert" << '\n';
    cout << "2 Erase" << '\n';
    cout << "3 getData" << '\n';
    cout << "4 getSize" << '\n';
    cout << "5 Print" << '\n';
    cout << "0 Exit" << '\n';
    int ans;
    cin >> ans;  //read answer
    return ans;
}
//Main function
int main(){
    //Create object
    ListaT<int> myList;
    //Populate object
    for(int i = 1; i < 21; i++){
        myList.insert(i);
    }
    //Begin program that will continue while ans != 0
    int ans = 1;
    while(ans != 0){
        ans = menu(); //Get answer from menu
        // This switch analyzes the answer given by the user and calls the object's method respectively
        switch (ans){
            case 1:
                int num;
                cout << "Enter num: ";
                cin >> num;
                try{
                    myList.insert(num);
                }
                catch(runtime_error& e){
                    cout << e.what() << '\n';
                }
                break;
            case 2:
                try {
                    int num = myList.erase();
                    cout << "Num = " << num << '\n';
                }
                catch (runtime_error& e) {
                    cout << e.what() << '\n';
                }
                break;
            case 3:
                int index;
                cout << "Enter index: ";
                cin >> index;
                try {
                    int num = myList.getData(index);
                    cout << "Num = " << num << '\n';
                }
                catch (runtime_error& e) {
                    cout << e.what() << '\n';
                }
                break;
            case 4:
                cout << "Size = " << myList.getSize() << '\n';
                break;
            case 5:
                myList.print();
                break;
            default:
                cout << "The program has finished" << '\n';
                break;
        }
    }
    return 0;
}