#include <iostream>
#include <stdlib.h>
#include "Line2.h"
using namespace std;

int main(void){

	Line *p = new Line(1,2,3,4);
	p->printInfo();
	delete p;
	p = NULL;
	
	system("pause");
	return 0;
}
