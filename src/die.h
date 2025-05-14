#ifndef DIE_H
#define DIE_H

class Die
{
public:
    Die() {set_seed();}
    int roll();
private:
    int sides {6};
    void set_seed();
};

#endif