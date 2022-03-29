#ifndef GSHARE
#define GSHARE

#include "../Bimodal/Bimodal.h"
#include <string>

class GShare : public Bimodal
{
    public:
        unsigned int N;

        void run();
        GShare (unsigned int M, unsigned int N);
};

#endif