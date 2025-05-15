#include "shooter.h"
#include <iostream>

Roll* Shooter::throw_dice(Die& uno, Die& dos) {
    
    Roll* roll = new Roll {uno, dos};
    rolls.push_back(roll);

    return roll;
}

void Shooter::display_rolled_values() {

    for (auto roll : rolls)
        std::cout << roll->roll_value() << "\n";
}

Shooter::~Shooter() {

    for (auto roll : rolls)
        delete roll;
}