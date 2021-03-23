
#include "Navigation.h"
#include <iostream>
#include <math.h>

/*
 Contains scripts used for navigating from
 planet to planet and system to system.
 
 Also triggers encounter logic.
 */
/*/
 Displays the main menu where the user can acces the various parts of the game.
 */
Player DisplayMenu(GamePackage gamePackage)
{
  int inputValue;
  if (gamePackage.nUser.CurrentSector.hasPlanet()) 
  {
    std::cout << "\n1.View Navigation: \n2.View Inventroy: \n3.View Objectives: \n4.View Station: \n5.View Planet: ";
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
      std::cout << "\nSelect Option: ";

      std::cin >> inputValue;
      std::cout << "\n";
    } while (inputValue > 4 && inputValue < 1);
  }

  switch (inputValue)
  {
  default:
    DisplayMenu(gamePackage);
    break;
  case 1:
    gamePackage.nUser.setSector(JumpDrive(gamePackage));
    gamePackage = InitEncoutner(gamePackage);
    gamePackage.nGameWorld.update(gamePackage.nGameWorld);
    break;
  case 2:
    gamePackage.nUser = ViewInventory(gamePackage.nUser);
    break;
  case 3:
    break;
  case 4:
    gamePackage.nUser = ViewStation(gamePackage.nUser);
    break;
  case 5:
    ViewPlanet(gamePackage);
    break;
  }

  return gamePackage.nUser;
}
/*
 Displays the contents of the users inventroy allowing them to
 edit the state of them
 */
Player ViewInventory(Player user) 
{
  int inputValue;
  for (int i = 0; i < user.getInventroy().size(); i++) 
  {
    std::cout << "\n"<< i + 1 << ". " << user.getCargo(i).getName();
  }
  std::cout << "\n\n Select Item: ";
  inputValue = integerInput();
  std::cout << "\n";
  user = ItemSettings(inputValue, user);
  return user;
}

/*/
 Display the details of the planet such as radius name and tech level
 */
void ViewPlanet(GamePackage gamePackage) 
{
  std::cout << "\n\n Planet Details \n Name : " << gamePackage.nUser.CurrentSector.getPlanet().getName();
  gamePackage.nUser.CurrentSector.getPlanet().displayStats();
  DisplayMenu(gamePackage);
}

/*
 Allows the user to access the station's utilities such as
 the news and the shop
 */
Player ViewStation(Player user)
{
  int inputValue;
  std::cout << "\n1.View Store: \n2.View Inventroy: \n3.View Objectives: \n4.View Galactic News: \n";
  do
  {
    std::cout << "Select Option: ";
    inputValue = integerInput();
    std::cout << "\n";
  } 
  while (inputValue > 4 && inputValue < 1);

  switch (inputValue)
    {
    default:
      break;
    case 1:
      user.CurrentSector.getStation().displayGoods();
      user = user.CurrentSector.getStation().market(user);
      break;
    case 2:
      user = ViewInventory(user);
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    }

  return user;
}
int integerInput()
{
  int inputValue;
  for (;;) {
    if (std::cin >> inputValue) {
      return inputValue;
    }
    else {
      std::cout << "Please enter a valid integer\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}
/*/
 Allows the user to delete, sell or equip a selected item
 */
Player ItemSettings(int type, Player user) 
{
  int inputValue;
  std::cout << "\n1.Equip: \n2.Sell: \n3.View Stats: \n";
  do
  {
    std::cout << "Select Option: ";
    inputValue = integerInput();
    std::cout << "\n";
  } while (inputValue > 5 && inputValue < 1);

  switch (inputValue)
  {
  default:
    break;
  case 1:
    user.toggleEquip(type);
    break;
  case 2:
    user.sell(type);
    break;
  case 3:
    user.displayStats(type);
    break;
  }

  return user;
}
/*
 Starts enemy encounter and enters user into combat interface
 */

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

/*
 Finds the sector specified by the player using the hash
 */
Sector sectorSearch(GamePackage gamePackage)
{
  while (true) 
  {
    std::cout << "<<Select Your Destination >>\n";
    int x, y;
    std::cout << "<<X>> :";
    x = integerInput();
    std::cout << "<<Y>> :";
    y = integerInput();
    
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
/*
 Activates the travel system
 Displays the route the player travels
 */
Sector JumpDrive(GamePackage gamePackage)
{
  Sector destination = sectorSearch(gamePackage);
  HQueue route;
  route.enQueue(gamePackage.nUser.CurrentSector);
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

  std::cout << "\n\n<<You have arrived at your destination>>\n\n\n";
  destination.display();
  return destination;
}
/*
 Searches the graph for the user selected sector
 */
HQueue FindRoute(Sector currentNode, Sector destination , HQueue route)
{ 
  currentNode.toggleVisited();
  Sector closestNode(0,0);
  int smallest_distance = 999999999;
  int distance = 0;
  if (currentNode.getHash() == destination.getHash()) 
  {
    std::cout << "Jumping to " << destination.nSearchHash << "\n";
    return route;
  }
  if (currentNode.xVal == 0) { return route; }
  for (int i = 0; i < currentNode.nList.size(); i++)
  {
    if (!route.contains(currentNode.nList[i])) 
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
  std::cout << "\n";
  closestNode.display();
  route.enQueue(closestNode);
  FindRoute(closestNode, destination, route);
  return route;
}

/*
 Returns distance between 2 sectors
 */
int CalculateDistance(Sector Node1, Sector Node2)
{
  return sqrt(pow((Node1.xVal - Node2.xVal), 2) + pow((Node1.yVal - Node2.yVal), 2));
}
