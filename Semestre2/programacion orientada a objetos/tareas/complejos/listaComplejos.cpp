// Abraham Cepeda
// A00827666
#include <iostream>
#include <fstream>
#include "Complejo.h"
using namespace std;

int main(){
    ifstream archivo;
    archivo.open("numerosComplejos.txt");
    
    Complejo complejos[10];
    double real, imag;
    int count = 0;
    while(archivo >> real >> imag){
        complejos[count].setReal(real);
        complejos[count].setImaginary(imag);
        complejos[count].printComplejo();
        count++;
    }
    archivo.close();
    Complejo newComplejo;
    newComplejo = complejos[0];
    for(int i = 1; i < count+1; i++){
        newComplejo = newComplejo.suma(complejos[i]);
    }
    cout << "Suma: ";
    newComplejo.printComplejo();
    return 0;
}