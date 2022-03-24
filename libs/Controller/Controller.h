#ifndef CONTROLLER
#define CONTROLLER

#include "../Bimodal/Bimodal.h"
#include "../GShare/GShare.h"
#include "../Hybrid/Hybrid.h"
#include "../Smith/Smith.h"

#include "../utils/utils.h"

class Controller
{
    protected:
        Bimodal *b;
        GShare *g;
        Hybrid *h;
        Smith *s;

    public:
        Controller (Bimodal &b);
        Controller (GShare &g);
        Controller (Hybrid &h);
        Controller (Smith &s);

        void bimodal(utils::branch br);
        void gshare(utils::branch br);
        void hybrid(utils::branch br);
        void smith(utils::branch br);
};

#endif