#include "Navigation.h"
/*
 * Start the game and triggers all the processes that have to happen
 * before the game can commence
 */
GamePackage InitGame()
{
  Player userPlayer;
  std::string playerName;
  
  std::cout << "Welcome to Hyperspace \nEnter your name : ";
  std::cin >> playerName; //Player enters their name
  userPlayer.setName(playerName);
  std::cout << "Welcome back commander " << playerName << "\n";
  
  std::cout << "\nSelect Game World size: ";

  int size = integerInput(); // Selects generation size of he gameworld

  GameWorld gameWorld(size);
  gameWorld.initialize();
  userPlayer.CurrentSector = gameWorld.UniverseList[0]; // Sets players starting sector
  GamePackage package(gameWorld , userPlayer);

  return package;
}

/*
 * Triggers jump gate sequence
 */
Sector Travel(GamePackage gamePackage)
{
  Sector desSector;
  desSector = JumpDrive(gamePackage);
  return desSector;
}

/*
 All of the game systems take place in the loop, doesnt end until the player dies
 */
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

