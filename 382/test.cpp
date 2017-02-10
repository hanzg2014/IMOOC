#include<iostream>
#include<stdlib.h>
using namespace std;

/*
class TV
{
public:
	char name[20];
	int type;

	void changeVol():
	void power();

}
*/

class Coordinate
{
public:
	int x;
	int y;
	void printX()
	{
		cout<<x<<endl;
	}
	void printY()
	{
		cout<<y<<endl;
	}
};


int main(void)
{

	Coordinate coor;
	coor.x=10;
	coor.y=20;
	coor.printX();
	coor.printY();

	Coordinate *p = new Coordinate();
	if(NULL == p){
		//failed
		return 0;
	}

	p->x = 100;
	p->y = 200;
	p->printX();
	p->printY();

	delete p;
	p = NULL;
	
	/*
	TV tv;
	TV tv[20]

	TV *p = new TV();
	TV *q = new TV[20];

	delete p;
	delete q[];
	*/

	system("pause");
	return 0;
}