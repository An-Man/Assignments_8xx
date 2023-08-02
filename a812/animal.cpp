#include "animal.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

void make_sound(Animal& animal) {
    animal.make_sound();
}

void print_eats_grass(Animal& animal) {
    std::cout << "Eats grass: " 
              << std::boolalpha
              << animal.eats_grass() << '\n';
}

void print_is_fluffy(Animal& animal) {
    std::cout << "Is fluffy: " 
              << std::boolalpha
              << animal.eats_grass() << '\n';
}

void print_stats(Animal& animal) {
    std::cout << "Name: " << animal.name << '\n'
              << "Makes sound: ";
    animal.make_sound();
    std::cout << "Fluffy: " << std::boolalpha << animal.is_fluffy() << '\n'
              << "Eats grass: " << animal.eats_grass() << '\n';
}

void print_animals(const std::vector<std::unique_ptr<Animal>>& animals)
{
    for (auto& a : animals)
    {
        std::cout << a->species << ", "
                  << a->name << '\n';
    }
}

void read_animals_from_file(std::vector<std::unique_ptr<Animal>>& animals)
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
            std::unique_ptr<Pig> piggy_point    // make a smart pointer
                = std::make_unique<Pig>();      // and worry not about freeing the memory
            piggy_point->name = second;
            piggy_point->species = first;
            animals.emplace_back(std::move(piggy_point)); // create the object in the vector
        
        } else if (animal_species == "Dog") {
            std::unique_ptr<Dog> doggy_point
                = std::make_unique<Dog>();
            doggy_point->name = second;
            doggy_point->species = first;
            animals.emplace_back(std::move(doggy_point));
        
        } else if (animal_species == "Cow") {
            std::unique_ptr<Cow> cow_point
                = std::make_unique<Cow>();
            cow_point->name = second;
            cow_point->species = first;
            animals.emplace_back(std::move(cow_point));
        
        } else {
            std::unique_ptr<Animal> animal_point
                = std::make_unique<Animal>();
            animal_point->name = second;
            animal_point->species = first;
            animals.emplace_back(std::move(animal_point));           
        }
    }
}

