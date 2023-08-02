#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Animal
{
    public:
        virtual void make_sound() {
            std::cout << "Bonk!\n";
        }

        virtual bool is_fluffy() const {
            return false;
        }

        virtual bool eats_grass() const {
            return false;
        }

        virtual ~Animal() = default;

        std::string name {};
        std::string species {};

    private:
};

class Cow : public Animal
{
    public:
        
        Cow() {
            name = "Dairy-Mary";
            species = "Cow";
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
            species = "Pig";
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
            species = "Dog";
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

void make_sound(Animal& animal);

void print_eats_grass(Animal& animal);

void print_is_fluffy(Animal& animal);

void print_stats(Animal& animal);

void print_animals(const std::vector<std::unique_ptr<Animal>>& animals);

void read_animals_from_file(std::vector<std::unique_ptr<Animal>>& animals);



#endif