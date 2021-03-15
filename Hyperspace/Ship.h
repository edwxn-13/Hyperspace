#pragma once
#include <iostream>
#include <vector>
#include "Equipment.h"
#include "Weapon.h"
class Ship
{
public:
  int cost;
  std::string mShipName;
  bool hasShields();
  std::vector<Weapon> mHardpoints; //Locations where weapons can be attached.

private:
  int mShields; // Shield value.
  int mArmour; //Armour value.
  int mHardpointNum; // Number of hardpoints, differs from ship to ship.

public:
  //Initializes a new ship object.
  Ship();
  void setShields(int); //Sets shield value
  void setArmour(int); // Sets armour value.
  int getArmour();
  std::string getName();
};

