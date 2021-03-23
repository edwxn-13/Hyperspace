#pragma once
#include <iostream>
#include "NaturalResource.h"
#include <time.h>
class GameWorld;
class Sector;
/*
 Defines Faction class
 */
class Faction {
public:

  struct FContainer 
  {
    std::vector<Faction> nFactionList;
  };

  Faction();
  Faction(std::string name, NaturalResource::RContainer rContainer , int type);
  float getCapital();
  void factionUpdate(FContainer fContainer, NaturalResource::RContainer rContainer);
  void dailySpening(NaturalResource::RContainer rContainer);
  void market(Faction::FContainer fContainer, NaturalResource::RContainer rContainer, float supplyVal);
  float mine(NaturalResource::RContainer rContainer, int index);
  int sectorCount(GameWorld);
private:
  std::string nName;
  std::string nDesc;
  int nID;
  float nCriticalValue;
  int nCapital;
  int nType;
  
  std::vector<float> nStorage;
  std::vector<Sector> nControlledSectors;
  
  float nMineRate;
  
};

