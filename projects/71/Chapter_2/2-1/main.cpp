#include <iostream>
#include <algorithm>
#define ARR_LEN(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

void printArr(int arr[], int len){
	for(int i=0;i<len; i++){
		cout<<arr[i]<<",";
	}
	cout<<endl;
}

void selectionSort(int arr[], int len){
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
	int array[5]={1,6,3,0,5};

	cout<<"Before sorting: ";
	printArr(array, ARR_LEN(array));
	selectionSort(array, ARR_LEN(array));
	cout<<"After sorting: ";
	printArr(array, ARR_LEN(array));

	return 0;
}