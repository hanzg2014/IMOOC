#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
	//Teacher();
	Teacher(string _name = "Jim", int _age = 1);
	Teacher(const Teacher &);
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
	int m_iAge;



};
