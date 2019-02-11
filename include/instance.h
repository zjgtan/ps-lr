#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>
#include "ps/ps.h"

struct Instance{
    public:
        int show;
        int clk;
        std::vector<ps::Key> keys;
};
#endif
