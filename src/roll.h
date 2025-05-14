#ifndef ROLL_H
#define ROLL_H
#include "die.h"

class Roll
{
public:
    Roll(Die& uno, Die& dos);
    void roll_dice() {rolled_value = uno.roll() + dos.roll();}
    int roll_value() const {return rolled_value;}
private:
    Die& uno;
    Die& dos;
    int rolled_value = uno.roll() + dos.roll();
};

#endif