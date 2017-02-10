#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
#include <string>
using namespace std;

struct Student{
	string name;
	int score;

	//this->score will be used implicitly
	bool operator < (const Student& otherStudent){
		return score==otherStudent.score?name<otherStudent.name:score<otherStudent.score;
	}
	friend ostream& operator<<(ostream& out, Student &student){
		cout<<"Student: "<<student.name<<" "<<student.score<<endl;
		return out;
	}
};

#endif