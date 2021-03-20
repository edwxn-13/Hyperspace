#pragma once
#include <iostream>
#include <vector>
#include "Equipment.h"
#include "Weapon.h"
#include "ShipSystem.h"
class Ship
{
public:
  int cost;
  std::string mShipName;
  bool hasShields();
  std::vector<Weapon> mHardpoints; //Locations where weapons can be attached.

private:
  int fuel;
  int mShields; // Shield value.
  int mArmour; //Armour value.
  int mHardpointNum; // Number of hardpoints, differs from ship to ship.

public:
  //Initializes a new ship object.
  Ship();
  Ship(int);
  std::vector<ShipSystem> nSystems;
  void setShields(int); //Sets shield value
  void setArmour(int); // Sets armour value.
  int getArmour();
  int getFuel();
  void burnFuel(int);
  std::string getName();
};

