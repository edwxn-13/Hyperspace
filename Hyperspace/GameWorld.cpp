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
  if (genNum == size) 
  {
    return Sector(0,0);
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


