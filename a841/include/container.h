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

        using value_type        = T;
        using reference         = value_type&;
        using const_reference   = const value_type&;
        using pointer           = T*;
        using const_pointer     = const T*;
        using iterator          = pointer;
        using const_iterator    = const_pointer;
        using difference_type   = std::size_t;
        using size_type         = std::size_t;

        Array() {                               // default constructor
            array = new T[length] {};
        }                                       

        Array(std::size_t input_length) {       // with length as parameter
            length = input_length;
            array = new T[length] {};
        }

        Array(const Array& other) {             // copy constructor
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
            array = nullptr;
        }

        std::size_t size() const {
            return length;
        }
};

#endif