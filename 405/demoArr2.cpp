#include <iostream>
#include "stdlib.h"
#include "Array2.h"
using namespace std;

int main(){
	Array arr1(10);
	//arr1.printInfo().setLen(5).printInfo();
	arr1.printInfo()->setLen(5)->printInfo();
	//cout<<"len ="<<arr1.getLen()<<endl;
	system("pause");
	return 0;
}