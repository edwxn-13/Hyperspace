#pragma once
#include <iostream>
#include "NaturalResource.h"
#include "GameWorld.h"

class Faction {
public:
  Faction();
private:
  std::string fName;
  std::string fDesc;

  int fCapital;
  int fType;
  
  std::vector<NaturalResource> fStorage;
  std::vector<Faction*> FactionList;
  std::vector<Sector> fControlledSectors;
  
  float fMineRate;
  
public:
  void FactionRefresh();
};

