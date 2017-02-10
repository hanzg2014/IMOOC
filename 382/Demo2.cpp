#include "Teacher2.h"
#include <iostream>
#include "stdlib.h"
#include <string>
using namespace std;

int main(void){
	Teacher t1("Merry", 12);

	cout<<t1.getName()<<" "<<t1.getAge()<<" "<<t1.getMax()<<endl;

	system("pause");
	return 0;
}


