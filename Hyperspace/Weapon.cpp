#include "Weapon.h"

Weapon::Weapon()
{
  damage = 100;
}

int Weapon::useEquipment() 
{
  int finalDamage = volitility + rand() % (damage - volitility + 1 );
  return finalDamage;
}

