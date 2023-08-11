#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "memerror3.h"

TEST_CASE(" FIX MEMERROR 3") {
    // added a move constructor to the class cpp_wrapper
    // and doing everything in the same way otherwise

    auto wrapped2 = build_wrapper();
    CHECK(wrapped2.values().random == 42 );

    // fsanitize=address is fine too
}