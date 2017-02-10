#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#define N 10000
#define ARR_LEN(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;


template <typename T>
void selectionSort(T arr[], int len){
    int minIndex;
    for (int i=0; i<len-1; i++){
        minIndex = i;
        for(int j=i+1; j<len; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

template<typename T>
void insertionSort(T arr[], int len){
    for(int i =1; i<len; i++){
        for(int j=i; j>0 && (arr[j-1]>arr[j]); j--){
            swap(arr[j-1],arr[j]);
        }
    }
    return;
}

int main() {
    int *arr1 = SortTestHelper::generateRandomArray(N,0,N);
    int *arr2 = SortTestHelper::copyIntArray(arr1, N);

    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,N);
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,N);

    delete[] arr1;
    arr1 = NULL;
    delete[] arr2;
    arr2 = NULL;

    return 0;
}