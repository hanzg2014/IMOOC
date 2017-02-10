#ifndef SELECTIONSORT_TESTHELPER_H
#define SELECTIONSORT_TESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
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
}


#endif