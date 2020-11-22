#include "Enemy.h"

Enemy::Enemy(int threat) 
{
  mShip.setArmour(100 * threat);
  mShip.setArmour(1200 * threat);
}

Ship Enemy::getShip() 
{
  return mShip;
}