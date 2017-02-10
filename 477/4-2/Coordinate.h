#include <iostream>
using namespace std;

class Coordinate
{
	//friend ostream & operator<<(ostream &out, Coordinate &coor);
	friend Coordinate & operator-(Coordinate &coor);
	
public:
	Coordinate(int x =0, int y = 0);

	int getX();
	int getY();
	//void printCoordinate();
	//bool operator ==(Coordinate &coor);
	//Coordinate & operator-();
	Coordinate & operator++();
	Coordinate operator++(int);

private:
	int m_iX;
	int m_iY;
};