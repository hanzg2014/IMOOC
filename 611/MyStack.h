//#ifndef MYSTACK_H
//#define MYSTACK_H

class MyStack
{
public:
	MyStack(int size); //allocating memory, setting length(fixed), stack top
	~MyStack(); //retrive the allocated memory
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength(); //number of elementes in stack
	bool push(char elem);
	char pop();
	bool pop(char &elem);
	void stackTraverse(bool isFromBottom); //traverse all the data stored in stack

private:
	char *m_pBuffer;	//pointer to the stack
	int m_iSize;	//size of a stack
	int m_iTop;		//stack top
};