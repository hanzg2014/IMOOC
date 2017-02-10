#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
using namespace std;

class Coordinate
{
	friend ostream & operator<<(ostream &out, Coordinate &coor);
	friend Coordinate & operator-(Coordinate &coor);
	friend Coordinate operator+(Coordinate &c1, Coordinate &c2);
	
public:
	Coordinate(int x =0, int y = 0);
	int operator[](int index);
	int getX();
	int getY();
	//void printCoordinate();
	//bool operator ==(Coordinate &coor);
	//Coordinate operator+(Coordinate &c);
	//Coordinate & operator++();
	//Coordinate operator++(int);

private:
	int m_iX;
	int m_iY;
};

#endif