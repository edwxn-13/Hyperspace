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

std::string Ship::getName()
{
  return mShipName;
}
