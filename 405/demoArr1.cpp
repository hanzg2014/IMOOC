#include <iostream>
#include "stdlib.h"
#include "Array1.h"
using namespace std;

int main(){
	Array arr1(5);
	Array arr2(arr1);

//	arr1.printAddr();
//	arr2.printAddr();
	arr1.printArr();
	arr2.printArr();

	system("pause");
	return 0;
}