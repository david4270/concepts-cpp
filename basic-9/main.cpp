//Hash tables WITHOUT STL functions - chaining

#include <iostream>
#include "func.h"

using namespace std;

int main(){
    HashTable names;
    names.insertElement("David Song");
    names.insertElement("Ian Webster");
    names.insertElement("Jun Ho Sung");
    names.printTable();
    names.insertElement("Yixin Tian");
    names.printTable();
    names.insertElement("Mymy Tran");
    names.printTable();
    names.deleteElement("David Song");
    names.printTable();

    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   