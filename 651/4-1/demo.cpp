#include "List.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void)
{
	Node node1;
	Node node2;
	
	List *pList = new List();

	node1.data.name = "tester1";
	node1.data.phone = "12345";


	node2.data.name = "tester2";
	node2.data.phone = "23456";

	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	
	pList->ListTraverse();
	delete pList;
	pList = NULL;
	system("pause");
	return 0;
}
