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

        unsigned int max;
        unsigned int mid;
        unsigned int size;
        unsigned int *chooser_table;
        
        Hybrid (unsigned int K, unsigned int M1, unsigned int N, unsigned int M2);
        ~Hybrid (void);
};

#endif