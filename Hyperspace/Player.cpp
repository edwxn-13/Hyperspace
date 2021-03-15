#include "Player.h"

Player::Player() 
{
  alive = true;
  nBankAccount = 15000;
  XP = 0;
  nPlayerLevel = 0;
}

std::string Player::getName() 
{
  return std::string();
}

void Player::setName(std::string newName) 
{
  mName = newName;
}

Weapon Player::getInventroy(int index)
{
  return nPlayerShip.mHardpoints[index];
}

int Player::getBalance() 
{
  return nBankAccount;
}

void Player::setBalance(int newBalance) 
{
  nBankAccount = newBalance;
}

void Player::Equip(int newVal)
{
  
}


void Player::useEquipment(int eqVal)
{
  //Inventory[eqVal].
}

void Player::LevelUp() 
{
  nPlayerLevel = nPlayerLevel + 1;
}
/*
 Checks the players XP amount,
 if it is a sufficient level the player levels up
 */
void Player::XPCheck() 
{
  if (XP < 200) 
  {
    XP = 0;
    LevelUp();
  }
}
