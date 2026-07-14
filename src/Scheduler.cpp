#include <stdexcept>
#include "Scheduler.h"

namespace taskforge
{
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
            auto worker = std::make_unique<Worker>(taskQueue_);
            workers_.push_back(std::move(worker));
        }

        for(auto& worker : workers_)
        {
            worker->start();
        }

        started_ = true;

    }


}