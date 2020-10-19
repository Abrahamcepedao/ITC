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


// Function: menu
// Description: Prints the available choices for the user to select
// Input: NA
// Output: number that signifies the chosen option
// Complexity: O(1) - depends on the user input
int menu(){
    int ans;
    cout << "\n\n<---Menu: select an option--->\n\n";
    cout << "1.  Insert node\n";
    cout << "2.  Delete node\n";
    cout << "3.  What level am I?\n";
    cout << "4.  Get height of tree\n";
    cout << "5.  Print ancestors of node\n";
    cout << "6.  Print tree\n";
    cout << "7.  Visit tree (preorder)\n";
    cout << "8.  Visit tree (inorder)\n";
    cout << "9.  Visit tree (postorder)\n";
    cout << "10. Visit tree (level by level)\n";
    cout << "11. Find node\n";
    cout << "0.  toExit\n";
    cout << "Enter selection: ";
    return checkIntR(0,13);
}



int main(){
    MinHeap<int> minHeap;
    minHeap.insert(9);
    minHeap.insert(4);
    minHeap.insert(6);
    minHeap.insert(8);
    minHeap.printHead();
    minHeap.print();
    Node<int> *temp = minHeap.getNodeAt(2);
    cout << "temp->data: " << temp->data << endl;
    /* BinarySearchTree<int> bts;
    bts.insert(10);
    bts.insert(15);
    bts.insert(5);
    bts.insert(7);
    bts.insert(6);
    bts.insert(1);
    bts.insert(4);
    bts.insert(3);
    bts.insert(9);
    bts.insert(14);
    bts.insert(17);
    bts.insert(12);
    bts.insert(16);
    bts.insert(23);
    bts.insert(24);
    bts.insert(25);

    cout << "<------Current tree------>\n";
    bts.print();

    int ans = menu();
     while(ans != 0){
        int num;
        switch(ans){
            case 1:
                cout << "Inserting node..\n";
                cout << "Enter node value: ";
                bts.insert(checkInt());
                break;
            case 2:
                cout << "Deleting node..\n";
                cout << "Enter value: ";
                try{
                    bts.deleteData(checkInt());
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 3:
                cout << "Finding level..\n";
                cout << "Enter value: ";
                num = checkInt();
                try{
                    cout << "->Level of" << num << ": " << bts.whatlevelamI(num);
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 4:
                cout << "Getting height of tree..\n";
                try{
                    cout << "->Height of tree: " << bts.getHeight() << "\n";
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 5:
                cout << "Printing ancestors of node..\n";
                cout << "Enter value: ";
                try{
                    bts.ancestors(checkInt());
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 6:
                cout << "Printing entire tree..\n";
                try{
                    bts.print();
                } catch(runtime_error& e){
                    cout << e.what();
                }
                break;
            case 7:
                cout << "Visiting tree (preorder)..\n";
                bts.visit(1);
                break;
            case 8:
                cout << "Visiting tree (inorder)..\n";
                bts.visit(2);
                break;
            case 9:
                cout << "Visiting tree (postorder)..\n";
                bts.visit(3);
                break;
            case 10:
                cout << "Visiting tree (level by level)..\n";
                bts.visit(4);
                break;
            case 11:
                cout << "Finding node..\n";
                cout << (bts.find(checkInt()) ? "The node was found..\n" : "The node was not found..\n");
                break;
            default:
                break;
        }
        ans = menu();
    } */
    cout << "The program has finished with ease..\n\n\n";
    return 0;
}