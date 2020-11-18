#pragma once
#include <vector>
#include "Planet.h"

// Make it a graph to secure these marks

class Sector
{
public:
  Sector();
  Sector(int,int);
  void setPlanet(Planet);
  Planet getPlanet();
  int FactionID;
  int checkNeigbours();
  static int SectorCount;
  std::vector<Sector> nList;
protected:
  int xVal, yVal;
  int neigbours;
  Planet localPlanet;
};

class GameWorld
{
private:
  Sector mainNode;
  std::vector<Sector> UniverseList;
  int size;
  int genNum;
  Sector Generate(Sector);
public:
  GameWorld();
  GameWorld(int);
  void Initialize();
  void Update();
  int GetSize();
  static std::vector< std::vector<Sector>> GetMap();
};

int Sector::SectorCount = 0;
