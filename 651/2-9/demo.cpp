#include <stdlib.h>
#include "List.h"
#include <iostream>
using namespace std;

int main(void)
{
	List *list1 = new List(10);

	// 3 5 7 2 9 1 8
	Coordinate e1(3,5);
	Coordinate e2(5,7);
	Coordinate e3(6,8);

	//the versatile temp
	Coordinate temp(0,0);

	list1->ListInsert(0,&e1);
	list1->ListInsert(1,&e2);
	list1->ListInsert(2,&e3);


	// 3 5 7 8 2 9 1
	list1->ListTraverse();


	delete list1;
	list1 = NULL;	

	system("pause");
	return 0;
}