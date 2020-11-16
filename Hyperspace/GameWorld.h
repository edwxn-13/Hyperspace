#pragma once
#include <vector>
#include "Planet.h"

// Make it a graph to secure these marks

class Sector
{
public:
  Sector();
  Sector(int,int);
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
  static Sector mainNode;
  static std::vector<Sector> UniverseList;
  static int size;
  static int genNum;
public:
  GameWorld();
  static Sector Generate(Sector);
  static void Update();
  static int GetSize();
  static std::vector< std::vector<Sector>> GetMap();
};
