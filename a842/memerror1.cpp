#include <vector>
#include <iostream>
#include "memerror1.h"


// Implementations
large_object::large_object() {
    
    int next_handle = object_storage.size();

// create new default-initialised value in the container
// and set our handle to match the index

    object_storage.push_back({std::string("object number ") +
    std::to_string(next_handle)});
    handle = next_handle;
}

large_object::~large_object()
{
    // delete the handle'th element from the storage
    object_storage.erase(object_storage.begin() + handle);
}

// int main()
// {
//     // segmentation fault
//     large_object a;
//     large_object b = a;
//     large_object c;
// }