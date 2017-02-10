#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

int main(void)
{
		
	/*
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
	/*
	vector<int>::iterator iter = vec.begin();
	for(;iter!=vec.end();iter++){    //vec.end()指向vec的末尾的，下一個位置
    	cout<<*iter<<endl;    //*citer 指向元素本身
	}

	cout<<vec.front()<<endl;
	cout<<vec.back()<<endl;
	*/

	/*
	list<int> list1;
	list1.push_back(4);
	list1.push_back(7);
	list1.push_back(10);

	/*
	for(int i=0;i<list1.size();i++)
	{
		cout<<list[i]<<endl;
	}
	*/

	/*
	list<int>::iterator iter = list1.begin();
	for(;iter!=list1.end();iter++)
	{
		cout<<*iter<<endl;
	}
	*/

	/*
	map<int, string> m;
	pair<int, string> p1(3,"hello");
	pair<int, string> p2(6,"world");

	m.insert(p1);
	m.insert(p2);

	//cout<<m[3]<<endl;
	map<int, string>::iterator iter = m.begin();
	for(;iter!=m.end();iter++)
	{
		cout<<iter->first<<endl;
		cout<<iter->second<<endl;
	}
	*/

	map<string, string> m;
	pair<string, string> p1("h","hello");
	pair<string, string> p2("w","world");
	pair<string, string> p3("b","beijing");

	m.insert(p1);
	m.insert(p2);
	m.insert(p3);

	cout<<m["w"]<<endl;

	map<string, string>::iterator iter = m.begin();
	for(;iter!=m.end();iter++)
	{
		cout<<iter->first<<endl;
		cout<<iter->second<<endl;
	}

	system("pause");
	return 0;
}

