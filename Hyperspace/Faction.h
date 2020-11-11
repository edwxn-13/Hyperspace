#pragma once
#include "NaturalResource.h"
class Faction {
public:
    Faction();

private:
  int storage;
  int credits;
  
  
  void factionRefresh();
};

