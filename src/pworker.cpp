#include "pworker.h"
#include "instance.h"

#include <vector>
#include <numeric>
#include <math.h>

PWorker::PWorker(int rank, std::string dir):_worker(0), _loader(dir), _rank(rank) {

}

void PWorker::do_iter(int epoch) {
    _loader.reset();

    while (1) {
        Instance ins;
        bool ret = _loader.next(ins);
        if (ret == false) {
            // 一轮迭代结束
            break;
        }

        // 请求参数
        std::vector<float> weights = pull(ins);
        // 计算梯度
        std::vector<float> grads = backprop(weights, ins.clk);
        // 更新参数
        push(ins.keys, grads);
    }
}

std::vector<float> PWorker::pull(Instance& ins) {
    std::vector<float> weights;
    _worker.Wait(_worker.Pull(ins.keys, &weights));

    return weights;
}

std::vector<float> PWorker::backprop(std::vector<float> weights, int label) {

    float pctr = std::accumulate(weights.begin(), weights.end(), 0);
    pctr = 1 / (1 + exp(-1 * pctr));

    std::vector<float> grads; 
    for (int i=0; i < weights.size(); i++) {
        grads.push_back((pctr - label)); // 默认为1
    }
    return grads;
}

void PWorker::push(std::vector<ps::Key> keys, 
        std::vector<float> grads) {
    _worker.Push(keys, grads);
}
