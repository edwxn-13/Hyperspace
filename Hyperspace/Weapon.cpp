#include "Weapon.h"

int Weapon::useEquipment() 
{
  int finalDamage = volitility + rand() % (damage - volitility + 1 );
  return finalDamage;
}