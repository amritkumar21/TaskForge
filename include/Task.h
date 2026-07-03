#pragma once

#include <functional>
#include <string>

#include "TaskState.h"
#include "TaskPriority.h"
#include "TaskId.h"

namespace taskforge
{
    class Task
    {
    public:
            Task(TaskId id,
                 const std::string& name,
                 TaskPriority priority,
                 std::function<void()> callback);
            
            Task(const Task&) = delete;
            Task& operator=(const Task&) = delete;

            Task(Task&&) noexcept = default;

            Task& operator=(Task&&) noexcept = default;
            
            TaskId getId() const;

            const std::string& getName() const;

            TaskPriority getPriority() const;

            TaskState getState() const;

            void execute();

        private:
                TaskId taskId_;

                std::string name_;

                TaskPriority priority_;

                TaskState state_;
                
                std::function<void()> callback_;
    };

} //namespace taskforge
