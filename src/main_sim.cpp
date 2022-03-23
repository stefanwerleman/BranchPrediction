#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include "../libs/ArgumentWrapper/ArgumentWrapper.h"
#include "../libs/utils/utils.h"

void run_sim(ArgumentWrapper arguments)
{
    std::cout << "RUNNING SIM WITH:\t" << arguments;

    std::fstream file("./data/traces/" + arguments.trace_file);

    if (!file.is_open())
    {
        std::cout << "FAILED TO OPEN FILE" << std::endl;
        return;
    }

    std::string in;

    while (file >> in)
    {
        std::string address = in;

        file >> in;
        char state = in[0];
        utils::branch current_branch = utils::process_branch(address, state);
    }
}

int main(int argc, char **argv)
{
    auto start = std::chrono::system_clock::now();
    std::cout << "START OF BRANCH PREDICTION" << std::endl;

    if (argc < 4 || argc > 7)
    {
        std::cout << "INCORRECT AMOUNT OF ARGUMENTS" << std::endl;
        return 1;
    }

    ArgumentWrapper arguments(argc, argv);

    run_sim(arguments);

    std::cout << "END OF BRANCH PREDICTION" << std::endl;
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_time = end - start;
    std::cout << "ELAPSED TIME:\t" << elapsed_time.count() << "s ";
    std::cout << "(" << ((elapsed_time.count() <= 120.0) ? "GOOD" : "TOO LONG") << ")" << std::endl;
    return 0;
}
