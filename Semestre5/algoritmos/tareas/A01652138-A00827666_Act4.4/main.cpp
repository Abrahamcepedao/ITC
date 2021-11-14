//Actividad 4.4 Implementación Randomized Binary Search
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

//function to generate a random number between an interval
//input: min and max values
//output: random number
//complexity: O(1)
int generateRandom(int x, int y){
    srand(time(NULL));
    return (x + rand() % (y - x + 1));
}

//function to find number with randomized binary search in vector
//input: vector of numbers, number to find
//output: index of number in vector
//complexity: O(log n)
//randomized binary search
int randomizedBinaryAearch(vector<int> &v, int low, int high, int n) {
    while (low <= high) {
        int mid = generateRandom(low, high); //generate random number between low and high
        if (v[mid] == n) return mid; //if number is found, return index
        else if (v[mid] < n) low = mid + 1; //if number is smaller, search in the right half
        else high = mid - 1; //if number is bigger, search in the left half
    }
    return -1;
}

int main(){
    //read number of points
    int n;
    string input, aux;
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementación Randomized Binary Search\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Ingrese el número que se debe encontrar> ";
    cin >> n;
    cin >> input;
    while(input[input.size()-1] == ','){
        cin >> aux;
        input += aux;
    }
    
    //convert string to vector
    vector<int> numbers;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ',') {
            numbers.push_back(stoi(input.substr(0, i)));
            input = input.substr(i + 1);
            i = 0;
        }
    }

    //push last number
    numbers.push_back(stoi(input));

    //sort vector
    sort(numbers.begin(), numbers.end());

    //find number in vector
    int index = randomizedBinaryAearch(numbers, 0, numbers.size() - 1, n);
    if (index == -1) {
        cout << "\nEl número no se encuentra en el vector";
    } else {
        cout << "\nEl número se encuentra en el vector en la posición " << index;
    }
    cout << endl;

    return 0;
}
