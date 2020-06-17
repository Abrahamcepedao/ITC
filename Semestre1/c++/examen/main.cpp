// Abraham Cepeda Oseguera
// A00827666
// Examen
#include <iostream>
#include "Empleado.h"
using namespace std;

void printEmpleados(Empleado emp){
    cout << "<----------Datos de un empleado---------->\n\n"; 
    cout << "Nombre:  " << emp.getNombreEmp() << endl;
    cout << "Sueldo:  " << emp.getSueldoEmp() << endl;
    cout << "Categoria:  " << emp.getCategoriaEmp() << endl;
    cout << "<---------------------------------------->\n\n";
}

int main(){
    Empleado emp1 = Empleado("Alex", 10000, 'A');
    Empleado emp2 = Empleado("Sofia", 12000, 'B');
    printEmpleados(emp1);
    printEmpleados(emp2);
    emp1.promoverEmpleado('C');
    printEmpleados(emp1);
    return 0;
}