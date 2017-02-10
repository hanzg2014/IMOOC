#include <iostream>
#include "MyQueue1.h"
using namespace std;

MyQueue::MyQueue(int queueCapacity)
{
	m_pQueue = new Customer[m_iQueueCapacity]; //possibility of a memory failure. //Need default initializer to initialize
	m_iQueueCapacity = queueCapacity;
	ClearQueue();
	/*
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;	
	*/
}

MyQueue::~MyQueue()
{
	delete[] m_pQueue;
	m_pQueue = NULL;
}

void MyQueue::ClearQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	cout<<"Queue cleared"<<endl;
}		//Clear a queue

bool MyQueue::QueueEmpty() const
{
	return (m_iQueueLen==0)?true:false;
	/*
	if(0 == m_iQueueLen)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
}


int MyQueue::QueueLength() const
{
	return m_iQueueLen;
}

bool MyQueue::QueueFull() const
{
	return (m_iQueueLen==m_iQueueCapacity)?true:false;
}

bool MyQueue::EnQueue(Customer element)
{
	if(QueueFull())
	{
		return false;
	}
	else
	{
		m_pQueue[m_iTail]=element;
		m_iTail++;
		m_iTail %= m_iQueueCapacity;
		m_iQueueLen++;
		cout<<"Element entered: "<<endl;
		element.printInfo();
		return true;
	}
}

bool MyQueue::DeQueue(Customer &element)
{
	if(QueueEmpty())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_iHead++;
		m_iHead %= m_iQueueCapacity;
		m_iQueueLen--;
		cout<<"Element dequeued: "<<endl;
		element.printInfo();
		return true;
	}
}

void MyQueue::QueueTraverse()
{	
	cout<<"QueueTraverse():"<<endl;
	for(int i=m_iHead; i<m_iQueueLen+m_iHead; i++)
	{
		cout<<"Number of customers ahead: "<<i-m_iHead<<endl;
		m_pQueue[i%m_iQueueCapacity].printInfo();
	}
	cout<<endl;
}

