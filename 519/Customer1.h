#include <string>
using namespace std;

class Customer
{
public:
	Customer(string name = "uknown", int age=0);
	~Customer();
	void printInfo() const;
private:
	string m_strName;
	int m_iAge;
};