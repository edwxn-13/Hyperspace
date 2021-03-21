#include "Ship.h"


bool Ship::hasShields()
{
  if (mShields > 0) 
  {
    return true;
  }

  else
  {
    return false;
  }
}

Ship::Ship()
{
  mHardpoints.push_back(Weapon());
  oFuel = 1000;
  oShields = 100;
  oArmour = 100;
  fuel = oFuel;
  mShields = oShields;
  mArmour = oArmour;
  nSystems.push_back(ShipSystem("Thrusters"));
  nSystems.push_back(ShipSystem("Shield Emitter"));
  nSystems.push_back(ShipSystem("Weapons"));
}

Ship::Ship(int threat)
{
  mHardpoints.push_back(Weapon());
  oFuel = 1000;
  oShields = 100;
  oArmour = 100;
  fuel = oFuel;
  mShields = oShields;
  mArmour = oArmour;
  nSystems.push_back(ShipSystem("Thrusters"));
  nSystems.push_back(ShipSystem("Shield Emitter"));
  nSystems.push_back(ShipSystem("Weapons"));
}

void Ship::setShields(int newVal) 
{
  mShields = mShields - newVal;
}


void Ship::setArmour(int newVal)
{
  mArmour = mArmour - newVal;
}

int Ship::getArmour()
{
    return mArmour;
}

int Ship::getShields()
{
  return mShields;
}

int Ship::getFuel()
{
  return fuel;
}

void Ship::burnFuel(int newVal)
{
  fuel = fuel - newVal;
}

void Ship::repair()
{
  mShields = oShields;
  mArmour = oArmour;
  fuel = oFuel;
  std::cout << "\n<<Ship Succesfully Restored>>>\n\n";
}

std::string Ship::getName()
{
  return mShipName;
}
