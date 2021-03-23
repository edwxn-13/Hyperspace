#pragma once
#include "Equipment.h"
#include <iostream>
#include <string>
class Weapon : public Equipment 
{
public:
  Weapon();
  Weapon(std::string nameVal, int damageVal, int priceVal, int volitilityVal, int tech);
  int useEquipment();
  std::string getName();
  int getPrice();
  int getDamage();
  int getTechLevel();
  void empty();
private:
  std::string nName;
  int damage;
  int nPrice;
  int nTechLevel;
  int nVolitility;
};

