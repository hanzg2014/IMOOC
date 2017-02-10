#include <iostream>
#include <cstdlib>
using namespace std;


//Input an integer and print it 
//
//

/* 2-1
typedef struct 
{
	int x;
	int y;
	
}Coor;
*/

/* 2-2
typedef struct 
{
	int x;
	int y;
	
}Coord;

void fun(int &a, int &b)
{	
	int c = 0;
	c = a;
	a = b;
	b = c;
}
*/


void fun(int i=30, int j=20, int k = 10);
void fun(double i, double j);

/*4-1

//void fun(const int &a, const int &b);

void fun(const int &a, const int &b){
	a = 10;
	b = 20;
}
*/

int main(void)
{
	fun(1, 2.2);
	fun(1,2);
	//fun();
	//fun(100);
	//fun(100,200);
	//fun(100,200,300);

	/*4-1
	int x = 3;
	int y = 5;
	fun(x,y);
	cout<<x<<","<<y<<endl;
	/*
	//int const &z = x;
	//z = 10;
	//int * const p =&x;
	//*p = 10;
	//cout<<x<<endl;
	//int const *p = &x; //const int *p = &x
	//x = 5;

	/* 2-2
	int x = 10;
	int y = 20;
	cout<<x<<","<<y<<endl;
	fun(x,y);
	cout<<x<<","<<y<<endl;
	*/

	/* 2-2
	int a = 3;
	int *p = &a;
	int *&q = p;

	*q = 5;
	cout<<a<<endl;
	*/

	/* 2-2
	Coord c;
	Coord &c1 = c;
	c1.x = 10;
	c1.y = 20;
	cout<<c.x<<","<<c.y<<endl;
	*/

	/* 2-2
	int a = 10;
	int &b = a;

	b = 20;
	cout<<a<<endl;

	a = 30;
	cout<<b<<endl;

	system("pause");
	*/

	/* 2-1
	int a = 10;
	int *p = &a;
	int *&q = p;

	*q = 20;
	cout<<a<<endl;
	*/

	/* 2-1
	Coor c1;
	Coor &c = c1;
	c.x=10;
	c.y=20;
	cout<<c1.x<<endl<<c1.y<<endl;
	*/

	/* 1-1
	// int a = 3;
	// int &b = a;
	// b = 10;
	// cout<<a<<endl;
	*/

	system("pause");
	return 0;
}


void fun(int i, int j, int k){
	cout<<i<<","<<j<<","<<k<<endl;

}

void fun(double i, double j){
	cout<<i<<","<<j<<endl;
}

