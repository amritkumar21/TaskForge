#include "Task.h"

#include <utility>
#include <stdexcept>

namespace taskforge
{

Task::Task(TaskId id,
           const std::string& name,
           TaskPriority priority,
           std::function<void()> callback)
    : taskId_(id),
      name_(name),
      priority_(priority),
      state_(TaskState::Created),
      callback_(std::move(callback))
{
}

TaskId Task::getId() const
{
    return taskId_;
}

const std::string& Task::getName() const
{
    return name_;
}

TaskPriority Task::getPriority() const
{
    return priority_;
}

TaskState Task::getState() const
{
    return state_;
}

void Task::execute()
{
    callback_();
}

std::optional<std::uint64_t> Task::getSequenceNumber() const
{
    return sequenceNumber_;
}

void Task::setSequenceNumber(std::uint64_t sequenceNumber)
{
    if (sequenceNumber_.has_value())
    {
      throw std::logic_error("Sequence number already assigned.");
    }
    sequenceNumber_ = sequenceNumber;
}

} // namespace taskforge