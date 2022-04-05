#ifndef UTILS
#define UTILS

#include <bitset>
#include <iostream>
#include <string>

namespace utils
{
    typedef struct branch
    {
        std::string address;
        char outcome;
        std::bitset<32> addr_val;
    } branch;
}

#endif