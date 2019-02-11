#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <thread>
#include "ps/ps.h"

#include "pserver.h"
#include "pworker.h"

void start_server() {
    // 启动pserver
  if (!ps::IsServer()) {
    return;
  }
  PServer* server = new PServer();
  ps::RegisterExitCallback([server](){ delete server; });
}

void run_worker() {
    // 启动worker
    if (!ps::IsWorker()) {
        return ;
    }

    int rank = ps::MyRank();

    PWorker worker(rank, "./data");

    // 迭代
    for (int epoch = 0; epoch < 10; epoch++) {
        worker.do_iter(epoch);
    }

}

int main() {
    start_server();
    ps::Start();
    run_worker();
    ps::Finalize();

    return 0;
}
