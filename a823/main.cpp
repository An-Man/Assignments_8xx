/* 
    Assignment 8.2.3
    Returning back to our 2D Grid class from earlier,
    make sure it is both copyable and movable.
    (As it uses std::vector, it is, by default)
*/

#include "grid.h"
#include <algorithm>

int main()
{
    Grid<int> grid;
    Grid<int> grid2(grid);

    grid.print_data();
    grid2.print_data();

    return 0;
}