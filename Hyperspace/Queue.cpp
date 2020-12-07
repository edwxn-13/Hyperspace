#include "Queue.hpp"

EncounterQueue::EncounterQueue()
{
  frontPointer = 0;
  
}

void EncounterQueue::enQueue(Encounter newEncounter)
{
  nQueue.push_back(newEncounter);
  
}

Encounter EncounterQueue::deQueue()
{
  Encounter rEncounter;
  rEncounter = nQueue[frontPointer];
  frontPointer++;
  return rEncounter;
}
