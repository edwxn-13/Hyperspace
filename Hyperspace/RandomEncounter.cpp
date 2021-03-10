#include "RandomEncounter.h"
RandomEncounter::RandomEncounter(int threatVal) 
{
  threat = threatVal;
}

GamePackage RandomEncounter::Combat(GamePackage gamePackage)
{
  for (int i = 0; i < rand() % 5; i++)
  {
    nEnemyContainer.push_back(Enemy(threat));
  }
  return gamePackage;
  bool encounterStatus = true;
  while (encounterStatus) 
  {
    int pTargetChoice;
    int pWeaponChoice;
    int pSystemChoice;
    int eTargetChoice;
    int eWeaponChoice;
    int eSystemChoice;
  }
}