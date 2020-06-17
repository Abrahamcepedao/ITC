#include <iostream>
#include <fstream>
#include "Fraccion.h"
using namespace std;


int main(){
    ifstream archivo;
    archivo.open("operaciones.txt");
    
    Fraccion fracciones[10];
    int cant = 0; //cantidad de datos de arreglos de objetos
    int ren;
    int tOper, num1, den1, num2, den2;
    
    archivo >> ren;
    cout << ren;
    while(archivo >> tOper >> num1 >> den1 >> num2 >> den2){
        Fraccion fr1(num1, den1);
        Fraccion fr2(num2,den2);
        Fraccion fr3;
        
        if(tOper == 1){
            fr3 = fr1.sumaFracciones(fr2);
        }else{
            fr3 = fr1.multiFracciones(fr2);
        }
        fracciones[cant] = fr3;
        cant++;
    }
    archivo.close();
    for(int i = 0; i < cant; i++){
        fracciones[i].muestra();
    }
    return 0;
}