//#ifndef STUDENT_H_
//#define STUDENT_H_

#ifndef MATCH_H_
#define MATCH_H_

#include "Time.h"

class Time;
class Match
{
public:
	Match(int hour, int min, int sec);
	void testTime();
private:
	Time m_tTimer;
};

#endif