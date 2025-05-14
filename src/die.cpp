#include "die.h"
#include <ctime>
#include <cstdlib>

int Die::roll()
{
    return rand() % 6 + 1;
}

//private

void Die::set_seed()
{
    std::srand(std::time(0));
}