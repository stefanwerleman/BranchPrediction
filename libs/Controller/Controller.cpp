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

void bimodal(utils::branch br)
{
    // Run predictor
}

void gshare(utils::branch br)
{
    // Run predictor
}

void hybrid(utils::branch br)
{
    // Run predictor
}

void smith(utils::branch br)
{
    // Run predictor
}
