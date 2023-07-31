// Assignment 8.1.1

// Exercise 3

// Create a (template) function that takes a container as its input, and checks 
// if the elements in the container are next to each other.

// Create few container types (list, vector, array, deque) and check if this holds true. 
// Try it with different counts of elements (e.g. with 1000, 1000000, 100000000 elements)

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <iterator>

template <typename T>
bool check_container(const T& container) {
    
    for (auto it = container.begin(); it != container.end(); ++it) {
        
        if (&(*std::next(it)) - &(*it) != 1) {
            return false;
        }
        
    }
    return true;
}

// this is a utility function to check what's inside a container
template<typename T>
void print_contents(const T& container) {
    for (auto& elem : container) {
        std::cout << elem << ", ";
    }
    std::cout << "\n\n";
}

int main()
{
    std::vector<int> vect10(10);
    std::vector<int> vect1000(1000);
    std::vector<int> vect100000000(100000000);
    std::list<int> list10 = {};
    std::list<int> list1000(1000);
    std::array<int, 10> arr10 = {};
    std::array<int, 1000> arr1000 = {};
    std::deque<int> deq10(10, 6);
    std::deque<int> deq1000(1000, 5);


    std::cout << sizeof(vect10) << ", " << sizeof(vect1000) << '\n'; // same size
    std::cout << sizeof(arr10) << ", " << sizeof(arr1000) << '\n';  // sizes 40, 4000

    std::cout << std::boolalpha << check_container(vect10) << '\n';
    std::cout << std::boolalpha << check_container(vect1000) << '\n';
    std::cout << std::boolalpha << check_container(vect100000000) << '\n';
    std::cout << std::boolalpha << check_container(list10) << '\n';
    std::cout << std::boolalpha << check_container(list1000) << '\n';
    std::cout << std::boolalpha << check_container(arr10) << '\n';
    std::cout << std::boolalpha << check_container(arr1000) << '\n';
    std::cout << std::boolalpha << check_container(deq10) << '\n';
    std::cout << std::boolalpha << check_container(deq10) << '\n';
  
    
}