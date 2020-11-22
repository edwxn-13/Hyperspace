#pragma once
#include <iostream>
#include <vector>
#include "Equipment.h"
class Ship
{
public:
  int cost;
  std::string mShipName;
private:
  int mShields; // Shield value.
  int mArmour; //Armour value.
  int mHardpointNum; // Number of hardpoints, differs from ship to ship.
  std::vector<Equipment> mHardpoints; //Locations where weapons can be attached.

public:
  //Initializes a new ship object.
  Ship();
  void setShields(int); //Sets shield value
  void setArmour(int); // Sets armour value.
};

