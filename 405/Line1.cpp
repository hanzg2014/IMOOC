#include <iostream>
#include "Line1.h"
using namespace std;

Line::Line()
{
	cout<<"Line()"<<endl;
}

Line::~Line()
{
	cout<<"~Line()"<<endl;
}


void Line::setA(int _x, int _y){
	m_coorA.setX(_x);
	m_coorA.setY(_y);
}
void Line::setB(int _x, int _y){
	m_coorB.setX(_x);
	m_coorB.setY(_y);
}

void Line::printInfo(){
	cout<<"("<<m_coorA.getX()<<","<<m_coorA.getY()<<")"<<endl;
	cout<<"("<<m_coorB.getX()<<","<<m_coorB.getY()<<")"<<endl;
}
