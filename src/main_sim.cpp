#include <iostream>

#include "../libs/ArgumentWrapper/ArgumentWrapper.h"

int main(int argc, char **argv)
{
    std::cout << "START OF BRANCH PREDICTION" << std::endl;

    if (argc < 4 || argc > 7)
    {
        std::cout << "INCORRECT AMOUNT OF ARGUMENTS" << std::endl;
        return 1;
    }

    ArgumentWrapper arguments(argc, argv);

    std::cout << "PARSED ARGUMENTS:\t" << arguments << std::endl;

    std::cout << "END OF BRANCH PREDICTION" << std::endl;
    return 0;
}
