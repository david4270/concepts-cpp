//Operator Overloading - complex numbers

#include <iostream>
#include "func.h"

using namespace std;

int main(){

    Complex a(3,4);
    Complex b(2,5);
    Complex c;
    Complex d;
    Complex e;
    Complex f;
    Complex g;
    Complex h;
    c.setReal(5);
    c.setImag(2);

    c.print();

    d = a.operator*(b);
    e = a.operator+(b);
    f = a.operator-(b);
    g = a.operator/(b);
    if(a.operator==(b)){
        cout << "Wrong!" <<endl;
    }

    d.print();
    e.print();
    f.print();

    operator<<(cout,g);
    //cout << c;
    cout << "Insert your complex number: a b for a+bj: ";
    operator>>(cin,h);
    //cin >> h;
    h.print();

    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   