#include "../Bimodal/Bimodal.h"
#include <bitset>
#include <cmath>
#include "GShare.h"
#include <iostream>
#include "../utils/utils.h"

GShare::GShare(unsigned int M, unsigned int N) : Bimodal(M)
{
    this->N = N;
    this->bhr = 0;
    this->bhr_max = pow(2, this->N) - 1;
    this->toggle = true;
}

void GShare::update_bhr(char actual)
{
    this->bhr = this->bhr >> 1;

    if (actual == 't')
    {
        unsigned int msb = this->bhr_max ^ (this->bhr_max >> 1);
        this->bhr = this->bhr ^ msb;
    }
}

unsigned int GShare::get_xor_index(utils::branch &br)
{
    unsigned int m = this->get_index(br.addr_val);
    unsigned index = m ^ this->bhr;

    this->update_bhr(br.outcome);

    return index;
}
