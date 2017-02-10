#include <iostream>
#include "MyQueue.h"
#include <stdlib.h>
using namespace std;

int main(void){

	MyQueue *p = new MyQueue(4); //initialization

	p->EnQueue(10);
	p->EnQueue(12);
	p->EnQueue(16);
	p->EnQueue(18);

	p->QueueTraverse();

	int e = 0;
	p->DeQueue(e);
	cout<<e<<endl;

	p->DeQueue(e);
	cout<<e<<endl;
	cout<<endl;
	p->QueueTraverse();

	p->ClearQueue();

	p->QueueTraverse();

	delete p;
	p = NULL;

	system("pause");
	return 0;
}