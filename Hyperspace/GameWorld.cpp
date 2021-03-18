#include "GameWorld.h"
#include <time.h>

/*/
 Default Sector Constructor
 */
Sector::Sector()
{
  xVal = 0;
  yVal = 0;
  nVisited = false;
};

/*/
 Defines sector with coordinates x and y;
 /*/
Sector::Sector(int x, int y)
{
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

//Returns the amount of sectors local to itself.
int Sector::checkNeigbours(GameWorld world)
{
  //select all sectors in a range
  //if 2 or more belong to the parent faction then convert them
  //else belongs to the closest faction
  //else factionless
  int range;
  std::vector<Sector> closeSectors;
  std::vector<Sector> enemySectors;
  for (int i = 0; i < world.UniverseList.size(); i++) 
  {
    if (world.UniverseList[i].xVal < (xVal + 100) && world.UniverseList[i].yVal < (yVal + 100)) 
    {
      if (world.UniverseList[i].nFactionID == nFactionID) 
      {
        closeSectors.push_back(world.UniverseList[i]);
      }

      else 
      {
        enemySectors.push_back(world.UniverseList[i]);
      }
    }
  }

  if (closeSectors.size() < 2) 
  {
    nFactionID = 0;

    if (PopularFaction(enemySectors) > 2) 
    {
      nFactionID = PopularFaction(enemySectors)
    }
  }

  else if (closeSectors.size() < 4) 
  {

  }

  else if (closeSectors.size() > 4)
  {

  }
  return nNeigbours;
}

int Sector::getThreat()
{
  return nThreat;
}

int Sector::factionCount() {}

int Sector::PopularFaction(std::vector<Sector> enemySectors) {}

//Connects secotrs together by adding it the array. w
//@args Sector childSector
void Sector::append(Sector childSector) 
{
  nList.push_back(childSector);
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

GameWorld::GameWorld(int sizeVal)
{
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
    xVal = rand() % 2400;
    yVal = rand() % 2400;
    
    Sector tempSector(xVal,yVal);
    tempSector.nThreat = rand() % 4;
    int planetC = rand() % 2; // does the sector contain a planet?

    if (planetC == 1)
    {
      Planet tempPlanet;
      tempPlanet.setName("temp planet");
      tempSector.setPlanet(tempPlanet);
    }
    std::cout << "\n<<" << xVal << " , " << yVal << ">>\n";
    UniverseList.push_back(tempSector);
  }
  
  Generate(0);
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
  for(int i = 0; i < rootNode.nList.size(); i++)
  {
    if(rootNode.nList[i].xVal == childNode.xVal && rootNode.nList[i].yVal == childNode.yVal)
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

  for (int i = 0; i < rand() % nSize; i++) 
  {
    int randSectorIndex;
    do 
    {
      randSectorIndex = (rand() % UniverseList.size() - 1);
    } while (randSectorIndex < 0);

    if (CheckDuplicates(UniverseList[index],UniverseList[randSectorIndex]) == false)
    {
      UniverseList[index].append(UniverseList[randSectorIndex]);
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
void GameWorld::update()
{
  
  for(int i = 1; i < nSize-1; i++)
  {
    UniverseList[i].checkNeigbours();
  }
  // First check the faction of the node
  // Check the amount of neigbouts that belong to the same faction
  // Then if the number of factions meet the criteria
  // the faction stays in control
  // If not then the node is controlled by the nearest faction.
}


