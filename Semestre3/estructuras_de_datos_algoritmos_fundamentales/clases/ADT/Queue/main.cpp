// Act 2.2.1 - Implementación de un ADT de estructura de datos lineales - Stack
// Abraham Cepeda Oseguera
// A00827666
// 1 de octubre 2020
#include <iostream>
#include <limits>
using namespace std;
#include "Queue.h"

// Function: checkInt
// Description: validates input to be of type (int) 
// Input: NA
// Output: validated number
// Complexity: best case O(1), worst case O(n) - depends on the user input
int checkInt(){
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
            return num;
        }
    }
}

// Function: checkIntR
// Description: validates input to be of type (int) and in the range of the given values
// Input: min (minimum value), max (maximum value)
// Output: validated number
// Complexity: best case O(1), worst case O(n) - depends on the user input
int checkIntR(int min, int max){
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
    cout << "1.  enqueue\n";
    cout << "2.  dequeue\n";
    cout << "3.  front\n";
    cout << "4.  back\n";
    cout << "5.  getSize\n";
    cout << "6.  clear\n";
    cout << "7.  print\n";
    cout << "0.  toExit\n";
    cout << "Enter selection: ";
    return checkIntR(0,7);
}

int main(){
    Queue<int> queue;
    int ans = menu();
    while(ans != 0){
        int num, index;
        switch(ans){
            case 1:
                cout << "enqueue..\n";
                cout << "Enter value: ";
                num = checkInt();
                queue.enqueue(num);
                /* queue.push(num); */
                break;
            case 2:
                cout << "dequeue..\n";
                try{
                    cout << "Dequeued element = " << queue.dequeue() << "\n";
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 3:
                cout << "Front..\n";
                try{
                    cout << "front = " << queue.front() << "\n";
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 4:
                cout << "Back..\n";
                cout << "back = " << queue.back() << "\n";
                break;
            case 5:
                cout << "Get size..\n";
                cout << "size = " << queue.getSize() << "\n";
                break;
            case 6:
                cout << "Clear..\n";
                queue.clear();
                break;
            case 7:
                cout << "Print queue..\n";
                cout << "\nCurrent queue: ";
                queue.print();
                break;
            default:
                break;
        }
        ans = menu();
    }
    cout << "The program has finished with ease..\n\n\n";
    return 0;
}