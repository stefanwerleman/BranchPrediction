#ifndef ARGUMENT_WRAPPER
#define ARGUMENT_WRAPPER

#include <iostream>
#include <string>

// Single place for all parameters given by user.
class ArgumentWrapper
{
    public:
        int B;
        int M1;
        int M2;
        int K;
        int N;
        std::string predictor;
        std::string trace_file;

        ArgumentWrapper (int argc, char **argv);
};

std::ostream& operator << (std::ostream &output, ArgumentWrapper argument_wrapper);

#endif