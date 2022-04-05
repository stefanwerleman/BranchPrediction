#include <iostream>

#include "Controller.h"

#include "../Bimodal/Bimodal.h"
#include "../GShare/GShare.h"
#include "../Hybrid/Hybrid.h"
#include "../Smith/Smith.h"

Controller::Controller (Bimodal *b)
{
    this->b = b;
    this->num_pred = 0;
    this->num_misses = 0;
}

Controller::Controller (GShare *g)
{
    this->g = g;
    this->num_pred = 0;
    this->num_misses = 0;
}

Controller::Controller (Hybrid *h)
{
    this->h = h;
    this->num_pred = 0;
    this->num_misses = 0;

    this->b = new Bimodal(h->M2);
    this->g = new GShare(h->M1, h->N);
}

Controller::Controller (Smith *s)
{
    this->s = s;
    this->num_pred = 0;
    this->num_misses = 0;
}

Controller::~Controller (void)
{
    if (this->b != NULL)
    {
        delete this->b;
    }

    if (this->g != NULL)
    {
        delete this->g;
    }
}