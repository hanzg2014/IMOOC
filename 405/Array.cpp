#include <iostream>
#include "Array.h"
using namespace std;

Array::Array()
{
	cout<<"Array()"<<endl;
}

Array::Array(const Array &arr)
{
	m_iCount = arr.m_iCount;
	cout<<"Array &"<<endl;
}

Array::~Array()
{
	cout<<"~Array"<<endl;
}

void Array::setCount(int _count)
{
	m_iCount = _count;
}

int Array::getCount()
{
	return m_iCount;
}