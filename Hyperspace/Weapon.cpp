#include "Weapon.h"

Weapon::Weapon(std::string nameVal, int damageVal, int priceVal , int volitilityVal, int tech)
{
  nName = nameVal;
  damage = damageVal;
  nVolitility = volitilityVal;
  nPrice = priceVal;
  nTechLevel = tech;
}

Weapon::Weapon()
{
  damage = 100;
}

int Weapon::useEquipment() 
{
  int finalDamage = nVolitility + rand() % (damage - nVolitility + 1 );
  return finalDamage;
}

std::string Weapon::getName()
{
  return nName;
}

int Weapon::getPrice()
{
  return nPrice;
}

int Weapon::getDamage()
{
  return damage;
}

int Weapon::getTechLevel()
{
  return nTechLevel;
}

