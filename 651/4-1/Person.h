#ifndef PERSON_H_  
#define PERSON_H_  

#include <string>
#include <iostream>
using namespace std;

class Person
{
	friend ostream & operator<<(ostream &out, Person & person);
public:
	string name;
	string phone;
	Person & operator= (Person &person);
	bool operator== (Person & person);
};


#endif