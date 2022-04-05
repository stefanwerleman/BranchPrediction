#ifndef HYBRID
#define HYBRID

#include <string>

class Hybrid
{
    public:
        unsigned int K;
        unsigned int M1;
        unsigned int N;
        unsigned int M2;
        std::string tracefile;
        
        Hybrid (unsigned int K, unsigned int M1, unsigned int N, unsigned int M2);

        void run();
};

#endif