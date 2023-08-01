#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

class Counter
{
    public:
        inline static int count;
        bool must_be_destroyed = true;      // to avoid counting destruction in double

        Counter() {
            ++count;
        }

        Counter(const Counter&) = delete;

        Counter(Counter&& other) {
            other.must_be_destroyed = false;    // the moved-from object set to false
        }

        ~Counter(){
            if (must_be_destroyed) {        // so it doesn't decrease the counter
                --count;
            }
        }        
};

#endif