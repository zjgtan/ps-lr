#ifndef PSERVER_H_
#define PSERVER_H_
#include <unordered_map>
#include "ps/ps.h"
using namespace ps;

class PServer{

    private:
        KVServer<float>* _server;
        std::unordered_map<uint64_t, float>* _parameters;

    public:
        PServer(); //初始化方法

    private:
        void DataHandle(const KVMeta& req_meta,
                const KVPairs<float>& req_data,
                KVServer<float>* server); // 请求处理入口
};

#endif
