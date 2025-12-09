#include "die.h"
#include <cstdlib>  // rand()
#include <ctime>    // time()

int Die::roll() {
    return (rand() % sides) + 1;  
}