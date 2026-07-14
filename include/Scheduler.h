#pragma once

#include <cstddef>
#include <memory>
#include <vector>

#include "TaskQueue.h"
#include "Worker.h"

namespace taskforge
{

class Scheduler
{
public:
    Scheduler();

    ~Scheduler() = default;

    Scheduler(const Scheduler&) = delete;
    Scheduler& operator=(const Scheduler&) = delete;

    Scheduler(Scheduler&&) = delete;
    Scheduler& operator=(Scheduler&&) = delete;

    void start(std::size_t numWorkers);

    void stop();

    void submitTask(std::unique_ptr<Task> task);

private:
    TaskQueue taskQueue_;

    std::vector<std::unique_ptr<Worker>> workers_;

    bool started_{false};
};

} // namespace taskforge