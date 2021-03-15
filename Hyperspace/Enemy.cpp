#include "Enemy.h"

Enemy::Enemy(int threat) 
{
  mShip.setArmour(100 * threat);
  mShip.setArmour(1200 * threat);
  nSystems.push_back(ShipSystem("Thrusters"));
  nSystems.push_back(ShipSystem("Shield Emitter"));
  nSystems.push_back(ShipSystem("Weapons"));

}

Player Enemy::attack(GamePackage gamePackage)
{

  return gamePackage.nUser;
}

Ship Enemy::getShip() 
{
  return mShip;
}

bool Enemy::retreat()
{
  if (nSystems[0].integrity < 1) 
  {
    return false;
  }

  else if (nSystems[1].integrity < 1) 
  {
    std::cout << "\n<<The enemy " << mShip.getName() << " has retreated>>\n\n";
    return true;
  }

  else 
  {
    srand(time(0));
    int retreatChance = rand() % 10;

    if (retreatChance < 3) 
    {
      std::cout << "\n<<The enemy " << mShip.getName() << " has retreated>>\n\n";
      return true;
    }

    else {return false;}
  }
}
