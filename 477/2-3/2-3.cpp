#include <iostream>
using namespace std;

/**
 * 定义Coordinate类
 * 友元函数：display
 * 数据成员：m_iX、m_iY
 */
class Coordinate
{
    friend void display(Coordinate &coor);
    
public:
	Coordinate(int x, int y)
	{
		m_iX = x;
		m_iY = y;
	}
public:
	int m_iX;
	int m_iY;
};

/**
 * display函数用于显示m_iX、m_iY的值
 */
void display(Coordinate &coor)
{
	cout << "m_iX：" << coor.m_iX << endl;
	cout << "m_iY：" << coor.m_iY << endl;
}

int main(void)
{
    // 实例化Coordinate对象
    Coordinate coor1(1,2);
    // 调用display函数
    display(coor1);
	return 0;
}