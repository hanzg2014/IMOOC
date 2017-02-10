#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
	Teacher();
	Teacher(string _name, int _age = 20);
	string getName();
	void setName(string _name);
    string getGender();
    void setGender(string _gender);
    int getAge();
    void setAge(int _age);
    void teach();

private:
	string m_strName;
	string m_strGender;
	int m_iAge = 0;
};
