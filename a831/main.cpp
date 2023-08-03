/* 
    Assignment 8.3.1

    Create another standard-library-almost-compatible container - a
    non-resizable array that uses heap memory. 

*/

#include "container.h"
#include <algorithm>

int main()
{
    Array<int> arr(6, 7);
    Array<int> arr2;

    std::cout << arr[0] << '\n';
    std::cout << arr2[0] << '\n';

    std::cout << *arr.begin() << '\n';

    for (auto it = arr.begin(); it < arr.end(); ++it) {
        std::cout << *it << '\n';
    }

    for (const auto& elem : arr) {
        std::cout << elem << ", ";
    }
    std::cout << '\n';

}