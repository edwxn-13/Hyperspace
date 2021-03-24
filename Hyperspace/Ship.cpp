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
  mHardpoints.push_back(Weapon("Triton Light Laser", 40, 10 , 90, 1));
  for (int i = 0; i < 5; i++) 
  {
    mHardpoints.push_back(Weapon("Empty Slot", 0, 0, 0, 0));
  }
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

Ship::Ship(std::string name, int shields, int armour, int fuel, int price)
{
  nPrice = price;
  oFuel = fuel;
  oShields = shields;
  oArmour = armour;
  fuel = oFuel;
  mShields = oShields;
  mArmour = oArmour;
  nSystems.push_back(ShipSystem("Thrusters")); //Makes new subsystem called Thrusters
  nSystems.push_back(ShipSystem("Shield Emitter"));//Makes new subsystem called Shield Emitter
  nSystems.push_back(ShipSystem("Weapons"));//Makes new subsystem called Weapons
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
  nSystems.push_back(ShipSystem("Thrusters")); //Makes new subsystem called Thrusters
  nSystems.push_back(ShipSystem("Shield Emitter")); //Makes new subsystem called Shield Emitter
  nSystems.push_back(ShipSystem("Weapons")); //Makes new subsystem called Weapons
}

void Ship::makeShields(int newVal)
{
  mShields = newVal;
  oShields = newVal;
}

void Ship::makeArmour(int newVal)
{
  mShields = newVal;
  oShields = newVal;
}

void Ship::setShields(int newVal)
{
  mShields = mShields - newVal;
}


void Ship::setArmour(int newVal)
{
  mArmour = mArmour - newVal;
}

void Ship::damageShip(int dmgVal)
{
  if (!hasShields()) 
  {
    setArmour(dmgVal);
    std::cout << "\n<<" << dmgVal << " damage dealt>>";
  }

  else 
  {
    setShields(dmgVal);
    std::cout << "\n<<" << dmgVal << " shield damage>>";

  }
}

void Ship::damageSystem(int dmgVal, int systemInt)
{
  if (!hasShields())
  {
    setArmour(dmgVal / 10);
    nSystems[systemInt - 1].integrity = nSystems[systemInt - 1].integrity - dmgVal / 5;
    std::cout << "\n<<" << dmgVal/5 << " system damage>>";
    std::cout << "\n<<" << dmgVal/10 << " armour damage>>";
  }

  else
  {
    setShields(dmgVal);
    std::cout << "\n<<" << dmgVal << " shield damage>>";
  }
}

void Ship::setName(std::string newVal)
{
  mShipName = newVal;
}

int Ship::getArmour()
{
    return mArmour;
}

int Ship::getPrice()
{
  return nPrice;
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
