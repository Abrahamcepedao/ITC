#include<iostream>
#include<string>
#include "ListaT.h"

using namespace std;

int menu(){
    cout << "1 Insert" << '\n';
    cout << "2 Erase" << '\n';
    cout << "3 getData" << '\n';
    cout << "4 getSize" << '\n';
    cout << "5 Print" << '\n';
    cout << "0 Exit" << '\n';
    int ans;
    cin >> ans;
    return ans;
}

int main(){
    ListaT<int> myList;
    for(int i = 1; i < 21; i++){
        myList.insert(i);
    }

    int ans = 1;
    while(ans != 0){
        ans = menu();
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