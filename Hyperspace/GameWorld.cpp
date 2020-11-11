#include "GameWorld.h"
#include <time.h>
Sector::Sector(){};

Sector::Sector(int x, int y)
{
  xVal = x;
  yVal = y;
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
void GameWorld::Generate(int size)
{
  for (int i = 0; i < size; i++) 
  {
    for (int j = 0; j < size; j++)
    {
      srand(time(0));
      UVerseGrid[i][j] = Sector(i,j);
      int planet = rand() % 2;
      if (planet > 3)
      {
        Planet tempP;
        tempP.name = "placeHolder";
        tempP.techLevel = rand() % 7;
        tempP.threatLevel = rand() % 7;
        UVerseGrid[i][j].getPlanet() = tempP;
      }
    }
  }
}

void GameWorld::Update()
{
  for(int i = 0; i < UVerseGrid.size(); i++)
  {
    for(int j = 0; j < UVerseGrid.size(); j++)
    {
      if(UVerseGrid[i][j].checkNeigbours() > 4)
      {
        tempUVerseGrid[i][j].FactionID = 0;
      }
      
      if(UVerseGrid[i][j].checkNeigbours() == 2)
      {
        tempUVerseGrid[i][j].FactionID =
                        tempUVerseGrid[i][j].nList[0].FactionID;
      }
      else
      {
        Sector x(i,j);
        tempUVerseGrid[i].push_back(x);
      }
      
    }
  }
  UVerseGrid = tempUVerseGrid;
}


