#include <iostream>
#include "Array2.h"
using namespace std;

Array::Array(int len)
{
	this->len = len;
	//m_iLen = len;
	cout<<"Array()"<<endl;
}

Array::~Array()
{
	cout<<"~Array()"<<endl;
}

/*
Array& Array::setLen(int len)
{
	this->len = len;
	return *this;
}
*/
Array* Array::setLen(int len)
{
	this->len = len;
	return this;
}

int Array::getLen()
{
	return this->len;
}

/*
Array& Array::printInfo()
{
	cout<<"len = "<<this->len<<endl;
	return *this;

}
*/

Array* Array::printInfo()
{
	cout<<"len = "<<this->len<<endl;
	return this;

}

