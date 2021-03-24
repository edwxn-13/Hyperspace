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
  Ship mShip;// Enemy Ship 
  Faction nFaction; // Enemy Faction
  std::vector<Equipment> mInventory;// Enemy weapons
public:
  Enemy(int);
  Player attack(GamePackage);
  Ship getShip();
  void setShip(Ship);
  bool retreat();
  void displayStats();
};

