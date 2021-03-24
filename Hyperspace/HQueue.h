#pragma once
#include "GameWorld.h"
#include <vector>
class HQueue 
{
public:
  HQueue();
  void enQueue(Sector); // Adds sector to the queue
  Sector deQueue(); // Pops sector from the queue
  int size(); // 
  bool contains(Sector);
private:
  int pointer;
  std::vector<Sector> queueList;
};

