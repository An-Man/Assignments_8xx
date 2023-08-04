/* 
    Assignment 8.3.1

    Create another standard-library-almost-compatible container - a
    non-resizable array that uses heap memory. + unit tests
    Ex 1: A template class with type aliases
    Ex 2: Create constructors (default, copy, move) for the class.  
          Then create destructor and assignment operators.
    Ex 3: Implement element access.
    Ex 4: Implement swapping two arrays with each other.
    Ex 5: Implement rest of the Container requirements.
    (Optional) ex 6: Try out your container with range-based for loops, 
    and by trying to use it as backing container to your 2D grid.
*/

#ifndef CONTAINER_H
#define CONTAINER_H
#include <vector>
#include <cstdint>
#include <iostream>
#include <limits>

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

        Array(std::size_t input_length, T fill) {  // "fill constructor"
            length = input_length;
            array = new T[length] {};
            for (std::size_t i = 0; i < length; ++i) {
                array[i] = fill;
            }
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

        Array(Array&& other) {              // move constructor
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

        ~Array() {                          // destructor
            delete[] array;
            array = nullptr;
        }

        iterator begin() {
            return array;
        }

        iterator end() {
            return &array[length];
        }

        const_iterator begin() const {
            return array;
        } 

        const_iterator end() const {
            return &array[length];
        }

        T& operator[](std::size_t index) {
            return array[index];
        }

        std::size_t size() const {
            return std::distance(begin(), end());
        }

        std::size_t max_size() const {
            return std::numeric_limits<size_type>::max();
        }

        void swap(Array& other) {
            T* temp_array {array};
            array = other.array;
            other.array = temp_array;
        }

        bool operator==(const Array& other) const {
            return (std::equal(begin(), end(), other.begin(),
            other.end()));
        }

        bool operator!=(const Array& other) const {
            return !(*this == other);
        }

        friend void swap(Array& arr, Array& brr) {
            arr.swap(brr);
        }

        bool empty() const {
            return (begin() == end());
        }
};


#endif