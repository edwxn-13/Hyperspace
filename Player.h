#pragma once

#include <iostream>
#include "Ship.h"
#include "Planet.h"
#include "GameWorld.h"
#include "Equipment.h"
/*
 Defines Player, the users controlled entity
 */
class Player
{
public:
  bool alive; // Is the player alive?
  Sector CurrentSector; // Players current location

private:
  std::string mName; // Cmon man
  int mBankAccount; // Players Credit Balance.
  int mPlayerLevel, XP;
  Ship mPlayerShip; // The player's ship
  std::vector<Equipment> Inventory; // Contains all of the users equipment.
public:
  Player(); // Default player constructor, sets initial values.
  std::string getName(); // Returns players name.
  void setName(std::string); // Sets a new name for the player.

  int getBalance(); // Returns the players credit balance
  void setBalance(int); // Sets new balance.
  void Equip(int); // Equips a new item from the inventory.
  void LevelUp(); // Increases players level.
  void XPCheck(); // Checks if player can increace in level.
  void Fire(int); // Uses currently equipped equipment.

};

