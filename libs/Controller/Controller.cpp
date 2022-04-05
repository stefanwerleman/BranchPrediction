#include <iostream>

#include "Controller.h"

#include "../Bimodal/Bimodal.h"
#include "../GShare/GShare.h"
#include "../Hybrid/Hybrid.h"
#include "../Smith/Smith.h"
#include "../utils/utils.h"

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

void Controller::run_hybrid(utils::branch &br)
{
    unsigned int bi, gi, index;
    unsigned int count;

    bi = this->b->get_index(br.addr_val);
    gi = this->g->get_xor_index(br);

    index = stoi(br.addr_val.to_string().substr(32 - this->h->K + 1), nullptr, 2);

    count = this->h->chooser_table[index];

    if (count <= this->h->mid)
    {
        // Bimodal
        this->b->update_table(br, bi);
    }
    else
    {
        // GShare
        this->g->update_table(br, gi);
    }

    unsigned int bmiss, gmiss;

    bmiss = this->b->is_miss_prediction(br, bi);
    gmiss = this->g->is_miss_prediction(br, gi);

    if (bmiss == 0 && gmiss == 1)
    {
        this->h->chooser_table[index]--;
    }
    else if (bmiss == 1 && gmiss == 0)
    {
        this->h->chooser_table[index]++;
    }
}