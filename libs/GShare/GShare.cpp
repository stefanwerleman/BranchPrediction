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
    this->i = 0;
}

unsigned int GShare::run(utils::branch &br)
{
    unsigned int m = this->get_index(br.addr_val);
    unsigned index = m ^ this->bhr;

    // Know when insert 0s or 1s
    if (this->bhr == this->bhr_max)
        toggle = false;
    else if (this->bhr == 0)
        toggle = true;

    if (toggle == true)
        this->bhr = this->bhr + pow(2, this->i);
    else
        this->bhr = this->bhr - pow(2, this->i);

    this->i = (i + 1) % this->N;

    char actual = br.outcome;
    char pred_dir = (this->table[index] >= this->mid) ? 't' : 'n';

    if (actual == 't' && this->table[index] < this->max)
    {
        (this->table[index])++;
    }
    else if (actual == 'n' && this->table[index] > 0)
    {
        (this->table[index])--;
    }

    return (unsigned int)(pred_dir != actual);
}