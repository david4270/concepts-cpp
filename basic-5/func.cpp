#include <iostream>
#include "func.h"

using namespace std;

Complex::Complex(){
    real = 0.0;
    imag = 0.0;
}

Complex::Complex(double r, double i){
    real = r;
    imag = i;
}

Complex::~Complex(){}

double Complex::getReal() const{
    return real;
}

double Complex::getImag() const{
    return imag;
}

void Complex::setReal(double r){
    real = r;
}

void Complex::setImag(double i){
    imag = i;
}

void Complex::print() const{
    cout << real << " + " << imag << "j" << endl;
}

Complex Complex::operator+(const Complex & rhs) const{
    Complex sum;
    sum.real = real + rhs.real;
    sum.imag = imag + rhs.imag;
    return sum;
}

Complex Complex::operator-(const Complex & rhs) const{
    Complex sum;
    sum.real = real - rhs.real;
    sum.imag = imag - rhs.imag;
    return sum;
}

Complex Complex::operator*(const Complex & rhs) const{
    Complex sum;
    sum.real = (real * rhs.real) - (imag * rhs.imag);
    sum.imag = (imag * rhs.real) + (real * rhs.imag);
    return sum;
}

Complex Complex::operator/(const Complex & rhs) const{
    Complex sum;
    double magnitude = (rhs.real * rhs.real) + (rhs.imag * rhs.imag);
    sum.real = (real * rhs.real) + (imag * rhs.imag);
    sum.real = sum.real/magnitude;
    sum.imag = (imag * rhs.real) - (real * rhs.imag);
    sum.imag = sum.imag/magnitude;
    return sum;
}

bool Complex::operator==(const Complex & rhs) const{
    return (real==rhs.real && imag == rhs.imag);
}

ostream& operator<<(ostream &os, const Complex &x){
    os << x.getReal() << " + " << x.getImag() << "j" << endl;
    return os;
}

istream& operator>>(istream &is, Complex & c){
    double r,i;
    is >> r >> i;
    c.setReal(r);
    c.setImag(i);
    return is;
}