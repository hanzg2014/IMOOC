#include <iostream>
#include "stdlib.h"
#include "MyStack1.h"
using namespace std;


/**
MyStack(int size); //allocating memory, setting length(fixed), stack top
~MyStack(); //retrive the allocated memory
bool stackEmpty();
bool stackFull();
void clearStack();
int stackLength(); //number of elementes in stack
void push(char elem);
char pop(char &elem);
void stackTraverse(); //traverse all the data stored in stack
*/

int main(void){
	MyStack *pStack = new MyStack(5);

	/*
	pStack->push('h'); 	//bottom
	pStack->push('e');
	pStack->push('l');
	pStack->push('l');
	pStack->push('o');	//top
	*/
	pStack->push(Coordinate(1,2));
	pStack->push(Coordinate(3,4));

	//pStack->clearStack();
	pStack->stackTraverse(true);

	
	//cout<<"Element popped:"<<elem<<endl;

	pStack->stackTraverse(false);

	Coordinate elem;
	pStack->pop(elem);


	cout<<"Stack Length is: "<<pStack->stackLength()<<endl;

	if(pStack->stackEmpty())
	{
		cout<<"Stack is empty"<<endl;
	}
	if(pStack->stackFull())
	{
		cout<<"Stack is full"<<endl;
	}

	delete pStack;
	pStack = NULL;

	return 0;
}


