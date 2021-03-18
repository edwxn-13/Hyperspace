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
  int getHash();
  Planet getPlanet();
  bool hasPlanet();
  bool contains(Sector);
  void toggleVisited();
  int checkNeigbours();
  int getThreat();
  int factionCount();
  int PopularFaction(std::vector<Sector>);
  std::vector<Sector> nList;
  int nFactionID;
  int xVal, yVal;
  int nNeigbours;
  bool nVisited;
  int nDistanceFromPlayer;
  int nThreat;
  int nSectorCount;
  int nSearchHash;
  Planet nLocalPlanet;
};

class GameWorld
{
public:
  Sector nMainNode;
  int nSize;
  int nGenNum;
  bool CheckDuplicates(Sector,Sector);
  std::vector<Sector> SortList(std::vector<Sector>);
  void Generate(int);
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