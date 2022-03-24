#ifndef UTILS
#define UTILS

#include <iostream>
#include <string>

namespace utils
{
    typedef struct branch
    {
        // TODO: Change to unsigned int
        std::string address;
        char state;
    } branch;

    utils::branch process_branch(std::string address, char state);
}

#endif