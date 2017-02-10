#include <iostream>
#include "stdlib.h"
#include "MyStack.h"
using namespace std;

MyStack::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new char[size];
	m_iTop = 0;		//number of elements in stakc, 0 when initiated
}
MyStack::~MyStack(){
	delete[] m_pBuffer;
	m_pBuffer = NULL;
}

bool MyStack::stackEmpty(){
	if(0 == m_iTop)
		return true;
	else 
		return false;
}

bool MyStack::stackFull(){
	if(m_iTop >= m_iSize)
		return true;
	else 
		return false;
}

void MyStack::clearStack()
{
	m_iTop = 0; //so that other elements could be flushed again
	cout<<"Stack is now empty again"<<endl;
}

int MyStack::stackLength()
{
	return m_iTop;
}

bool MyStack::push(char elem)
{
	if(!stackFull()){
		m_pBuffer[m_iTop] = elem; 
		m_iTop++;
		cout<<elem<<" is pushed into the stack"<<endl;
		return true;
	}else
	{
		cout<<"Stack is full!"<<endl;
		return false; 
	} 
}

char MyStack::pop()
{
	if(stackEmpty())
	{
		throw 1;
	}else
	{
		return m_pBuffer[--m_iTop];
	}
}

bool MyStack::pop(char &elem)
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

void MyStack::stackTraverse(bool isFromBottom)
{
	if(isFromBottom)
	{
		cout<<"Traverse from bottom: ";
		for(int i=0; i<m_iTop; i++)
		{
		cout<<m_pBuffer[i]<<",";
		}
	}else
	{
		cout<<"Traverse from top: ";
		for(int i = m_iTop-1; i>=0; i--)
		{
			cout<<m_pBuffer[i]<<",";
		}
	}
	cout<<endl;
}



