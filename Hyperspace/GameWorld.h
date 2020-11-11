#pragma once
#include <vector>
#include "Planet.h"
class Sector
{
public:
  Sector();
  Sector(int,int);

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
  void Generate(int size);
  void Update();
  int GetSize();
  std::vector< std::vector<Sector>> GetMap();
};


std::vector< std::vector<Sector>> GameWorld::UVerseGrid;
std::vector< std::vector<Sector>> GameWorld::tempUVerseGrid;
int GameWorld::size;
