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
		void getFrequency();
};

/* --PUBLIC-- */

QueryPerformanceTimer::QueryPerformanceTimer() : counterStartTimestamp(), counterEndTimestamp(), counterFrequency(0.0)
{
	getFrequency();
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
	return static_cast<double>(counterEndTimestamp.QuadPart - counterStartTimestamp.QuadPart) / counterFrequency;
}

/* --PRIVATE-- */

void QueryPerformanceTimer::getFrequency()
{
	LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);

	counterFrequency = static_cast<double>(li.QuadPart);
}


