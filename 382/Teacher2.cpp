#include "Teacher2.h"
#include <iostream>
#include <string>
using namespace std;


/*
Teacher::Teacher(){
	m_strName = "Jim";
	m_iAge = 5;
	cout<<"Teacher()"<<endl;
}
*/

Teacher::Teacher(string _name, int _age, int m):m_strName(_name), m_iAge(_age), m_iMax(m){
//	m_strName = _name;
//	m_iAge = _age;
	cout<<"Teacher(string _name, int _age)"<<endl;
}

void Teacher::setName(string _name)
{
  m_strName = _name;
}

string Teacher::getName()
{
  return m_strName;
}

void Teacher::setGender(string _gender)
{
  m_strGender = _gender;
}

string Teacher::getGender()
{
  return m_strGender;
}

int Teacher::getAge()
{
  return m_iAge;
}

void Teacher::setAge(int _age)
{
  m_iAge += _age;
}

void Teacher::teach()
{
	cout<<"Now the class."<<endl;
}

int Teacher::getMax()
{
	return m_iMax;
}