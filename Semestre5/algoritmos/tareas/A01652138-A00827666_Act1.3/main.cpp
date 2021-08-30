//Actividad 1.3 Implementación de la técnica de programación "backtracking" y "ramificación y poda"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666

#include<iostream>
using namespace std;

int n, m; // col and rows of matrix

void printSol(int solArray[][100]){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++) cout << solArray[i][j] << " ";
		cout << "\n";
	}
}

//funcion: backtrackingUtil
//Analiza las posibles casillas por las cuales se podría llegar a la solución y eventualmente determina las correctas
//Complejidad O(n^2)
bool backtrackingUtil(int matrix[][100], int l, int r, int solArray[][100]){
	if(l == n -1 && r == m - 1){
		solArray[l][r] = 1; 
		return true; // found solution
	}

	solArray[l][r] = 1; // agregar casilla a solución
	
	//move right
	if(r < n -1) if(matrix[l][r+1] == 1 && solArray[l][r+1] != 1) if(backtrackingUtil(matrix, l, r + 1, solArray)) return true;
		
	//move down
	if(l < m -1) if(matrix[l+1][r] == 1 && solArray[l+1][r] != 1) if(backtrackingUtil(matrix, l + 1, r, solArray)) return true;

	//move left
	if(r > 0) if(matrix[l][r-1] == 1 && solArray[l][r-1] != 1) if(backtrackingUtil(matrix, l, r - 1, solArray)) return true;

	//move up
	if(l > 0) if(matrix[l-1][r] == 1 && solArray[l-1][r] != 1) if(backtrackingUtil(matrix, l - 1, r, solArray)) return true;
		
	solArray[l][r] = 0; // quitar casilla de solución
	return false;

}

void backtracking(int matrix[][100]){
	int solArray[m][100];
	for (int i = 0; i < m; ++i) for(int j = 0; j < n; j++) solArray[i][j] = 0;

	if(backtrackingUtil(matrix, 0, 0, solArray)) printSol(solArray); else cout << "N hay solución..\n";
}

void rampoda(int matrix[][100]){
	int solArray[m][100];
	for (int i = 0; i < m; ++i) for(int j = 0; j < n; j++) solArray[i][j] = 0;

}

int main() {

    cout<<endl<<"----------------------------------------------------------------------------------------\n";
    cout<<"Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout<<"----------------------------------------------------------------------------------------\n";

    cout<<"Programación 'backtracking' y 'ramificación poda'\n";
    cout<<"----------------------------------------------------------------------------------------\n";

	cout << "\nIngresa el numero filas >";cin >> m; cout << "\n";
	cout << "\nIngresa el numero columnas >";cin >> n; cout<< "\n";
	cout << "Ingresa el valor de cada moneda (uno por linea) >"; cout << "\n";
	
	int matrix[m][100];
	for (int i = 0; i < m; ++i) for(int j = 0; j < n; j++) cin >> matrix[i][j];
	cout << "\n";

	cout << "backtracking: \n";
	backtracking(matrix);

	cout << "\n\nramificación y poda: \n";
	rampoda(matrix);

	cout<<"\n\n";

}