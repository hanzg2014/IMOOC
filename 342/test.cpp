#include <iostream>
#include <stdlib.h>
using namespace std;

//Input an integer and print it 
//
//

int main(void)
{
	int x=0;
	cout<<"Please input an integer value"<<endl;
	cin>>x;

	cout<<oct<<x<<endl;
	cout<<dec<<x<<endl;
	cout<<hex<<x<<endl;

	cout<<"Please input a bool value(0,1)"<<endl;
	bool y=false;
	cin>>y;
	cout<<boolalpha<<y<<endl;
	system("pause");
	return 0;
}

