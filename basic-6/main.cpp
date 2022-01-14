// Recursive sort. Use some of algo as well?

//https://www.geeksforgeeks.org/sorting-algorithms/ 
//Quicksort [V]
//Mergesort
//Heapsort
//Radix sort
//Selection sort
//Bubble sort(recursive)
//Insertion sort(recursive)
//Counting sort

#include <iostream>
#include "func.h"

using namespace std;

int main(){
    //put everything into while loop?
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
    //QuickSort(myArr, 0, size-1);

    //Mergesort used
    //MergeSort(myArr,0,size-1);

    //Heapsort used
    //HeapSort(myArr,size);

    //Radixsort used

    //Selectionsort used
    SelectionSort(myArr,size);

    //Bubble sort(recursive)
    //BubbleSort(myArr,size);

    //Insertion sort(recursive)
    //InsertionSort(myArr,size);

    //Counting sort
    //CountingSort(myArr,size);



    cout << "Your sorted array is: ";
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


