// Act 2.1.1 - Implementación de un ADT de estructura de datos lineales - linked list
// Abraham Cepeda Oseguera
// A00827666
// 26 de septiembre 2020
#include <iostream>
#include <limits>
using namespace std;
#include "LinkedList.h"

// Function: checkInt
// Description: validates input to be of type (int) and in the range of the given values
// Input: min (minimum value), max (maximum value)
// Output: validated number
// Complexity: best case O(1), worst case O(n) - depends on the user input
int checkInt(int min, int max){
    int num;
    cin >> num;
    while(1){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Input must be a number.. try again: ";
            cin >> num;
        }
        if(!cin.fail()){
            if(num < min || num > max){
                cout << "Enter a valid number: ";
                cin >> num;
            } else{
                break;
            }
        }
    }
    return num;
}
// Function: menu
// Description: Prints the available choices for the user to select
// Input: NA
// Output: number that signifies the chosen option
// Complexity: O(1) - depends on the user input
int menu(){
    int ans;
    cout << "\n\n<---Menu: select an option--->\n\n";
    cout << "1. addFirst\n";
    cout << "2. addLast\n";
    cout << "3. deleteData\n";
    cout << "4. deleteAt\n";
    cout << "5. updateAt\n";
    cout << "6. updateData\n";
    cout << "7. getData\n";
    cout << "8. findData\n";
    cout << "0. toExit\n";
    cout << "Enter selection: ";
    return checkInt(0,8);
}

int main(){
    LinkedList<int> list;
    int n;
    cout << "Enter number of values: ";
    cin >> n;
    for(int i = n; i > 0; i--){
        list.addFirst(i);
    }
    list.print();
    int ans = menu();
    while(ans != 0){
        int num, index;
        switch(ans){
            case 1:
                cout << "Adding first..\n";
                cout << "Enter value: ";
                cin >> num;
                list.addFirst(num);
                break;
            case 2:
                cout << "Adding last..\n";
                cout << "Enter value: ";
                cin >> num;
                list.addLast(num);
                break;
            case 3:
                cout << "Delete data..\n";
                cout << "Enter value: ";
                cin >> num;
                try{
                    list.deleteData(num);
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 4:
                cout << "Delete data at..\n";
                cout << "Enter index: ";
                index = checkInt(1,list.getSize());
                try{
                    list.deleteAt(index);
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 5:
                cout << "Update data at..\n";
                cout << "Enter index: ";
                index = checkInt(1, list.getSize());
                cout << "Enter new data: ";
                cin >> num;
                try{
                    list.updateAt(index, num);
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 6:
                cout << "Update data..\n";
                cout << "Enter data: ";
                cin >> index;
                cout << "Enter new data: ";
                cin >> num;
                try{
                    list.updateData(index, num);
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 7:
                cout << "Get data at..\n";
                cout << "Enter index: ";
                index = checkInt(1, list.getSize());
                try{
                    cout << "data at [" << index << "] = " << list.getData(index) << "\n";
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 8:
                cout << "Find data..\n";
                cout << "Enter data: ";
                cin >> num;
                try{
                    cout << "The index of (" << num << ") = " << list.findData(num);
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            default:
                break;
        }
        cout << "\nCurrent linkedlist: ";
        list.print();
        ans = menu();
    }
    cout << "The program has finished with ease..\n\n\n";
    return 0;
}