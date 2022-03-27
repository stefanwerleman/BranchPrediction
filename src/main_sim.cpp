#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "../libs/ArgumentWrapper/ArgumentWrapper.h"
#include "../libs/Bimodal/Bimodal.h"
#include "../libs/Controller/Controller.h"
#include "../libs/GShare/GShare.h"
#include "../libs/Hybrid/Hybrid.h"
#include "../libs/Smith/Smith.h"
#include "../libs/utils/utils.h"

void print_results(ArgumentWrapper arguments, Controller *ctrl)
{
    std::cout << "COMMAND" << std::endl;
    std::cout << arguments;
    std::cout << "OUTPUT" << std::endl;
    std::cout << "number of predictions:     " << ctrl->num_pred << std::endl;
    std::cout << "number of mispredictions:  " << ctrl->num_misses << std::endl;
    
    double miss_rate = ((double)ctrl->num_misses / ctrl->num_pred) * 100;
    std::cout << "misprediction rate:        " << std::setprecision(4) << miss_rate << "%" << std::endl;

    if (arguments.predictor == "bimodal")
    {
        std::cout << "FINAL BIMODAL CONTENTS" << std::endl;
    }
    else if (arguments.predictor == "gshare")
    {
        std::cout << "FINAL GSHARE CONTENTS" << std::endl;
    }
    else if (arguments.predictor == "hybrid")
    {
        std::cout << "FINAL CHOOSER CONTENTS" << std::endl;
    }
    else if (arguments.predictor == "smith")
    {
    std::cout << "FINAL COUNTER CONTENT:     " << ctrl->s->smith_bit << std::endl;
    }
}

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
        Smith s(arguments.B);
        ctrl = new Controller(s);
    }

    std::string in;

    while (file >> in)
    {
        std::string address = in;

        file >> in;
        char outcome = in[0];
        utils::branch current_branch = utils::process_branch(address, outcome);
        
        ctrl->num_pred++;

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
            ctrl->num_misses += ctrl->s->run(current_branch);
        }   
    }

    print_results(arguments, ctrl);

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
    std::cout << "(" << ((elapsed_time.count() <= 120.0) ? "\033[92mGOOD\033[m" : "\033[91mTOO LONG\033[m") << ")" << std::endl;
    return 0;
}
