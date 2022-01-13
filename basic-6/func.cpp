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
...
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
<<Mergesort>> Reference: https://www.geeksforgeeks.org/merge-sort/ and https://www.programiz.com/dsa/merge-sort
Array given: [26,33,35,29,19,24,36]
    Get middle -> 0 + (6-0)/2 = 3 (index)
    [26,33,35,29]        [19,24,36]      -> Divided
    [26,33]  [35,29]     [19,24] [36]    -> Divided
    [26] [33] [35] [29]  [19] [24] [36]  -> Divided
    [26,33]    [29,35]     [19,24]  [36] -> created sorted array and merge
      [26,29,33,35]          [19,24,36]  -> created sorted array and merge
        [19,24,26,29,33,35,36]           -> created sorted array and merge
*/

void MergeSort(int* arr, int left, int right){
    int middle = left + (right - left)/2;
    if(right <= left) return;
    cout << middle << endl;
    MergeSort(arr,left,middle);
    MergeSort(arr,middle+1,right);
    Merge(arr,left,middle,right);
}

void Merge(int* arr, int left, int middle, int right){
    int* lftarr = new int[middle-left+1];
    int* rgtarr = new int[right-middle];
    int lftptr = 0;
    int rgtptr = 0;
    int arrptr = left;
    
    for(int i = 0; i < middle-left+1; i++){
        lftarr[i] = arr[left+i];
    }

    for(int i = 0; i < right-middle; i++){
        rgtarr[i] = arr[middle+1+i];
    }

    while((lftptr < (middle-left+1)) && (rgtptr < (right-middle))){
        if(lftarr[lftptr] <= rgtarr[rgtptr]){
            cout << lftarr[lftptr] << " ";
            arr[arrptr] = lftarr[lftptr];
            lftptr++;
        }
        else{
            cout << rgtarr[rgtptr] << " ";
            arr[arrptr] = rgtarr[rgtptr];
            rgtptr++;
        }
        arrptr++;
    }

    while(lftptr < (middle-left+1)){
        cout << lftarr[lftptr] << " ";
        arr[arrptr] = lftarr[lftptr];
        arrptr++;
        lftptr++;
    }
    while(rgtptr < (right-middle)){
        cout << rgtarr[rgtptr] << " ";
        arr[arrptr] = rgtarr[rgtptr];
        arrptr++;
        rgtptr++;
    }
    cout << endl;

    delete [] lftarr;
    delete [] rgtarr;
    lftarr = NULL;
    rgtarr = NULL;
}

/*
<<Heapsort>> Reference: https://www.geeksforgeeks.org/heap-sort/ and https://medium.com/basecs/heapify-all-the-things-with-heap-sort-55ee1c93af82 
Array given: [26,33,35,29,19,24,36]
<>: removed (pushed back). (): heapify units. []: last unit - move to top
     (26)        |  Heapify   |       <36>         |             |       (26)     |  Heapify  |      <35>     |
  33      35     |   ------>  |    33      35      |   ------->  |    33     (35) | ------->  |   33      26  |
29  19  24  (36) |            |  29  19  24  [26]  |             |  29  19  24    |           | 29  19 [24]   |
                            [[26],33,35,29,19,24,<36>]                                   [[24],33,26,29,19,<35,36>]

         |     (24)     | Heapify |        33     |  Heapify |     <33>    |
 ------> |  (33)    26  | ------> |   (24)    26  |  ------> |   29    26  |  ...
         | 29  19       |         | (29) 19       |          | 24 [19]     |
                                                        [[19],29,26,24,<33,35,36>]
*/



//Radix sort


//Selection sort


//Bubble sort(recursive)


//Insertion sort(recursive)


//Counting sort




