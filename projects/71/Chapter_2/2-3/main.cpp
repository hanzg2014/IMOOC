#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#define N 10000
#define ARR_LEN(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

template <typename T>
void printArr(T arr[], int len){
	for(int i=0;i<len; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


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

int main(void){
	int *arr = SortTestHelper::generateRandomArray(N,N,0);
	//int array[5]={1,6,3,0,5};
	float array[5]={1.0,6.0,3.0,0.0,5.0};
	//string array[5]={"A","C","B","E","D"};
	//Student arr[4] = {{"D",90},{"C",100},{"B", 95},{"A",95}};

	cout<<"Before sorting: "<<endl;
	printArr(arr, N);
	selectionSort(arr, N);
	//selectionSort(arr, ARR_LEN(arr));
	cout<<"After sorting: "<<endl;
	printArr(arr, N);

	delete[] arr;
	arr = NULL;

	return 0;
}