//Actividad 5.1 Implementación backtracking: El problema The Knight’s tour.
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
#include <string>
using namespace std;

#define N 8 // NxN chessboard

//function checks if the move is valid or not
//input: row, col, board
//output: true if valid, false otherwise
//complexity: O(1)
int isSafe(int row, int col, int board[N][N]) { return (row >= 0 && row < N && col >= 0 && col < N && board[row][col] == -1); }

//function prnit the board
//input: board
//output: none
//complexity: O(n^2)
void printBoard(int board[N][N]){
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++)
            cout << " " << board[row][col] << " ";
        cout << endl;
    }
}

//function to solve knight tour board using backtracking
//input: row, col, nMove, board, rMoves, cMoves
//output: true if solution is found, false otherwise
//complexity: O(n^2)
int solveKnightTour(int row, int col, int nMove, int board[N][N], int rMoves[8], int cMoves[8]){
    int k, nerowt_row, nerowt_col;
    if (nMove == N * N) return true; // se completo el tablero

    for (k = 0; k < 8; k++){
        nerowt_row = row + rMoves[k]; // obtener la fila de la siguiente posicion
        nerowt_col = col + cMoves[k]; // obtener la columna de la siguiente posicion
        if (isSafe(nerowt_row, nerowt_col, board)){
            board[nerowt_row][nerowt_col] = nMove; // colocar el numero de movimiento en la siguiente posicion
            if (solveKnightTour(nerowt_row, nerowt_col, nMove + 1, board, rMoves, cMoves) == 1)
                return true; // se completo el tablero
            else
                board[nerowt_row][nerowt_col] = -1; // se remueve la posicion
        }
    }
    return false; // no se completo el tablero
}

int main(){
    int n;
    cout << endl << "----------------------------------------------------------------------------------------\n";
    cout << "Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout << "----------------------------------------------------------------------------------------\n";

    cout << "Implementación backtracking: El problema The Knight’s tour.\n";
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Ingrese el número n: ";
    cin >> n;
    cout << endl;
    int board[N][N];

    for (int row = 0; row < N; row++) for (int col = 0; col < N; col++) board[row][col] = -1; // inicializar el tablero a -1

    int rMoves[8] = {2, 1, -1, -2, -2, -1, 1, 2}; // posibles movies de las filas
    int cMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // posibles movies de las columnas

    board[0][0] = 0; // cambiar primera posicion del tablero a 0

    if (solveKnightTour(0, 0, 1, board, rMoves, cMoves)){
        printBoard(board);
    } else
        cout << "No se encontró una solucion";
    return 0;
}
