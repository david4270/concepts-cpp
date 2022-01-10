//Operator Overloading - complex numbers

#include <iostream>
#include <vector>
#include "func.h"

using namespace std;

int main(){
    
    cout << "sample" << endl;
    Complex a(3,4);
    Complex b(2,5);
    Complex c;
    Complex d;
    Complex e;
    Complex f;
    Complex g;
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

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    
    vector<Complex> complexSeries;
    char flag, flag2;
    string eqn,sub;
    int y,z;

    cout << "Welcome to complex calculator module" << endl;
    while(1){
        cout << "What do you want to do? 1. New complex to list. 2. Calculation of two complex numbers. 3. Check the storage. 4. Delete complex number" <<endl;
        cout << "Any other key = exit." << endl;
        cin >> flag;
        if(flag == '1'){
            Complex h;
            cout << "Insert your complex number - a b for a+bj: ";
            operator>>(cin,h);
            complexSeries.push_back(h);
        }
        else if(flag == '2'){
            cout <<"Insert index of first number (start 0): ";
            cin >> y;
            cout <<"Insert index of second number (start 0): ";
            cin >> z;
            cout << "Which calculation are you going to do? 1.add 2.sub 3.mul 4.div: "; 
            cin >> flag2;
            if (flag2 == '1'){
                complexSeries[y].operator+(complexSeries[z]).print();
            }
            if (flag2 == '2'){
                complexSeries[y].operator-(complexSeries[z]).print();
            }
            if (flag2 == '3'){
                complexSeries[y].operator*(complexSeries[z]).print();
            }
            if (flag2 == '4'){
                complexSeries[y].operator/(complexSeries[z]).print();
            }
            
        }
        else if(flag == '3'){
            for (int i = 0; i < complexSeries.size(); i++){
                cout << "index " << i << ": ";
                complexSeries[i].print();
            }

        }
        else if(flag == '4'){
            Complex h;
            cout << "Write down the complex number you want to remove - a b for a+bj:";
            operator>>(cin,h);
            for (int i = 0; i < complexSeries.size(); i++){
                if((complexSeries[i].getReal() == h.getReal()) && (complexSeries[i].getImag() == h.getImag())){
                    complexSeries.erase(complexSeries.begin()+i);
                }
            }            
        }
        else{
            break;
        }
    }

   
    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   