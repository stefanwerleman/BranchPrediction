#include <bitset>
#include <cmath>
#include "Bimodal.h"
#include "../utils/utils.h"

Bimodal::Bimodal (unsigned int M2)
{
    this->M2 = M2;
}

unsigned int Bimodal::get_index(std::bitset<32> value)
{
    unsigned int index = stoi(value.to_string().substr(32 - this->M2), nullptr, 2);

    return 0;
}

unsigned int Bimodal::run(utils::branch &br)
{
    unsigned int index = this->get_index(br.addr_val);
    return 0;
}