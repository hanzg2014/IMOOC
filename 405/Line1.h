#include "Coordinate1.h"

class Line
{
public:
	Line();
	~Line();
	void setA(int x, int y);
	void setB(int x, int y);
	void printInfo();
private:
	Coordinate m_coorA;
	Coordinate m_coorB;
};