#include <new>
#include <cstdint>
#include <iostream>

// This is pretty much a poor man's std::array (with some not-immediately-obvious
// memory problems)

template <typename T, std::size_t Count>
class flawed_array
{
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using const_pointer = const T*;
        using iterator = pointer;
        using const_iterator = const_pointer;
        using size_type = std::size_t;

        constexpr flawed_array() = default;

        // unchecked access
        constexpr reference operator[](const std::size_t index) noexcept {
            return reinterpret_cast<reference>(*(data_storage + index *
            sizeof(value_type)));
        }

        constexpr const_reference operator[](const std::size_t index) const noexcept {
            return reinterpret_cast<const_reference>(*(data_storage + index *
            sizeof(value_type)));
        }

        constexpr iterator begin() noexcept { 
            return reinterpret_cast<pointer>(data_storage); 
            }
        constexpr const_iterator begin() const noexcept {
            return reinterpret_cast<pointer>(data_storage); 
            }
        constexpr iterator end() noexcept { 
            return reinterpret_cast<pointer>(data_storage + sizeof(value_type) * Count); 
            }
        constexpr const_iterator end() const noexcept { 
            return reinterpret_cast<const_pointer>(data_storage + sizeof(value_type) * Count); 
            }
        constexpr size_type size() const noexcept { 
            return Count; }
        
        private:
            // Create buffer of unsigned byte array (plain data), correctly aligned
            // and large enough to hold Count elements. The data is uninitialised.
            // This is basically a way to reserve stack memory.

            alignas(value_type) uint8_t data_storage[sizeof(value_type) * Count];

            // The alignas needs to be there so the memory is correctly aligned, we
            // aren't going to go deeper into that, but it can cause *really* hard to
            // debug errors if that isn't there.
};


int main() {
    flawed_array<int, 5> int_array;

    for (std::size_t i = 0; i < int_array.size(); ++i) {
        int_array[i] = i;
    }

    for (auto& elem : int_array) {
        std::cout << elem << "\n";
    }

    auto int_array_copy = int_array;

    for (auto& elem : int_array_copy) {
        std::cout << elem << "\n";
    }

// Works like a charm so far. Where's the error?
}