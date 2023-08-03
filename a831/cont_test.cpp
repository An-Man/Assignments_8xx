#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "container.h"

TEST_CASE("Constructors and assignment operators") {

    SUBCASE("Default constructors"){
        Array<int> arr;
        Array<int> arr2(5);
        CHECK(arr.size() == 0);
        CHECK(arr2.size() == 5);
    }

    SUBCASE("Fill constructor") {
        Array<int> arr_f(4, 16);

        for (auto a : arr_f) {
            CHECK(a == 16);
        }
    }

    SUBCASE("Constructor, copy") {
        Array<int> arr3;
        Array<int> arr4(arr3);

        CHECK(arr3.size() == 0);
        CHECK(arr4.size() == 0);
    }

    SUBCASE("Copy assign operator") {
        Array<int> arr5;
        Array<int> arr6(10);

        arr5 = arr6;

        CHECK(arr5.size() == 10);
        CHECK(arr6.size() == 10);
    }

    SUBCASE("Constructor, move") {
        Array<int> arr7(10, 2);
        Array<int> arr8(std::move(arr7));

        CHECK(arr7.size() == 0);
        CHECK(arr8.size() == 10);
        CHECK(arr8[5] == 2);
    }

    SUBCASE("Move assign operator") {
        Array<int> arr9(10);
        Array<int> arr10;

        arr10 = (std::move(arr9));

        CHECK(arr9.size() == 0);
        CHECK(arr10.size() == 10);
    }
}

TEST_CASE("Access element") {
    Array<int> arr11(7);
    arr11[0] = 6;
    arr11[1] = 8;

    CHECK(arr11[0] == 6);
    CHECK(arr11[1] == 8);
    CHECK(arr11[2] == 0);
}

TEST_CASE("Iterator") {
    Array<int> arr12(5, 10);
    CHECK(*arr12.begin() == 10);

    for (auto it = arr12.begin(); it < arr12.end(); ++it) {
        CHECK(*it == 10);
    }
}