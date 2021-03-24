#pragma once
#include "Equipment.h"
#include <iostream>
#include <string>
/*
* Defines Equipment used in combat situations to cause damage to other ships
*/
class Weapon : public Equipment 
{
public:
  Weapon();
  Weapon(std::string nameVal, int damageVal, int priceVal, int volitilityVal, int tech);
  int useEquipment(); //Returns the final calculated damage accounting for volitility
  std::string getName(); //Returns the name of the weapon
  int getPrice(); //Returns the price of the weapon
  int getDamage(); // Calculates the damage that the weapon will inflict on the target
  int getTechLevel(); //Returns TechLevel
  void empty(); // Turns an inventroy slot into an empty place holder
private:
  std::string nName;//Name of weapon
  int damage; // The base damage dealt before volitility
  int nPrice; //How much the item costs in a shop
  int nTechLevel; // Measures how sophisticated the weapons technology is, determines what stations it can spawn at
  int nVolitility; // How much the damage can vary below the base damage value
};

