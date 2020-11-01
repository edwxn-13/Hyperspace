#pragma once

#include <iostream>
#include "Ship.h"
#include "Planet.h"
class Player
{
public:
  int locCord;
  bool alive;
  Planet CurrentPlanet; 

private:
  std::string mName; // Cmon man
  int mBankAccount; // Players Credit Balance.
  int mPlayerLevel, XP;
  Ship mPlayerShip; // The player's ship

public:
  Player();
  std::string getName();
  void setName(std::string);

  int getBalance();
  void setBalance(int);

  void LevelUp();
  void XPCheck();

};

