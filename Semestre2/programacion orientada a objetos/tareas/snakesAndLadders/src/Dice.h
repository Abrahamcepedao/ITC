// Abraham Cepeda
// A00827666
// Class Dice
#include <iostream>
#include <stdlib.h>
using namespace std;
class Dice{
    private:
        int number;

    public:
        Dice();

        // get methods
        int diceRoll();
};
// constructors
Dice::Dice(){
    int number = 0;
}

// get methods
int Dice::diceRoll(){
    number = rand() % 6 + 1;
    return int(number);
}