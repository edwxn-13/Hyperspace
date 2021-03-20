#include "HQueue.h"

HQueue::HQueue()
{
  pointer = 0;
}

void HQueue::enQueue(Sector newVal)
{
  queueList.push_back(newVal);
}

Sector HQueue::deQueue()
{
  Sector returnSec = queueList[pointer];
  pointer++;
  return returnSec;
}

int HQueue::size()
{
  return queueList.size() - pointer;
}
