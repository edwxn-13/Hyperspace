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
  void setDistance(int);
  Planet getPlanet();
  bool contains(Sector);
  int checkNeigbours();
public:
  std::vector<Sector> nList;
  int FactionID;
  int xVal, yVal;
  int neigbours;
  int distanceFromPlayer;
  int SectorCount;
  int searchHash;
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
  std::vector<Sector> GetMap();
};