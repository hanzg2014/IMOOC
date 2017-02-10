#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

bool List::ListInsertHead(Node *pNode)
{

	Node *temp = m_pList->next;
	Node *newNode = new Node;

	if(NULL==newNode)
	{
		return false;
	}

	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

bool List::ListInsertTail(Node *pNode)
{

	Node *currentNode = m_pList;
	while(currentNode->next!=NULL)
	{
		currentNode=currentNode->next;
	}
	Node *newNode = new Node;
	if(NULL==newNode) //allocation failed
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

bool List::ListInsert(int i, Node *pNode)
{
	if(i<0||i>m_iLength)	//the same for both tail and head
	{
		return false;
	}
	Node *currentNode = m_pList;
	for(int k=0; k<i; k++){
		currentNode = currentNode->next;
	}
	Node *newNode = new Node;
	if(NULL==newNode) //allocation failed
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return true;
}

void List::ClearList()
{
	Node *currentNode = m_pList->next;
	while(currentNode!=NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;
	m_iLength = 0;
}

bool List::ListEmpty()
{
	return (0==m_iLength)?true:false;
}

int List::ListLength()
{
	return m_iLength;
}

//I think this will also work
bool List::ListDelete(int i, Node * pNode)
{
	if(i<0||i>=m_iLength)
	{
		return false;
	}
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for(int k=0; k<=i; k++){
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

bool List::GetElem(int i, Node *pNode)
{
	if(i<0||i>=m_iLength)
	{
		return false;
	}
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for(int k=0; k<=i; k++){
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}

int List::LocateElem(Node *pNode)
{
	Node * currentNode = m_pList;
	int count = 0;
	while(currentNode->next!=NULL)
	{
		currentNode=currentNode->next;
		if(currentNode->data == pNode->data)
		{
			return count;
		}
		count++;

	}
	return -1;  //cannot find
}

bool List::PriorElem(Node *pCurrentNode, Node *pPreNode)
{
	Node * currentNode = m_pList;
	Node * tempNode = NULL;
	while(currentNode->next!=NULL)
	{
		tempNode = pCurrentNode;
		currentNode = currentNode->next;
		if(currentNode->data == pCurrentNode->data)
		{
			if(tempNode == m_pList)
			{
				return false;	//the first element 
			}
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	return false;  //cannot find
}

bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	Node * currentNode = m_pList;
	while(currentNode->next!=NULL)
	{
		currentNode = currentNode->next;
		if(currentNode->data == pCurrentNode->data)
		{
			if(currentNode->next==NULL)
			{
				return false;	//the last element 
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	return false;  //cannot find
}

void List::ListTraverse()
{
	int count =0;
	Node *currentNode = m_pList;
	while(currentNode->next!=NULL)
	{
		currentNode = currentNode->next;
		cout<<"No."<<count<<": ";
		currentNode->printNode();
		count++;
	}
}


