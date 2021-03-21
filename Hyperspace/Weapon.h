#pragma once
#include "Equipment.h"
#include <iostream>
class Weapon : public Equipment 
{
public:
  Weapon();
  int useEquipment();
private:
  int damage;
  int volitility;
};

