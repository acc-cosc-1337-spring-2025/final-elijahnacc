#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test Die class roll function") {
	
	Die uno;
	int roll {0};

	for (int i = 0; i < 10; ++i) {
		roll = uno.roll();
		CHECK(roll <= 6);
		CHECK(roll >= 1);
	}
}