#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, int array[])
{

	int len = sizeof(array)/sizeof(array[0]);
	for(int i=0; i<len; i++)
	{
		cout<<array[i]<<",";
	}
	cout<<endl;
	return out;
}

void select(int array[])
{
	int min;
	int len = sizeof(array)/sizeof(array[0]);
	for (int i=0; i<len-1; i++)
	{
		min = array[i];
		for(int j=i+1; j<len; j++)
		{
			if(array[j]<min)
			{
				min = array[j];
			}
		}
		array[i] = min;
	}
}

int main(void)
{
	int array[]={1,6,3,0,5};
	cout<<array;
	select(array);
	return 0;
}