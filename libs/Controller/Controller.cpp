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

Controller::Controller (Hybrid *h, Bimodal *b, GShare *g)
{
    this->h = h;
    this->num_pred = 0;
    this->num_misses = 0;

    this->b = b;
    this->g = g;
}

Controller::Controller (Smith *s)
{
    this->s = s;
    this->num_pred = 0;
    this->num_misses = 0;
}

void Controller::run_hybrid(utils::branch &br)
{
    unsigned int count;
    unsigned int bmiss, gmiss;
    unsigned int bi, gi, index;

    bi = this->b->get_index(br.addr_val);
    gi = this->g->get_xor_index(br);


    index = stoi(br.addr_val.to_string().substr(32 - this->h->K), nullptr, 2);
    char pred_dir = (this->h->chooser_table[index] >= this->h->mid) ? 'g' : 'b';
    
    count = this->h->chooser_table[index];
    bmiss = this->b->is_miss_prediction(br, bi);
    gmiss = this->g->is_miss_prediction(br, gi);

    if (count <= this->h->mid)
    {
        this->b->update_table(br, bi);
        this->num_misses += bmiss;
    }
    else
    {
        this->g->update_table(br, gi);
        this->num_misses += gmiss;
    }

    if (bmiss == 0 && gmiss == 1 && this->h->chooser_table[index] > 0)
    {
        this->h->chooser_table[index]--;
    }
    else if (bmiss == 1 && gmiss == 0 && this->h->chooser_table[index] < this->h->max)
    {
        this->h->chooser_table[index]++;
    }
}