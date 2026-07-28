#include <stdexcept>
#include "Scheduler.h"

namespace taskforge
{
    Scheduler::Scheduler()
    {
    }

    void Scheduler::start(std::size_t numWorkers)
    {
        if(started_)
        {
            throw std::logic_error("Schedular has already been started");
        }
        if(numWorkers == 0)
        {
            throw std::invalid_argument("Number of workers must be greater than 0");
        }

        for(std::size_t i =0;i<numWorkers;i++)
        {
            workers_.push_back(std::make_unique<Worker>(taskQueue_));
        }

        for(auto& worker : workers_)
        {
            worker->start();
        }

        started_ = true;

    }

    void Scheduler::submitTask(std::unique_ptr<Task> task)
    {
        if(!task)
        {
            throw std::invalid_argument("Task cannot be null.");
        }
        if(!started_)
        {
            throw std::logic_error("Scheduler has not been started");
        }
        taskQueue_.push(std::move(task));
    }

    void Scheduler::stop()
    {
        if(!started_)
        {
            throw std::logic_error("Scheduler has not been started");
        }

        taskQueue_.shutdown();

        workers_.clear();
        started_ = false;
    }


}// namespace taskforge