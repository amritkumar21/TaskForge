#pragma once
#include <cstdint>

namespace taskforge
{
    enum class TaskState : std::uint8_t
    {
        Created,
        Queued,
        Running,
        Completed,
        Failed,
        Canceled
    };
} // namespace taskforge