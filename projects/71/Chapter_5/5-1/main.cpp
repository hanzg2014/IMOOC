#include <iostream>

using namespace std;


template<typename T>
int binarySearch(T arr[], int n, T target){	//arr[] 是有序的	
	//arr[l...r]中查找target
	int l = 0, r = n - 1;
	while(l<=r){
		//int mid = (l+r)/2;	//有溢出風險
		int mid = l+(r-l)/2;
		if(target==arr[mid])	//l==r 的時候也成立
			return mid;
		else{
			if(target < arr[mid]){
				r = mid - 1;
			}
			if(target > arr[mid]){
				l = mid + 1;
			}
		}
	}
}

int main(){
	
	return 0;
}