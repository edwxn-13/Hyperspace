#include "GameWorld.h"
#include <time.h>
Sector::Sector(){};

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
  mainNode = Generate(mainNode);
}

Sector GameWorld::Generate(Sector rootNode)
{
  genNum++;
  
  if (genNum == size) 
  {
    Sector tempSector(rand() % 1000,rand() % 1000);
    int planet = rand() % 2;
    switch (planet)
    {
      case 1:
        Planet tempPlanet;
        tempSector.setPlanet(tempPlanet);
        break;
    }
    return tempSector;
  }
  int randChild = rand() % size;
  for (int i = 0; i < randChild; i++) {
    rootNode.nList.push_back(Generate(rootNode));
  }
  
  return Sector(0,0);
}

void GameWorld::Update()
{
  
}


