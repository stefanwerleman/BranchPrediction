#include <bitset>
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
    
    // TODO: Modify precision to match correct outputs (show trailing zeros)  
    double miss_rate = ((double)ctrl->num_misses / ctrl->num_pred) * 100;
    std::cout << "misprediction rate:        " << std::setprecision(4) << miss_rate << "%" << std::endl;

    if (arguments.predictor == "bimodal")
    {
        std::cout << "FINAL BIMODAL CONTENTS" << std::endl;
        for (int entry = 0; entry < ctrl->b->size; entry++)
        {
            std::cout << entry << "\t" << ctrl->b->table[entry] << std::endl;
        }
    }
    else if (arguments.predictor == "gshare")
    {
        std::cout << "FINAL GSHARE CONTENTS" << std::endl;
        for (int entry = 0; entry < ctrl->g->size; entry++)
        {
            std::cout << entry << "\t" << ctrl->g->table[entry] << std::endl;
        }
    }
    else if (arguments.predictor == "hybrid")
    {
        std::cout << "FINAL CHOOSER CONTENTS" << std::endl;
        for (int i = 0; i < ctrl->h->size; i++)
        {
            std::cout << i << "\t" << ctrl->h->chooser_table[i] << std::endl;        
        }

        std::cout << "FINAL GSHARE CONTENTS" << std::endl;
        for (int entry = 0; entry < ctrl->g->size; entry++)
        {
            std::cout << entry << "\t" << ctrl->g->table[entry] << std::endl;
        }

        std::cout << "FINAL BIMODAL CONTENTS" << std::endl;
        for (int entry = 0; entry < ctrl->b->size; entry++)
        {
            std::cout << entry << "\t" << ctrl->b->table[entry] << std::endl;
        }
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
    Bimodal *b = NULL;
    Smith *s = NULL;
    GShare *g = NULL;
    Hybrid *h = NULL;

    if (arguments.predictor == "bimodal")
    {
        b = new Bimodal(arguments.M2);
        ctrl = new Controller(b);
    }
    else if (arguments.predictor == "gshare")
    {
        g = new GShare(arguments.M1, arguments.N);
        ctrl = new Controller(g);
    }
    else if (arguments.predictor == "hybrid")
    {
        h = new Hybrid(arguments.K, arguments.M1, arguments.N, arguments.M2);
        ctrl = new Controller(h);
    }
    else if (arguments.predictor == "smith")
    {
        s = new Smith(arguments.B);
        ctrl = new Controller(s);
    }
    unsigned mask;
    unsigned int index;
    char outcome;
    std::string in;
    std::string  address;
    utils::branch current_branch;

    while (file >> in)
    {
        address = in;

        file >> in;
        outcome = in[0];

        current_branch.outcome = outcome;
        current_branch.address = address;

        mask = stoi(address, 0, 16);
        std::bitset<32> binary_addr(mask);
        current_branch.addr_val = binary_addr >> 2;

        ctrl->num_pred++;

        if (arguments.predictor == "bimodal")
        {
            index = ctrl->b->get_index(current_branch.addr_val);
            ctrl->num_misses += ctrl->b->is_miss_prediction(current_branch, index);
            ctrl->b->update_table(current_branch, index);
        }
        else if (arguments.predictor == "gshare")
        {
            index = ctrl->g->get_xor_index(current_branch);
            ctrl->num_misses += ctrl->g->is_miss_prediction(current_branch, index);
            ctrl->g->update_table(current_branch, index);
        }
        else if (arguments.predictor == "hybrid")
        {
            ctrl->run_hybrid(current_branch);
        }
        else if (arguments.predictor == "smith")
        {
            ctrl->num_misses += ctrl->s->run(current_branch);
        }   
    }

    print_results(arguments, ctrl);

    delete b;
    delete s;
    delete g;
    delete h;
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
