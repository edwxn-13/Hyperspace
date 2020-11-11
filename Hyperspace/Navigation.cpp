#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include "Navigation.h"
#include "GameWorld.h"
#include <time.h>


void DisplayMap(std::vector< std::vector<Sector>> mapVal, GameWorld world)
{
  vector< vector<Sector>> map = mapVal;
  
  for (int i = 0 ; i < world.GetSize(); i++)
  {
    for (int j = 0; j < world.GetSize(); i++)
    {
      cout << (i+1) << ": " << map[i][j].getPlanet().name << " ";
    }
    
    std::cout << "\n";
  }
  
}


Coords Navigation()
{
  int planetX;

  cout << "Enter Destination: ";
  cin >> planetX;
  cout << "\n\n";
  Coords coords = { planetX };
  return coords;
}

Sector JumpDrive(Coords val, std::vector< std::vector<Sector>> mapVal)
{
  Sector destination = mapVal[val.x][val.y];
  return destination;
}
