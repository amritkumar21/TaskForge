#include "TaskQueue.h"

namespace taskforge
{
    void TaskQueue::push(std::unique_ptr<Task> task)
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            queue_.push(std::move(task));
        }
        condition_.notify_one();
    }

    std::unique_ptr<Task> TaskQueue::pop()
    {
        
    }
} // namespace taskforge