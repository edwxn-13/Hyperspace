#pragma once
#include <iostream>
#include "Player.h"

struct GamePackage
{
  GamePackage(GameWorld gVal, Player pVal);
  GameWorld nGameWorld;
  Player nUser;
};
