//#ifndef MYSTACK_H
//#define MYSTACK_H
#include <iostream>
using namespace std;

template <typename T>
class MyStack
{
public:
	MyStack(int size); //allocating memory, setting length(fixed), stack top
	~MyStack(); //retrive the allocated memory
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength(); //number of elementes in stack
	//bool push(char elem);
	bool push(T elem);
	//char pop();
	T pop();
	//bool pop(char &elem);
	bool pop(T &elem);
	void stackTraverse(bool isFromBottom); //traverse all the data stored in stack

private:
	//char *m_pBuffer;	//pointer to the stack
	T *m_pBuffer;
	int m_iSize;	//size of a stack
	int m_iTop;		//stack top
};

template <typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new T[size];
	m_iTop = 0;		//number of elements in stakc, 0 when initiated
}

template <typename T>
MyStack<T>::~MyStack(){
	delete[] m_pBuffer;
	m_pBuffer = NULL;
}

template <typename T>
bool MyStack<T>::stackEmpty(){
	if(0 == m_iTop)
		return true;
	else 
		return false;
}

template <typename T>
bool MyStack<T>::stackFull(){
	if(m_iTop >= m_iSize)
		return true;
	else 
		return false;
}

template <typename T>
void MyStack<T>::clearStack()
{
	m_iTop = 0; //so that other elements could be flushed again
	cout<<"Stack is now empty again"<<endl;
}

template <typename T>
int MyStack<T>::stackLength()
{
	return m_iTop;
}

template <typename T>
bool MyStack<T>::push(T elem)
{
	if(!stackFull()){
		m_pBuffer[m_iTop] = elem; 
		m_iTop++;
		//cout<<elem<<" is pushed into the stack"<<endl;
		return true;
	}else
	{
		cout<<"Stack is full!"<<endl;
		return false; 
	} 
}


//char MyStack<T>::pop()
template <typename T>
T MyStack<T>::pop()
{
	if(stackEmpty())
	{
		throw 1;
	}else
	{
		return m_pBuffer[--m_iTop];
	}
}

template <typename T>
bool MyStack<T>::pop(T &elem)
{
	if(stackEmpty())
	{
		return false;
	}else
	{
		elem = m_pBuffer[--m_iTop];
		return true;
	}
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromBottom)
{
	if(isFromBottom)
	{
		cout<<"Traverse from bottom: "<<endl;
		for(int i=0; i<m_iTop; i++)
		{
			cout<<m_pBuffer[i];
			//m_pBuffer[i].printT();
			//cout<<",";
		}
	}else
	{
		cout<<"Traverse from top: "<<endl;
		for(int i = m_iTop-1; i>=0; i--)
		{
			cout<<m_pBuffer[i];
			//m_pBuffer[i].printT();
			//cout<<",";
		}
	}
	cout<<endl;
}
