#ifndef PWORKER_H_
#define PWORKER_H_

#include <string>
#include "ps/ps.h"
#include "instance.h"
#include "data_loader.h"


class PWorker {
    private:
        ps::KVWorker<float> _worker; // 参数
        DataLoader _loader; // 读入样本
        int _rank; // 进程号
        std::string _dir; //数据路径

    public:
        PWorker(int rank, std::string dir);
        void do_iter(int epoch);

    private:
        std::vector<float> pull(Instance& ins);
        std::vector<float> backprop(std::vector<float> weights,
                int label);
        void push(std::vector<ps::Key> keys, std::vector<float> grads);
};

#endif
