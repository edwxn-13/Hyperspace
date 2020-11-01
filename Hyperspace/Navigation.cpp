#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include "Navigation.h"
#include <time.h>


Map InitGalaxy()
{
  srand(time(0));
  vector<Planet> GalaxyMap;
  string pName;
  for (int i = 0; i < 12; i++)
  {
    Planet x;
    x.techLevel = rand() % 5;
    x.threatLevel = rand() % 10;
    x.name = "[naem]";
    GalaxyMap.push_back(x);
  }
  Map map = { GalaxyMap };
  return map;
}

void DisplayMap(Map mapVal)
{
  for (int i = 0; i < mapVal.map.size(); i++)
  {
    cout << (i+1) << ": " << mapVal.map[i].name << "\n";
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

Planet JumpDrive(Coords val, Map mapVal)
{
  Planet x = mapVal.map[val.x];
  cout << "Welcome to " << x.name << "\n";
  return mapVal.map[val.x];
  int eChance = rand() % 2;
  if (eChance < 2) 
  {
    Encounter encounter(x.threatLevel);
  }
}