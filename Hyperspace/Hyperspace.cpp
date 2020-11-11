#include <iostream>
#include "Player.h"
#include "Navigation.h"
#include "GameWorld.h"


Player InitGame(GameWorld world)
{
  Player userPlayer;
  std::string playerName;
  
  std::cout << "Welcome to Hypderspace \nEnter your name \n";
  std::cin >> playerName;
  userPlayer.setName(playerName);
  std::cout << "Welcome back commander " << playerName << "\n";
  
  int size;
  std::cin >> size;
  world.Generate(size);
  
  return userPlayer;
}

Player Travel(Player user , GameWorld world)
{
  DisplayMap(world.GetMap() , world);
  Coords pos = Navigation();
  user.locCord = pos.x;
  user.CurrentPlanet = JumpDrive(pos,world.GetMap());

  return user;
}

void GameLoop(Player user , GameWorld world)
{
  while (user.alive) 
  {
    user = Travel(user,world);
  }
}

int main() 
{
  GameWorld world;
  GameLoop(InitGame(world), world);
}

