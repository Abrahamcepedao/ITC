#include <iostream>
using namespace std;
class Complejo{
    private:
        double real, imaginary;
    public:
        // constructores
        Complejo();
        Complejo(double r, double i);
        // get methods
        double getReal();
        double getImaginary();
        // set methods
        void setReal(double r);
        void setImaginary(double i);
        // other methods
        Complejo suma(Complejo c2);
        void printComplejo();
};
// constructores
Complejo::Complejo(){
    double real = 0;
    double imaginary = 0;
}
Complejo::Complejo(double r, double i){
    real = r;
    imaginary = i;
}

// get methods
double Complejo::getReal(){
    return real;
}
double Complejo::getImaginary(){
    return imaginary;
}
// set methods
void Complejo::setReal(double r){
    real = r;
}
void Complejo::setImaginary(double i){
    imaginary = i;
}
// other methods
Complejo Complejo::suma(Complejo c2){
    double newReal = real + c2.getReal();
    double newImaginary = imaginary + c2.getImaginary();
    Complejo newComplejo(newReal, newImaginary);
    return newComplejo;
}
void Complejo::printComplejo(){
    cout << real << " + " << imaginary << "i\n";
}
