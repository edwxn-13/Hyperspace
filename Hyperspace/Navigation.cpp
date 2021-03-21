
#include "Navigation.h"
#include <iostream>
#include <math.h>

/*
 Contains scripts used for navigating from
 planet to planet and system to system.
 
 Also triggers encounter logic.
 */

void DisplayMenu(GamePackage gamePackage) 
{
  int inputValue;
  if (gamePackage.nUser.CurrentSector.hasPlanet()) 
  {
    std::cout << "\n1.View Navigation: \n2.View Inventroy: \n3.View Objectives: \n4.View Planet: \n5.View Station: ";
    do
    {
      std::cout << "Select Option\n";

      std::cin >> inputValue;
    } while (inputValue > 5 && inputValue < 1);
  }

  else 
  {
    std::cout << "\n1.View Navigation: \n2.View Inventroy: \n3.View Objectives: \n4.View Station: ";
    do
    {
      std::cout << "Select Option\n";

      std::cin >> inputValue;
    } while (inputValue > 4 && inputValue < 1);
  }

  switch (inputValue)
  {
  default:
    DisplayMenu(gamePackage);
    break;
  case 1:
    gamePackage.nUser.setSector(JumpDrive(gamePackage));
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  }
}

void ViewInventory(GamePackage gamePacakge) 
{

}

void ItemSettings() 
{

}

GamePackage InitEncoutner(GamePackage gamePackage) 
{
  RandomEncounter Encounter(gamePackage.nUser.CurrentSector.getThreat());
  return Encounter.CombatInit(gamePackage);
}

void DisplayMap(GamePackage gamePackage)
{
  for (int i = 0; i < gamePackage.nGameWorld.UniverseList.size() - 1;i++) 
  {
    std::cout << "Sector: " << gamePackage.nGameWorld.UniverseList[i].xVal << " : " << gamePackage.nGameWorld.UniverseList[i].yVal << "\n";
    for (int j = 0; j < gamePackage.nGameWorld.UniverseList[i].nList.size() - 1; i++) 
    {
      std::cout << "Child: " << gamePackage.nGameWorld.UniverseList[i].xVal << " : " << gamePackage.nGameWorld.UniverseList[i].yVal << "  ";
    }
    std::cout << "\n";
  }
}


Sector sectorSearch(GamePackage gamePackage)
{
  while (true) 
  {
    std::cout << "<<Select Your Destination >>\n";
    int x, y;
    std::cout << "<<X>> :";
    std::cin >> x;
    std::cout << "<<Y>> :";
    std::cin >> y;

    int hash = x * y;

    std::cout << "\n<<Searching Coordinates>>\n";

    for (int i = 0; i < gamePackage.nGameWorld.getSize(); i++) 
    {
      if (gamePackage.nGameWorld.UniverseList[i].getHash() == hash) 
      {
        std::cout << "\n<<Found Coordinate>>\n";

        return gamePackage.nGameWorld.UniverseList[i];
      }
    }
    std::cout << "\n<<Invalid Coordinates>>\n";
  }
}

Sector JumpDrive(GamePackage gamePackage)
{
  Sector destination = sectorSearch(gamePackage);
  HQueue route;
  route = FindRoute(gamePackage.nUser.CurrentSector, destination, route);
  std::cout << "\n\n<<Initiating Jump>>\n";
  while (gamePackage.nUser.getShip().getFuel() != 0)
  {
    if (route.size() > 0) 
    { 
      destination = route.deQueue();
      std::cout << "\n<<" << destination.getHash() << ">>\n\n";
      gamePackage.nUser.getShip().burnFuel(50);
    }

    else { break; }
  }

  std::cout << "\n\n<<You have arrived at your destination>>\n";
  return destination;
}

HQueue FindRoute(Sector currentNode, Sector destination , HQueue route)
{ 
  currentNode.toggleVisited();
  Sector closestNode;
  int smallest_distance = 999999999;
  int distance = 0;
  if (currentNode.getHash() == destination.getHash()) 
  {
    std::cout << "Jumping to " << destination.nSearchHash << "\n";
    return route;
  }

  if (currentNode.nList.size() == 0) 
  {
    return route;
  }

  for (int i = 0; i < currentNode.nList.size(); i++)
  {
    if (!currentNode.nList[i].nVisited) 
    {
      distance = CalculateDistance(currentNode.nList[i], currentNode);
      currentNode.nList[i].setDistance(distance);
      if (distance < smallest_distance)
      {
        smallest_distance = distance;
        closestNode = currentNode.nList[i];
      }
    }
  }

  route.enQueue(closestNode);
  FindRoute(closestNode, destination, route);
  return route;
}
int CalculateDistance(Sector Node1, Sector Node2)
{
  return sqrt(pow((Node1.xVal - Node2.xVal), 2) + pow((Node1.yVal - Node2.yVal), 2));
}
