#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "point_phase.h"
#include "come_out_phase.h"
#include <iostream>

using std::cin, std::cout;

int main() 
{
	Die uno {}; 
	Die dos {};
	Shooter shooter {};
	Roll* roll {};
	int rolled_value {};
	int point {};

	ComeOutPhase come_out_phase;
	cout << "Game Start\n";

	do {
		roll = shooter.throw_dice(uno, dos);
		rolled_value = roll -> roll_value();
		if (come_out_phase.get_outcome(roll) != RollOutcome::point)
			cout << "Rolled " << rolled_value << " roll again\n";
	} while (come_out_phase.get_outcome(roll) != RollOutcome::point);

	cout << "Rolled " << rolled_value << " start of point phase\n";
	cout << "Roll until " << rolled_value <<" or 7 is rolled\n";

	point = rolled_value;
	PointPhase point_phase(point);

	do {
		roll = shooter.throw_dice(uno, dos);
		rolled_value = roll -> roll_value();
		if (point_phase.get_outcome(roll) == RollOutcome::nopoint)
			cout << "Rolled " << rolled_value << " roll again \n";
	} while (point_phase.get_outcome(roll) == RollOutcome::nopoint);

	cout << "Rolled " << rolled_value << " end of point phase\n";
	cout << "Game Over\n";
	shooter.display_rolled_values();

	return 0;
}