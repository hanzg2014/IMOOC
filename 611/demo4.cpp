#include <iostream>
#include "stdlib.h"
#include "MyStack4.h"
using namespace std;

#define BINARY		 2
#define OCTONARY	 8
#define HEXADECIMAL 16

int main(void)
{
	MyStack<char> *pStack = new MyStack<char>(30);
	MyStack<char> *pNeedStack = new MyStack<char>(30);

	char str[] = "[[()]]]";

	char currentNeed = 0; //ASCII "cannot be seen"

	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]!=currentNeed)
		{
			pStack->push(str[i]);
			switch(str[i])
			{
				case '[':
					if(currentNeed!=0)
					{
						pNeedStack->push(currentNeed);
					}
					currentNeed = ']';
						break;
				case '(':
					if(currentNeed!=0)
					{
						pNeedStack->push(currentNeed);
					}
					currentNeed = ')';
						break;
				default:
					cout<<"String do not match"<<endl;
					system("pause");
					return 0;
			}
		}else
		{
			char elem;
			pStack->pop(elem);
			if(pNeedStack->pop(currentNeed))
			{
				currentNeed = 0;
			}
		}
	}

	if(pStack->stackEmpty())
	{
		cout<<"String match"<<endl;
	}else
	{
		cout<<"String do not match"<<endl;
	}

	delete pStack;
	pStack = NULL;

	delete pNeedStack;
	pStack = NULL;

	system("pause");
	return 0;
}



