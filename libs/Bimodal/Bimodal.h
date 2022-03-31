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

        unsigned int M;

        unsigned int *table;

        Bimodal (unsigned int M);
        ~Bimodal (void);

        unsigned int get_index(std::bitset<32> value);
        unsigned int is_miss_prediction(utils::branch &br, unsigned int index);
        void update_table(utils::branch &br, unsigned int index);
};

#endif