#include <iostream>
#include <string>
using namespace std;

/**
  * 定义类：Student
  * 数据成员：名字、年龄
  */
class Student
{
  public:
    // 定义数据成员名字 m_strName 和年龄 m_iAge
    void setAge(int _age){
      if(_age>0 &&_age<100)
      {
        age = _age;
      } 
    }

    int getAge(){
      return age;
    }

  private:
    string name;
    int age;
};

class Car
{
  public:
    int getWheelCount()
    {
      return m_iWheelCount;
    }

  private:
    int m_iWheelCount;
}


int main()
{
    // 实例化一个Student对象stu
    Student stu;
    // 设置对象的数据成员
    stu.m_strName = "慕课网";
    stu.m_iAge = 2;
    
    // 通过cout打印stu对象的数据成员
    cout <<stu.m_strName<< "," <<stu.m_iAge<< endl;
    return 0;
}