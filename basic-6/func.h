#ifndef _func_h
#define _func_h

#include <iostream>

//Quicksort
void QuickSort(int* arr, int left, int right);
int SelectAndShuffule(int * arr, int left, int right);


//Mergesort
void MergeSort(int* arr, int left, int right);
void Merge(int* arr, int left, int middle, int right);

//Heapsort
void heapify(int * arr, int size, int idx);
void HeapSort(int * arr, int size);

//Radix sort
int getMaxSig(int* arr, int size);
void countRdxSort(int * arr, int size, int exp);
void RadixSort(int * arr, int size);

//Selection sort
void SelectionSort(int * arr, int size);

//Bubble sort(recursive)
void BubbleSort(int * arr, int size);

//Insertion sort(recursive)
void InsertionSort(int * arr, int size);

//Counting sort
void CountingSort(int * arr, int size);


#endif