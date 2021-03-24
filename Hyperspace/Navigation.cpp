
#include "Navigation.h"
#include <iostream>
#include <math.h>

/*
* 
* The main menu 
* Contains scripts used for navigating from
* planet to planet and system to system.
* Also triggers encounter logic.
* Refreshes sector
* Displays the main menu where the user can acces the various parts of the game.
 */
Player DisplayMenu(GamePackage gamePackage)
{
  int inputValue;
  if (gamePackage.nUser.CurrentSector.hasPlanet()) //If there is a planet the menu changes to accomodate that
  {
    std::cout << "\n1.View Navigation: \n2.View Inventroy: \n3.View Objectives: \n4.View Planet:";
    do
    {
      std::cout << "Select Option\n";

      inputValue = integerInput(); // Takes player input
    } while (inputValue > 5 && inputValue < 1); //Loop ensures users input is acceptable
  }

  else 
  {
    std::cout << "\n1.View Navigation: \n2.View Inventroy: \n3.View Objectives: \n4.View Station: ";
    do
    {
      std::cout << "\nSelect Option: ";

      inputValue = integerInput(); // Takes player input
      std::cout << "\n";
    } while (inputValue > 4 && inputValue < 1); //Loop ensures users input is acceptable
  }

  switch (inputValue)
  {
  default:
    DisplayMenu(gamePackage);
    break;
  case 1:
    DisplayMap(gamePackage); // All coordinates are displayed
    gamePackage.nUser.setSector(JumpDrive(gamePackage)); // User selects and travels to sector
    gamePackage = InitEncoutner(gamePackage); // Encounter is triggered
    gamePackage.nGameWorld.update(gamePackage.nGameWorld); // All sector faction data is updated
    break;
  case 2:
    gamePackage.nUser = ViewInventory(gamePackage.nUser); // Inventory management screen is activated
    break;
  case 3:
    std::cout << "\n\n<<Survive>>\n\n";
    break;
  case 4:
    if (!gamePackage.nUser.CurrentSector.hasPlanet()) //If there is no planet, station interface is activated
      gamePackage.nUser = ViewStation(gamePackage.nUser);
    else
      ViewPlanet(gamePackage); // Else planet data and information are shown
    break;
  case 5:
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
    std::cout << "\n"<< i + 1 << ". " << user.getCargo(i).getName(); // Retrieves all the players inventory items
  }
  std::cout << "\n\n Select Item: "; 
  inputValue = integerInput(); // User input is taken
  std::cout << "\n";
  user = ItemSettings(inputValue, user); // Item settings are displayed for selected item
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
    }

  return user;
}

/*
* Input validates any integer input ensuring there are not unaccepted characters
*/
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
  std::cout << "\n1.Equip: \n2.Sell: \n3.View Stats: \n"; //Displays menu
  do
  {
    std::cout << "Select Option: ";
    inputValue = integerInput(); //Takes input
    std::cout << "\n";
  } while (inputValue > 5 && inputValue < 1);

  switch (inputValue)
  {
  default:
    break;
  case 1:
    user.toggleEquip(type); //Equips itemn at index type
    break;
  case 2:
    user.sell(type); //Sells item at index type
    break;
  case 3:
    user.displayStats(type); //Displays the information about the weapon at index type
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

/*
* Displays the coordinates of every sector
*/
void DisplayMap(GamePackage gamePackage)
{
  for (int i = 0; i < gamePackage.nGameWorld.UniverseList.size(); i++) 
  {
    gamePackage.nGameWorld.UniverseList[i].display();
  }
}

/*
 Finds the sector specified by the player using the hash
 */
Sector sectorSearch(GamePackage gamePackage)
{
  while (true) 
  {
    std::cout << "\n\n<<Select Your Destination >>\n";
    int x, y;
    std::cout << "<<X>> :";
    x = integerInput();
    std::cout << "<<Y>> :";
    y = integerInput();
    
    int hash = x * y;

    std::cout << "\n<<Searching Coordinates>>\n";
    //Searches the list for the sector with a mathcing hash to the coordinates provided by the player
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
  while (gamePackage.nUser.getShip().getFuel() != 0) // If the player has fuel in their ship they can travel, otherwise they cannot
  {
    if (route.size() > 0) //To avoid an out of range error. deQueues the queue until it is empty
    { 
      destination = route.deQueue(); // Destination is set to the returned sector, if the fuel runs out mid jump, they will be dumped as far as they can go
      std::cout << "\n\n <<" << destination.xVal << " , " << destination.yVal <<">>\n\n";  // Displays every sector traversed through on the route
      gamePackage.nUser.getShip().burnFuel(50); // Spends fuel for every sector jump
    }

    else { break; }
  }

  std::cout << "\n\n<<You have arrived at your destination>>\n\n\n";
  destination.display();
  return destination;
}
/*
 Searches the graph for the user selected sector
 Returns queue containing the sectors that were travelled through to reach the destination
 */
HQueue FindRoute(Sector currentNode, Sector destination , HQueue route)
{ 
  Sector closestNode(0,0); // Sets the closest node to an impossible value so its always replaced
  int smallest_distance = 999999999; // Sets smallest_distance to large value so its always replaced
  int distance = 0;
  if (currentNode.getHash() == destination.getHash())  // Compares the hash of the destination sector and the player's current sector as a completion state
  {
    std::cout << "Jumping to " << destination.nSearchHash << "\n";
    return route;
  }
  /*
  * If the sector the player searches for is not on the jump gate network, they will be returned to the sector they started in
  */
  if (currentNode.xVal == 0) { return route; }
  for (int i = 0; i < currentNode.nList.size(); i++)
  {
    if (!route.contains(currentNode.nList[i]))  // Ensures the sector has not been visited in this jump instance, stops algorithm traveling backwards
    {
      distance = CalculateDistance(currentNode.nList[i], currentNode); //Calculates distance
      currentNode.nList[i].setDistance(distance);
      if (distance < smallest_distance) //Compares the distance of all the child sectors of the root sector and finds the shortest.
      {
       
        smallest_distance = distance;
        closestNode = currentNode.nList[i]; // Sets the node that is the closest
      }
    }
  }
  std::cout << "\n";
  route.enQueue(closestNode); //Adds the new closest node to the queue so it is shown on the route the player takes through the system
  FindRoute(closestNode, destination, route); //Recurs until the target sector is found or all options have been exhausted. 
  return route; //Returns queue
}

/*
 Returns distance between 2 sectors
 */
int CalculateDistance(Sector Node1, Sector Node2)
{
  return sqrt(pow((Node1.xVal - Node2.xVal), 2) + pow((Node1.yVal - Node2.yVal), 2));
}
