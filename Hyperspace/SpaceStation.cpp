#include "SpaceStation.h"
#include "Player.h"
SpaceStation::SpaceStation()
{
}

/*
* Adds stock to the store depending on tech level
* the higher the tech level the more powerful the equipment
*/
SpaceStation::SpaceStation(int tech)
{
  if (tech == 1) 
  {
    nShop.push_back(Weapon("Stalker Battle Cannon", 40, 140, 5, tech));
    nShop.push_back(Weapon("Primal Carbon Launcher", 100, 200 , 60, tech));
    nShop.push_back(Weapon("Honed Blaster", 40, 140, 5, tech));
    nShop.push_back(Weapon("Twilight's Obsidian Sniper", 200, 4000, 5, tech));

    nHanger.push_back(Ship("Calypso", 150, 150, 3000, 15000));
    nHanger.push_back(Ship("LWSS Phoenix", 90, 90, 3000, 1500));
    nHanger.push_back(Ship("Bayonet", 400, 150, 5000, 20000));
  }

  if (tech < 3)
  {
    nShop.push_back(Weapon("Heinous Rifle", 60, 240, 5, tech));
    nShop.push_back(Weapon("Barbaric Steel Blaster", 100, 400, 60, tech));
    nShop.push_back(Weapon("Phantom Gilded Launcher", 20, 840, 5, tech));
    nShop.push_back(Weapon("Stormrider", 200, 4000, 5, tech));

    nHanger.push_back(Ship("Vindicator", 1250, 150, 3000, 400000));
    nHanger.push_back(Ship("Bayonet II", 650, 425, 7000, 50000));
    nHanger.push_back(Ship("Apollo", 1000, 150, 5000, 75000));
  }

  else if (tech < 6)
  {
    nShop.push_back(Weapon("Devastator Battle Cannon", 900, 5400, 5, tech));
    nShop.push_back(Weapon("Boomstick", 900, 6156, 60, tech));
    nShop.push_back(Weapon("Honed Blaster", 40, 3052, 50, tech));
    nShop.push_back(Weapon("Enterprise", 200, 4000, 25, tech));

    nHanger.push_back(Ship("Experimental Class Ulysses", 5000, 1500, 20000, 150530));
    nHanger.push_back(Ship("ISS Seleucia", 5000, 1500, 20000, 700000));
    nHanger.push_back(Ship("HWSS Starfall Anniversary Frigate", 50000, 70000, 200000, 75000000000));
  }
}

/*
* Allows the user to buy the item they select
*/
Player SpaceStation::market(Player user)
{
  int input;
  std::cin >> input;
  if (input < 5)
  {
    user.purchase(nShop[input - 1]); // User buys a weapon if input is less than 5
  }

  else
  {
    user.purchase(nHanger[input - nShop.size() - 1]); // Any other input the user buys a ship
  }

  return user;
}

/*
* Displays the store listings
*/
void SpaceStation::displayGoods() 
{
  std::cout << "\nWeapons: \n\n";
  for (int i = 0; i < nShop.size(); i++) 
  {
    std::cout << i + 1 << ". "<< nShop[i].getName() << " Price: " << nShop[i].getPrice() << " Damage: " << nShop[i].getDamage() << "\n";
  }
  std::cout << "\nShips: \n\n";
  for (int i = 0; i < nHanger.size(); i++)
  {
    std::cout << i+nShop.size()+1 << ". " << nHanger[i].getName() << " Price: " << nHanger[i].getPrice() << " Shields: " << nHanger[i].getShields() << " Armour: " << nHanger[i].getArmour() << "\n";
  }
}
