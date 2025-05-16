#include "phase.h"
#include "point_phase.h"

RollOutcome PointPhase::get_outcome(Roll* roll) {
    
    if (roll -> roll_value() == point)
        return RollOutcome::point;
    else if (roll -> roll_value() == 7)
        return RollOutcome::seven_out;
    else
        return RollOutcome::nopoint;
}