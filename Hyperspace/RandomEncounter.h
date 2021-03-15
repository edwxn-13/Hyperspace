#pragma once
#include "GamePackage.h"
#include "Enemy.h"
#include "Weapon.h"
class RandomEncounter 
{
public:
  RandomEncounter(int);
  GamePackage CombatInit(GamePackage);
  GamePackage Combat(GamePackage gamePackage);
private:
  int threat;
  std::vector<Enemy> nEnemyContainer;

};

