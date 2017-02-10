#include "Coordinate.h"

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

// void Coordinate::printCoordinate()
// {
// 	cout<<"("<<m_iX<<","<<m_iY<<")"<<endl;
// }

int Coordinate::getX()
{
	return m_iX;
}

int Coordinate::getY()
{
	return m_iY;
}

ostream &operator<<(ostream &out, Coordinate &coor)
{
	out<<"("<<coor.m_iX<<","<<coor.m_iY<<")"<<endl;
	return out;
}

// bool Coordinate::operator ==(Coordinate &coor)
// {
// 	if((this->m_iX==coor.m_iX)&&(this->m_iY==coor.m_iY))
// 		return true;
// 	else 
// 		return false;
// }

Coordinate & operator-(Coordinate &coor)
{
	coor.m_iX = -coor.m_iX;
	coor.m_iY = -coor.m_iY;
	return coor;
}

// Coordinate & Coordinate::operator-()
// {
// 	m_iX = -m_iX;
// 	m_iY = -m_iY;
// 	return *this;
// }
/*
Coordinate & Coordinate::operator++()
{
	m_iX++;
	m_iY++;
	return *this;
}

Coordinate Coordinate::operator++(int)
{
	Coordinate old(*this);
	m_iX++;
	m_iY++;
	return old;
}
*/

/*
Coordinate Coordinate::operator+(Coordinate &c)
{
	Coordinate temp(0,0);
	temp.m_iX = this->m_iX + c.m_iX;
	temp.m_iY = this->m_iY + c.m_iY;
	return temp;
}
*/

Coordinate operator+(Coordinate &c1, Coordinate &c2)
{	
	Coordinate temp(0,0);
	temp.m_iX = c1.m_iX + c2.m_iX;
	temp.m_iY = c1.m_iY + c2.m_iY;
	return temp;
}

int Coordinate::operator[](int index)
{
	if(0 == index){return m_iX;}
	if(1 == index){return m_iY;}
	throw 1;
}



