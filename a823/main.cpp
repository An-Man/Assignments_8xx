/* 
    Assignment 8.2.3
    Returning back to our 2D Grid class from earlier,
    make sure it is both copyable and movable.

*/

#include "grid.h"
#include <algorithm>


int main()
{
    Grid<int> grid;

    grid.print_data();
    grid.print_size();

    std::cout << grid.at(0,0) << '\n';  // prints element 
    std::cout << grid.at(1,1) << '\n';

    grid.at(0,0) = 5;                   // changes element value 

    grid.print_data();

    std::cout << *grid.begin() << '\n'; // testing iterator

    std::fill(grid.begin(), grid.end(), 6); // use std::fill from algorithms: fill with '6'

    grid.print_data();

    Grid<int> grid2 (4);                // make a new grid with size
    grid2.print_size();
    std::fill(grid2.begin(), grid2.end(), 7);
    grid2.print_data();
  
    return 0;
}