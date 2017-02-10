
class Coordinate
{
public:
	Coordinate();
	Coordinate(int x, int y);
	~Coordinate();
	void setX(int x);
	void setY(int y);
	int getX() const; //int getX(const Coordinate *this)
	int getY() const; //int getY(const Coordinate *this)

public:
	int m_iX;
	int m_iY;
};	
