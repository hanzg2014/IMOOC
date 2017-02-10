#include <iostream>
#include <stdlib.h>
#include "Line5.h"
using namespace std;

int main(void){

	const Line line(1,2,3,4);
	line.printInfo();
	/*
	Line *p = new Line(1,2,3,4);
	p->printInfo();
	delete p;
	p = NULL;
	cout<<sizeof(p)<<endl;
	cout<<sizeof(Line)<<endl;
	*/
	system("pause");
	return 0;
}

