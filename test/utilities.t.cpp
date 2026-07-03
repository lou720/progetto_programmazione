#include "../doctest.h"
#include "utilities.hpp"

TEST_CASE("Function stringToInt"){
    CHECK(nc::stringToInt("1234", "a") == 1234);
    CHECK_THROWS(nc::stringToInt("123a", "b"));
    CHECK_THROWS(nc::stringToInt("!234", "c"));
    CHECK_THROWS(nc::stringToInt("1234567890123456", "d"));
}