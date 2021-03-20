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
}

Ship::Ship(int threat)
{
  fuel = 1000;
  mShields = 100;
  mArmour = 100;
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

int Ship::getFuel()
{
  return fuel;
}

void Ship::burnFuel(int newVal)
{
  fuel = fuel - newVal;
}

std::string Ship::getName()
{
  return mShipName;
}
