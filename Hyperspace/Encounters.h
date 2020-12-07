#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Queue.hpp"
#include <time.h>
#include <vector>
class Encounter 
{
public:
  Encounter();
private:
  int threatLevel;
  EncounterQueue queue;
};
