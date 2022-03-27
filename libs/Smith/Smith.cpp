#include <bitset>
#include <math.h>
#include "Smith.h"
#include "../utils/utils.h"

Smith::Smith (unsigned int B)
{
    this->B = B;
    this->max = pow(2, B) - 1;
    this->mid = (this->max + 1) / 2;
    this->smith_bit = this->mid - 1;
}

unsigned int Smith::run(utils::branch &br)
{
    char actual = br.outcome;
    char pred_dir = (this->smith_bit >= this->mid) ? 't' : 'n';

    // std::cout << this->mid << std::endl;
    // std::cout << "Predicted: " << pred_dir << ", Actual: " << actual << std::endl;
    // std::cout << std::bitset<2>(this->smith_bit) << std::endl;

    if (actual == 't' && this->smith_bit < this->max)      // Move up
    {
        this->smith_bit++;
    }
    else if (actual == 'n' && this->smith_bit > 0)         // Move down
    {
        this->smith_bit--;
    }

    // std::cout << std::bitset<2>(this->smith_bit) << std::endl;
    // std::cout << std::endl;

    return (unsigned int)(pred_dir != actual);
}