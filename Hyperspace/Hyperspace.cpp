#include "Navigation.h"

GamePackage InitGame()
{
  
  Player userPlayer;
  std::string playerName;
  
  std::cout << "Welcome to Hyperspace \nEnter your name : ";
  std::cin >> playerName;
  userPlayer.setName(playerName);
  std::cout << "Welcome back commander " << playerName << "\n";
  
  std::cout << "\nSelect size: ";
  int size;
  std::cin >> size;

  GameWorld gameWorld(size);
  gameWorld.initialize();
  userPlayer.CurrentSector = gameWorld.UniverseList[0];
  GamePackage package(gameWorld , userPlayer);

  return package;
}

Faction::FContainer FactionInit(NaturalResource::RContainer rContainer) 
{
  Faction::FContainer fContainer;
  Faction f1(rContainer, 0);
  Faction f2(rContainer, 1);
  Faction f3(rContainer, 2);

  fContainer.nFactionList.push_back(f1);
  fContainer.nFactionList.push_back(f2);
  fContainer.nFactionList.push_back(f3);

  return fContainer;
}

Sector Travel(GamePackage gamePackage)
{
  Sector desSector;
  desSector = JumpDrive(gamePackage);
  return desSector;
}

void GameLoop(GamePackage gamePackage)
{
  /*
   
   First the user is on the menu
   They can select what they want to do
   Go to navigation
   Select a new sector
   Route plotted
   Jump drive
   Encounter is generated or player can visit local station
  
   */
  while (gamePackage.nUser.alive) 
  {
    DisplayMenu(gamePackage);
    gamePackage.nUser.CurrentSector = Travel(gamePackage);
    InitEncoutner(gamePackage);
  }
}

int main() 
{
  GamePackage package = InitGame();
  GameLoop(package);
}

