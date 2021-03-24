#pragma once
#include <iostream>
#include "Player.h"

/*
* Contains player and gameworld class to make them easier to pass to functions
*/
struct GamePackage
{
  GamePackage(GameWorld gVal, Player pVal); 
  GameWorld nGameWorld;
  Player nUser;
};
