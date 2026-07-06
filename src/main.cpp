#include <iostream>
#include <memory>

#include "Task.h"
#include "TaskQueue.h"

int main()
{
    taskforge::TaskQueue queue;

    std::cout << "===== Sprint 3 TaskQueue Test =====\n\n";

    // Create Task 1
    auto task1 = std::make_unique<taskforge::Task>(
        1,
        "Send Email",
        taskforge::TaskPriority::High,
        []()
        {
            std::cout << "Executing Task 1...\n";
        });

    // Create Task 2
    auto task2 = std::make_unique<taskforge::Task>(
        2,
        "Generate Report",
        taskforge::TaskPriority::Medium,
        []()
        {
            std::cout << "Executing Task 2...\n";
        });

    std::cout << "Queue Empty : "
              << std::boolalpha
              << queue.empty() << '\n';

    std::cout << "\nPushing Tasks...\n";

    queue.push(std::move(task1));
    queue.push(std::move(task2));

    std::cout << "Queue Size  : "
              << queue.size() << '\n';

    std::cout << "Queue Empty : "
              << queue.empty() << "\n\n";

    auto task = queue.pop();

    std::cout << "Popped Task\n";
    std::cout << "Task ID     : " << task->getId() << '\n';
    std::cout << "Task Name   : " << task->getName() << '\n';

    std::cout << "\nExecuting Task...\n";
    task->execute();

    std::cout << "\nQueue Size  : "
              << queue.size() << '\n';

    std::cout << "Queue Empty : "
              << queue.empty() << '\n';

    return 0;
}