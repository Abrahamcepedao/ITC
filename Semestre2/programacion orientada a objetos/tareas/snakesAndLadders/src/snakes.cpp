// Tarea 1 - Serpientes y escaleras
// Abraham Cepeda Oseguera
// A00827666

#include <iostream>
#include <string>
#include "MyGamee.h"
#include "Player.h"
#include "Dice.h"
using namespace std;

int main(){
    cout << "\n\n\n                        <--------------------Welcome Snakes and Ladders!!-------------------->\n\n\n";
    MyGamee game;
    Dice dice;
    int diceRoll;
    int numberPlayers;
    int newPosition;
    int winner = 0;
    string playerName;
    string userAnswer = "C";

    game.createBoard();
    game.printBoard();

    cout << "Enter number of players: ";
    cin >> numberPlayers;
    game.setNumberPlayers(numberPlayers);
    Player player[game.getNumberPlayers()];

    for(int i = 0; i < game.getNumberPlayers(); i++){
        cout << "Enter player " << (i+1) << " name: ";
        cin >> playerName;
        player[i].setName(playerName);
    }

    while ((userAnswer == "C") & (game.getCounter() < 30) & (winner != 30)){
        game.increaseCounter();
        cout << "Turn number: " << game.getCounter() << "\n";
        for(int i = 0; i < game.getNumberPlayers(); i++){
            cout << player[i].getPlayerName() << " its your turn\n";
            cout << "Your current position is: " << player[i].getCurrentPosition() << "\n";
            diceRoll = dice.diceRoll();
            cout << "You dice number is: " << diceRoll << "\n";
            newPosition = game.calculateNewPosition(player[i].getCurrentPosition(),diceRoll);
            player[i].setNewPosition(newPosition);
            cout << "Your new position is: " << player[i].getCurrentPosition() << "\n";
            if(player[i].getCurrentPosition() >= 30){
                winner = 30;
                cout << "We have a winer!!\n";
                break;
            }
        }
        if(winner == 30){
            break;
        } else{
            cout << "Press C to continue or E to exit: ";
            cin >> userAnswer;
            cout << userAnswer << endl;
        }
    }
    if (userAnswer == "E"){
        cout << "Thanks for playing!!\n";
    } else if(game.getCounter() == 30){
        cout << "Maximum number of turns has been reached!!\n";
        cout << "These are the final results!!\n";
        for(int i = 0; i < game.getNumberPlayers(); i++){
            cout << player[i].getPlayerName() << " final position is: " << player[i].getCurrentPosition() << "\n";
        }
    } else{
        cout << "We have a winer!!\n";
        cout << "These are the final results:\n";
        int maxNumber = player[0].getCurrentPosition();
        string maxName = player[0].getPlayerName();
        for(int i = 0; i < game.getNumberPlayers(); i++){
            cout << player[i].getPlayerName() << " final position is: " << player[i].getCurrentPosition() << "\n";
            if(maxNumber < player[i].getCurrentPosition()){
                maxNumber = player[i].getCurrentPosition();
                maxName = player[i].getPlayerName();
            }
        }
        cout << "Therefore, the winner is: " << maxName << " with the " << maxNumber << " position!!\n";
    }
    return 0;
}