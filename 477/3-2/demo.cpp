#include "Tank.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void){


	cout<<Tank::getCount()<<endl;

	Tank *p = new Tank('A');
	Tank t1('A');
	cout<<t1.getCount()<<endl;

	system("pause");
	return 0;
}