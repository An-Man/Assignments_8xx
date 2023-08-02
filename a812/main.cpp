/* 
    Assignment 8.1.2

    Create a vector of unique_ptrs to animal base class, and read the
    file and add the animals to the vector.  If the animal species
    matches a class for the species, create a pointer to that type 
    of animal, otherwise create a general animal pointer.

    Test your program by printing the contents of the vector.

 */

#include "animal.h"


int main()
{
    std::vector<std::unique_ptr<Animal>> animals;

    read_animals_from_file(animals);

    print_animals(animals);

    return 0;
}