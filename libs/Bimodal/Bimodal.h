#ifndef BIMODAL
#define BIMODAL

#include <bitset>
#include <string>
#include "../utils/utils.h"

class Bimodal
{
    public:
        unsigned int M2;
        std::string tracefile;

        Bimodal (unsigned int M2);

        unsigned int get_index(std::bitset<32> value);
        unsigned int run(utils::branch &br);
};

#endif