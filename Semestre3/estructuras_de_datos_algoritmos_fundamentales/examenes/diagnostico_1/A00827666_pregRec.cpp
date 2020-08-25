// Matricula: A00827666
// Nombre: Abraham Cepeda Oseguera
#include <iostream>
using namespace std;

// Complejidad: O(n)
int sumaRecursivaCuadrada(int n){
	return n > 0 ? n*n+sumaRecursivaCuadrada(n-1) : n;
}

int main(){
	int n;
	cin >> n;
	cout << sumaRecursivaCuadrada(n) << endl;
}