#include <iostream>
#include <string>

#include "ArgumentWrapper.h"

const int UNDEFINED = -1;

ArgumentWrapper::ArgumentWrapper (int argc, char **argv)
{
    this->B = UNDEFINED;
    this->M1 = UNDEFINED;
    this->M2 = UNDEFINED;
    this->K = UNDEFINED;
    this->N = UNDEFINED;

    this->predictor = argv[1];
    this->trace_file = argv[argc - 1];
    
    if (this->predictor == "bimodal")
    {
        this->M2 = atoi(argv[2]);
    }
    else if (this->predictor == "gshare")
    {
        this->M1 = atoi(argv[2]);
        this->N = atoi(argv[3]);
    }
    else if (this->predictor == "hybrid")
    {
        this->K = atoi(argv[2]);
        this->M1 = atoi(argv[3]);
        this->N = atoi(argv[4]);
        this->M2 = atoi(argv[5]);
    }
    else if (this->predictor == "smith")
    {
        this->B = atoi(argv[2]);
    }
}

std::ostream& operator << (std::ostream &output, ArgumentWrapper arguments)
{
    output << "{" << "B: " << arguments.B;
    output << ", M1: " << arguments.M1;
    output << ", M2: " << arguments.M2;
    output << ", K: " << arguments.K;
    output << ", N: " << arguments.N;
    output << ", trace_file: " << arguments.trace_file;
    output << ", predictor: " << arguments.predictor;
    output << "}" << std::endl;

    return output;
}