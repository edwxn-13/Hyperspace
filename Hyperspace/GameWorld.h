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
  void liberate();
  void append(Sector);
  void setDistance(int);
  Planet getPlanet();
  bool contains(Sector);
  int checkNeigbours();
public:
  std::vector<Sector> nList;
  int nFactionID;
  int xVal, yVal;
  int nNeigbours;
  int nDistanceFromPlayer;
  int nSectorCount;
  int nSearchHash;
  Planet nLocalPlanet;
};

class GameWorld
{
private:
  Sector nMainNode;
  int nSize;
  int nGenNum;
  bool CheckDuplicates(Sector,Sector);
  std::vector<Sector> SortList(std::vector<Sector>);
  Sector Generate(int);
public:
  std::vector<Sector> UniverseList;

  GameWorld();
  GameWorld(int);
  void initialize();
  std::vector<Sector> getWorld();
  void update();
  int getSize();
  std::vector<Sector> getMap();
};