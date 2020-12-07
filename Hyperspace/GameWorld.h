#pragma once
#include <vector>
#include "Planet.h"

// Make it a graph to secure these marks bout this paper

class Sector
{
public:
  Sector();
  Sector(int,int);
  void setPlanet(Planet);
  void append(Sector);
  Planet getPlanet();
  int FactionID;
  int checkNeigbours();
  int SectorCount;
  int searchHash;
  std::vector<Sector> nList;
public:
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
  bool CheckDuplicates(Sector,Sector);
  std::vector<Sector> sortList(std::vector<Sector>);
  Sector Generate(Sector);
public:
  GameWorld();
  GameWorld(int);
  void Initialize();
  void Update();
  int GetSize();
  static std::vector< std::vector<Sector>> GetMap();
};
