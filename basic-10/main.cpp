//Exception Handling

#include <iostream>
#include "func.h"

using namespace std;

int main(){
    //Ontario legal age verification
    int yr,mo,dy;
    cout << "When is your birthday? Type in yyyy mm dd: ";
    cin >> yr >> mo >> dy;
    if(canDrinkorDrive(yr,mo,dy)){
        cout << "Horray!" << endl;
    }

    //Input string
    string ipt;
    cout << "Type string, less than 10 characters: ";
    cin >> ipt;
    inputStr(ipt);

    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   