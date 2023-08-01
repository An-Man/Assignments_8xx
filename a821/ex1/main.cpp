/* 
    Assignment 8.2.1
    Exercise 1

    Create a function that takes universal reference as is argument (template T&&) to print out
    whether or not its argument is an lvalue reference or an rvalue reference

    Make a program and call the function to demonstrate both cases.

 */


#include <iostream>
#include <type_traits>

template<typename T>
void print_value_cat(T&& tt)
{
    if (std::is_rvalue_reference_v<T&&>) {
        std::cout << tt << " is an rvalue reference.\n";
    } else {
        std::cout << tt << " is not an rvalue reference.\n";
    }

    if (std::is_lvalue_reference_v<T&&>) {
        std::cout << tt << " is an lvalue reference.\n";
    } else {
        std::cout << tt << " is not an lvalue reference.\n";
    }
}

int main()
{
    int aa {9};
    int bb {};  // = 0

    print_value_cat(aa);    // lvalue reference
    print_value_cat(3);     // rvalue (literal)
    print_value_cat(bb);    // lvalue
    print_value_cat(aa-bb); // rvalue (expression)
    
}