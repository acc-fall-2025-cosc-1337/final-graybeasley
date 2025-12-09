#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

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