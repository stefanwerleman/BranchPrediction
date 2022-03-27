#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include "../libs/ArgumentWrapper/ArgumentWrapper.h"
#include "../libs/Bimodal/Bimodal.h"
#include "../libs/Controller/Controller.h"
#include "../libs/GShare/GShare.h"
#include "../libs/Hybrid/Hybrid.h"
#include "../libs/Smith/Smith.h"
#include "../libs/utils/utils.h"

void run_sim(ArgumentWrapper arguments)
{
    std::fstream file("./data/traces/" + arguments.trace_file);

    if (!file.is_open())
    {
        std::cout << "FAILED TO OPEN FILE" << std::endl;
        return;
    }

    Controller *ctrl = NULL;

    if (arguments.predictor == "bimodal")
    {
        Bimodal b;
        ctrl = new Controller(b);
    }
    else if (arguments.predictor == "gshare")
    {
        GShare g;
        ctrl = new Controller(g);
    }
    else if (arguments.predictor == "hybrid")
    {
        Hybrid h;
        ctrl = new Controller(h);
    }
    else if (arguments.predictor == "smith")
    {
        Smith s;
        ctrl = new Controller(s);
    }

    std::string in;

    while (file >> in)
    {
        std::string address = in;

        file >> in;
        char outcome = in[0];
        utils::branch current_branch = utils::process_branch(address, outcome);
        
        if (arguments.predictor == "bimodal")
        {
            
        }
        else if (arguments.predictor == "gshare")
        {
            
        }
        else if (arguments.predictor == "hybrid")
        {
            
        }
        else if (arguments.predictor == "smith")
        {
            
        }   
    }

    delete ctrl;
}

int main(int argc, char **argv)
{
    auto start = std::chrono::system_clock::now();

    if (argc < 4 || argc > 7)
    {
        std::cout << "INCORRECT AMOUNT OF ARGUMENTS" << std::endl;
        return 1;
    }

    ArgumentWrapper arguments(argc, argv);

    run_sim(arguments);

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_time = end - start;
    std::cout << "ELAPSED TIME:\t" << elapsed_time.count() << "s ";
    std::cout << "(" << ((elapsed_time.count() <= 120.0) ? "GOOD" : "TOO LONG") << ")" << std::endl;
    return 0;
}
