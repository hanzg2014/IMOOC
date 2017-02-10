#include <stdlib.h>
#include "List.h"
#include <iostream>
using namespace std;

int main(void)
{
	Node node1;
	Node node2;
	Node node3;
	Node node4;
	Node node5;

	node1.data = 3;
	node2.data = 4;
	node3.data = 5;
	node4.data = 6;
	node5.data = 7;

	Node temp;

	List *pList = new List();

/*
	pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	*/
	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node4);

	pList->ListInsert(1,&node5);

	pList->GetElem(1, &temp);


	//pList->ListDelete(1, &temp);

	temp.printNode();

	pList->ListTraverse();

	delete pList;
	pList = NULL;
	system("pause");
	return 0;
}