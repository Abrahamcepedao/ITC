#include <cmath>
#ifndef Complejo_h
#define Complejo_h

class Complejo{
    public:
        Complejo() { real = 0; imag = 0; };
        Complejo(double r, double i) { real = r; imag = i;};

        void setReal (double r) { real = r; };
        void setImag (double i) { imag = i; };

        double getReal () { return real; };
        double getImag () { return imag; };

        void muestra();
        Complejo suma (Complejo c1);
        Complejo operator+(Complejo c2);
        Complejo operator-(Complejo c2);
        Complejo operator++();
        Complejo operator*(Complejo c2);
        bool operator>(Complejo c2);
        bool operator==(Complejo otro);
    private:
        double real, imag;
};
Complejo Complejo:: suma (Complejo c1) {
    Complejo res;
    res.real = this->real + c1.real;
    res.imag = this->imag + c1.imag;
    return res;
}
void Complejo:: muestra() {
    cout << real << " + " << imag << "i ";
}
Complejo Complejo::operator+(Complejo c2) {
    int realN = this->real + c2.real;
    int imagN = this->imag + c2.imag;
    Complejo nuevo(realN, imagN);
    return nuevo;
}
Complejo Complejo::operator-(Complejo c2) {
    int realN = real - c2.real;
    int imagN = imag - c2.imag;
    Complejo nuevo(realN, imagN);
    return nuevo;
}
Complejo Complejo::operator++() {
    this->real++;
    this->imag++;
    return *this;
}
bool Complejo::operator==(Complejo otro) {
    if (real == otro.real && imag == otro.imag)
        return true;
    else
        return false;
}

Complejo Complejo::operator*(Complejo c2){
    int real = real * c2.real - imag * c2.imag;
    int imag = real * c2.imag + imag * c2.real;
    Complejo nuevoCom(real, imag);
    return nuevoCom;
}

bool Complejo::operator>(Complejo c2){
    double norma1 = sqrt(pow(real,2)+pow(imag,2));
    double norma2 = sqrt(pow(c2.real,2)+pow(c2.imag,2));
    return (norma1 > norma2);
}

 

#endif /* Complejo_h */