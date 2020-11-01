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
  int mShields;
  int mArmour;
  int mHardpointNum;
  std::vector<Equipment> mHardpoints;

public:
  //Initializes a new ship object.
  Ship();
  void setShields(int);
  void setArmour(int);
};

