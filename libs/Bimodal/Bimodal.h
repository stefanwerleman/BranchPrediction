#ifndef BIMODAL
#define BIMODAL

#include <bitset>
#include <string>
#include "../utils/utils.h"

class Bimodal
{
    public:
        unsigned int max;
        unsigned int mid;
        unsigned int size;

        unsigned int M2;
        std::string tracefile;

        unsigned int *table;

        Bimodal (unsigned int M2);
        ~Bimodal (void);

        unsigned int get_index(std::bitset<32> value);
        unsigned int run(utils::branch &br);
};

#endif