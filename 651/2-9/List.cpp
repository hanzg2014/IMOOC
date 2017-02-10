#include "List.h"
#include <iostream>
using namespace std;

List::List(int size)
{
	m_iSize = size;
	m_pList = new Coordinate[size];
	m_iLength = 0;
}

List::~List()
{
	delete[] m_pList;
	m_pList = NULL;
}

void  List::ClearList()
{
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

bool List::GetElem(int i, Coordinate *e)
{
	if(i<0||i>=m_iSize)
	{
		return false;
	}
	else
	{
		*e = m_pList[i];
		return true;
	}
}

int List::LocateElem(Coordinate *e)
{
	for(int i=0;i<m_iLength;i++)
	{
		if(m_pList[i]==*e)
		{
			return i;
		}
	}
	return -1;
}

bool List::PriorElem(Coordinate *currentElem, Coordinate *preElem)
{
	int temp = LocateElem(currentElem);
	if(-1==temp)
	{
		return false;
	}
	else
	{
		if(0==temp)
		{
			return false;
		}
		else
		{
			*preElem = m_pList[temp-1];
			return true;
		}
	}
}

bool List::NextElem(Coordinate *currentElem, Coordinate *nextElem)
{
	int temp = LocateElem(currentElem);
	if(-1==temp)
	{
		return false;
	}
	else
	{
		if(temp==m_iLength)
		{
			return false;
		}
		else
		{
			*nextElem = m_pList[temp+1];
			return true;
		}
	}
}

void List::ListTraverse()
{
	for(int i = 0; i<m_iLength; i++)
	{
		cout<<m_pList[i]<<" ";

	}
	cout<<endl;
}

bool List::ListInsert(int i, Coordinate *e)
{
	if(i<0||i>m_iLength)
	{
		return false;
	}	
	else
	{
		for(int k = m_iLength; k>i; k--)
		{
			m_pList[k]=m_pList[k-1];
		}
		m_pList[i]=*e;
		m_iLength++;
		return true;
	}
}

bool List::ListDelete(int i, Coordinate *e)
{
	if(i < 0||i >= m_iLength)
	{
		return false;
	}	
	else
	{
		*e = m_pList[i];

		for(int k=i; k<m_iLength-1; k++)
		{
			m_pList[k]=m_pList[k+1];
		}

		m_iLength--;
		return true;
	}
}



