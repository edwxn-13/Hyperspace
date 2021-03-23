#pragma once
#include <vector>
#include "Planet.h"
#include <string>
#include "SpaceStation.h"
#include "Faction.h"
// Make it a graph to secure these marks bout this paper
class GameWorld;

struct NeighbourFactionCount {
  NeighbourFactionCount();
  NeighbourFactionCount(int, int, int, int);
  int f1, f2, f3;
  int popularID;
};

class Sector
{
public:
  Sector();
  Sector(int,int);
  void setPlanet(Planet);
  void liberate();
  void append(Sector);
  void display();
  void setDistance(int);
  int getHash();
  Planet getPlanet();
  SpaceStation getStation();
  void setStation(SpaceStation);
  bool hasPlanet();
  bool contains(Sector);
  void toggleVisited();
  void checkNeigbours(GameWorld);
  int getThreat();
  int getTech();
  int factionCount();
  NeighbourFactionCount PopularFaction(std::vector<Sector>);
  std::vector<Sector> nList;
  int nFactionID;
  int xVal, yVal;
  int nNeigbours;
  bool nVisited;
  int nDistanceFromPlayer;
  int nThreat;
  int nTechLevel;
  int nSectorCount;
  int nSearchHash;
  Planet nLocalPlanet;
  SpaceStation nLocalStation;
};

class GameWorld
{
public:
  Sector nMainNode;
  int nSize;
  int nGenNum;
  Faction::FContainer gameFactions;
  NaturalResource::RContainer nWorldResources;
  bool CheckDuplicates(Sector,Sector);
  std::vector<Sector> SortList(std::vector<Sector>);
  void Generate(int);
public:
  std::vector<Sector> UniverseList;

  GameWorld();
  GameWorld(int);
  void initialize();
  std::vector<Sector> getWorld();
  void update(GameWorld);
  int getSize();
  std::vector<Sector> getMap();
};
