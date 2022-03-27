#ifndef CONTROLLER
#define CONTROLLER

#include "../Bimodal/Bimodal.h"
#include "../GShare/GShare.h"
#include "../Hybrid/Hybrid.h"
#include "../Smith/Smith.h"

#include "../utils/utils.h"

class Controller
{
    public:
        Bimodal *b;
        GShare *g;
        Hybrid *h;
        Smith *s;

        unsigned int num_pred;
        unsigned int num_misses;

        Controller (Bimodal &b);
        Controller (GShare &g);
        Controller (Hybrid &h);
        Controller (Smith &s);
};

#endif