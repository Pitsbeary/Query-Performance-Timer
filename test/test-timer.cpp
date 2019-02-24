#pragma once

#include "catch.hpp"
#include "../src/timer.h"

TEST_CASE("Timer basic tests.", "[timer][basics]")
{
	QueryPerformanceTimer testTimer;

	SECTION( "Created timer should return counter frequency > 0.0" )
	{
		REQUIRE(testTimer.getCounterFrequency() > 0.0);
	}

	SECTION( "Created timer should return 0.0 elapsed time" )
	{
		REQUIRE(testTimer.getElapsedTime() == 0.0);
	}

	SECTION( "getElapsedTime() should return 0.0 when startTimer() was called and stopTimer() was not." )
	{
		REQUIRE(testTimer.getElapsedTime() == 0.0);
	}

	SECTION( "getElapsedTime() should return value greater than 0.0 when startTimer() and stopTimer() were called correctly." )
	{
		testTimer.startTimer();
		Sleep(1000);
		testTimer.stopTimer();

		REQUIRE(testTimer.getElapsedTime() > 0.0);
		SECTION( "getElapsedTime() should return approximately 1.0 after using waiting for approximately 1000 milliseconds." )
		{
			REQUIRE(testTimer.getElapsedTime() == Approx(1.0).margin(0.001));
		}
		SECTION( "getElapsedTime() should return 0.0 after calling resetTimer()." )
		{
			testTimer.resetTimer();

			REQUIRE(testTimer.getElapsedTime() == 0.0);
		}
	}
}
