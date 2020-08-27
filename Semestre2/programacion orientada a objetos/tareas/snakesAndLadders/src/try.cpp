#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Dice.h"
using namespace std;
int main(){
    Dice dice;
    int random;
    for(int i = 0; i < 10; i++){
        random = dice.diceRoll();
        cout << random << endl;
    }
}