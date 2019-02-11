#ifndef PSERVER_H_
#define PSERVER_H_

#include "ps/ps.h"
#include "parameters.h"

class PServer{

    private:
        ps::KVServer<float> _server;
        Parameters _parameters;

    public:
        PServer(); //初始化方法

    private:
        void DataHandle(const ps::KVMeta& req_meta,
                const ps::KVPairs<float>& req_data,
                ps::KVServer<float>* server); // 请求处理入口
};

#endif
