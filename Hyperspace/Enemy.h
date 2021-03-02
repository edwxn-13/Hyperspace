#pragma once
#include "Ship.h"
#include "Faction.h"
#include "Equipment.h"
#include <vector>

class Enemy
{
private:
  Ship mShip;
  Faction nFaction;
  std::vector<Equipment> mInventory;
public:
  Enemy(int);
  Ship getShip();

};

