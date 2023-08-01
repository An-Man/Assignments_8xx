/* 
    Assignment 8.2.1
    Exercise 2

    Create a class with following properties:

    - Has template parameter that enables or disables console output
    - Counts number of calls to
        - Default constructor
        - Copy constructor
        - Move constructor
        - Destructor
    -If enabled, prints out when its constructor / destructor is called

*/


#include "helper.h"
#include <vector>

int main()
{
    std::vector<Helper<true>> helpers;      // this is only for experimenting purposes
    
    Helper<true> help;                      // default constructed
    Helper h2(help);                        // copy constructed from first
    Helper help3;                           // does not print anything

    helpers.push_back(help);                // copy constructor used with push_back
    helpers.push_back(h2);
    helpers.emplace_back(std::move(h2));    // move constructor in use when emplacing
                                            // with std::move  

    std::cout << Helper<true>::count_default_c << '\n'; // these can be printed if needed
    std::cout << Helper<true>::count_copy_c << '\n';
    std::cout << Helper<true>::count_move_c << '\n';
}