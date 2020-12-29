
#include "Navigation.h"
/*
 Contains scripts used for navigating from
 planet to planet and system to system.
 
 Also triggers encounter logic.
 */


void DisplayMap(GamePackage gamePackage)
{

}


Sector sectorSearch(GamePackage gamePackage)
{
  while (true) {
    std::cout << "<<Select Your Destination >>\n";
    int x, y;
    std::cout << "<<X>> :";
    std::cin >> x;
    std::cout << "<<Y>> :";
    std::cin >> y;

    int hash = x * y;

    std::vector<Sector> secList = gamePackage.gameworld.GetMap();

    for (int i = 0; i < gamePackage.gameworld.GetMap().size(); i++)
    {
      if (hash == secList[i].searchHash)
      {
        return secList[i];
      }
    }
    std::cout << "Invalid Coordinates\n";
  }
}

Sector JumpDrive(GamePackage gamePackage)
{
  Sector destination = sectorSearch(gamePackage);
  std::vector<Sector> route;
  if (destination.contains(gamePackage.user.CurrentSector)) 
  {
    std::cout << "Jumping to " << destination.searchHash << "\n";
    return destination;
  }
  route = FindRoute(gamePackage.user.CurrentSector , route);
  return destination;
}

std::vector<Sector> FindRoute(Sector currentNode, std::vector<Sector> route) 
{
  Sector discoveredNode;
  for(int i = 0; i < currentNode.nList.size() - 1; i++)
  {
    discoveredNode = currentNode.nList[i];
    int distance = CalculateDistance(currentNode, discoveredNode);
    currentNode.nList[i].setDistance(distance);
  }

  int smallest_distance = currentNode.nList[0].distanceFromPlayer;
  int largest_distance = currentNode.nList[0].distanceFromPlayer;

  for (int i = 0; i < currentNode.nList.size(); i++)
  {
    if (currentNode.nList[i].distanceFromPlayer < smallest_distance)
    {
      smallest_distance = currentNode.nList[i].distanceFromPlayer;
    }
    if (currentNode.nList[i].distanceFromPlayer > largest_distance)
    {
      largest_distance = currentNode.nList[i].distanceFromPlayer;
    }
  }

  route.push_back(discoveredNode);
  FindRoute(discoveredNode.nList[rand() % discoveredNode.nList.size()],route);
  return route;
}
int CalculateDistance(Sector Node1 , Sector Node2) 
{
  return sqrt(pow((Node1.xVal - Node2.xVal), 2) + pow((Node1.yVal - Node2.yVal), 2));
}