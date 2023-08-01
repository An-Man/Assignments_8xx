/* 
    Assignment 8.2.1
    Exercise 3

    Earlier, we created a class that counted the number of instances
    created.  Delete the classes copy constructor and implement
    the move constructor.

*/

#include "counter.h"

int main()
{
    std::cout << Counter::count << '\n';        // 0

    Counter count1;

    std::cout << Counter::count << '\n';        // 1

    Counter count2(std::move(count1));

    std::cout << Counter::count << '\n';        // 1

    count1.~Counter();
    count2.~Counter();

    std::cout << Counter::count << '\n';        // 0

    return 0;
}