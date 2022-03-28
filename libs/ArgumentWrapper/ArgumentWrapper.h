#ifndef ARGUMENT_WRAPPER
#define ARGUMENT_WRAPPER

#include <iostream>
#include <string>

// Single place for all parameters given by user.
class ArgumentWrapper
{
    public:
        unsigned int B;
        unsigned int M1;
        unsigned int M2;
        unsigned int K;
        unsigned int N;
        std::string predictor;          // smith, bimodal, gshare, and hybrid
        std::string trace_file;

        ArgumentWrapper (int argc, char **argv);
};

std::ostream& operator << (std::ostream &output, ArgumentWrapper argument_wrapper);

#endif