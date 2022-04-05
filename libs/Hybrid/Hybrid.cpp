#include <cmath>
#include "Hybrid.h"

Hybrid::Hybrid (unsigned int K, unsigned int M1, unsigned int N, unsigned int M2)
{
    this->K = K;
    this-> M1 = M1;
    this->N = N;
    this->M2 = M2;

    this->max = 3;
    this->mid = 1;
    this->size = pow(2, this->K);

    this->chooser_table = new unsigned int[this->size];

    for (int entry = 0; entry < this->size; entry++)
    {
        this->chooser_table[entry] = this->mid;
    }
}

Hybrid::~Hybrid (void)
{
    if (this->chooser_table != NULL)
    {
        delete [] this->chooser_table;
    }
}