#include <stdlib.h>
#include <iostream>
using namespace std;

template<typename T>
void display(T a)
{
	cout<<a<<endl;
}

template<typename T, class S>
void display(T a, S s)
{
	cout<<a<<" "<<s<<endl;
}

template<typename T, int KSize>
void display(T a)
{
	for(int i=0;i<KSize;i++)
	{
		cout<<a<<endl;
	}
}


int main(void)
{
	
	display<int>(10);
	display<double>(10.89);
	display<int, double>(5,8.3);
	display<int,5>(6);


	system("pause");
	return 0;
}