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
    bts.insert(10);
    bts.insert(15);
    bts.insert(5);
    bts.insert(2);
    bts.insert(7);
    bts.insert(1);
    bts.insert(9);
    bts.insert(14);
    bts.insert(17);
    bts.insert(12);
    bts.insert(16);
    bts.insert(23);
    bts.print();
    bts.deleteData(15);
    bts.print();
    
    return 0;
}