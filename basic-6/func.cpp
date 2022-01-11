#include <iostream>
#include "func.h"

using namespace std;

/*
<<Quicksort>>
Array given: [26,33,35,29,19,24,36]

Select and shuffle:
    <> is 'ls' (lastsmall), [] is 'i' (iterator)
    [<(26)>,33,35,29,19,24,36]    i=1
    [<26>,(33),35,29,19,24,36]    i=2
    [<26>,33,(35),29,19,24,36]    i=3
    [<26>,33,35,(29),19,24,36]    i=4
    [<26>,33,35,29,(19),24,36]    i=5  -> 19 < 26 (arr[i] <= arr[left])
    [26,<19>,35,29,(33),24,36]    i=5
    [26,<19>,35,29,33,(24),36]    i=6  -> 24 < 26 (arr[i] <= arr[left])
    [26,19,<24>,29,33,(35),36]    i=6
    [26,19,<24>,29,33,35,(36)]    i=7
    Now swap arr[left] with arr[ls]
    [24,19,<26>,29,33,35,36]
    Return 26

Quicksort for [24,19]
Quicksort for [29,33,35,36]

(Proceeds recursively)
*/


void QuickSort(int* arr, int left, int right){
    int pivot;
    pivot = SelectAndShuffule(arr,left,right);
    if(pivot > left) QuickSort(arr,left,pivot-1);
    if(pivot < right) QuickSort(arr,pivot+1,right);
}

int SelectAndShuffule(int * arr, int left, int right){
    int ls = left;
    int tmp;
    for(int i = left+1; i <= right; ++i){
        if(arr[i] <= arr[left]){
            ls = ls+1;
            tmp = arr[i];
            arr[i] = arr[ls];
            arr[ls] = tmp;
        }
    }
    tmp = arr[left];
    arr[left] = arr[ls];
    arr[ls] = tmp;
    return ls;
}

/*
<<Mergesort>>


*/


//Heapsort


//Radix sort


//Selection sort


//Bubble sort(recursive)


//Insertion sort(recursive)


//Counting sort




