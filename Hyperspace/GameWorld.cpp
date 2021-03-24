#include "GameWorld.h"
#include <time.h>

/*/
 Default Sector Constructor
 */
Sector::Sector()
{
  xVal = 0;
  yVal = 0;
  nFactionID = 0;
  nVisited = false;
};

/*/
 Defines sector with coordinates x and y;
 /*/
Sector::Sector(int x, int y)
{
  nFactionID = 0;
  xVal = x;
  yVal = y;
  nSearchHash = xVal * yVal;
  nSectorCount++;
  nVisited = false;
}

void Sector::setDistance(int val) 
{
  nDistanceFromPlayer = val;
}

void Sector::setFaction(int newVal)
{
  nFactionID = newVal;
}

/*
* Returns identifying hash made from multiplying both coordinates together
*/
int Sector::getHash()
{
  return xVal * yVal;
}

//Sets planet value
void Sector::setPlanet(Planet newPlanet) 
{
  nLocalPlanet = newPlanet;
}
//Returns planet value
Planet Sector::getPlanet()
{
  return nLocalPlanet;
}

SpaceStation Sector::getStation()
{
  return nLocalStation;
}

void Sector::setStation(SpaceStation newStation)
{
  nLocalStation = newStation;
}

//Finds the amount of sectors local to itself and updates the faction of the neighbouring factions.
void Sector::checkNeigbours(GameWorld world)
{
  //select all sectors in a range
  //if 2 or more belong to the parent faction then convert them
  //else belongs to the closest faction
  //else factionless
  int range;
  std::vector<Sector> closeSectors;
  std::vector<Sector> enemySectors;
  for (int i = 0; i < world.UniverseList.size(); i++)  // Iterates through all sectors
  {
    if (world.UniverseList[i].xVal < (xVal + 100) && world.UniverseList[i].yVal < (yVal + 100)) // finds all sectors in a range of 100
    {
      if (nFactionID == world.UniverseList[i].nFactionID) // Finds allied sectors
      {
        closeSectors.push_back(world.UniverseList[i]);
      }

      else // Therefore these are enemy sectors
      {
        enemySectors.push_back(world.UniverseList[i]);
      }
    }
  }

  NeighbourFactionCount track = PopularFaction(enemySectors);

  switch (track.popularID)
  {
  case 1:
    if (track.f1 > 2) // If there are more than 2 neighbours belonging to faction 1
    {
      nFactionID = track.popularID; // Sector now belongs to faction 1
    }
    break;
  case 2:
    if (track.f2 > 2) // If there are more than 2 neighbours belonging to faction 2
    {
      nFactionID = track.popularID; // Sector now belongs to faction 1
    }
    break;
  case 3:
    if (track.f3 > 2) // If there are more than 2 neighbours belonging to faction 3
    {
      nFactionID = track.popularID; // Sector now belongs to faction 1
    }
    break;
  }

  if (closeSectors.size() < 3) 
  {
    switch (track.popularID)
    {
    case 1:
      if (track.f1 > 2)
      {
        nFactionID = track.popularID;
      }
      break;
    case 2:
      if (track.f2 > 2)
      {
        nFactionID = track.popularID;
      }
      break;
    case 3:
      if (track.f3 > 2)
      {
        nFactionID = track.popularID;
      }
      break;
    }

  }

  else if (closeSectors.size() > 3)
  {
    liberate();
  }
                                                                                                                                                                                                                                                                                                                                                                                                                                                              }

int Sector::getThreat()
{
  return nThreat;
}

int Sector::getTech()
{
  return nTechLevel;
}

int Sector::factionCount() 
{
  int count = 0;
  return count;
}

