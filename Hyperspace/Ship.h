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
  int oShields;
  int oArmour;
  int nPrice;
  int oFuel;
  int mShields; // Shield value.
  int mArmour; //Armour value.
  int mHardpointNum; // Number of hardpoints, differs from ship to ship.

public:
  //Initializes a new ship object.
  Ship();
  Ship(std::string name, int shields, int armour, int fuel, int price);
  Ship(int);
  std::vector<ShipSystem> nSystems;
  void makeShields(int);
  void makeArmour(int);
  void setShields(int); //Sets shield value
  void setArmour(int); // Sets armour value.
  void damageShip(int);
  void damageSystem(int , int);
  void setName(std::string);
  int getArmour();
  int getPrice();
  int getShields();
  int getFuel();
  void burnFuel(int);
  void repair();
  std::string getName();
};

