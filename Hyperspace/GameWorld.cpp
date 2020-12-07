#include "GameWorld.h"
#include <time.h>

/*/
 Default Sector Constructor
 */
Sector::Sector()
{
  xVal = 0;
  yVal = 0;
};

/*/
 Defines sector with coordinates x and y;
 /*/
Sector::Sector(int x, int y)
{
  xVal = x;
  yVal = y;
  searchHash = xVal * yVal;
  SectorCount++;
}

//Sets planet value
void Sector::setPlanet(Planet newPlanet) 
{
  localPlanet = newPlanet;
}
//Returns planet value
Planet Sector::getPlanet()
{
  return localPlanet;
}

//Returns the amount of sectors local to itself.
int Sector::checkNeigbours()
{
  //select all sectors in a range
  //if 2 or more belong to the parent faction then convert them
  //else belongs to the closest faction
  //else factionless
  return neigbours;
}

//Connects secotrs together by adding it the array. w
//@args Sector childSector
void Sector::append(Sector childSector) 
{
  nList.push_back(childSector);
}

GameWorld::GameWorld()
{
  
}

GameWorld::GameWorld(int sizeVal)
{
  size = sizeVal;
  genNum = 0;
}

int GameWorld::GetSize()
{
  return size;
}

/*
 The GameWorld is initiallized
 Sectors are generated based on specified size from player.
 Random cooordinates are assigned
 Triggers Generate function to create graph based on points
 The in game solar system is modelled as a weighted graph.
 */
void GameWorld::Initialize() 
{
  std::cout <<"<Generating Universe> \n";

  int xVal;
  int yVal;
  
  for (int i = 0; i < size; i++) // Creaes the nodes
  {
    xVal = rand() % 2400;
    yVal = rand() % 2400;
    
    Sector tempSector(xVal,yVal);
    int planetC = rand() % 2; // does the sector contain a planet?

    if (planetC == 1)
    {
      Planet tempPlanet;
      tempPlanet.setName("temp planet");
      tempSector.setPlanet(tempPlanet);
    }
    UniverseList.push_back(tempSector);
  }
  mainNode = Generate(mainNode);
  UniverseList = sortList(UniverseList);
}

//Combines sections together
void Merge()
{
  
}

// Splits list into smalller sections
std::vector<Sector> GameWorld::sortList(std::vector<Sector> rootList)
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

Sector GameWorld::Generate(Sector rootNode)
{
  genNum++;
  
  if(genNum > size - 1)
  {
    return rootNode;
  }
  
  for(int i = 0; i < (rand() % (size + 1)); i++)
  {
    Sector childSector = Generate(UniverseList[rand() % (size - 1)]);
    
    if(!CheckDuplicates(rootNode, childSector))
    {
      rootNode.nList.push_back(childSector);
    }
  }
  return rootNode;
}
/*/
 Factions update their terratories by calculating the amount of faction
 owend sectors in a specified area
 */
void GameWorld::Update()
{
  
  for(int i = 1; i < size-1; i++)
  {
    UniverseList[i].checkNeigbours();
  }
  // First check the faction of the node
  // Check the amount of neigbouts that belong to the same faction
  // Then if the number of factions meet the criteria
  // the faction stays in control
  // If not then the node is controlled by the nearest faction.
}


