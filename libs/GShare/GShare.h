#ifndef GSHARE
#define GSHARE

#include "../Bimodal/Bimodal.h"
#include <string>
#include "../utils/utils.h"

class GShare : public Bimodal
{
    public:
        unsigned int N;
        unsigned int bhr;
        unsigned int bhr_max;

        bool toggle;

        GShare (unsigned int M, unsigned int N);

        void update_bhr(char actual);
        unsigned int get_xor_index(utils::branch &br);
        // unsigned int run(utils::branch &br);
};

#endif