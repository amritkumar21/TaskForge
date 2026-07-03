#include <iostream>

#include "Task.h"

int main()
{
    taskforge::Task task(
        1,
        "Send Email",
        taskforge::TaskPriority::High,
        []()
        {
            std::cout << "Executing callback...\n";
        });

    std::cout << "Task ID       : " << task.getId() << '\n';
    std::cout << "Task Name     : " << task.getName() << '\n';

    std::cout << "Executing Task...\n";

    task.execute();

    std::cout << "Execution Finished\n";

    return 0;
}