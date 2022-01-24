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

    for(int i = left; i < right; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int SelectAndShuffule(int * arr, int left, int right){
    int ls = left;
    int tmp;

    //For each i from left+1 to right, if arr[i] <= arr[left]
    //move ls(pivot) by 1, and swap arr[i] and arr[ls]
    for(int i = left+1; i <= right; ++i){
        if(arr[i] <= arr[left]){
            ls = ls+1;
            tmp = arr[i];
            arr[i] = arr[ls];
            arr[ls] = tmp;
        }
    }

    //After traversal, swap arr[left] and arr[ls]
    tmp = arr[left];
    arr[left] = arr[ls];
    arr[ls] = tmp;

    //return ls as pivot
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
    //cout << middle << endl;
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
    
    //Left to middle - copy left array
    for(int i = 0; i < middle-left+1; i++){
        lftarr[i] = arr[left+i];
    }

    //middle to right - copy right array
    for(int i = 0; i < right-middle; i++){
        rgtarr[i] = arr[middle+1+i];
    }

    //while lftptr (left pointer) < middle-left+1 and rgtptr (right pointer) < right-middle
    while((lftptr < (middle-left+1)) && (rgtptr < (right-middle))){

        //if lftarr[lftptr] <= rgtarr[rgtptr], fill arr[arrptr] from left array, and add 1 to lftptr
        if(lftarr[lftptr] <= rgtarr[rgtptr]){
            cout << lftarr[lftptr] << " ";
            arr[arrptr] = lftarr[lftptr];
            lftptr++;
        }
        //if lftarr[lftptr] > rgtarr[rgtptr]. fill arr[arrptr] from right array, and add 1 to rgtptr
        else{
            cout << rgtarr[rgtptr] << " ";
            arr[arrptr] = rgtarr[rgtptr];
            rgtptr++;
        }
        //Anyway...add arrptr
        arrptr++;
    }
    //when lftarr remains, add lftarr elements to array
    while(lftptr < (middle-left+1)){
        cout << lftarr[lftptr] << " ";
        arr[arrptr] = lftarr[lftptr];
        arrptr++;
        lftptr++;
    }
    //when rgtarr remains, add rgtarr elements to array
    while(rgtptr < (right-middle)){
        cout << rgtarr[rgtptr] << " ";
        arr[arrptr] = rgtarr[rgtptr];
        arrptr++;
        rgtptr++;
    }

    //Since merge is performed from one-element arrays, array is being automatically sorted in merging process

    cout << endl;

    delete [] lftarr;
    delete [] rgtarr;
    lftarr = NULL;
    rgtarr = NULL;
}

/*
<<Heapsort>> Reference: https://www.geeksforgeeks.org/heap-sort/W
Array given: [26,33,35,29,19,24,36]
<>: removed (pushed back). (): heapify units. []: last unit - move to top
      26     | Rearrange |     (26)     | Rearrange |      <36>     | Swap  |     <35>   | Swap  |    (24)   |
  33    (35) | --------> |   33    (36) | --------> |   33      26  | ----> |   33   26  | ----> |  (33)  26 | 
29  24 (36)  |   i=2     | 29  24 35    |   i=0     | 29  24 [35]   |       | 29 [24]    |       | 29        |

 Maxheap |    <33>   | Swap  |   <29>   | Swap  |   <26> | End   |  <24> |
-------> |  24   26  | ----> | 24  [26] | ----> | 24     | ----> |       |
         |[29]       |       |          |       |        |       |       |

*/

void heapify(int * arr, int size, int idx){
    //Set maximum element
    int maxi = idx;
    if(idx*2+1 < size && arr[idx*2+1] > arr[maxi]){
        maxi = idx*2+1;
    }
    if(idx*2+2 < size && arr[idx*2+2] > arr[maxi]){
        maxi = idx*2+2;
    }
    if(maxi != idx){
        swap(arr[idx],arr[maxi]);

        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        heapify(arr,size,maxi);
    }
}

void HeapSort(int * arr, int size){
    //Rearrange array (Rearrange) - except bottom of the heap
    for(int i = (size/2)-1; i>=0 ; i--){
        heapify(arr,size,i);
    }

    for(int i = size-1; i>0; i--){
        //Move maximum to the end of the array (Swap)
        swap(arr[0],arr[i]);
        //Max heapify (Maxheap)
        heapify(arr,i,0);
    }
    
}

/*
<<Radix sort>> Reference: https://www.geeksforgeeks.org/radix-sort/
Array given: [32,56,23,16,48,72,88,160,21]
0) Get the most significant digit -> 3 (160)
1) sort by least significant digit
[160,21,32,72,23,56,16,48,88]
2) sort by second least significant digit
[16,21,23,32,48,56,160,72,88]
3) sort by third least significant digit
[16,21,23,32,48,56,72,88,160]
*/

int getMaxSig(int* arr, int size){
    int maxi = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}

//Counting sort modified for radix sort
void countRdxSort(int * arr, int size, int exp){
    int max = 10;
    int * c = new int [max]();
    int * b = new int [size]();

    for(int j=0; j<size; j++){
        c[(arr[j]/exp)%10] = c[(arr[j]/exp)%10] + 1;
    }
    
    for(int i=1; i<max; ++i){
        c[i] = c[i] + c[i-1];
    }

    for(int j = size-1; j >= 0; j--){
        b[c[(arr[j]/exp)%10]-1] = arr[j];
        c[(arr[j]/exp)%10] = c[(arr[j]/exp)%10] - 1;
    }

    for(int j=0; j<size; j++){
        arr[j] = b[j];
    }
    
    delete [] c;
    c = NULL;
}

void RadixSort(int * arr, int size){
    int maxi = getMaxSig(arr,size);
    for (int exp = 1; maxi/exp > 0; exp *=10){
        countRdxSort(arr,size,exp);

        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}


/*
<<Selection sort>> Reference: https://www.geeksforgeeks.org/selection-sort/
Array given: [4,3,2,10,12,1,5,6]
Round 1: Find minimum element of arr[0:7] and place at the beginning of arr[0:7]
[1,3,2,10,12,4,5,6]
Round 2: Find minimum element of arr[1:7] and place at the beginning of arr[1:7]
[1,2,3,10,12,4,5,6]
Round 3: Find minimum element of arr[2:7] and place at the beginning of arr[2:7]
[1,2,3,10,12,4,5,6]
Round 4: Find minimum element of arr[3:7] and place at the beginning of arr[3:7]
[1,2,3,4,12,10,5,6]
Round 5: Find minimum element of arr[4:7] and place at the beginning of arr[4:7]
[1,2,3,4,5,10,12,6]
Round 6: Find minimum element of arr[5:7] and place at the beginning of arr[5:7]
[1,2,3,4,5,6,12,10]
Round 7: Find minimum element of arr[6:7] and place at the beginning of arr[6:7]
[1,2,3,4,5,6,10,12]
*/

void SelectionSort(int * arr, int size){
    int minidx;
    for (int i = 0; i < size-1; i++){
        minidx = i;
        for(int j = i+1; j< size; j++){
            if(arr[minidx] > arr[j]){
                minidx = j;
            }
        }
        swap(arr[minidx], arr[i]);

        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

/*
<<Bubble sort(recursive)>> Reference: https://www.geeksforgeeks.org/recursive-bubble-sort/
Array given: [4,3,2,10,12,1,5,6]
Round 1 
[(4,3),2,10,12,1,5,6] 4>3
[3,(4,2),10,12,1,5,6] 4>2
[3,2,(4,10),12,1,5,6] 4<10
[3,2,4,(10,12),1,5,6] 10<12
[3,2,4,10,(12,1),5,6] 12>1
[3,2,4,10,1,(12,5),6] 12>5
[3,2,4,10,1,5,(12,6)] 12>6
Round 2
[(3,2),4,10,1,5,6,12] 3>2
[2,(3,4),10,1,5,6,12] 3<4
[2,3,(4,10),1,5,6,12] 4<10
[2,3,4,(10,1),5,6,12] 10>1
[2,3,4,1,(10,5),6,12] 10>5
[2,3,4,1,5,(10,6),12] 10>6
[2,3,4,1,5,6,(10,12)] 10<12
...
*/

void BubbleSort(int * arr, int size){
    if(size == 1) return;
    for(int i = 0; i < size-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    BubbleSort(arr,size-1);
}


/*
<<Insertion sort(recursive)>> Reference: https://www.geeksforgeeks.org/recursive-insertion-sort/ 
Array given: [4,3,2,10,12,1,5,6]
Compare with previous elements
[4,(3),2,10,12,1,5,6]
[3,4,(2),10,12,1,5,6]
[2,3,4,(10),12,1,5,6]
[2,3,4,10,(12),1,5,6]
[2,3,4,10,12,(1),5,6]
[1,2,3,4,10,12,(5),6]
[1,2,3,4,5,10,12,(6)]
[1,2,3,4,5,6,10,12]
*/

void InsertionSort(int * arr, int size){
    if(size <= 1) return;

    InsertionSort(arr,size-1);
    int last = arr[size-1]; //backup last element of arr
    int j = size-2;

    while(j >=0 && arr[j] > last){ //while front element is larger
        arr[j+1] = arr[j]; //update arr -> push back by 1
        j--;
    }
    arr[j+1] = last;
    
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


/*
<<Counting sort>> Reference: https://www.geeksforgeeks.org/counting-sort/
Array given: [2,6,4,2,3,4,1,2]
   0,1,2,3,4,5,6
c [0,1,3,1,2,0,1]
c [0,1,4,5,7,7,8]
b [1,2,2,2,3,4,4,6]
*/

void CountingSort(int * arr, int size){
    int max = 1000;

    int * c = new int [max]();
    int * b = new int [size]();

    for(int j=0; j<size; j++){
        c[arr[j]] = c[arr[j]] + 1;
    }
    
    for(int i=1; i<max; ++i){
        c[i] = c[i] + c[i-1];
    }

    for(int j=0; j < size; j++){
        b[c[arr[j]]-1] = arr[j];
        c[arr[j]] = c[arr[j]] - 1;
    }

    for(int j=0; j<size; j++){
        arr[j] = b[j];
    }
    
    delete [] c;
    c = NULL;
}