//Compares the amount of enemy factions belonging to each faction and returns the enemy faction with the greatest amout of non allied fsectors
NeighbourFactionCount Sector::PopularFaction(std::vector<Sector> enemySectors) 
{
  int f1Count = 0;
  int f2Count = 0;
  int f3Count = 0;
  for(int i = 0; i < enemySectors.size(); i++) 
  {
    if (enemySectors[i].nFactionID == 0) { f1Count++; }
    if (enemySectors[i].nFactionID == 1) { f2Count++; }
    if (enemySectors[i].nFactionID == 2) { f3Count++; }
  }

  int popFaction;
  if(f1Count > f2Count)
  {
    if (f3Count > f1Count) { popFaction = 3; return NeighbourFactionCount(f1Count, f2Count, f3Count, popFaction);}
    popFaction =  1;
    return NeighbourFactionCount(f1Count, f2Count, f3Count, popFaction);
  }

  if (f2Count > f3Count) 
  {
    if (f1Count > f2Count) { popFaction = 1; return NeighbourFactionCount(f1Count, f2Count, f3Count, popFaction);}
    popFaction =  2;
    return NeighbourFactionCount(f1Count, f2Count, f3Count, popFaction);
  }

  if (f3Count > f1Count) 
  {
    if (f2Count > f3Count) { popFaction = 2; return NeighbourFactionCount( f1Count,f2Count,f3Count,popFaction );}
    popFaction = 3;
    return NeighbourFactionCount(f1Count, f2Count, f3Count, popFaction);
  }
  return NeighbourFactionCount();
}

//Connects secotrs together by adding it the array. 
//@args Sector childSector
void Sector::append(Sector childSector) 
{
  nList.push_back(childSector);
}

void Sector::display()
{
  std::cout << "  Sector: <<" << xVal << "," << yVal << ">>\n" << "  Faction: " << nFactionID;
}

bool Sector::hasPlanet() 
{
  if (nLocalPlanet.pExist != 1) 
  {
    return false;
  }

  else 
  {
    return true;
  }
}

bool Sector::contains(Sector childNode) 
{
  for (int i = 0; i < nList.size(); i++)
  {
    if (nList[i].getHash() == childNode.getHash()) 
    {
      return true;
    }
  }

  return false;
}

void Sector::toggleVisited()
{
  nVisited = !nVisited;
}

void Sector::liberate() 
{
  nFactionID = 0;
}

GameWorld::GameWorld()
{
  
}

/*
* Initialized gameworld, takes size parameter which defines how many sectors the universe will have
*/

GameWorld::GameWorld(int sizeVal)
{
  nWorldResources.nResourceList.push_back(NaturalResource(100000, 0, 0.9, 1.62, 2000, 10)); // Pushes back main 3 natural resources in the game. 
  nWorldResources.nResourceList.push_back(NaturalResource(100000, 1, 0.45, 1.3, 1000, 20)); // Game is scalable so any amount of resources can be added
  nWorldResources.nResourceList.push_back(NaturalResource(50000, 2, 0.1, 1.01, 200, 95));

  // 0 - main resource is carbon fibre
  // 1 - main resource is water
  // 2 - main resource is xeon
  gameFactions.nFactionList.push_back(Faction("The Mesaron Commonwealth", nWorldResources, 2)); // Defines main 3 factions in game
  gameFactions.nFactionList.push_back(Faction("The Federation", nWorldResources, 1)); // Game is scalable so any amount of factions can be added
  gameFactions.nFactionList.push_back(Faction("The Free Nations of Kaytions", nWorldResources, 0));
  nSize = sizeVal;
  nGenNum = 0;
}

std::vector<Sector> GameWorld::getMap()
{
  return UniverseList;
}

int GameWorld::getSize()
{
  return nSize;
}

std::vector<Sector> GameWorld::getWorld() 
{
  return UniverseList;
}
/*
 The GameWorld is initiallized
 Sectors are generated based on specified size from player.
 Random cooordinates are assigned
 Triggers Generate function to create graph based on points
 The in game solar system is modelled as a weighted graph.
 */
