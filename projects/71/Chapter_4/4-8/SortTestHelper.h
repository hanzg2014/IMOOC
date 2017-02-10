#ifndef TESTHELPER_H
#define TESTHELPER_H

#include <iostream>
#include <ctime>
#include <algorithm>
#include <cassert>

using namespace std;

namespace SortTestHelper{

	template <typename T>
	void printArr(T arr[], int len){
	    for(int i=0;i<len; i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	//array contaning random numbers ranging between [rangeL, rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR){
		assert(rangeL<=rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for(int i=0; i<n; i++){
			arr[i] = rand()%(rangeR - rangeL +1) + rangeL;	//[rangeL, rangeR]
		}
		return arr;
	}

	int* generateNearlyOrderedArray(int n, int swapTimes){
		int *arr = new int[n];
		for(int i=0; i<n; i++){
			arr[i] = i;
		}
		srand(time(NULL));
		for(int i=0;i<swapTimes;i++){
			int posx = rand()%n;
			int posy = rand()%n;
			swap(arr[posx],arr[posy]);
		}
		return arr;
	}

	template <typename T>
	bool isSorted(T arr[], int len){
		for(int i=0; i<len-1; i++){
			if(arr[i]>arr[i+1]){
				//cout<<arr[i]<<">"<<arr[i+1]<<endl;
				return false;
			}
		}
		return true;
	}

	//sortName: 排序算法的名字
	//void(*sort): 排序算法的函數指針
	template <typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
		clock_t startTime = clock();
		sort(arr,n);
		clock_t endTime = clock();
		assert(isSorted(arr, n));
		cout<<sortName<<":"<<double(endTime - startTime)/CLOCKS_PER_SEC<<"s"<<endl;
	}

	template <typename T>
	T* copyIntArray(T a[], int len){
		T* arr = new T[len];
		copy(a, a+len, arr);
		return arr;
	}
}


#endif