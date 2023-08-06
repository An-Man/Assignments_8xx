// Assignment 8.1.1

// Exercise 1

// Create a stack variable of any fundamental type in main() function (so just an usual declaration).  Then print out
// its memory address.

// Create a function in the same program and do the same.  Compute the difference between the addresses and
// print that out too.

#include <iostream>

int return_number() // just any function
{
    int num {};
    return num;
}

int main()
{
    int number {4};
    int number2 {};

    std::cout << &number << '\n';  // print out memory address
    std::cout << &number2 << '\n';

    std::cout << reinterpret_cast<void*>(&return_number) << '\n'; // print address without ()
                 // to print correctly, casting to void* (or any pointer)
    std::cout << (&number2 - &number) << '\n'; // prints 1, which is the size of one int
    
}