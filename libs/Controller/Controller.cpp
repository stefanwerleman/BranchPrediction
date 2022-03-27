#include <iostream>

#include "Controller.h"

#include "../Bimodal/Bimodal.h"
#include "../GShare/GShare.h"
#include "../Hybrid/Hybrid.h"
#include "../Smith/Smith.h"

Controller::Controller (Bimodal &b)
{
    this->b = &b;
    this->num_pred = 0;
    this->num_misses = 0;
}

Controller::Controller (GShare &g)
{
    this->g = &g;
    this->num_pred = 0;
    this->num_misses = 0;
}

Controller::Controller (Hybrid &h)
{
    this->h = &h;
    this->num_pred = 0;
    this->num_misses = 0;
}

Controller::Controller (Smith &s)
{
    this->s = &s;
    this->num_pred = 0;
    this->num_misses = 0;
}
