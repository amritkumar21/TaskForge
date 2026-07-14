#include "Worker.h"

namespace taskforge
{
    Worker::Worker(TaskQueue& taskQueue): taskQueue_(taskQueue){}

    void Worker::start()
    {
        thread_ = std::thread(&Worker::run, this);
    }


    Worker::~Worker()
    {
        if(thread_.joinable())
        {
            thread_.join();
        }
    }

    void Worker::run()
    {
        while(true)
        {
            auto task = taskQueue_.pop();

            if(task)
            {
                try
                {
                     task->execute();
                }
                catch(const std::exception& e)
                {
                    std::cerr << " Task execution failed:"
                        <<e.what() << '\n';
                }
                catch (...)
                {
                    std::cerr << "Task execution failed with unknown exception\n";
                }
                  
            }
            else
            {
                break;
            }
        }
    }

}