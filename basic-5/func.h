#ifndef _func_h
#define _func_h

#include <iostream>
#include <vector>

using namespace std;

class Complex{
    private:
        double real;
        double imag;
    public:
        Complex();
        Complex(double r, double i);
        ~Complex();
        
        double getReal() const;
        double getImag() const;
        void setReal(double r);
        void setImag(double i);

        Complex operator+ (const Complex & rhs) const;
        Complex operator- (const Complex & rhs) const;
        Complex operator* (const Complex & rhs) const;
        Complex operator/ (const Complex & rhs) const;
        bool operator== (const Complex & rhs) const;

        void print() const;

    friend ostream& operator<<(ostream& os, const Complex &x);
    friend istream& operator>>(istream& is, Complex &c);
};

#endif