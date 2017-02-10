#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main(){


	string name;
	cin>>name;

	cout<<"Please input your name:"<<endl;

	getline(cin, name);
	if(name.empty())
	{
		cout<<"Input is null.."<<endl;
		return 0;
	}
	if("imooc"==name)
	{
		cout<<"You're Administrator"<<endl;
	}
	cout<<"Hello "+name<<endl;
	cout<<"Name length: "<<name.size()<<endl;
	cout<<"Initial letter: "<<name[0]<<endl;
	*/

	/*
	string name = "ZhangSan";
	string hobby("football");
	cout<<name<<hobby<<endl;

	string s12 = "hello";
	string s2("world");
	strng s3 = s1+s2;
	s4  
	*/
	return 0;
}