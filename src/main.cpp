#include <iostream>
#include <memory>

#include "Task.h"
#include "TaskQueue.h"
#include "Worker.h"
#include <chrono>
#include <thread>

int main()
{
    taskforge::TaskQueue taskQueue;
    taskforge::Worker worker(taskQueue);

    worker.start();

    for(int i = 1; i<=20; i++)
    {
        auto task = std::make_unique<taskforge::Task>
        (
            i,
            "Task " + std::to_string(i),
            taskforge::TaskPriority::Medium,
            [i]()
            {
                if(i==10)
                {
                    throw std::runtime_error("Error in Task " + std::to_string(i));
                }
                std::cout<< "Executing Task " << i << std::endl;
            }

        );
        taskQueue.push(std::move(task));
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    taskQueue.shutdown();
    worker.stop();
}