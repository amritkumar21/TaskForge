#pragma once
#include <cstdint>

namespace taskforge
{
    enum class TaskPriority : std::uint8_t
    {
        Low      = 50,
        Medium   = 100,
        High     = 150,
        Critical = 255
    };
} // namespace taskforge