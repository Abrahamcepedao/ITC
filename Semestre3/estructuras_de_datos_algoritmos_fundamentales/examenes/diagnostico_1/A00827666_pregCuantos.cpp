// Matricula: A00827666
// Nombre: Abraham Cepeda Oseguera
#include <iostream>

using namespace std;

// Complejidad: O(n)
int cuantos(int inf, int sup){
	int acum = 0;
	for(int i = inf; i <= sup; i++){
		if(i % 3 ==  0 && i % 5 == 0){
			acum++;
		}
	}
	return acum;
}

int main(){
	int inf, sup;
	cin >> inf >> sup;
	cout << cuantos(inf, sup) << endl;
}