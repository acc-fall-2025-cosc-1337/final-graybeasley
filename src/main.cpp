#include <iostream>
#include <ctime>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() {
    srand(time(0)); 

    Die die1, die2;
    Shooter shooter;
    Roll* roll;

    ComeOutPhase come_out_phase;

    // come out
    do {
        roll = shooter.throw_dice(die1, die2);
        std::cout << "Rolled " << roll->roll_value() << " roll again\n";
    } while(come_out_phase.get_outcome(roll) == RollOutcome::natural ||
            come_out_phase.get_outcome(roll) == RollOutcome::craps);

    int rolled_value = roll->roll_value();
    std::cout << "Rolled " << rolled_value << " start of point phase\n";
    std::cout << "Roll until rolled value or a 7 is rolled\n";

    int point = rolled_value;
    PointPhase point_phase(point);

    // point phase
    do {
        roll = shooter.throw_dice(die1, die2);
        std::cout << "Rolled " << roll->roll_value() << " roll again\n";
    } while(point_phase.get_outcome(roll) != RollOutcome::seven_out &&
            point_phase.get_outcome(roll) != RollOutcome::point);

    std::cout << "Rolled " << roll->roll_value() << " end of point phase\n";

    // all rolls
    shooter.display_rolled_values();

    return 0;
}