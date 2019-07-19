#pragma once

#include <windows.h>

class QueryPerformanceTimer
{
	LARGE_INTEGER counterStartTimestamp, counterEndTimestamp;

	double counterFrequency;

	public:
		QueryPerformanceTimer();

		inline void setStartTimestamp();
		inline void setEndTimestamp();

		double getElapsedTime();

	private:
		double getFrequency();

		inline double getTimestampsDifference();
};

/* ---PUBLIC--- */

QueryPerformanceTimer::QueryPerformanceTimer() : counterStartTimestamp(), counterEndTimestamp(), counterFrequency(0.0)
{
	counterFrequency = getFrequency();
}

inline void QueryPerformanceTimer::setStartTimestamp()
{
	QueryPerformanceCounter(&counterStartTimestamp);
}

inline void QueryPerformanceTimer::setEndTimestamp()
{
	QueryPerformanceCounter(&counterEndTimestamp);
}

double QueryPerformanceTimer::getElapsedTime()
{
	return getTimestampsDifference() / counterFrequency;
}

/* ---PRIVATE--- */

double QueryPerformanceTimer::getFrequency()
{
	LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);

	return static_cast<double>(li.QuadPart);
}

inline double QueryPerformanceTimer::getTimestampsDifference()
{
    return static_cast<double>(counterEndTimestamp.QuadPart - counterStartTimestamp.QuadPart);
}


