#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void readFile(string &str, int n){
    string fileName;
    switch (n){
        case 0:
            fileName = "transmission1.txt";
            break;
        case 1:
            fileName = "transmission2.txt";
            break;
        case 2:
            fileName = "mcode1.txt";
            break;
        case 3:
            fileName = "mcode2.txt";
            break;
        case 4:
            fileName = "mcode3.txt";
            break;
        default:
            break;
    }
    ifstream file(fileName);
    string line;
    while(getline(file, line)) str += line;
}

void findSequence(string txt, string seq){
    
}

int  main(){
    //create variables
    string transmission1, transmission2, mcode1, mcode2, mcode3;

    //read files
    readFile(transmission1, 0);
    readFile(transmission2, 1);
    readFile(mcode1, 2);
    readFile(mcode2, 3);
    readFile(mcode3, 4);
    cout << "transmision1: " << transmission1 <<  "\n\n";
    cout << "transmision2: " << transmission2 << "\n\n";
    cout << "mcode1: " << mcode1 << "\n\n";
    cout << "mcode2: " << mcode2 << "\n\n";
    cout << "mcode3: " << mcode3 << "\n\n";

    //output 1

    //output 2

    //output 3

    return 0;
}