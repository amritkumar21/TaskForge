#include <iostream>
#include <memory>

#include "Task.h"
#include "Scheduler.h"
#include <chrono>
#include <thread>

int main()
{
    // =====================================================
    // Test 1 : Priority Ordering
    // =====================================================
    std::cout << "\n========== TEST 1 : Priority Ordering ==========\n";

    {
        taskforge::Scheduler scheduler;
        scheduler.start(1);

        // Submit in random order
        // Expected:
        // Critical -> High -> Medium -> Low

        // Task 1 - Medium
        // Task 2 - Low
        // Task 3 - Critical
        // Task 4 - High
        //

        scheduler.stop();
    }

    // =====================================================
    // Test 2 : FIFO
    // =====================================================
    std::cout << "\n========== TEST 2 : FIFO ==========\n";

    {
        taskforge::Scheduler scheduler;
        scheduler.start(1);

        // Five Medium priority tasks

        // Expected:
        // 0 1 2 3 4

        //...
        scheduler.submitTask(std::make_unique<taskforge::Task>(0,"Task 0", taskforge::TaskPriority::Medium,[]{
            std::cout << "Executing Task 1 (Medium)\n";
        }));

        scheduler.submitTask(std::make_unique<taskforge::Task>(1,"Task 1", taskforge::TaskPriority::Medium,[]{
            std::cout << "Executing Task 2 (Medium)\n";
        }));
        scheduler.submitTask(std::make_unique<taskforge::Task>(2,"Task 2", taskforge::TaskPriority::Medium,[]{
            std::cout << "Executing Task 3 (Medium)\n";
        }));
        scheduler.submitTask(std::make_unique<taskforge::Task>(3,"Task 3", taskforge::TaskPriority::Medium,[]{
            std::cout << "Executing Task 4 (Medium)\n";
        }));
        scheduler.submitTask(std::make_unique<taskforge::Task>(4,"Task 4", taskforge::TaskPriority::Medium,[]{
            std::cout << "Executing Task 5 (Medium)\n";
        }));

        scheduler.stop();
    }

    // =====================================================
    // Test 3 : Mixed Priorities + FIFO
    // =====================================================
    std::cout << "\n========== TEST 3 : Mixed ==========\n";

    {
        taskforge::Scheduler scheduler;
        scheduler.start(1);

        // A Medium
        // B Critical
        // C Medium
        // D Critical
        // E High

        // Expected:
        // B D E A C

        //...
        scheduler.submitTask(std::make_unique<taskforge::Task>(0,"Task A", taskforge::TaskPriority::Medium,[]{
            std::cout << "Executing Task 0 (Medium)\n";
        }));
        scheduler.submitTask(std::make_unique<taskforge::Task>(1,"Task B", taskforge::TaskPriority::Critical,[]{
            std::cout << "Executing Task 1 (Critical)\n";
        }));
        scheduler.submitTask(std::make_unique<taskforge::Task>(2,"Task C", taskforge::TaskPriority::Medium,[]{
            std::cout << "Executing Task 2 (Medium)\n";
        }));
        scheduler.submitTask(std::make_unique<taskforge::Task>(3,"Task D", taskforge::TaskPriority::Critical,[]{
            std::cout << "Executing Task 3 (Critical)\n";
        }));
        scheduler.submitTask(std::make_unique<taskforge::Task>(4,"Task E", taskforge::TaskPriority::High,[]{
            std::cout << "Executing Task 4 (High)\n";
        }));

        scheduler.stop();
    }

    // =====================================================
    // Test 4 : Concurrent Execution
    // =====================================================
    std::cout << "\n========== TEST 4 : Concurrent ==========\n";

    {
        taskforge::Scheduler scheduler;
        scheduler.start(4);

        // Submit 30-50 tasks with mixed priorities.

        // Order of completion is NOT deterministic.
        // Just verify:
        // 1. No crash
        // 2. No deadlock
        // 3. No lost tasks

        //...

        for(int i = 0; i < 50; ++i)
        {
            taskforge::TaskPriority priority;
            if(i % 4 == 0)
                priority = taskforge::TaskPriority::Critical;
            else if(i % 4 == 1)
                priority = taskforge::TaskPriority::High;
            else if(i % 4 == 2)
                priority = taskforge::TaskPriority::Medium;
            else
                priority = taskforge::TaskPriority::Low;

            scheduler.submitTask(std::make_unique<taskforge::Task>(i,"Task " + std::to_string(i), priority, [i]{
                std::cout << "Executing Task " << i << "\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }));
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        scheduler.stop();
    }
}