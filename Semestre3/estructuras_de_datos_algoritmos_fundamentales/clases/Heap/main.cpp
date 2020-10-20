#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip>
#include "MinHeap.h"

using namespace std;

// Function: checkInt
// Description: validates input to be of type (int)
// Input: NA
// Output: validated number
// Complexity: best case O(1), worst case O(n) - depends on the user input
int checkInt(){
    int num;
    cout << "Enter num: ";
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

// Function: checkInt
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

template<class T>
void heapSort(MinHeap<T> &minHeap, DLinkedList<T> &list){
    list.clear();
    while(minHeap.getSize() > 0){
        list.addBack(minHeap[1]->data);
        minHeap.remove();
    }
}



// Function: menu
// Description: Prints the available choices for the user to select
// Input: NA
// Output: number that signifies the chosen option
// Complexity: O(1) - depends on the user input
int menu(){
    int ans;
    cout << "\n\n<---Menu: select an option--->\n\n";
    cout << "1.  Insert node\n";
    cout << "2.  Remove node\n";
    cout << "3.  Heap Sort\n";
    cout << "4.  Print\n";
    cout << "0.  toExit\n";
    cout << "Enter selection: ";
    return checkIntR(0,13);
}



int main(){
    
    DLinkedList<int> dList;
    dList.addBack(9);
    dList.addBack(4);
    dList.addBack(6);
    dList.addBack(8);
    dList.addBack(7);
    dList.addBack(3);
    MinHeap<int> minHeap(dList);

    int ans = menu();
     while(ans != 0){
        int num;
        switch(ans){
            case 1:
                cout << "Inserting node..\n";
                cout << "Enter node value: ";
                minHeap.insert(checkInt());
                break;
            case 2:
                cout << "Deleting node..\n";
                minHeap.remove();
                break;
            case 3:
                cout << "Heap sort..\n";
                heapSort(minHeap, dList);
                minHeap = dList;
                cout << "Sorted heap: ";
                minHeap.print();
                break;
            case 4:
                cout << "Printing heap..\n";
                minHeap.print();
                break;
            default:
                break;
        }
        ans = menu();
    }
    cout << "The program has finished with ease..\n\n\n";
    return 0;
}