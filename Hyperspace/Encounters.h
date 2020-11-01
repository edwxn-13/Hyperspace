#pragma once
#include "Player.h"
#include "Enemy.h"
#include <time.h>
#include <vector>
class Encounter 
{
  int pThreat;
  int pFleetSize;
  std::vector<Enemy> Fleet;
  void Combat(Player);
  void DisplayTargets();
  void DisplayEquipment(Player);
public:
  Encounter();
  Encounter(int threat,Player user);
};