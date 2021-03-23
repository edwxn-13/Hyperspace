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

std::vector<Weapon> Player::getInventroy()
{
  return nInventory;
}

Weapon Player::getCargo(int index)
{
  return nInventory[index];
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
  std::cout << "\n";

  std::cout << "\nCredits: " << nBankAccount << "\n" << nPlayerShip.getName()
    << "  Shields: " << nPlayerShip.getShields() << "  Armour: " << nPlayerShip.getArmour() << "\n";
  std::cout << "\n";
  std::cout << "<<Systems>>\n";
  for (int i = 0; i < nPlayerShip.nSystems.size(); i++)
  {
    std::cout << i + 1 << ". " << nPlayerShip.nSystems[i].nName << " integrity"<< ": " << nPlayerShip.nSystems[i].integrity << " - ";
  }
  std::cout << "<<Weapons>>\n";
  std::cout << "\n";
  for (int i = 0; i < nPlayerShip.mHardpoints.size(); i++) 
  {
    std::cout << i + 1 << ". " << nPlayerShip.mHardpoints[i].getName() << " - ";
  }


  
}

void Player::displayStats(int input)
{
  std::cout << nInventory[input - 1].getName() << " Price: " << nInventory[input - 1].getPrice() << " Damage: " << nInventory[input - 1].getDamage() << "\n";
}
/*
 Player buys item selected by user from station;
 */
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

/*
 Sells item selected by player
 */
void Player::sell(int input)
{
  if (CurrentSector.hasPlanet()) 
  {
    nBankAccount = nBankAccount + nInventory[input - 1].getPrice();
    std::cout << "\n\n<Sold for " << nInventory[input - 1].getPrice() << ">>\n";
    nInventory.erase(nInventory.begin() + input - 1);
  }

  else { std::cout << "\n\n<<No Nearby Station>>\n"; }
}

void Player::toggleEquip(int index)
{
  if (nInventory[index - 1].getState()) 
  {
    nPlayerShip.mHardpoints[nInventory[index - 1].getPos()].empty();
    nInventory[index - 1].toggleEquip();
    std::cout << "\n<<Succesfully Unequipped Weapon>>\n";
  }

  else 
  { 
    nPlayerShip.mHardpoints[index - 1] = nInventory[index - 1];
    nInventory[index - 1].toggleEquip();
    std::cout << "\n<<Succesfully Equipped Weapon>>\n";
  }
}

void Player::discard(int input)
{
  nInventory.erase(nInventory.begin() + input - 1);
}

Ship Player::getShip()
{
  return nPlayerShip;
}

void Player::setShip(Ship newShip)
{
  nPlayerShip = newShip;
}
/*
 Equips selected Itemn
 */
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
