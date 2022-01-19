//Inheritance Basic -  products, parts and subparts

#include <iostream>
#include "func.h"

using namespace std;

int main(){

    FullContact David("David Song", 1999, 7, 24, false,"david990724@gmail.com",
                    "29 Galleria Parkway, Thornhill, ON", 'M',"Galaxy Note 10+",
                    "2356326462354234523","647-807-2473");
    David.print();
    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   