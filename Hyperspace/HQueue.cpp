#include "HQueue.h"

HQueue::HQueue()
{
  pointer = 0;
}

void HQueue::enQueue(Sector newVal)
{
  queueList.push_back(newVal); // Adds to queue
}

Sector HQueue::deQueue()
{
  Sector returnSec = queueList[pointer];
  pointer++; // Increments pointer
  return returnSec; // Returns sector
}
/*
 Returns size of queue
 */
int HQueue::size()
{
  return queueList.size() - pointer;
}

bool HQueue::contains(Sector testSec)
{
  for (int i = 0; i < queueList.size(); i++) 
  {
    if (queueList[i].getHash() == testSec.getHash()) { return true; } // Iterates through list until it finds the mathing hash
  }
  return false;
}
