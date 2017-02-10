#include "Tank.h"
#include <iostream>
using namespace std;

int Tank::s_iCount = 10;

Tank::Tank(char code)
{
	m_cCode = code;
	s_iCount++;
	cout<<"Tank"<<endl;
}

Tank::~Tank()
{
	s_iCount--;
	cout<<"~Tank"<<endl;
	//cout<<s_iCount<<endl;
}

void Tank::fire()
{
	cout<<"Tank -- fire"<<endl;

}

int Tank::getCount()
{
	return s_iCount;
}