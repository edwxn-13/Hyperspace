#pragma once
#include "Equipment.h";
#include "Ship.h"
#include "NaturalResource.h"
#include <vector>
class SpaceStation 
{
public:
  SpaceStation();
  SpaceStation(int tech);
  void restock();
  void displayGoods();
private:
  std::vector<Weapon> nShop;
  std::vector<Ship> nHanger;
  std::vector<NaturalResource> Commodities;
};

