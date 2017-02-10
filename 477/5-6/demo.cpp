#include <stdlib.h>
#include <iostream>
#include "MyArray.h"
using namespace std;

int main(void)
{
		
	//template <typename T, int KSize, int KVal>
	MyArray<int, 5, 6> arr; //
	arr.display();

	system("pause");
	return 0;
}