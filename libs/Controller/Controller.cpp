#include <iostream>

#include "Controller.h"

#include "../Bimodal/Bimodal.h"
#include "../GShare/GShare.h"
#include "../Hybrid/Hybrid.h"
#include "../Smith/Smith.h"

Controller::Controller (Bimodal &b)
{
    this->b = &b;
}

Controller::Controller (GShare &g)
{
    this->g = &g;
}

Controller::Controller (Hybrid &h)
{
    this->h = &h;
}

Controller::Controller (Smith &s)
{
    this->s = &s;
}

void Controller::bimodal(utils::branch &br)
{
    // Run predictor
}

void Controller::gshare(utils::branch &br)
{
    // Run predictor
}

void Controller::hybrid(utils::branch &br)
{
    // Run predictor
}

void Controller::smith(utils::branch &br)
{
    // Run predictor
    std::cout << (&br) << std::endl;
    std::cout << std::endl;
}
