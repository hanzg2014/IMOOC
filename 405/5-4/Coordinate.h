
class Coordinate
{
public:
	Coordinate();
	Coordinate(int x, int y);
	~Coordinate();
	void setX(int x);
	void setY(int y);
	int getX(); //int getX(const Coordinate *this)
	int getY(); //int getY(const Coordinate *this)
	void printInfo() const;
public:
	int m_iX;
	int m_iY;
};	
