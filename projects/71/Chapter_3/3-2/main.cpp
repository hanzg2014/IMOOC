#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#define N 50000
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
        T elem = arr[i];
        int j;
        for(j=i; (j>0)&&(arr[j-1]>elem); j--){
                arr[j]=arr[j-1];
        }
        arr[j]=elem;
    }
}



/*
template<typename T>
void insertionSort(T arr[], int len){
    for(int i =1; i<len; i++){
        for(int j=i; j>0 && (arr[j-1]>arr[j]); j--){
            swap(arr[j-1],arr[j]);
        }
    }
}
*/

// arr[l...mid] 和 arr[mid+1...r]進行合併
template<typename T>
void __merge(T arr[], int l, int mid, int r){  
    //cout<<"__merge: "<<l<<","<<mid<<","<<r<<endl;
    T aux[r-l+1];
    for(int i=l; i<=r; i++){    //Array Copy 
        aux[i-l] = arr[i];
    } 
    int i = l;
    int j = mid +1;
    for(int k=l; k<=r; k++){
        if(i>mid){      //左邊已經超過的話, copy右邊， ^*^還可以優化
            arr[k] = aux[j-l];
            j++;
        }else{
            if(j>r){        //右邊已經超過的話, copy左邊， ^*^還可以優化
                arr[k] = aux[i-l];
                i++;
            }else{
                if(aux[i-l]<aux[j-l]){
                    arr[k] = aux[i-l];
                    i++;
                }
                else{
                    arr[k] = aux[j-l];
                    j++;
                }
            }
        }
    }
}


//遞歸使用__mergeSort, 對arr[l...r]的範圍內進行排序
//__mergeSort 加上"__", 私有函數可以，但是不應該被用戶所調用 (Pythonic)
template<typename T>
void __mergeSort(T arr[], int l, int r){
    //cout<<"__mergeSort: "<<l<<","<<r<<endl;
    if(l>=r){    //數組為空，或者只有一個元素
        return;
    }
    int mid = (l+r)/2; // l+r 可能會有溢出風險
    __mergeSort(arr, l, mid); 
    __mergeSort(arr, mid+1, r); 
    __merge(arr, l, mid, r); 
}

template<typename T>
void mergeSort(T arr[], int len){

    __mergeSort(arr, 0, len-1);   //0 開始的位置， n -1 結束的位置
}

int main() {
    //int arr[] = {4,3,6,7,8,1};
    //SortTestHelper::printArr(arr,6);
    //mergeSort(arr, 6);
    int *arr1 = SortTestHelper::generateRandomArray(N,0,N);
    //int *arr1 = SortTestHelper::generateNearlyOrderedArray(N, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr1, N);
    int *arr3 = SortTestHelper::copyIntArray(arr1, N);
    
    SortTestHelper::testSort("Selection Sort", selectionSort,arr1,N);
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr2,N);
    SortTestHelper::testSort("Merge Sort", mergeSort,arr3,N);

    //SortTestHelper::printArr(arr,6);

    delete[] arr1;
    arr1 = NULL;
    delete[] arr2;
    arr2 = NULL;
    delete[] arr3;
    arr3 = NULL;

    return 0;
}