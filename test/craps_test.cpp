#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Die roll returns a value from 1 to 6", "[Die]") {
    srand(time(0));
    Die die;

    for(int i = 0; i < 10; i++) {
        int val = die.roll();
        REQUIRE(val >= 1);
        REQUIRE(val <= 6);
    }
}

TEST_CASE("Roll class returns values from 2 to 12", "[Roll]") {
    srand(time(0));
    Die die1, die2;
    Roll roll(die1, die2);

    for(int i = 0; i < 10; i++) {
        roll.roll_dice();
        int val = roll.roll_value();
        REQUIRE(val >= 2);
        REQUIRE(val <= 12);
    }
}

TEST_CASE("Shooter returns Roll values from 2 to 12", "[Shooter]") {
    srand(time(0));
    Die die1, die2;
    Shooter shooter;

    for(int i = 0; i < 10; i++) {
        Roll* r = shooter.throw_dice(die1, die2);
        int val = r->roll_value();
        REQUIRE(val >= 2);
        REQUIRE(val <= 12);
    }
}

TEST_CASE("ComeOutPhase returns natural, craps, or point", "[ComeOutPhase]") {
    srand(time(0));
    Die die1, die2;
    Roll roll(die1, die2);
    ComeOutPhase co_phase;

    for(int i = 0; i < 10; i++) {
        roll.roll_dice();
        RollOutcome outcome = co_phase.get_outcome(&roll);
        REQUIRE(
            outcome == RollOutcome::natural || 
            outcome == RollOutcome::craps || 
            outcome == RollOutcome::point
        );
    }
}

TEST_CASE("PointPhase returns point, seven_out, or nopoint", "[PointPhase]") {
    srand(time(0));
    Die die1, die2;
    Roll roll(die1, die2);
    int test_point = 5;
    PointPhase pt_phase(test_point);

    for(int i = 0; i < 10; i++) {
        roll.roll_dice();
        RollOutcome outcome = pt_phase.get_outcome(&roll);
        REQUIRE(
            outcome == RollOutcome::point || 
            outcome == RollOutcome::seven_out || 
            outcome == RollOutcome::nopoint
        );
    }
}