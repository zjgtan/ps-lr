#include <iostream>
#include "pserver.h"


PServer::PServer():_parameters(), _server(0) {
    using namespace std::placeholders;
    _server.set_request_handle(std::bind(&PServer::DataHandle, this, _1, _2, _3));
}

void PServer::DataHandle(const ps::KVMeta& req_meta,
        const ps::KVPairs<float>& req_data,
        ps::KVServer<float>* server) {

    size_t n = req_data.keys.size();

    if (req_meta.push) {
        // push
           

    } else {
        // pull
        // init response
        ps::KVPairs<float> response;
        response.keys = req_data.keys;
        response.vals.resize(n);

        // copy vals
        for (size_t i = 0; i < n; i++) {
            ps::Key key = req_data.keys[i];
            response.vals[i] = _parameters.get_weight(key);
        }
        server->Response(req_meta, response);
    }

}
