#pragma once
#include "GamePackage.h"
#include "Enemy.h"
class RandomEncounter 
{
public:
  RandomEncounter(int);
  GamePackage Combat(GamePackage gamePackage);
private:
  int threat;
  std::vector<Enemy> nEnemyContainer;

};

