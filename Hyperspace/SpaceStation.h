#pragma once
#include "Equipment.h";
#include "Ship.h"
#include "NaturalResource.h"
#include <vector>

class Player;

class SpaceStation 
{
public:
  SpaceStation();
  SpaceStation(int tech);
  void restock();
  Player market(Player user);
  void displayGoods();
private:
  std::vector<Weapon> nShop;
  std::vector<Ship> nHanger;
  std::vector<NaturalResource> Commodities;
};

