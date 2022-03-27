#ifndef SMITH
#define SMITH

#include <string>

class Smith
{
    public:
        unsigned int B;
        unsigned int smith_bit;
        std::string tracefile;

        void run(void);
};

#endif