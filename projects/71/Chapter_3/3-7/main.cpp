#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#define N 100000
#define SWAP_TIMES	100
#define ARR_LEN(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;


/****************************************************/

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

/****************************************************/

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

template<typename T>
void insertionSort(T arr[], int l, int r){
    for(int i=l+1; i<=r; i++){
        T elem = arr[i];
        int j;
        for(j=i; j>l&&arr[j-1]>elem; j--){
                arr[j]=arr[j-1];
        }
        arr[j]=elem;
    }
}

/****************************************************/
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
    if(r-l<=15){    //數組為空，或者只有一個元素
    	insertionSort(arr, l, r);
        return;
    }else{
    	int mid = (l+r)/2; // l+r 可能會有溢出風險
    	__mergeSort(arr, l, mid); 
    	__mergeSort(arr, mid+1, r); 
   		if(arr[mid]>arr[mid+1]){	//這個時候才需要再進行一次 __merge 操作
   			__merge(arr, l, mid, r);   
   		}  
   	} 
}

template<typename T>
void mergeSort(T arr[], int len){

    __mergeSort(arr, 0, len-1);   //0 開始的位置， n -1 結束的位置
}



template<typename T>
//Bottom Up
void mergeSortBU(T arr[], int len){
    int size;
    int i;
    for(size=1; size<len; size+=size){
        //第一部分[i...i+size-1]不能越界
        for(i=0; i+size<len; i+=2*size){
            ///i+size+size-1 不能越界
            __merge(arr, i, i+size-1, min(i+2*size-1, len-1));
        }
    }
}

/*********************************************/

template<typename T>
//arr[l...p-1]<arr[p]<arr[p+1...r]
int __partition2(T arr[], int l, int r){
    //隨機生成一個索引
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    int i = l + 1;  //arr[l+1...i) <=v 
    int j = r;  //arr(j...r] <=v 
    //v =  arr[j]
    //arr[l+1...j]<v; arr[j+1...i)>v
    while(true){
        while(i<=r&&arr[i]<v) i++;
        while(j>=l&&arr[j]>v) j--;
        if(i>j) break;
        swap(arr[i++],arr[j--]);
    }
    swap(arr[l],arr[j]);    //arr[j]是小於v的
    return j;
}

template<typename T>
void __quickSort2(T arr[], int l, int r){
    if(r - l <=15){
        insertionSort(arr, l, r);
        return;
    }
    int p = __partition2(arr, l, r);
    __quickSort2(arr,l,p-1);
    __quickSort2(arr,p+1,r);
}

template<typename T>
void quickSort2(T arr[], int len){
    srand(time(NULL));
    __quickSort2(arr, 0, len-1);
}

/*********************************************/

template<typename T>
//arr[l...p-1]<arr[p]<arr[p+1...r]
int __partition(T arr[], int l, int r){
    //隨機生成一個索引
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int j = l;  //position of the selected standard element
    //v =  arr[j]
    //arr[l+1...j]<v; arr[j+1...i)>v
    for(int i =l+1; i<=r; i++){
        if(arr[i]<v){
            //++j
            swap(arr[i], arr[++j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r){
    if(r - l <=15){
        insertionSort(arr, l, r);
        return;
    }
    int p = __partition(arr, l, r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}

template<typename T>
void quickSort(T arr[], int len){
    srand(time(NULL));
    __quickSort(arr, 0, len-1);
}

/*
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
*/

int main() {

    //int arr[] = {4,3,6,7,8,1};
    //SortTestHelper::printArr(arr,6);
    //mergeSort(arr, 6);
    int *arr1 = SortTestHelper::generateRandomArray(N,0,10);
    //int *arr1 = SortTestHelper::generateNearlyOrderedArray(N, SWAP_TIMES);
    //int *arr2 = SortTestHelper::copyIntArray(arr1, N);
    int *arr3 = SortTestHelper::copyIntArray(arr1, N);
    //int *arr4 = SortTestHelper::copyIntArray(arr1, N);
    int *arr5 = SortTestHelper::copyIntArray(arr1, N);
    int *arr6 = SortTestHelper::copyIntArray(arr1, N);
    
    //SortTestHelper::testSort("Selection Sort: ", selectionSort,arr1,N);
    //SortTestHelper::testSort("Insertion Sort: ", insertionSort,arr2,N);
    SortTestHelper::testSort("Merge Sort: ", mergeSort,arr3,N);
    //SortTestHelper::testSort("Merge Sort Bottom Up: ", mergeSortBU,arr4,N);
    //SortTestHelper::testSort("Quick Sort: ", quickSort,arr5,N);
    SortTestHelper::testSort("Quick Sort: ", quickSort,arr5,N);
    SortTestHelper::testSort("Quick Sort2: ", quickSort2,arr6,N);

    //SortTestHelper::printArr(arr,6);
    /*
    delete[] arr1;
    arr1 = NULL;
    delete[] arr2;
    arr2 = NULL;
    delete[] arr3;
    arr3 = NULL;
    delete[] arr4;
    arr4 = NULL;
    delete[] arr5;
    arr5 = NULL;
    */

    return 0;
}