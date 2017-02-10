#include <iostream>
#include "stdlib.h"
#include "MyStack3.h"
#include "Coordinate2.h"
using namespace std;

#define BINARY		 2
#define OCTONARY	 8
#define HEXADECIMAL 16

int main(void)
{
	MyStack<char> *pStack = new MyStack<char>(30);
	MyStack<char> *pNeedStack = new MyStack<char>(30);

	char str[] = "[()]";

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
			}
		}else
		{
			char elem;
			pStack->pop(elem);
			pNeedStack->pop(currentNeed);
		}
	}

	if(pStack->stackEmpty())
	{
		cout<<"Char match"<<endl;
	}else
	{
		cout<<"Char not match"<<endl;
	}

	delete pStack;
	pStack = NULL;

	delete pNeedStack;
	pStack = NULL;

	system("pause");
	return 0;
}



