#include <iostream>
using namespace std;

class Empleado{
    private:
        string nombreEmp;
        float sueldo;
        char categoriaEmp;
    public:
        Empleado();
        Empleado(string n, int s, char c);
        string getNombreEmp();
        float getSueldoEmp();
        char getCategoriaEmp();
        void setNombreEmp(string n);
        void setSueldoEmp(float s);
        void setCategoriaEmp(char c);
        void promoverEmpleado(char co);
};
//constructores
Empleado::Empleado(){
    nombreEmp = "-";
    sueldo = 0.0;
    categoriaEmp = 'A';
}
Empleado::Empleado(string n, int s, char c){
    nombreEmp = n;
    sueldo = s;
    categoriaEmp = c;
}

// get methods
string Empleado::getNombreEmp(){
    return nombreEmp;
}
float Empleado::getSueldoEmp(){
    return sueldo;
}
char Empleado::getCategoriaEmp(){
    return categoriaEmp;
}

// set methods
void Empleado::setNombreEmp(string n){
    nombreEmp = n;
}
void Empleado::setSueldoEmp(float s){
    sueldo = s;
}
void Empleado::setCategoriaEmp(char c){
    categoriaEmp = c;
}

// other methods
void Empleado::promoverEmpleado(char co){
    if(co != 'A' && co != 'B' && co != 'C'){
        cout << "Categoría inválida\n\n";
    } else{
        if(co == 'B' && categoriaEmp == 'A'){
            categoriaEmp = 'B';
            sueldo = sueldo * 1.025;
        } else if(co == 'C'){
            if(categoriaEmp == 'B'){
                sueldo = sueldo * 1.025;
            } else if(categoriaEmp == 'A'){
                sueldo = sueldo * 1.05;
            }
            categoriaEmp = 'C';
        } else{
            categoriaEmp = 'A';
        }
    }
}