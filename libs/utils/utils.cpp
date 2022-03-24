#include <bitset>
#include <iostream>
#include <string>

#include "utils.h"

utils::branch utils::process_branch(std::string address, char state)
{
    utils::branch new_branch;

    new_branch.state = state;
    new_branch.address = address;

    return new_branch;
}
