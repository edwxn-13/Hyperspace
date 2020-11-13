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
private:
  std::vector<Sector> nList;
  
  int xVal, yVal;
  int neigbours;
  Planet localPlanet;
};

class GameWorld
{
private:
  static Sector mainNode;
  static std::vector<Sector> UniverseList;
public:
  GameWorld();
  static void Generate(int size);
  static void Update();
  static int GetSize();
  static std::vector< std::vector<Sector>> GetMap();
};


std::vector< std::vector<Sector>> GameWorld::UVerseGrid;
std::vector< std::vector<Sector>> GameWorld::tempUVerseGrid;
int GameWorld::size;
