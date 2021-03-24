#pragma once
#include <vector>
#include "Planet.h"
#include <string>
#include "SpaceStation.h"
#include "Faction.h"
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
  Sector(int,int); // Constucter, sets coordinates and generates attributes
  void setPlanet(Planet);
  void liberate(); // Makes the secotor free from any faction ownership
  void append(Sector); // Links 2 sectors together on the jump gate network
  void display(); // Displays the sectors attributes in a user interface friendly area
  void setDistance(int); //Sets the distance between the sector and the player
  void setFaction(int);
  int getHash(); // Returns the hash of the sector, (xVal * yVal)
  Planet getPlanet(); //Returns local planet
  SpaceStation getStation(); //Returns local station
  void setStation(SpaceStation);
  bool hasPlanet(); //Returns true if the sector has a planet false if otherwise
  bool contains(Sector); // Returns true if the parameter is contained in the sector's nList
  void toggleVisited(); // Toggles bool isVisited
  void checkNeigbours(GameWorld);
  int getThreat();
  int getTech();
  int factionCount();
  NeighbourFactionCount PopularFaction(std::vector<Sector>);
  std::vector<Sector> nList;
  int nFactionID; // Faction Identifier
  int xVal, yVal;
  int nNeigbours;
  bool nVisited;
  int nDistanceFromPlayer; // Distance from sector to player's current sector
  int nThreat; // Determines the strength of enemys that can spawn in the sector
  int nTechLevel; // Determmines what technology can spawn in the sector
  int nSectorCount;
  int nSearchHash; // The hash of the sector
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
  void Generate(int); // Generates graph using the rootNode
public:
  std::vector<Sector> UniverseList;

  GameWorld();
  GameWorld(int);
  void initialize(); // Generates sectors
  std::vector<Sector> getWorld();
  void update(GameWorld);
  int getSize();
  std::vector<Sector> getMap();
};
