#ifndef SHOOTER_H
#define SHOOTER_H
#include "die.h"
#include "roll.h"
#include <vector>

class Shooter
{
public:
    Roll* throw_dice(Die& uno, Die& dos);
    void display_rolled_values();
    ~Shooter();
private:
    std::vector<Roll*> rolls;
};

#endif