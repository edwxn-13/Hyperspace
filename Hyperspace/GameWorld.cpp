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
  
  return neigbours;
}

//Connects secotrs together by adding it the array. @Argument Sector
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
 The in game solar system is modelled as a weighted graph.
 */
void GameWorld::Initialize() 
{
  for (int i = 0; i < size; i++)
  {
    int xVal;
    int yVal;

    srand(time(0));

    bool uniqueC = false;

    std::vector<int> xVals, yVals;

    xVal = rand() % 2400;
    yVal = rand() % 2400;

    while (uniqueC == false) 
    {

      if (xVals.empty() && yVals.empty()) 
      {
        uniqueC = true;
        break;
      }
      else 
      {
        int xU = 0;
        int yU = 0;
        for (int i = 0; i < xVals.size(); i++) 
        {
          if(xVal == xVals[i])
          xU++;
        }
        for (int i = 0; i < yVals.size(); i++)
        {
          if (yVal == yVals[i])
          yU++;
        }

        if (xVal && yVal) 
        {
          uniqueC = false;
        }

        else 
        {
          uniqueC = true;
        }
      }
    }
    xVals.push_back(xVal);
    yVals.push_back(yVal);
    std::cout << xVal << " : " << yVal << "\n";
    Sector tempSector(xVal,yVal);

    int planetC = rand() % 2;

    if (planetC == 1)
    {
      Planet tempPlanet;
      tempPlanet.setName("temp planet");
      tempSector.setPlanet(tempPlanet);
    }
    UniverseList.push_back(tempSector);
  }
  mainNode = Generate(mainNode);
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
  rootNode = UniverseList[(rand() % UniverseList.size()) - 1];
  for (int i = 0; i < ((rand() % UniverseList.size()) - 1); i++) 
  {
    int altNode = (rand() % UniverseList.size()) - 1;
    rootNode.append(UniverseList[altNode]);
    std::cout << rootNode.getPlanet().getName() << "\n";
    Generate(UniverseList[altNode]);
  }
  
  return rootNode;
}

void GameWorld::Update()
{
  // First check the faction of the node
  // Check the amount of neigbouts that belong to the same faction
  // Then if the number of factions meet the criteria the faction stays in control
  // If not then the node is controlled by the nearest faction.
}


