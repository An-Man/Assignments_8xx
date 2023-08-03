#ifndef CONTAINER_H
#define CONTAINER_H
#include <vector>
#include <cstdint>
#include <iostream>

template <typename T>
class Array
{
        std::size_t length {};
        T* array {};

    public:

        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = value_type*;
        using const_iterator = const value_type*;
        using difference_type = long int;
        using size_type = std::size_t;

        Array() {
            array = new T[length] {};
        }                                       // default constructor

        Array(std::size_t input_length) {       // with length as parameter
            array = new T[length] {};
            length = input_length;
        }

        Array(const Array& other) {     // copy constructor
            length = other.length;
            array = new T[length] {};
            for (std::size_t i = 0; i < length; ++i) {
                array[i] = other.array[i];
            }
        }

        Array& operator=(const Array& other) {    // copy assignment operator
            if (&other == this) {
                return *this;
            }

            delete[] array;

            length = other.length;
            array = new T[length]{};

            for (std::size_t i = 0; i < length; ++i) {
            array[i] = other.array[i];
            }

            return *this;
        }

        Array(Array&& other) {          // move constructor
            length = other.length;
            array = other.array;
            other.length = 0;
            other.array = nullptr;
        }

        Array& operator=(Array&& other) {   // move assignment operator
            if (&other == this) {
                return *this;
            }

            delete[] array;

            length = other.length;
            array = other.array;
            other.length = 0;
            other.array = nullptr;

            return *this;
        }

        T& operator[](std::size_t index) {
            return array[index];
        }

        ~Array() {
            delete[] array;
        }

        std::size_t get_length() const {
            return length;
        }
};

#endif