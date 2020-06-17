#include <iostream>
using namespace std;
class MyGame{
    private:
        string board[30];
        int numberPlayers;
        int counter;
    public:
        // initialize
        MyGame();
        MyGame(int np);

        // get methods
        string createBoard();
        int getContador();
        //void printBoard();

        // set methods
        void setNumberPlayers(int n);

        // other methods
        void increaseCounter();
 };
 
 // constructors
 MyGame::MyGame(){
     string board[30];
     int numberPlayers = 2;
     int counter = 0;
 }
 
 MyGame::MyGame(int np){
     string board[30];
     int numberPlayers = np;
     int counter = 0;
 }

// get mehtods
string MyGame::createBoard(){
    int snakes[3];
    int ladders[3];
    int random;
    // normals
    for (int i = 0; i < 30; i++){
        board[i] = "N";
    }
    // snakes
    for (int i = 0; i < 3; i++){
        random = rand() % 25 + 4;
        snakes[i] = random;
        if (i > 0){
            while (snakes[i-1] == snakes[i]){
                random = rand() % 25 + 4;
                snakes[i] = random;
            }
        }
        board[snakes[i]] = "S";
    }
    // ladders
    for (int i = 0; i < 3; i++){
        bool continuee = false;
        while (!continuee){
            random = rand() % 25 + 4;
            ladders[i] = random;
            for (int j = 0; j < 3; j++){
                if (ladders[i] == snakes[j]){
                    continuee = true;
                }
            }
            for (int k = 0; k < i; k++){
                if (ladders[i] == ladders[k]){
                    continuee = true;
                }
                
            }
        }
    }
}
int MyGame::getContador(){
    return counter;
}
// set methods
 
 // other methods
 void MyGame::increaseCounter(){
     counter++;
 }