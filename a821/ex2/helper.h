#ifndef HELPER_H
#define HELPER_H

#include <iostream>

template<bool is_print = false>   // defaults to false
class Helper
{
    public:

    inline static int count_default_c;
    inline static int count_copy_c;
    inline static int count_move_c;
    inline static int count_destroyer;

    Helper() 
    {
        ++count_default_c;
        if constexpr (is_print) {
            std::cout << "default constructor called\n";
        }
    }

    Helper(const Helper& other) {
        ++count_copy_c;
        
        if constexpr (is_print) {
            std::cout << "copy constructor called\n";
        }
    } 

    Helper(Helper&& other) {
        ++count_move_c;

        if constexpr (is_print) {
        std::cout << "move constructor called\n";
        }
    }

    ~Helper() {
        if constexpr (is_print) {
            std::cout << "destructor called\n";
        }
    }
};

#endif