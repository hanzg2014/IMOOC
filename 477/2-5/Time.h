#ifndef TIME_H_
#define TIME_H_

class Match; // for "friend Match; " to be available
class Time
{
	friend class Match;
public:
	Time(int hour, int min, int sec);
private:
	void printTime();
	int m_iHour;
	int m_iMinute;
	int m_iSecond;
};

#endif