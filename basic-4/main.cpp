//Linked list-alike class + Dynamic allocation of classes

// + Maybe substitute string into char pointer? Make it intentionally harder

#include <iostream>
#include "func.h"

using namespace std;

int main(){

    PersonalInfo David("David Song", 1999, 7, 24);
    David.print();
    
    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   