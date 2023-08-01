
#include "animal.h"


int main()
{
    std::vector<std::unique_ptr<Animal>> animals;
    read_animals_from_file(animals);

    

    return 0;
}