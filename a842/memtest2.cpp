#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "memerror2.h"

TEST_CASE ("Use flawed_array with non-int type") {
    flawed_array<std::string, 2> strings;

    for (auto& elem : strings) {
        elem = "well";
    }

    CHECK(strings[0] == "well");
}

// produces: FATAL ERROR: test case CRASHED: SIGSEGV - Segmentation violation signal
