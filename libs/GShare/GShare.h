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

        unsigned int i;
        bool toggle;

        GShare (unsigned int M, unsigned int N);

        unsigned int run(utils::branch &br);
};

#endif