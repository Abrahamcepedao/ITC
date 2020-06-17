#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
    string board[30];
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
    for(int i = 0; i < 30; i++){
        cout << board[i] << endl;
    }
    for(int i = 0; i < 3; i++){
        cout << snakes[i] << endl;
        cout << ladders[i] << endl;
    }
    return 0;
}