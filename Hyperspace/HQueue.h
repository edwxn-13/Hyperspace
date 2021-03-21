#pragma once
#include "GameWorld.h"
#include <vector>
class HQueue 
{
public:
  HQueue();
  void enQueue(Sector);
  Sector deQueue();
  int size();
  bool contains(Sector);
private:
  int pointer;
  std::vector<Sector> queueList;
};

