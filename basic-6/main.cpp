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
    int * origArr;
    int tmp;
    int menu;
    int size = 10;
    
    while(1){
        
        origArr = new int[size];

        for(int i = 0; i < size; i++){
            cout << "Insert number: ";
            cin >> tmp;
            origArr[i] = tmp;
        }

        cout << "Your array is: ";
        for(int i = 0; i < size; i++){
            cout << origArr[i] << " ";
        }
        cout << endl;


        while(1){

            myArr = new int[size];

            for(int i = 0; i < size; i++){
                myArr[i] = origArr[i];
            }

            cout << "Select your sort: 1) Quick sort 2) Merge sort 3) Heap sort 4) Radix sort " << endl;
            cout << "                  5) Selection sort 6) Bubble sort 7) Insertion sort 8) Counting sort " << endl;
            cout << "                  9) Insert new array. Press any other key to exit: ";
            cin >> menu;
            
            if(menu == 1){
                //Quicksort used
                QuickSort(myArr, 0, size-1);
            }        
            else if(menu == 2){
                //Mergesort used
                MergeSort(myArr,0,size-1);
            }
            else if(menu == 3){
                //Heapsort used
                HeapSort(myArr,size);
            }
            else if(menu == 4){
                //Radixsort used
                RadixSort(myArr,size);
            }
            else if(menu == 5){
                //Selectionsort used
                SelectionSort(myArr,size);
            }
            else if(menu == 6){
                //Bubble sort(recursive)
                BubbleSort(myArr,size);
            }
            else if(menu == 7){
                //Insertion sort(recursive)
                InsertionSort(myArr,size);
            }
            else if(menu == 8){
                //Counting sort
                CountingSort(myArr,size);
            }
            else if(menu == 9){
                delete [] myArr;
                myArr = NULL;
                
                break;
            }
            else{
                delete [] myArr;
                myArr = NULL;
                delete [] origArr;
                origArr = NULL;
                
                return 0;
            }

            cout << "Your sorted array is: ";
            for(int i = 0; i < size; i++){
                cout << myArr[i] << " ";
            }
            cout << endl;

        }
        delete [] origArr;
        origArr = NULL;
    }

    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe


