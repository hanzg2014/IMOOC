#include "Teacher.h"
#include <iostream>
#include "stdlib.h"
#include <string>
using namespace std;

int main(void){
	Teacher t;
	t.setName("Confucius");
	t.setGender("Male");
	t.setAge(30);

	cout<<t.getName()<<" "<<t.getAge()<<" "<<t.getGender()<<endl;
	t.teach();
	return 0;
}


