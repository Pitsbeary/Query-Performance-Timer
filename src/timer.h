#pragma once

#include <windows.h>

class QueryPerformanceTimer
{
	LARGE_INTEGER counterStart, counterStop;
	double counterFrequency;

	public:
		QueryPerformanceTimer();

		void resetTimer();

		inline void startTimer();
		inline void stopTimer();

		double getElapsedTime();

		double getCounterFrequency();

	private:
		void initFrequency();

};

QueryPerformanceTimer::QueryPerformanceTimer()
{
	initFrequency();

	resetTimer();
}

void QueryPerformanceTimer::initFrequency()
{
	LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);

	counterFrequency = static_cast<double>(li.QuadPart);
}

void QueryPerformanceTimer::resetTimer()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);

	counterStop = counterStart = li;
}

inline void QueryPerformanceTimer::startTimer()
{
	QueryPerformanceCounter(&counterStart);
}

inline void QueryPerformanceTimer::stopTimer()
{
	QueryPerformanceCounter(&counterStop);
}

double QueryPerformanceTimer::getElapsedTime()
{
	if(counterStart.QuadPart > counterStop.QuadPart)
	{
		return 0.0;
	}

	return static_cast<double>(counterStop.QuadPart - counterStart.QuadPart) / counterFrequency;
}

double QueryPerformanceTimer::getCounterFrequency()
{
	return counterFrequency;
}


