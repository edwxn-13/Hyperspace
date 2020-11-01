#include "GameWorld.h"
#include <time.h>
Sector::Sector(int x, int y) 
{
  xVal = x;
  yVal = y;
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
        UVerseGrid[i][j].localPlanet = tempP;
      }
    }
  }
}