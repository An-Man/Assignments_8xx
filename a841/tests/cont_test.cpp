/* 
    Assignment 8.4.1

    Exercise 1: Create unit tests for your heap array type (ex 8.3.1),
    enable the sanitizers with the compiler.

    Ex 2: Add unit tests that use the type you created previously,
    that counts its constructor calls as your element type.  (ex. 8.2.1)
    Make sure that calls to the constructors equal the calls to the destructor.
    Run the unit tests with sanitizers enabled.

    Ex 3: Disable the sanitizers from the build (since they don't always
    play along with valgrind), and use valgrind to go through the unit
    tests for ex1.  Make sure valgrind reports that no leaks were possible.

 */


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/container.h"
#include "../include/counter.h"

TEST_CASE("Constructors, destructor and assignment operators") {

    SUBCASE("Default constructors"){
        Array<int> arr;
        Array<int> arr2(5);
        CHECK(arr.size() == 0);
        CHECK(arr2.size() == 5);
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
        Array<int> arr7(10);
        Array<int> arr8(std::move(arr7));

        CHECK(arr7.size() == 0);
        CHECK(arr8.size() == 10);
    }

    SUBCASE("Move assign operator") {
        Array<int> arr9(10);
        Array<int> arr10;

        arr10 = (std::move(arr9));

        CHECK(arr9.size() == 0);
        CHECK(arr10.size() == 10);
    }

    SUBCASE("Destructor") {
        Array<int> arppa(10);
        arppa.~Array();
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

TEST_CASE("Counter, using counter.h class Counter") {
    Array<Counter> three(3);  // three counters
    Array<Counter> two(2);    // two counters

    CHECK(Counter::count == 5); // total 5

    Array<Counter> zero;      // size == 0, counter doesn't change

    CHECK(Counter::count == 5);

    Array<Counter> move_two(std::move(two)); 

    CHECK(Counter::count == 5);

    three.~Array();
    two.~Array();
    move_two.~Array();

    CHECK(Counter::count == 0);
}