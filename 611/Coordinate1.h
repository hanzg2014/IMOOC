//#ifndef COORDINATE_H
//#include COORDINATE_H

class Coordinate
{
public:
	Coordinate(int x = 0, int y = 0);
	~Coordinate();
	void printCoordinate();
	//operator <<;
public:
	int m_iX;
	int m_iY;
};	

//#endif