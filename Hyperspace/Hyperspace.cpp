#include <iostream>
#include "Player.h"
#include "Navigation.h"
#include "GameWorld.h"


Player InitGame()
{
  Player userPlayer;
  std::string playerName;
  std::cout << "Welcome to Hypderspace \nEnter your name \n";
  std::cin >> playerName;
  userPlayer.setName(playerName);
  std::cout << "Welcome back commander " << playerName << "\n";

  GameWorld.Generate();
  return userPlayer;
}

Player Travel(Player user)
{

  DisplayMap(starMap);
  Coords pos = Navigation();
  user.locCord = pos.x;
  user.CurrentPlanet = JumpDrive(pos,starMap);

  return user;
}

void GameLoop(Player user) 
{
  while (user.alive) 
  {
    user = Travel(user);
  }
}

int main() 
{
  GameLoop(InitGame());
}

