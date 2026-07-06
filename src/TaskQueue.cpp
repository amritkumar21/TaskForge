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
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return !queue_.empty();});
        auto task = std::move(queue_.front());
        queue_.pop();
        return task;
    }

    bool TaskQueue::empty() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }

    size_t TaskQueue::size() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size();
    }
} // namespace taskforge