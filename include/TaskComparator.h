#pragma once

#include <memory>
#include "Task.h"

namespace taskforge
{

class TaskComparator
{
public:
    bool operator()(const std::unique_ptr<Task>& lhs,
                    const std::unique_ptr<Task>& rhs) const;
};

} // namespace taskforge