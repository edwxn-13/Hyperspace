#include "GameWorld.h"
#include <time.h>
Sector::Sector()
{
  xVal = 0;
  yVal = 0;
};
Sector::Sector(int x, int y)
{
  xVal = x;
  yVal = y;
  SectorCount++;
}
void Sector::setPlanet(Planet newPlanet) 
{
  localPlanet = newPlanet;
}
Planet Sector::getPlanet()
{
  return localPlanet;
}

int Sector::checkNeigbours()
{
  
  return neigbours;
}

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

void GameWorld::Initialize() 
{
  for (int i = 0; i < size; i++)
  {
    srand(time(0));
    int xVal = rand() % 2400;
    int yVal = rand() % 2400;
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

Sector GameWorld::Generate(Sector rootNode)
{
  rootNode = UniverseList[(rand() % UniverseList.size()) - 1];
  for (int i = 0; i < ((rand() % UniverseList.size()) - 1); i++) 
  {
    rootNode.append(UniverseList[(rand() % UniverseList.size()) - 1]);
  }

  return rootNode;
}

void GameWorld::Update()
{
  
}


