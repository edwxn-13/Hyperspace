#pragma once
#include "Equipment.h";
#include "Ship.h"
#include "NaturalResource.h"
#include <vector>
class SpaceStation 
{
public:
  void restock();
  void displayGoods(int);
private:
  std::vector<Equipment> nShop;
  std::vector<Ship> nHanger;
  std::vector<NaturalResource> Commodities;
};

