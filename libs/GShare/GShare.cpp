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

unsigned int GShare::get_index(std::bitset<32> value)
{
    std::cout << value.to_string().substr(this->N) << std::endl;
    std::cout << this->bhr << std::endl;
    return stoi(value.to_string().substr(32 - this->N), nullptr, 2);
}

unsigned int GShare::run(utils::branch &br)
{
    unsigned int n = this->get_index(br.addr_val);
    unsigned int index = n ^ this->bhr;

    if (this->bhr == this->bhr_max)
    {
        toggle = false;
    }
    else if (this->bhr == 0)
    {
        toggle = true;
    }

    if (toggle == true)
    {
        this->bhr = this->bhr + pow(2, this->i);
    }
    else
    {
        this->bhr = this->bhr - pow(2, this->i);
    }

    this->i = (i + 1) % this->N;

    // std::cout << index << std::endl;

    return 0;
}