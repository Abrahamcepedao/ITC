#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip>
#include "BinarySearchTree.h"

using namespace std;
int main(){
    BinarySearchTree<int> bts;
    /* bts.insert(5);
    for(int i = 0; i < 10; i++){
        bts.insert(i);
    } */
    bts.insert(20);
    bts.insert(10);
    bts.insert(30);
    bts.insert(15);
    bts.insert(25);
    bts.print();
    bts.deleteData(25);
    bts.print();
    
    return 0;
}