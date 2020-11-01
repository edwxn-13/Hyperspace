#pragma once
#include <vector>
#include "Planet.h"
struct Sector 
{
  Sector(int,int);
  int xVal, yVal;
  Planet localPlanet;
};

static class GameWorld 
{
  std::vector< std::vector<Sector>> UVerseGrid;

public:
  void Generate(int size);
};

