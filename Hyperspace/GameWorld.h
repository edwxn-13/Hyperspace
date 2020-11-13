#pragma once
#include <vector>
#include "Planet.h"

// Make it a graph to secure these marks

class Sector
{
public:
  Sector();
  Sector(int,int);
  Sector sUp,sRt,sLft,sDwn;
  Planet getPlanet();
  int FactionID;
  std::vector<Sector> nList;
  int checkNeigbours();
private:
  int xVal, yVal;
  int neigbours;
  Planet localPlanet;
};

class GameWorld
{
private:
  static int size;
  static std::vector< std::vector<Sector>> UVerseGrid;
  static std::vector< std::vector<Sector>> tempUVerseGrid;
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
