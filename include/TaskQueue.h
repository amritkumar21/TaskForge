#pragma once

#include <cstddef>
#include <memory>
#include <mutex>
#include <queue>

#include "Task.h"

namespace taskforge
{

class TaskQueue
{
public:
    void push(std::unique_ptr<Task> task);

    std::unique_ptr<Task> pop();

    bool empty() const;

    std::size_t size() const;

private:
    std::queue<std::unique_ptr<Task>> queue_;

    std::mutex mutex_;
};

} // namespace taskforge