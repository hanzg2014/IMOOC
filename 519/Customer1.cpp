#include <string>
#include <iostream>
#include "Customer1.h"
using namespace std;

Customer::Customer(string name, int age)
{
	m_strName = name;
	m_iAge = age;
}

Customer::~Customer()
{

}

void Customer::printInfo() const
{
	cout<<"Name: "<<m_strName<<endl;
	cout<<"Age: "<<m_iAge<<endl;
	cout<<endl;
}