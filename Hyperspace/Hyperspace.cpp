#include <iostream>
#include "Navigation.h"




GamePackage InitGame()
{
  
  Player userPlayer;
  std::string playerName;
  
  std::cout << "Welcome to Hypderspace \nEnter your name \n";
  std::cin >> playerName;
  userPlayer.setName(playerName);
  std::cout << "Welcome back commander " << playerName << "\n";
  
  int size;
  std::cin >> size;

  GameWorld gameWorld(size);
  gameWorld.Initialize();

  GamePackage package;
  package.gameworld = gameWorld;
  package.user = userPlayer;

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
  while (gamePackage.user.alive) 
  {
    gamePackage.user.CurrentSector = Travel(gamePackage);
  }
}

int main() 
{
  GameLoop(InitGame());
}

