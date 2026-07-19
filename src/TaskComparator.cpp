#include "TaskComparator.h"

namespace taskforge
{
    bool TaskComparator::operator()(const std::unique_ptr<Task>& lhs,
                                   const std::unique_ptr<Task>& rhs) const
    {
       if(lhs->getPriority() != rhs->getPriority())
       {
             // Lower priority should come after higher priority.
            if(lhs->getPriority() < rhs->getPriority())
            {
                return true;
            }
            else
            {
                return false;
            }
       }
       else
       {
          // Among equal priorities, later submitted tasks should come after earlier tasks.
          if(lhs->getSequenceNumber() < rhs->getSequenceNumber())
          {
             return false;
          }
          else
          {
            return true;
          }
       }
    }

}