// Act 2.2.1 - Implementación de un ADT de estructura de datos lineales - Stack
// Abraham Cepeda Oseguera
// A00827666
// 1 de octubre 2020
#include <iostream>
#include <limits>
using namespace std;
#include "Stack.h"

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
    cout << "1.  Push\n";
    cout << "2.  Pop\n";
    cout << "3.  Top\n";
    cout << "4.  getSize\n";
    cout << "5.  clear\n";
    cout << "6.  print\n";
    cout << "0.  toExit\n";
    cout << "Enter selection: ";
    return checkInt(0,6);
}

int main(){
    Stack<int> stack;
    int ans = menu();
    while(ans != 0){
        int num, index;
        switch(ans){
            case 1:
                cout << "Push..\n";
                cout << "Enter value: ";
                cin >> num;
                stack.push(num);
                break;
            case 2:
                cout << "Pop..\n";
                try{
                    cout << "Popped element = " << stack.pop() << "\n";
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 3:
                cout << "Top..\n";
                try{
                    cout << "top = " << stack.getTop() << "\n";
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 4:
                cout << "Get size..\n";
                cout << "size = " << stack.getSize() << "\n";
                break;
            case 5:
                cout << "Clear..\n";
                stack.clear();
                break;
            case 6:
                cout << "Print stack..\n";
                cout << "\nCurrent Stack: ";
                stack.print();
                break;
            default:
                break;
        }
        ans = menu();
    }
    cout << "The program has finished with ease..\n\n\n";
    return 0;
}