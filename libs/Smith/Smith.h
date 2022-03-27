#ifndef SMITH
#define SMITH

#include <string>
#include "../utils/utils.h"

class Smith
{
    public:
        unsigned int B;
        unsigned int max;
        unsigned int mid;

        // Will be used as counter and final counter content
        unsigned int smith_bit;

        Smith (unsigned int B);
        
        unsigned int run(utils::branch &br);
};

#endif