// Recursive sort. Use some of algo as well?

#include <iostream>
#include "func.h"

using namespace std;

int main(){

    int * myArr;
    int tmp;
    int size = 10;
    myArr = new int[size];
    for(int i = 0; i < size; i++){
        cout << "Insert number: ";
        cin >> tmp;
        myArr[i] = tmp;
    }

    cout << "Your array is: ";
    for(int i = 0; i < size; i++){
        cout << myArr[i] << " ";
    }
    cout << endl;

    //Quicksort used
    QuickSort(myArr, 1, size);

    cout << "Your array is: ";
    for(int i = 0; i < size; i++){
        cout << myArr[i] << " ";
    }
    cout << endl;

    delete [] myArr;
    myArr = NULL;

    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe

//Mergesort
//Heapsort
//Quicksort
//Radix sort
//Selection sort
