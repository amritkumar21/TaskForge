#include <iostream>
#include <memory>

#include "Task.h"
#include "Scheduler.h"
#include <chrono>
#include <thread>

int main()
{
    taskforge::Scheduler scheduler;

    scheduler.start(4);

    for(int i =0; i <= 20; i++)
    {
     
        auto task =  std::make_unique<taskforge::Task>
                     (
                        i,
                        "Task " + std::to_string(i),
                        taskforge::TaskPriority::Medium,
                        [i]()
                        {
                            std::cout <<" Executing Task " << i <<std::endl;
                            std::this_thread::sleep_for(std::chrono::milliseconds(100));
                        }
                     );
                       

        scheduler.submitTask(std::move(task));
        
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Stopping Scheduler..." << std::endl;
    scheduler.stop();
}