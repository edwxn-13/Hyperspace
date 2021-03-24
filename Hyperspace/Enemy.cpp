#include "Enemy.h"

/*
 * Spawns enemy based on threat level
 * Higher threat level will spawn more powerful enemys with more powerful equipment
 */
Enemy::Enemy(int threat) 
{
  Ship newShip(threat);
  mShip = newShip;
  mShip.makeArmour(100 * threat);
  mShip.makeShields(125 * threat);

  if (threat < 2) 
  {
    mShip.mHardpoints[0] = Weapon("Light Assault Laser" , 20 , 100 , 8, 1);
    mShip.setName("Light Fighter");
  }

  else if (threat < 4)
  {
    mShip.mHardpoints[0] = Weapon("Light Assault Laser", 40, 620, 14, 2);
    mShip.setName("Medium Fighter");
  }

  else
  {
    mShip.mHardpoints[0] = Weapon("Light Assault Laser", 55, 1340, 7, 4);
    mShip.setName("Heavy Assault Frigate");
  }
}
/*
 * Enemy battle logic
 * First attacks
 * Decides if it wants to retreat
 */
Player Enemy::attack(GamePackage gamePackage)
{
  Ship target = gamePackage.nUser.getShip();
  target.damageShip(mShip.mHardpoints[0].useEquipment());
  gamePackage.nUser.setShip(target);
  return gamePackage.nUser;
}

Ship Enemy::getShip() 
{
  return mShip;
}

void Enemy::setShip(Ship newShip)
{
  mShip = newShip;
}
/*
 Decides if the enemy should retreat from the combat
 */
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
    int retreatChance = rand() % 25;

    if (retreatChance < 3) 
    {
      std::cout << "\n<<The enemy " << mShip.getName() << " has retreated>>\n\n";
      return true;
    }

    else {return false;}
  }
}
/*
 Enemy armour and shields are displayed
 */
void Enemy::displayStats()
{
  std::cout << "\n";

  for (int i = 0; i < mShip.nSystems.size(); i++)
  {
    std::cout << i + 1 << ". " << mShip.nSystems[i].nName << " integrity" << ": " << mShip.nSystems[i].integrity << " - ";
  }
  std::cout << "\n";
  std::cout << "\n" << mShip.getName() << "  Shields: " << mShip.getShields() << "  Armour: " << mShip.getArmour() << "\n";
}
