#include "Hash.h"
#include "HashC.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    Hash<string> hashTable;
    HashC<string> hastTableC;
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    srand(time(0));
    
    for(int i = 0; i < 50; i++){
        string key = "";
        for(int j = 0; j < 2; j++){
            key += letters[rand() % 25];
            key += to_string(rand() % 9);
        }
        hashTable.insert(key);
        hastTableC.insert(key);
    }
    cout << "\n\nHashTable Quadratic probing\n\n";
    hashTable.print();
    cout << "\n\nHashTable Chain probing\n\n";
    hastTableC.print();
    
    return 0;
}