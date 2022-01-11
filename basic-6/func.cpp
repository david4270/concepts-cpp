#include <iostream>
#include "func.h"

using namespace std;

//Quicksort
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