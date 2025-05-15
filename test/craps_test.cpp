#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"

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

TEST_CASE("Test Roll class") {

	Die uno;
	Die dos;
	Roll roll {uno, dos};
	int current_roll {0};

	for (int i = 0; i < 10; ++i) {
		roll.roll_dice();
		current_roll = roll.roll_value();
		CHECK(current_roll <= 12);
		CHECK(current_roll >= 2);
	}
}

TEST_CASE("Test Shooter class") {

	Shooter shooter1;
	Die uno;
	Die dos;
	int current_roll {0};

	for (int i = 0; i < 10; ++i) {
		Roll* roll = shooter1.throw_dice(uno, dos);
		current_roll = roll -> roll_value();
		CHECK(current_roll <= 12);
		CHECK(current_roll >= 2);
	}
}