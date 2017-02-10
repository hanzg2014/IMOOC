#include <stdlib.h>
#include "List.h"
#include <iostream>
using namespace std;

int main(void)
{
	List *list1 = new List(10);

	// 3 5 7 2 9 1 8
	int e1=3;
	int e2=5;
	int e3=7;
	int e4=2;
	int e5=9;
	int e6=1;
	int e7=8; 


	//the versatile temp
	int temp = 0;

	list1->ListInsert(0,&e1);
	list1->ListInsert(1,&e2);
	list1->ListInsert(2,&e3);
	list1->ListInsert(3,&e4);
	list1->ListInsert(4,&e5);
	list1->ListInsert(5,&e6);
	list1->ListInsert(3,&e7);


	// 3 5 7 8 2 9 1
	list1->ListTraverse();

	list1->PriorElem(&e4, &temp);
	cout<<"Prior is: "<<temp<<endl;
	list1->NextElem(&e4, &temp);
	cout<<"Next is: "<<temp<<endl;

	delete list1;
	list1 = NULL;	

	system("pause");
	return 0;
}