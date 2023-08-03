#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "memerror1.h"

TEST_CASE(" FAIL MEMERROR 1") {
    
    large_object a;
    large_object b = a;
    large_object c;
    
    // this works after initializing the size of the vector to 1,
    // and -fsanitize=address doesn't complain either
}


