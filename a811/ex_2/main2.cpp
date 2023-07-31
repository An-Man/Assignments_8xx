// Assignment 8.1.1

// Exercise 2

// std::vector uses heap memory internally to store its contents.  Create an std::vector,
// throw in some elements and print out the address of the vector 
// itself and all of its elements.  Think about what you see.  Is the vector's position
// in the memory same as its contents?  Why?

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vect {};

    std::cout << "Address of vector: " << &vect << '\n'; 

    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);

    std::cout << sizeof(vect) << '\n';  

    for (auto& elem : vect) {
        std::cout << "Address of element: " << &elem << '\n';  
    }
    // Elements are next to each other but in different address than the vector
    
}