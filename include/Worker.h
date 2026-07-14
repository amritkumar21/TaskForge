#pragma once

#include <atomic>
#include <thread>
#include <iostream>

#include "TaskQueue.h"

namespace taskforge
{

class Worker
{
public:
    explicit Worker(TaskQueue& taskQueue);

    ~Worker();

    Worker(const Worker&) = delete;
    Worker& operator=(const Worker&) = delete;

    Worker(Worker&&) = delete;
    Worker& operator=(Worker&&) = delete;

    void start();
    void stop();

private:
    void run();

    TaskQueue& taskQueue_;

    std::thread thread_;
};

} // namespace taskforge