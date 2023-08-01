#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Animal
{
    public:
        virtual void make_sound() = 0;

        virtual bool is_fluffy() const {
            return false;
        }

        virtual bool eats_grass() const {
            return false;
        }

        virtual ~Animal() = default;

        std::string name {};


    private:
};

class Cow : public Animal
{
    public:
        
        Cow() {
            name = "Dairy-Mary";
        }

        void make_sound() final {
            std::cout << "Mooo\n";
        }

        bool eats_grass() const override {
        return true;
        }
        
        virtual ~Cow() {}

    private:
};

class Pig : public Animal
{
    public:
        
        Pig() {
            name = "Peppa";
        }

        void make_sound() final {
            std::cout << "Oink\n";
        }

        bool eats_grass() const override {
        return false;
        }
        
        virtual ~Pig() {}
};

class Dog : public Animal
{
    public:

        Dog() {
            name = "Milou";
        }

        void make_sound() final {
            std::cout << "Barkka Barkka\n";
        }

        bool is_fluffy() const override {
            return true;
        }

        virtual ~Dog() {}

    private:
        
};

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
        std::cout << a->name << '\n';
    }
}

void read_animals_from_file(const std::vector<std::unique_ptr<Animal>>& animals);



#endif