#pragma once
#include "Ship.h"
#include "Faction.h"
#include "Equipment.h"
#include <vector>
#include "ShipSystem.h"
#include "GamePackage.h"

class Enemy
{
private:
  Ship mShip;
  Faction nFaction;
  std::vector<Equipment> mInventory;
public:
  Enemy(int);
  Player attack(GamePackage);
  Ship getShip();
  bool retreat();
  void displayStats();
};

