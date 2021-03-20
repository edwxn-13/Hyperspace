#include "Enemy.h"

Enemy::Enemy(int threat) 
{
  Ship newShip(threat);
  mShip = newShip;
  mShip.setArmour(100 * threat);
  mShip.setShields(1200 * threat);
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
  if (mShip.nSystems[0].integrity < 1) 
  {
    return false;
  }

  else if (mShip.nSystems[1].integrity < 1) 
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

void Enemy::displayStats()
{
  std::cout << mShip.getName() << "  Shields: " << mShip.getShields() << "  Armour: " << mShip.getArmour();
}
