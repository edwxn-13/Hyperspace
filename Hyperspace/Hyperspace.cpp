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

  int size = integerInput();

  GameWorld gameWorld(size);
  gameWorld.initialize();
  userPlayer.CurrentSector = gameWorld.UniverseList[0];
  GamePackage package(gameWorld , userPlayer);

  return package;
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
    gamePackage.nUser = DisplayMenu(gamePackage);
  }
}

int main() 
{
  GamePackage package = InitGame();
  GameLoop(package);
}

