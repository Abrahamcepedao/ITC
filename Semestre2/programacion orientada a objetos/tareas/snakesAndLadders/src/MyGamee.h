// Abraham Cepeda
// A00827666
// Class MyGame
#include <iostream>
#include <stdlib.h>
using namespace std;
class MyGamee{
    private:
        string board[30];
        int numberPlayers;
        int counter;

    public:
        MyGamee();
        MyGamee(int np);

        // get methods
        void createBoard();
        int getNumberPlayers();
        int getCounter();
        void printBoard();
        
        // set methods
        void setNumberPlayers(int n);

        // other methods
        void increaseCounter();
        int calculateNewPosition(int cp, int dr);
};

// constructors
MyGamee::MyGamee(){
    string board[30];
    int numberPlayers = 2;
    int counter = 0;
}
MyGamee::MyGamee(int np){
    string board[30];
    int numberPlayers = np;
    int counter = 0;
}

// get mehtods
void MyGamee::createBoard(){
    int snakes[3];
    int ladders[3];
    int random;
    srand(time(0));
    // normals
    for (int i = 0; i < 30; i++){
        board[i] = "N";
    }
    // snakes
    for(int i = 0; i < 3; i++){
        random = rand() % 25 + 4;
        snakes[i] = random;
        if(i > 0){
            bool continuee = true;
            while(continuee){
                continuee = false;
                for(int j = 0; j < i; j++){
                    if(snakes[i] == snakes[j]){
                        continuee = true;
                        random = rand() % 25 + 4;
                        snakes[i] = random;
                    }
                }
            }
        }
        board[snakes[i]] = "S";
    }
    // ladders
    for(int i = 0; i < 3; i++){
        random = rand() % 26 + 1;
        ladders[i] = random;
        bool continuee = true;
        while(continuee){
            continuee = false;
            //check for snakes
            for(int j = 0; j < 3; j++){
                if(ladders[i] == snakes[j]){
                    continuee = true;
                    random = rand() % 26 + 1;
                    ladders[i] = random;
                }
            }
            if(!continuee){
                for(int j = 0; j < i; j++){
                    if(ladders[i] == ladders[j]){
                        continuee = true;
                        random = rand() % 26 + 1;
                        ladders[i] = random;
                    }
                }
            }
        }
        board[ladders[i]] = "L";
    }
}
int MyGamee::getNumberPlayers(){
    return numberPlayers;
}
int MyGamee::getCounter(){
    return counter;
}

void MyGamee::printBoard(){
    for(int i = 0; i < 30; i++){
        cout << board[i];
    }
    cout << "\n";
}

// set methods
void MyGamee::setNumberPlayers(int np){
    numberPlayers = np;
}



// other methods
void MyGamee::increaseCounter(){
    counter++;
}
int MyGamee::calculateNewPosition(int cp, int dr){
    int newPosition = cp + dr;
    if(board[newPosition-1] == "S"){
        newPosition -= 3;
        cout << "Type of position: S\n";
    } else if(board[newPosition-1] == "L"){
        newPosition += 3;
        cout << "Type of position: L\n";
    } else{
        cout << "Type of position: N\n";
    }
    return newPosition;
}
