#ifndef TIME_H_
#define TIME_H_
#include "Match.h"
#include <iostream>
using namespace std;

class Time
{
	friend void Match::printTime(Time &t);
	//friend void printTime(Time &t);
public:
	Time(int hour, int min, int sec);
private:
	int m_iHour;
	int m_iMinute;
	int m_iSecond;
};

#endif