#include "Player.h"

Player::Player() 
{
  nPlayerShip = Ship();
  nInventory.push_back(nPlayerShip.mHardpoints[0]);
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

void Player::setSector(Sector newSector)
{
  CurrentSector = newSector;
}

void Player::displayStats()
{
  CurrentSector.display();
  std::cout << "\nCredits: " << nBankAccount <<  "\n" << nPlayerShip.getName() << "  Shields: " << nPlayerShip.getShields() << "  Armour: " << nPlayerShip.getArmour() << "\n";
}

void Player::purchase(Weapon newWeapon)
{
  if (nBankAccount > newWeapon.getPrice())
  {
    nBankAccount = nBankAccount - newWeapon.getPrice();
    nInventory.push_back(newWeapon);
    std::cout << "\n<<Purchase Succesful>>\n";
  }

  else
  {
    std::cout << "\n<<Insufficient Funds>>\n";
  }
}

void Player::purchase(Ship newShip)
{
  if (nBankAccount > newShip.getPrice())
  {
    nBankAccount = nBankAccount - newShip.getPrice();
    nPlayerShip = newShip;
    std::cout << "\n<<Purchase Succesful>>\n";
  }

  else
  {
    std::cout << "\n<<Insufficient Funds>>\n";
  }
}

Ship Player::getShip()
{
  return nPlayerShip;
}

void Player::setShip(Ship newShip)
{
  nPlayerShip = newShip;
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
