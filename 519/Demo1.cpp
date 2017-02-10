#include <iostream>
#include <string>
#include <stdlib.h>
#include "MyQueue1.h"

using namespace std;

int main(void)
{
	MyQueue *p = new MyQueue(4); //initialization

	string s = "what?";
	cout<<s<<endl;
	
	Customer c1("Zhang San",20);
	Customer c2("Li Si",30);
	Customer c3("Wang Wu",24);

	p->EnQueue(c1);
	p->EnQueue(c2);
	p->EnQueue(c3);


	p->QueueTraverse();

	Customer c4;
	p->DeQueue(c4);
	c4.printInfo();

	delete p;
	p = NULL;

	system("pause");
	return 0;
}