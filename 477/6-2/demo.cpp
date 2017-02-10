#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
		
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(6);	
	/*
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<endl;
	}
	*/
	vector<int>::iterator iter = vec.begin();
	for(;iter!=vec.end();iter++){    //vec.end()指向vec的末尾的，下一個位置
    	cout<<*iter<<endl;    //*citer 指向元素本身
	}

	cout<<vec.front()<<endl;
	cout<<vec.back()<<endl;

	system("pause");
	return 0;
}

