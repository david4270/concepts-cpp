//Input and Output, Streams + Vectors and Pair

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "func.h"

using namespace std;

// Accept arguments!
// Example: 3 + 1 -> Returns 4
// Example: 3 Add 1 -> Returns 4
// Example: 3 Add 1 - 2 -> Returns 2

int main(){

    string inputLine;
    double output;

    getline(cin,inputLine);
    inputLine.erase(remove_if(inputLine.begin(), inputLine.end(), ::isspace), inputLine.end());
    output = calculator(inputLine);

    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   