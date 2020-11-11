#include "Player.h"

Player::Player() 
{
  GameWorld playerWorld;
  alive = true;
  mBankAccount = 15000;
  XP = 0;
  mPlayerLevel = 0;
  std::vector< std::vector<Sector>> startpoint = playerWorld.GetMap();
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

void Player::LevelUp() 
{
  mPlayerLevel = mPlayerLevel + 1;
}

void Player::XPCheck() 
{
  if (XP < 200) 
  {
    XP = 0;
    LevelUp();
  }
}
