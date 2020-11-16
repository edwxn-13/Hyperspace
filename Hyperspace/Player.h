#pragma once

#include <iostream>
#include "Ship.h"
#include "Planet.h"
#include "GameWorld.h"
#include "Equipment.h"
class Player
{
public:
  int locCord;
  bool alive;
  Sector CurrentSector;

private:
  std::string mName; // Cmon man
  int mBankAccount; // Players Credit Balance.
  int mPlayerLevel, XP;
  Ship mPlayerShip; // The player's ship
  std::vector<Equipment> Inventory;
public:
  Player();
  std::string getName();
  void setName(std::string);

  int getBalance();
  void setBalance(int);
  void Equip(int);
  void LevelUp();
  void XPCheck();
  void Fire(int);

};

