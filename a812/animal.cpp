#include "animal.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

void read_animals_from_file(const std::vector<std::unique_ptr<Animal>>& animals)
{
    std::ifstream input_file ("animals.txt");

    if (!input_file) {
        throw std::runtime_error("No input file");
    }

    std::string animal_name {};
    std::string animal_species {};

    std::string line {};

    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        std::string first;
        std::string second;

        std::getline(iss, first, ',');
        animal_species = first;
        
        std::getline(iss, second);
        animal_name = second;

        if (animal_species == "Pig") {
            std::unique_ptr<Pig> piggy_point
                = std::make_unique<Pig>(std::move(piggy_point));
            piggy_point->name = second;
            animals.emplace_back(&piggy_point);
        }
    }
}

