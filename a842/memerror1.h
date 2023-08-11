#ifndef ERROR1_H
#define ERROR1_H

#include <vector>
#include <iostream>

struct object_data
{
    std::string name;
};

static std::vector<object_data> object_storage {1};

class large_object
{
    public:
        large_object();
        ~large_object();
        large_object(const large_object &) = default;   // default the copy
                                                        //constructor, since
                                                  // the class is basically just
                                                  // the handle anyways
        
        private :
        // int is often used as a handle, so negative values an be used to denote
        // errors. std::ssize_t is another often seen choice, but we aren't going
        // to create more than INT_MAX elements in our container here.
        int handle;
};

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




#endif