#pragma once
#include <iostream>
#include "Player.h"

struct GamePackage
{
  GamePackage();
  GameWorld gameworld;
  Player user;
};
