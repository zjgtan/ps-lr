#include "ps/ps.h"
using namespace ps;

class PWorker {
    private:
        KVWorker<float>* worker;

    public:
        void start_worker();
};
