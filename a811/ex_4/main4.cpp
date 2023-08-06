// Assignment 8.1.1

// Exercise 4

// Check if std::vector of std::vectors is contiguous.


#include <iostream>
#include <vector>

template <typename T>
bool check_container(const T& container) {
    
    for (auto it = container.begin(); it != container.end(); ++it) {
        
        if (&(*std::next(it)) - &(*it) != 1) {
            return false;
        }
        
    }
    return true;
}

int main()
{
    std::vector<std::vector<int>> vects(5); // a vector of vectors

    std::cout << std::boolalpha << check_container(vects) << '\n'; // prints true

  
}