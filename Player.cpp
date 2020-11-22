#include "Player.h"

Player::Player() 
{
  alive = true;
  mBankAccount = 15000;
  XP = 0;
  mPlayerLevel = 0;
}

std::string Player::getName() 
{
  return std::string();
}

void Player::setName(std::string newName) 
{
  mName = newName;
}

int Player::getBalance() 
{
  return mBankAccount;
}

void Player::setBalance(int newBalance) 
{
  mBankAccount = newBalance;
}

void Player::Equip(int newVal)
{
  
}

void Player::Fire(int eqVal)
{
  //Inventory[eqVal].
}

void Player::LevelUp() 
{
  mPlayerLevel = mPlayerLevel + 1;
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