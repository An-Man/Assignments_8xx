#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/container.h"

TEST_CASE("Constructor, default and with parameter length") {
    Array<int> arr(6);
    Array<int> arr2;

    CHECK(arr.get_length() == 6);
    CHECK(arr2.get_length() == 10);
}

TEST_CASE("Constructor, copy") {
    Array<int> arr(5);
    Array<int> arr2(arr);

    CHECK(arr.get_length() == 5);
    CHECK(arr2.get_length() == 5);
}

TEST_CASE("Copy assign operator") {
    Array<int> arr(9);
    Array<int> arr2;

    arr2 = arr;

    CHECK(arr2.get_length() == 9);
    CHECK(arr.get_length() == 9);
}

TEST_CASE("Constructor, move") {
    Array<int> arr(10);
    Array<int> arr2(std::move(arr));

    CHECK(arr2.get_length() == 10);
    CHECK(arr.get_length() == 0);
}

TEST_CASE("Move assign operator") {
    Array<int> arr(10);
    Array<int> arr2;

    arr2 = (std::move(arr));

    CHECK(arr2.get_length() == 10);
    CHECK(arr.get_length() == 0);
}

// TEST_CASE("Access element") {
//     Array<int> arr(7);
//     arr[0] = 6;
//     arr[1] = 8;

//     CHECK(arr[0] == 6);
//     CHECK(arr[1] == 8);
//     // CHECK(arr[2] == 0);
// }