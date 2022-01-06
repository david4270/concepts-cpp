//Multi-cpp files and class practice

#include <iostream>
#include "b2func.h"

using namespace std;

int main (){

    Day christmas(2021,12,25);
    christmas.print();

    Day myBirthday;
    myBirthday.setDay(24);
    myBirthday.setMonth(7);
    myBirthday.setYear(1999);
    myBirthday.print();

    Day yeetDay;
    yeetDay.setDMY(2021,1,31);
    yeetDay.print();

    return 0;
}

// How to compile this code
// g++ -std=c++11 -c basic-2.cpp
// g++ -std=c++11 -c b2func.cpp 
// g++ -std=c++11 basic-2.o b2func.o -o basic-2.exe   