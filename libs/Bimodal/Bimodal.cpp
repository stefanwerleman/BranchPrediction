#include <bitset>
#include <cmath>
#include "Bimodal.h"
#include "../utils/utils.h"

Bimodal::Bimodal (unsigned int M2)
{
    this->max = 7;
    this->mid = 4;

    this->M2 = M2;

    this->size = pow(2, this->M2);
    this->table = new unsigned int[this->size];
    for (int entry = 0; entry < this->size; entry++)
    {
        this->table[entry] = this->mid;
    }
}

Bimodal::~Bimodal (void)
{
    if (this->table != NULL)
    {
        delete [] this->table;
    }
}

unsigned int Bimodal::get_index(std::bitset<32> value)
{
    unsigned int index = stoi(value.to_string().substr(32 - this->M2), nullptr, 2);

    return index;
}

unsigned int Bimodal::run(utils::branch &br)
{
    unsigned int index = this->get_index(br.addr_val);

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