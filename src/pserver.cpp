#include <iostream>
#include "pserver.h"


PServer::PServer() {
    _parameters = new std::unordered_map<uint64_t, float>();

    using namespace std::placeholders;
    _server = new KVServer<float>(0);
    _server->set_request_handle(std::bind(DataHandle, this, _1, _2, _3));
}

void PServer::DataHandle(const KVMeta& req_meta,
        const KVPairs<float>& req_data,
        KVServer<float>* server) {

}
