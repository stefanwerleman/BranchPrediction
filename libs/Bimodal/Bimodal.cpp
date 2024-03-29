#include <bitset>
#include <cmath>
#include "Bimodal.h"
#include "../utils/utils.h"

Bimodal::Bimodal (unsigned int M)
{
    this->max = 7;
    this->mid = 4;

    this->M = M;

    this->size = pow(2, this->M);
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
    unsigned int index = stoi(value.to_string().substr(32 - this->M), nullptr, 2);

    return index;
}

unsigned int Bimodal::is_miss_prediction(utils::branch &br, unsigned int index)
{
    char actual = br.outcome;
    char pred_dir = (this->table[index] >= this->mid) ? 't' : 'n';
    return (unsigned int)(pred_dir != actual);
}

void Bimodal::update_table(utils::branch &br, unsigned int index)
{
    char actual = br.outcome;
    
    if (actual == 't' && this->table[index] < this->max)
    {
        (this->table[index])++;
    }
    else if (actual == 'n' && this->table[index] > 0)
    {
        (this->table[index])--;
    }
}