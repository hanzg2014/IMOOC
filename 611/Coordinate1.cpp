#include <iostream>
#include "Coordinate1.h"
using namespace std;

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
	//cout<<"Coordinate()"<<endl;
}

Coordinate::~Coordinate()
{
	//cout<<"~Coordinate()"<<endl;
}

void Coordinate::printCoordinate(){
	cout<<"("<<m_iX<<","<<m_iY<<")"<<endl;
}
