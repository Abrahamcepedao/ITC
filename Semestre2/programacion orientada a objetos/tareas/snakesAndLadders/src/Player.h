#include <iostream>
using namespace std;
class Player{
    private:
        string name;
        int currentPosition;
    public:
        Player();
        Player(string n, int c);

        string getPlayerName();
        int getCurrentPosition();

        void setName(string n);
        void setNewPosition(int c);
};

// constructors
Player::Player(){
    name = "Player";
    currentPosition = 1;
}

Player::Player(string n, int c){
    name = n;
    currentPosition = c;
}

// get methods
string Player::getPlayerName(){
    return name;
}
int Player::getCurrentPosition(){
    return currentPosition;
}

// set methods
void Player::setName(string n){
    name = n;
}
void Player::setNewPosition(int c){
    currentPosition = c;
}