void GameWorld::initialize() 
{
  std::cout <<"<Generating Universe> \n";

  int xVal;
  int yVal;
  
  for (int i = 0; i < nSize; i++) // Creaes the nodes
  {
    xVal = rand() % 2400; //Random x coordinate
    yVal = rand() % 2400; //Random y coordinate
    
    Sector tempSector(xVal,yVal);
    tempSector.nTechLevel = rand() % 5; // Random tech level
    tempSector.nThreat = rand() % 4; // Random threat level
    int planetC = rand() % 2; // does the sector contain a planet?

    if (planetC == 1) // Adds planet to sector
    {
      Planet tempPlanet(tempSector.getTech(), tempSector.getThreat());
      tempSector.setPlanet(tempPlanet);
      tempSector.setFaction(rand()%3);
    }
    else // Adds station to sector
    {
      SpaceStation tempStation = SpaceStation(tempSector.getTech());
      tempSector.setPlanet(Planet(0));
      tempSector.setStation(tempStation);
    }
    UniverseList.push_back(tempSector);
  }
  
  Generate(0); // Generates graph with sectors
  //UniverseList = sortList(UniverseList);
}

//Combines sections together
void Merge()
{
  
}

// Splits list into smalller sections
std::vector<Sector> GameWorld::SortList(std::vector<Sector> rootList)
{
  return rootList;
}

/*/
  Checks if a sector is already connected to another one so there are no
  duplicate sectors in the child sector array.
*/
bool GameWorld::CheckDuplicates(Sector rootNode, Sector childNode)
{
  if (rootNode.getHash() == childNode.getHash()) 
  {
    return true;
  }

  for(int i = 0; i < rootNode.nList.size(); i++)
  {
    if(rootNode.nList[i].getHash() == childNode.getHash())
    {
      return true;
    }
  }
  return false;
}

/*
 The graph is generated
 Nodes are generated and given random coordinates.
 Then the nodes are randomly joined together.
 Then any free standing graphs or nodes
 are deleted using a bredth search algorithm.
 */

void GameWorld::Generate(int index)
{
  nGenNum++;
  if (nGenNum > nSize) 
  {
    return;
  }

  for (int i = 0; i < nSize - (rand() % nSize - 1); i++) 
  {
    int randSectorIndex;
    do 
    {
      randSectorIndex = (rand() % UniverseList.size() - 1);
    } while (randSectorIndex < 0);

    if (CheckDuplicates(UniverseList[index],UniverseList[randSectorIndex]) == false)
    {
      UniverseList[index].append(UniverseList[randSectorIndex]);
      UniverseList[randSectorIndex].append(UniverseList[index]);
      Generate(randSectorIndex);
    }
  }

}

/*Sector GameWorld::Generate(Sector rootNode)
{
  srand(time(0));
  nGenNum++;
  
  if(nGenNum > nSize - 1)
  {
    return rootNode;
  }
  
  for(int i = 0; i < (rand() % (nSize)); i++)
  {
    int ranint = rand() % nSize;
    Sector childSector = Generate(UniverseList[ranint]);
    
    if(!CheckDuplicates(rootNode, childSector))
    {
      rootNode.nList.push_back(childSector);
    }
  }
  return rootNode;
}*/

/*/
 Factions update their terratories by calculating the amount of faction
 owend sectors in a specified area
 */
void GameWorld::update(GameWorld world)
{
  for(int i = 1; i < nSize-1; i++)
  {
    UniverseList[i].checkNeigbours(world);
  }
  // First check the faction of the node
  // Check the amount of neigbouts that belong to the same faction
  // Then if the number of factions meet the criteria
  // the faction stays in control
  // If not then the node is controlled by the nearest faction.
}

NeighbourFactionCount::NeighbourFactionCount(int f1Val, int f2Val, int f3Val, int popVal)
{
  f1 = f1Val;
  f2 = f2Val;
  f3 = f3Val;
  popularID = popVal;
}

NeighbourFactionCount::NeighbourFactionCount()
{
  
}
