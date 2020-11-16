#include "GameWorld.h"
#include <time.h>
Sector::Sector(){};

Sector::Sector(int x, int y)
{
  xVal = x;
  yVal = y;
  SectorCount++;
}

Planet Sector::getPlanet()
{
  return localPlanet;
}

int Sector::checkNeigbours()
{
  
  return neigbours;
}

GameWorld::GameWorld()
{
  
}

std::vector< std::vector<Sector>> GameWorld::GetMap()
{
  return UVerseGrid;
}

int GameWorld::GetSize()
{
  return size;
}
Sector GameWorld::Generate(Sector rootNode)
{
  genNum++;
  
  if (genNum == size) 
  {
    Sector temp(rand() % 1000,rand() % 1000);
    temp.setName(/*/randname/*/);
    planet = rand() % 2;
    switch planet
    {
      case 1:
        Planeta tempPlanet();
        Sector.setPlanet(tempPlanet);
        break;
    }
    return temp;
  }
  int randChild = rand() % size;
  for (int i = 0; i < randChild; i++) {
    rootNode.nList.push_back(Generate(rootNode));
  }

  return;
}

void GameWorld::Update()
{
  
}


