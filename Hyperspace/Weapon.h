#pragma once
#include "Equipment.h"
#include <iostream>
class Weapon : public Equipment 
{
public:
  int useEquipment();
private:
  int damage;
  int volitility;
};

