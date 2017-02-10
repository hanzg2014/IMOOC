#include "List.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int menu(){
	int order;
	cout<<"1. New Contact"<<endl;
	cout<<"2. Delete Contact"<<endl;
	cout<<"3. Browse Contact"<<endl;
	cout<<"4. Exit"<<endl;
	cin>>order;
	return order;
}

void createPerson(List *pList)
{

	Node node;
	cout<<"Name: "<<endl;
	cin>>node.data.name;
	cout<<"Phone: "<<endl;
	cin>>node.data.phone;
	pList->ListInsertTail(&node);
}

int main(void)
{
	int userOrder = 0;

	List *pList = new List();

	while(userOrder!=4)
	{
		userOrder = menu();
		switch(userOrder)
		{
			case 1:
				cout<<"Add A New Contact"<<endl;
				createPerson(pList);
				break;
			case 2:
				cout<<"2. Delete A Contact"<<endl;
				break;
			case 3:	
				cout<<"3. Browse The Contact"<<endl;
				pList->ListTraverse();
				break;
			case 4:
				cout<<"4. Exit"<<endl;
				break;
			default:
				break;
		}
	}

	delete pList;
	pList = NULL;

	/*
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
	*/
	system("pause");
	return 0;
}
