#pragma once
#include "GameWorld.h"
#include <vector>
class HQueue 
{
public:
  HQueue();
  void enQueue(Sector); // Adds sector to the queue
  Sector deQueue(); // Pops sector from the queue
  int size(); // Size of queue
  bool contains(Sector); // Returns if the queue contains @param
private:
  int pointer; // front pointer
  std::vector<Sector> queueList; // base list
};

