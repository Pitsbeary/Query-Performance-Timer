#include "catch.hpp"
#include "../src/timer.h"

TEST_CASE("Timer basic tests.", "[timer][basics]")
{
	QueryPerformanceTimer testTimer;

	SECTION( "Created timer should return 0.0 elapsed time" )
	{
		REQUIRE(testTimer.getElapsedTime() == 0.0);
	}

	SECTION( "getElapsedTime() should return value <= 0.0 when setStartTimestamp() was called and setEndTimestamp() was not." )
	{
		testTimer.setStartTimestamp();
		REQUIRE(testTimer.getElapsedTime() <= 0.0);
	}

	SECTION( "getElapsedTime() should return value greater or equal than 0.0 when setStartTimestamp() and setEndTimestamp() were called correctly." )
	{
		testTimer.setStartTimestamp();
		testTimer.setEndTimestamp();

		REQUIRE(testTimer.getElapsedTime() >= 0.0);
	}
}

TEST_CASE("Timer precision tests.", "[timer][precision]")
{



}
