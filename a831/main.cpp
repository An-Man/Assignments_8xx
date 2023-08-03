/* 
    Assignment 8.3.1

    Create another standard-library-almost-compatible container - a
    non-resizable array that uses heap memory. 

*/

#include "container.h"

int main()
{
    Array<int> arr(6);
    Array<int> arr2;

    std::cout << arr[0] << '\n';
    std::cout << arr2[0] << '\n';

}