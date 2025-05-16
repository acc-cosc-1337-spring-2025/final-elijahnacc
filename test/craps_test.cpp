#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "point_phase.h"
#include "come_out_phase.h"
#include <vector>

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

TEST_CASE("Test ComeOutPhase get_outcome()") {

	Die uno;
	Die dos;
	ComeOutPhase phase;

	std::vector<Roll*> rolls;
	bool get_natural = false, get_craps = false, get_point = false;

	do {
		Roll roll {uno, dos};
		roll.roll_dice();
		rolls.push_back(&roll);
		
		if (roll.roll_value() == 7 || roll.roll_value() == 11) {
			REQUIRE(phase.get_outcome(&roll) == RollOutcome::natural);
			get_natural = true;
		}
		else if (roll.roll_value() == 2 || roll.roll_value() == 3 || roll.roll_value() == 12) {
			REQUIRE(phase.get_outcome(&roll) == RollOutcome::craps);
			get_craps = true;
		}
		else {
			REQUIRE(phase.get_outcome(&roll) == RollOutcome::point);
			get_point = true;
		}

		if (rolls.size() >= 24)
			break;
		
	} while (!get_natural || !get_craps || !get_point);
}

TEST_CASE("Test PointPhase get_outcome()") {

	Die uno;
	Die dos;
	int point = 5;
	PointPhase phase(point);

	std::vector<Roll*> rolls;
	bool get_point = false, get_sevenout = false, get_nopoint = false;

	do {
		Roll roll {uno, dos};
		roll.roll_dice();
		rolls.push_back(&roll);

		if (roll.roll_value() == 7) {
			REQUIRE(phase.get_outcome(&roll) == RollOutcome::seven_out);
			get_sevenout = true;
		}
		else if (roll.roll_value() == point) {
			REQUIRE(phase.get_outcome(&roll) == RollOutcome::point);
			get_point = true;
		}
		else {
			REQUIRE(phase.get_outcome(&roll) == RollOutcome::nopoint);
			get_nopoint = true;
		}

		if (rolls.size() >= 24)
			break;

	} while (!get_point || !get_sevenout || !get_nopoint);
}